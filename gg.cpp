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

void specialUp(int,int,int);	
void specialDown(int,int,int);  
void reshape(void);		
void draw(void);		
void callMenu(void);			
void revert(void);
void main_menu(int);

#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
void initialize()	
{
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
	ball.velx=0.35;
	ball.vely=0.35;

	red1=0.96;
	green1=0.8;
	blue1=0.69;
	red2=0.6;
	green2=0.8;
	blue2=0.196078;

	ball.red=0.55;
	ball.green=0.64;
	ball.blue=0.34;

	block.red=1;
block.green=1;
	

}
bool check_collision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh) 
{
if ( Ay+Ah< By ) return false; 
else if ( Ay >By+Bh ) return false; 
else if ( Ax+Aw<Bx ) return false; 
else if ( Ax>Bx+Bw ) return false; 

return true; 
}

void reshape()		
{
	if(block.myx<0)
	block.myx=0;
	if(block.myx+block.width>600)
	block.myx=500;
	if(block.lft==true)
	block.myx=block.myx-0.2;
	if(block.rgt==true)
	block.myx=block.myx+0.2;
ball.ballx+=0.2*ball.velx;
	ball.bally+=0.2*ball.vely;

	for(int n=0;n<45;n++)
	{
	if(b[n].alive==true)
	   {
		if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,b[n].x,b[n].y,b[n].w,b[n].h)==true)
		{
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
		ball.vely=-ball.vely;
	else if(ball.bally<0)
		exit(0);

	if(check_collision(ball.ballx,ball.bally,ball.ballwh,ball.ballwh,block.myx,block.myy,block.width,block.height)==true)
	{
			ball.vely=-ball.vely;
			ball.up=true;
			ball.down=false;
	}
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
		callMenu();
	}
}
void myinit()
{
	glViewport(0,0,600,400);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,600,0,400);
}
void draw()		
{

float angle,x1,x2,y1,y2,radius=16;

	for(int i=0;i<45;i++)
	{
		if(b[i].alive==true)    
		{
		if(i%2==0) glColor3f(red1,green1,blue1);
		else glColor3f(red2,green2,blue2);
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
	draw();
	glFlush();
	reshape();
}

/*int main1()
{
	initialize();
	myinit();
	draw();
	glutDisplayFunc(display);
glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(reshape);
	glutMainLoop();
	return 0;
}
*/
void bg1_menu(int opt)
{
	switch(opt)
	{
		case RED:	red=1.0;

				green=0.0;
				blue=0.0;
				display();
				break;
		case GREEN:	red=0.0;
				green=1.0;
				blue=0.0;
				display();
				break;
		case BLUE:	red=0.0;
				green=0.0;
				blue=1.0;
				display();
				break;
		case BLACK:	red=0.0;
				green=0.0;
				blue=0.0;
				display();
				break;
	}

}
void bg2_menu(int opt)
{
	switch(opt)
	{
		case GOLD:	ball.red=0.858824;
				ball.green=0.858824;
				ball.blue=0.439216;
				break;

		case ORCHID:	ball.red=0.858824;
				ball.green=0.439216;
				ball.blue=0.858824;
				break;
	}
}
void bg3_menu(int opt)
{
	switch(opt)
	{
		case C1:
			red1=0.72;
			green1=0.45;
			blue1=0.20;
			red2=0.42;
			green2=0.26;
			blue2=0.15;
			break;
		case C2:
			red1=1;
			green1=0.5;
			blue1=0;
			red2=0.9;
			green2=0.91;
			blue2=0.98;
			break;
		case C3:
			red1=0.858824;
			green1=0.439216;
			blue1=0.858824;
			red2=0.36;
			green2=0.2;
			blue2=0.09;
	}
}
void bg4_menu(int opt)
{
	switch(opt)
	{
		case BLACK1:
			block.red=0.0;
			block.green=0.0;
			block.blue=1.0;
			break;
		case WHITE:
			block.red=1;
			block.green=1;
			block.blue=1;
			break;
	}
}
void sp_menu(int opt)
{
	switch(opt)
	{
		case INC:
			ball.velx++;
			ball.vely++;
			break;
		case DEC:
			ball.velx-=0.25;
			ball.vely-=0.25;
			break;

	}
}
int main1()
{
	initialize();
	myinit();
	draw();
	glutDisplayFunc(display);
glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(reshape);
	glutMainLoop();
	return 0;
}

void main_menu(int opt)
{
	switch(opt)
	{
		case CONTINUE: revert();
			break;
case RESTART: main1();
break;
		case QUIT: exit(0);
	}
}
void callMenu()
{
	int bg,bg1,bg2,bg3,bg4,sp;
	bg1=glutCreateMenu(bg1_menu);
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Default",BLACK);

	bg2=glutCreateMenu(bg2_menu);
	glutAddMenuEntry("gold",GOLD);
	glutAddMenuEntry("Orchid",ORCHID);

	bg3=glutCreateMenu(bg3_menu);
	glutAddMenuEntry("Combo1",C1);
	glutAddMenuEntry("Combo2",C2);
	glutAddMenuEntry("Combo3",C3);

	bg4=glutCreateMenu(bg4_menu);
	glutAddMenuEntry("Blue",BLACK1);
	glutAddMenuEntry("White",WHITE);

	sp=glutCreateMenu(sp_menu);
	glutAddMenuEntry("Increase",INC);
	glutAddMenuEntry("Decrease",DEC);

	bg=glutCreateMenu(main_menu);
	glutAddSubMenu("Background",bg1);
	glutAddSubMenu("Ball",bg2);
	glutAddSubMenu("Brick",bg3);
	glutAddSubMenu("Block",bg4);

	glutCreateMenu(main_menu);
	glutAddMenuEntry("Continue",CONTINUE);
	glutAddMenuEntry("Restart",RESTART);
	glutAddSubMenu("Color",bg);
	glutAddSubMenu("Speed",sp);
	glutAddMenuEntry("Quit Game",QUIT);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void revert()
{
	ball.velx=0.35;
	ball.vely=0.35;
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
}



