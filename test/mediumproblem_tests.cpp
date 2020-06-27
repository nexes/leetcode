#include <gtest/gtest.h>
#include <palindrome_substr.h>
#include <simplifypath.h>
#include <swapnodes.h>
#include <anagrams_in_string.h>
#include <add_two_numbers.h>
#include <longest_substr.h>
#include <string_to_integer.h>
#include <first_last_pos.h>
#include <rotated_array.h>

#include <string>
#include <vector>

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

    auto *list = new Leet::ListNode(1);
    list->next = new Leet::ListNode(2);
    list->next->next = new Leet::ListNode(3);
    list->next->next->next = new Leet::ListNode(4);

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

TEST(Medium, Anagram_in_strings)
{
    Leet::Medium::Anagram a;

    auto index = a.findAnagrams_sliding_window("abcdebacb", "cab");
    std::vector s{0, 5, 6};
    ASSERT_EQ(index, s);

    index = a.findAnagrams_sliding_window("abab", "ab");
    s = {0, 1, 2};
    ASSERT_EQ(index, s);

    index = a.findAnagrams_sliding_window("baa", "aa");
    s = {1};
    ASSERT_EQ(index, s);

    index = a.findAnagrams_sliding_window("cbaebabacd", "abc");
    s = {0, 6};
    ASSERT_EQ(index, s);
}

TEST(Medium, Add_two_numbers)
{
    Leet::Medium::TwoNumbers t;
    auto *l1 = new Leet::ListNode(2);
    l1->next = new Leet::ListNode(4);
    l1->next->next = new Leet::ListNode(3);

    auto *l2 = new Leet::ListNode(5);
    l2->next = new Leet::ListNode(6);
    l2->next->next = new Leet::ListNode(4);

    auto *result = t.addTwoNumbers(l1, l2);

    ASSERT_EQ(result->val, 7);
    ASSERT_EQ(result->next->val, 0);
    ASSERT_EQ(result->next->next->val, 8);
}

TEST(Medium, Longest_substr)
{
    Leet::Medium::LongestSubString l;

    auto i = l.lengthOfLongestSubstring("abcabcbb");
    ASSERT_EQ(i, 3);

    i = l.lengthOfLongestSubstring("bbbbb");
    ASSERT_EQ(i, 1);

    i = l.lengthOfLongestSubstring("pwwkew");
    ASSERT_EQ(i, 3);

    i = l.lengthOfLongestSubstring("dvdf");
    ASSERT_EQ(i, 3);
}

TEST(Medium, string_to_int)
{
    Leet::Medium::Atoi a;

    ASSERT_EQ(a.myAtoi("42"), 42);
    ASSERT_EQ(a.myAtoi("      -42"), -42);
    ASSERT_EQ(a.myAtoi("4193 with words"), 4193);
    ASSERT_EQ(a.myAtoi("words and 987"), 0);
    // Input: "-91283472332"
    // Output: -2147483648
    // Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
    //              Thefore INT_MIN (−231) is returned.
    ASSERT_EQ(a.myAtoi("-91283472332"), -2147483648);
    ASSERT_EQ(a.myAtoi(""), 0);
}

TEST(Medium, first_last_position)
{
    Leet::Medium::FirstLastPos f;

    std::vector<int> r{5, 7, 7, 8, 8, 10};
    auto range = f.searchRange(r, 8);

    ASSERT_EQ(range[0], 3);
    ASSERT_EQ(range[1], 4);

    r = {5, 7, 7, 8, 8, 10};
    range = f.searchRange(r, 6);

    ASSERT_EQ(range[0], -1);
    ASSERT_EQ(range[1], -1);

    r = {1};
    range = f.searchRange(r, 0);

    ASSERT_EQ(range[0], -1);
    ASSERT_EQ(range[1], -1);

    r = {1};
    range = f.searchRange(r, 1);

    ASSERT_EQ(range[0], 0);
    ASSERT_EQ(range[1], 0);

    r = {2, 2};
    range = f.searchRange(r, 2);

    ASSERT_EQ(range[0], 0);
    ASSERT_EQ(range[1], 1);
}

TEST(Medium, rotated_array)
{
    Leet::Medium::RotatedArray r;

    std::vector<int> f{4, 5, 6, 7, 0, 1, 2};
    auto index = r.search(f, 0);

    ASSERT_EQ(index, 4);

    f = {4, 5, 6, 7, 0, 1, 2};
    index = r.search(f, 3);

    ASSERT_EQ(index, -1);
}
