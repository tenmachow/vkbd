#include "keyboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	KeyBoard keyboard;

	keyboard.show();

	return app.exec();
}
