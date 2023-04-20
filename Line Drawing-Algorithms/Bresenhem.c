#include <GL/glut.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int x = x1;
	int y = y1;
	int sx = x2 >= x1 ? 1 : -1;
	int sy = y2 >= y1 ? 1 : -1;
	int err = dx - dy;

	glBegin(GL_POINTS);
	while (true) {
    	glVertex2i(x, y);
    	if (x == x2 && y == y2) {
        	break;
    	}
    	int e2 = 2 * err;
    	if (e2 > -dy) {
        	err -= dy;
        	x += sx;
    	}
    	if (e2 < dx) {
        	err += dx;
        	y += sy;
    	}
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	drawLineBresenham(120, 100, 400, 400);
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Bresenham Algorithm for Line Drawing");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(0, 640, 0, 480);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
