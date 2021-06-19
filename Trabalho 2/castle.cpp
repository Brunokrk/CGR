#include <GL/glut.h>
#include <stdio.h>

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
//Estratégia é criar uma função para desenhar todas as torres
void bigTower(GLUquadricObj *quad, GLfloat x, GLfloat y, GLfloat z);

void castle(){
	GLUquadricObj *pObj;    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
	glTranslatef(0.0f, -1.0f, -5.0f); 
	glRotatef(xRot, 1.0f, 0.0f, 0.0f); 
	glRotatef(yRot, 0.0f, 1.0f, 0.0f); 
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
    
    
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    bigTower(pObj, 0.0f, 1.5f, 1.0f);
    glPopMatrix();
    glPushMatrix();
    
    
    
    
    
    
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void bigTower(GLUquadricObj *quad, GLfloat x, GLfloat y, GLfloat z){
	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(x, y, z-0.8f);
    gluCylinder(quad, 0.3f, 0.3f, 1.1f, 26, 13);
    glColor3f(1.0f, 0.5f, 0.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
    gluCylinder(quad, 0.4f, 0.0f, 0.5f, 26, 13);
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
    glutInitWindowSize(800, 600);
    glutCreateWindow("TC2 - Castelo - Bruno Marchi Pires");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(castle);
    SetupRC();
    glutMainLoop();
    return 0;
}

