#pragma once
#include <vector>
using std::vector;
#include <utility>
using std::pair;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        height_ = board.size();
        if (!height_) {
            return;
        }
        width_ = board[0].size();
        if (!width_) {
            return;
        }
        // top & bottom
        for (int i = 0; i < width_; i++) {
            if (board[0][i] == O) {
                board[0][i] = B;
                depthFirstSearch(board, { 0, i });
            }
            if (board[height_ - 1][i] == O) {
                board[height_ - 1][i] = B;
                depthFirstSearch(board, { height_ - 1, i });
            }
        }
        // left & right
        for (int i = 1; i < height_ - 1; i++) {
            if (board[i][0] == O) {
                board[i][0] = B;
                depthFirstSearch(board, { i, 0 });
            }
            if (board[i][width_ - 1] == O) {
                board[i][width_ - 1] = B;
                depthFirstSearch(board, { i, width_ - 1 });
            }
        }
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
    int height_;
    int width_;
    void depthFirstSearch(vector<vector<char>>& board, Pos p) {
        static const Pos move[4] ={ { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
        for (auto& m : move) {
            Pos new_p(p.first + m.first, p.second + m.second);
            if (new_p.first <= 0 || new_p.first >= height_ - 1 ||
                new_p.second <= 0 || new_p.second >= width_ - 1) {
                continue;
            }
            if (board[new_p.first][new_p.second] == O) {
                board[new_p.first][new_p.second] = B;
                depthFirstSearch(board, new_p);
            }
        }
    }
};
