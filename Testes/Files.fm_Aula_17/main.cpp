#include<Windows.h>
#include<GLFW/glfw3.h>
#include<gl/GLU.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include "cores.h"
#include "primitivas.h"
#include "Camera.h"
#include "Textura.h"

static float angulo = 5.0;
static float lastMousePos = 0.0;
static bool firstTimeMouse = true;

// Display List
struct Objeto {
	GLuint id;
	vec3 pos;
	Objeto() :id(0), pos(vec3(0.0, 0.0, 0.0)) {}
};

const GLuint total_objetos = 45;
std::vector<Objeto> objetos;

Camera camera(vec3(-100, 0, 0));

enum{BRICK,PAINTED,MASK,WOOD,METAL};
Textura CuboTex[5];


void redimensiona(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}


void desenha(float dt)
{

	float veloc_ang = 60.0*dt;// 60 graus por segundo

	glLoadIdentity();


	camera.ativar();

	glCallList(objetos[0].id);

	for (int i = 1; i < total_objetos; i++)
	{
		float x = objetos[i].pos.x;
		float y = objetos[i].pos.y;
		float z = objetos[i].pos.z;

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(angulo, 1.0, 1.0, 0.0);
		glCallList(objetos[i].id);
		glPopMatrix();
	}

	angulo += veloc_ang;
	if (angulo >= 360.0)
		angulo = 0.0;
}

float aleatorio(float a, float b)
{
	float n = (float)rand() / RAND_MAX;
	float t = b - a;
	float r = a + n * t;
	return r;
}

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else if (key==GLFW_KEY_W &&(action == GLFW_PRESS || action==GLFW_REPEAT))
	{
		// Forward
		camera.forward();
	}
	else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		// Back
		camera.back();

	}
	else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		// Left
		camera.left();

	}
	else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		// Right
		camera.right();
	}
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	float dx;

	if (firstTimeMouse)
	{
		dx = 0;
		lastMousePos = xpos;
		firstTimeMouse = false;
	}
	dx = xpos - lastMousePos;
	lastMousePos = xpos;
	camera.updateYaw(dx);
	camera.update();
}

void init(GLFWwindow* window)
{
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetKeyCallback(window, teclado_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwMaximizeWindow(window);
	//glClearColor(0.0, 0.15, 0.25, 1.0); // cor de fundo
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	CuboTex[BRICK].load("images/cubo/brick.png");
	CuboTex[WOOD].load("images/cubo/wood.png");
	CuboTex[METAL].load("images/cubo/metal.png");
	CuboTex[PAINTED].load("images/cubo/painted_brick.png");
	CuboTex[MASK].load("images/cubo/mask.png");

	for (int i = 0; i < total_objetos; i++)
	{
		Objeto p;
		objetos.push_back(p);
	}

	objetos[0].id = glGenLists(total_objetos);
	desenhaTerreno(objetos[0].id);

	for (int i = 1; i < total_objetos; i++)
	{
		objetos[i].id = objetos[0].id + i;
		float x = aleatorio(-200, 200);
		float y = aleatorio(8, 20);
		float z = aleatorio(-300,300);
		objetos[i].pos = vec3(x, y, z);

		float k = (float)rand() / RAND_MAX;
		if (k <= 0.5)
		{
			color* cor;
			if (k <= 0.15)
				cor = &verde;
			else
				cor = &laranja;
			desenhaEsfera(objetos[i].id, *cor, 5.0, 20.0, 20.0);
		}
		else
		{
			Textura* tex;
			if (k <= 0.60)
				tex = &CuboTex[WOOD];
			else if (k <= 0.70)
				tex = &CuboTex[METAL];
			else if (k <= 0.80)
				tex = &CuboTex[MASK];
			else if (k <= 0.90)
				tex = &CuboTex[PAINTED];
			else
				tex = &CuboTex[BRICK];

			desenhaCubo(objetos[i].id, tex,5.0);
		}
	}

}


int main(void)
{

	const int LARGURA = 800;
	const int ALTURA = 600;

	/* Initialize the library */
	glfwInit();

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Camera OpenGL", NULL, NULL);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// -- inicio
	init(window);

	float valor = 0.0;
	float lastTime = 0.0;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		float currentTime = (float)glfwGetTime();
		float dt = currentTime - lastTime;
		lastTime = currentTime;

		/* Poll for and process events */
		glfwPollEvents();
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int largura, altura;
		glfwGetFramebufferSize(window, &largura, &altura);

		redimensiona(largura, altura);

		desenha(dt);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	glDeleteLists(objetos[0].id, total_objetos);
	glfwTerminate();
	return 0;
}