

/*
 * sea.c
 *
 *  Created on: Mar 28, 2014
 *      Author: kamath
 */
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int glob=0;
int boat=0;
int v=0;
int u=0;
int n;
int bi;
int s;
int count=0;
int i;
int c;

void day();
void night();
void drawsea();
void drawsea2();
void mountain();
void mountain2();
void drawtree2();
void drawtree();
void drawboat();
void redrawboat();
void drawsmallboat();
void circle_draw(GLint h,GLint k,GLint r);
void plotpixels(GLint h,GLint k,GLint x,GLint y);
void display();


void key(unsigned char key,int x,int y);
void mainmenu(int id);

void init();
int main(int argc,char** argv);



void init()
{	glClearColor(.8,.5,0.0,1.0);

	glColor3f(1.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2200.0,0.0,1800.0);

	printf("press 'x' to move boat in +ve x-direction\n");
	printf("press 'y' to move boat in -ve x-direction\n");
	printf("press 'z' to move the moon in +ve y-direction\n");
	printf("press 'w' to move the moon in -ve y-direction\n");
	printf("press 's' to stop the smallboat\n");
	printf("press 'r' to restart the smallboat\n");

	glutPostRedisplay();
}

//To draw Mountain for DAY

void mountain()
{

	glColor3f(0.60,0.40,0.12);
    glBegin(GL_TRIANGLES);
	glVertex2f(250,1300);
		glColor3f(0.55,0.40,0.12);
	glVertex2f(0,1600);
		glColor3f(0.55,0.40,0.12);
	glVertex2f(0,1300);
	glEnd();
	glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(100,1300);
	glVertex2f(300,1600);
	glVertex2f(400,1600);
		glColor3f(0.55,0.40,0.12);
	glVertex2f(500,1650);
	glVertex2f(700,1630);
		glColor3f(0.55,0.40,0.12);
	glVertex2f(900,1300);
	glEnd();

	glColor3f(0.60,0.40,0.12);
	glBegin(GL_TRIANGLES);
	glVertex2f(300,1300);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(700,1680);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(900,1300);
	glEnd();
	glColor3f(0.60,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(500,1300);
	glVertex2f(700,1500);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(900,1650);
	glVertex2f(1300,1500);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(1500,1450);
	glVertex2f(1600,1300);
	glEnd();
	glColor3f(0.62,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(1400,1300);
	glVertex2f(1800,1600);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(1850,1650);
	glVertex2f(1900,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(2000,1300);
	//glEnd();glColor3f(0.62,0.42,0.13);
	glBegin(GL_TRIANGLES);
	glVertex2f(2000,1300);
	glColor3f(0.50,0.40,0.12);
	glVertex2f(2200,1600);
	glColor3f(0.55,0.40,0.12);
	glVertex2f(2200,1300);

//glEnd();



}

//To Draw Mountain for Night

void mountain2()
{

	glColor3f(0.60,0.40,0.12);
    glBegin(GL_TRIANGLES);
	glVertex2f(250,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(0,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(0,1300);
	glEnd();
	glColor3f(0.60,0.40,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(100,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(300,1600);
	glColor3f(0.10,0.10,0.0);

	glVertex2f(400,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(500,1650);
	glVertex2f(700,1630);
	glColor3f(0.10,0.10,0.0);

	glVertex2f(900,1300);
	glEnd();
	glColor3f(0.60,0.40,0.12);
	glBegin(GL_TRIANGLES);
	glVertex2f(300,1300);
	glColor3f(0.10,0.10,0.0);

	glVertex2f(700,1680);
	glColor3f(0.10,0.10,0.0);

	glVertex2f(900,1300);
	glEnd();
	glColor3f(0.60,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(500,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(700,1500);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(900,1650);
	glVertex2f(1300,1500);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1500,1450);
	glVertex2f(1600,1300);
//	glEnd();
	glColor3f(0.62,0.42,0.12);
	glBegin(GL_POLYGON);
	glVertex2f(1400,1300);
	glVertex2f(1800,1600);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1850,1650);
	glVertex2f(1900,1600);
	glColor3f(0.10,0.10,0.0);

	glVertex2f(2000,1300);
	glEnd();
	glColor3f(0.62,0.42,0.13);
	glBegin(GL_TRIANGLES);
	glVertex2f(2000,1300);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2200,1600);
		glColor3f(0.10,0.10,0.0);
//	glColor3f(0.60,0.40,0.0);

	glVertex2f(2200,1300);
	glEnd();

	//to draw road for Night

	glPointSize(8.0);
	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,700);
	glColor3f(0.05,0.05,0.0);
	glVertex2f(2200,400);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1700,0);
	glColor3f(0.05,0.07,0.0);
	glVertex2f(1400,0);
	glEnd();
	glColor3f(.8,.7,0.0);
	glBegin(GL_LINES);
	glVertex2f(2200,550);
	glVertex2f(1600,0);
	glVertex2f(2200,560);
	glVertex2f(1590,0);
	glEnd();


}


void draw_pixel(GLint cx,GLint cy)
{	glPolygonMode(GL_FRONT,GL_FILL);

	glBegin(GL_POINTS);

	glVertex2i(cx,cy);

	glEnd();
}


void plotpixels(GLint h,GLint k,GLint x,GLint y)
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

void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;

	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

//To draw Sea for DAY

void drawsea()
{
	glColor3f(0.0,0.6,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,900);
	glVertex2f(2200,900);
	glColor3f(0.0,0.7,1.0);
	glVertex2f(2200,800);
	glVertex2f(2200,750);
	glVertex2f(1900,700);
	glColor3f(0.0,0.7,1.0);
	glVertex2f(1850,600);
	glVertex2f(1800,600);
	glColor3f(.0,0.8,.9);
	glVertex2f(1700,550);
	glVertex2f(1600,550);
	glColor3f(0.0,0.6,.98);
	glVertex2f(1450,400);
	glColor3f(.0,0.8,.95);
	glVertex2f(1300,300);
	glColor3f(.0,0.7,.98);
	glVertex2f(1100,250);
	glColor3f(.0,0.8,.9);
	glVertex2f(900,200);
	glColor3f(.0,0.8,.9);
	glVertex2f(700,200);

	glColor3f(.0,0.7,.9);
	glVertex2f(500,300);
	glVertex2f(400,400);
	glColor3f(0.0,0.6,.9);
	glVertex2f(300,500);
	glVertex2f(150,600);
	glColor3f(.0,0.7,.9);
	glVertex2f(0,700);
	glVertex2f(0,1300);
	glColor3f(.0,0.8,.9);
	glVertex2f(2200,1300);
	glEnd();

}

//To draw sea for NIGHT

void drawsea2()
{

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,900);
	glColor3f(0.,0.,.0);

	glVertex2f(2200,900);
	glColor3f(.0,0.,.0);
	glVertex2f(2200,800);
	glColor3f(1.,1.,1.0);
	glVertex2f(2200,750);
	glColor3f(.0,0.,.0);
	glVertex2f(1900,700);
	glColor3f(.0,0.,.0);
	glVertex2f(1850,600);
	glColor3f(.0,0.,.0);
	glVertex2f(1800,600);

	glVertex2f(1700,550);
	glColor3f(.0,0.,.0);
	glVertex2f(1600,550);
	glColor3f(.0,0.,.0);

	glVertex2f(1450,400);
	glColor3f(.0,0.0,.0);
	glVertex2f(1300,300);
	glColor3f(.0,0.,.0);
	glVertex2f(1100,250);
	glColor3f(.0,0.0,.0);
	glVertex2f(900,200);
	glColor3f(.0,0.,.0);
	glVertex2f(700,200);

	glColor3f(.0,0.0,.0);
	glVertex2f(500,300);
	glColor3f(.0,0.0,.0);
	glVertex2f(400,400);
	glColor3f(0.0,0.,.0);
	glVertex2f(300,500);
	glColor3f(.0,0.0,.0);
	glVertex2f(150,600);
	glColor3f(.0,0.,.0);
	glVertex2f(0,700);
	glColor3f(.0,0.0,.0);
	glVertex2f(0,1300);
	glColor3f(.0,0.,.0);
	glVertex2f(2200,1300);
	glColor3f(.0,0.,.0);
	glEnd();


}



void night()
{	// to set the background color to black
int l;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,1800);
	glVertex2f(0,1800);
	glVertex2f(0,0);
	glVertex2f(2200,0);
	glEnd();

	//to draw the moon
glPointSize(9.0);
	glColor3f(1.0,1.0,1.0);
for(l=0;l<=80;l++)
{
	circle_draw(1400,1600,l);
}
	


//to draw the stars
glPointSize(2.2);
	glBegin(GL_POINTS);
	glVertex2f(900,1700);
	glVertex2f(800,1700);
	glVertex2f(700,1700);
	glVertex2f(200,1500+250);
	glVertex2f(1800-1000,1700-100);
	glVertex2f(100,1600);
	glVertex2f(150,1650);
	glVertex2f(50,1600);
	glVertex2f(100,1750);
	glVertex2f(125,1550);
	glVertex2f(100,1500);
	glVertex2f(150,1550);
	glVertex2f(200,1500);
	glVertex2f(250,1600);
	glVertex2f(300,1650);
	glVertex2f(400,1650);
	glVertex2f(350,1675);
	glVertex2f(275,1700);
	glVertex2f(500,1750);
	glVertex2f(600,1650);
	glVertex2f(1950,1600);
	glVertex2f(1800,1600);
	glVertex2f(1850,1650);
	glVertex2f(1875,1750);
	glVertex2f(2100,1600);
	glVertex2f(2200,1700);
	glVertex2f(2150,1750);
	glVertex2f(2125,1775);
	glVertex2f(2000,1700);
	glVertex2f(1500,1700);
	glVertex2f(1550,1600);
	glVertex2f(1575,1650);
	glVertex2f(1650,1700);
	glVertex2f(1700,1650);
	glVertex2f(1800,1750);
	glVertex2f(1200,1750);
	glVertex2f(1150,1600);
	glVertex2f(1000,1775);
	glVertex2f(1100,1700);
	glVertex2f(2000,1500);
	glEnd();

      //glColor3f(.25,.25,.25);
mountain2();
glColor3f(.7,.7,.7);
drawsea2();

//to draw street light for NIGHT

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1400,0);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1425,0);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1425,250);
	glVertex2f(1400,250);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1410,280,30);
	circle_draw(1410,280,10);

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1600,200);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1625,200);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1625,350);
	glVertex2f(1600,350);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1610,380,30);
	circle_draw(1610,380,10);

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1800,380);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1825,380);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(1825,525);
	glVertex2f(1800,525);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1810,555,30);
	circle_draw(1810,555,10);

	glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2000,500);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2025,500);
	glColor3f(0.10,0.10,0.0);
	glVertex2f(2025,650);
	glVertex2f(2000,650);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(2010,680,30);
	circle_draw(2010,680,10);

	//to draw tree and boat

	drawtree2();
	drawsmallboat();
	drawboat();
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
if(count<=5)
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(60+i,510);
glVertex2f(100+i,550);
glEnd();
count++;
}
else
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,1.0,0.0);
glVertex2f(30+i,550);
glVertex2f(60+i,590);
glVertex2f(100+i,550);
glEnd();
count=0;
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

