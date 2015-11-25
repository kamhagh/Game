#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>

class ShapeData {

public:
	ShapeData(){};
	ShapeData(std::vector<float> verts, std::vector<GLuint> ind) : verts(verts), indicies(ind), type(1){}

	std::vector<float> verts;
	std::vector<GLuint> indicies;


	GLuint vertexArrayObjectID;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	int type;

};