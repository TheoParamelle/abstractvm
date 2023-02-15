/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Test_basic.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Core.hpp"

int main_test(std::string text, std::string id);
void redirect_all_stdout(void);

Test(register_tests, Store, .init=redirect_all_stdout)
{
std::string text = "push int8(14)\nstore int8(0)\nexit";

cr_assert_eq(main_test(text, "register_Store"), 0);
}

Test(register_tests, Store_2, .init=redirect_all_stdout)
{
std::string text = "push int8(14)\nstore int8(10)\nexit";

cr_assert_eq(main_test(text, "register_Store_2"), 0);
}

Test(register_tests, Load, .init=redirect_all_stdout)
{
std::string text = "push int8(14)\nstore int8(0)\nload int8(0)\nexit";

cr_assert_eq(main_test(text, "register_Load"), 0);
}
