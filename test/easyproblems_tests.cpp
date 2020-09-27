#include <gtest/gtest.h>
#include <palindrome.h>
#include <plusone.h>
#include <twosums.h>
#include <sqrt.h>
#include <strstr.h>
#include <reverse_integer.h>
#include <rotate_array.h>
#include <valid_parentheses.h>
#include <insert_position.h>
#include <min_depth_tree.h>
#include <balanced_binary_tree.h>
#include <merge_sorted_array.h>
#include <symmetric_tree.h>
#include <same_tree.h>
#include <remove_duplicate_list.h>
#include <max_subarray.h>
#include <greedy_sellstock.h>
#include <min_stack.h>
#include <kth_missing_number.h>
#include <contain_duplicate.h>
#include <contain_duplicate_2.h>
#include <count_primes.h>
#include <reverse_string.h>

#include <vector>
#include <../treenode.h>

TEST(Easy, TwoSums)
{
    Leet::Easy::TwoSums t;

    std::vector sums{2, 7, 11, 15};
    std::vector result{0, 1};

    ASSERT_EQ(t.twoSum(sums, 9), result);
}

TEST(Easy, TwoSums_unsorted)
{
    Leet::Easy::TwoSums t;

    std::vector sums{3, 2, 4};
    std::vector result{1, 2};

    ASSERT_EQ(t.twoSum(sums, 6), result);
}

TEST(Easy, TwoSums_duplicate)
{
    Leet::Easy::TwoSums t;

    std::vector sums{3, 3};
    std::vector result{0, 1};

    ASSERT_EQ(t.twoSum(sums, 6), result);
}

TEST(Easy, Palindrome)
{
    Leet::Easy::Palindrome p;

    ASSERT_TRUE(p.isPalindrome(121));
    ASSERT_FALSE(p.isPalindrome(10));
}

TEST(Easy, Palindrome_negative)
{
    Leet::Easy::Palindrome p;

    ASSERT_FALSE(p.isPalindrome(-121));
}

TEST(Easy, Palindrome_zero)
{
    Leet::Easy::Palindrome p;

    ASSERT_TRUE(p.isPalindrome(0));
}

TEST(Easy, Plus_one)
{
    Leet::Easy::PlusOne p;

    std::vector check{4, 3, 2, 1};
    std::vector result{4, 3, 2, 2};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {4, 3, 2, 1}";

    check = {4, 3, 9};
    result = {4, 4, 0};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {4, 3, 9}";

    check = {9, 9};
    result = {1, 0, 0};
    ASSERT_EQ(p.plusone(check), result) << "Test Case: {9, 9}";
}

TEST(Easy, square_root)
{
    Leet::Easy::Sqrt s;

    ASSERT_EQ(s.mySqrt(8), 2);
    ASSERT_EQ(s.mySqrt(0), 0);
    ASSERT_EQ(s.mySqrt(5), 2);
    ASSERT_EQ(s.mySqrt(99), 9);
    ASSERT_EQ(s.mySqrt(2), 1);
    ASSERT_EQ(s.mySqrt(2147395599), 46339);
}

TEST(Easy, strstr)
{
    Leet::Easy::Str s;

    ASSERT_EQ(s.strStr("hello", "ll"), 2);
    ASSERT_EQ(s.strStr("aaaaa", "bcb"), -1);
    ASSERT_EQ(s.strStr("aabbaabba", "bb"), 2);
    ASSERT_EQ(s.strStr("a", ""), 0);
}

TEST(Easy, reverse_int)
{
    Leet::Easy::Reverse_int r;

    ASSERT_EQ(r.reverse(123), 321);
    ASSERT_EQ(r.reverse(-123), -321);
    ASSERT_EQ(r.reverse(120), 21);
    ASSERT_EQ(r.reverse(9), 9);
}

