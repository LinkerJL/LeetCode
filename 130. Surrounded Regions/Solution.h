#pragma once
#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <utility>
using std::pair;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int height = board.size();
        if (!height) {
            return;
        }
        int width = board[0].size();
        if (!width) {
            return;
        }
        queue<Pos> q;
        // top & bottom
        for (int i = 0; i < width; i++) {
            if (board[0][i] == O) {
                q.push({ 0, i });
            }
            if (board[height - 1][i] == O) {
                q.push({ height - 1, i });
            }
        }
        // left & right
        for (int i = 1; i < height - 1; i++) {
            if (board[i][0] == O) {
                q.push({ i, 0 });
            }
            if (board[i][width - 1] == O) {
                q.push({ i, width - 1 });
            }
        }
        breadthFirstSearch(board, q);
        for (auto& row : board) {
            for (auto& point : row) {
                if (point == O) {
                    point = X;
                } else if (point == B) {
                    point = O;
                }
            }
        }
    }
private:
    typedef pair<int, int> Pos;
    enum { O='O', X='X', B='B' };
    static void breadthFirstSearch(vector<vector<char>>& board, queue<Pos>& q) {
        static const Pos move[4] ={ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        int height = board.size();
        int width = board[0].size();
        while (!q.empty()) {
            Pos p = q.front();
            q.pop();
            board[p.first][p.second] = B;
            for (auto& m : move) {
                Pos new_p(p.first + m.first, p.second + m.second);
                // ignore the edges
                if (new_p.first <= 0 || new_p.first >= height - 1 ||
                    new_p.second <= 0 || new_p.second >= width - 1) {
                    continue;
                }
                if (board[new_p.first][new_p.second] == O) {
                    q.push(new_p);
                }
            }
        }
    }
};
