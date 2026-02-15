#pragma once

#include <cstddef>
#include <string>
#include <vector>

struct argument {
    std::string argument;
    void (*function)(const size_t index);
};

class ArgumentsManager {
    std::vector<struct argument> arguments;
    void (*default_catcher)(const std::string Argument) = NULL;

    std::vector<std::string> passed_arguments;
    int passed_size = 0;
    int start = 0;

    public:
        ArgumentsManager();
        ArgumentsManager(char** Arguments, int Size, int start = 0);

        void run();
        void add(const std::string arg, void(*functiontorun)(const size_t index));
        void delete_arg(size_t index);
        void set_catcher(void (*catcher)(const std::string Argument)) {this->default_catcher = catcher;}
        std::string get(size_t index) const;
};