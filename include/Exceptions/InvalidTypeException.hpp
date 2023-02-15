/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** ParseException.hpp
*/


#pragma once

#include <string>

#include "BaseException.hpp"

class InvalidTypeException : public BaseException
{
    public:
        InvalidTypeException(char const *message);
        InvalidTypeException(std::string const &message);
};