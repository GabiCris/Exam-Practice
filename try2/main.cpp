#include "try2.h"
#include <QtWidgets/QApplication>
#include "Utils.h"
#include <fstream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::ifstream programmerf("programmers.txt");
	std::fstream taskf("tasks.txt");

	std::string line;
	std::vector<std::string> res;
	std::vector<Programmer> programmers;
	while (getline(programmerf, line))
	{
		res = tokenize(line, ';');
		programmers.push_back(Programmer{ res[0], stoi(res[1]) });
	}
	TaskRepository repo{"tasks.txt"};
	while (getline(taskf, line))
	{
		res = tokenize(line, ';');
		repo.addTask(Task{ res[0],res[1], stoi(res[2]) });
	}

	for (auto p : programmers)
	{
		try2* w = new try2{ p, repo };
		w->show();
	}
	//try2 w{ programmers[0], repo };
	//w.show();



	return a.exec();
}
