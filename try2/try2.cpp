#include "try2.h"


try2::try2(Programmer p, TaskRepository& repo, QWidget *parent)
	:p(p), repo(repo), QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromStdString(this->p.getName()));
	this->repo.addObserver(this);

	connect(this->ui.addButton, &QPushButton::clicked, this, &try2::addTask);
	connect(this->ui.removeButton_2, &QPushButton::clicked, this, &try2::removeTask);
	connect(this->ui.startButton, &QPushButton::clicked, this, &try2::startTask);
	connect(this->ui.closeButton, &QPushButton::clicked, this, &try2::closeTask);
	update();
}

try2::~try2()
{

}

void try2::update()
{
	this->ui.taskListWidget->clear();
	int count = 0;
	for (auto t : this->repo.getTasksSorted())
		if (t.getProgrammer() != "")
		{
			
			this->ui.taskListWidget->addItem(QString::fromStdString(t.getTask() + "; " + t.getProgrammer()));
			//ui.taskListWidget->currentItem()->setBackgroundColor(QColor{ "red" });
			QFont f; f.setItalic(true);
			ui.taskListWidget->item(count)->setFont(f);
			++count;
		}
		else
		{
			//QBrush col{ QColor{"red"} };
			//QListWidgetItem i{ QString::fromStdString(t.getTask())};
			//i.setBackgroundColor(QColor{ "red" });
			this->ui.taskListWidget->addItem(QString::fromStdString(t.getTask()));
			++count;
		}
}

void try2::addTask()
{
	std::string desc = this->ui.taskDescriptionEdit->text().toStdString();
	if (desc != "")
		this->repo.addTask(Task{ desc, "open", p.getId() });

}

void try2::removeTask()
{
	std::string desc = this->ui.taskDescriptionEdit->text().toStdString();
	if (desc != "")
		this->repo.removeTask(desc);
}

int try2::getIndex()
{

	if (this->ui.taskListWidget->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->ui.taskListWidget->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
	
}

void try2::startTask()
{
	int current = getIndex();
	try {
		if (repo.getTasks()[current].getStatus() != "open")
			throw std::exception("Task not open!");
		this->repo.getTasks()[current].setInprogress();
		this->repo.getTasks()[current].setProgrammer(this->p.getName());
		this->repo.notify();
	}
	catch (...)
	{
		QMessageBox box{};
		auto reply = box.question(0, "Confirmation", "Delete entry?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			QMessageBox box{};
			box.critical(0, "Yes", "It was a yes!!");
		}
	}
}

void try2::closeTask()
{
	int current = getIndex();
	try {
		if (repo.getTasks()[current].getStatus() != "in progress")
			throw CustomException{ "Task not in progress atm!" };
		if (repo.getTasks()[current].getId() != this->p.getId())
			throw std::exception("Task programmer not him!");
		repo.getTasks()[current].setClosed();
		this->repo.notify();
	}
	catch(CustomException& c)
	{ 
		QMessageBox box{};
		box.critical(0, "Custom Exception lawl", c.what());
	}
	catch(std::exception& e)
	{ 
		QMessageBox box{};
		box.critical(0, "Titlu", e.what());
	}
	
}
