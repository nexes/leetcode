#pragma once

namespace Leet
{
    void ltrim(std::string &s)
    {
        if (s.empty())
            return;
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](const char &c) { return !std::isspace(c); }));
    }

    void rtrim(std::string &s)
    {
        if (s.empty())
            return;
        // .base() accesses the underlying iterator. needed because this is a reverse iterator
        s.erase(std::find_if(s.rbegin(), s.rend(), [](const char &c) { return !std::isspace(c); }).base(), s.end());
    }

    std::vector<std::string> split(std::string &s)
    {
        if (s.empty())
            return {};
        auto ss = std::istringstream{s};

        // istream_iterator will skip whitespace on its own. We get the functionality for free!
        return std::vector(std::istream_iterator<std::string>{ss},
                           std::istream_iterator<std::string>());
    }

    template <typename T>
    void reverse(std::vector<T> &v)
    {
        if (v.empty())
            return;
        auto left = v.begin();
        auto right = v.end() - 1;

        for (int i = 0; i < v.size() / 2; i++)
            std::iter_swap(left++, right--);
    }
} // namespace Leet
