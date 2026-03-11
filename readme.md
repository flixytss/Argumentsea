# Argumentsea

This is a library for parsing your program arguments more easily

## Usage

``` cpp
#include <argumentsea.hpp>
#include <iostream>

int main(int argc, char** argv) {
    ArgumentsManager manager(argv, argc, 1);

    manager.add("help", [](ArgumentsManager* manager){
        std::cout << "help section" << std::endl;
        std::cout << "this is the argument " << manager->get_index() << std::endl;
    });
    manager.set_catcher([](ArgumentsManager* manager){
        std::cout << "error section" << std::endl;
        std::cout << "this is the argument " << manager->get_index() << std::endl;
    });

    manager.run();

    return 0;
}
```

This is base code of argumentsea. For the first step you have to declare a variable with the type `ArgumentsManager`, That will handle everything.  
The manager's constructor is
``` cpp
ArgumentsManager(char** Arguments, int Size, int start = 0)
```
The first argument is the argv variable and the second argument is the argc variable, And, The last argument is where the manager will start getting the arguments from argv (This is util when you don't want to include the program name or path).  
The manager has the following functions members:
``` cpp
void run();
void add(const std::string arg, std::function<void(ArgumentsManager* manager)>);
void delete_arg(int index);
void set_catcher(void (*catcher)(ArgumentsManager* manager));
const std::string get(int index);
const int get_index();
void block_next_arguments(const std::string argument, int amount);
const std::vector<std::string> get_blocked_arguments();
const std::string get_argument(int index);
```
The run function is the final thing to run when you are using ArgumentsManager.  
The add function, Add an argument to look for in the arguments that you passed in the constructor, If the argument is in, It will call the callback (The second argument).  
The delete_arg deletes an argument that you did set with add.  
The set_catcher set a fallback if a arguments dosen't match with the all the arguments that you setted. 
The get returns you an argument from the list that you passed to the constructor.  
The get_index gives you the actual index in use. This is util when you are adding a argument, using it in the callback.  
The block_next_arguments block the fallback (catcher) to execute for an argument that you setted with add, `block_next_arguments("add", 1);`  
The get_blocked_arguments gives you the blocked arguments. This is util when you needs argument next to your setted argument without the callback get executed.  
The get_argument gives you an argument that is in the arguments that you setted in base of the first argument.