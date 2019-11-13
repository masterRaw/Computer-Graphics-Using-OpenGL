#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
int state=1;
int r1=100;
int r2=90;
int r3=80;
int r4=70;
int r5=60;
int r6=50;
int r7=5;
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
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r1 * cos(i); 
		y = r1 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 

glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r2 * cos(i); 
		y = r2 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 

glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r3 * cos(i); 
		y = r3 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 

glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r4 * cos(i); 
		y = r4 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 

	glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r5 * cos(i); 
		y = r5 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 
	
	glBegin(GL_LINE_LOOP); 
	  
	for ( i = 0; i <= (2 * pi); i+=0.01) 
	{  
		x = r6 * cos(i); 
		y = r6 * sin(i);
		glVertex2i(x, y); 
	} 
	glEnd(); 
	glFlush(); 
 
} 

void timer()
{  
	glutPostRedisplay();
	glutTimerFunc(15, timer, 0);
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

	switch(state)
	{
	case 1:
		if(r2 > 40)
		{
			r2--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r2 < 90)
		{
			r2++;
		}
		else
			state = 1;
		break;
	}

	switch(state)
	{
	case 1:
		if(r3 > 30)
		{
			r3--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r3 < 80)
		{
			r3++;
		}
		else
			state = 1;
		break;
	}

	switch(state)
	{
	case 1:
		if(r4 > 20)
		{
			r4--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r4 < 70)
		{
			r4++;
		}
		else
			state = 1;
		break;
	}

	switch(state)
	{
	case 1:
		if(r5 > 10)
		{
			r5--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r5 < 60)
		{
			r5++;
		}
		else
			state = 1;
		break;
	}

	switch(state)
	{
	case 1:
		if(r6 > 0)
		{
			r6--;
		}
		else
			state = -1;
		break;
	case -1:
		if(r6 < 50)
		{
			r6++;
		}
		else
			state = 1;
		break;
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
	glutMainLoop(); 
} 

