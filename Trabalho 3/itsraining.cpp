#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

//O objetivo é tentar fazer uma tela de chuva utilizando conceitos
//de sistema de partículas

//O ínicio da chuva ta estranho, com muitos riscos alinhados
//provalvemente se arruma isso mudando os valores de "setParticles()"

#define PARTICLES 7500

typedef struct{
	bool isSetted;
	float lifeTime, timeTaken, x, y, z, velocity, gravity;
	//timeTaken é o "tempo" que sera retirado do lifeTime
}Particle;

//variaveis globais
int counter;
Particle conj_particulas[PARTICLES];

void setParticles(int n){
	//seta informações iniciais de cada partícula
	conj_particulas[n].isSetted = true;
	conj_particulas[n].lifeTime = 2.0;
	conj_particulas[n].timeTaken = (float)(rand()%100)*0.001; 
	conj_particulas[n].x = (float)(rand()%50);
	conj_particulas[n].z = (float) (rand() % 15);
	conj_particulas[n].y = 15.0;
	conj_particulas[n].velocity = 0.0001;
	conj_particulas[n].gravity = -0.00009;
}

void initParticles(){
	for (counter = 0; counter <= PARTICLES; counter++){
		setParticles(counter);
	}
}

void itsraining(){
	float xAux, yAux, zAux;
	for(counter = 0; counter < PARTICLES; counter++){
		if(conj_particulas[counter].isSetted == true){
			xAux = conj_particulas[counter].x;
			yAux = conj_particulas[counter].y;
			zAux = conj_particulas[counter].z-25; 
			//desenhando chuva
			//glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
			glColor3f(0.2f, 0.4f, 1.0f);
			glBegin(GL_LINES);
			glVertex3f(xAux-1, yAux, zAux);
			glVertex3f(xAux, yAux+1, zAux);
			glEnd();
			
			//manipulando particulas
			conj_particulas[counter].x += conj_particulas[counter].velocity;
			conj_particulas[counter].y += conj_particulas[counter].velocity;
			//Z não precisa
			//simulando uma gravidade duvidosa
			conj_particulas[counter].velocity += conj_particulas[counter].gravity;
			//matando partícula
			conj_particulas[counter].lifeTime -= conj_particulas[counter].timeTaken;
			
			//revivendo partícula
			if(conj_particulas[counter].lifeTime <= 0.0){
				setParticles(counter);
			}
		}
		
	}
}

void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.00f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glEnd();
    itsraining();
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


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TC3 - Partículas - Bruno Marchi Pires");
    
    initParticles();
    
    glutDisplayFunc(drawScene); 
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(glutPostRedisplay); //mágica
    glutMainLoop();
    return 0;
}
