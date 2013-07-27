Working with OpenGL
===================

OpenGL (Open Graphics Library) is a cross-language, multi-platform Application programming interface (API) for rendering 2D and 3D computer graphics. The API is typically used to interact with a Graphics processing unit (GPU), to achieve hardware-accelerated rendering.

What this is for
----------------

Great collection of useful utility programs in openGL(c++).

Installation In Ubuntu
----------------------

.. code-block:: bash

    sudo apt-get install freeglut3 freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev

Include header files
--------------------

.. code-block:: c++

    #include "GL/glut.h"
    #include "GL/gl.h"

Compilation
-----------

.. code-block:: bash


    g++ -o filename filename.cpp -lglut

References
----------
http://www.glprogramming.com/red/
