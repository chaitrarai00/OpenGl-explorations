#include <stdlib.h>

#include <glut.h>
#include <math.h>




#define AppTitle "Face versus vertex normal" 

int Window,fullscreen=1,phasestep=1;
unsigned long int phase=0;
int smooth=0;
GLfloat theta[] = {0.0,0.0,0.0};
int r=-50;
float move;
int  axis,dir=1;
float z=1;

#define MAX 300

double rpl[MAX][MAX][3];
double nrm[MAX][MAX][3];
double stp=1.0;


void fnc()
{
	int i,j;
	double x,y,z,w;

	w=-MAX*stp/2.0;

	for (i=0;i<MAX;i++) 
	{
		y=w+(double)i*stp;
		for (j=0;j<MAX;j++)
		{
			x=w+(double)j*stp;
			z=2.0*sin((x*x+y*y-phase)/100.0);
			rpl[i][j][0]=x;
			rpl[i][j][1]=y;
			rpl[i][j][2]=z;
		}
	}
}


void normal()
{

	int i,j;
	double x,y,w,v;

	w=-MAX*stp/2.0;

	for (i=0;i<MAX;i++) 
	{
		y=w+(double)i*stp;
		for (j=0;j<MAX;j++)
		{
			x=w+(double)j*stp;
			v=4.0*cos((x*x+y*y-phase)/100.0)/100.0;
			nrm[i][j][0]=x*v;
			nrm[i][j][1]=y*v;
			nrm[i][j][2]=-1;
		}
	}
	
}


void draw1()
{
	int i,j;


	for (i=0;i<MAX-1;i++) for (j=0;j<MAX-1;j++)
	{
		glBegin(GL_QUADS);
			glNormal3dv(nrm[i][j]);
			glVertex3dv(rpl[i][j]);
			glNormal3dv(nrm[i][j+1]);
			glVertex3dv(rpl[i][j+1]);
			glNormal3dv(nrm[i+1][j+1]);
			glVertex3dv(rpl[i+1][j+1]);
			glNormal3dv(nrm[i+1][j]);
			glVertex3dv(rpl[i+1][j]);
		glEnd();
	
	}
}

