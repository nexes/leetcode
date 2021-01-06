#include <132pattern.h>
#include <LRUCache.h>
#include <add_two_numbers.h>
#include <anagrams_in_string.h>
#include <balance_parentheses.h>
#include <bitwise_and_range.h>
#include <bst_iterator.h>
#include <counting_bits.h>
// #include <decode_string.h>
#include <coin_change.h>
#include <duplicate_number.h>
#include <duplicates_in_array.h>
#include <find_peak.h>
#include <first_last_pos.h>
#include <greedy_sellstock_fee.h>
#include <gtest/gtest.h>
#include <increasing_subsequence.h>
#include <k_frequent_elements.h>
#include <kth_largest.h>
#include <largest_number.h>
#include <longest_substr.h>
#include <max_length_subarray.h>
#include <max_product_subarray.h>
#include <max_width_ramp.h>
#include <merge_intervals.h>
#include <min_subarray.h>
#include <multiply_strings.h>
#include <nth_node.h>
#include <palindrome_substr.h>
#include <pancake_sort.h>
#include <permutations.h>
#include <pow.h>
#include <remove_duplicate_letters.h>
#include <remove_k_digits.h>
#include <reverse_words.h>
#include <rotate_function.h>
#include <rotated_array.h>
#include <sequential_digits.h>
#include <simplifypath.h>
#include <sort_array.h>
#include <sort_by_frequency.h>
#include <string_compression.h>
#include <string_to_integer.h>
#include <subsets.h>
#include <summary_ranges.h>
#include <swapnodes.h>
#include <target_sum.h>
#include <three_sum.h>
#include <trie.h>
#include <unique_path.h>
#include <unique_path2.h>

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
    ASSERT_EQ(
        p.longestPalindrome_faster("dddddddddddddddddddddddddddddddddddddddddddddddd"),
        "dddddddddddddddddddddddddddddddddddddddddddddddd");
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

    while (swap) {
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
    // Explanation: The number "-91283472332" is out of the range of a 32-bit
    // signed integer.
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

    while (h) {
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

    auto arr = std::vector<int>{4, 3, 2, 6};

    ASSERT_EQ(r.maxRotateFunction(arr), 26);
}

TEST(Medium, LRU_caceh)
{
    Leet::Medium::LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);

    ASSERT_EQ(c.get(1), 1);

    c.put(3, 3);  // evicts key 2

    ASSERT_EQ(c.get(2), -1);  // returns -1 (not found)
    c.put(4, 4);              // evicts key 1

    ASSERT_EQ(c.get(1), -1);  // returns -1 (not found)
    ASSERT_EQ(c.get(3), 3);   // returns 3
    ASSERT_EQ(c.get(4), 4);   // returns 4
}

TEST(Medium, summary_ranges)
{
    Leet::Medium::SummaryRange s;

    std::vector<int> nums{0, 1, 2, 4, 5, 7};
    std::vector<std::string> output{"0->2", "4->5", "7"};

    ASSERT_EQ(s.summaryRanges(nums), output);

    nums = {0, 2, 3, 4, 6, 8, 9};
    output = {"0", "2->4", "6", "8->9"};
    ASSERT_EQ(s.summaryRanges(nums), output);
}

TEST(Medium, trie)
{
    Leet::Medium::Trie t;

    t.insert("apple");

    ASSERT_TRUE(t.search("apple"));
    ASSERT_FALSE(t.search("app"));
    ASSERT_TRUE(t.startsWith("app"));

    t.insert("app");
    ASSERT_TRUE(t.search("app"));
}

TEST(Medium, counting_bits)
{
    Leet::Medium::CountBits c;

    std::vector<int> out{0, 1, 1};
    ASSERT_EQ(c.countBits(2), out);

    out = {0, 1, 1, 2, 1, 2};
    ASSERT_EQ(c.countBits(5), out);
}

TEST(Medium, balance_parentheses)
{
    Leet::Medium::BalancedParens b;

    std::string s = "(()))";
    ASSERT_EQ(b.minInsertions(s), 1) << "(()))";

    s = "())";
    ASSERT_EQ(b.minInsertions(s), 0) << "())";

    s = "))())(";
    ASSERT_EQ(b.minInsertions(s), 3) << "))())(";

    s = "((((((";
    ASSERT_EQ(b.minInsertions(s), 12) << "((((((";

    s = ")))))))";
    ASSERT_EQ(b.minInsertions(s), 5) << ")))))))";
}

