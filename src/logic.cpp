#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

const std::string TASKS = "tasks.json";

json loadTasks(){
    std::ifstream file(TASKS);
    
    if (!file.is_open()){
        std::cout<<"Could not open file :(\n";
        return json::array();
    }

    json tasks;
    file >> tasks;

    file.close();
    
    return tasks;
}


// MAINNNNN
int main()
{
    std::cout<<"hey, Hey, HEY! WELCOME to the task manager!\n";
    std::cout<<"1. Add a task\n";
    std::cout<<"2. List tasks\n";
    std::cout<<"3. Update a task\n";
    std::cout<<"4. Delete a task\n";
    std::cout<<"5. Quit :(\n";

    std::cout<<"Pick ONE! (1-5):\n";
    int choice{};
    std::cin>> choice;

    std::cout<<"You selected option: "<< choice << std::endl;
    return 0;
}