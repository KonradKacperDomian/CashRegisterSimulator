
#include <iostream>
#include <Windows.h>
#include "core/ProductListManager.h"
#include "core/DailyRaport.h"
#include "gui/mainwindow.h"
#include <QApplication>

int main(int ac, char** av)
{
	DailyRaport newDailyRaport;
	ProductListManager VectorOfProducts;//wczytywanie danych z pliku

	QApplication app(ac, av);

	MainWindow window(newDailyRaport, VectorOfProducts, nullptr);
	window.show();

	return app.exec();
}