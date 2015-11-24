#pragma once;
#include "src\Engine\Model\ShapeData.h"

class Entity{

public:

	Entity(ShapeData &shape) : shape(&shape){}
	inline ShapeData &getShape(){ return *shape; }
	ShapeData *shape;
private:
	
};