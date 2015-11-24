#include "GL\glew.h"
#include "src\Engine\Render Engine\Renderer.h"

void Renderer::prepare(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

}

void Renderer::render(){

	for (auto i : entities){

		glBindVertexArray(i.shape->vertexArrayObjectID);
		glDrawElements(GL_TRIANGLES, i.shape->indicies.size(), GL_UNSIGNED_INT, 0);
	}
		
}

void Renderer::render(Entity &entity){

	/*ShapeData *shape = &entity.getShape();*/
	glBindVertexArray(entity.shape->vertexArrayObjectID);
	glDrawElements(GL_TRIANGLES, entity.shape->indicies.size(), GL_UNSIGNED_SHORT, 0);


}
