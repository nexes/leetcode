#pragma once

#include <string>
#include <vector>

namespace Leet::Easy {
    // Write a program that outputs the string representation of numbers
    // from 1 to n. But for multiples of three it should output “Fizz” instead
    // if the number and for the multiples of five output “Buzz”. For numbers
    // which are multiples of both three and five output “FizzBuzz”.

    // Example:
    // n = 15,
    // Return:
    // [
    //     "1",
    //     "2",
    //     "Fizz",
    //     "4",
    //     "Buzz",
    //     "Fizz",
    //     "7",
    //     "8",
    //     "Fizz",
    //     "Buzz",
    //     "11",
    //     "Fizz",
    //     "13",
    //     "14",
    //     "FizzBuzz"
    // ]
    struct FizzBuzz
    {
        std::vector<std::string> fizzBuzz(int n)
        {
            auto fizz_buzz = std::vector<std::string>{};

            for (int i = 1; i <= n; i++) {
                if (i % 3 == 0 && i % 5 == 0)
                    fizz_buzz.push_back("FizzBuzz");
                else if (i % 3 == 0)
                    fizz_buzz.push_back("Fizz");
                else if (i % 5 == 0)
                    fizz_buzz.push_back("Buzz");
                else
                    fizz_buzz.push_back(std::to_string(i));
            }

            return fizz_buzz;
        }
    };
}  // namespace Leet::Easy
