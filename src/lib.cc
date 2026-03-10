#include "argumentsea.hpp"
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

void ArgumentsManager::add(const std::string arg, std::function<void(ArgumentsManager* manager)> functiontorun) {
    this->arguments.push_back({arg, functiontorun});
}
ArgumentsManager::ArgumentsManager(char** Arguments, int Size, int start) {
    if (!Arguments) throw std::runtime_error("ArgumentsManager: ArgumentsManager(char** Arguments, int Size): invalid arguments");
    this->start = start;
    this->passed_size = Size;
    for (int i = this->start; i < this->passed_size; i++) this->passed_arguments.push_back(std::make_tuple(Arguments[i], false));
}
const std::string ArgumentsManager::get(int index) {
    if (--index > this->arguments.size()) throw std::runtime_error("ArgumentsManager: get(int index): size < index");
    return this->arguments.at(index).argument;
}
void ArgumentsManager::delete_arg(int index) {
    if (index > this->arguments.size()) throw std::runtime_error("ArgumentsManager: delete_arg(int index): size < index");
    this->arguments.erase(this->arguments.begin() + index);
}
const int ArgumentsManager::get_index() { return this->argument; }
void ArgumentsManager::block_next_arguments(const std::string argument, int amount) { this->BlockedArguments.push_back(std::make_tuple(argument, amount, this->BlockedArguments.size())); }
void ArgumentsManager::run() {
    int blocking_remaining = 0;

    for (const auto& tuple : this->passed_arguments) {
        const std::string passed = std::get<0>(tuple);
        this->argument++;

        if (blocking_remaining > 0 && current_block) {
            current_block->owned_args.push_back(passed);
            blocking_remaining--;

            if (blocking_remaining == 0) {
                current_block->function(this);
                current_block = nullptr;
            } continue;
        }

        bool found = false;
        for (auto& arg : this->arguments) {
            struct argument* argcopy = new struct argument(arg);
            this->argumentstodelete.push_back(argcopy);
            if (passed == arg.argument) {
                for (auto& blocked : this->BlockedArguments) {
                    if (std::get<0>(blocked) == passed) {
                        blocking_remaining = std::get<1>(blocked);
                        current_block = argcopy;
                        found = true;
                        break;
                    }
                }
                if (!found) arg.function(this);
                found = true;
                break;
            }
        }

        if (!found && this->default_catcher)
            this->default_catcher(this);
    }
}