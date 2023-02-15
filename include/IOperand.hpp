/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** IOperand.hpp
*/

#pragma once

#include <iostream>

using namespace std;

typedef enum eOperandType
{
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
    UNKNOWN,
} eOperandType;

class IOperand
{
    public:
        virtual string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual double getNumericLimit() const = 0;
        virtual int getPrecision() const = 0;
        virtual IOperand * operator+( const IOperand &rhs ) const = 0;
        virtual IOperand * operator-( const IOperand &rhs ) const = 0;
        virtual IOperand * operator*( const IOperand &rhs ) const = 0;
        virtual IOperand * operator/( const IOperand &rhs ) const = 0;
        virtual IOperand * operator%( const IOperand &rhs ) const = 0;
        virtual bool operator==( const IOperand &rhs ) const = 0;
        virtual bool operator!=( const IOperand &rhs ) const = 0;
        virtual ~IOperand() = default;
};