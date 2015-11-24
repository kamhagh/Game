#include "src\SandboxGame\Window\SandboxWindow.h"
#include <iostream>
#include <vector>
using std::vector;

bool SandboxWindow::initialize(){

	bool state;
	state = clock.initialize();
	if (state != true){

		qDebug() << "failed to initialize clock";
		return state;
	}

	return true;
}

bool SandboxWindow::shutdown(){

	bool state;
	state = clock.shutdown();
	if (state != true){

		qDebug() << "failed to shutdown clock";
		return state;
	}

	return true;
}

void SandboxWindow::initializeGL(){
	
	glewInit();
	
	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(1000 / settings.eng.MAX_FPS);

	vector<float> verts =
	{ -1, -1, 0,
	1, -1, 0,
	0,1,0
	};

	vector<GLuint> index = {
		0, 1, 2
	};

	shape = ShapeData(verts, index);
	loader.loadObject(shape);

	Entity entity = Entity(shape);
	renderer.processEntities(entity);

}

void SandboxWindow::paintGL(){

	glViewport(0, 0, width(), height());
	renderer.prepare();

	renderer.render();
	


}

void SandboxWindow::update(){

	clock.newFrame();
	checkKeyState();
	repaint();
}

void SandboxWindow::checkKeyState(){

	if (GetAsyncKeyState(VK_ESCAPE)){
		close();
	}
}
