#include <Windows.h>

#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qtextstream.h>
#include "EldenDing.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QFile file(":/dark.qss");
	file.open(QFile::ReadOnly | QFile::Text);
	QTextStream stream(&file);
	a.setStyleSheet(stream.readAll());

    EldenDing w;
    w.show();
    return a.exec();
}
