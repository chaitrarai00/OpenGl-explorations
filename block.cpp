//brick hunt

#define CONTINUE 1

#define QUIT 0

#define RESTART 15

#define RED 2

#define GREEN 3

#define BLUE 4

#define BLACK 5

#define INC 6

#define DEC 7

#define C1 8

#define C2 9

#define C3 10

#define GOLD 11

#define ORCHID 12

#define BLACK1 13

#define WHITE 14

#include<GL/freeglut.h>
float score=0;
int br=0.5,bg=1.0,bb=0.0;
struct bricks   

{
	
float x,y,w,h;
	
bool alive;

} b[45];

float red1,red2,green1,green2,blue1,blue2;


struct ball     

{
	
float ballx,bally,ballwh,velx,vely;
	
float red;
	
float green;
	
float blue;
	
bool left,right,up,down;

} ball;


struct block

{
	
float myx;
	
float myy;
	
float width;
	
float height;
	
bool lft;
	
bool rgt;
	
float red;
	
float green;
	
float blue;

}block;


float red=0.0;

float green=0.0;

float blue=0.0;

void renderBitmapString(float x, float y, float z, void *font,char *string)
{
	char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void specialUp(int,int,int);	

void specialDown(int,int,int);  

void reshape(void);		

void draw(void);		

//void callMenu(void);			

void revert(void);

void menu(int);


#include<GL/glut.h>

#include<stdlib.h>

#include<stdio.h>

#include<math.h>


char gameEnd[]="GAME OVER";

int m;


void initialize()	

{
	
//for(int n=0,x=4,y=390;n<45;n++,x+=66)

for(int n=0,x=4,y=390;n<45;n++,x+=66)
	
{
	
if(x>560)                             
	   
{
	     
x=4;
	     
y-=25;                              
	   
}
	
b[n].x=x;
	
b[n].y=y;
	
b[n].w=60;           
	
b[n].h=20;
	
b[n].alive=true;    
 
}

	
block.myx=300;          
	
block.myy=0;
	
block.width=100;
	
block.height=20;
	
block.lft=false;
	
block.rgt=false;

	

ball.ballx=300;
	
ball.bally=200;
	
ball.ballwh=30;
	
ball.velx=1.25;        //speeed
	
ball.vely=1.25;        //speeed

	

red1=0.96;
	
green1=0.8;
	
blue1=0.69;
	
red2=0.6;
	
green2=0.8;
	
blue2=0.196078;

	
ball.red=br;
	
ball.green=bg;
	
ball.blue=bb;

block.red=1;

block.green=1;



}

bool check_collision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh) 

{

if ( Ay+Ah< By ) 
return false; 

else if ( Ay >By+Bh ) 
return false; 

else if ( Ax+Aw<Bx ) 
return false; 

else if ( Ax>Bx+Bw ) 
return false; 


return true; 

}


char scorevalue[100];
void reshape()		

{
	

if(block.myx<0)
	
block.myx=0;
	
if(block.myx+block.width>600)
	
block.myx=500;
	
if(block.lft==true)
	
block.myx=block.myx-0.4;
	
if(block.rgt==true)
	
block.myx=block.myx+0.4;

ball.ballx+=0.2*ball.velx;
	
ball.bally+=0.2*ball.vely;

	
for(int n=0;n<45;n++)
	
{	
if(b[n].alive==true)
	   
{
		
if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,b[n].x,b[n].y,b[n].w,b[n].h)==true)
		
{
++score;
		
ball.vely=-ball.vely;
		
b[n].alive=false;
		
ball.down=true;
		
ball.up=false;
		
break;
		
}
	   
}
	
}
	
if(ball.ballx<0)
	
{
		
ball.velx=-ball.velx;
		
ball.right=true;
		
ball.left=false;

}
	
if(ball.ballx+ball.ballwh>600)
	
{
		
ball.right=false;
		
ball.left=true;
		
ball.velx=-ball.velx;
	
}
	
if(ball.bally+ball.ballwh>400)
		
{ball.vely=-ball.vely;}
	
else if(ball.bally<0)
{

glColor3f(1.0,1.0 ,1.0);
		
glRasterPos3f(236,195,0); 
			
for(m=0;gameEnd[m]!='\0';m++)
			
glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, gameEnd[m]);		
       


}
	
if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,block.myx,block.myy,block.width,block.height)==true)
	
{
			
ball.vely=-ball.vely;
			
ball.up=true;
			
ball.down=false;
}

glColor3f(1.0,1.0 ,0.0);
		
//glRasterPos3f(236,100,0); 
		
sprintf(scorevalue,"Score:%.f",score);	

renderBitmapString(136,200,0,GLUT_BITMAP_HELVETICA_18,scorevalue);	
draw();

}

void specialUp(int key,int x,int y)