void redrawbird()
{	if(v==0)
	{
		if(i<1600)
		{

			i+=2;
			glutPostRedisplay();
		}
		else
		{	i=i-2400;
		glutPostRedisplay();
		}
	}
}
void birdu()
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(10+c,330);
glVertex2f(10+c,370);
glVertex2f(40+c,350);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+c,350);
glVertex2f(30+c,360);
glVertex2f(100+c,350);
glEnd();
if(count<=5)
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+c,350);
glVertex2f(60+c,310);
glVertex2f(100+c,350);
glEnd();
count++;
}
else
{
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.5);
glVertex2f(30+c,350);
glVertex2f(60+c,390);
glVertex2f(100+c,350);
glEnd();
count=0;
}
glBegin(GL_TRIANGLES);
glColor3f(1.0,0.2,0.55);
glVertex2f(90+c,350);
glVertex2f(110+c,360);
glVertex2f(130+c,345);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);
glVertex2f(112+c,355);
glVertex2f(114+c,355);
glVertex2f(114+c,357);
glVertex2f(112+c,357);
glEnd();
}

void redrawbirdu()
{	if(u==0)
	{
		if(c<1600)
		{

			c+=2;
			glutPostRedisplay();
		}
		else
		{	c=c-2400;
		glutPostRedisplay();
		}
	}
}

