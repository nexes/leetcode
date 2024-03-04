#include <algorithm>
#include <vector>

namespace Leet::Medium {
    struct BagOfTokens
    {
        int bagOfTokensScore(std::vector<int> &tokens, int power)
        {
            int score = 0;
            int max_score = 0;
            int l = 0;
            int r = tokens.size() - 1;

            std::sort(tokens.begin(), tokens.end());

            while (l <= r) {
                if (score == 0 && power < tokens[l])
                    break;

                if (power >= tokens[l]) {
                    // face-up
                    power -= tokens[l];
                    score++;
                    l++;
                    max_score = std::max(score, max_score);
                } else if (score >= 1) {
                    // face-down
                    power += tokens[r];
                    score--;
                    r--;
                }
            }

            return max_score;
        }
    };
}  // namespace Leet::Medium