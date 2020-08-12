#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
GLdouble l,r,b,t;
float rd=0.2;
GLfloat BXMAX,BXMIN,BYMAX,BYMIN;
GLfloat BkMAX,BkMIN,BtMAX,BtMIN;
GLfloat x=0,y=-0.7,k=0,tr=-0.5;
GLfloat fm=0.0001f,fm1=0.0001f;  
GLfloat fn=0.00007f,fn1=0.00007f;
int a[10]={0,0.1,-0.2,0.3,-0.4,-0.5,-0.6,0.7,-0.8,-0.9};
int c,lc;
int p,q,pz,qz;
int score;
int missed;
//////////////////////////// init func starts////
void initGL()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glLoadIdentity();
glPointSize(5);
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(-1,1,-1,1);
}
//////////////////////////// init func ends////



//////////////////////////// idle starts////
void idle()
{
glutPostRedisplay();
}

void print(int x,int y,int z,char *string){
    glRasterPos2f(x,y);
    int i;
    int len=strlen(string);

    for(i=0; i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);

    }
}
//////////////////////////// idle ends ////



//////////////////////////// mouse active func starts////
void processMouseActiveMotion(int xz,int yz){
pz=xz;
qz=yz;
printf("%d  %d \n",pz,qz);
}
//////////////////////////// mouse active func ends////




//////////////////////////// mouse passive func starts////
void mouseClicks(int button, int state, int xm, int ym) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        p=xm;
    q=ym;}
float mp=0,mq=0;
printf("%d %d \n",p,q);
printf("%f %f \n",x,y);
mp=(x+1.3)*307.692307692;
mq=(1-y)*300;
printf("%f %f \n",mp,mq);

mp=abs(mp);
mq=abs(mq);
int ad,b,cd;
ad=pow((p-mp),2);
b=pow((q-mq),2);
cd=sqrt(ad+b);
printf("%d================ \n",cd);
if(cd<50){ score++;
lc=rand()%10;
x=a[lc]; y=-0.7;
c=rand()%10;
          x=a[c]; y=-0.7;  
}



mp=(k+1.3)*307.692307692;
mq=(1-tr)*300;

mp=abs(mp);
mq=abs(mq);

ad=pow((p-mp),2);
b=pow((q-mq),2);
cd=sqrt(ad+b);

if(cd<50){ score++;
lc=rand()%10;
k=a[lc]; tr=-0.7;

c=rand()%10;
k=a[c+1]+c; tr=-0.7;
}
}
//////////////////////////// mouse passive func ends////