TEST(Easy, rotated_array)
{
    Leet::Easy::RotateArray r;

    std::vector<int> input{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> output{5, 6, 7, 1, 2, 3, 4};
    r.rotate(input, 3);
    ASSERT_EQ(input, output);

    input = {-1, -100, 3, 99};
    output = {3, 99, -1, -100};
    r.rotate(input, 2);
    ASSERT_EQ(input, output);
}

TEST(Easy, valid_parentheses)
{
    Leet::Easy::Parentheses p;

    std::string s = "()";
    ASSERT_TRUE(p.isValid(s));

    s = "(){}[]";
    ASSERT_TRUE(p.isValid(s));

    s = "(]";
    ASSERT_FALSE(p.isValid(s));

    s = "([)]";
    ASSERT_FALSE(p.isValid(s));

    s = "{[]}";
    ASSERT_TRUE(p.isValid(s));

    s = "]";
    ASSERT_FALSE(p.isValid(s));
}

TEST(Easy, insert_position)
{
    Leet::Easy::InsertPos::InsertPosition i;

    std::vector<int> f{1, 3, 5, 6};
    ASSERT_EQ(i.searchInsert(f, 5), 2);
    ASSERT_EQ(i.searchInsert(f, 2), 1);
    ASSERT_EQ(i.searchInsert(f, 7), 4);
    ASSERT_EQ(i.searchInsert(f, 0), 0);
}

TEST(Easy, min_depth)
{
    Leet::Easy::MinDepthTree d;
    Leet::TreeNode *tree = new Leet::TreeNode(3);
    tree->left = new Leet::TreeNode(9);
    tree->right = new Leet::TreeNode(20);
    tree->right->left = new Leet::TreeNode(15);
    tree->right->right = new Leet::TreeNode(7);

    ASSERT_EQ(d.minDepth(tree), 2);

    delete tree;
}

TEST(Easy, balanced_tree)
{
    Leet::Easy::BalancedTree b;
    Leet::TreeNode *tree = new Leet::TreeNode(3);
    tree->left = new Leet::TreeNode(9);
    tree->right = new Leet::TreeNode(20);
    tree->right->left = new Leet::TreeNode(15);
    tree->right->right = new Leet::TreeNode(7);

    Leet::TreeNode *tree2 = new Leet::TreeNode(1);
    tree2->right = new Leet::TreeNode(2);
    tree2->left = new Leet::TreeNode(2);
    tree2->left->right = new Leet::TreeNode(3);
    tree2->left->left = new Leet::TreeNode(3);
    tree2->left->left->left = new Leet::TreeNode(4);
    tree2->left->left->right = new Leet::TreeNode(4);

    ASSERT_TRUE(b.isBalanced(tree));
    ASSERT_FALSE(b.isBalanced(tree2));

    delete tree;
    delete tree2;
}

TEST(Easy, merged_array)
{
    Leet::Easy::MergeSorted m;

    std::vector<int> m1{1, 2, 3, 0, 0, 0};
    std::vector<int> m2{2, 5, 6};
    std::vector<int> out{1, 2, 2, 3, 5, 6};

    m.merge(m1, 3, m2, 3);
    ASSERT_EQ(m1, out);

    m1 = {1, 2, 5, 5, 6, 0, 0, 0, 0};
    m2 = {3, 4, 8, 9};
    out = {1, 2, 3, 4, 5, 5, 6, 8, 9};

    m.merge(m1, 5, m2, 4);
    ASSERT_EQ(m1, out);

    m1 = {4, 0, 0, 0, 0, 0};
    m2 = {1, 2, 3, 5, 6};
    out = {1, 2, 3, 4, 5, 6};

    m.merge(m1, 1, m2, 5);
    ASSERT_EQ(m1, out);
}

TEST(Easy, symmetric_tree)
{
    Leet::Easy::SymmetricTree t;

    Leet::TreeNode *tree1 = new Leet::TreeNode(1);
    tree1->left = new Leet::TreeNode(2);
    tree1->right = new Leet::TreeNode(2);
    tree1->left->left = new Leet::TreeNode(3);
    tree1->left->right = new Leet::TreeNode(4);
    tree1->right->left = new Leet::TreeNode(4);
    tree1->right->right = new Leet::TreeNode(3);

    ASSERT_TRUE(t.isSymmetric_recursive(tree1));

    Leet::TreeNode *tree2 = new Leet::TreeNode(1);
    tree2->left = new Leet::TreeNode(2);
    tree2->right = new Leet::TreeNode(2);
    tree2->left->right = new Leet::TreeNode(3);
    tree2->right->right = new Leet::TreeNode(3);

    ASSERT_FALSE(t.isSymmetric_recursive(tree2));

    delete tree1;
    delete tree2;
}

TEST(Easy, same_tree)
{
    Leet::Easy::SameTree t;

    Leet::TreeNode *tree1 = new Leet::TreeNode(1);
    tree1->left = new Leet::TreeNode(2);
    tree1->right = new Leet::TreeNode(3);

    Leet::TreeNode *tree2 = new Leet::TreeNode(1);
    tree2->left = new Leet::TreeNode(2);
    tree2->right = new Leet::TreeNode(3);

    ASSERT_TRUE(t.isSameTree_no_preorder(tree1, tree2));

    delete tree1;
    delete tree2;
}

TEST(Easy, remove_duplicate_item)
{
    Leet::Easy::DeleteDuplicate d;

    Leet::ListNode *n = new Leet::ListNode(1);
    n->next = new Leet::ListNode(1);
    n->next->next = new Leet::ListNode(2);
    n->next->next->next = new Leet::ListNode(3);
    n->next->next->next->next = new Leet::ListNode(3);

    auto non_dup = d.deleteDuplicates(n);

    auto val = {1, 2, 3};
    for (auto &v : val)
    {
        ASSERT_EQ(non_dup->val, v);
        non_dup = non_dup->next;
    }

    delete n;
}

TEST(Easy, maximum_subarray)
{
    Leet::Easy::MaxSubArray m;

    std::vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ASSERT_EQ(m.maxSubArray(v), 6);
}

TEST(Easy, greedy_sellstock)
{
    Leet::Easy::SellStock s;

    std::vector<int> v{7, 1, 5, 3, 6, 4};
    ASSERT_EQ(s.maxProfit(v), 7);

    v = {1, 2, 3, 4, 5};
    ASSERT_EQ(s.maxProfit(v), 4);

    v = {7, 6, 4, 3, 1};
    ASSERT_EQ(s.maxProfit(v), 0);

    v = {1, 4, 2};
    ASSERT_EQ(s.maxProfit(v), 3);
}

TEST(Easy, min_stack)
{
    Leet::Easy::MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);

    ASSERT_EQ(m.getMin(), -3);
    m.pop();

    ASSERT_EQ(m.top(), 0);
    ASSERT_EQ(m.getMin(), -2);
}