TEST(Medium, duplicate_in_array)
{
    Leet::Medium::DuplicatesArray d;

    auto s = std::vector<int>{4, 3, 2, 7, 8, 2, 3, 1};
    auto out = std::vector<int>{2, 3};

    ASSERT_EQ(d.findDuplicates(s), out);
}

TEST(Medium, subsets)
{
    Leet::Medium::SubSets s;

    auto arr = std::vector<int>{1, 2, 3};
    auto out = std::vector<std::vector<int>>{
        {1, 2, 3},
        {1, 2},
        {1, 3},
        {1},
        {2, 3},
        {2},
        {3},
        {},
    };

    ASSERT_EQ(s.subsets(arr), out);
}

TEST(Medium, sequential_digits)
{
    Leet::Medium::SequentialDigit s;
    ASSERT_EQ(s.digit_length(321), 3);

    auto out = std::vector<int>{123, 234};
    ASSERT_EQ(s.sequentialDigits(100, 300), out);

    out = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
    ASSERT_EQ(s.sequentialDigits(1000, 13000), out);
}

TEST(Medium, max_subarray)
{
    Leet::Medium::MaxSubArray m;

    auto a = std::vector<int>{1, 2, 3, 2, 1};
    auto b = std::vector<int>{3, 2, 1, 4, 7};

    ASSERT_EQ(m.findLength(a, b), 3);

    a = std::vector<int>{0, 1, 1, 1, 1};
    b = std::vector<int>{1, 0, 1, 0, 1};

    ASSERT_EQ(m.findLength(a, b), 2);
}

TEST(Medium, merge_interval)
{
    Leet::Medium::MergeInterval m;

    std::vector<std::vector<int>> arr = {
        {1, 9},
        {2, 5},
        {19, 20},
        {10, 11},
        {12, 20},
        {0, 3},
        {0, 1},
        {0, 2},
    };

    std::vector<std::vector<int>> out = {
        {0, 9},
        {10, 11},
        {12, 20},
    };

    ASSERT_EQ(m.merge(arr), out);
}

TEST(Medium, sort_array)
{
    Leet::Medium::SortArray s;

    auto in = std::vector<int>{5, 2, 3, 1};
    auto out = std::vector<int>{1, 2, 3, 5};
    ASSERT_EQ(s.sortArray(in), out);

    in = {5, 1, 1, 2, 0, 0};
    out = {0, 0, 1, 1, 2, 5};
    ASSERT_EQ(s.sortArray(in), out);
}

TEST(Medium, max_width_ramp)
{
    Leet::Medium::MaxWidthRamp m;

    auto in = std::vector<int>{6, 0, 8, 2, 1, 5};
    ASSERT_EQ(m.maxWidthRamp(in), 4);

    in = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    ASSERT_EQ(m.maxWidthRamp(in), 7);
}

TEST(Medium, pancake_sort)
{
    Leet::Medium::Pancake p;

    auto in = std::vector<int>{3, 2, 4, 1};
    auto out = std::vector<int>{1, 2, 3, 4};

    p.pancakeSort(in);
    ASSERT_EQ(in, out);

    in = {-23, 5, 6, 8, 334, 0, 1};
    out = {-23, 0, 1, 5, 6, 8, 334};

    p.pancakeSort(in);
    ASSERT_EQ(in, out);

    in = {-23, -5, -6, 8, 334, 8, 1};
    out = {-23, -6, -5, 1, 8, 8, 334};

    p.pancakeSort(in);
    ASSERT_EQ(in, out);
}

TEST(Medium, pow)
{
    Leet::Medium::Pow p;

    ASSERT_DOUBLE_EQ(p.myPow(2, 10), 1024);
    ASSERT_DOUBLE_EQ(p.myPow(2.1, 3), 9.261);
    ASSERT_DOUBLE_EQ(p.myPow(2, -2), 0.25);
}

TEST(Medium, max_product_subarray)
{
    Leet::Medium::MaxProduct m;

    auto arr = std::vector<int>{2, 3, -1, 4};
    ASSERT_EQ(m.maxProduct(arr), 6);

    arr = {-2, 0, -1};
    ASSERT_EQ(m.maxProduct(arr), 0);

    arr = {0, 2};
    ASSERT_EQ(m.maxProduct(arr), 2);

    arr = {2, 3, -2, 4};
    ASSERT_EQ(m.maxProduct_linear(arr), 6);
}

