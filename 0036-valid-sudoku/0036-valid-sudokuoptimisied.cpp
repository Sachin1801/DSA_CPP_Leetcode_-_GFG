class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowset;
        unordered_map<int, unordered_set<char>> colset;
        vector<vector<unordered_set<char>>> squareset(3,vector<unordered_set<char>>(3));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (rowset[i].find(board[i][j]) != rowset[i].end() ||
                    colset[j].find(board[i][j]) != colset[j].end() ||
                    squareset[i / 3][j / 3].find(board[i][j]) !=
                        squareset[i / 3][j / 3].end()) {
                    return false;
                }
                rowset[i].insert(board[i][j]);
                colset[j].insert(board[i][j]);
                squareset[i / 3][j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};