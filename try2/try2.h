#ifndef TRY2_H
#define TRY2_H

#include <QtWidgets/QMainWindow>
#include "ui_try2.h"

class try2 : public QMainWindow
{
	Q_OBJECT

public:
	try2(QWidget *parent = 0);
	~try2();

private:
	Ui::try2Class ui;
};

#endif // TRY2_H
