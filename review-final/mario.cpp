// Write a C++ program for the problem:
// Mario stands in a MAZE which is a grid of N x M cells including free cells
// and obstacle cells. The MAZE is represented by 0-1 matrix a_{NxM}  in which
// a_{ij}= 1 means that the cell (i,j)  (row i and column j) is an obstacle, and
// ai,j = 1 means that the cell row i and column j is an empty cell. Mario
// executes a sequence of movements including: move-up: move from a current cell
// (r,c) to the cell (r-1,c) if this cell is an empty cell within the MAZE,
// otherwise, Mario does nothing (he stands at the current cell). move-down:
// move from a current cell (r,c) to the cell (r+1,c) if this cell is an empty
// cell within the MAZE, otherwise, Mario does nothing (he stands at the current
// cell). move-left: move from a current cell (r,c) to the cell (r,c-1) if this
// cell is an empty cell within the MAZE, otherwise, Mario does nothing (he
// stands at the current cell). move-right: move from a current cell (r,c) to
// the cell (r,c+1) if this cell is an empty cell within the MAZE, otherwise,
// Mario does nothing (he stands at the current cell). Find the last cell that
// Mario stands after the movements. Input Line 1: contains N, M, r, c in which
// N and M are numbers of rows and columns of the MAZE; r, c are the row and
// column indices of the cell that Mario stands at the beginning (1 <= r <= N <=
// 1000, 1 <= c <= M <= 1000) Line i+1 (i = 1, 2, ..., N): contains the ith row
// of the matrix a Subsequence lines (terminated by a line containing #), each
// line contains a string of types: move-up, move-down, move-left, move-right
// Output
// Write the row and column indices (separated by a SPACE character) of the last
// cell that Mario stands after the movements.
// Example Input
// 5 5 5 3 0 0 0 0 0
// 0 0 0 0 0
// 0 1 1 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// move-up
// move-up
// move-left
// move-up
// move-left
// move-up
// #
// Output
// 3 1

#include <iostream>
using namespace std;

int main() {
    int N, M, r, c;
    cin >> N >> M >> r >> c;

    int a[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> a[i][j];
    }

    string s;
    while (cin >> s) {
        if (s == "move-up") {
            if (r > 1 && a[r - 2][c - 1] == 0) {
                r--;
            }
        } else if (s == "move-down") {
            if (r < N && a[r][c - 1] == 0) {
                r++;
            }
        } else if (s == "move-left") {
            if (c > 1 && a[r - 1][c - 2] == 0) {
                c--;
            }
        } else if (s == "move-right") {
            if (c < M && a[r - 1][c] == 0) {
                c++;
            }
        } else {
            break;
        }
    }

    cout << r << " " << c << endl;

    return 0;
}