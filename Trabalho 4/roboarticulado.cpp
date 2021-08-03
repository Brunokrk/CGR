#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

enum ANIMATION {STOP, WALK, ACENAR} action = STOP;
float leftShoulder = 0.0, leftHand = 0.0, leftLeg = 0.0;
float rightShoulder = 0.0, rightHand = 0.0, rightLeg = 0.0;

void buildRobot(void) {

    GLUquadricObj *pObj;

    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
        //Body
        glColor3f(1.0f, 0.0f, 1.0f); 
        glScalef(15.0f, 50.0f, 80.0f);
        glutSolidCube(1.0f);
        glScalef(1.0f/15.0f, 1.0f/50.0f, 1.0f/80.0f);
        //Left leg and joints
        glPushMatrix();
            //Joint
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, -12.5f, -40.0f);
            glRotatef(leftLeg, 0.0, 1.0, 0.0);
            gluSphere(pObj, 5.0f, 50, 30);
            //Leg Part 1
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.5f);
            glScalef(15.0f, 20.0f, 40.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/15.0f, 1.0f/20.0f, 1.0f/40.0f);
            //Knee
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.0f);
            gluSphere(pObj, 7.5f, 50, 30);
            //Leg Part 2
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.5f);
            glScalef(15.0f, 20.0f, 40.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/15.0f, 1.0f/20.0f, 1.0f/40.0f);
            //Ankle
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.0f);
            gluSphere(pObj, 5.0f, 50, 30);
            //Foot
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(1.0f, 0.0f, -6.0f);
            glScalef(20.0f, 20.0f, 10.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/20.0f, 1.0f/20.0f, 1.0f/10.0f);
        glPopMatrix();
        //Right Leg and Joints
        glPushMatrix();
            //Joint
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 12.5f, -40.0f);
            glRotatef(rightLeg, 0.0, 1.0, 0.0);
            gluSphere(pObj, 5.0f, 50, 30);
            //Leg Part 1
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.5f);
            glScalef(15.0f, 20.0f, 40.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/15.0f, 1.0f/20.0f, 1.0f/40.0f);
            //Knee
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.0f);
            gluSphere(pObj, 7.5f, 50, 30);
            //Leg Part 2
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.5f);
            glScalef(15.0f, 20.0f, 40.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/15.0f, 1.0f/20.0f, 1.0f/40.0f);
            //Ankle
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, -20.0f);
            gluSphere(pObj, 5.0f, 50, 30);
            //Foot
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(1.0f, 0.0f, -6.0f);
            glScalef(20.0f, 20.0f, 10.0f);
            glutSolidCube(1.0f);
            glScalef(1.0f/20.0f, 1.0f/20.0f, 1.0f/10.0f);
        glPopMatrix();
        //Left Arm and Joints
        glPushMatrix();
            //Shoulder Joint
            	glColor3f(1.0f, 1.0f, 1.0f);
            	glTranslatef(0.0f, 35.0f, 35.0f);
                glRotatef(leftShoulder, 0.0, 1.0, 0.0);
            	gluSphere(pObj, 10.0f, 50,30);
            //Arm 
            	glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -22.0f);
            	glScalef(15.0f, 15.0f, 25.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/15.0f, 1.0f/15.0f, 1.0f/25.0f);
            glPushMatrix();
                //Forearm Joints
                glColor3f(1.0f, 1.0f, 1.0f);
            	glTranslatef(0.0f, 0.0f, -15.0f);
            	gluSphere(pObj, 5.0f, 50, 30);
                //Forearm
                glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -12.0f);
            	glScalef(15.0f, 15.0f, 25.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/15.0f, 1.0f/15.0f, 1.0f/25.0f);
                //Hand Joint
                glColor3f(1.0f, 1.0f, 1.0f);
                glRotatef(leftHand, 0.0, 1.0, 0.0);
            	glTranslatef(0.0f, 0.0f, -15.0f);
            	gluSphere(pObj, 4.0f, 50, 30);
                //Hand
                glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -7.0f);
            	glScalef(5.0f, 15.0f, 15.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/5.0f, 1.0f/15.0f, 1.0f/15.0f);
            glPopMatrix();
        glPopMatrix();
        //Right Arm and Joints
        glPushMatrix();
            //Shoulder Joint
            	glColor3f(1.0f, 1.0f, 1.0f);
            	glTranslatef(0.0f, -35.0f, 35.0f);
                glRotatef(rightShoulder, 0.0, 1.0, 0.0);
            	gluSphere(pObj, 10.0f, 50,30);
            //Arm Joint
            	glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -22.0f);
            	glScalef(15.0f, 15.0f, 25.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/15.0f, 1.0f/15.0f, 1.0f/25.0f);
            //Forearm/Hand and Joints
            glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
            	glTranslatef(0.0f, 0.0f, -15.0f);
            	gluSphere(pObj, 5.0f, 50, 30);
                //Forearm
                glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -12.0f);
            	glScalef(15.0f, 15.0f, 25.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/15.0f, 1.0f/15.0f, 1.0f/25.0f);
                //Hand Joint
                glColor3f(1.0f, 1.0f, 1.0f);
            	glTranslatef(0.0f, 0.0f, -15.0f);
                glRotatef(rightHand, 0.0, 1.0, 0.0);
            	gluSphere(pObj, 4.0f, 50, 30);
                //Hand
                glColor3f(1.0f, 0.0f, 1.0f);
            	glTranslatef(0.0, 0.0, -7.0f);
            	glScalef(5.0f, 15.0f, 15.0f);
            	glutSolidCube(1.0f);
            	glScalef(1.0f/5.0f, 1.0f/15.0f, 1.0f/15.0f);
            glPopMatrix();
        glPopMatrix();
        //Head
        glPushMatrix();
            //Neck
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 38.0f);
            gluCylinder(pObj, 5.0f, 5.0f, 5.0f, 50, 30);
            //Head
            glColor3d(1.0f, 0.0f, 1.0f);
            glTranslatef(0.0f, 0.0f, 12.5f);
            glScalef(15.0f, 25.0f, 20.0f);
            glutSolidCube(1.25f);
            glScalef(1.0f/15.0f, 1.0f/25.0f, 1.0f/20.0f);
            //Eyes
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(8.5f, 9.0f, 8.0f);
            glScalef(5.0f, 5.0f, 5.0f);
            glutSolidCube(1.0f);
            glTranslatef(0.0f, -4.0f, 0.0f);
            glutSolidCube(1.0f);
        glPopMatrix();
    
    glPopMatrix();
}

