#include <GL/glut.h>
#include <stdio.h>
void humanoide();

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;

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
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    
    //corpo
    glPushMatrix();
    	glTranslatef(0.0f, 0.0f, 1.5f);
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    	glScalef(1.1f, 0.5f, 1.6f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(0.0f, -0.05f, 1.7f);
		glColor3f(0.5f, 1.0f, 1.0f);
    	glScalef(0.45f, 0.45f, 0.45f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(0.0f, -0.01f, 1.7f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    	glScalef(0.5f, 0.5f, 0.5f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    //cabeça
    glPushMatrix();
    	glTranslatef(0.0f, 0.0f, 2.69f);
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    	glScalef(0.8f, 0.8f, 0.8f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(0.0f, -0.12f, 2.69f);
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    	glScalef(0.6f, 0.6f, 0.6f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
	//olho
    glPushMatrix();
    	glTranslatef(0.2f, -0.4f, 2.79f);
		//glColor3f(0.0f, 0.0f, 0.2f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    	glScalef(0.15f, 0.1f, 0.1f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
	//olho
    glPushMatrix();
    	glTranslatef(-0.2f, -0.4f, 2.79f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    	glScalef(0.15f, 0.1f, 0.1f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    //braços
    
    glPushMatrix();
    	glTranslatef(0.7f, 0.0f, 1.69f);
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    	glScalef(0.4f, 0.4f, 1.2f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(-0.7f, 0.0f, 1.69f);
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    	glScalef(0.4f, 0.4f, 1.2f);
    	glutSolidCube(1.0f);
    glPopMatrix();
	
	
	glPushMatrix();
	//pernas
		glTranslatef(0.3, 0.0, 0.3f);
    	glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    	glScalef(0.52f, 0.52f, 1.2f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(-0.3f, 0.0f, 0.3f);
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    	glScalef(0.52f, 0.52f, 1.2f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    //botas
    glPushMatrix();
    	glTranslatef(-0.3f, 0.0f, -0.08f);
		glColor4f(1.5f, 0.3f, 0.0f, 0.0f);
    	glScalef(0.57f, 0.57f, 0.6f);
    	glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(0.3f, 0.0f, -0.08f);
		glColor4f(1.5f, 0.3f, 0.0f, 0.0f);
    	glScalef(0.57f, 0.57f, 0.6f);
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

