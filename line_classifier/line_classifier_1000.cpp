/*

This program classifies a line as:
* Trivially Visible
* Trivially Invisible
* Partially Visible

(c) 2013 Varun Malhotra. MIT License
Also available at https://www.github.com/softvar/opengl @Varun Malhotra

*/

#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

#define XWidth 700  // Clipping window size 700*700
#define YHeight 700 

void renderFunction() {

/*Clear Information from last draw
Sets the current clearing color for use in clearing
color buffers in RGBA mode.
*/
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Set line width
    glLineWidth(1);

    //(x,y) coordinates as in pixels
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, XWidth, 0, YHeight, -1, 1);


    //Set line color
    glColor3f(1.0, 0.0, 0.0);

    //random num generated
    for(int i=0;i<500;i++){ // will run for 1000 times
    int r1 = rand() % 1000;
    int r2 = rand() % 1000;
    int r3 = rand() % 1000;
    int r4 = rand() % 1000;
    //Begin LINE coordinates
    glBegin(GL_LINES);
        //Provide (x,y) coordinates
        glVertex2d(r1, r2);
        glVertex2d(r3,r4);
    //End LINE coordinate
    glEnd();

    int LRBT1[3], LRBT2[3];

    //calculating LRBT for first set of line coordinate
    if (r1 < 0){
        LRBT1[0] = 1;
    }else {
        LRBT1[0] = 0;
    }
    if (r1 > 700){
        LRBT1[1] = 1;
    }else {
        LRBT1[1] = 0;
    }
    if (r2 < 0){
        LRBT1[2] = 1;
    }else {
        LRBT1[2] = 0;
    }
    if (r2 > 700){
        LRBT1[3] = 1;
    }else {
        LRBT1[3] = 0;
    }
 
    //calculating LRBT for second set of line coordinate
    if (r3 < 0){
        LRBT2[0] = 1;
    }else {
        LRBT2[0] = 0;
    }
    if (r3 > 700){
        LRBT2[1] = 1;
    }else {
        LRBT2[1] = 0;
    }
    if (r4 < 0){
        LRBT2[2] = 1;
    }else {
        LRBT2[2] = 0;
    }
    if (r4 > 700){
        LRBT2[3] = 1;
    }else {
        LRBT2[3] = 0;
    }

    
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
    //cout<<i<<" "<<LRBT[0]<<LRBT[1]<<LRBT[2]<<LRBT[3]<<endl;

    if(LRBT1[0] == 0 && LRBT1[1] == 0 && LRBT1[2] == 0 && LRBT1[3] == 0)
        {if (LRBT2[0] == 0 && LRBT2[1] == 0 && LRBT2[2] == 0 && LRBT2[3] == 0)
            cout<<"Trivially Visible"<<endl;}
    else if(LRBT1[0] == LRBT2[0] && LRBT1[1]==LRBT2[1]  && LRBT1[2]==LRBT2[2]  && LRBT1[3]==LRBT2[3])
        cout<<"Trivially Invisible"<<endl;
    else 
        cout<<"Partially Visible"<<endl;
    
    //Forces previously issued OpenGL commands to begin execution
    glFlush();
    }
}

// Driver program to test above functions
int main(int argc, char** argv) {

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    
    //Set Output Window Size
    glutInitWindowSize(XWidth,YHeight);
    
    //Set the position of Output window corresponding to Screen
    glutInitWindowPosition(100,100);
    
    //Create the Window
    glutCreateWindow("OpenGL - Classify line among three classes");

    //Set handler functions for drawing
    glutDisplayFunc(renderFunction);

    //Start the main loop
    glutMainLoop();
    return 0;
}