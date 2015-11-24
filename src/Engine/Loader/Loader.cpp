#include <GL\glew.h>
#include "src\Engine\Loader\Loader.h"
#include <vector>
using std::vector;

void Loader::loadObject(ShapeData &shape){

	this->shape = &shape;

	setupVertexAndIndexArrays();	
	bindShapeData();

	/*GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), &shape.position[0], GL_STATIC_DRAW);
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);*/
}


void Loader::bindShapeData(){

	switch (shape->type)
	{
	case (1) :
		bindShapeData_type1();
		break;
	}

}

void Loader::bindShapeData_type1(){

	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

}


void Loader::setupVertexAndIndexArrays(){

	glGenVertexArrays(1, &shape->vertexArrayObjectID);
	glBindVertexArray(shape->vertexArrayObjectID);

	glGenBuffers(1, &shape->vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, shape->position.size() * sizeof(float), &shape->position[0], GL_STATIC_DRAW);


	glGenBuffers(1, &shape->indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape->indicies.size() * sizeof(GLuint), &shape->indicies[0], GL_STATIC_DRAW);

}
