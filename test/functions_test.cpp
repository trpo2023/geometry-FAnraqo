#include <ctest.h>

#include <math.h>
#include <string>
#define _USE_MATH_DEFINES

#include <libgeometry/functions.h>

CTEST(check_name_figure_true, test1)
{
    std::string str = "circle(1 3, 5)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_name_figure_false, test2)
{
    std::string str = "circlee(1 3, 5)";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_x_int_figure_true, test3)
{
    std::string str = "circle(2 5, 6)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_x_float_figure_true, test4)
{
    std::string str = "circle(2.1 5.2, 6.3)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_x_negative_figure_true, test5)
{
    std::string str = "circle(-2 5, 6)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_x_figure_false, test6)
{
    std::string str = "circle(x1 5.2, 6.3)";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_y_int_figure_true, test7)
{
    std::string str = "circle(2 5, 6)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_y_float_figure_true, test8)
{
    std::string str = "circle(2.1 5.2, 6.3)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_y_negative_figure_true, test9)
{
    std::string str = "circle(2 -5, 6)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_y_figure_false, test10)
{
    std::string str = "circle(2.1 y1, 6.3)";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_r_int_figure_true, test11)
{
    std::string str = "circle(2 5, 6)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_r_float_figure_true, test12)
{
    std::string str = "circle(2.1 5.2, 6.3)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_r_figure_false, test13)
{
    std::string str = "circle(2.1 5.2, r1)";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end_bracket_true, test14)
{
    std::string str = "circle(2.1 5.2, 6.3)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end_bracket_false, test15)
{
    std::string str = "circle(2.1 5.2, 6.3(";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_behind_bracket_true, test16)
{
    std::string str = "circle(2.1 5.2, 6.3)";
    const int expected = 0;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_behind_bracket_false, test17)
{
    std::string str = "circle(2.1 5.2, 6.3) 123";
    const int expected = 1;
    const int result = checking_for_errors(str);
    ASSERT_EQUAL(expected, result);
}
