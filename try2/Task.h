#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Observer.h"

class Task {
private:
	std::string description;
	std::string status;
	std::string programmer;
	int id;
public:
	Task(const std::string& d, const std::string& s, const int& i) : description(d), status(s), id(i) { this->programmer = ""; }
	std::string getDescription() { return this->description; }
	std::string getStatus() { return this->status; }
	std::string getTask() {
		std::string temp = this->description + "; " + this->getStatus();
		return temp;
	}
	std::string getProgrammer() { return programmer; }
	int getId() { return this->id; }
	bool operator <(Task t) { 
		if (this->status < t.getStatus()) return true; 
		if (t.getStatus() < status) return false;

		if (this->description < t.description) return true;
		if (t.description < this->description) return false;
	}
	void setInprogress() { 
		this->status = "in progress"; 
	}
	void setClosed() {
		this->status = "closed";
	}
	void setProgrammer(std::string p) { this->programmer = p; }
};


class TaskRepository: public Subject {
private:
	std::vector<Task> taskList;
	std::string fileName;
public:
	TaskRepository(std::string fileName) : fileName(fileName) {}
	void addTask(const Task& t) { this->taskList.push_back(t); this->notify(); }
	void removeTask(const std::string & t) {
		int i;
		for (i = 0; i < taskList.size(); i++)
			if (taskList[i].getDescription() == t)
				break;
		this->taskList.erase(taskList.begin() + i);
		this->notify();
	}
	std::vector<Task> getTasksSorted() {
		std::sort(taskList.begin(), taskList.end());
		return taskList;
	}
	std::vector<Task>& getTasks() { return this->taskList; }

	~TaskRepository() { 
		std::fstream f("tasks.txt");
		for(auto t: this->taskList)
			f << t.getDescription() << ";" << t.getStatus() << ";" << t.getId() << "\n";
		f.close();
	}
};