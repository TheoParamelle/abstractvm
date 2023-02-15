/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Core.cpp
*/

#include "Core.hpp"

std::map<std::string, void (*)(IOperand const*)> Core::Functions {
    {"push", Core::push},
    {"assert", Core::assert},
    {"load", Core::load},
    {"store", Core::store},
};

std::map<std::string, void (*)()> Core::VoidFunctions {
    {"add", Core::add},
    {"mul", Core::mul},
    {"dump", Core::dump},
    {"print", Core::print},
    {"sub", Core::sub},
    {"div", Core::div},
    {"clear", Core::clear},
    {"dup", Core::dup},
    {"swap", Core::swap},
    {"pop", Core::pop},
    {"mod", Core::mod}
};

std::stack<IOperand const *> Core::_stack = {};
std::map<int, IOperand const *> Core::_registers = {};

bool Core::compile(vector<pair<string, IOperand*>> instructions)
{
    for (auto const &instruction : instructions) {
        if (instruction.first == "exit")
            return true;
        executeInstruction(instruction.first, instruction.second);
    }
    return false;
}

void Core::executeInstruction(string instruction, IOperand *operand)
{
    if (VoidFunctions.count(instruction))
        (Core::VoidFunctions[instruction])();
    else if (Functions.count(instruction))
        (Core::Functions[instruction])(operand);
}