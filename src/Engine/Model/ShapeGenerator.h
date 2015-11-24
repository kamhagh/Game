#pragma once
#include "ShapeData.h"
#include <QtCore\qstring.h>
#include <glm\glm.hpp>
class ShapeGenerator
{

public:
	static ShapeData createBasicTriangle();
	static ShapeData createCubeTest();
	static ShapeData createObjectFromObjFile(QString fileName, glm::vec3 &color = glm::vec3(0.0f, 0.0f, 0.0f));

};

