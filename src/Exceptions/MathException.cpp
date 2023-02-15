/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** MathException.cpp
*/

#include "Exceptions/MathException.hpp"

MathException::MathException(char const *message) : MathException(std::string(message)) {}

MathException::MathException(std::string const &message) : BaseException{ "Math Error: " + message } {}