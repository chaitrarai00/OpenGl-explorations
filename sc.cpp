#include<GL/glut.h>
#include<stdio.h>
GLint x1=200,x2=100,x3=200,x4=300,y1=200,y2=300,y3=400,y4=300;

void edgedetect(GLint x1,GLint y1,GLint x2,GLint y2,GLint *le,GLint *re)
{
int mx,x,temp;
int i;
if((y2-y1)<0)
{
temp=y1;y1=y2;y2=temp;
temp=x1;x1=x2;x2=temp;
}
if((y2-y1)!=0)
{
mx=(x2-x1)/(y2-y1);
}
else
{
mx=x2-x1;
}
x=x1;
for(i=y1;i<y2;i++)
{
if(x<le[i])
{
le[i]=x;
}
if(x>re[i])
{
re[i]=x;
}
x+=mx;
}
}

void drawpixel(int m,int n)
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_POINTS);
glVertex2i(m,n);
glEnd();
}
void scanfill()
{
int le[500],re[500];
int i,y;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
edgedetect(x1,y1,x2,y2,le,re);
edgedetect(x2,y2,x3,y3,le,re);
edgedetect(x3,y3,x4,y4,le,re);
edgedetect(x4,y4,x1,y1,le,re);
for(y=0;y<500;y++)
{
for(i=le[y];i<re[y];i++)
{
drawpixel(i,y);
}
}
}
void display()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);
glEnd();
scanfill();
glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(800,600);
glutInitWindowPosition(0,0);
glutCreateWindow("scanfill");
glutDisplayFunc(display);
gluOrtho2D(0.0,400.0,0.0,500.0);
glutMainLoop();
return 0;
}
