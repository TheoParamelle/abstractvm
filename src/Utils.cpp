/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Utils.cpp
*/

#include "Utils.hpp"

std::string Utils::addStrings(std::string const &one, std::string const &two)
{
    std::string result = "";

    if (one[0] == '-' && two[0] != '-')
        result = subStrings(two, &one[1]);
    else if (one[0] != '-' && two[0] == '-')
        result = subStrings(one, &two[1]);
    if (one[0] == '-' && two[0] == '-') {
        result = addNbr(&one[1], &two[1]);
        result.insert(0, "-");
    } else if (one[0] != '-' && two[0] != '-')
        result = addNbr(one, two);
    return (result);
}

std::string Utils::subStrings(std::string one, std::string two)
{
    std::string result = "";

    if (two[0] != '-')
        two.insert(0, "-");
    else
        two = &two[1];
    if (one[0] == '-' && two[0] == '-') {
        result = addStrings(&one[1], &two[1]);
        result.insert(0, "-");
    } else 
        result = (one[0] != '-' && two[0] != '-') ? addStrings(one, two) : subComplexNbs(one, two);
    if (result == "-0")
        result = &result[1];
    return (result);
}

void Utils::formatComplex(std::string &nb1, std::string &nb2)
{
    std::pair<std::string, std::string> integer;
    std::pair<std::string, std::string> floating = { "", "" };
    int diff;
    integer.first = nb1.substr(0, nb1.find("."));
    integer.second = nb2.substr(0, nb2.find("."));

    if (nb1.find(".") != std::string::npos)
        floating.first = nb1.substr(nb1.find(".") + 1);
    if (nb2.find(".") != std::string::npos)
        floating.second = nb2.substr(nb2.find(".") + 1);


    diff = integer.second.length() - integer.first.length();

    if (diff > 0)
        integer.first.insert(0, diff, '0');
    else if (diff < 0)
        integer.second.insert(0, -diff, '0');
    
    diff = floating.second.length() - floating.first.length();

    if (diff > 0)
        floating.first.append(diff, '0');
    else if (diff < 0)
        floating.second.append(-diff, '0');
    
    nb1 = integer.first;
    nb2 = integer.second;

    if (floating.first.length()) {
        nb1 += "." + floating.first;
        nb2 += "." + floating.second;
    }
}

void Utils::Sanitize(std::string &string)
{
    if (string.find(".") != std::string::npos)
		while (string.back() == '0')
			string.pop_back();
	if (string.back() == '.')
		string.pop_back();
    
    while (string[0] == '0')
		string.erase(0,1);

    if (string[0] == '.')
		string.insert(0, 1, '0');
}

std::string Utils::addNbr(std::string nb1, std::string nb2)
{
    std::string result = "";
    int retain = 99;
    int calcul;

    formatComplex(nb1, nb2);

    for (int i = nb1.length() - 1; i >= 0; i--) {
        if (nb1[i] == '.') {
            i--;
            result.insert(0, ".");
        }
        execCalcul(nb1[i] - '0', nb2[i] - '0', &calcul, &retain);
        result.insert(0, std::to_string(calcul));
    }
    if (retain != 99) {
        result.insert(0, std::to_string(retain));
    }
    return (result);
}

void Utils::execCalcul(int nb1, int nb2, int *calcul, int *retain)
{
    *calcul = nb1 + nb2;

    if (*retain != 99) {
        *calcul = *calcul + *retain;
        *retain = 99;
    }
    if (*calcul >= 10) {
        *retain = *calcul / 10;
        *calcul = *calcul % 10;
    }
}

std::string Utils::subComplexNbs(std::string nb1, std::string nb2)
{
    std::string result = "";
    bool negative = false;
    bool nb1_neg = (nb1[0] == '-');
    int zero;

    if (nb1[0] == '-')
        nb1.erase(0,1);
    if (nb2[0] == '-')
        nb2.erase(0,1);

    formatComplex(nb1,nb2);

    if (std::strcmp(nb2.c_str(), nb1.c_str()) > 0) {
        std::string swap = nb1;
        nb1 = nb2;
        nb2 = swap;
        negative = (!nb1_neg);
    } else
        negative = (nb1_neg);
    
    result = execSubCalcul(nb1, nb2);

    for (zero = 0; result[zero] == '0' && result[zero + 1] ;++zero);
    result = result.substr(zero, result.length() - zero);
    if (result != "0" && negative)
        result.insert(0, "-");
    return (result);
}

std::string Utils::execSubCalcul(std::string const &nb1, std::string const &nb2)
{
    std::string result = "";
    int n1;
    int n2;
    bool retain = false;

    for (int i = nb1.length() - 1; i >= 0; i--) {

        if (nb1[i] == '.') {
            i--;
            result.insert(0, ".");
        }
        n1 = nb1[i] - '0';
        n2 = nb2[i] - '0';

        if (retain) {
            n1 -= 1;
            retain = false;
        }
        if (n1 < n2) {
            n1 = n1 + 10;
            retain = true;
        }

        result.insert(0, std::to_string(n1 - n2));
    }
    return (result);
}

