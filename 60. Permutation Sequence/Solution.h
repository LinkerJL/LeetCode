#pragma once
#include <string>
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        static int factorial[] ={ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        string result(n, '1');
        for (int i = 1; i < n; i++) {
            result[i] += i;
        }
        k--;
        for (int i = 0; i < n - 1; i++) {
            int pos = k / factorial[n - 1 - i];
            k = k % factorial[n - 1 - i];
            if (pos) {
                char c = result[pos + i];
                for (int j = pos + i; j > i; j--) {
                    result[j] = result[j - 1];
                }
                result[i] = c;
            }
        }
        return result;
    }
};
