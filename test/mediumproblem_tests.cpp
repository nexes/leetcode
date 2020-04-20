#include <gtest/gtest.h>
#include <palindrome_substr.h>

#include <string>

TEST(Medium, Palindrome_isPalindrome)
{
    Leet::Medium::PalindromeSubstr p;

    ASSERT_TRUE(p.is_palindrome("dabbad", 0, 5));
    ASSERT_FALSE(p.is_palindrome("daxbbad", 0, 6));
}

TEST(Medium, Palindrome_substring)
{
    Leet::Medium::PalindromeSubstr p;

    ASSERT_EQ(p.longestPalindrome_faster("cbbd"), "bb") << "bb";
    ASSERT_EQ(p.longestPalindrome_faster("babad"), "bab") << "bab";
    ASSERT_EQ(p.longestPalindrome_faster("abb"), "bb") << "bb";
    ASSERT_EQ(p.longestPalindrome_faster("a"), "a") << "a";
    ASSERT_EQ(p.longestPalindrome_faster("bb"), "bb") << "bb";
    ASSERT_EQ(p.longestPalindrome_faster("bxb"), "bxb") << "bxb";
    ASSERT_EQ(p.longestPalindrome_faster("ac"), "a") << "a";
    ASSERT_EQ(p.longestPalindrome_faster("dddddddddddddddddddddddddddddddddddddddddddddddd"), "dddddddddddddddddddddddddddddddddddddddddddddddd");
}
