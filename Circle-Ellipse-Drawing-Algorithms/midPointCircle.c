#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void midPointCircle(int r, int xc, int yc)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y)
    {
        plot(xc + x, yc + y);
        plot(xc - x, yc + y);
        plot(xc + x, yc - y);
        plot(xc - x, yc - y);
        plot(xc + y, yc + x);
        plot(xc - y, yc + x);
        plot(xc + y, yc - x);
        plot(xc - y, yc - x);

        if (p < 0)
            p = p + 2 * x + 3;
        else
        {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    midPointCircle(100, 250, 250);

    glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid Point Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}