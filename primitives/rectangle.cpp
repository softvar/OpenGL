/*

This program generates a rectangle 

* glBegin(GL_POLYGON) for generating polygon


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

    //Set line color
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    //Begin POLYGON coordinates
    glBegin(GL_POLYGON);
        //Provide coordinates
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    //End POLYGON coordinate
    glEnd();

    //Forces previously issued OpenGL commands to begin execution
    glFlush();
}

// Driver program to test above functions 
int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    
    //Set Output Window Size 
    glutInitWindowSize(500,500);
    
    //Set the position of Output window corresponding to Screen
    glutInitWindowPosition(100,100);
    
    //Create the Window
    glutCreateWindow("OpenGL - RECTANGLE drawing demo");

    //Set handler functions for drawing
    glutDisplayFunc(renderFunction);

    //Start the main loop
    glutMainLoop();  
}