void colorcube()
{
	glBegin(GL_QUADS);           
	glColor3f(.54,.27,.07);
	glVertex3f(-.4*r,.2*r,-.2*r);     
	glVertex3f(.4*r,.2*r,-.2*r);
	glVertex3f(.4*r,0.1*r,-.15*r);
	glVertex3f(-.4*r,0.1*r,-.15*r);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.35,0.77,0.38);
	glVertex3f(-.4*r,0.1*r,.15*r);       
	glVertex3f(.4*r,0.1*r,.15*r);
	glVertex3f(.4*r,.2*r,.2*r);
	glVertex3f(-.4*r,.2*r,.2*r);
	glEnd();


        	glBegin(GL_QUADS);           
     	glColor3f(0.41,0.41,0.41);       
	 
	glVertex3f(-.4*r,.1*r,-.15*r);
	glVertex3f(.4*r,.1*r,-.15*r);
	glVertex3f(.4*r,-.2*r,0.0*r);
        	glVertex3f(-.4*r,-.2*r,0.0*r);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.61,0.61,0.61);
	glVertex3f(-.4*r,-.2*r,0.0*r);        
        	glVertex3f(.4*r,-.2*r,0.0*r);
        	glVertex3f(.4*r,.1*r,.15*r);
        	glVertex3f(-.4*r,.1*r,.15*r);
	glEnd();
	
        	glBegin(GL_QUADS);
	glColor3f(0.60,0.16,0.42);
	glVertex3f(-.6*r,.2*r,0.0*r);               
	glVertex3f(-.4*r,.2*r,-.2*r);
        glVertex3f(-.4*r,.1*r,-.15*r);           
		glVertex3f(-.555*r,.1*r,0.0);
	glEnd();

        	glBegin(GL_QUADS);
	glColor3f(0.80,0.26,0.12);
	glVertex3f(-.555*r,.1*r,0.0*r);              
        	glVertex3f(-.4*r,.1*r,.15*r);
        	glVertex3f(-.4*r,.2*r,.2*r);
        	glVertex3f(-.6*r,.2*r,0.0*r);
	glEnd();


        	glBegin(GL_QUADS);
	glColor3f(0.70,0.46,0.82);
        	glVertex3f(.555*r,.1*r,0.0*r);             
        	glVertex3f(.4*r,.1*r,-.15*r);
        	glVertex3f(.4*r,.2*r,-.2*r);               
	glVertex3f(.6*r,.2*r,0.0*r);
        	glEnd();
       
        
        
        	glBegin(GL_QUADS);
	glColor3f(0.30,0.96,0.42);
        	glVertex3f(.6*r,.2*r,0.0*r);                
			glVertex3f(.4*r,.2*r,.2*r);
        	glVertex3f(.4*r,.1*r,.15*r);
	glVertex3f(.555*r,.1*r,0.0*r);
        	glEnd();

	


        	glBegin(GL_TRIANGLES);                
	glColor3f(0.6f, 0.7f, 0.5f);
	glVertex3f(-.555*r,.1*r,-0*r);                 
	glVertex3f(-.4*r,.1*r,-.15*r);
	glVertex3f(-.4*r,-.2*r,-0.0*r);
	glEnd();

         	glBegin(GL_TRIANGLES);
	glColor3f(0.4f, 0.6f, 0.4f);
        	glVertex3f(-.4*r,-.2*r,0.0*r);        
	glVertex3f(-.4*r,.1*r,.15*r);
	glVertex3f(-.555*r,.1*r,0*r);
	glEnd();


        	glBegin(GL_TRIANGLES);               
        	glColor3f(0.7f, 0.7f, 0.3f);
        	glVertex3f(.4*r,-.2*r,-0.0*r);       
        	glVertex3f(.4*r,.1*r,-.15*r);
	glVertex3f(.555*r,.1*r,-0*r);
	glEnd();
	
	

        	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.7f, 0.2f);
        	glVertex3f(.555*r,.1*r,0*r);         
        	glVertex3f(.4*r,.1*r,.15*r);
        	glVertex3f(.4*r,-.2*r,0.0*r);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(.555*r,.1*r,0*r);
	glVertex3f(.4*r,.1*r,-0.15*r);
	glVertex3f(-0.4*r,.1*r,-0.15*r);
	glVertex3f(-.555*r,.1*r,0*r);
	glVertex3f(-0.4*r,.1*r,.15*r);
	glVertex3f(.4*r,.1*r,0.15*r);
	glEnd();

	glBegin(GL_QUADS);                       
	glColor3f(0.30,0.96,0.42);
	glVertex3f(-.2,.3,.1);                   
    	glVertex3f(-.2,.1,.1);               
		glVertex3f(-.1,.1,.1);
    	glVertex3f(-.1,.3,.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.30,0.96,0.42);
	glVertex3f(-.2*r,.3*r,-.1*r);
    	glVertex3f(-.2*r,.1*r,-.1*r);                
    	glVertex3f(-.1*r,.1*r,-.1*r);
    	glVertex3f(-.1*r,.3*r,-.1*r);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.30,0.96,0.42);
	glVertex3f(-.2*r,.1*r,.1*r);
    	glVertex3f(-.2*r,.3*r,.1*r);                
    	glVertex3f(-.2*r,.3*r,-.1*r);
    	glVertex3f(-.2*r,.1*r,-.1*r);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.30,0.96,0.42);
	glVertex3f(-.1*r,.1*r,.1*r);
    	glVertex3f(-.1*r,.3*r,.1*r);                
    	glVertex3f(-.1*r,.3*r,-.1*r);
    	glVertex3f(-.1*r,.1*r,-.1*r);
	glEnd();
	

	glBegin(GL_QUADS);
	glColor3f(0.30,0.96,0.42);
	glVertex3f(-.2*r,.3*r,.1*r);
    	glVertex3f(-.1*r,.3*r,.1*r);                
    	glVertex3f(-.1*r,.3*r,-.1*r);
    	glVertex3f(-.2*r,.3*r,-.1*r);
	glEnd();
	

    	glBegin(GL_QUADS);                     
	glColor3f(0.30,0.36,0.42);
	glVertex3f(-.1*r,.3*r,.1*r);
    	glVertex3f(.3*r,.3*r,.1*r);                
    	glVertex3f(.3*r,0.1*r,.1*r);
    	glVertex3f(-.1*r,.1*r,.1*r);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.00,0.0,0.0);
	glVertex3f(-.1*r,.3*r,-.1*r);
    	glVertex3f(.3*r,.3*r,-.1*r);                
    	glVertex3f(.3*r,0.1*r,-.1*r);
    	glVertex3f(-.1*r,.1*r,-.1*r);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(.3*r,.3*r,.1*r);
    	glVertex3f(.3*r,.3*r,-.1*r);                
    	glVertex3f(.3*r,.1*r,-.1*r); 
    	glVertex3f(.3*r,.1*r,.1*r);
	glEnd();

    	glBegin(GL_QUADS);
	glColor3f(0.30,0.36,0.12);
	glVertex3f(-.1*r,.3*r,.1*r);
    	glVertex3f(-.1*r,.3*r,-.1*r);                
    	glVertex3f(.3*r,.3*r,-.1*r); 
    	glVertex3f(.3*r,.3*r,.1*r);
	glEnd();                         

	glBegin(GL_QUADS);             
	glColor3f(0.30,0.36,0.12);
	glVertex3f(-.08*r,.4*r,.07*r);
    glVertex3f(-.08*r,.4*r,-.07*r);                
    glVertex3f(-.08*r,.3*r,-.07*r); 
    glVertex3f(-.08*r,.3*r,.07*r);
	glEnd();

	glBegin(GL_QUADS);             
	glColor3f(0.30,0.36,0.12);
	glVertex3f(.27*r,.4*r,.07*r);
    glVertex3f(.27*r,.4*r,-.07*r);                
                   
    glVertex3f(.27*r,.3*r,-.07*r); 
    glVertex3f(.27*r,.3*r,.07*r);
	glEnd();


    glBegin(GL_QUADS);
	glColor3f(1.00,0.56,0.12);
	glVertex3f(-.08*r,.4*r,.07*r);
    glVertex3f(.27*r,.4*r,.07*r);                
    glVertex3f(.27*r,.3*r,.07*r); 
    glVertex3f(-.08*r,.3*r,.07*r);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.30,0.36,0.12);
	glVertex3f(-.08*r,.4*r,-.07*r);
    glVertex3f(.27*r,.4*r,-.07*r);                
    glVertex3f(.27*r,.3*r,-.07*r); 
    glVertex3f(-.08*r,.3*r,-.07*r);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(5.0,0.0,0.0);
	glVertex3f(-0.08*r,.4*r,.07*r);
	glVertex3f(-0.08*r,.4*r,-.07*r);
    glVertex3f(.27*r,.4*r,-.07*r);                
    glVertex3f(.27*r,.4*r,.07*r); 
   	glEnd();

	                                
}

