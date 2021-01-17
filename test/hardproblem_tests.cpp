#include <edit_distance.h>
#include <gtest/gtest.h>
#include <median.h>
#include <merge_k_sorted.h>

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
    //                                               5, new Leet::ListNode(6))))))));

    // std::vector<Leet::ListNode*> list{list1, list2, list3};
    // ASSERT_EQ(m.mergeKList(list), merged);
}
