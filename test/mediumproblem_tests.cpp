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
#include <three_sum.h>
#include <multiply_strings.h>
#include <nth_node.h>
#include <greedy_sellstock_fee.h>
#include <reverse_words.h>
#include <bst_iterator.h>
#include <permutations.h>
#include <unique_path.h>
#include <unique_path2.h>
#include <find_peak.h>
#include <bitwise_and_range.h>
#include <min_subarray.h>
#include <kth_largest.h>
#include <duplicate_number.h>
#include <rotate_function.h>

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

    delete list;
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

    delete l1;
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

TEST(Medium, rotated_array_search)
{
    Leet::Medium::RotatedArray r;

    std::vector<int> f{4, 5, 6, 7, 0, 1, 2};
    auto index = r.search(f, 0);

    ASSERT_EQ(index, 4);

    f = {4, 5, 6, 7, 0, 1, 2};
    index = r.search(f, 3);

    ASSERT_EQ(index, -1);
}

// TEST(Medium, three_sum)
// {
//     Leet::Medium::ThreeSum t;

//     std::vector<int> f{-1, 0, 1, 2, -1, -4};
//     std::vector<std::vector<int>> v{
//         {-1, 0, 1},
//         {-1, -1, 2}};
//     ASSERT_EQ(t.threeSum(f), v);

//     f = {-2, 0, 1, 1, 2};
//     v = {
//         {-2, 0, 2},
//         {-2, 1, 1}};
//     ASSERT_EQ(t.threeSum(f), v);
// }

TEST(Medium, multiply_string)
{
    Leet::Medium::MultiplyString m;

    ASSERT_EQ(m.multiply("2", "3"), "6");
    ASSERT_EQ(m.multiply("123", "456"), "56088");
    ASSERT_EQ(m.multiply("123456789", "987654321"), "121932631112635269");
}

TEST(Medium, nth_node)
{
    Leet::Medium::NthNode n;

    auto *list = new Leet::ListNode(1);
    list->next = new Leet::ListNode(2);
    list->next->next = new Leet::ListNode(3);
    list->next->next->next = new Leet::ListNode(4);
    list->next->next->next->next = new Leet::ListNode(5);

    auto i = 0;
    auto h = n.removeNthFromEnd_one_pass(list, 2);
    int val[5] = {1, 2, 3, 5};

    while (h)
    {
        ASSERT_EQ(h->val, val[i++]);
        h = h->next;
    }

    delete list;
}

TEST(Medium, greedy_sellstock_fee)
{
    Leet::Medium::SellStock s;

    std::vector<int> v{1, 3, 2, 8, 4, 9};
    ASSERT_EQ(s.maxProfit(v, 2), 8);

    v = {4, 5, 2, 4, 3, 3, 1, 2, 5, 4, 1};
    ASSERT_EQ(s.maxProfit(v, 1), 4);
}

TEST(Medium, reverse_words)
{
    Leet::Medium::ReverseWords r;

    ASSERT_EQ(r.reverseWords("the sky is blue"), "blue is sky the");
    ASSERT_EQ(r.reverseWords("    hello world!   "), "world! hello");
    ASSERT_EQ(r.reverseWords("a good    example "), "example good a");
}

TEST(Medium, bst_iterator)
{
    Leet::TreeNode *root = new Leet::TreeNode(7);
    root->left = new Leet::TreeNode(3);
    root->right = new Leet::TreeNode(15);
    root->right->left = new Leet::TreeNode(9);
    root->right->right = new Leet::TreeNode(20);

    Leet::Medium::BSTIterator b(root);

    ASSERT_EQ(b.next(), 3);
    ASSERT_EQ(b.next(), 7);
    ASSERT_TRUE(b.hasNext());
    ASSERT_EQ(b.next(), 9);
    ASSERT_TRUE(b.hasNext());
    ASSERT_EQ(b.next(), 15);
    ASSERT_TRUE(b.hasNext());
    ASSERT_EQ(b.next(), 20);
    ASSERT_FALSE(b.hasNext());

    delete root;
}

TEST(Medium, permutation)
{
    Leet::Medium::Permutation p;
    std::vector<int> in{1, 2, 3};
    std::vector<std::vector<int>> out{
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 2, 1},
        {3, 1, 2},
    };

    ASSERT_EQ(p.permute(in), out);
}

TEST(Medium, unique_path)
{
    Leet::Medium::UniquePath p;

    ASSERT_EQ(p.uniquePath(3, 2), 3);
    ASSERT_EQ(p.uniquePath(7, 3), 28);
}

TEST(Medium, unique_path2)
{
    Leet::Medium::UniquePath2 p;
    std::vector<std::vector<int>> grid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };

    ASSERT_EQ(p.uniquePathWithObstacles(grid), 2);
}

TEST(Medium, find_peak_element)
{
    Leet::Medium::FindPeak f;

    std::vector<int> nums{1, 2, 3, 1};

    ASSERT_EQ(f.findPeakElement_linear(nums), 2);

    nums = {1, 2, 1, 3, 5, 6, 4};
    ASSERT_EQ(f.findPeakElement_linear(nums), 1);

    nums = {1, 2, 3, 1};
    ASSERT_EQ(f.findPeakElement_logarithmic(nums), 2);

    nums = {1, 2, 1, 3, 5, 6, 4};
    ASSERT_EQ(f.findPeakElement_logarithmic(nums), 5);
}

TEST(Medium, bitwise_and_range)
{
    Leet::Medium::BitwiseAnd b;

    ASSERT_EQ(b.rangeBitwiseAnd(5, 7), 4);
    ASSERT_EQ(b.rangeBitwiseAnd(0, 1), 0);

    // takes to long
    // ASSERT_EQ(b.rangeBitwiseAnd(20000, 2147483647), 0);

    ASSERT_EQ(b.rangeBitwiseAnd_clever(5, 7), 4);
    ASSERT_EQ(b.rangeBitwiseAnd_clever(0, 1), 0);
    ASSERT_EQ(b.rangeBitwiseAnd_clever(20000, 2147483647), 0);
}

TEST(Medium, min_sub_array)
{
    Leet::Medium::MinSubArray m;

    std::vector<int> nums{2, 3, 1, 2, 4, 3};
    ASSERT_EQ(m.minSubArrayLen(7, nums), 2);

    nums = {1, 4, 4};
    ASSERT_EQ(m.minSubArrayLen(4, nums), 1);

    nums = {1, 2, 3, 4, 5};
    ASSERT_EQ(m.minSubArrayLen(11, nums), 3);
}

TEST(Medium, kth_largest_element)
{
    Leet::Medium::KthLargest k;

    std::vector nums{3, 2, 1, 5, 6, 4};
    ASSERT_EQ(k.findKthLargest_queue(nums, 2), 5);

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    ASSERT_EQ(k.findKthLargest(nums, 4), 4);
}

TEST(Medium, dupicate_number)
{
    Leet::Medium::DuplicateNumber d;

    std::vector<int> nums{1, 3, 4, 2, 2};
    ASSERT_EQ(d.findDuplicate(nums), 2);

    nums = {3, 1, 3, 4, 2};
    ASSERT_EQ(d.findDuplicate(nums), 3);

    nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    ASSERT_EQ(d.findDuplicate(nums), 9);
}

TEST(Medium, rotate_function)
{
    Leet::Medium::RotateFunc r;
}
