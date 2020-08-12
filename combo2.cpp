#include<stdio.h>
#include<GL/glut.h>
#include <stdlib.h>
#define SPEED 40.0     //speed of car
float i=0.0;    //movement of car
float m=0.0;    //movement of clouds
int day=1;        //1 for day ,0 for night
GLint c=0;
void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void bird()
{

glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(10+i,530);
glVertex2f(10+i,570);
glVertex2f(40+i,550);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(30+i,560);
glVertex2f(100+i,550);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(60+i,510);
glVertex2f(100+i,550);
glEnd();
}

glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(90+i,550);
glVertex2f(110+i,560);
glVertex2f(130+i,545);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112+i,555);
glVertex2f(114+i,555);
glVertex2f(114+i,557);
glVertex2f(112+i,557);
glEnd();
}

void birdu()
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(10+i,330);
glVertex2f(10+i,370);
glVertex2f(40+i,350);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(30+i,360);
glVertex2f(100+i,350);
glEnd();
if(count<=5)
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(60+i,310);
glVertex2f(100+i,350);
glEnd();
count++;
}
else
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+i,350);
glVertex2f(60+i,390);
glVertex2f(100+i,350);
glEnd();
count=0;
}
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.55);
glVertex2f(90+i,350);
glVertex2f(110+i,360);
glVertex2f(130+i,345);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112+i,355);
glVertex2f(114+i,355);
glVertex2f(114+i,357);
glVertex2f(112+i,357);
glEnd();
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,625,l);
}


//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}






//grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100+100,450);
glVertex2f(1100+100,160);
glEnd();

}
else
{
//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//moon
int l;

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}

//star1

glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();

//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();

//star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();

//star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();

//star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();

//star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();



//grass
glColor3f(0.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();



}


//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350-220,325-90);
glVertex2f(350-220,395-90);
glVertex2f(365-220,395-90);
glVertex2f(365-220,325-90);
glEnd();


	for(l=0;l<=30+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(340-230,400-60,l);
		draw_circle(380-210,400-60,l);
	}

	for(l=0;l<=25+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350-230,440-40,l);
		draw_circle(370-210,440-40,l);
	}

	for(l=0;l<=20+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360-220,465-10,l);
	}

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350+600,325-90);
glVertex2f(350+600,395-90);
glVertex2f(365+600,395-90);
glVertex2f(365+600,325-90);
glEnd();


	for(l=0;l<=30+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(340+590,400-60,l);
		draw_circle(380+610,400-60,l);
	}

	for(l=0;l<=25+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350+590,440-40,l);
		draw_circle(370+610,440-40,l);
	}

	for(l=0;l<=20+20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360+600,465-10,l);
	}

//car 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(25+i,50);
glVertex2f(25+i,125);
glVertex2f(75+i,200);
glVertex2f(175+i,200);
glVertex2f(200+i,125);
glVertex2f(250+i,115);
glVertex2f(250+i,50);
glEnd();


//windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(35+i,125);
glVertex2f(80+i,190);
glVertex2f(115+i,190);
glVertex2f(115+i,125);
glEnd();

glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(125+i,125);
glVertex2f(125+i,190);
glVertex2f(170+i,190);
glVertex2f(190+i,125);
glEnd();


for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(75+i,50,l);
	draw_circle(175+i,50,l);
   }




//car2

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-470+i,50);
glVertex2f(-470+i,112);
glVertex2f(-400+i,125);
glVertex2f(-372+i,210);
glVertex2f(-210+i,210);
glVertex2f(-180+i,125);
glVertex2f(-135+i,125);
glVertex2f(-110+i,50);
glEnd();


//windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-410+i,125);
glVertex2f(-364+i,200);
glVertex2f(-300+i,200);
glVertex2f(-300+i,125);
glEnd();

glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-290+i,125);
glVertex2f(-290+i,200);
glVertex2f(-217+i,200);
glVertex2f(-192+i,125);
glEnd();


for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-350+i,50,l);
	draw_circle(-200+i,50,l);
   }


glFlush();
}

void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
i+=SPEED/10;
++m;
if(i>1630)
 i=0.0;
if(m>1100)
m=0.0;
glutPostRedisplay();
}

void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'd':
	case 'D':
		day=1;
		break;

	case 'n':
case 'N':
		day=0;
		break;

    };
}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
for(c=0;c<1100;c++)
{
glPushMatrix();
bird();
birdu();
glPopMatrix();
}
glFlush();
}

int main(int argc,char** argv)
{
printf("Press 'd' or 'D' to make it day \n");
printf("Press 'n' or 'N' to make it night \n");
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1100.0,700.0);
glutInitWindowPosition(0,0);
glutCreateWindow("combo2");
glutDisplayFunc(display);
glutIdleFunc(idle);
glutKeyboardFunc(keyboardFunc);
myinit();
glutMainLoop();
return 0;
}



