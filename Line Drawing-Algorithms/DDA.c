#include <GL/glut.h>
#include <stdio.h>

void drawLineDDA(float x1, float y3, float x2, float y2)
{
    float dy, dx, step, x, y, k, m;
    dx = x2 - x1;
    dy = y2 - y3;
    m = dy / dx;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);

    x = x1;
    y = y3;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (k = 1; k <= step; k++)
    {
        if (m < 1)
        {
            x = 1 + x;
            y = m + y;
        }
        else if (m == 1)
        {
            x = 1 + x;
            y = 1 + y;
        }
        if (m > 1)
        {
            x = (1 / m) + x;
            y = 1 + y;
        }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}
void display(void)
{
    drawLineDDA(120, 100, 400, 400);
}

void init(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200, 200, -200, 200.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDA Algorithm for Line Drawing");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}