void display(void)
{
  
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();

	
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();


glTranslatef(move,0,0);
glTranslatef(0,33,0);
glRotatef(theta[0], 1.0, 0.0, 0.0);
glRotatef(theta[1], 0.0, 1.0, 0.0);
glRotatef(theta[2], 0.0, 0.0, 1.0);
colorcube();

glPopMatrix();
glPopAttrib();
	
	GLfloat Unlit[] = {0.0, 0.0, 0.0, 1.0};

    
	GLfloat Material1Diffuse[] = {0.28, 0.46, 1.0, 1.0};
    
	GLfloat Material1Specular[] = {1.0, 1.0, 1.0, 1.0};
    
	GLfloat Material1Shininess[] = {20.0};
    

	static GLfloat a=0.0;
	a++;
	
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	

	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Material1Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Material1Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,Material1Shininess);

	
	glPushMatrix();

	 
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE); 

	//glRotatef(0,1,1,1);
   glTranslatef(move,0,0);
	fnc();
	normal();
	draw1();

	glDisable(GL_LIGHTING);
    
	
	glPopMatrix();

		glutSwapBuffers();
}


void reshape(int w,int h)
{
 
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(1.33*(-50.0),1.33*50.0,50.0,-50.0,-100.0,100.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}



void mouse(int btn, int state, int x, int y)
{
	theta[0]=0.0;
	theta[1]=0.0;
	theta[2]=0.0;
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
z++;
phasestep++;
move+=1;

}
if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
{
z=1;
phasestep=1;
}
if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN && phasestep>0)
{
z--;
phasestep--;
move-=1;
}


}


