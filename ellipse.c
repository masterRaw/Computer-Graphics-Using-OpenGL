#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
void drawBitmapText(char *string, float x, float y, float z)
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++)
		{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		}

}
int r=100;
void myellipse(float x_coord, float y_coord, float a, float b, int num_segments) 
{ 
    float theta = 2 * 3.1415926 / num_segments; 
    float c = cosf(theta);
    float s = sinf(theta);
    float x_temp = 1;
    float y_temp = 0;
    float t; 

    glBegin(GL_LINE_LOOP); 
    for(int i = 0; i < num_segments; i++) 
    {
	glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x_temp * a + x_coord, y_temp * b + y_coord);
        t = x_temp;
        x_temp = c * x_temp - s * y_temp;
        y_temp = s * t + c * y_temp;
    } 
    glEnd(); 
}
void circle(int x, int y, int pointX1, int pointY1)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2i(x+pointX1, y+pointY1);
	glEnd();
}
void mycircle(int pointX1, int pointY1)
{		int x_coord = 0;
		int y_coord = r;
		float decision = r;
		circle(x_coord, y_coord, pointX1, pointY1);
		while (y_coord > x_coord)
		{
			if (decision < 0)
			{
			x_coord++; 
			decision += 2*x_coord+1;
			}
			else
			{
			y_coord--;
			x_coord++;
			decision += 2*(x_coord-y_coord)+1;
			}
			circle(x_coord, y_coord, pointX1, pointY1);
			circle(x_coord, -y_coord, pointX1, pointY1);
			circle(-x_coord, y_coord, pointX1, pointY1);
			circle(-x_coord, -y_coord, pointX1, pointY1);
			circle(y_coord, x_coord, pointX1, pointY1);
			circle(-y_coord, x_coord, pointX1, pointY1);
			circle(y_coord, -x_coord, pointX1, pointY1);
			circle(-y_coord, -x_coord, pointX1, pointY1);
		}
}
void Mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mycircle(x, 480-y);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		myellipse(x, 480-y, 100, 70, 100);
	}

	
glutPostRedisplay();
}
void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 0.0f, 1.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}
void display()
{
	int j;
	glBegin(GL_LINES);
	glColor3f(1.00, 1.00, 1.00);
	glVertex2i(0, 240);
	glVertex2i(640, 240); //x-axis
	glVertex2i(320, 0);
	glVertex2i(320, 480);  //y-axis
	glVertex2i(10, 230);
	glVertex2i(0, 240);
	glVertex2i(0, 240);
	glVertex2i(10, 250); // left arrow
	glVertex2i(630, 250);
	glVertex2i(640, 240);
	glVertex2i(640, 240);
	glVertex2i(630, 230); // right arrow
	glVertex2i(310, 470);glVertex2i(320, 480);glVertex2i(320, 480);glVertex2i(330, 470);// top arrow
	glVertex2i(310, 10);glVertex2i(320, 0);glVertex2i(320, 0);glVertex2i(330, 10); //Bottom arrow
	glEnd();
	glFlush();
drawBitmapText("Abhinav", 0, 450, 0);
    	drawBitmapText("500060070", 0, 430, 0);
   
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Lab work Circle");
	glutDisplayFunc(display);
	glutMouseFunc(Mouse);
	init();
	glutMainLoop();
	return 0;
}
