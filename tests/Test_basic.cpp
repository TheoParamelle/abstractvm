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

int main_test(std::string text, std::string id)
{
    std::string filepath = "tests/resources/temps/temp_" + id + ".tmp";
    std::ofstream out (filepath.c_str());
    out << text << std::endl;
    out.close();

    try {
        if (!Core::compile(Parser::ParseAsm(filepath)))
            return 84;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;

        while (!Core::_stack.empty()) {
            IOperand const *stack_one = Core::_stack.top();
            Core::_stack.pop();
            delete(stack_one);
        }

		return 84;
    }

    return 0;
}

Test(basic_tests, Assert, .init=redirect_all_stdout)
{
    std::string text = "push double(42.2)\nassert double(42.2)\nexit";

    cr_assert_eq(main_test(text, "Assert"), 0);
}

Test(basic_tests, Add, .init=redirect_all_stdout)
{
    std::string text = "push int32(1808)\npush int32(0)\nadd\nassert int32(1808)\nexit";

    cr_assert_eq(main_test(text, "Add"), 0);
}

Test(basic_tests, Add_2, .init=redirect_all_stdout)
{
    std::string text = "push int32(183)\npush int32(17)\nadd\ndump\nexit";

    main_test(text, "Add_2");

    cr_assert_stdout_eq_str("200\n");
}

Test(basic_tests, Add_3, .init=redirect_all_stdout)
{
    std::string text = "push int32(183)\npush int16(32600)\nadd\ndump\nexit";

    main_test(text, "Add_3");

    cr_assert_stdout_eq_str("32783\n");
}

Test(basic_tests, Sub, .init=redirect_all_stdout)
{
    std::string text = "push int32(656)\npush int32(-445)\nsub\ndump\nexit";

    main_test(text, "Sub");

    cr_assert_stdout_eq_str("1101\n");
}

Test(basic_tests, Sub_2, .init=redirect_all_stdout)
{
    std::string text = "push int32(656)\npush int32(1445)\nsub\ndump\nexit";

    main_test(text, "Sub_2");

    cr_assert_stdout_eq_str("-789\n");
}

Test(basic_tests, Sub_3, .init=redirect_all_stdout)
{
    std::string text = "push int32(453656)\npush int16(3656)\nsub\ndump\nexit";

    main_test(text, "Sub_3");

    cr_assert_stdout_eq_str("450000\n");
}

Test(basic_tests, Div, .init=redirect_all_stdout)
{
    std::string text = "push int16(3980)\npush int32(-23)\ndiv\ndump\nexit";

    main_test(text, "Div");

    cr_assert_stdout_eq_str("-173\n");
}

Test(basic_tests, Div_2, .init=redirect_all_stdout)
{
    std::string text = "push double(1994)\npush double(16)\ndiv\ndump\nexit";

    main_test(text, "Div_2");

    cr_assert_stdout_eq_str("124.625\n");
}

Test(basic_tests, Div_3, .init=redirect_all_stdout)
{
    std::string text = "push int32(3434355)\npush int16(2)\ndiv\ndump\nexit";

    main_test(text, "Div_3");

    cr_assert_stdout_eq_str("1717177\n");
}

Test(basic_tests, Mod, .init=redirect_all_stdout)
{
    std::string text = "push int32(-1334347)\npush int32(434)\nmod\ndump\nexit";

    main_test(text, "Mod");

    cr_assert_stdout_eq_str("-231\n");
}

Test(basic_tests, Mod_2, .init=redirect_all_stdout)
{
    std::string text = "push int16(1337)\npush int16(4)\nmod\ndump\nexit";

    main_test(text, "Mod_2");

    cr_assert_stdout_eq_str("1\n");
}

Test(basic_tests, Mul, .init=redirect_all_stdout)
{
    std::string text = "push int32(32767)\npush int32(32767)\nmul\ndump\nexit";

    main_test(text, "Mul");

    cr_assert_stdout_eq_str("1073676289\n");
}

Test(basic_tests, Mul_2, .init=redirect_all_stdout)
{
    std::string text = "push int32(655361)\npush int32(-65)\nmul\ndump\nexit";

    main_test(text, "Mul_2");

    cr_assert_stdout_eq_str("-42598465\n");
}

Test(basic_tests, Dup, .init=redirect_all_stdout)
{
    std::string text = "push int32(42)\npush int32(33)\npush float(44.55)\npush double(42.42)\npush int32(54)\ndup\ndump\nexit";

    main_test(text, "Dup");

    cr_assert_stdout_eq_str("54\n54\n42.42\n44.55\n33\n42\n");
}

Test(basic_tests, Pop, .init=redirect_all_stdout)
{
    std::string text = "push int32(42)\npush int32(33)\npush float(44.55)\npush double(42.42)\npush int32(42)\npush int16(200)\npop\npop\npop\ndump\nexit";

    main_test(text, "Pop");

    cr_assert_stdout_eq_str("44.55\n33\n42\n");
}

Test(basic_tests, Print, .init=redirect_all_stdout)
{
    std::string text = "push int8(104)\npush int8(99)\npush int8(101)\npush int8(116)\npush int8(105)\npush int8(112)\npush int8(69) ; 'E'\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nprint\npop\nexit";

    main_test(text, "Print");

    cr_assert_stdout_eq_str("E\np\ni\nt\ne\nc\nh\n");
}

Test(basic_tests, Push, .init=redirect_all_stdout)
{
    std::string text = "push int32(89042)\npush int32(33333)\npush float(44.55)\npush double(-42.42)\npush int32(678)\npush int32(-434)\npush int32(-3453454)\npush double(3.14159)\npush int16(51)\npush int16(49)\npush int16(2432)\npush int32(3)\ndump\nexit";

    main_test(text, "Push");

    cr_assert_stdout_eq_str("3\n2432\n49\n51\n3.14159\n-3453454\n-434\n678\n-42.42\n44.55\n33333\n89042\n");
}

Test(basic_tests, Swap, .init=redirect_all_stdout)
{
    std::string text = "push int32(656)\npush double(678.343)\npush int32(4321)\npush int16(-34)\nswap\ndump\nexit";

    main_test(text, "Swap");

    cr_assert_stdout_eq_str("4321\n-34\n678.343\n656\n");
}

Test(basic_tests, Clear, .init=redirect_all_stdout)
{
    std::string text = "push int32(42)\npush int32(33)\npush float(44.55)\npush double(42.42)\npush int32(42)\ndump\nclear\ndump\nexit";

    main_test(text, "Clear");

    cr_assert_stdout_eq_str("42\n42.42\n44.55\n33\n42\n");
}

Test(basic_tests, Clear_2, .init=redirect_all_stdout)
{
    std::string text = "push int32(42)\npush int32(33)\npush float(44.55)\npush double(42.42)\npush int32(42)\nclear\npush int16(200)\ndump\nexit";

    main_test(text, "Clear_2");

    cr_assert_stdout_eq_str("200\n");
}