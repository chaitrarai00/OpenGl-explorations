#include<GL/glut.h>
#include<math.h>
#define DEG2RAD 3.1415/180
void semicircle(float radius,float u,float v)
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
for (int i=135;i<=315;i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

   glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
semicircle(20.0,100,50);
glutSwapBuffers();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(400,400);
glutCreateWindow("Simple");
glutDisplayFunc(display);
glutIdleFunc(display);
glutMainLoop();
return 0;
}
