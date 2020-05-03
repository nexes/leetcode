#include <gtest/gtest.h>
#include <palindrome.h>
#include <plusone.h>
#include <twosums.h>

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
