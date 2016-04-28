#pragma once
#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string getHint(string secret, string guess) {
        //assert(secret.length() == guess.length());
        const int kRange = 10;
        auto As = 0, Bs = 0;
        int cache[kRange] = { 0 };
        auto len = secret.length();
        for (auto i = 0U; i < len; i++) {
            if (secret[i] == guess[i]) {
                As++;
                continue;
            }
            Bs += (cache[secret[i] - '0'] > 0);
            cache[secret[i] - '0']--;
            Bs += (cache[guess[i] - '0'] < 0);
            cache[guess[i] - '0']++;
        }
        return to_string(As) + 'A' + to_string(Bs) + 'B';
    }
};
