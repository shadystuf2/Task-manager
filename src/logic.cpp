#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

const std::string TASKS = "tasks.json";


// FILE FUNCTIONS
json loadTasks(){
    std::ifstream file(TASKS);
    
    if (!file.is_open()){
        cout << "No tasks file found, so I created a new one!\n";
        std::ofstream newFile(TASKS);
        newFile << "[]";
        newFile.close();
        return json::array();
    }

    json tasks;
    file >> tasks;
    file.close();
    
    return tasks;
}

void saveTasks(const json& tasks) {
    std::ofstream file(TASKS);
    file << tasks.dump(4); // .dump converts JSON object (compatible with cpp, not json file) to string
    file.close();
}


// LOGIC FUNCTIONS
void addTask(json& tasks) {
    int input_task;
    std::cin>>input_task;

    tasks.push_back(input_task);
    saveTasks(tasks);
    
}


void viewTasks() {
    
    ifstream file(TASKS);
    std::string s;

    getline(file, s);
    cout << "Your tasks are: " << s;
    
}

void clearTasks() {
    std::fstream file(TASKS, std::ios::trunc);
    file.close();
}

void updateTasks(){
    std::cout<<"Hi \n";
}


// MAINNNNN
int main()
{
    json tasks = loadTasks();
    
    std::cout<<"hey, Hey, HEY! WELCOME to the task manager!\n";
    std::cout<<"1. Add a task\n";
    std::cout<<"2. List tasks\n";
    std::cout<<"3. Update a task\n";
    std::cout<<"4. Clear tasks\n";
    std::cout<<"5. Quit :(\n";

    std::cout<<"Pick ONE! (1-5):\n";
    int choice{};
    std::cin>> choice;
    
    if (choice == 1) {
        addTask(tasks);
    }
    else if (choice == 2) {
        viewTasks();
    }
    else if (choice == 3) {
        updateTasks();
    }
    else if (choice == 4) {
        clearTasks();
    }
    else if (choice == 5) {
        std::cout << "ok, bye...";
        return 0;
    }
    else {
        std::cout<<"Invalid choice, uh oh... try again\n";
        std::cin>> choice;
    }

}
