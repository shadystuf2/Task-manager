#include <iostream>

int main()
{
    std::cout<<"Welcome to the task manager!\n";
    std::cout<<"Please select an option:\n";
    std::cout<<"1. Add a task\n";
    std::cout<<"2. List tasks\n";
    std::cout<<"3. Update a task\n";
    std::cout<<"4. Delete a task\n";
    std::cout<<"5. Quit\n";

    std::cout<<"Enter your choice (1-5): \n";
    int choice{};
    std::cin>> choice;

    std::cout<<"You selected option: "<< choice << std::endl;
    return 0;
}