//To draw user BOAT

void drawboat()
{

	glColor3f(0.1,0.0,0.1);
	glBegin(GL_POLYGON);

	glVertex2f(700+n,950);
	glColor3f(.6,0.5,0.0);
	glVertex2f(800+n,800);
	glVertex2f(1200+n,800);
	glColor3f(0.1,0.0,0.1);
	glVertex2f(1400+n,950);
	glEnd();

     glColor3f(.6,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(1200+n,950);

	glColor3f(.6,0.5,0.5);
	glVertex2f(1350+n,950);
	glColor3f(.0,0.2,0.6);
	glVertex2f(1000+n,1150);
	glEnd();
	glPointSize(9.0);
	glBegin(GL_LINES);
	glVertex2f(1000+n,950);
	glVertex2f(1000+n,1150);
	glEnd();

	glColor3f(0.1,0.0,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(850+n,950);
	glVertex2f(1000+n,950);
	glVertex2f(1000+n,1000);
	glVertex2f(850+n,1000);
	glEnd();
}
void redrawboat1()
{	if(boat==0)
	{
		if(n<1600)
		{

			n+=2;
			glutPostRedisplay();
		}
		else
		{	n=n-2400;
		glutPostRedisplay();
		}
	}
}


void drawsmallboat()
{
	glColor3f(0.0,1.0,0.0);

	glBegin(GL_POLYGON);

	glVertex2f(400+bi,1200);
		glColor3f(1.0,0.6,.9);
	glVertex2f(475+bi,1100);
	glColor3f(0.3,0.0,0.2);
	glVertex2f(575+bi,1100);
	glVertex2f(650+bi,1200);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(550+bi,1200);
	glColor3f(1.0,0.6,.9);

	glVertex2f(650+bi,1200);
	glColor3f(.0,0.2,0.6);
	glVertex2f(500+bi,1250);
	glEnd();
	glPointSize(9.0);
	glBegin(GL_LINES);
	glVertex2f(500+bi,1250);
	glVertex2f(500+bi,1200);
	glEnd();

}

//To loop small boat

void redrawboat()
{	if(boat==0)
	{
		if(bi<1600)
		{

			bi+=2;
			glutPostRedisplay();
		}
		else
		{	bi=bi-2400;
		glutPostRedisplay();
		}
	}
}

// keyboard function

void key(unsigned char key,int x,int y)
{
	if(key=='x')
	{

   	  n=n+10;
   	  if(n>2000) n=-800;
     glutPostRedisplay();
	}
	if(key=='y')
	{
		n=n-10;
		if(n<-1400) n=1400;
	glutPostRedisplay();
	}
	if(key=='z')
	{	 s=s+10;
		glutPostRedisplay();
	}
	if(key=='w')
	{	s=s-10;
		glutPostRedisplay();
	}
	if(key=='s') //to stop boat
	{	boat=1;
		glutPostRedisplay();
	}
	if(key=='r') // to restart boat
	{	boat=0;
		glutPostRedisplay();
	}

}


//To draw tree for DAY

void drawtree()
{
int l;	

//stamp
	glColor3f(.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(150,0);
//		glColor3f(0.47,0.0,0.0);
	glVertex2f(150,300);
	glColor3f(0.57,0.0,0.0);
	glVertex2f(200,300);
	glColor3f(0.47,0.0,0.0);
	glVertex2f(200,0);
	glEnd();


	glColor3f(0.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(500,0);
	glVertex2f(500,250);
	glColor3f(0.57,0.0,0.0);
	glVertex2f(550,250);
	glVertex2f(550,0);
	glEnd();

	glColor3f(0.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(950,0);
	glVertex2f(950,200);
	glColor3f(0.57,0.0,0.0);
	glVertex2f(1000,200);
	glVertex2f(1000,0);
	glEnd();

for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(340-210,400-40,l);
		circle_draw(380-150,400-40,l);
	}

for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(350-210,440+40,l);
		circle_draw(370-150,440+40,l);
	}
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(360-180,465+120,l);
	}



		
	glEnd();


for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(340+140,400-100,l);
		circle_draw(380+200,400-100,l);
	}

for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(350+130,440-30,l);
		circle_draw(370+210,440-30,l);
	}
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.4,0.0);
		circle_draw(360+170,465+50,l);
	}

		
	glEnd();
