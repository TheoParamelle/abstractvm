/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** BaseException.hpp
*/

#pragma once

#include <exception>
#include <string>

class BaseException : public std::exception
{
    public:
        BaseException() = default;
        explicit BaseException(char const *);
        explicit BaseException(std::string const &message);

        char const *what() const noexcept;

    private:
        std::string _message;
};