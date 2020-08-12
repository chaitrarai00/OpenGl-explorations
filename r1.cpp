#include<GL/glut.h>
#include<stdlib.h>
#include<string.h>
int w;
char wel[100]="WELCOME TO 'BRICKS' GAME...";
char start[50]="TO START GAME PRESS S";

void initfun()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,600,0,400);
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,1.0);
glColor3f(0.2,0.8,0.5);
glRasterPos2f(50,380);
for(w=0;w<sizeof(wel);w++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,wel[w]);
glColor3f(0.6,0.7,0.8);
glRasterPos2f(50,350);
for(w=0;w<sizeof(start);w++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,start[w]);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(600,400);
glutInitWindowPosition(0.0,0.0);
glutCreateWindow("!!!");
initfun();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
