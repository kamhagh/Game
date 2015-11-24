#pragma once
#include <vector>
#include "src\Engine\Model\ShapeData.h"
#include "src\Engine\Entities\Entity.h"
class Renderer{

public:
	void prepare();
	void render();
	void render(Entity &entity);
	inline void processEntities(Entity entity){ entities.push_back(entity); }

private:

	std::vector<Entity> entities;


};