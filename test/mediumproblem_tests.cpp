#include <gtest/gtest.h>
#include <palindrome_substr.h>
#include <simplifypath.h>
#include <swapnodes.h>

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

TEST(Medium, Swap_Nodes)
{
    Leet::Medium::SwapNodes s;

    auto *list = new Leet::Medium::ListNode(1);
    list->next = new Leet::Medium::ListNode(2);
    list->next->next = new Leet::Medium::ListNode(3);
    list->next->next->next = new Leet::Medium::ListNode(4);

    auto *swap = s.swapPairs(list);
    int numbers[] = {2, 1, 4, 3};
    auto idx = 0;

    while (swap)
    {
        ASSERT_EQ(swap->val, numbers[idx++]);
        swap = swap->next;
    }
}

TEST(Medium, Simple_path)
{
    Leet::Medium::Path p;

    ASSERT_EQ(p.simplifyPath_better("/home/"), "/home");
    ASSERT_EQ(p.simplifyPath_better("/../"), "/");
    ASSERT_EQ(p.simplifyPath_better("/a/../../b/../c//.//"), "/c");
    ASSERT_EQ(p.simplifyPath_better("/a//b////c/d//././/.."), "/a/b/c");
    ASSERT_EQ(p.simplifyPath_better("/..."), "/...");
}
