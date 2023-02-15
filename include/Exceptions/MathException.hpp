/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** ParseException.hpp
*/


#pragma once

#include <string>

#include "BaseException.hpp"

class MathException : public BaseException
{
    public:
        MathException(char const *message);
        MathException(std::string const &message);
};