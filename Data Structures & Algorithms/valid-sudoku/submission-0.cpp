class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> boxes(9);

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char x=board[r][c];
                if(x=='.'){
                    continue;
                }

                int box=(r/3)*3+(c/3);

                if(rows[r].count(x) || cols[c].count(x) || boxes[box].count(x)){
                    return false;
                }

                rows[r].insert(x);
                cols[c].insert(x);
                boxes[box].insert(x);
            }
        }

        return true;
    }
};
