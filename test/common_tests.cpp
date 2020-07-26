#include <gtest/gtest.h>
#include <../common.h>

TEST(Common, string_trim)
{
    std::string s = "     hello !world!";
    Leet::ltrim(s);
    ASSERT_EQ(s, "hello !world!");

    s = "hello !world! a       ";
    Leet::rtrim(s);
    ASSERT_EQ(s, "hello !world! a");
}

TEST(Common, string_split)
{
    std::string s{"hello world leet code leetcode code what wat"};
    auto sv = Leet::split(s);

    std::vector<std::string> list{"hello", "world", "leet", "code", "leetcode", "code", "what", "wat"};
    ASSERT_EQ(sv, list);
}

TEST(Common, reverse_lists)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9999};
    std::vector<int> rev_nums{9999, 8, 7, 6, 5, 4, 3, 2, 1};

    Leet::reverse(nums);
    ASSERT_EQ(nums, rev_nums);

    std::vector<std::string> words{"the", "bear", "is", "sticky", "from", "the", "honey"};
    std::vector<std::string> words_rev{"honey", "the", "from", "sticky", "is", "bear", "the"};
    Leet::reverse(words);
    ASSERT_EQ(words, words_rev);
}
