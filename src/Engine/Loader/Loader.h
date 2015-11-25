#pragma once
#include <GL\GL.h>
#include "src\Engine\Model\ShapeData.h"
#include <vector>
class Loader{

public:
	
	void loadObject(ShapeData& shape); // need to add cleanup method !!!

private:

	ShapeData *shape;

	void setupVertexAndIndexArrays();
	void bindShapeData();
	void bindShapeData_type1();			//type1 = position only
	void bindShapeData_type2();			//type2 = position and color;

};

