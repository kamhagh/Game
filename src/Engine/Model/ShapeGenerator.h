#pragma once
#include "ShapeData.h"
#include <QtCore\qstring.h>
#include <glm\glm.hpp>
class ShapeGenerator
{

public:
	static ShapeData createTriangle_type1();
	static ShapeData createTriangle_type2();
	static ShapeData createTriangle_type3();
	static ShapeData createCubeTest();
	static ShapeData createObjectFromObjFile(QString fileName, glm::vec3 &color = glm::vec3(0.0f, 0.0f, 0.0f));

};

