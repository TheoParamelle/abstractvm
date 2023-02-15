/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** AssertException.cpp
*/

#include "Exceptions/AssertException.hpp"

AssertException::AssertException(char const *message) : AssertException(std::string(message)) {}

AssertException::AssertException(std::string const &message) : BaseException{ "Assert Error: " + message } {}