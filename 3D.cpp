
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>

void Display(void);
void  CreateEnvironment(void);
void  MakeGeometry(void);
void  MakeLighting(void);
void  MakePlane(int,int);
void  HandleKeyboard(unsigned char key,int x, int y);
void  HandleSpecialKeyboard(int key,int x, int y);
void  HandleMainMenu(int);
void  HandleQualMenu(int);
void  HandleSpeedMenu(int);
void  HandleVisibility(int vis);
void  HandleIdle(void);
void  DrawTextXY(double,double,double,double,char *);

#define TRUE  1
#define FALSE 0
#define PI 3.141592653589793238462643

#define DRAFT  0
#define BEST   1
int drawquality = DRAFT;
int spinplane = TRUE;
int planedirection = 1;
double updownrotate = 60;
int ballbounce = TRUE;
double ballspeed = 2;

#define SPHEREID    1
#define BOXID       2
#define PLANEID     3
#define TEXTID      4
int main(int argc,char **argv)
{
	int mainmenu,speedmenu,qualitymenu;
   
   /* Set things up and go */
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowPosition(50,50);
   glutInitWindowSize(500,500);
   glutCreateWindow("BOUNCING A BALL OVER A ROTATING A SURFACE");
   glutDisplayFunc(Display);
   glutVisibilityFunc(HandleVisibility);
   glutKeyboardFunc(HandleKeyboard);
   glutSpecialFunc(HandleSpecialKeyboard);
   CreateEnvironment();

   /* Set up some menus */
   speedmenu = glutCreateMenu(HandleSpeedMenu);//speed menu
   glutAddMenuEntry("Slow",1);
   glutAddMenuEntry("Medium",2);
   glutAddMenuEntry("fast",3);
   qualitymenu=glutCreateMenu(HandleQualMenu);//menu for display mode
   glutAddMenuEntry("Draft",1);
   glutAddMenuEntry("Best",2);
   mainmenu = glutCreateMenu(HandleMainMenu);//main menu
   glutAddMenuEntry("Toggle plane spin",1);
   glutAddMenuEntry("Toggle ball bounce",2);
   glutAddSubMenu("Ball speed",speedmenu);
   glutAddSubMenu("Quality",qualitymenu);
   glutAddMenuEntry("Quit",100);
   glutAttachMenu(GLUT_RIGHT_BUTTON);

   glutMainLoop();
   return(0);
}
/* This is where global settings are made, that is, 
   things that will not change in time */
void CreateEnvironment(void)
{
   glEnable(GL_DEPTH_TEST);

   if (drawquality == DRAFT) {
      glShadeModel(GL_FLAT);
   }

   else if (drawquality == BEST) {
      glEnable(GL_LINE_SMOOTH);
      glEnable(GL_POINT_SMOOTH);
      glEnable(GL_POLYGON_SMOOTH); 
      glShadeModel(GL_SMOOTH);    
      glDisable(GL_DITHER);         /* Assume RGBA capabilities */
   }
   glLineWidth(1.0);
   glPointSize(1.0);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   glFrontFace(GL_CW);
   glDisable(GL_CULL_FACE);
   glClearColor(0.0,0.0,0.0,0.0);         /* Background colour */
   glEnable(GL_COLOR_MATERIAL);
}
/* This is the basic display callback routine
   It creates the geometry, lighting, and viewing position
   In this case it rotates the plane around the scene*/
