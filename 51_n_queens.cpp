//https://www.youtube.com/watch?v=i05Ju7AftcM

class Solution {
public:
    int X[4] = {1,1,-1,-1};
    int Y[4] = {1,-1,-1,1};

    void fill_adjacent(int x, int y, int n, vector<vector<bool>> &visited){
        for(int i = 0; i < n; i++){
            visited[i][y] = true;
            visited[x][i] = true;
        } 
        for(int i = x + X[0], j = y + Y[0]; i < n && j < n; i++, j++)
            if(i >= 0 && i < n && j >= 0 && j < n)
                visited[i][j] = true;

        for(int i = x + X [1], j = y + Y[1]; i < n && j >= 0; i++, j--)
            if(i >= 0 && i < n && j >= 0 && j < n)
                visited[i][j] = true;

        for(int i = x + X [2], j = y + Y[2]; i >= 0 && j >= 0; i--, j--)
            if(i >= 0 && i < n && j >= 0 && j < n)
                visited[i][j] = true;

        for(int i = x + X [3], j = y + Y[3]; i >= 0 && j < n; i--, j++)
            if(i >= 0 && i < n && j >= 0 && j < n)
                visited[i][j] = true;
    }
    void util1(int n, vector<vector<string> > &res, vector<string> temp, 
            vector<vector<bool>> visited, int x, int y, int st){ //assume i is 0, j is coming for col
        if(visited[x][y])
            return;
        if(st == n){
            temp[x][y] =  'Q';
            res.push_back(temp);
            return;
        }
        fill_adjacent(x, y, n, visited);
        temp[x][y] = 'Q';
        
        for(int i= 0; i < n ;i++){
            util1(n, res, temp, visited, x+1, i, st+1);
        }
        return;  
    }                                                                                 
    
    //                                                                                   \
    //                                                                                    \
    //filling col-wise, and run for all rows and check if we have queen in left   <-----
    //                                                                                    /
    //                                                                                   /
    void util(int n, vector<vector<string> > &res, vector<string> &board, vector<int> &leftR, 
                    vector<int> &upperD, vector<int> &lowerD, int col )
    {
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(leftR[row] == 0 && upperD[n-1+col-row] ==0 && lowerD[col+row] == 0){
                board[row][col] = 'Q';
                leftR[row] = 1;
                upperD[n-1+col-row] = 1;
                lowerD[col+row] = 1;
                util(n, res, board, leftR, upperD, lowerD, col+1);
                board[row][col] = '.';
                leftR[row] = 0;
                upperD[n-1+col-row] = 0;
                lowerD[col+row] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<string> > res;
        // vector<string> temp(n, string(n,'.'));
        // vector<vector<bool>> visited(n, vector<bool>(n, false));

        // for(int i = 0; i < n; i++){
        //     temp[0][i] = 'Q';
        //     util1(n, res, temp, visited, 0, i, 1); 
        //     temp[0][i] = '.';
        // }

        vector<vector<string> > res;
        vector<string> board(n, string(n,'.'));

        vector<int> leftR(n, 0);
        vector<int> upperD(2*n-1, 0);
        vector<int> lowerD(2*n-1, 0);        
        util(n, res, board, leftR, upperD, lowerD, 0);
        
        return res;
    }
};