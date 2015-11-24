#include <GL\glew.h>
#include <QtWidgets\qapplication.h>

int main(int argc, char* argv[]){
	
	QApplication application(argc, argv);

	SandboxWindow window;

	window.show();


	return application.exec();
}