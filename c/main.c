// Parts adapted from https://github.com/markkilgard/glut/blob/master/progs/examples/cube.c
// and 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GL/glut.h>

#define TRIANGLES 12
#define VERTICES 3

GLfloat vtx[TRIANGLES * VERTICES * 3] = { // XYZ per vertex
	-1.0f, -1.0f, -1.0f,
    	-1.0f, -1.0f,  1.0f,
    	-1.0f,  1.0f,  1.0f,
    	 1.0f,  1.0f, -1.0f,
    	-1.0f, -1.0f, -1.0f,
    	-1.0f,  1.0f, -1.0f,
    	 1.0f, -1.0f,  1.0f,
    	-1.0f, -1.0f, -1.0f,
    	 1.0f, -1.0f, -1.0f,
    	 1.0f,  1.0f, -1.0f,
    	 1.0f, -1.0f, -1.0f,
    	-1.0f, -1.0f, -1.0f,
    	-1.0f, -1.0f, -1.0f,
    	-1.0f,  1.0f,  1.0f,
    	-1.0f,  1.0f, -1.0f,
    	 1.0f, -1.0f,  1.0f,
    	-1.0f, -1.0f,  1.0f,
    	-1.0f, -1.0f, -1.0f,
    	-1.0f,  1.0f,  1.0f,
    	-1.0f, -1.0f,  1.0f,
    	 1.0f, -1.0f,  1.0f,
    	 1.0f,  1.0f,  1.0f,
    	 1.0f, -1.0f, -1.0f,
    	 1.0f,  1.0f, -1.0f,
    	 1.0f, -1.0f, -1.0f,
    	 1.0f,  1.0f,  1.0f,
    	 1.0f, -1.0f,  1.0f,
    	 1.0f,  1.0f,  1.0f,
    	 1.0f,  1.0f, -1.0f,
    	-1.0f,  1.0f, -1.0f,
    	 1.0f,  1.0f,  1.0f,
    	-1.0f,  1.0f, -1.0f,
    	-1.0f,  1.0f,  1.0f,
    	 1.0f,  1.0f,  1.0f,
    	-1.0f,  1.0f,  1.0f,
    	 1.0f, -1.0f,  1.0f
};

GLfloat vtxc[TRIANGLES * VERTICES * 3]; // 3 colors per channel

void colorize() {
	srand((int)(time(NULL)));
	for (int i = 0; i < (sizeof(vtxc) / sizeof(vtxc[0])); i++) {
		vtxc[i] = (float)rand() / RAND_MAX;
	}
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vtx);
	glColorPointer(3, GL_FLOAT, 0, vtxc);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	glEnd();

	glutSwapBuffers();
}

void init() {
	colorize();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.114f, 0.114f, 0.114f, 1.0f);    
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0f, 1.0f, 1.0f, 10.0f);
	glMatrixMode(GL_MODELVIEW);

	gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -1.0f);
	glRotatef(60.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Cube (C)");
	glutDisplayFunc(draw);
	init();
	glutMainLoop();
	return 0;

}
