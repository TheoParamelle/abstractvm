/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** IOperand.hpp
*/

#pragma once

#include <iostream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include <array>

class Factory
{
    public:
        static IOperand *createOperand(eOperandType type, const std::string &value);
        static IOperand *createOperand(const string type, const string &value);
        static IOperand *createOperand(IOperand const *);

    private:
        static IOperand *createInt8(const std::string &);
        static IOperand *createInt16(const std::string &);
        static IOperand *createInt32(const std::string &);
        static IOperand *createFloat(const std::string &);
        static IOperand *createDouble(const std::string &);
        static IOperand *createBigDecimal(const std::string &);

       static std::array<IOperand * (*) (const std::string &), 6> operands;
       static std::array<std::string, 6> toperands;
};