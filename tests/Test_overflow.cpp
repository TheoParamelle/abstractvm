/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Test_parser.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Core.hpp"
#include "Parser.hpp"

int main_test(std::string, std::string);

void redirect_all_stdout(void);

Test(overflow, constructor)
{
    std::string text = "push int8(99999999)\nexit";

    cr_assert_eq(main_test(text, "overflow_constructor"), 84);
}

Test(undeflow, constructor)
{
    std::string text = "push int8(-99999999)\nexit";

    cr_assert_eq(main_test(text, "undeflow_constructor"), 84);
}

Test(overflow, operator_plus)
{
    std::string text = "push int8(100)\npush int8(100)\nadd\nexit";

    cr_assert_eq(main_test(text, "overflow_operator_plus"), 84);
}

Test(undeflow, operator_plus)
{
    std::string text = "push int8(-100)\npush int8(-100)\nadd\nexit";

    cr_assert_eq(main_test(text, "underflow_operator_plus"), 84);
}

Test(overflow, operator_minus)
{
    std::string text = "push int8(100)\npush int8(-100)\nsub\nexit";

    cr_assert_eq(main_test(text, "overflow_operator_minus"), 84);
}

Test(undeflow, operator_minus)
{
    std::string text = "push int8(-100)\npush int8(100)\nsub\nexit";

    cr_assert_eq(main_test(text, "underflow_operator_minus"), 84);
}

Test(overflow, operator_mult)
{
    std::string text = "push int8(100)\npush int8(100)\nmul\nexit";

    cr_assert_eq(main_test(text, "overflow_operator_mult"), 84);
}

Test(undeflow, operator_mult)
{
    std::string text = "push int8(-100)\npush int8(100)\nmul\nexit";

    cr_assert_eq(main_test(text, "underflow_operator_mult"), 84);
}

Test(overflow, operator_div)
{
    std::string text = "push float(99999999999999999999999999)\npush float(0.00000000000001)\ndiv\nexit";

    cr_assert_eq(main_test(text, "overflow_operator_div"), 84);
}

Test(undeflow, operator_div)
{
    std::string text = "push float(-99999999999999999999999999)\npush float(0.00000000000001)\ndiv\nexit";

    cr_assert_eq(main_test(text, "underflow_operator_div"), 84);
}
