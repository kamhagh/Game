#pragma once

#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include <QtCore\qtimer.h>
#include "src\Engine\Tming\Clock.h"
#include <QtCore\qdebug.h>

class SandboxWindow : public QGLWidget{

	Q_OBJECT

public:
	bool initialize();
	bool shutdown();

protected:

	void initializeGL();
	void paintGL();

private:

	QTimer timer;
	Clock clock;

	void checkKeyState();

private slots:

	void update();
};