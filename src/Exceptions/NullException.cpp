/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** NullException.cpp
*/

#include "Exceptions/NullException.hpp"

NullException::NullException(char const *message) : NullException(std::string(message)) {}

NullException::NullException(std::string const &message) : BaseException{ "Null Error: " + message } {}