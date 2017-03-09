/*#include <GL\glut.h>
#include <iostream>

void render(void);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 27) {
				
		exit(0);
	}
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		exit(0);
	}
}

void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0);
	glVertex2f(0.5, -0.5);
	glColor3f(0, 0, 1);
	glVertex2f(0.0, 0.5);
	glEnd();

	glutSwapBuffers();
}


#include <GL\glut.h>
GLfloat xRotated, yRotated, zRotated;
void init(void)
{
	glClearColor(0, 0, 0, 0);

}

void DrawCube(void)
{

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.5);
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	glColor3f(0.0f, 1.0f, 0.0f);    // Color Blue
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
	glColor3f(1.0f, 0.5f, 0.0f);    // Color Orange
	glVertex3f(1.0f, -1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Bottom)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Bottom)
	glColor3f(1.0f, 0.0f, 0.0f);    // Color Red    
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
	glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);    // Top Right Of The Quad (Back)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Left Of The Quad (Back)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Bottom Left Of The Quad (Back)
	glVertex3f(1.0f, 1.0f, -1.0f);    // Bottom Right Of The Quad (Back)
	glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
	glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right Of The Quad (Right)
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom Right Of The Quad (Right)
	glEnd();            // End Drawing The Cube
	glFlush();
}


void animation(void)
{

	yRotated += 0.01;
	xRotated += 0.02;
	DrawCube();
}


void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
								   //Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0

	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	//we initizlilze the glut. functions
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(DrawCube);
	glutReshapeFunc(reshape);
	//Set the function for the animation.
	glutIdleFunc(animation);
	glutMainLoop();
	return 0;
}

































#include <GL/glut.h>

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'a':
		angle+= 5;			// increase rotation by 5 degrees
		break;
	case 'l':
		 angle-= 5;			// decrease rotation by 5 degrees
		break;
	case 'q':
		exit(0);			// exit
	

	glutPostRedisplay();		// redraw the image now
} 


void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPointSize(2.0);
	//glLineWidth(2);
	//glBegin(GL_LINE_LOOP);
	
	
	
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0);
	glVertex2f(0.5, -0.5);
	glColor3f(0, 0, 1);
	glVertex2f(0.0, 0.5);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("one");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyboard);
	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}





*/





/*


#include <stdlib.h>
#include <GL/glut.h>


float red = 1.0f, blue = 1.0f, green = 1.0f;

float angle = 0.0f;

void changeSize(int w, int h) {


	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();


	glViewport(0, 0, w, h);


	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	//glOrtho(-10.0, 10.0, -10.0, 10, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	
	glutSwapBuffers();
}

void displayScene(void) {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(red, green, blue);
	glBegin(GL_QUA)
	//glBegin(GL_LINE_LOOP);
	glVertex3f(-2.0f, -2.0f, 0.0);
	glVertex3f(2.0f, 0.0f, 0.0);
	glVertex3f(0.0f, 2.0f, 0.0);
	glVertex3f(0.0, 0.0, 2.0f);
	glEnd();

	angle += 0.01f;

	glutSwapBuffers();
}



void exitkey (unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}
}


void colourchngkey (int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_F1:
		red = 1.0;
		green = 0.0;
		blue = 0.0; break;
	case GLUT_KEY_F2:
		red = 0.0;
		green = 1.0;
		blue = 0.0; break;
	case GLUT_KEY_F3:
		red = 0.0;
		green = 0.0;
		blue = 1.0; break;
	}
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("assignment1");

	// register callbacks
	glutDisplayFunc(displayScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(displayScene);

	// here are the new entries
	glutKeyboardFunc(exitkey);
	glutSpecialFunc(colourchngkey);
	glutMouseFunc(mouse);
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}*/
/*
 Main program
int main(int argc, char** argv)
{
   glutInit(&amp;argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (10, 10);
   glutTimerFunc( 10, TimeEvent, 1);
   window_1 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("GlutWindow 1");
   init ();
   glutDisplayFunc(display_1);
   glutReshapeFunc(reshape_1);
   glutKeyboardFunc(keyboard);
 
   window_2 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("GlutWindow 2");
   init ();
   glutDisplayFunc(display_2);
   glutReshapeFunc(reshape_2);
   glutMainLoop();
   return 0;
   }

 */








 // Glutdualwindow.c
 // By Eric Stringer 2002
 // Simple examples of OpenGL and Glut usage.
 // Keyboard input
 // 'v' = view ortho/perspective
 // 'l' = lighting on/off


#include <windows.h>  // This header file will be needed for some windows compilers
#include <GL/gl.h>   // gl.h and glu.h also maybe needed for some compilers
#include <GL/glu.h>
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include <stdio.h>    // standard (I/O library)
#include <stdlib.h>   // standard library (set of standard C functions
#include <math.h>     // Math library (Higher math functions )


 // lighting
