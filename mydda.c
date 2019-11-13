#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
int ww = 600, wh = 400; 
int first = 0; 
void display(void)
{
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-y1;
float slope= dy/dx; 
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;
 
x= x1;
y=y1;

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
 
for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
glFlush();
}
void mouse(int btn, int state, int x, int y) 
{ 
if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
{ 
switch(first) 
{ 
case 0: 
x1 = x; 
y1 = (wh-y); 
first = 1; 
break; 
case 1: 
x2 = x; 
y2 = (wh-y); 
display(); 
first = 0; 
break; 
} 
} 
} 
void init(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0); 
glColor3f(1.0, 1.0, 1.0);
glViewport(0,0,ww,wh); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh); 
glMatrixMode(GL_MODELVIEW); 
}

void press(unsigned char key, int x,int y)
{
if(key==27)
glutDestroyWindow(glutGetWindow());
}
 
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutMouseFunc(mouse);
glutKeyboardFunc(press);
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
