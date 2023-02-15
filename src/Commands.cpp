/*
** EPITECH PROJECT, 2022
** Project
** File description:
** vm.cpp
*/

#include "Core.hpp"

void Core::push(IOperand const *op)
{
    _stack.push(op);
}

void Core::pop()
{
    if (_stack.empty())
        throw OutOfRangeException("stack vide");
    IOperand const *stack = _stack.top();
    _stack.pop();
    delete (stack);
}

void Core::clear()
{
    while (!_stack.empty()) {
        IOperand const *stack = _stack.top();
        _stack.pop();
        delete (stack);
    }
}

void Core::dup()
{
    if (_stack.empty())
        throw OutOfRangeException("stack vide");
    _stack.push(Factory::createOperand(_stack.top()));
}

void Core::swap()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(stack_one);
    _stack.push(stack_two);
}

void Core::dump()
{
    std::stack<IOperand const *> _mirror = _stack;

    while (!_mirror.empty()) {
        std::cout << _mirror.top()->toString() << std::endl;
        _mirror.pop();
    }
}

void Core::assert(IOperand const *op)
{
    if (_stack.empty())
        throw OutOfRangeException("stack vide");
    if (*_stack.top() != *op)
        throw AssertException("Assert failed");
}

void Core::add()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(Factory::createOperand( (*stack_one + *stack_two) ));
    delete (stack_one);
    delete (stack_two);
}

void Core::sub()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(Factory::createOperand( (*stack_two - *stack_one) ));
    delete (stack_one);
    delete (stack_two);
}

void Core::mul()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(Factory::createOperand( (*stack_one * *stack_two) ));
    delete (stack_one);
    delete (stack_two);
}

void Core::div()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(Factory::createOperand( (*stack_two / *stack_one) ));
    delete (stack_one);
    delete (stack_two);
}

void Core::mod()
{
    if (_stack.size() < 2)
        throw OutOfRangeException("stack inférieur à 2");

    IOperand const *stack_one = _stack.top();
    _stack.pop();
    IOperand const *stack_two = _stack.top();
    _stack.pop();

    _stack.push(Factory::createOperand( (*stack_two % *stack_one) ));
    delete (stack_one);
    delete (stack_two);
}

void Core::load(IOperand const *op)
{
    int64_t val;
    std::stringstream value(op->toString());
    value >> val;

    if (value.fail())
        throw BaseException("InvalidPointer Error: Please provide an integer");

    if (!_registers.count(val))
        throw NullException("registre vide");
    _stack.push(Factory::createOperand(_registers.at(val)));
}

void Core::store(IOperand const *op)
{
    int val;
    std::stringstream value(op->toString());
    value >> val;

    if (value.fail())
        throw BaseException("InvalidPointer Error: Please provide an integer");


    if (_stack.empty())
        throw OutOfRangeException("Stack vide");
    if (val > 15 || val < 0)
        throw OutOfRangeException("Registre non valide");
    _registers[val] = _stack.top();
    _stack.pop();
}

void Core::print()
{
    if (_stack.empty())
        throw OutOfRangeException("stack vide");

    IOperand const *stack_one = _stack.top();

    if (stack_one->getType() != INT8)
        throw InvalidTypeException("no INT8");
    std::cout << static_cast<char>(stoi(stack_one->toString())) << std::endl;
}