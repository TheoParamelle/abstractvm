/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** ParseException.hpp
*/


#pragma once

#include <string>

#include "BaseException.hpp"

class OutOfRangeException: public BaseException
{
    public:
        OutOfRangeException(char const *message);
        OutOfRangeException(std::string const &message);
};