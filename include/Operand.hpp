/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Operand.hpp
*/

#pragma once

#include <stdexcept>
#include <limits>
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Exceptions/MathException.hpp"
#include "Utils.hpp"

template <typename T>
class Operand : public IOperand
{
    public:
        Operand(eOperandType type, const std::string &value, int = 0);
        ~Operand();

        std::string toString() const;
        double getNumericLimit() const;
        int getPrecision() const;
        eOperandType getType() const;

        IOperand *operator+(const IOperand &target) const;
        IOperand *operator-(const IOperand &target) const;
        IOperand *operator*(const IOperand &target) const;
        IOperand *operator/(const IOperand &target) const;
        IOperand *operator%(const IOperand &target) const;

        bool operator==(const IOperand &target) const;
        bool operator!=(const IOperand &target) const;

    protected:
        std::string value;
        eOperandType type;
        int _precision;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;