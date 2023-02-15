/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** AssertException.cpp
*/

#include "Exceptions/InvalidTypeException.hpp"

InvalidTypeException::InvalidTypeException(char const *message) : InvalidTypeException(std::string(message)) {}

InvalidTypeException::InvalidTypeException(std::string const &message) : BaseException{ "Invalid type Error: " + message } {}