GLfloat LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat LightDiffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightPosition[] = { 5.0f, 5.0f, -10.0f, 1.0f };
GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 1.0 };

int window_1, window_2;

static int view_state = 0, light_state = 0;

int spin;

int shape;

// I use this to put text on the screen
void Sprint(int x, int y, char *st)
{
	int l, i;

	l = strlen(st); // see how many characters are in text string.
	glRasterPos2i(x, y); // location to start printing text
	for (i = 0; i < l; i++)  // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // Print a character on the screen
	}

}


// This creates the spinning of the cube.
static void TimeEvent(int te)
{

	spin++;  // increase cube rotation by 1
	if (spin > 360) spin = 0; // if over 360 degress, start back at zero.

	glutSetWindow(window_1);
	glutPostRedisplay();  // Update screen with new rotation data

	glutSetWindow(window_2);
	glutPostRedisplay();  // Update screen with new rotation data

	glutTimerFunc(100, TimeEvent, 1);  // Reset our timmer.
}


// Setup our Opengl world, called once at startup.
void init(void)
{


	glClearColor(0.0, 0.0, 0.0, 0.0);  // When screen cleared, use black.
	glShadeModel(GL_SMOOTH);  // How the object color will be rendered smooth or flat
	glEnable(GL_DEPTH_TEST);   // Check depth when rendering
							   // Lighting is added to scene
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHTING);  // Turn on lighting
	glEnable(GL_LIGHT1);    // Turn on light 1


}


// Draw our world
void display_1(void)
{
	char *p;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen

	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	glLoadIdentity();  // Clear the matrix
	glOrtho(-8.0, 8.0, -8.0, 8.0, 0.0, 30.0);  // Setup an Ortho view
	glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
	glLoadIdentity(); // Clear the model matrix


	glColor3f(1.0, 1.0, 1.0);
	if (shape == 8) Sprint(-3, -7, "Solid Cube");
	if (shape == 1) Sprint(-3, -7, "Solid Cone");
	if (shape == 2) Sprint(-3, -7, "Solid Sphere");
	if (shape == 3) Sprint(-3, -7, "Solid Torus");
	if (shape == 4) Sprint(-3, -7, "Solid Dodecahedron");
	if (shape == 5) Sprint(-3, -7, "Solid Octahedron");
	if (shape == 6) Sprint(-3, -7, "Solid Tetrahedron");
	if (shape == 7) Sprint(-3, -7, "Solid Icosahedron");
	if (shape == 0) Sprint(-3, -7, "Solid Teapot");

	// Setup view, and print view state on screen
	if (view_state == 1)
	{
		glColor3f(1.0, 1.0, 1.0);
		Sprint(-2, 4, "Perspective view");
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, 1, 1, 30);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
		Sprint(-2, 4, "Ortho view");
	}

	glColor3f(0.0, 0.0, 1.0);  // Cube color

							   // Lighting on/off
	if (light_state == 1)
	{
		glDisable(GL_LIGHTING);  // Turn off lighting
		glDisable(GL_COLOR_MATERIAL); // Turn off material, which needs lighting to work
	}
	else
	{
		glEnable(GL_LIGHTING); // Turn on lighting
		glEnable(GL_COLOR_MATERIAL); // Turn on material settings
		glColorMaterial(GL_FRONT, GL_AMBIENT);
		glColor4f(0.65, 0.65, 0.65, 0.4);
		glColorMaterial(GL_FRONT, GL_EMISSION);
		glColor4f(0.10, 0.10, 0.10, 0.0);
		glColorMaterial(GL_FRONT, GL_SPECULAR);
		glColor4f(0.5, 0.5, 0.5, 0.4);
		glColorMaterial(GL_FRONT, GL_DIFFUSE);
		glColor4f(0.85, 0.85, 0.85, 0.4);
	}

	gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

	glRotatef( 45, 1.0, 1.0, 0.0); // rotate cube
	glRotatef(spin++, 1.0, 1.0, 1.0); // spin cube

	if (shape == 8) glutSolidCube(10); // Draw a cube
	if (shape == 1) glutSolidCone(5, 10, 16, 16);  // Draw a Cone
	if (shape == 2) glutSolidSphere(5, 16, 16);  // Draw a Sphere
	if (shape == 3) glutSolidTorus(2.5, 5, 16, 16);
	if (shape == 4)
	{
		glScalef(3.5, 3.5, 3.5);
		glutSolidDodecahedron();
	}

	if (shape == 5)
	{
		glScalef(5.0, 5.0, 5.0);
		glutSolidOctahedron();
	}
	if (shape == 6)
	{
		glScalef(5.0, 5.0, 5.0);
		glutSolidTetrahedron();
	}

	if (shape == 7)
	{
		glScalef(5.0, 5.0, 5.0);
		glutSolidIcosahedron();
	}
	if (shape == 0) glutSolidTeapot(5);

	glutSwapBuffers();
}

