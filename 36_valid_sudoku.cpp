class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<int> row(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row[board[i][j]- '0'] == 0)
                        row[board[i][j] -'0'] = 1;
                    else
                        return false;
                }
            }
        }

        for(int i = 0; i < 9; i++){
            vector<int> col(10, 0);
            for(int j = 0; j < 9; j++){
                //cout << board[j][i] << endl;

                if(board[j][i] != '.'){
                    if(col[board[j][i] - '0'] == 0)
                        col[board[j][i] - '0'] = 1;
                    else
                        return false;
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j< 9; j += 3){
                vector<int> sq(10,0);
                for(int p = i; p < i + 3; p++){
                    for(int k = j; k < j + 3; k++){
                        //cout << p << " " << k<<endl;
                        if(board[p][k] != '.'){
                            if(sq[board[p][k] - '0'] == 0)
                                sq[board[p][k] - '0'] = 1;
                            else
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};