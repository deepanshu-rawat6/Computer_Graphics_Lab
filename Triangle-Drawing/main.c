#include <GL/glut.h>
#include <math.h>

int color = 0;

void displayName() {
    glColor3f(255.0,255.0,255.0);
    glRasterPos2f(-0.15,0.35);
    char name[]="Deepanshu";
    for(int i=0;name[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,name[i]);
    }
}

void displayMe(){
    glClear(GL_COLOR_BUFFER_BIT);

    if (color == 0) {
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        
        double val = sqrt(0.75);
        glVertex2f(0.5,0.0);
        glVertex2f(-0.5,0.0);
        glVertex2f(0.0,val);
    } else if (color == 1) {
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_POLYGON);
        double val = sqrt(0.75);
        glVertex2f(0.5,0.0);
        glVertex2f(-0.5,0.0);
        glVertex2f(0.0,val);
    } else {
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_POLYGON);
        double val = sqrt(0.75);
        glVertex2f(0.5,0.0);
        glVertex2f(-0.5,0.0);
        glVertex2f(0.0,val);
    }
    glEnd();
    displayName();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        color++;
        if (color > 2) {
            color = 0;
        }
        glutPostRedisplay();
    }
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Hi,I'm Deepanshu!");
    glutDisplayFunc(displayMe);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
