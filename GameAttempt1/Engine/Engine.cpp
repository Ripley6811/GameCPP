#include "Engine.h"
#include "IO\mouse.h"
#include "IO\Keyboard.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window;
double Engine::dt = 0;
double Engine::lastTime;

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(char* windowTitle)
{
	if (!glfwInit())
	{
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (!window)
	{
		cout << "Error creating window" << endl;
		return false;
	}
	// TODO: add glfwTerminate() and glfwDestroyWindow(window) somewhere

	// GLFW Setup
	glfwMakeContextCurrent(window);  // Must have OpenGL context to use OpenGL API
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1); //Swap every frame

	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	// GL Setup
	// viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // Applies the projection
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);
	
	// Alpha blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Update()
{
	double now = glfwGetTime();
	dt = now - lastTime;
	lastTime = now;
	glfwPollEvents();  //Capture mouse motion etc.
}

void Engine::BeginRender()
{
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender()
{
	glfwSwapBuffers(window);
}

double Engine::GetDT()
{
	return dt;
}