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