void KeyInp(unsigned char key,int x,int y)
{
	
	if (key==27)
	{
		glutDestroyWindow(Window);
		exit(0);
	}

	if (key=='m') 
	move+=1;

	if (key=='n') 
	move-=1;
	
}
void SpKeyInp(int key,int x,int y)
{
}

void Idle()
{   
	if( dir==1)  
   	{
		theta[2] += 0.1*z;
		if(theta[2]>3)
			dir=0;
   	}	
	if(  dir==0)
	{
		theta[2] -= 0.1*z;
		if(theta[2]<-3)
			dir=1;
    	}
    
	if( theta[2]>3)
		theta[2] -= 0.1*z;
	if( theta[2]<-3)
		theta[2] += 0.1*z;

	if( dir==1)      
   	{
		theta[0] += 0.1*z;
		if(theta[0]>3)
			dir=0;
   	}
	if(  dir==0)
	{
		theta[0] -= 0.1*z;
		if(theta[0]<-3)
			dir=1;
    	}

	if( theta[0]>3)
		theta[0] -= 0.1*z;
	if( theta[0]<-3)
		theta[0] += 0.1*z;
	


	phase+=phasestep;
	glutPostRedisplay();

}

void init(void)
{
	
	int a;
	char *c2,c[]=".\\";
    	GLfloat Light1Position[] = {0, 0, 290.0, 1.0};
    	GLfloat Light2Position[] = {0, 0, -290.0, 1.0};
    	GLfloat LightAmbient[] = {0.1, 0.1, 0.1, 1.0};
    	GLfloat LightDiffuse[] = {1.0, 1.0, 1.0, 1.0};
    	GLfloat LightSpecular[] = {1, 1, 1, 1.0};
    	GLfloat Light1Shininess[] = {90.0};
    	GLfloat Light2Shininess[] = {90.0};

	
	a=1;
	c2=c;

	glutInit(&a,&c2);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow(AppTitle);
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	Window=glutGetWindow();

	glClearColor(0.0,0.0,0.0,0.0);
	
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
	glLineWidth(1.1);
	reshape(640,480);


    
	glLightfv(GL_LIGHT0, GL_POSITION, Light1Position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_SHININESS, Light1Shininess);

	glLightfv(GL_LIGHT1, GL_POSITION, Light2Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT1, GL_SHININESS, Light2Shininess);

   
glTranslatef(0,33,0);
glRotatef(80, 1.0, 0.0, 0.0);
glRotatef(0, 0.0, 1.0, 0.0);
glRotatef(0, 0.0, 0.0, 1.0);
	
	
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(KeyInp);
	glutSpecialFunc(SpKeyInp);
	glutIdleFunc(Idle);


	if (fullscreen) glutFullScreen();
	glEnableClientState(GL_VERTEX_ARRAY);
}


int main(int argc, char **argv)
{
	init();
	glutMainLoop();
	return 0;
}



