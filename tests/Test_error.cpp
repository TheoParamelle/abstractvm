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

Test(error, pop)
{
    std::string text = "pop\nexit";

    cr_assert_eq(main_test(text, "error_pop"), 84);
}

Test(error, dup)
{
    std::string text = "dup\nexit";

    cr_assert_eq(main_test(text, "error_dup"), 84);
}

Test(error, swap)
{
    std::string text = "swap\nexit";

    cr_assert_eq(main_test(text, "error_swap"), 84);
}

Test(error, assert)
{
    std::string text = "assert int32(45)\nexit";

    cr_assert_eq(main_test(text, "error_assert"), 84);
}

Test(error, assert_2)
{
    std::string text = "push int32(5)\npush int32(56)\nassert int32(45)\nexit";

    cr_assert_eq(main_test(text, "error_assert_2"), 84);
}

Test(error, add)
{
    std::string text = "add\nexit";

    cr_assert_eq(main_test(text, "error_add"), 84);
}

Test(error, sub)
{
    std::string text = "sub\nexit";

    cr_assert_eq(main_test(text, "error_sub"), 84);
}

Test(error, mul)
{
    std::string text = "mul\nexit";

    cr_assert_eq(main_test(text, "error_mul"), 84);
}

Test(error, div)
{
    std::string text = "div\nexit";

    cr_assert_eq(main_test(text, "error_div"), 84);
}

Test(error, mod)
{
    std::string text = "mod\nexit";

    cr_assert_eq(main_test(text, "error_mod"), 84);
}

Test(error, load_empty)
{
    std::string text = "load int32(3)\nexit";

    cr_assert_eq(main_test(text, "load_empty"), 84);
}

Test(error, load_bad_registre)
{
    std::string text = "push int32(3)\nstore int32(3)\nload int32(17)\nexit";

    cr_assert_eq(main_test(text, "load_bad_registre"), 84);
}

Test(error, store_empty)
{
    std::string text = "store int32(3)\nexit";

    cr_assert_eq(main_test(text, "store_empty"), 84);
}

Test(error, store_bad_registre)
{
    std::string text = "push int32(3)\nstore int32(17)\nexit";

    cr_assert_eq(main_test(text, "store_bad_registre"), 84);
}

Test(error, print_empty)
{
    std::string text = "print\nexit";

    cr_assert_eq(main_test(text, "print_empty"), 84);
}

Test(error, print_no_int)
{
    std::string text = "push int32(3)\nprint\nexit";

    cr_assert_eq(main_test(text, "print_no_int"), 84);
}

Test(error, no_exit)
{
    std::string text = "push int8(3)\nprint";

    cr_assert_eq(main_test(text, "no_exit"), 84);
}

Test(error, zero_division)
{
    std::string text = "push int8(0)\npush int8(1)\ndiv\nexit";

    cr_assert_eq(main_test(text, "zero_division"), 84);
}

Test(error, modulo_zero)
{
    std::string text = "push int8(3)\npush int8(0)\nmod\nexit";

    cr_assert_eq(main_test(text, "modulo_zero"), 84);
}

Test(error, modulo_float)
{
    std::string text = "push int8(3)\npush float(14)\nmod\nexit";

    cr_assert_eq(main_test(text, "modulo_float"), 84);
}