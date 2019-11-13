    
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
using namespace std;



void init() 
{ 
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(10,10);
 glutInitWindowSize(800, 800);
 glutCreateWindow("2D Translation");
 gluOrtho2D(0,800,0,800); 
}

int xa = 200, ya = 200, xb = 400, yb = 200, xc = 400, yc = 400, xd = 200, yd = 400;
int tx = 20, ty = 20;

void line ()
{	
 glBegin(GL_POLYGON);
 glColor3f(1.0,1.0,1.0);
 glVertex2f(xa,ya);
 glVertex2f(xb,yb);
 glVertex2f(xc,yc);
 glVertex2f(xd,yd);
 glEnd();
 glFlush();
}

void Xtranslation()
{
 int t[3][3];
 t[0][0] = 1;
 t[0][1] = 0;
 t[0][2] = tx;
 t[1][0] = 0;
 t[1][1] = 1;
 t[1][2] = 0;
 t[2][0] = 0;
 t[2][1] = 0;
 t[2][2] = 1;
  
 int c1[3] = {0,0,1};
 int c2[3] = {0,0,1};
 int c3[3] = {0,0,1};
 int c4[3] = {0,0,1};
 
 
 int q1[3] = {xa,ya,1};
 int q2[3] = {xb,yb,1};
 int q3[3] = {xc,yc,1};
 int q4[3] = {xd,yd,1};
 
 float temp1,temp2,temp3,temp4;
 
 for(int i=0;i<3;i++)
 { for(int j=0;j<3;j++)
  { 
   temp1 =0; temp2 =0; temp3=0; temp4 =0;
   for(int k=0;k<3;k++)
   {
    temp1 = temp1 + t[i][k] * q1[k];
    temp2 = temp2 + t[i][k] * q2[k];
    temp3 = temp3 + t[i][k] * q3[k];
    temp4 = temp4 + t[i][k] * q4[k];
   }
   c1[i] = temp1;
   c2[i] = temp2;
   c3[i] = temp3;
   c4[i] = temp4;
  }
 }
 
 xa = c1[0]; ya = c1[1];
 xb = c2[0]; yb = c2[1];
 xc = c3[0]; yc = c3[1];
 xd = c4[0]; yd = c4[1];
 
 glClear(GL_COLOR_BUFFER_BIT);
 
 line();
}

void Ytranslation()
{
 int t[3][3];
 t[0][0] = 1;
 t[0][1] = 0;
 t[0][2] = 0;
 t[1][0] = 0;
 t[1][1] = 1;
 t[1][2] = ty;
 t[2][0] = 0;
 t[2][1] = 0;
 t[2][2] = 1;
  
 int c1[3] = {0,0,1};
 int c2[3] = {0,0,1};
 int c3[3] = {0,0,1};
 int c4[3] = {0,0,1};
 
 
 int q1[3] = {xa,ya,1};
 int q2[3] = {xb,yb,1};
 int q3[3] = {xc,yc,1};
 int q4[3] = {xd,yd,1};
 
 float temp1,temp2,temp3,temp4;
 
 for(int i=0;i<3;i++)
 { for(int j=0;j<3;j++)
  { 
   temp1 =0; temp2 =0; temp3=0; temp4 =0;
   for(int k=0;k<3;k++)
   {
    temp1 = temp1 + t[i][k] * q1[k];
    temp2 = temp2 + t[i][k] * q2[k];
    temp3 = temp3 + t[i][k] * q3[k];
    temp4 = temp4 + t[i][k] * q4[k];
   }
   c1[i] = temp1;
   c2[i] = temp2;
   c3[i] = temp3;
   c4[i] = temp4;
  }
 }
 
 xa = c1[0]; ya = c1[1];
 xb = c2[0]; yb = c2[1];
 xc = c3[0]; yc = c3[1];
 xd = c4[0]; yd = c4[1];
 
 glClear(GL_COLOR_BUFFER_BIT);
 
 line();
}

void key(int button, int x, int y)
{
 if(button == GLUT_KEY_RIGHT )
 { 
  Xtranslation(); 
  glutPostRedisplay();
 }
if(button == GLUT_KEY_UP )
 { 
  Ytranslation(); 
  glutPostRedisplay();
 }
}

void dis()
{
 
 line();
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 init();
 glutDisplayFunc(dis);
 glutSpecialFunc(key);
 glutMainLoop();
 return 0;
}
