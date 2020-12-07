#include <cstdlib>
#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <GL/glut.h> 
#include <GL/glu.h> 
#include <GL/gl.h> 


using namespace std; 
double rotAngle = 10; // Beware: Global variable!!
void init()
{
glClearColor(0.96, 0.98, 0.03, 0); // You can use your own color here in (r,g,b,O) format
glClearDepth(1.0); 
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
// gluPerspective(70, 1, 1, 1000); // setup a perspective projection
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
/* gluLookAt( // set up the camera
0.0, 0.0, 10.0, // eye position
0.0, 0.0, 0.0, // lookat position
0.0, 1.0, 0.0); */ // up direction
glEnable(GL_DEPTH_TEST); 
glEnable(GL_LIGHTING); 
glEnable(GL_LIGHT0); 
float lpos[] = { 5, 5, 5, 0 };
glLightfv(GL_LIGHT0, GL_POSITION, lpos);
//glShadeModel(GL_FLAT); // flat shading
glShadeModel(GL_SMOOTH); 
}
//-----------------------------------------------------------------------
// display callback function
//-----------------------------------------------------------------------
void display()
{
glClear(
GL_COLOR_BUFFER_BIT | 
GL_DEPTH_BUFFER_BIT); 
glPushMatrix(); 
glRotated(rotAngle, 0, 1, 0); // rotate by rotAngle about y-axis
glEnable(GL_COLOR_MATERIAL); 
glColor3f(0.07, 0.37, 0.85); // reddsh effect

glutSolidTeapot(1); // draw the teapot
glPopMatrix(); // restore the modelview matrix
glFlush(); // force OpenGL to render now
glutSwapBuffers(); // make the image visible
}
void keyboard(unsigned char k, int x, int y)
{
switch (k)
{
case 'a':
rotAngle += 5; // increase rotation by 5 degrees
break;
case 's':
rotAngle -= 5; // decrease rotation by 5 degrees
break;
case 'd':
glTranslatef(0.5,0.5,0);
break;
case 'f':
glTranslatef(-0.5,-0.5,0);
break;
case 'g':
glScalef(0.5,0.5,0.5);
break;
case 'h':
glScalef(2.0,2.0,2.0);
break;
case 'q':
exit(0); // exit
}
glutPostRedisplay(); // redraw the image now
}
void usage()
{
cout << "\n\
-----------------------------------------------------------------------\n\
Menu\n\
Inputs keybord:\n\
a: Rotate counterclockwise\n\
s: Rotate clockwise\n\
d: Translate with x=1 y=1 z=0\n\
f: Translate with x= -1 y= -1 z =0 \n\
g: Zoom Out\n\
h: Zoom in\n\
q: Quit\n\
You may need to place the cursor over the graphics window for\n\
keyboard input to be processed.\n\
-----------------------------------------------------------------------\n";
cout.flush();
}
void menu(int value) {
switch (value) {
case 1 : rotAngle +=10;
break;
case 2 : rotAngle -=10;
break;
case 3 : glTranslatef(0.5,0.5,0);
break;
case 4 : glTranslatef(-0.5,-0.5,0);
break;
case 5 : glScalef(0.5,0.5,0.5);
break;
case 6 : glScalef(2.0,2.0,2.0);
break;
case 7 : exit(0);
}
glutPostRedisplay();
}
int main(int argc, char **argv)
{
usage(); // explain how to use
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH |GLUT_RGB );
glutCreateWindow("GLUT Example"); // create the window
glutCreateMenu(menu);
glutAddMenuEntry("Clockwise",1);
glutAddMenuEntry("Anticlockwise",2);
glutAddMenuEntry("Translate",3);
glutAddMenuEntry("AntiTranslate",4);
glutAddMenuEntry("Zoom out",5);
glutAddMenuEntry("Zoom in",6);
glutAddMenuEntry("Quit",7);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display); // call display() to redraw window
glutKeyboardFunc(keyboard); // call keyboard() when key is hit
init(); // our own initializations
glutMainLoop(); // let GLUT take care of everything
return 0;
}
