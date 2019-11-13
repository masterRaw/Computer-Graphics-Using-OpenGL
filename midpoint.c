#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>

#define ROUND(a) ((int)(a+0.5))

int f = 0, count = 0, arr = 0;
float i, slope, m;
int x, y, xm, ym,r=40;
int check;

struct cord
{
		int xc;
		int yc;
}abc;

void Init(void)
{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glPointSize(1.2);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



void setPixel(float xx, float yy)
{
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POINTS);
		glVertex2f(xx, yy);
		glEnd();
		glFlush();
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry)
{
		int Rx2 = Rx * Rx;
		int Ry2 = Ry * Ry;
		int twoRx2 = 2 * Rx2;
		int twoRy2 = 2 * Ry2;
		int p;
		int x = 0;
		int y = Ry;
		int px = 0;
		int py = twoRx2 * y;
		ellipsePlotPoints(xCenter, yCenter, x, y);
		p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
		while (px < py)
		{
				x++;
				px += twoRy2;
				if (p < 0)
						p += Ry2 + px;
				else
				{
						y--;
						py -= twoRx2;
						p += Ry2 + px - py;
				}
				ellipsePlotPoints(xCenter, yCenter, x, y);
		}
		p = ROUND(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
		while (y > 0)
		{
				y--;
				py -= twoRx2;
				if (p > 0)
						p += Rx2 - py;
				else
				{
						x++;
						px += twoRy2;
						p += Rx2 - py + px;
				}
				ellipsePlotPoints(xCenter, yCenter, x, y);
		}
}

void ellipse()
{
		ellipseMidpoint(abc.xc, abc.yc, 100, 50);
}


void circlePlotPoints(int xCenter, int yCenter, int x, int y)
{
		setPixel(xCenter + x, yCenter + y);
		setPixel(xCenter - x, yCenter + y);
		setPixel(xCenter + x, yCenter - y);
		setPixel(xCenter - x, yCenter - y);
		setPixel(xCenter + y, yCenter + x);
		setPixel(xCenter - y, yCenter + x);
		setPixel(xCenter + y, yCenter - x);
		setPixel(xCenter - y, yCenter - x);
}

void circle()
{
		int x = 0;
		int y = r;
		int p = 1 - r;
		circlePlotPoints(abc.xc, abc.yc, x, y);
		while (x < y)
		{
				x++;
				if (p < 0)
				{
						p += 2 * x + 1;
				}
				else
				{
						y--;
						p += 2 * (x - y) + 1;
				}
				circlePlotPoints(abc.xc, abc.yc, x, y);
		}
}

void quad()
{
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(320, 480);
		glVertex2f(320, 0);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1, 1, 1);
		glVertex2f(0, 240);
		glVertex2f(640, 240);
		glEnd();
}

void display(void)
{
		quad();
		if (check)
		{
				x = xm;
				y = ym;
				glClear(GL_COLOR_BUFFER_BIT);
				glBegin(GL_POINTS);
				glColor3f(0, 0, 0);
				glVertex2f(x, y);
				glEnd();
				glFlush();
				abc.xc = x;
				abc.yc = y;
				quad();
				printf("%d", abc.xc);
				printf("  %d\n", abc.yc);
				if ((abc.xc > 320 && abc.yc > 240) || (abc.xc < 320 && abc.yc < 240))
						circle();
				else
						ellipse();
		}
		
}

void Mouse(int button, int state, int xmouse, int ymouse)
{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
				check = 1;
				xm = xmouse;
				ym = 480 - ymouse;
				glutPostRedisplay();
		}
}

int main(int argc, char** argv)
{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(640, 480);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Midpoint algorithm");
		Init();
		glutMouseFunc(Mouse);
		glutDisplayFunc(display);
		glutMainLoop();
}

