#include <gtest/gtest.h>
#include <palindrome_substr.h>

#include <string>

TEST(Medium, Palindrome_isPalindrome)
{
    Leet::Medium::PalindromeSubstr p;

    ASSERT_TRUE(p.is_palindrome("dabbad"));
    ASSERT_FALSE(p.is_palindrome("daxbbad"));

    ASSERT_TRUE(p.better_is_palindrome("dabbad", 0, 5));
}

TEST(Medium, Palindrome_substring)
{
    Leet::Medium::PalindromeSubstr p;

    ASSERT_EQ(p.longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(p.longestPalindrome("babad"), "bab");
    ASSERT_EQ(p.longestPalindrome("a"), "a");
    ASSERT_EQ(p.longestPalindrome("bb"), "bb");
    ASSERT_EQ(p.longestPalindrome("ac"), "a");
    ASSERT_EQ(p.longestPalindrome("dddddddddddddddddddddddddddddddddddddddddddddddd"), "dddddddddddddddddddddddddddddddddddddddddddddddd");
}
