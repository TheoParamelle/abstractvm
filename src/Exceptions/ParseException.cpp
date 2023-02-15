/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** ParserException.cpp
*/

#include "Exceptions/ParseException.hpp"

ParseException::ParseException(char const *message) : ParseException(std::string(message)) {}

ParseException::ParseException(std::string const &message) : BaseException{ "Parse Error: " + message } {}