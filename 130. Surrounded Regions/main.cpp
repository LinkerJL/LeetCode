#include "Solution.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    Solution s;
    vector<vector<char>> v ={ {'O'} };
    s.solve(v);
    for (auto& vv : v) {
        for (auto& c : vv) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}