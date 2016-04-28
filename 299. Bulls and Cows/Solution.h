#pragma once
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <algorithm>
using std::min;

class Solution {
public:
    string getHint(string secret, string guess) {
        //assert(secret.length() == guess.length());
        const int kRange = 10;
        auto As = 0, Bs = 0;
        int secret_num[kRange] = { 0 };
        int guess_num[kRange] = { 0 };
        auto len = secret.length();
        for (auto i = 0U; i < len; ++i) {
            if (secret[i] == guess[i]) {
                ++As;
            } else {
                secret_num[secret[i] - '0']++;
                guess_num[guess[i] - '0']++;
            }
        }
        for (auto i = 0; i < kRange; ++i) {
            Bs += min(secret_num[i], guess_num[i]);
        }
        ostringstream oss;
        oss << As << 'A' << Bs << 'B';
        return oss.str();
    }
};