{
	
switch(key)
	
{
		
case (GLUT_KEY_LEFT): block.lft=false;break;
		
case (GLUT_KEY_RIGHT): block.rgt=false;break;
	
}

}

void specialDown(int key,int x,int y)

{
	
switch(key)
	
{
		
case (GLUT_KEY_LEFT): block.lft=true;break;
		
case (GLUT_KEY_RIGHT): block.rgt=true;break;
	
}

}

void keyboard(unsigned char key,int x,int y)

{
	
if(key==27) 		
	
{
		
ball.velx=0;
		
ball.vely=0;	
	
}

if(key=='r')
{
br=1.0;
bg=0.0;
bb=0.0;
}
if(key=='g')
{
br= 0.0;
bg=1.0;
bb=0.0;
}
if(key=='b')
{
br= 0.0;
bg=0.0;
bb=1.0;
}
if(key=='w')
{
br=1.0;
bg=1.0;
bb=1.0;
}
glFlush();
	glutSwapBuffers();
glutPostRedisplay();
}

void myinit()

{
	
glViewport(0,0,600,400);
	
glLoadIdentity();
	
glShadeModel(GL_SMOOTH);
	
glMatrixMode(GL_PROJECTION);
	
gluOrtho2D(0,600,0,400);
	
//printf("GAME IS OVER");

}

void draw()		

{


float angle,x1,x2,y1,y2,radius=16;

	
for(int i=0;i<45;i++)
	
{
		
if(b[i].alive==true)    
		
{
		
if(i%2==0) 
glColor3f(red1,green1,blue1);
		
else 
glColor3f(red2,green2,blue2);
		
glBegin(GL_POLYGON);
			
glVertex2f(b[i].x,b[i].y);           
			
glVertex2f(b[i].x+b[i].w,b[i].y);
			
glVertex2f(b[i].x+b[i].w,b[i].y+b[i].h);
			
glVertex2f(b[i].x,b[i].y+b[i].h);
		
glEnd();
		
}
	
}



	
glColor3f(block.red,block.green,block.blue);    
	
glBegin(GL_POLYGON);
		
glVertex2f(block.myx,block.myy);
		
glVertex2f(block.myx+block.width,block.myy);
		
glVertex2f(block.myx+block.width,block.myy+block.height);
		
glVertex2f(block.myx,block.myy+block.height);
	
glEnd();
glColor3f(ball.red,ball.green,ball.blue);
	
x1=ball.ballx;
	
y1=ball.bally;
	
glBegin(GL_TRIANGLE_FAN);
        
glVertex2f(x1,y1);

for(angle=1.0f;angle<361.0f;angle+=0.2)
        
{

x2 = x1+sin(angle)*radius;
            
y2 = y1+cos(angle)*radius;
            
glVertex2f(x2,y2);
        
}

glEnd();

	
glutPostRedisplay();
	
glutSwapBuffers();


}

void display()

{
	
glClear(GL_COLOR_BUFFER_BIT);
	
glClearColor(red,green,blue,1);
	
glDisable(GL_DEPTH_TEST);
	
ball.red=br;
	
ball.green=bg;
	
ball.blue=bb;
draw();
	
glFlush();
	
reshape();

}


int main1()

{
	
initialize();
	
myinit();
	
}


void menu(int opt)

{
	
switch(opt)
	
{
		
case 1: revert();
			
break;

case 2: score=0.0; main1();  

break;
		
case 3: exit(0);
	
}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}


void revert()

{
	
ball.velx=2.95;
	
ball.vely=7.35;
	
if(ball.up==true)
	
{
		
if(ball.right==true)
		
{
			
ball.velx=ball.velx;
			
ball.vely=ball.vely;
		
}
		
else if(ball.left==true)
		
{
			
ball.velx=-ball.velx;
			
ball.vely=ball.vely;
		
}
	
}
	
else if(ball.down=true)
	
{

if(ball.right=true)
		
{
			
ball.velx=ball.velx;
			
ball.vely=-ball.vely;
		
}
		
else if(ball.left==true)
		
{
			
ball.velx=-ball.velx;
			
ball.vely=-ball.vely;
		
}
	
}

}




int main(int argc,char *argv[])

{
	
glutInit(&argc,argv);
	
glutInitWindowSize(600,400);
	
glutInitWindowPosition(100,100);
	

glutCreateWindow("Block Breaker");
main1();	
draw();
	glutCreateMenu(menu);
    glutAddMenuEntry("Continue",1);
	glutAddMenuEntry("Restart",2);
glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	
glutDisplayFunc(display);

glutSpecialFunc(specialDown);
	
glutSpecialUpFunc(specialUp);
	
glutKeyboardFunc(keyboard);
	
glutIdleFunc(reshape);
	
glutMainLoop();
	
return 0;

//printf("game over");
	


}



