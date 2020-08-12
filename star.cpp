#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define INNER_RADIUS	  0.3 	
#define OUTER_RADIUS	  1.0		
#define NUM_STAR_POINTS	  1
#define NUM_STARS		  1		
#define ROT_INC		     0.1		
#define STAR_IDX		  1		
#define M_PI              22/7

static GLfloat g_rotate = 0;
static GLfloat g_rotInc = ROT_INC; 

void drawStar(GLfloat inner, GLfloat outer, int numPoints) 

{

	GLfloat step = M_PI * 2.0 / (GLfloat)(2 * numPoints);
	register int i;
	GLfloat angle, r;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i < numPoints * 2; ++i) 
     {
	
      	r = (i % 2 == 0 ? inner : outer);
		angle = i * step;
		glVertex2f(r * cos(angle), r * sin(angle));
	
     }

	glEnd();

}


void display(void)
{
	register int i;
	register GLfloat c; 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear( GL_COLOR_BUFFER_BIT );
	for (i = 0; i < NUM_STARS; ++i) 
     {
		glPushMatrix();
     	glRotatef(360.0/NUM_STARS * i, 0, 0, 1);
		glTranslatef(OUTER_RADIUS, 0,0);	
     	glRotatef(g_rotate + (3 * i), 0, 0, 1);
		c = 1.0/NUM_STARS * (GLfloat)i;
		glColor3f(1.0 - c, 0.0, c);
		glCallList(STAR_IDX);
     	glPopMatrix();
	}
 	glFlush(); 
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); 
    //GlLoadIdentity(); 
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -1.0, 1.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
         2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

void myKey(unsigned char k, int x, int y)
{
	switch (k) {
		case 'q': exit(0);
		case 'r': g_rotInc += ROT_INC;
		case 't': g_rotInc = ROT_INC;
		case 'y': g_rotInc -= ROT_INC;
		break;
	default:
		printf("Unknown keyboard command \'%c\'.\n", k);
		break;
	}
}


void myMouse(int btn, int state, int x, int y)
{   

if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) g_rotInc += ROT_INC;
if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) g_rotInc = ROT_INC;
if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) g_rotInc -= ROT_INC;
glutPostRedisplay();

}   


void myIdleFunc(void) 
{
	g_rotate += g_rotInc;
	glutPostRedisplay();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Star Instance Test");
    glutReshapeFunc(myReshape);

    glutDisplayFunc(display);
    glutIdleFunc(myIdleFunc);
    glutKeyboardFunc(myKey);
    glutMouseFunc(myMouse);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glNewList(STAR_IDX,GL_COMPILE);
    drawStar(INNER_RADIUS, OUTER_RADIUS, NUM_STAR_POINTS);
    glEndList();
    glutMainLoop();
    return 0;

}