void DrawScene(void) {
    GLfloat light_pos[] = {500.0, 500.0, 500.0, 1.0};
    double cam_x, cam_y, cam_z;
    static float position_x = -600.0;
    static double speed = 0.0;

    // FOV
    cam_x = position_x + 800.0;
    cam_y = 800.0;
    cam_z = 800.0 * cos(1.5);
    glLoadIdentity();
    gluLookAt(cam_x, cam_y, cam_z, position_x, 0.0, 0.0, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Lightning
    glLightfv (GL_LIGHT0, GL_POSITION, light_pos);
    glEnable(GL_LIGHTING);

    // Floor
    /*
    int i, j, c = 100;
    for(i = -20; i <= 20; i++) {
        for(j = -20; j <= 20; j++) {
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
                glNormal3f(0,0,1);
                glVertex3f(i * c, j * c, 0.0);
                glVertex3f(i * c + c, j * c, 0.0);
                glVertex3f(i * c + c, j * c + c, 0.0);
                glVertex3f(i * c, j * c + c, 0.0);
            glEnd();
        }
    }
    */

    if(action == WALK) {
        position_x += fabs(3.0 * sin((70 + speed) * 0.01745));
        speed = fmod(speed + 8.0, 360.0);
    }
    
    glTranslatef(position_x, 0.0, 85);
    buildRobot();
    glutSwapBuffers();
}

void SetupRC() {
    GLfloat whiteLight[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat sourceLight[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat lightPos[] = { 1.0, 1.0, 1.0, 1.0 };
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    glLightfv(GL_LIGHT0,GL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void animation(ANIMATION action) {
    static double speed = 0.0;
    switch(action) {
        case WALK:
            leftHand = 0.0;
            rightLeg = 20.0 * sin(speed * 0.01745);
            rightShoulder = -30.0 * sin(speed * 0.01745);
            leftLeg = -20.0 * sin(speed * 0.01745);
            leftShoulder = 30.0 * sin(speed * 0.01745); 
            speed = fmod(speed + 8.0, 360.0);
        case STOP:
            if(speed == 0) break;
            break;
        case ACENAR:
        	leftShoulder = -200.0 * sin(speed * (0.01745/2));  
            speed = fmod(speed + 8.0, 360.0); 
            break;
    }
}

void ChangeSize(int w, int h) {
    if(w < 700) glutReshapeWindow(700, h);
    if(h < 500) glutReshapeWindow(w, 500);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(24.0f, (GLfloat)w / (GLfloat)h, 0.5f, 10000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int a, int b) {
    switch(key) {
        case 'w':
            action = WALK;
            break;
        case 's':
            action = STOP;
            break;
        case 'a':
        	action = ACENAR;
    }
}

void Loop(int w) {
    glutPostRedisplay();
    animation(action);
    glutTimerFunc(40, Loop, 1);
}

// Programa Principal
int main(int argc, char*argv[]) {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bruno Marchi Pires - Guilherme Araújo");
    glutDisplayFunc(DrawScene);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);
    SetupRC();
    Loop(1);
    glutMainLoop();
}