TEST(Medium, largest_number)
{
    Leet::Medium::LargestNum n;

    auto arr = std::vector<int>{3, 30, 34, 5, 9};
    ASSERT_EQ(n.largestNumber(arr), "9534330");

    arr = {1};
    ASSERT_EQ(n.largestNumber(arr), "1");

    arr = {10, 2};
    ASSERT_EQ(n.largestNumber(arr), "210");

    arr = {0, 0};
    ASSERT_EQ(n.largestNumber(arr), "0");
}

TEST(Medium, remove_k_digits)
{
    Leet::Medium::RemoveDigits r;

    ASSERT_EQ(r.removeKdigits("1432219", 3), "1219");
    ASSERT_EQ(r.removeKdigits("10200", 1), "200");
    ASSERT_EQ(r.removeKdigits("5337", 2), "33");
}

// TEST(Medium, decode_string)
// {
//     Leet::Medium::DecodeStr d;

//     ASSERT_EQ(d.decodeString("abc3[cd]xyz"), "abccdcdcdxyz");
//     ASSERT_EQ(d.decodeString("3[a]2[bc]"), "aaabcbc");
//     ASSERT_EQ(d.decodeString("3[a2[c]]"), "accaccacc");
// }

TEST(Medium, compress_string)
{
    Leet::Medium::StringCompress s;

    auto arr = std::vector<char>{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    ASSERT_EQ(s.compress(arr), 6);

    arr = {'a'};
    ASSERT_EQ(s.compress(arr), 1);

    arr = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    ASSERT_EQ(s.compress(arr), 4);
}

TEST(Medium, sort_by_frequency)
{
    Leet::Medium::CharFrequency c;

    ASSERT_EQ(c.frequencySort("tree"), "eert");
    ASSERT_EQ(c.frequencySort("cccaaa"), "aaaccc");
    ASSERT_EQ(c.frequencySort("Aabb"), "bbaA");
}

TEST(Medium, target_sum)
{
    Leet::Medium::TargetSum t;

    auto arr = std::vector<int>{1, 1, 1, 1, 1};
    ASSERT_EQ(t.findTargetSumWays(arr, 3), 5);
}

TEST(Medium, pattern_132)
{
    Leet::Medium::Pattern132 p;

    auto arr = std::vector<int>{1, 2, 3, 4};
    ASSERT_FALSE(p.find132pattern_cubic(arr));

    arr = {3, 1, 4, 2};
    ASSERT_TRUE(p.find132pattern_cubic(arr));

    arr = {-1, 3, 2, 0};
    ASSERT_TRUE(p.find132pattern_cubic(arr));
}

TEST(Medium, k_freq_elements)
{
    Leet::Medium::KFreqElements k;

    auto arr = std::vector<int>{1, 1, 1, 2, 2, 3};
    auto out = std::vector<int>{1, 2};

    ASSERT_EQ(k.topKFrequent(arr, 2), out);

    arr = {1};
    out = {1};
    ASSERT_EQ(k.topKFrequent(arr, 1), out);
}

TEST(Medium, remove_dup_letters)
{
    Leet::Medium::RemoveDuplicate r;

    // ASSERT_EQ(r.removeDuplicateLetters("bcabc"), "abc");
    // ASSERT_EQ(r.removeDuplicateLetters("cbacdcbc"), "acdb");
    ASSERT_EQ(r.removeDuplicateLetters("cdadabcc"), "adbc");
}

TEST(Medium, coin_change)
{
    Leet::Medium::CoinChange c;

    auto arr = std::vector<int>{1, 2, 5};
    ASSERT_EQ(c.coinChange(arr, 11), 3);

    arr = {2};
    ASSERT_EQ(c.coinChange(arr, 3), -1);

    arr = {0};
    ASSERT_EQ(c.coinChange(arr, 0), 0);

    arr = {1};
    ASSERT_EQ(c.coinChange(arr, 1), 1);

    arr = {1};
    ASSERT_EQ(c.coinChange(arr, 2), 2);
}

TEST(Medium, increasing_subsequence)
{
    Leet::Medium::IncreasingSubSeq i;

    auto arr = std::vector<int>{10, 9, 2, 5, 3, 7, 101, 18};
    ASSERT_EQ(i.lengthOfLIS(arr), 4);

    arr = {0, 1, 0, 3, 2, 3};
    ASSERT_EQ(i.lengthOfLIS(arr), 4);

    arr = {7, 7, 7, 7, 7};
    ASSERT_EQ(i.lengthOfLIS(arr), 1);

    arr = {4, 10, 4, 3, 8, 9};
    ASSERT_EQ(i.lengthOfLIS(arr), 3);
}
