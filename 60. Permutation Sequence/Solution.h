#pragma once
#include <string>
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        static int factorial[] ={ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        int m[9] ={ 0 };
        k--;
        for (int i = n - 1; i >= 1; i--) {
            m[i] = k / factorial[i];
            k = k % factorial[i];
        }
        string result;
        for (int i = 0; i < n; i++) {
            result += i + '1';
        }
        for (int i = 0; i < n - 1; i++) {
            int pos = m[n - 1 - i];
            if (pos) {
                char c = result[pos + i];
                result.erase(pos + i, 1);
                result.insert(i, 1, c);
            }
        }
        return result;
    }
};
