#pragma once

#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include <QtCore\qtimer.h>
#include "src\Engine\Tming\Clock.h"
#include <QtCore\qdebug.h>
#include "src\SandboxGame\Settings\SanboxSettings.h"
#include "src\Engine\Loader\Loader.h"
#include "src\Engine\Render Engine\Renderer.h"
#include "src\Engine\Model\ShapeData.h"
#include "src\Engine\Entities\Entity.h"
#include "src\Engine\Shader\BasicShader.h"

class SandboxWindow : public QGLWidget{

	Q_OBJECT

public:

	bool initialize();
	bool shutdown();

protected:

	void initializeGL();
	void paintGL();

private:

	SandboxSettings settings;

	Loader loader;
	Renderer renderer;

	ShapeData shape;
	BasicShader basicShader;

	QTimer timer;
	Clock clock;

	void checkKeyState();

private slots:

	void update();
};