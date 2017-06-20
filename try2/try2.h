#ifndef TRY2_H
#define TRY2_H

#include <QtWidgets/QMainWindow>
#include "ui_try2.h"
#include "Programmer.h"
#include "Task.h"
#include "qmessagebox.h"

class CustomException : public std::exception {
private:
	std::string error;
public:
	CustomException(){}
	CustomException(std::string e): std::exception{}, error{e} {}
	virtual const char* what() { return this->error.c_str(); }
};

class try2 : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	try2(Programmer p, TaskRepository& repo,QWidget *parent = 0);
	~try2();
	void update() override;
	void addTask();
	void removeTask();
	int getIndex();
	void startTask();
	void closeTask();

private:
	Ui::try2Class ui;
	TaskRepository& repo;
	Programmer p;
};

#endif // TRY2_H
