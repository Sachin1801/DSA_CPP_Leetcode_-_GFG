class Solution {
private:
    pair<int, int> intToPos(int square, int n) {

        int row = (square-1) / n;
        int col = (square -1)%n;
        if(row %2 !=0){
            col = n-1-col;
        } 


        return {row,col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        reverse(board.begin(), board.end());
        queue<pair<int, int>> q;
        q.push({1, 0});
        unordered_set<int> visited;
        while (!q.empty()) {
            pair<int, int> p = q.front(); //[ square, moves]
            q.pop();

            for (int i = 1; i < 7; i++) {
                int nextSquare = p.first + i;
                pair<int, int> rowCol = intToPos(nextSquare,n);

                if (board[rowCol.first][rowCol.second] != -1) {
                    nextSquare = board[rowCol.first][rowCol.second];
                }
                if (nextSquare == n * n) {
                    return p.second + 1;
                }
                if (visited.find(nextSquare) == visited.end()) {
                    visited.insert(nextSquare);
                    q.push({nextSquare, p.second + 1});
                }
            }
        }
        return -1;
    }
};

// queue ( 4,5,6,7,15,4,5,6,7,8,9 )