/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** BaseException.cpp
*/

#include "Exceptions/BaseException.hpp"

BaseException::BaseException(char const *message) : _message(message)
{}

BaseException::BaseException(std::string const &message) : _message(message)
{}

char const *BaseException::what() const noexcept
{
	return _message.c_str();
}