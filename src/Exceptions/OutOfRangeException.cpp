/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** MathException.cpp
*/

#include "Exceptions/OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(char const *message) : OutOfRangeException(std::string(message)) {}

OutOfRangeException::OutOfRangeException(std::string const &message) : BaseException{ "OutOfRange Error: " + message } {}