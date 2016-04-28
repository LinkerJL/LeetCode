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
        int secret_num[kRange] = { 0 };
        int guess_num[kRange] = { 0 };
        auto len = secret.length();
        for (auto i = 0U; i < len; i++) {
            if (secret[i] == guess[i]) {
                As++;
                continue;
            }
            if (guess_num[secret[i] - '0'] > 0) {
                guess_num[secret[i] - '0']--;
                Bs++;
            } else {
                secret_num[secret[i] - '0']++;
            }
            if (secret_num[guess[i] - '0'] > 0) {
                secret_num[guess[i] - '0']--;
                Bs++;
            } else {
                guess_num[guess[i] - '0']++;
            }
        }
        return to_string(As) + 'A' + to_string(Bs) + 'B';
    }
};
