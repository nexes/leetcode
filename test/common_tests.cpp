#include <../common.h>
#include <gtest/gtest.h>

TEST(Common, string_trim)
{
    auto algo = Leet::Algorithm();

    std::string s = "     hello !world!";
    algo.ltrim(s);
    ASSERT_EQ(s, "hello !world!");

    s = "hello !world! a       ";
    algo.rtrim(s);
    ASSERT_EQ(s, "hello !world! a");
}

TEST(Common, string_split)
{
    auto algo = Leet::Algorithm();

    std::string s{"hello world leet code leetcode code what wat"};
    auto sv = algo.split(s);

    std::vector<std::string> list{"hello",    "world", "leet", "code",
                                  "leetcode", "code",  "what", "wat"};
    ASSERT_EQ(sv, list);
}

TEST(Common, reverse_lists)
{
    auto algo = Leet::Algorithm();

    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9999};
    std::vector<int> rev_nums{9999, 8, 7, 6, 5, 4, 3, 2, 1};

    algo.reverse(nums);
    ASSERT_EQ(nums, rev_nums);

    std::vector<std::string> words{"the", "bear", "is", "sticky", "from", "the", "honey"};
    std::vector<std::string> words_rev{"honey", "the",  "from", "sticky",
                                       "is",    "bear", "the"};

    algo.reverse(words);
    ASSERT_EQ(words, words_rev);
}

TEST(Common, rotate_list)
{
    auto algo = Leet::Algorithm();

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> rotated{5, 6, 7, 1, 2, 3, 4};

    algo.rotate(v, 3);
    ASSERT_EQ(v, rotated);

    v = {1, 2, 3, 4, 5, 6, 7};
    rotated = {7, 1, 2, 3, 4, 5, 6};

    algo.rotate(v, 8);
    ASSERT_EQ(v, rotated);
}
