#include <../treenode.h>
#include <add_binary.h>
#include <add_strings.h>
#include <alien_dictionary.h>
#include <array_from_integer.h>
#include <average_level_tree.h>
#include <balanced_binary_tree.h>
#include <base7.h>
#include <binary_substring.h>
#include <binary_tree_mode.h>
#include <check_straight_line.h>
#include <contain_duplicate.h>
#include <contain_duplicate_2.h>
#include <convert_to_hex.h>
#include <count_chars.h>
#include <count_primes.h>
#include <cousins_binary_tree.h>
#include <defang_ip.h>
#include <disappeared_nums.h>
#include <distribute_candies.h>
#include <fibonacci_number.h>
#include <find_pivot.h>
#include <find_the_difference.h>
#include <greedy_sellstock.h>
#include <gtest/gtest.h>
#include <hamming_distance.h>
#include <insert_position.h>
#include <is_subsequence.h>
#include <island_perimeter.h>
#include <isomorphic_string.h>
#include <kth_missing_number.h>
#include <length_last_word.h>
#include <longest_palindrome.h>
#include <majority_element.h>
#include <max_product_three.h>
#include <max_subarray.h>
#include <merge_sorted_array.h>
#include <min_absolute_diff.h>
#include <min_depth_tree.h>
#include <min_stack.h>
#include <move_zeroes.h>
#include <n_repeated_array.h>
#include <number_complement.h>
#include <palindrome.h>
#include <pascals_triangle.h>
#include <perfect_square.h>
#include <plusone.h>
#include <power_of_three.h>
#include <ransom_note.h>
#include <remove_duplicate_list.h>
#include <remove_list_elements.h>
#include <reverse_bits.h>
#include <reverse_integer.h>
#include <reverse_string.h>
#include <reverse_string_2.h>
#include <reverse_words_3.h>
#include <rotate_array.h>
#include <same_tree.h>
#include <single_number.h>
#include <sort_array_parity.h>
#include <sqrt.h>
#include <string_from_tree.h>
#include <strstr.h>
#include <symmetric_tree.h>
#include <third_max_number.h>
#include <two_sum_2.h>
#include <twosums.h>
#include <unique_char_str.h>
#include <valid_anagram.h>
#include <valid_palindrome.h>
#include <valid_parentheses.h>
#include <word_pattern.h>

#include <vector>

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
    for (auto &v : val) {
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

    std::vector<int> nums{1, 2, 3, 1};
    ASSERT_TRUE(d.containsDuplicate(nums));

    nums = {1, 2, 3, 4};
    ASSERT_FALSE(d.containsDuplicate(nums));

    nums = {1, 1, 1, 1, 3, 3, 4, 5, 6, 7, 7};
    ASSERT_TRUE(d.containsDuplicate(nums));
}

