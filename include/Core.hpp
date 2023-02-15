/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Core.hpp
*/

#pragma once
using namespace std;

#include <vector>
#include <string>
#include "IOperand.hpp"
#include <map>
#include <stack>
#include "Factory.hpp"
#include <sstream>

#include "Exceptions/OutOfRangeException.hpp"
#include "Exceptions/NullException.hpp"
#include "Exceptions/AssertException.hpp"
#include "Exceptions/InvalidTypeException.hpp"


class Core {
    public:
        static bool compile(vector<pair<string, IOperand *>>);
        static void executeInstruction(string, IOperand *);

        static map<string, void (*)(IOperand const*)> Functions;
        static map<string, void (*)(void)> VoidFunctions;
        static std::stack<IOperand const *> _stack;
        static std::map<int, IOperand const *> _registers;

    private:
        static void add();
        static void push(IOperand const *);
        static void pop();
        static void mul();
        static void dump();
        static void assert(IOperand const *);
        static void print();
        static void sub();
        static void mod();
        static void div();
        static void load(IOperand const *);
        static void store(IOperand const *);
        static void clear();
        static void dup();
        static void swap();
};