#include <GL/glut.h>

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void snowman(){
	GLUquadricObj *pObj;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glPushMatrix();
	
	glTranslatef(0.0f,-1.0f,-5.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	

	//Quadrica
	pObj = gluNewQuadric();
	gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);
	
	//CORPO
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f); //branco
	gluSphere(pObj, 0.4f, 40, 30);
	glTranslatef(0.0f, 0.55f, 0.0f);
	gluSphere(pObj, 0.30f, 40, 30);
	glTranslatef(0.0f, 0.45f, 0.0f);
	gluSphere(pObj, 0.20f, 40, 30);
	
	//Cabeça - olhos, nariz
	glColor3f(0.0f, 0.0f, 1.0f); // azul para os olhos
	glTranslatef(0.05f, 0.1f, 0.2f);
	gluSphere(pObj, 0.04f, 40, 30);
	glTranslatef(-0.15f, 0.0f, -0.02f);
	gluSphere(pObj, 0.04f, 40, 30);
	
	
	glColor3f(1.0f, 0.5f, 0.0f); 
	glTranslatef(0.08f, -0.12f, 0.0f);
	gluCylinder(pObj, 0.05f, 0.0f, 0.3f, 26, 20);


	//ROUPA
	glColor3f(0.0f, 0.0f, 0.0f); 
    glTranslatef(0.0f, -0.3f, 0.1f);
    gluSphere(pObj, 0.03f, 40, 30);
    glTranslatef(0.0f, -0.3f, -0.02f);
    gluSphere(pObj, 0.03f, 40, 30);
    glTranslatef(0.0f, -0.3f, 0.15f);
    gluSphere(pObj, 0.03f, 40, 30);
    glPopMatrix();
	//gluDisk(pObj, 0.0f, 0.17f, 26, 20);
	
	
	//CHAPEU
	glPushMatrix();
	glColor3f(0.5f, 1.0f, 1.0f); 
	glTranslatef(0.0f, 1.14f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(pObj, 0.175f, 0.175f, 0.4f, 26, 20);

	// Base do chapeu
	glDisable(GL_CULL_FACE);
	gluDisk(pObj, 0.17f, 0.28f, 26, 20);
	glEnable(GL_CULL_FACE);

	glTranslatef(0.0f, 0.0f, 0.40f);
	gluDisk(pObj, 0.0f, 0.17f, 26, 20);
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
    glClearColor(0.0f, 0.0f, 0.00f, 0.0f);
}

void SpecialKeys(int key, int x, int y){
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;
    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;
    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;
    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;
        xRot = (GLfloat)((const int)xRot % 360);
        yRot = (GLfloat)((const int)yRot % 360);
    // Refresh the Window
    glutPostRedisplay();
}


int main(int argc, char *argv[]) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutCreateWindow("SnowMan - Bruno Marchi Pires");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(snowman);
    SetupRC();
    glutMainLoop();
    return 0;
}