TEST(Easy, kth_missing_number)
{
    Leet::Easy::KthMissing k;
    std::vector<int> s{2, 3, 4, 7, 11};

    ASSERT_EQ(k.findKthPositive(s, 5), 9);
}

TEST(Easy, contains_duplicate)
{
    Leet::Easy::Duplicates d;

    std::vector<int> nums{1,2,3,1};
    ASSERT_TRUE(d.containsDuplicate(nums));

    nums = {1,2,3,4};
    ASSERT_FALSE(d.containsDuplicate(nums));

    nums = {1,1,1,1,3,3,4,5,6,7,7};
    ASSERT_TRUE(d.containsDuplicate(nums));
}

TEST(Easy, contains_duplicate_2)
{
    Leet::Easy::Duplicate2 d;

    std::vector<int> nums{1,2,3,1};
    ASSERT_TRUE(d.containsNearbyDuplicate(nums, 3));

    nums = {1, 0, 1, 1};
    ASSERT_TRUE(d.containsNearbyDuplicate(nums, 1));

    nums = {1, 2, 3, 1, 2, 3};
    ASSERT_FALSE(d.containsNearbyDuplicate(nums, 2));
}

TEST(Easy, count_primes)
{
    Leet::Easy::CountPrimes c;

    ASSERT_EQ(c.countPrimes(10), 4);
    ASSERT_EQ(c.countPrimes(1000), 168);
}

TEST(Easy, reverse_string)
{
    Leet::Easy::ReverseString r;

    std::vector<char> input{'h', 'e', 'l', 'l', 'o'};
    std::vector<char> output{'o', 'l', 'l', 'e', 'h'};

    r.reverseString(input);
    ASSERT_EQ(input, output);
}