for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.5,0.0);
		circle_draw(340+580,400-150,l);
		circle_draw(380+660,400-150,l);
	}
for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.5,0.0);
		circle_draw(350+570,440-90,l);
		circle_draw(370+660,440-90,l);
	}
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.5,0.0);
		circle_draw(360+610,465-10,l);
	}

		

glEnd();
}

//To draw tree for NIGHT

void drawtree2()
{
int l;


//stamp
	glColor3f(.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(150,0);
	glColor3f(0.,0.,.0);
	glVertex2f(150,300);
		glColor3f(0.1,0.0,0.0);
	glVertex2f(200,300);
		glColor3f(0.2,0.0,0.0);
	glVertex2f(200,0);
	glEnd();


	glColor3f(0.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(500,0);
	glVertex2f(500,250);
		glColor3f(0.0,0.0,0.0);
	glVertex2f(550,250);
		glColor3f(0.1,0.0,0.0);
	glVertex2f(550,0);
	glEnd();

	glColor3f(0.2,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(950,0);
	glVertex2f(950,200);
		glColor3f(0.0,0.0,0.0);
	glVertex2f(1000,200);
		glColor3f(0.1,0.0,0.0);
	glVertex2f(1000,0);
	glEnd();

for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(340-210,400-40,l);
		circle_draw(380-150,400-40,l);
	}
	
for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(350-210,440+40,l);
		circle_draw(370-150,440+40,l);
	}
	
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(360-180,465+120,l);
	}


	
	glEnd();

for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(340+140,400-100,l);
		circle_draw(380+200,400-100,l);
	}

