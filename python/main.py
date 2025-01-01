import random
import OpenGL
OpenGL.ERROR_CHECKING = False
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

TRIANGLES = 12
VERTICES = 3

vtx = [
	    -1.0, -1.0, -1.0,
    	-1.0, -1.0,  1.0,
    	-1.0,  1.0,  1.0,
    	 1.0,  1.0, -1.0,
    	-1.0, -1.0, -1.0,
    	-1.0,  1.0, -1.0,
    	 1.0, -1.0,  1.0,
    	-1.0, -1.0, -1.0,
    	 1.0, -1.0, -1.0,
    	 1.0,  1.0, -1.0,
    	 1.0, -1.0, -1.0,
    	-1.0, -1.0, -1.0,
    	-1.0, -1.0, -1.0,
    	-1.0,  1.0,  1.0,
    	-1.0,  1.0, -1.0,
    	 1.0, -1.0,  1.0,
    	-1.0, -1.0,  1.0,
    	-1.0, -1.0, -1.0,
    	-1.0,  1.0,  1.0,
    	-1.0, -1.0,  1.0,
    	 1.0, -1.0,  1.0,
    	 1.0,  1.0,  1.0,
    	 1.0, -1.0, -1.0,
    	 1.0,  1.0, -1.0,
    	 1.0, -1.0, -1.0,
    	 1.0,  1.0,  1.0,
    	 1.0, -1.0,  1.0,
    	 1.0,  1.0,  1.0,
    	 1.0,  1.0, -1.0,
    	-1.0,  1.0, -1.0,
    	 1.0,  1.0,  1.0,
    	-1.0,  1.0, -1.0,
    	-1.0,  1.0,  1.0,
    	 1.0,  1.0,  1.0,
    	-1.0,  1.0,  1.0,
    	 1.0, -1.0,  1.0
]

vtxc = []

def colorize(): # Unlike C, we can increase array as we initialize it 
    for i in range(0, TRIANGLES * VERTICES * 3):
        x = random.random()
        vtxc.append(x)

def init():
    colorize()
    glEnable(GL_DEPTH_TEST)
    glClearColor(0.114, 0.114, 0.114, 1.0)
    gluPerspective(40.0, 1.0, 1.0, 10.0)

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)

    glTranslatef(0.0, 0.0, -1.0)
    glRotatef(60.0, 1.0, 0.0, 0.0)
    glRotatef(-20.0, 0.0, 0.0, 1.0)


def draw():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    
    glEnableClientState(GL_VERTEX_ARRAY)
    glEnableClientState(GL_COLOR_ARRAY)

    glVertexPointer(3, GL_FLOAT, 0, vtx)
    glColorPointer(3, GL_FLOAT, 0, vtxc)

    glDrawArrays(GL_TRIANGLES, 0, 36)

    glDisableClientState(GL_VERTEX_ARRAY)
    glDisableClientState(GL_COLOR_ARRAY)

    glEnd()

    glutSwapBuffers()

def main():
    glutInit()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
    glutCreateWindow("Cube (Python)")
    glutDisplayFunc(draw)
    init()
    glutMainLoop()

if __name__ == "__main__":
    main()
