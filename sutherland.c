#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

float xmin=100;
float ymin=100;
float xmax=300;
float ymax=300;
float xd1,yd1,xd2,yd2;

void BitmapText(char *string,float x,float y) 
{  
		char c;
		int i;
		glColor3f(0.0,1.0,1.0);
		glRasterPos2f(x, y);
		for (i=0;string[i]!='\0'; i++) 
		{
				c=string[i];
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
		}
}

void render()
{ 
		glColor3f(1.0,1.0,0.0);
		BitmapText("",400,400);
		BitmapText("",400,350);
		glFlush(); 
}

void init(void)
{
		glClearColor(0.0,0,0,0);
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0.0,640.0,0.0,480.0);
}

int code(float x,float y)
{
		int c=0;
		if(y>ymax)c=8;
		if(y<ymin)c=4;
		if(x>xmax)c=c|2;
		if(x<xmin)c=c|1;
		return c;
}

void cohen(float x1,float y1,float x2,float y2)
{
	int c1=code(x1,y1);
	int c2=code(x2,y2);
	float m=(y2-y1)/(x2-x1);
	while((c1|c2)>0)
	{
			if((c1 & c2)>0)
			{
					exit(0);
			}

			float xi=x1;float yi=y1;
			int c=c1;
			if(c==0)
			{
					c=c2;
					xi=x2;
					yi=y2;
			}
			float x,y;
			if((c & 8)>0)
			{
					y=ymax;
					x=xi+ 1.0/m*(ymax-yi);
			}
			else
					if((c & 4)>0)
					{
							y=ymin;
							x=xi+1.0/m*(ymin-yi);
					}
					else
							if((c & 2)>0)
							{
									x=xmax;
									y=yi+m*(xmax-xi);
							}
							else
									if((c & 1)>0)
									{
											x=xmin;
											y=yi+m*(xmin-xi);
									}

			if(c==c1)
			{
					xd1=x;
					yd1=y;
					c1=code(xd1,yd1);
			}

			if(c==c2)
			{
					xd2=x;
					yd2=y;
					c2=code(xd2,yd2);
			}
	}
	display();
}

void mouse(int btn,int state,int x,int y)  
{  
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   {  
			xd1=x;  
			yd1=480-y;
	}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) {
		xd2=x;  
		yd2=480-y;  
		cohen(xd1,yd1,xd2,yd2);
	}
}  
void display()
{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(xmin,ymin);
		glVertex2i(xmin,ymax);
		glVertex2i(xmax,ymax);
		glVertex2i(xmax,ymin);
		glEnd();
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINES);
		glVertex2i(xd1,yd1);
		glVertex2i(xd2,yd2);
		glEnd();
		render();
		glFlush();
}

int main(int argc,char** argv)
{
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(600,600);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Clipping");
		glutDisplayFunc(display);
		glutMouseFunc(mouse); 
		init();
		glutMainLoop();
		return 0;
}

