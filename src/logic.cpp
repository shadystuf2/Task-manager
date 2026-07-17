#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>

using namespace std;
using json = nlohmann::json;

const string TASKS = "tasks.json";


// FILE FUNCTIONS
json loadTasks(){
    ifstream file(TASKS);
    
    if (!file.is_open()){
        cout << "No tasks file found, so I created a new one!\n";
        ofstream newFile(TASKS);
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

    ofstream file(TASKS);
    file << tasks.dump(4); // .dump converts JSON object (compatible with cpp, not json file) to string
    file.close();

}


// LOGIC FUNCTIONS
void addTask(json& tasks) {
    string title, description, due_date, status;

    cout << "Enter task title: \n";
    getline(cin, title);

    cout << "Enter task description: \n";
    getline(cin, description);

    cout << "Enter task due date (YYYY-MM-DD): \n";
    getline(cin, due_date);
    
    status = "Incomplete";


    json task = {
        {"status", status},
        {"due_date", due_date},
        {"description", description}, 
        {"title", title}
    };

    tasks.push_back(task); // .push_back adds element to end of json file
    saveTasks(tasks);
    cout << "Task " << task["title"] << " successfully added!\n";
    
}


void viewTasks(const json& tasks) {
    
    cout << "Your tasks are: \n";
    for (const auto& task : tasks){
        cout << "* " << task["title"] << " | " << task["description"] << " | " << task["due_date"] << " | " << task["status"] << "\n";
    
    }
    
}


void clearTasks(json& tasks) {
    
    tasks.clear();
    saveTasks(tasks);
    cout << "All tasks cleared!\n";

}

void updateTasks(json& tasks){
    
    cout << "What do you want to update?\n\n";
    cout << "1. Update task title\n";
    cout << "2. Update task description\n";
    cout << "3. Update task due date\n";
    cout << "4. Update task status\n";
    string updateChoice, key;
    getline(cin, updateChoice);

    if (updateChoice == "1"){
        key = "title";
    }
    else if (updateChoice == "2"){
        key = "description";
    }
    else if (updateChoice == "3"){
        key = "due_date";
    }
    else if (updateChoice == "4"){
        key = "status";
    }
    else {
        cout << "Invalid choice, returning to main menu...\n";
        return;
    }

    cout << "Enter the title of the task you want to update: \n";
    string name;
    getline(cin, name);

    for (auto& task : tasks) {
        if (task["title"] == name) {
            cout << "Enter the new " << key << " for the task: \n";
            string newName;
            getline(cin, newName);
            task[key] = newName;
            cout << "Task " << name << " was updated to " << newName << "\n";
            break;
        }
    }
    saveTasks(tasks);
}


// MAINNNNN
int main() 
{
    json tasks = loadTasks();
    
    cout<<"TASK MANAGER\n\n";
    cout<<"1. Add a task\n";
    cout<<"2. List tasks\n";
    cout<<"3. Update a task\n";
    cout<<"4. Clear tasks\n";
    cout<<"5. Delete task\n";
    cout<<"6. Quit :(\n\n";

    while (true) {
        cout<<"Pick ONE! (1-5):\n";
        int choice{};
        cin>> choice;
        cout<<"\n";
        cin.ignore();
        if (choice == 1) {
        addTask(tasks);
    }
    else if (choice == 2) {
        viewTasks(tasks);
    }
    else if (choice == 3) {
        updateTasks(tasks);
    }
    else if (choice == 4) {
        clearTasks(tasks);
    }
    else if (choice == 6) {
        cout << "ok, bye...\n";
        return 0;
    }
    else {
        cout<<"Invalid choice, bye\n";
        return 0;
    }

    }
}
