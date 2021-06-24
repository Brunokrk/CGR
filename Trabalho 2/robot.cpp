#include <GL/glut.h>
#include <stdio.h>

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


void humanoide(){
	GLUquadricObj *pObj;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glPushMatrix();
	
	glTranslatef(0.0f,-1.0f,-5.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    
    pObj = gluNewQuadric();
	gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);
	//Para rotacionar da forma imaginada, talvez seja mágica
	//mas fez o esperado
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
	
	//pernas
	glTranslatef(0.3, 0.0, 0.3f);
    glColor3f(0.2f, 0.2f, 0.2f);
    glScalef(0.5f, 0.4f, 1.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glTranslatef(-0.3f, 0.0f, 0.3f);
	glColor3f(0.2f, 0.2f, 0.2f);
    glScalef(0.5f, 0.4f, 1.2f);
    glutSolidCube(1.0f);
    glPopMatrix();
	
	
	
	
	
	
	
	
	
	glEnd();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}


void ChangeSize(int w, int h){
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupRC(){

    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);    // Hidden surface removal
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);     // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

void SpecialKeys(int key, int x, int y){
    if(key == GLUT_KEY_UP) {
        xRot-= 5.0f;
    }
    if(key == GLUT_KEY_DOWN) {
        xRot += 5.0f;
    }
    if(key == GLUT_KEY_LEFT) {
        yRot -= 5.0f;
    }
    if(key == GLUT_KEY_RIGHT) {
        yRot += 5.0f;
    }
    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);
    glutPostRedisplay();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("TC2 - Humanoide - Bruno Marchi Pires");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(humanoide);
    SetupRC();
    glutMainLoop();
    return 0;
}