void Display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
   MakePlane(0,0);
   MakeLighting();
   MakeGeometry();
   glPopMatrix();
   glutSwapBuffers();
}
/*   Create the geometry*/
void MakeGeometry(void)
{
   
   double radius = .5;
   static double theta = 0;
   GLfloat mshin1[] = {1.0};               /* For the sphere */
   GLfloat mspec1[] = {0.5,0.5,0.5,1.0};
   GLfloat mdiff1[] = {0.6,0.0,0.6,1.0};
   GLfloat mamb1[]  = {0.1,0.0,0.1,1.0};
   GLfloat mdiff2[] = {0.0,1.0,0.0,1.0};   /* For the plane */
   GLfloat mamb2[]  = {0.0,0.2,0.0,1.0};
   GLfloat mdiff3[] = {0.5,0.5,0.5,1.0};  /* For the boxes */
   GLfloat mamb3[]  = {0.2,0.2,0.2,1.0};
   /* Create a ground plane */
   glLoadName(PLANEID);
   if (drawquality > DRAFT)
      glBegin(GL_POLYGON);
   else
      glBegin(GL_POLYGON);
   glColor3f(0.0,1.0,1.0);  //color for plane
   if (drawquality > DRAFT) {
      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff2);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb2);
   }
   glNormal3f( 0.0, 1.0, 0.0);
   glVertex3f( 2.0, 0.0, 2.0);
   glVertex3f( 2.0, 0.0,-2.0);
   glVertex3f(-2.0, 0.0,-2.0);
   glVertex3f(-2.0, 0.0, 2.0); 
   glEnd();
   /* Place a few  boxes around the plane */
   glLoadName(BOXID);
      glColor3f(1.0,0.0,1.0);
      if (drawquality > DRAFT) {
      glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff3);
      glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb3);
   }
   glPushMatrix();
       glTranslatef(1.8,0.2,1.8);//first right box
	  if (drawquality > DRAFT)
      glutSolidCube(0.4);
   else
      glutWireCube(0.4);
      glTranslatef(-3.6,0.0,0.0);//second left box
   if (drawquality > DRAFT)
      glutSolidCube(0.4);
   else
      glutWireCube(0.4);

     glTranslatef(0.0,0.0,-3.6);   // for first left box
   if (drawquality > DRAFT)
      glutSolidCube(0.4);
   else
      glutWireCube(0.4);
   glTranslatef(3.6,0.0,0.0);   //for second right box
   if (drawquality > DRAFT)
      glutSolidCube(0.4);
   else
      glutWireCube(0.4);
   glPopMatrix();
   /* Create a magenta bouncing ball */
   glLoadName(SPHEREID);
  // glColor3f(0.6,0.0,0.6);
   if (drawquality > DRAFT) {
      glMaterialfv(GL_FRONT,GL_SHININESS,mshin1);
      glMaterialfv(GL_FRONT,GL_SPECULAR,mspec1);
      glMaterialfv(GL_FRONT,GL_DIFFUSE,mdiff1);
      glColor3f(1.0,1.0,.0);
	  glLoadName(TEXTID);
   DrawTextXY(-2.0,-0.25,2.0,0.001," An OpenGL Miniproject    ");
   }glColor3f(0.6,0.0,0.6);
   glPushMatrix();
   glTranslatef(0.0,radius+0.5*(1+sin(PI*theta/180)),0.0);
   glScalef(radius,radius,radius);
   if (ballbounce)
      theta += ballspeed;
   if (drawquality > DRAFT)
      glutSolidSphere(1.0,32,32);
   else
      glutWireSphere(1.0,32,32);
   glPopMatrix();
   glColor3f(1.0,1.0,.0);
      /* Write some text */
   glLoadName(TEXTID);
   DrawTextXY(-2.0,-0.25,2.0,0.001," An OpenGL Miniproject    ");
}
/*   Set up the lighing environment*/
void MakeLighting(void)
{
   GLfloat globalambient[] = {0.4,0.4,0.4,1.0};

   /* The specifications for light sources */
    GLfloat pos0[] = {0.6,.8,.8,0.0};      /* w = 0 == infinite distance */
   GLfloat dif0[] = {5.0,5.0,5.0,1.0};
   GLfloat pos1[] = {-5.0,-5.0,5.0,0.0};   /* Light from below */
  GLfloat dif1[] = {0.4,0.4,0.4,1.0};      /* Fainter */
   GLfloat pos3[] = {5.0,-2.0,5.0,0.0};   /* Light from below */
  GLfloat dif3[] = {0.8,0.8,0.8,1.0};      /* Fainter */


   if (drawquality > DRAFT) {
      /* Set ambient globally, default ambient for light sources is 0 */
      glLightModelfv(GL_LIGHT_MODEL_AMBIENT,globalambient);
      glLightfv(GL_LIGHT0,GL_POSITION,pos0);
      glLightfv(GL_LIGHT0,GL_DIFFUSE,dif0);
      glLightfv(GL_LIGHT1,GL_POSITION,pos1);
      glLightfv(GL_LIGHT1,GL_DIFFUSE,dif1);
	  glLightfv(GL_LIGHT2,GL_POSITION,pos3);
      glLightfv(GL_LIGHT2,GL_DIFFUSE,dif3);
     
     
	  glEnable(GL_LIGHT0);
      glEnable(GL_LIGHT1);
	  glEnable(GL_LIGHT2);
      glEnable(GL_LIGHTING);
   }
   else if(drawquality==DRAFT)
   {
	   glDisable(GL_LIGHT0);
	   glDisable(GL_LIGHT1);
	   glDisable(GL_LIGHTING);
   }
}
/* Set up the view  */
void MakePlane(int x,int y)
{
   static double theta = 0;
     /* Plane setup */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(70.0,          /* Field of view */
                   1.0,          /* aspect ratio  */
                   0.1,1000.0);  /* near and far  */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(5*cos(theta*PI/180)*sin(updownrotate*PI/180),
             5*cos(updownrotate*PI/180),
             5*sin(theta*PI/180)*sin(updownrotate*PI/180), 
             0.0,0.0,0.0,                                   /* Focus    */
             0.0,1.0,0.0);                                  /* Up       */
   if (spinplane)
      theta += (planedirection * 0.2);
}
/*   Deal with plain key strokes*/
void HandleKeyboard(unsigned char key,int x, int y)
{
   switch (key) {
   case 27: /* ESC */
   case 'Q':
   case 'q': exit(0); break;
   case 's':
   case 'S': spinplane = !spinplane; break;
   case 'b':
   case 'B': ballbounce = !ballbounce; break;
   }
}
/*   Deal with special key strokes */
void HandleSpecialKeyboard(int key,int x, int y)
{
   switch (key) {
   case GLUT_KEY_LEFT:  planedirection = -1; break;
   case GLUT_KEY_RIGHT: planedirection = 1;  break;
   case GLUT_KEY_UP:    updownrotate -= 2;  break;
   case GLUT_KEY_DOWN:  updownrotate += 2;  break;
   }
}

