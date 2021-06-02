//
// Created by seraf on 17.03.2021.
//

#include "ToDoList.h"

ToDoList::ToDoList(std::string name): name(name), tasks(), completed() {}
ToDoList::~ToDoList(){}
ToDoList::ToDoList(const ToDoList &A): name(A.name), tasks(A.tasks), completed(A.completed){}
std::ostream& operator<<(std::ostream& out, ToDoList& lista){
    out << lista.name << "\n";
    int n = lista.tasks.size();
    for(int i = 0; i < n; ++i){
        out << i+1 << ")" << lista.tasks[i].getMessage() << "\nDeadline: " << lista.tasks[i].getDate() << "\n";
    }
    return out;
}
void ToDoList::addTask(std::string message, DateTime time){
    tasks.push_back(Reminder(message, time));
    std::cout<< "Task added succesfully!" << "\n" ;
}
void ToDoList::removeTask(int i){
    Reminder R = tasks[i];
    tasks.erase(tasks.begin() + i);
    std::cout << "Removed task: " << R.getMessage() << "\n";
}
void ToDoList::nextTasks(DateTime time){
    int n = tasks.size();
    for(int i = 0; i < n; ++i){
        if( tasks[i].getDate() > time )
            std::cout << tasks[i];
    }
}
void ToDoList::missedTasks() {
    DateTime time;
    int n = tasks.size();
    for (int i = 0; i < n; ++i) {
        if (time > tasks[i].getDate())
            std::cout << "You missed a task!" << "\n" << tasks[i];
    }
}
void ToDoList::completedTask(int i){
    Reminder R = tasks[i-1];
    this->removeTask(i-1);
    completed.push_back(R);
    std::cout << "Completed task: " << R.getMessage() << "\n";
}
void ToDoList::printCompleted(std::ostream& os){
    os << "Completed tasks: " << "\n";
    int n = completed.size();
    for(int i = 0; i < n; ++i){
        os << completed[i].getMessage() << "\n";
    }
}