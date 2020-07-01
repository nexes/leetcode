#include <gtest/gtest.h>
#include <palindrome.h>
#include <plusone.h>
#include <twosums.h>
#include <sqrt.h>
#include <strstr.h>
#include <reverse_integer.h>
#include <rotate_array.h>
#include <valid_parentheses.h>

#include <vector>

TEST(Easy, TwoSums)
{
    Leet::Easy::TwoSums t;

    std::vector sums{2, 7, 11, 15};
    std::vector result{0, 1};

    ASSERT_EQ(t.twoSum(sums, 9), result);
}

TEST(Easy, TwoSums_unsorted)
{
    Leet::Easy::TwoSums t;

    std::vector sums{3, 2, 4};
    std::vector result{1, 2};

    ASSERT_EQ(t.twoSum(sums, 6), result);
}

TEST(Easy, TwoSums_duplicate)
{
    Leet::Easy::TwoSums t;

    std::vector sums{3, 3};
    std::vector result{0, 1};

    ASSERT_EQ(t.twoSum(sums, 6), result);
}

TEST(Easy, Palindrome)
{
    Leet::Easy::Palindrome p;

    ASSERT_TRUE(p.isPalindrome(121));
    ASSERT_FALSE(p.isPalindrome(10));
}

TEST(Easy, Palindrome_negative)
{
    Leet::Easy::Palindrome p;

    ASSERT_FALSE(p.isPalindrome(-121));
}

TEST(Easy, Palindrome_zero)
{
    Leet::Easy::Palindrome p;

    ASSERT_TRUE(p.isPalindrome(0));
}

TEST(Easy, Plus_one)
{
    Leet::Easy::PlusOne p;

    std::vector check{4, 3, 2, 1};
    std::vector result{4, 3, 2, 2};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {4, 3, 2, 1}";

    check = {4, 3, 9};
    result = {4, 4, 0};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {4, 3, 9}";

    check = {9, 9};
    result = {1, 0, 0};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {9, 9}";
}

TEST(Easy, square_root)
{
    Leet::Easy::Sqrt s;

    ASSERT_EQ(s.mySqrt(8), 2);
    ASSERT_EQ(s.mySqrt(0), 0);
    ASSERT_EQ(s.mySqrt(5), 2);
    ASSERT_EQ(s.mySqrt(99), 9);
    ASSERT_EQ(s.mySqrt(2), 1);
    ASSERT_EQ(s.mySqrt(2147395599), 46339);
}

TEST(Easy, strstr)
{
    Leet::Easy::Str s;

    ASSERT_EQ(s.strStr("hello", "ll"), 2);
    ASSERT_EQ(s.strStr("aaaaa", "bcb"), -1);
    ASSERT_EQ(s.strStr("aabbaabba", "bb"), 2);
    ASSERT_EQ(s.strStr("a", ""), 0);
}

TEST(Easy, reverse_int)
{
    Leet::Easy::Reverse_int r;

    ASSERT_EQ(r.reverse(123), 321);
    ASSERT_EQ(r.reverse(-123), -321);
    ASSERT_EQ(r.reverse(120), 21);
    ASSERT_EQ(r.reverse(9), 9);
}

TEST(Easy, rotated_array)
{
    Leet::Easy::RotateArray r;

    std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> output{5, 6, 7, 1, 2, 3, 4};
    r.rotate(input, 3);
    ASSERT_EQ(input, output);

    input = {-1, -100, 3, 99};
    output = {3, 99, -1, -100};
    r.rotate(input, 2);
    ASSERT_EQ(input, output);
}

TEST(Easy, valid_parentheses)
{
    Leet::Easy::Parentheses p;

    std::string s = "()";
    ASSERT_TRUE(p.isValid(s));

    s = "(){}[]";
    ASSERT_TRUE(p.isValid(s));

    s = "(]";
    ASSERT_FALSE(p.isValid(s));

    s = "([)]";
    ASSERT_FALSE(p.isValid(s));

    s = "{[]}";
    ASSERT_TRUE(p.isValid(s));

    s = "]";
    ASSERT_FALSE(p.isValid(s));
}