TEST(Easy, contains_duplicate_2)
{
    Leet::Easy::Duplicate2 d;

    std::vector<int> nums{1, 2, 3, 1};
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

TEST(Easy, power_of_three)
{
    Leet::Easy::PowerOfThree p;

    ASSERT_TRUE(p.isPowerOfThree_linear(27));
    ASSERT_FALSE(p.isPowerOfThree_linear(0));
    ASSERT_TRUE(p.isPowerOfThree_linear(9));
    ASSERT_FALSE(p.isPowerOfThree_linear(45));
}

TEST(Easy, hamming_distance)
{
    Leet::Easy::HammingDistance h;

    ASSERT_EQ(h.hammingDistance(1, 4), 2);
}

TEST(Easy, reverse_bits)
{
    Leet::Easy::ReverseBits r;

    auto rev = r.reverseBits(43261596);
    ASSERT_EQ(rev, 964176192);

    rev = r.reverseBits(4294967293);
    ASSERT_EQ(rev, 3221225471);
}

TEST(Easy, is_subsequence)
{
    Leet::Easy::IsSubsequence i;

    auto s = "abc";
    auto t = "ahbgdc";
    ASSERT_TRUE(i.isSubsequence(s, t));

    s = "axc";
    ASSERT_FALSE(i.isSubsequence(s, t));
}

TEST(Easy, disappeared_nums)
{
    Leet::Easy::DisappearNums n;

    auto s = std::vector<int>{4, 3, 2, 7, 8, 2, 3, 1};
    auto out = std::vector<int>{5, 6};

    ASSERT_EQ(n.findDisappearedNumbers(s), out);
}

TEST(Easy, length_last_word)
{
    Leet::Easy::LengthLastWord l;

    ASSERT_EQ(l.lengthOfLastWord("Hello World"), 5);
}

TEST(Easy, sort_array_parity)
{
    Leet::Easy::SortByParity s;

    auto in = std::vector<int>{3, 1, 2, 4};
    auto out = std::vector<int>{2, 4, 3, 1};

    ASSERT_EQ(s.sortArrayByParity(in), out);
}

TEST(Easy, unique_char_string)
{
    Leet::Easy::UniqueChar c;

    ASSERT_EQ(c.firstUniqChar("leetcode"), 0);
    ASSERT_EQ(c.firstUniqChar("loveleetcode"), 2);
}

TEST(Easy, defang_ip)
{
    Leet::Easy::Defang d;

    ASSERT_EQ(d.defangIPaddr("1.1.1.1"), "1[.]1[.]1[.]1");
    ASSERT_EQ(d.defangIPaddr("255.255.255.255"), "255[.]255[.]255[.]255");
}

TEST(Easy, diff_min)
{
    Leet::Easy::MinAbsDiff m;

    auto in = std::vector<int>{4, 2, 1, 3};
    auto out = std::vector<std::vector<int>>{
        {1, 2},
        {2, 3},
        {3, 4},
    };
    ASSERT_EQ(m.minimumAbsDifference(in), out);

    in = {3, 8, -10, 23, 19, -4, -14, 27};
    out = {
        {-14, -10},
        {19, 23},
        {23, 27},
    };
    ASSERT_EQ(m.minimumAbsDifference(in), out);
}

TEST(Easy, count_characters)
{
    Leet::Easy::CountChars c;

    auto arr = std::vector<std::string>{"cat", "bt", "hat", "tree"};
    ASSERT_EQ(c.countCharacters(arr, "atach"), 6);

    arr = {"hello", "world", "leetcode"};
    ASSERT_EQ(c.countCharacters(arr, "welldonehoneyr"), 10);
}

TEST(Easy, check_straight_line)
{
    Leet::Easy::StraightLine s;

    auto out = std::vector<std::vector<int>>{
        {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7},
    };
    ASSERT_TRUE(s.checkStraightLine(out));

    out = {
        {1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7},
    };
    ASSERT_FALSE(s.checkStraightLine(out));

    out = {
        {-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2},
    };
    ASSERT_FALSE(s.checkStraightLine(out));
}

TEST(Easy, find_pivot)
{
    Leet::Easy::FindPivot f;

    auto arr = std::vector<int>{1, 7, 3, 6, 5, 6};
    ASSERT_EQ(f.pivotIndex(arr), 3);

    arr = {1, 2, 3};
    ASSERT_EQ(f.pivotIndex(arr), -1);
}

TEST(Easy, alien_dictionary)
{
    Leet::Easy::AlienDictionary a;

    auto arr = std::vector<std::string>{"hello", "leetcode"};
    ASSERT_TRUE(a.isAlienSorted(arr, "hlabcdefgijkmnopqrstuvwxyz"));

    arr = {"word", "world", "row"};
    ASSERT_FALSE(a.isAlienSorted(arr, "worldabcefghijkmnpqstuvxyz"));

    arr = {"apple", "app"};
    ASSERT_FALSE(a.isAlienSorted(arr, "abcdefghijklmnopqrstuvwxyz"));
}

TEST(Easy, n_repeated_array)
{
    Leet::Easy::NRepeated n;

    auto arr = std::vector<int>{1, 2, 3, 3};

    ASSERT_EQ(n.repeatedNTimes(arr), 3);

    arr = {2, 1, 2, 5, 3, 2};
    ASSERT_EQ(n.repeatedNTimes(arr), 2);

    arr = {5, 1, 5, 2, 5, 3, 5, 4};
    ASSERT_EQ(n.repeatedNTimes(arr), 5);
}

TEST(Easy, cousins_binary_tree)
{
    Leet::Easy::CousinsTree c;

    auto *tree = new Leet::TreeNode(1);
    tree->left = new Leet::TreeNode(2);
    tree->right = new Leet::TreeNode(3);
    tree->left->left = new Leet::TreeNode(4);

    ASSERT_FALSE(c.isCousins(tree, 4, 3));
}

TEST(Easy, array_form)
{
    Leet::Easy::ArrayFromInt a;

    auto arr = std::vector<int>{1, 2, 0, 0};
    auto out = std::vector<int>{1, 2, 3, 4};

    ASSERT_EQ(a.addToArrayForm(arr, 34), out);

    arr = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    out = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ASSERT_EQ(a.addToArrayForm(arr, 1), out);
}

TEST(Easy, majority_element)
{
    Leet::Easy::MajorityElement m;

    auto arr = std::vector<int>{3, 2, 3};

    ASSERT_EQ(m.majorityElement(arr), 3);

    arr = {2, 2, 1, 1, 1, 2, 2};
    ASSERT_EQ(m.majorityElement(arr), 2);
}

TEST(Easy, add_strings)
{
    Leet::Easy::AddString a;

    ASSERT_EQ(a.addStrings("123", "9"), "132");
    ASSERT_EQ(a.addStrings("0", "10"), "10");
    ASSERT_EQ(a.addStrings("999", "1"), "1000");
}

TEST(Easy, max_three_product)
{
    Leet::Easy::MaxProduct m;

    auto arr = std::vector<int>{1, 2, 3, 4};
    ASSERT_EQ(m.maximumProduct(arr), 24);

    arr = {-100, -98, -1, 2, 3, 4};
    ASSERT_EQ(m.maximumProduct(arr), 39200);
}

TEST(Easy, binary_substring)
{
    Leet::Easy::BinarySubStr b;

    auto str = "00110011";
    ASSERT_EQ(b.countBinarySubstrings(str), 6);

    str = "10101";
    ASSERT_EQ(b.countBinarySubstrings(str), 4);
}

TEST(Easy, find_difference_string)
{
    Leet::Easy::FindDiff f;

    ASSERT_EQ(f.findTheDifference("abcd", "abcde"), 'e');
    ASSERT_EQ(f.findTheDifference("", "y"), 'y');
    ASSERT_EQ(f.findTheDifference("a", "aa"), 'a');
}

TEST(Easy, perfect_square)
{
    Leet::Easy::PerfectSqr p;

    ASSERT_TRUE(p.isPerfectSquare(16));
    ASSERT_FALSE(p.isPerfectSquare(14));
}

TEST(Easy, ransom_note)
{
    Leet::Easy::RansomNote r;

    ASSERT_FALSE(r.canConstruct("a", "b"));
    ASSERT_FALSE(r.canConstruct("aa", "ab"));
    ASSERT_TRUE(r.canConstruct("aa", "aab"));
}

TEST(Easy, convert_to_hex)
{
    Leet::Easy::ConvertToHex h;

    ASSERT_EQ(h.toHex(26), "1a");
    ASSERT_EQ(h.toHex(8547), "2163");
    ASSERT_EQ(h.toHex(0), "0");
    ASSERT_EQ(h.toHex(999993), "f4239");
    ASSERT_EQ(h.toHex(-4), "fffffffc");
    ASSERT_EQ(h.toHex(-123), "ffffff85");
    ASSERT_EQ(h.toHex(-1), "ffffffff");
}

TEST(Easy, longest_palindrome)
{
    Leet::Easy::LongestPalindrome p;

    ASSERT_EQ(p.longestPalindrome("abccccdd"), 7);
    ASSERT_EQ(p.longestPalindrome("a"), 1);
    ASSERT_EQ(p.longestPalindrome("bb"), 2);
}

TEST(Easy, single_number)
{
    Leet::Easy::SingleNumber s;

    auto arr = std::vector<int>{2, 2, 1};
    ASSERT_EQ(s.singleNumber(arr), 1);

    arr = {4, 1, 2, 1, 2};
    ASSERT_EQ(s.singleNumber(arr), 4);

    arr = {1};
    ASSERT_EQ(s.singleNumber(arr), 1);
}

TEST(Easy, island_perimeter)
{
    Leet::Easy::IslandPerimeter i;

    auto island = std::vector<std::vector<int>>{
        {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    ASSERT_EQ(i.islandPerimeter(island), 16);

    island = {{1}};
    ASSERT_EQ(i.islandPerimeter(island), 4);

    island = {{1, 0}};
    ASSERT_EQ(i.islandPerimeter(island), 4);
}

TEST(Easy, number_complement)
{
    Leet::Easy::NumComplement n;

    ASSERT_EQ(n.findComplement(5), 2);
    ASSERT_EQ(n.findComplement(10), 5);
    ASSERT_EQ(n.findComplement(14), 1);
}

TEST(Easy, third_max_number)
{
    Leet::Easy::ThirdMax t;

    auto arr = std::vector<int>{3, 2, 1};
    ASSERT_EQ(t.thirdMax(arr), 1);

    arr = {1, 2};
    ASSERT_EQ(t.thirdMax(arr), 2);

    arr = {2, 2, 3, 1};
    ASSERT_EQ(t.thirdMax(arr), 1);
}

TEST(Easy, two_sum_2)
{
    Leet::Easy::TwoSum2 t;

    auto arr = std::vector<int>{2, 7, 11, 15};
    auto out = std::vector<int>{1, 2};
    ASSERT_EQ(t.twoSum(arr, 9), out);

    arr = {2, 3, 4};
    out = {1, 3};
    ASSERT_EQ(t.twoSum(arr, 6), out);

    arr = {-1, 0};
    out = {1, 2};
    ASSERT_EQ(t.twoSum(arr, -1), out);
}

TEST(Easy, valid_anagram)
{
    Leet::Easy::ValidAnagram v;

    ASSERT_TRUE(v.isAnagram("anagram", "nagaram"));
    ASSERT_FALSE(v.isAnagram("rat", "car"));
}

TEST(Easy, word_pattern)
{
    Leet::Easy::WordPattern w;

    ASSERT_TRUE(w.wordPattern("abba", "dog cat cat dog"));
    ASSERT_TRUE(w.wordPattern("rqqr", "dog cat cat dog"));
    ASSERT_FALSE(w.wordPattern("rqqr", "dog dog dog dog"));
}

TEST(Easy, distribute_candy)
{
    Leet::Easy::Candies c;

    auto arr = std::vector<int>{1, 1, 2, 2, 3, 3};
    ASSERT_EQ(c.distributeCandies(arr), 3);

    arr = {1, 1, 2, 3};
    ASSERT_EQ(c.distributeCandies(arr), 2);

    arr = {6, 6, 6, 6, 6};
    ASSERT_EQ(c.distributeCandies(arr), 1);
}

TEST(Easy, reverse_words)
{
    Leet::Easy::ReverseWords r;

    ASSERT_EQ(r.reverseWords("Let's take LeetCode contest"),
              "s'teL ekat edoCteeL tsetnoc");
    ASSERT_EQ(r.reverseWords("leetcodechallenge!"), "!egnellahcedocteel");
}

TEST(Easy, add_binary)
{
    Leet::Easy::AddBinary a;

    ASSERT_EQ(a.addBinary("11", "1"), "100");
    ASSERT_EQ(a.addBinary("1010", "1011"), "10101");
}

TEST(Easy, valid_palindrome)
{
    Leet::Easy::ValidPalindrome v;

    ASSERT_TRUE(v.isPalindrome("A man, a plan, a canal: Panama"));
    ASSERT_FALSE(v.isPalindrome("race a car"));
}

TEST(Easy, move_zeroes)
{
    Leet::Easy::MoveZeroes m;

    auto arr = std::vector<int>{0, 1, 0, 3, 12};
    auto zero = std::vector<int>{1, 3, 12, 0, 0};

    m.moveZeroes(arr);
    ASSERT_EQ(arr, zero);
}

TEST(Easy, reverse_string_2)
{
    Leet::Easy::ReverseString2 r;

    auto str{"abcdefg"};
    auto out{"bacdfeg"};

    ASSERT_EQ(r.reverseStr(str, 2), out);
}

TEST(Easy, isomorphic_string)
{
    Leet::Easy::IsomorphicStrings i;

    ASSERT_TRUE(i.isIsomorphic("egg", "add"));
    ASSERT_TRUE(i.isIsomorphic("paper", "title"));
    ASSERT_FALSE(i.isIsomorphic("foo", "bar"));
}

TEST(Easy, fibonacci_number)
{
    Leet::Easy::Fib f;

    ASSERT_EQ(f.fib(2), 1);
    ASSERT_EQ(f.fib(4), 3);
    ASSERT_EQ(f.fib(30), 832040);
}

TEST(Easy, base_seven)
{
    Leet::Easy::BaseSeven b;

    ASSERT_EQ(b.convertToBase7(100), "202");
    ASSERT_EQ(b.convertToBase7(-7), "-10");
}
