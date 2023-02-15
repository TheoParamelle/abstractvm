/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Utils.hpp
*/

#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>

#include "Exceptions/MathException.hpp"

class Utils {
    public:
        static std::string addStrings(std::string const &, std::string const &);
        static std::string subStrings(std::string, std::string);
        static std::string MulString(std:: string nb1, std::string nb2);
        static std::string DivString(std::string s1, std::string s2);
        static std::string ModString(std::string s1, std::string s2);

        static void Sanitize(std::string &str);

    private:
        static std::string addNbr(std::string, std::string);
        static void execCalcul(int nb1, int nb2, int *calcul, int *retain);
        static std::string subComplexNbs(std::string nb1, std::string nb2);
        static std::string execSubCalcul(std::string const &nb1, std::string const &nb2);
        static void formatComplex(std::string &nb1, std::string &nb2);
        static std::string execMulCalcul(std::string const &s1, std::string const &s2);
        static std::pair<std::string, std::string> doDivision(std::string const &s1, std::string const &s2, bool euclidean = false);
        static int is_bigger(std::string const &a, std::string const &b);
        
};