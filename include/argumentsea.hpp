#pragma once

#include <cstddef>
#include <functional>
#include <string>
#include <tuple>
#include <vector>

class ArgumentsManager;
struct argument {
    std::string argument;
    std::function<void(ArgumentsManager* manager)> function;
    std::vector<std::string> owned_args;
};

class ArgumentsManager {
    std::vector<struct argument> arguments;
    std::function<void(ArgumentsManager* manager)> default_catcher = NULL;

    std::vector<std::tuple<std::string, bool>> passed_arguments;
    std::vector<std::tuple<std::string, int, int>> BlockedArguments;
    int passed_size = 0;
    int start = 0;
    int argument = 0;

    int blocking_remaining = 0;
    struct argument* current_block = nullptr;
    std::vector<struct argument*> argumentstodelete;

    public:
        ArgumentsManager();
        ArgumentsManager(char** Arguments, int Size, int start = 0);
        ~ArgumentsManager() { for ( struct argument* ptr : this->argumentstodelete ) delete ptr; }

        void run();
        void add(const std::string arg, std::function<void(ArgumentsManager* manager)>);
        void delete_arg(int index);
        void set_catcher(void (*catcher)(ArgumentsManager* manager)) {this->default_catcher = catcher;}
        const std::string get(int index);
        const int get_index();
        void block_next_arguments(const std::string argument, int amount);
        const std::vector<std::string> get_blocked_arguments() {
            if (this->current_block) return current_block->owned_args;
            return {};
        };
        const std::string get_argument(int index) {
            --index;
            if ( !this->passed_arguments.size() || index > this->passed_arguments.size() || index < 0 ) { return "N/A"; }
            return std::get<0>(this->passed_arguments.at(index));
        }
};