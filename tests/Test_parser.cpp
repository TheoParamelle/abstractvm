/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-abstractVM-theo.paramelle
** File description:
** Test_parser.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Parser.hpp"

int main_test(std::string, std::string);
void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(parser, undefined_method)
{
    try {
        Parser::ParseAsm("tests/resources/undefined_method.test");

        cr_assert(0);
    } catch (const ParseException &e) {
        cr_assert_str_eq("Parse Error: Illegal instruction: trend", e.what());
    }
}

Test(parser, method_without_arg)
{
    try {
        Parser::ParseAsm("tests/resources/method_without_arg.test");

        cr_assert(0);
    } catch (const ParseException &e) {
        cr_assert_str_eq("Parse Error: Instruction assert need parameter", e.what());
    }
}

Test(parser, no_file)
{
    try {
        Parser::ParseAsm("i_do_not_exist.test");

        cr_assert(0);
    } catch (const ParseException &e) {
        cr_assert(1);
    }
}

Test(parser, whitespace, .init=redirect_all_stdout)
{
    std::string text = "push int8 (104)\npush   int8( 99 )\n   push int8  (101)\npush int8(116)\npush int8(105     )\n  push int8     (112)\npush int8(69) ; 'E'\nprint    \n     pop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nexit";

    main_test(text, "Whitespace");

    cr_assert_stdout_eq_str("E\np\ni\nt\ne\nc\nh\n");
}

Test(parser, type_with_float, .init=redirect_all_stdout)
{
    std::string text = "push int8(100.34)\npush   int8( 99 )\n   push int8  (101)\npush int8(116)\npush int8(105     )\n  push int8     (112)\npush int8(69) ; 'E'\nprint    \n     pop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nexit";

    cr_assert_eq(main_test(text, "type_with_float"), 84);
}

Test(parser, comment_test)
{
    std::string text = "push int8(100)\npush int8(99)\n push int8(101)\n   ; this is a comment\npush int8(116)\npush int8(105)\npush int8(112)\npush int8(69);'E'\nexit";

    cr_assert_eq(main_test(text, "comment_test"), 0);
}