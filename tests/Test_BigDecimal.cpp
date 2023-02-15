/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Test_basic.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Core.hpp"
#include "Parser.hpp"

void redirect_all_stdout(void);
int main_test(std::string text, std::string id);

Test(big_decimal_tests, Assert, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(420000000000000000000000000000.2000000000000000000000000000000000000000000000001)\nassert bigdecimal(420000000000000000000000000000.2000000000000000000000000000000000000000000000001)\nexit";

    cr_assert_eq(main_test(text, "big_Assert"), 0);
}

Test(big_decimal_tests, Add, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(420000000000000000000000000000.2000000000000000000000000000000000000000000000001)\npush bigdecimal(0)\nadd\nassert bigdecimal(420000000000000000000000000000.2000000000000000000000000000000000000000000000001)\nexit";

    cr_assert_eq(main_test(text, "big_Add"), 0);
}

Test(big_decimal_tests, Add_2, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(183.000000000000000000000000000000000000000000000000000001)\npush bigdecimal(1.000000000000000000000000000000000000000000000000000001)\nadd\ndump\nexit";

    main_test(text, "big_Add_2");

    cr_assert_stdout_eq_str("184.000000000000000000000000000000000000000000000000000002\n");
}

Test(big_decimal_tests, Add_3, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(183.000000000000000000000000000000000000000000000000000001)\npush bigdecimal(0.999999999999999999999999999999999999999999999999999999)\nadd\ndump\nexit";

    main_test(text, "big_Add_3");

    cr_assert_stdout_eq_str("184\n");
}

Test(big_decimal_tests, Sub, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(656)\npush bigdecimal(-445)\nsub\ndump\nexit";

    main_test(text, "big_Sub");

    cr_assert_stdout_eq_str("1101\n");
}

Test(big_decimal_tests, Sub_2, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(656)\npush bigdecimal(1445)\nsub\ndump\nexit";

    main_test(text, "big_Sub_2");

    cr_assert_stdout_eq_str("-789\n");
}

Test(big_decimal_tests, Sub_3, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(453656)\npush int16(3656)\nsub\ndump\nexit";

    main_test(text, "big_Sub_3");

    cr_assert_stdout_eq_str("450000\n");
}

Test(big_decimal_tests, Div, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(100.2222222222222222222222222222222222222222222222222222222222222222)\npush bigdecimal(2)\ndiv\ndump\nexit";

    main_test(text, "big_Div");

    cr_assert_stdout_eq_str("50.1111111111111111111111111111111111111111111111111111111111111111\n");
}

Test(big_decimal_tests, Div_2, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(100.2222222222222222222222222222222222222222222222222222222222222222)\npush bigdecimal(-2)\ndiv\ndump\nexit";

    main_test(text, "big_Div_2");

    cr_assert_stdout_eq_str("-50.1111111111111111111111111111111111111111111111111111111111111111\n");
}

Test(big_decimal_tests, Div_3, .init=redirect_all_stdout)
{
    std::string text = "push bigdecimal(100.2222222222222222222222222222222222222222222222222222222222222222)\npush bigdecimal(0.01)\ndiv\ndump\nexit";

    main_test(text, "big_Div_3");

    cr_assert_stdout_eq_str("10022.22222222222222222222222222222222222222222222222222222222222222\n");
}