/*   Handle the main menu*/
void HandleMainMenu(int whichone)
{
   switch (whichone) {
   case 1: spinplane = !spinplane; break;
   case 2: ballbounce = !ballbounce; break;
   case 100: exit(0); break;
   }
}
/*   Handle the ball speed sub menu*/
void HandleSpeedMenu(int whichone)

{   switch (whichone) {
   case 1: ballspeed = 0.5; break;
   case 2: ballspeed = 2;   break;
   case 3: ballspeed = 10;  break;
   }
}
void HandleQualMenu(int whichone)
{   switch (whichone) {
   case 1: drawquality=DRAFT; break;
   
   case 2: drawquality=BEST;  break;
   }
}
/*   How to handle visibility*/
void HandleVisibility(int visible)
{   if (visible == GLUT_VISIBLE)
      glutIdleFunc(HandleIdle);
   else
      glutIdleFunc(NULL);
}
/*   What to do on an idle event*/
void HandleIdle(void)
{   glutPostRedisplay();
}

/*   Draw text in the x-y plane
   The x,y,z coordinate is the bottom left corner (looking down -ve z axis)*/
void DrawTextXY(double x,double y,double z,double scale,char *s)
{   unsigned int i;
   glPushMatrix();
   
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i<strlen(s);i++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
   glPopMatrix();
}
