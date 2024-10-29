#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Leet::Medium {
    // Design an algorithm to encode a list of strings to a string. The encoded string is
    // then sent over the network and is decoded back to the original list of strings.

    // Machine 1 (sender) has the function:

    // string encode(vector<string> strs) {
    //   // ... your code
    //   return encoded_string;
    // }
    // Machine 2 (receiver) has the function:
    // vector<string> decode(string s) {
    //   //... your code
    //   return strs;
    // }
    // So Machine 1 does:

    // string encoded_string = encode(strs);
    // and Machine 2 does:

    // vector<string> strs2 = decode(encoded_string);
    // strs2 in Machine 2 should be the same as strs in Machine 1.

    // Example 1:
    // Input: dummy_input = ["Hello","World"]
    // Output: ["Hello","World"]
    // Explanation:
    // Machine 1:
    // Codec encoder = new Codec();
    // String msg = encoder.encode(strs);
    // Machine 1 ---msg---> Machine 2
    // Machine 2:
    // Codec decoder = new Codec();
    // String[] strs = decoder.decode(msg);

    // Example 2:
    // Input: dummy_input = [""]
    // Output: [""]

    // Constraints:
    // 1 <= strs.length <= 200
    // 0 <= strs[i].length <= 200
    // strs[i] contains any possible characters out of 256 valid ASCII characters.
    struct EncodeDecodeStr
    {
        // Encodes a list of strings to a single string.
        string encode(vector<string>& strs)
        {
            string encoded = "";

            for (string str : strs) {
                encoded.append(std::to_string(str.length()) + "#" + str);
            }

            return encoded;
        }

        // Decodes a single string to a list of strings.
        vector<string> decode(string s)
        {
            vector<string> decoded;
            int i = 0;

            while (i < s.length()) {
                int j = i;
                int len = 0;

                while (s[j] != '#')
                    j++;
                len = std::stoi(s.substr(i, j));
                i = j + 1;

                decoded.push_back(s.substr(i, len));
                i += len;
            }

            return decoded;
        }
    };
}  // namespace Leet::Medium