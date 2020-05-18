#pragma once

#include <string>
#include <vector>

namespace Leet::Medium
{
    // Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
    // In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the
    // directory up a level. Note that the returned canonical path must always begin with a slash /, and there must be
    // only a single slash / between two directory names. The last directory name (if it exists) must not end with a
    // trailing /. Also, the canonical path must be the shortest string representing the absolute path.

    // Example 1:
    // Input: "/home/"
    // Output: "/home"
    // Explanation: Note that there is no trailing slash after the last directory name.

    // Example 2:
    // Input: "/../"
    // Output: "/"
    // Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

    // Example 3:
    // Input: "/home//foo/"
    // Output: "/home/foo"
    // Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

    // Example 4:
    // Input: "/a/./b/../../c/"
    // Output: "/c"

    // Example 5:
    // Input: "/a/../../b/../c//.//"
    // Output: "/c"

    // Example 6:
    // Input: "/a//b////c/d//././/.."
    // Output: "/a/b/c"
    struct Path
    {
        std::string simplifyPath(std::string path)
        {
            int len = path.length();
            char character;
            std::string name;
            std::vector<std::string> simple_path;

            for (int i = 1; i < len; i++)
            {
                character = path.at(i);

                while (character != '/' && i < len)
                {
                    name.push_back(character);
                    if (i + 1 < len)
                        character = path.at(i + 1);
                    i++;
                }

                if (name == "..")
                {
                    if (simple_path.size() > 0)
                        simple_path.pop_back();
                }
                else if (!name.empty() && name != "." && name != "/")
                {
                    simple_path.push_back(name);
                }

                name = "";
            }

            if (simple_path.size() == 0)
                return "/";

            for (auto &v : simple_path)
                name += "/" + v;

            return name;
        }

        std::string simplifyPath_better(std::string path)
        {
            std::string name;
            std::stringstream stream(path);
            std::vector<std::string> simple_path;

            // break it up per delim
            while (std::getline(stream, name, '/'))
            {
                if (name == "..")
                {
                    if (!simple_path.empty())
                        simple_path.pop_back();
                }
                else if (!name.empty() && name != "." && name != "/")
                {
                    simple_path.push_back(name);
                }

                name = "";
            }

            if (simple_path.empty())
                name = "/";

            for (auto &v : simple_path)
                name += "/" + v;

            return name;
        }
    };
} // namespace Leet::Medium
