#pragma once

#include <string>
#include <vector>

namespace Leet::Medium
{
    // Given two non-negative integers num1 and num2 represented as strings, return the product
    // of num1 and num2, also represented as a string.

    // Example 1:
    // Input: num1 = "2", num2 = "3"
    // Output: "6"

    // Example 2:
    // Input: num1 = "123", num2 = "456"
    // Output: "56088"

    // Note:
    // The length of both num1 and num2 is < 110.
    // Both num1 and num2 contain only digits 0-9.
    // Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    // You must not use any built-in BigInteger library or convert the inputs to integer directly.
    struct MultiplyString
    {
        // this works but I don't like it!
        std::string multiply(std::string num1, std::string num2)
        {
            if (num1.empty() || num2.empty())
                return "";

            if (num1 == "0" || num2 == "0")
                return "0";

            int num1_len = num1.size();
            int num2_len = num2.size();
            std::string output;
            std::vector<int> prod_vec;
            int carry = 0;
            int temp;
            int a;
            int b;
            int l = 1;
            int k = -1;

            for (int i = num1_len - 1; i >= 0; i--)
            {
                a = num1[i] - '0';
                carry = 0;

                if (prod_vec.size() > 0)
                    k = prod_vec.size() - 1 - l++;

                for (int j = num2_len - 1; j >= 0; j--)
                {
                    b = num2[j] - '0';
                    temp = (a * b + carry);

                    if (k < 0)
                        prod_vec.emplace(prod_vec.begin(), temp % 10);
                    else
                        prod_vec[k--] += temp % 10;

                    carry = temp / 10;
                }

                if (carry > 0)
                    prod_vec.emplace(prod_vec.begin(), carry);
            }

            for (int i = prod_vec.size() - 1; i >= 0; i--)
            {
                if (prod_vec[i] > 9)
                {
                    int c = prod_vec[i] / 10;
                    prod_vec[i] = prod_vec[i] % 10;

                    if (i > 0)
                        prod_vec[i - 1] += c;
                    else
                        prod_vec.emplace(prod_vec.begin(), c);
                }
            }

            for (auto e : prod_vec)
                output.append(std::to_string(e));

            return output;
        }
    };
} // namespace Leet::Medium