std::string Utils::execMulCalcul(std::string const &s1, std::string const &s2)
{
    std::string end;
    std::stack<std::string> results;
    std::string finalRes = "0";

    for (int i = s2.length() - 1; i >= 0; i--) {
        std::string result = "";
        int remainder = 0;

        result.append(s2.length() - 1 - i, '0');

        for (int j = s1.length() - 1; j >= 0; j--) {
            int nbr = ((s1[j] - '0') * (s2[i] - '0') + remainder);
            result.insert(0, std::to_string(nbr % 10));
            remainder = nbr / 10;
        }

        result.insert(0, std::to_string(remainder));
        results.push(result);
        
    }

    while (!results.empty()) {
        finalRes = Utils::addStrings(finalRes, results.top());
        results.pop();
    }

    return finalRes;
}

std::string Utils::MulString(std::string nb1, std::string nb2)
{
    std::string result;
    bool neg = ((nb1[0] == '-') ^ (nb2[0] == '-'));
    int virgule = 0;

    if (nb1[0] == '-')
        nb1.erase(0,1);
    if (nb2[0] == '-')
        nb2.erase(0,1);
    
    if (nb1.find(".") != std::string::npos) {
        virgule += nb1.length() - nb1.find(".") - 1;
    }
    if (nb2.find(".") != std::string::npos) {
        virgule += nb2.length() - nb2.find(".") - 1;
    }

    nb1.erase(std::remove(nb1.begin(), nb1.end(), '.'), nb1.end());
    nb2.erase(std::remove(nb2.begin(), nb2.end(), '.'), nb2.end());
    
    result = execMulCalcul(nb1, nb2);
    
    if (virgule)
        result.insert((result.end() - virgule), '.');
    
    Sanitize(result);
    
    if (neg)
        result.insert(0, "-");
    
    return result;
}

int Utils::is_bigger(std::string const &a, std::string const &b)
{
    int size1 = a.length();
    int size2 = b.length();

    for (int i = 0; a[i] == '0'; i++, size1--);
    for (int i = 0; b[i] == '0'; i++, size2--);
    
    if (size1 > size2)
        return 1;
    else if (size1 < size2)
        return 0;
    
    for (int i = 0; i < size1; i++) {
        if (a[a.length() - size1 + i] < b[b.length() - size2 + i])
            return 0;
        if (a[a.length() - size1 + i] > b[b.length() - size2 + i])
            return 1;
    }
    return 2;
}

std::pair<std::string, std::string> Utils::doDivision(std::string const &s1, std::string const &s2, bool euclidean)
{
    std::string result;
    std::string remainder = "0";
    int attempt = 200;


    for (uint i = 0; i < s1.length() || (remainder != "0" && !euclidean); i++) {
        if (attempt <= 0)
            break;
        
        if (i == s1.length())
            result += ".";
        if (i >= s1.length()) {
            remainder += "0";
            attempt--;
        } else
            remainder += s1[i];
        int retain = 0;
        while (is_bigger(remainder, s2)) {
            remainder = Utils::subStrings(remainder, s2);
            retain++;
        }
        result += std::to_string(retain);
    }

    return { result, remainder };
}

std::string Utils::DivString(std::string s1, std::string s2)
{
    std::string result;
    bool neg = ((s1[0] == '-') ^ (s2[0] == '-'));
    int virgule = 0;

    if (s1[0] == '-')
        s1.erase(0,1);
    if (s2[0] == '-')
        s2.erase(0,1);

    if (s2.find(".") != std::string::npos) {
        virgule -= (s2.length() - s2.find(".") - 1);
    }
    if (s1.find(".") != std::string::npos) {
        virgule += s1.length() - s1.find(".") - 1;
    }

    s1.erase(std::remove(s1.begin(), s1.end(), '.'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '.'), s2.end());

    if (virgule < 0)
        s1.insert(s1.end(), -virgule, '0');
    
    result = doDivision(s1, s2).first;

    if (virgule > 0) {
        auto pos = result.find(".");
        if (pos != std::string::npos) {
            result.erase(pos, 1);
            result.insert(pos - virgule, 1, '.');
        } else
            result.insert((result.end() - virgule), '.');
    }

    Sanitize(result);
    
    if (neg)
        result.insert(0, "-");
    
    return result;
}

std::string Utils::ModString(std::string s1, std::string s2)
{
    std::string result;

    bool neg = ((s1[0] == '-') ^ (s2[0] == '-'));

    if (s1[0] == '-')
        s1.erase(0,1);
    if (s2[0] == '-')
        s2.erase(0,1);
    
    result = doDivision(s1, s2, true).second;
    Sanitize(result);
    
    if (neg)
        result.insert(0, "-");
    
    return result;
}