for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(350+130,440-30,l);
		circle_draw(370+210,440-30,l);
	}
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(360+170,465+50,l);
	}
	
	glEnd();

for(l=0;l<=30+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(340+580,400-150,l);
		circle_draw(380+660,400-150,l);
	}
for(l=0;l<=25+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(350+570,440-90,l);
		circle_draw(370+660,440-90,l);
	}
for(l=0;l<=20+40;l++)
	{
		glColor3f(0.1,0.1,0.0);
		circle_draw(360+610,465-10,l);
	}
	
	glEnd();


}


void display(void)
{
int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	if(glob==1)
		night();
	if(glob==0)
		day();
   redrawboat();
   redrawboat1();
redrawbird();
redrawbirdu();

	glFlush();
	glutSwapBuffers();

}
void day()
{	//to set the sky color and ground color
int l;
	glColor3f(.8,.37,0.0);

	glBegin(GL_POLYGON);
	glVertex2f(2200,1800);
	glColor3f(.7,.37,0.0);
	glVertex2f(0,1800);
	glColor3f(.4,.6,0.0);
	glVertex2f(0,0);
			glColor3f(.4,.6,0.0);
	glVertex2f(2200,0);
	glEnd();

	// to draw the mountains
	mountain();

// to draw the sea
	drawsea();

	// to draw the sun
glPointSize(9.0);
	glColor3f(.9,0.2,0.0);
for(l=0;l<=80;l++)
{
	circle_draw(1400,1600,l);
}
	
	drawtree();

//to draw street light for DAY

		glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1400,0);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1425,0);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1425,250);
	glVertex2f(1400,250);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1410,280,30);
	circle_draw(1410,280,10);

			glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1600,200);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1625,200);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1625,350);
	glVertex2f(1600,350);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1610,380,30);
	circle_draw(1610,380,10);

			glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1800,380);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1825,380);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1825,525);
	glVertex2f(1800,525);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(1810,555,30);
	circle_draw(1810,555,10);

			glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2000,500);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(2025,500);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(2025,650);
	glVertex2f(2000,650);
	glEnd();
	glColor3f(1.0,01.0,01.0);
	circle_draw(2010,680,30);
	circle_draw(2010,680,10);
	drawsmallboat();
	drawboat();
		//to draw road DAY
bird();
birdu();
	glPointSize(8.0);
		glColor3f(0.10,0.10,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2200,700);
		glColor3f(0.05,0.05,0.0);
	glVertex2f(2200,400);
		glColor3f(0.10,0.10,0.0);
	glVertex2f(1700,0);
	glColor3f(0.05,0.07,0.0);
	glVertex2f(1400,0);
	glEnd();
		glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(2200,550);
	glVertex2f(1600,0);
	glVertex2f(2200,560);
	glVertex2f(1590,0);
	glEnd();

}


void mainmenu(int id)
{
	switch(id)
	{
		case 1:exit(0);
		break;
		case 2:glob=0;
			break;
		case 3:glob=1;
			break;

	}
	glutPostRedisplay();
}

int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(2200,1800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("sea view");

	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	glutCreateMenu(mainmenu);
	glutAddMenuEntry("QUIT",1);
	glutAddMenuEntry("DAY VIEW",2);
	glutAddMenuEntry("NIGHT VIEW",3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}


