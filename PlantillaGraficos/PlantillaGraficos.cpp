// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Shader.h"
#include "Vertice.h"
#include <vector>

using namespace std;

//Cada elemento que queramos renderear necesita un vertex array y un buffer

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> circulo;
GLuint vertexArrayCirculoID;
GLuint bufferCirculoID;

//Instancia del shader
Shader *shader;
//Identificadores para mapeo de atributos de entrada del vertex shader
GLuint posicionID;
GLuint colorID;

/*void inicializarCirculo() {
	//nubes
	for (double i = 0; i < 360.0; i += 5.0)
	{
		Vertice v1 = {
			vec3(0.1 * cos(i * 3.14159 / 180.0)) - 0.2, //tamaño X y offset X
			(0.05 * sin(i * 3.14159 / 180.0)) + 0.7, //tamaño Y y offset Y
			0.0f);
		}
		vec4(1.0f, 1.0f, 1.0f, 1.0f)
	}
	cirulo.push_back(v1);
}*/


void inicializarCuadrado() {
	//cesped
	Vertice v1 = {
		vec3(-1.0f, -0.6f, 0.0f),
		vec4(0.2578f, 0.5625f, 0.3164f, 1.0f)
	};
	Vertice v2 = {
		vec3(1.0f, -0.6f, 0.0f),
		vec4(0.2578f, 0.5625f, 0.3164f, 1.0f)
	};
	Vertice v3 = {
		vec3(1.0f, -1.0f, 0.0f),
		vec4(0.2578f, 0.5625f, 0.3164f, 1.0f)
	};
	Vertice v4 = {
		vec3(-1.0f, -1.0f, 0.0f),
		vec4(0.2578f, 0.5625f, 0.3164f, 1.0f)
	};

	//1
	Vertice v5 = {
		vec3(0.1f, 0.05f, 0.0f),
		vec4(0.5333f, 0.4235f, 0.3529f, 1.0f)
	};
	Vertice v6 = {
		vec3(-0.1f, 0.05f, 0.0f),
		vec4(0.5333f, 0.4235f, 0.3529f, 1.0f)
	};
	Vertice v7 = {
		vec3(-0.1f, -0.1f, 0.0f),
		vec4(0.5333f, 0.4235f, 0.3529f, 1.0f)
	};
	Vertice v8 = {
		vec3(0.1f, -0.1f, 0.0f),
		vec4(0.5333f, 0.4235f, 0.3529f, 1.0f)
	};

	//2
	Vertice v9 = {
		vec3(0.2f, -0.1f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v10 = {
		vec3(-0.2f, -0.1f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v11 = {
		vec3(-0.2f, -0.2f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v12 = {
		vec3(0.2f, -0.2f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};

	//3
	Vertice v13 = {
		vec3(0.3f, -0.2f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v14 = {
		vec3(-0.3f, -0.2f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v15 = {
		vec3(-0.3f, -0.3f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v16 = {
		vec3(0.3f, -0.3f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};

	//4
	Vertice v17 = {
		vec3(0.4f, -0.3f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v18 = {
		vec3(-0.4f, -0.3f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v19 = {
		vec3(-0.4f, -0.4f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v20 = {
		vec3(0.4f, -0.4f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};

	//5
	Vertice v21 = {
		vec3(0.5f, -0.4f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v22 = {
		vec3(-0.5f, -0.4f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v23 = {
		vec3(-0.5f, -0.5f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v24 = {
		vec3(0.5f, -0.5f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};

	//6
	Vertice v25 = {
		vec3(0.6f, -0.5f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v26 = {
		vec3(-0.6f, -0.5f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v27 = {
		vec3(-0.6f, -0.6f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};
	Vertice v28 = {
		vec3(0.6f, -0.6f, 0.0f),
		vec4(0.6666f, 0.6078f, 0.5607f, 1.0f)
	};

	//escaleras
	Vertice v29 = {
		vec3(0.1f, -0.1f, 0.0f),
		vec4(0.5372f, 0.4431f, 0.3843f, 1.0f)
	};
	Vertice v30 = {
		vec3(-0.1f, -0.1f, 0.0f),
		vec4(0.5372f, 0.4431f, 0.3843f, 1.0f)
	};
	Vertice v31 = {
		vec3(-0.15f, -0.6f, 0.0f),
		vec4(0.5372f, 0.4431f, 0.3843f, 1.0f)
	};
	Vertice v32 = {
		vec3(0.15f, -0.6f, 0.0f),
		vec4(0.5372f, 0.4431f, 0.3843f, 1.0f)
	};

	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
	
	cuadrado.push_back(v5);
	cuadrado.push_back(v6);
	cuadrado.push_back(v7);
	cuadrado.push_back(v8);

	cuadrado.push_back(v9);
	cuadrado.push_back(v10);
	cuadrado.push_back(v11);
	cuadrado.push_back(v12);

	cuadrado.push_back(v13);
	cuadrado.push_back(v14);
	cuadrado.push_back(v15);
	cuadrado.push_back(v16);

	cuadrado.push_back(v17);
	cuadrado.push_back(v18);
	cuadrado.push_back(v19);
	cuadrado.push_back(v20);

	cuadrado.push_back(v21);
	cuadrado.push_back(v22);
	cuadrado.push_back(v23);
	cuadrado.push_back(v24);

	cuadrado.push_back(v25);
	cuadrado.push_back(v26);
	cuadrado.push_back(v27);
	cuadrado.push_back(v28);

	cuadrado.push_back(v29);
	cuadrado.push_back(v30);
	cuadrado.push_back(v31);
	cuadrado.push_back(v32);
}


void dibujar() {
	//Elegir shader
	shader->enlazar();
	//Elegir el vertexArray 
	//Llamar la funcion de dibujo-Dibujar
	//Proceso dibujo de Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	glBindVertexArray(vertexArrayCirculoID);
	glDrawArrays(GL_POLYGON, 0, circulo.size());

	//Soltar Bind vertex array
	glBindVertexArray(0);
	//Soltar/desenlazar Shader
	shader->desenlazar();
}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW, inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);
	//Si no se pudo crear la ventana, terminamos la ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//inicializarTriangulo();
	inicializarCuadrado();

	const char* rutaVertexShader = "VertexShader.shader";
	const char* rutaFragmentShader = "FragmentShader.shader";
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	//Mapeo de atributos
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	/*//Crear el vertex array del triangulo
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);

	//Asociar datos al buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como comunicarse
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));*/
	
	
	//Proceso de inicializar Vertex Array para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	
	//Proceso de inicializar Vertex Array para el circulo
	glGenVertexArrays(1, &vertexArrayCirculoID);
	glBindVertexArray(vertexArrayCirculoID);
	glGenBuffers(1, &bufferCirculoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCirculoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * circulo.size(), circulo.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar el vertexArray y el buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	


	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.34, 0.64, 0.77, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo, eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}