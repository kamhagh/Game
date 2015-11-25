#pragma once;
#include "src\Engine\Model\ShapeData.h"
#include <glm\glm.hpp>

class Entity{

public:

	Entity(ShapeData &shape) : shape(&shape){}
	inline ShapeData &getShape(){ return *shape; }
	
	ShapeData *shape;
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(0.0f, 0.0f, 0.0f);

private:
	
};