#include "renderer.h"
#include "string"

namespace Engine {

	
    Renderer::Renderer() {
		char title[] = "Simple example";
		wind = new Window(title);
		cube = new Cube();
		
		this->rendState = new RenderState;
		this->rendState->leftTri = false;
		this->rendState->xPos = 0.0;
		this->rendState->yPos = -4.0;
		this->rendState->zPos = 1.0;
		this->rendState->xRotate = 0.0;
		this->rendState->yRotate = 0.0;

		//TODO: Shift 
		const char *vertexShaderSource ="#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout(location = 1) in vec3 vertexColor;\n"
			"uniform mat4 mvp;\n"
			"out vec3 fragmentColor;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = mvp * vec4(aPos, 1.0);\n"
			"	fragmentColor = vertexColor;\n"
			"}\0";
		const char *fragmentShaderSource = "#version 330 core\n"
			"in vec3 fragmentColor;\n"
			"out vec3 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = fragmentColor;\n"
			"}\n\0";
		

		//Vertex shader
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		//Check for shader compile errors
		int success;
		//char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			//TODO: fail safely
			//glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		}
		
		//Fragment shader
		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		//Check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			//TODO: fail safely
			//glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		}
		
		//Link shaders
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			//glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
    }

    Renderer::~Renderer() {
		//TODO: Exit cleanly
    }
	
	void Renderer::render() {
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		
		//Clear Screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Calculate Projection and View
		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) wind->getWidth() / (float)wind->getHeight(), 0.1f, 100.0f);
		glm::mat4 View = glm::lookAt(
			glm::vec3(this->rendState->xPos,this->rendState->zPos,this->rendState->yPos), //Camera Location
			glm::vec3(this->rendState->xPos + cosl(this->rendState->yRotate) * sinl(this->rendState->xRotate),this->rendState->zPos + sinl(this->rendState->yRotate),this->rendState->yPos + cosl(this->rendState->xRotate) * cosl(this->rendState->yRotate)), //Camera Look-at
			glm::vec3(0,1,0)  //Camera Head-up
		);
		
		//Draw Model
		cube->draw(this->rendState->leftTri, Projection, View, shaderProgram);
		
		//Render Model View Projection
		wind->render();		
	}
	
	Window* Renderer::getWindow() {
		return wind;
	}
	
	RenderState* Renderer::getState() {
		return this->rendState;
	}
	
	//Initializes Keyboard and Mouse callbacks 
	void Renderer::setInputs(GLFWkeyfun func, void* inState) {
		wind->setKeyCallback(func);
		wind->setInputPointer(inState);
	}
} //namespace Engine