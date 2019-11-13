#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int ww=640,wh=480;  
int first=0;  
int xi=0,yi=0,xf=0,yf=0; 

int xmin,ymin,xmax,ymax;
double p[4],q[4];
int xt1;
int yt1;
int xt2;
int yt2;



void delay(int nos) 
{ 
    int milli_seconds = 1000 * nos; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
    ; 
} 



int X1, Y1, X2, Y2; 



void display(int x1, int y1, int x2, int y2)
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



int clipping(int x1,int y1,int x2,int y2)
{
  float t1=0.0,t2=1.0;
  int dx=x2-x1;
  int dy=y2-y1;
    int i;
    float t;
    p[0]=-dx;
    q[0]=x1-xmin;
    p[1]=dx;
    q[1]=xmax-x1;
    p[2]=-dy;
    q[2]=y1-ymin;
    p[3]=dy;
    q[3]=ymax-y1;
    for(i=0;i<4;i++)
    {
        if(p[i]==0 && q[i]<0)
            return 0;
        if(p[i]<0.0)
        {
			     t=q[i]/p[i];
            if(t>t1)
                {
                  t1=t;
                }
        }
        if(p[i]>0.0)
        {  
			      t=q[i]/p[i];
            if(t<t2)
                {t2=t;}
        }
    }
    if(t1<t2)
    {  
         xt1=x1+t1*(x2-x1);
         yt1=y1+t1*(y2-y1);
         xt2=x1+t2*(x2-x1);
         yt2=y1+t2*(y2-y1);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();

        display(xmin, ymin, xmax, ymin);
        display(xmax, ymin, xmax, ymax);
        display(xmin, ymax,xmax, ymax);
        display(xmin, ymax, xmin, ymin);
        int i;

	glColor3f(0.0,1.0,0.0);
        display(xt1, yt1, xt2, yt2);

        glColor3f(0.0,0.0,1.0);
        display(xi, yi, xt1, yt1);

        glColor3f(0.0,0.0,1.0);
	 display(xt2, yt2, xf, yf);
     return 1;
    }
    else
    {
      return 0;
    }
}


void randomWindow()
{
  int flag=0;
  while(flag==0)
  {
    int randomX=(rand()%300)-150;
    int randomY=(rand()%300)-150;
    if(randomX<270&&randomX>-320)
    {

        if(randomY<190&&randomY>-240)
        {
          glClear(GL_COLOR_BUFFER_BIT);
          glColor3f(1.0,0.9,0.9);
          glFlush();
          display(xi, yi, xf, yf);
          xmin=randomX;
          xmax=randomX+100;
          ymin=randomY;
          ymax=randomY+100;
          display( xmin, ymin, xmax, ymin);
          display( xmax, ymin, xmax, ymax);
          display( xmin, ymax,xmax, ymax);
          display( xmin, ymax, xmin, ymin);
          int x=clipping(xi,yi,xf,yf);
         
          delay(500);
        }
    }
  }
}

void keyboardkey(unsigned char key,int x,int y)
{

    glClear(GL_COLOR_BUFFER_BIT);
    if(key=='k')
    {
	
   
        randomWindow();
    }
}


void draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  int i;
  glutSwapBuffers();
  glFlush();
}


void mouse(int btn, int state, int x, int y) 
{
	
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
        { 
        switch(first)  
        {  
        case 0:  
        xi = x-(ww/2);  
        yi = (wh/2)-y;  
        first = 1;  
        break;  
        case 1:  
        xf = x-(ww/2);  
        yf = (wh/2)-y;
		if(xi>xf)
		{
		  int temp=xi;
	 	  xi=xf;
		  xf=temp;  
		  temp=yi;
	 	  yi=yf;
		  yf=temp;  
		} 
		
		display( xi, yi, xf, yf);
        first = 2;
        break;
       }  
    }  
}  

void init() 
{ 
  glViewport(-(ww/2),0,(ww/2),0); 
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(ww,wh);
  glutCreateWindow("Clipping");
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(-(ww/2),(ww/2),-(wh/2),(wh/2)); 



}



int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  init();
  glutDisplayFunc(display);
  
  glutDisplayFunc(draw);
  glutMouseFunc(mouse); 
  glutKeyboardFunc(keyboardkey); 
  glutMainLoop();
  return 0;
}
