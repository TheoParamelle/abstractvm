/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

const string Parser::LineParse = "(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)+\\s*((int8|int16|int32|float|double|bigdecimal)\\s*\\(+\\s*(-?\\d+.?\\d*\\s*)\\))?";

bool NeedParameter(string val)
{
    return (val == "push" || val == "assert" || val == "load" || val == "store");
}

vector<pair<string, IOperand *>> Parser::ParseAsm(string path)
{
    ifstream file;
    string line;
    regex lineReg(LineParse);
    regex commentReg("^\\s*;");
    smatch matches;
    vector<pair<string, IOperand *>> instructions;
    
    if (path.empty())
        return ParseInput();
    file.open(path.c_str());
    if (!file.is_open())
        throw ParseException("Could not open file " + path);
    do {
        getline(file, line, '\n');

        if (regex_search(line, commentReg) || line == "")
            continue;

        if (!regex_search(line, matches, lineReg))
            throw ParseException("Illegal instruction: " + line);
        else if  (NeedParameter(matches[1]) && matches[3].str() == "")
            throw ParseException("Instruction " + matches[1].str() + " need parameter");
        
        pair<string, IOperand *> instruction = make_pair(matches[1].str(), (IOperand *)NULL);

        if (matches[3].str() != "") {
            if ((matches[4].str().find('.') != std::string::npos) && ( matches[3].str() == "int8" || matches[3].str() == "int16" || matches[3].str() == "int32"))
                throw ParseException("Type " + matches[3].str() + "need an int parameter");
            instruction.second = Factory::createOperand(matches[3].str(), matches[4].str());
        }
        instructions.push_back(instruction);
    }
    while (file.good() && !file.eof());
    file.close();
    return instructions;
}

vector<pair<string, IOperand *>> Parser::ParseInput()
{
    std::string file = ".input.txt";
    std::ofstream out (file);
    vector<pair<string, IOperand *>> instructions;

    do {
        std::string line;
        std::getline(std::cin, line);
        if (line == ";;") {
            out.close();
            return ParseAsm(file);
        } else
            out << line << std::endl;
    } while (true);
    out.close();
    return instructions;
}