//////////////////////////// display func starts////
void display(){
glClear(GL_COLOR_BUFFER_BIT); 

glPushMatrix();
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(-1.39,0.99);
glVertex2f(1.39,0.99);
glVertex2f(1.39,-1);
glVertex2f(-1.39,-1);
glEnd();
glPopMatrix();

////////////////////////////////s

glPushMatrix();
glTranslatef(0.9,0.7,0);
glBegin(GL_POLYGON);
glColor(0.0,1.0,0.0);
glVertex2f(-0.6,0.73);
glVertex2f(-0.4,0.63);
glVertex2f(-0.3,0.83);
glVertex2f(-0.2,0.4);
glVertex2f(-0.1,0.56);
glVertex2f(-0.1,0.73);
glPopMatrix();

glPushMatrix();
glTranslatef(0.87,0.73,0);
glPushMatrix();
         glColor3f(1,1,1);
     glTranslatef(0,1,1);
              glBegin(GL_POINTS);
              glVertex2f(-0.5,0.7);
        glVertex2f(-0.58,0.73);
              glVertex2f(-0.55,0.71);
glVertex2f(-0.6,0.73);
glVertex2f(-0.4,0.63);
glVertex2f(-0.3,0.83);
glVertex2f(-0.2,0.4);
glVertex2f(-0.1,0.56);
glVertex2f(-0.1,0.73);
glVertex2f(0.4,0.63);
glVertex2f(0.3,0.83);
glVertex2f(0.2,0.4);
glVertex2f(0.1,0.56);
glVertex2f(0.6,0.63);
glVertex2f(0.7,0.83);
glVertex2f(0.5,0.4);
glVertex2f(0.9,0.56);
glVertex2f(-1,0.63);
glVertex2f(-0.9,0.83);
glVertex2f(-1,0.4);
glVertex2f(-0.9,0.56);
              glEnd();
glPopMatrix();


///////////////////////////////////e

//////////////////////////////////////////////////////////////////

 
glPopMatrix();
glPushMatrix();
      glTranslatef(1.2,-0.6,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();
glPushMatrix();
          //glTranslatef(-1,-0.6,0);
glColor3f(1,1.0,0.0);
          glBegin(GL_QUADS);
           glVertex2f(-1.4,-0.6);
              glVertex2f(-1.2,-0.6);
              glVertex2f(-1.2,0);
              glVertex2f(-1.4,0);
              glEnd();
glPopMatrix();
glPushMatrix();
      glTranslatef(-1.23,0.1,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();
glPushMatrix();
      glTranslatef(-1,0.25,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();
glPushMatrix();
      glTranslatef(-1,0.4,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();
glPushMatrix();
      glTranslatef(-1.3,0.55,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();
glPushMatrix();
      glTranslatef(-1.4,0.3,0);
      glBegin(GL_POLYGON);
          glColor3f(0,1.0,0.0);
          for(i=0;i<circle_points;i++)
        {
               angle=2*PI*i/circle_points;
               glVertex2f((cos(angle))*rd,(sin(angle))*rd);
        }
         glEnd();
glPopMatrix();

glPushMatrix();
          glColor3f(0,0,0);
              glBegin(GL_LINE_STRIP);
              glVertex2f(0,-0.7);
              glVertex2f(0.03,-0.73);
              glVertex2f(0.05,-0.71);
              glEnd();
glPopMatrix();
glPushMatrix();
         glColor3f(0,0,0);
              glBegin(GL_LINE_STRIP);
              glVertex2f(0.5,-0.7);
              glVertex2f(0.53,-0.73);
              glVertex2f(0.55,-0.71);
              glEnd();
glPopMatrix();
glPushMatrix();
         glColor3f(0,0,0);
              glBegin(GL_LINE_STRIP);
              glVertex2f(-0.5,-0.7);
        glVertex2f(-0.53,-0.73);
              glVertex2f(-0.55,-0.71);
              glEnd();
glPopMatrix();

glPushMatrix();
         glColor3f(0,0,0);
      glTranslatef(0,0,0);
              glBegin(GL_LINE_STRIP);
              glVertex2f(-0.5,-0.7);
        glVertex2f(-0.53,-0.73);
              glVertex2f(-0.55,-0.71);
              glEnd();
glPopMatrix();



///////////////////////////////////////////////////score board//


    glPushMatrix();
    ///glColor3f(0.0,0.0,1.0);
         //glTranslatef(0.7, 0.92, 0.00);
         glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
         glTranslatef(0.92, 0.92, 0.00);
         switch(score){
        case 0: d=0; break;
        case 1: d=1; break;
        case 2: d=2; break;
        case 3: d=3; break;
        case 4: d=4; break;
        case 5: d=5; break;
        case 6: d=6; break;
        case 7: d=7; break;
        case 8: d=8; break;
        case 9: d=9; break;
        case 10: d=10; break;
        case 11: d=11; break;
        case 12: d=12; break;
        case 13: d=13; break;
        case 14: d=14;break;
     //case 15: d="14";break;
     //case 16: d="14";break;
     //case 17: d="14";break;
     //case 18: d="14";break;
     //case 19: d="14";break;
     //case 20: d=20;break;
        default: d=00;
        }
       glPopMatrix();



///////////////////////////////////////////////////score board end///
/////////////////////////////////////////////////////////////////

if(missed<3){
glutSwapBuffers();
} 
else
{
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
         glTranslatef(0.0,0.4,0.00);
glPopMatrix();
glutSwapBuffers();
}
 fm=fm*1.0002;
fn=fn*1.0002;
fm1=fm1*1.0002;
fn1=fn1*1.0002;
       x=x+fm;
    y=y+fn;
    k=k+fm1;
    tr=tr+fn1;


        if(x > BXMAX){ x=BXMAX; fm=-fm; }
        else if(x < BXMIN){ x=BXMIN; fm=-fm; }
        if(y > BYMAX){

    missed=missed+1;
if(missed>=3){ x=0; y=0; fm=0; fn=0; 


 } else{
        c=rand()%10;
          x=a[c]; y=-0.7; } }
        else if(y < BYMIN){ y=BYMIN; fn=-fn; }


    if(k > BkMAX){ k=BkMAX; fm1=-fm1; }
        else if(k < BkMIN){ k=BkMIN; fm1=-fm1; }
        if(tr > BtMAX){
missed=missed+1;
if(missed>=3){ k=0; tr=0; fm1=0; fn1=0;  printf("GAME OVER");
  } else{
        c=rand()%10;
          k=a[c+1]+c; tr=-0.7; } }
        else if(tr < BtMIN){ tr=BtMIN; fn1=-fn1; }




/////////////////////////////////////////////////////////////////


}




//////////////////////////// display func ends////



//////////////////////////// reshape func starts////
void reshape(int width, int height) {
   if (height == 0) height = 1;           
   GLfloat aspect = (GLfloat)width / (GLfloat)height;


   glViewport(0, 0, width, height);


   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (width >= height) {

      l=-1.0*aspect;
    r=1.0*aspect;
    b=-1.0;
    t=    1.0;

   } else {

    l=-1.0;
    r=1.0;
    b=-1.0/aspect;
    t= 1.0/aspect;
   }
gluOrtho2D(l,r,b,t);

BXMAX=r-(rd/4);
BXMIN=l+(rd/4);
BYMAX=t-(rd/4);
BYMIN=b+(rd/4);
BkMAX=r-(rd/4);
BkMIN=l+(rd/4);
BtMAX=t-(rd/4);
BtMIN=b+(rd/4);

}
//////////////////////////// reshape func ends////


int main(int argc,char **argv) 
{
   glutInit(&argc,argv);        
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(800,600); 
   glutInitWindowPosition(50, 50);
   glutCreateWindow("sky view");
   glutReshapeFunc(reshape);
  // glutSpecialFunc(specialKeys);
   glutDisplayFunc(display);      
 glutIdleFunc(idle);           
   initGL();
glutMouseFunc(mouseClicks);
glutMotionFunc(processMouseActiveMotion);                   
   glutMainLoop();               
   return 0;
}
