#include <basic_calculator3.h>
#include <binary_tree_max_path_sum.h>
#include <candy.h>
#include <edit_distance.h>
#include <first_missing_positive.h>
#include <gtest/gtest.h>
#include <largest_rect_histogram.h>
#include <longest_happy_prefix.h>
#include <median_sorted_arrays.h>
#include <merge_k_sorted.h>
#include <min_rotated_array2.h>
#include <min_window_substring.h>
#include <n-queen.h>
#include <serialize_deserialize_bt.h>
#include <trapping_water.h>
#include <word_ladder.h>
#include <word_search2.h>

#include <string>
#include <vector>

#include "../include/listnode.h"

TEST(Hard, Median)
{
    Leet::Hard::Median m;

    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2{5, 6, 7, 8, 9};

    m.findMedianSortedArrays_slower(v1, v2);

    // force fail
    // ASSERT_EQ(1, 2);
}

TEST(Hard, edit_distance)
{
    Leet::Hard::EditDistance e;

    ASSERT_EQ(e.minDistance("horse", "ros"), 3);
    ASSERT_EQ(e.minDistance("intention", "execution"), 5);
}

TEST(Hard, merge_k_list)
{
    // Leet::Hard::MergeKList m;
    // Leet::ListNode* list1 =
    //     new Leet::ListNode(1, new Leet::ListNode(4, new Leet::ListNode(5)));
    // Leet::ListNode* list2 =
    //     new Leet::ListNode(1, new Leet::ListNode(3, new Leet::ListNode(4)));
    // Leet::ListNode* list3 = new Leet::ListNode(2, new Leet::ListNode(6));

    // Leet::ListNode* merged = new Leet::ListNode(
    //     1, new Leet::ListNode(
    //            1, new Leet::ListNode(
    //                   2, new Leet::ListNode(
    //                          3, new Leet::ListNode(
    //                                 4, new Leet::ListNode(
    //                                        4, new Leet::ListNode(
    //                                               5, new
    //                                               Leet::ListNode(6))))))));

    // std::vector<Leet::ListNode*> list{list1, list2, list3};
    // ASSERT_EQ(m.mergeKList(list), merged);
}

TEST(Hard, missing_positive)
{
    Leet::Hard::FirstPositive f;

    auto arr = std::vector<int>{1, 2, 0};
    ASSERT_EQ(f.firstMissingPositive(arr), 3);

    arr = {3, 4, -1, 1};
    ASSERT_EQ(f.firstMissingPositive(arr), 2);

    arr = {7, 8, 9, 11, 12};
    ASSERT_EQ(f.firstMissingPositive(arr), 1);
}

TEST(Hard, candy)
{
    Leet::Hard::Candy c;

    std::vector<int> ratings = {1, 0, 2};
    ASSERT_EQ(c.candy(ratings), 5);

    ratings = {1, 2, 2};
    ASSERT_EQ(c.candy(ratings), 4);
}

TEST(Hard, trapping_water)
{
    Leet::Hard::RainWater r;

    std::vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    ASSERT_EQ(r.trap(h), 6);

    h = {4, 2, 0, 3, 2, 5};
    ASSERT_EQ(r.trap(h), 9);
}

TEST(Hard, min_window_substring)
{
    Leet::Hard::MinWinodwSubstring m;

    ASSERT_EQ(m.minWindow("ADOBECODEBANC", "ABC"), "BANC");
    ASSERT_EQ(m.minWindow("a", "a"), "a");
    ASSERT_EQ(m.minWindow("a", "aa"), "");
}

TEST(Hard, largest_rectangle)
{
    Leet::Hard::LargestRectHistogram l;

    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    ASSERT_EQ(l.largestRectangleArea(heights), 10);

    heights = {2, 4};
    ASSERT_EQ(l.largestRectangleArea(heights), 4);
}

TEST(Hard, longest_happy_prefix)
{
    Leet::Hard::LongestHappyPrefix l;

    ASSERT_EQ(l.longestPrefix("level"), "l");
    ASSERT_EQ(l.longestPrefix("ababab"), "abab");
}

TEST(Hard, min_rotated_array2)
{
    Leet::Hard::MinSortedArray2 m;

    std::vector<int> nums{1, 3, 5};
    ASSERT_EQ(m.findMin(nums), 1);

    nums = {2, 2, 2, 0, 1};
    ASSERT_EQ(m.findMin(nums), 0);
}

TEST(Hard, basic_calc_3)
{
    Leet::Hard::BasicCalc3 b;

    ASSERT_EQ(b.calculate("2*(5+5*2)/3+(6/2+8)"), 21);
    ASSERT_EQ(b.calculate("6-4/2"), 4);
    ASSERT_EQ(b.calculate("1+1"), 2);
}