/*
** EPITECH PROJECT, 2022
** Project
** File description:
** main.cpp
*/

#include "Parser.hpp"
#include "Core.hpp"

int main (int argc, char **argv)
{
    bool exit = false;

    try {
        exit = Core::compile(Parser::ParseAsm((argc == 2) ? argv[1] : ""));

        if (!exit)
            throw BaseException("Syntax Error: no exit method provided, exited with error code");

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;

        while (!Core::_stack.empty()) {
            IOperand const *stack_one = Core::_stack.top();
            Core::_stack.pop();
            delete(stack_one);
        }
		return 84;
    }
    return 0;
}