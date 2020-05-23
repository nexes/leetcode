#include <gtest/gtest.h>
#include <median.h>

#include <vector>

TEST(Hard, Median)
{
    Leet::Hard::Median m;

    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v2{5, 6, 7, 8, 9};

    m.findMedianSortedArrays_slower(v1, v2);

    // force fail
    // ASSERT_EQ(1, 2);
}
