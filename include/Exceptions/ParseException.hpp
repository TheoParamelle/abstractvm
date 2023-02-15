/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** ParseException.hpp
*/


#pragma once

#include <string>

#include "BaseException.hpp"

class ParseException : public BaseException
{
    public:
        ParseException(char const *message);
        ParseException(std::string const &message);
};