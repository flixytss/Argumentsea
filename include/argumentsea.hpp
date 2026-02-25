#pragma once

#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

class ArgumentsManager;
struct argument {
    std::string argument;
    void (*function)(ArgumentsManager* manager);
};

class ArgumentsManager {
    std::vector<struct argument> arguments;
    void (*default_catcher)(ArgumentsManager* manager) = NULL;

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
        void set_catcher(void (*catcher)(ArgumentsManager* manager)) {this->default_catcher = catcher;}
        std::string get(int index) const;
        const int get_index();
        const std::string get_argument(int index) {
            --index;
            if ( !this->passed_arguments.size() || index > this->passed_arguments.size() || index < 0 ) { return "N/A"; }
            return this->passed_arguments.at(index);
        }
};