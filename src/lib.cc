#include "argumentsea.hpp"
#include <stdexcept>
#include <string>
#include <vector>

void ArgumentsManager::add(const std::string arg, void(*functiontorun)(ArgumentsManager* manager)) {
    this->arguments.push_back({(char*)arg.c_str(), functiontorun});
}
ArgumentsManager::ArgumentsManager(char** Arguments, int Size, int start) {
    if (!Arguments) throw std::runtime_error("ArgumentsManager: ArgumentsManager(char** Arguments, int Size): invalid arguments");
    this->start = start;
    this->passed_size = Size;
    for (int i = this->start; i < this->passed_size; i++) this->passed_arguments.push_back(Arguments[i]);
}
std::string ArgumentsManager::get(int index) const {
    if (index > this->arguments.size()) throw std::runtime_error("ArgumentsManager: get(int index): size < index");
    return this->arguments[index].argument;
}
void ArgumentsManager::delete_arg(int index) {
    if (index > this->arguments.size()) throw std::runtime_error("ArgumentsManager: delete_arg(int index): size < index");
    this->arguments.erase(this->arguments.begin() + index);
}
const int ArgumentsManager::get_index() { return this->argument; }
void ArgumentsManager::run() {
    for (const std::string& passed : this->passed_arguments) {
        bool found = false;
        for (int i = 0; i < this->arguments.size(); ++i) {
            this->argument++;
            if (passed == this->arguments[i].argument) {
                this->arguments[i].function(this);
                found = true;
                break;
            }
        }

        if (!found) {
            if (this->default_catcher) this->default_catcher(this);
        }
    }
}