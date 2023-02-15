/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Test_basic.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Utils.hpp"

void redirect_all_stdout(void);

Test(utils_tests, test_1, .init=redirect_all_stdout)
{
    cr_assert_str_eq(Utils::addStrings("0", "-1").c_str(), "-1");
}

Test(utils_tests, test_2, .init=redirect_all_stdout)
{
    cr_assert_str_eq(Utils::addStrings("-1", "0").c_str(), "-1");
}

Test(utils_tests, test_3, .init=redirect_all_stdout)
{
    cr_assert_str_eq(Utils::addStrings("-1", "-1").c_str(), "-2");
}

Test(utils_tests, test_4, .init=redirect_all_stdout)
{
    cr_assert_str_eq(Utils::subStrings("-1", "1").c_str(), "-2");
}

Test(utils_tests, test_5, .init=redirect_all_stdout)
{
    cr_assert_str_eq(Utils::subStrings("-0", "0").c_str(), "0");
}