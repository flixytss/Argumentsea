#pragma once

#include <cstddef>
#include <string>
#include <vector>

class ArgumentsManager;
struct argument {
    std::string argument;
    void (*function)(ArgumentsManager* manager);
};

class ArgumentsManager {
    std::vector<struct argument> arguments;
    void (*default_catcher)(const std::string Argument) = NULL;

    std::vector<std::string> passed_arguments;
    int passed_size = 0;
    int start = 0;
    int argument = 0;

    public:
        ArgumentsManager();
        ArgumentsManager(char** Arguments, int Size, int start = 0);

        void run();
        void add(const std::string arg, void(*functiontorun)(ArgumentsManager* manager));
        void delete_arg(int index);
        void set_catcher(void (*catcher)(const std::string Argument)) {this->default_catcher = catcher;}
        std::string get(int index) const;
        const int get_index();
};