#include <GL\glew.h>
#include "src\Engine\Loader\Loader.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <SOIL\SOIL.h>
using std::vector;

void Loader::loadObject(ShapeData &shape){

	this->shape = &shape;

	setupVertexAndIndexArrays();	
	bindShapeData();

}

void Loader::loadTexture(Texture &texture){
	
	glGenTextures(1, &texture.bufferID);
	glBindTexture(GL_TEXTURE_2D, texture.bufferID);

	unsigned char* image = SOIL_load_image(texture.path.c_str(), &texture.width, &texture.height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	
	// move to renderer ! 
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.bufferID);
	
}


void Loader::bindShapeData(){

	switch (shape->type)
	{
	case (1) : {
		bindShapeData_type1();
		break;
	}
	case (2) : {
		bindShapeData_type2();
		break;
	}
	case (3) : {
		loadTexture(shape->texture);
		bindShapeData_type3();
		break;
	}
	}


}

void Loader::bindShapeData_type1(){

	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

}

void Loader::bindShapeData_type2(){
	
	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void Loader::bindShapeData_type3(){
	
	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}


void Loader::setupVertexAndIndexArrays(){

	glGenVertexArrays(1, &shape->vertexArrayObjectID);
	glBindVertexArray(shape->vertexArrayObjectID);

	glGenBuffers(1, &shape->vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, shape->vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, shape->verts.size() * sizeof(float), &shape->verts[0], GL_STATIC_DRAW);


	glGenBuffers(1, &shape->indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shape->indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape->indicies.size() * sizeof(GLuint), &shape->indicies[0], GL_STATIC_DRAW);

}