void display_2(void)
{
	char *p;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen

	glMatrixMode(GL_PROJECTION);  // Tell opengl that we are doing project matrix work
	glLoadIdentity();  // Clear the matrix
	glOrtho(-8.0, 8.0, -8.0, 8.0, 0.0, 30.0);  // Setup an Ortho view
	glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
	glLoadIdentity(); // Clear the model matrix


	glColor3f(1.0, 1.0, 1.0);
	if (shape == 2) Sprint(-3, -7, "Wire Cube");
	if (shape == 1) Sprint(-3, -7, "Wire Cone");
	if (shape == 8) Sprint(-3, -7, "Wire Sphere");
	if (shape == 3) Sprint(-3, -7, "Wire Torus");
	if (shape == 4) Sprint(-3, -7, "Wire Dodecahedron");
	if (shape == 5) Sprint(-3, -7, "Wire Octahedron");
	if (shape == 6) Sprint(-3, -7, "Wire Tetrahedron");
	if (shape == 7) Sprint(-3, -7, "Wire Icosahedron");
	if (shape == 0) Sprint(-3, -7, "Wire Teapot");

	// Setup view, and print view state on screen
	if (view_state == 1)
	{
		glColor3f(1.0, 1.0, 1.0);
		Sprint(-2, 4, "Ortho view");

	}
	else
	{
		glColor3f(1.0, 1.0, 1.0);
		Sprint(-2, 4, "Perspective view");
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, 1, 1, 30);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		
	}

	glColor3f(1.0, 0.0, .0);  // Cube color

							   // Lighting on/off
	if (light_state == 1)
	{
		glDisable(GL_LIGHTING);  // Turn off lighting
		glDisable(GL_COLOR_MATERIAL); // Turn off material, which needs lighting to work
	}
	else
	{
		glEnable(GL_LIGHTING); // Turn on lighting
		glEnable(GL_COLOR_MATERIAL); // Turn on material settings
		glColorMaterial(GL_FRONT, GL_AMBIENT);
		glColor4f(0.65, 0.65, 0.65, 0.4);
		glColorMaterial(GL_FRONT, GL_EMISSION);
		glColor4f(0.10, 0.10, 0.10, 0.0);
		glColorMaterial(GL_FRONT, GL_SPECULAR);
		glColor4f(0.5, 0.5, 0.5, 0.4);
		glColorMaterial(GL_FRONT, GL_DIFFUSE);
		glColor4f(0.85, 0.85, 0.85, 0.4);
	}

	gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);

	//glRotatef( 45, 1.0, 1.0, 0.0); // rotate cube
	glRotatef(spin++, 1.0, 1.0, 1.0); // spin cube

	if (shape == 2) glutWireCube(10); // Draw a cube
	if (shape == 1) glutWireCone(5, 10, 16, 16);  // Draw a Cone
	if (shape == 8) glutWireSphere(5, 16, 16);  // Draw a Sphere
	if (shape == 3) glutWireTorus(2.5, 5, 16, 16);
	if (shape == 4)
	{
		glScalef(3.5, 3.5, 3.5);
		glutSolidDodecahedron();
	}

	if (shape == 5)
	{
		glScalef(5.0, 5.0, 5.0);
		glutWireOctahedron();
	}
	if (shape == 6)
	{
		glScalef(5.0, 5.0, 5.0);
		glutWireTetrahedron();
	}

	if (shape == 7)
	{
		glScalef(5.0, 5.0, 5.0);
		glutWireIcosahedron();
	}
	if (shape == 0) glutWireTeapot(5);

	glutSwapBuffers();


}


// This is called when the window has been resized.
void reshape_1(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

// This is called when the window has been resized.
void reshape_2(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


// Read the keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'v':
	case 'V':
		view_state = abs(view_state - 1);
		break;
	case 'l':
	case 'L':
		light_state = abs(light_state - 1);
		break;
	case 's':
	case 'S':
		shape++;
		break;
	case 27:
		exit(0); // exit program when [ESC] key presseed
		break;
	default:
		break;
	}

	if (shape > 8) shape = 0;

}


// Main program
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutTimerFunc(10, TimeEvent, 1);
	window_1 = glutCreateWindow(argv[0]);
	glutSetWindowTitle("GlutWindow 1");
	init();
	glutDisplayFunc(display_1);
	glutReshapeFunc(reshape_1);
	glutKeyboardFunc(keyboard);
	glutInitWindowPosition(500, 10);
	window_2 = glutCreateWindow(argv[0]);
	glutSetWindowTitle("GlutWindow 2");
	//glutInitWindowPosition(10, 10);
	init();
	glutDisplayFunc(display_2);
	glutReshapeFunc(reshape_2);
	glutMainLoop();
	return 0;
}