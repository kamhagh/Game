#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "src\Engine\Model\Vertex.h"
#include <vector>

class ShapeData {

public:
	ShapeData(){};
	ShapeData(std::vector<float> pos, std::vector<GLuint> ind) : position(pos), indicies(ind), type(1){}

	std::vector<float> position;
	std::vector<GLuint> indicies;
	std::vector<float> color;
	std::vector<float> normals;
	std::vector<float> texture;

	GLuint vertexArrayObjectID;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	int type;

};