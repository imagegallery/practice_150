class Solution {
public:
    int X[4] = {0, 1, 0, -1};
    int Y[4] = {1, 0, -1, 0};

    bool util(vector<vector<char>>& board, string word, int i, int j, int m, int n){
        if(!word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[0])  
            return false;
        char ch = board[i][j];
        board[i][j] = '*';
        word = word.substr(1); 
        for(int p = 0; p < 4; p ++){
            int new_i = i + X[p];
            int new_j = j + Y[p];
            if(util(board, word, new_i, new_j, m, n))
                return true;
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int k = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(util(board, word, i, j, m, n))
                    return true;
            }
        }
        return false;
    }
};