#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include "ShoppingList.h"
#include "ToDoList.h"
#include "Alarm.h"
#include "App.h"

std::ifstream fin;

int main() {

    App* a = App::getApp();
    a -> launch();
}
