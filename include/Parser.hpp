/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Parser.hpp
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
#include <string>

#include "IOperand.hpp"
#include "Factory.hpp"

#include "Exceptions/ParseException.hpp"

using namespace std;

class Parser {
    public:
        static vector<pair<string, IOperand *>> ParseAsm(string);

    private:
        static vector<pair<string, IOperand *>> ParseInput();
        static const string LineParse;
    

};