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
	{ -0.5, 0.5, 0,
	-0.5, -0.5, 0
	};

	vector<GLuint> index = {
		0, 1, 3
	};
	shape = ShapeData(verts, index);
	loader.loadObject(shape);

	

}

void SandboxWindow::paintGL(){

	glViewport(0, 0, width(), height());
	renderer.prepare();

	
	Entity entity = Entity(shape);
	renderer.render(entity);

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

void SandboxWindow::close(){
	
	
}