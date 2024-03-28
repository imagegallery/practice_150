class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0, erow = m-1, scol = 0, ecol = n-1;
        vector<int> res;
        int i = 0, j = 0;
        int direction = 1;
        while(srow <= erow && scol <= ecol){
            //top row
            if(direction == 1){
                for(int p = scol; p <= ecol; p++)
                    res.push_back(matrix[srow][p]);
                srow++;
                direction = 2;
            }
            else if(direction == 2){ 
            //right col
                for(int p = srow; p <= erow; p++)
                    res.push_back(matrix[p][ecol]);
                ecol--;
                direction = 3;
            }
            else if(direction == 3){
                for(int p = ecol; p >= scol; p--)
                    res.push_back(matrix[erow][p]);
                erow--;
                direction = 4;
            }
            else if(direction == 4){
                for(int p = erow; p >= srow; p --)
                    res.push_back(matrix[p][scol]);
                    direction = 1;
                scol++;
            } 
        }
        return res;
    }
};