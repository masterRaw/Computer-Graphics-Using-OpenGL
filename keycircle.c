#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
int state=1;
int r1=100;
void myInit (void) 
{ 
 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glColor3f(1.0, 1.0, 1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluOrtho2D(-780, 780, -420, 420); 
} 

void display (void) 
{ 
	float x, y, i;
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.1) 
	{  
		x = r1 * cos(i); 
		y = r1 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 

	
} 

void timer()
{  
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
	switch(state)
	{
	case 1:
		if(r1 > 50)
		{
			r1--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r1 < 100)
		{
			r1++;
		}
		else
			state = 1;
		break;
	}
}

void press(unsigned char key, int x,int y)
{
	if(key == 32)
	{
		display();
		timer();
		
	}
}


int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	glutCreateWindow("Animated Circle"); 
	myInit(); 
	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);
	glutKeyboardFunc(press); 
	glutMainLoop(); 
} 

