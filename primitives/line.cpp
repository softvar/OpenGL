/*

This program generates a line from point(x1,y1) to another point(x2,y2).

* glBegin(GL_LINES) for generating line


(c) 2013 Varun Malhotra. MIT License

*/

#include "GL/glut.h"
#include "GL/gl.h"

void renderFunction() {

	/*Clear Information from last draw
	Sets the current clearing color for use in clearing 
	color buffers in RGBA mode.
    
	*/
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Set line width
    glLineWidth(2.5);

    //Set line color
    glColor3f(1.0, 0.0, 0.0);

    //Begin LINE coordinates
    glBegin(GL_LINES);
        //Provide (x,y) coordinates
        glVertex2d(0.0, 0.0);
        glVertex2d(0.5,0.5);
    //End LINE coordinate
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        //Provide (x,y,z) coordinates
        glVertex3f(-0.5,0.5,0.0);
        glVertex3f(0.5, 0, 0);
    glEnd();

    //Forces previously issued OpenGL commands to begin execution
    glFlush();
}

// Driver program to test above functions 
int main(int argc, char** argv) {

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    
    //Set Output Window Size 
    glutInitWindowSize(500,500);
    
    //Set the position of Output window corresponding to Screen
    glutInitWindowPosition(100,100);
    
    //Create the Window
    glutCreateWindow("OpenGL - LINE drawing demo");

    //Set handler functions for drawing
    glutDisplayFunc(renderFunction);

    //Start the main loop
    glutMainLoop();    
    return 0;
}