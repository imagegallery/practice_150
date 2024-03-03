class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> res(n+1);
        // res[0] = 0;
        // if(n == 0)
        //     return res;
        
        // while(n >= 1){
        //     int temp = n;
        //     int count = 0;
        //     while(n != 0){
        //         if(n & 1)
        //             count ++;
        //         n >>=1;
        //     }
        //     res[temp] = count;
        //     n = temp-1;
        // }
        // return res;
        vector<int> res(n+1, 0);
        //res[1] = 1;

        for(int i = 1; i <= n; i++){
            res[i] = res[i/2] + (i%2);
        }
        return res;

    }
};