class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int count = 0;
        // while(n > 0){
        //     if(n & 1)
        //         count ++;
        //     n = n >> 1;
        //     //cout << n <<endl;
        // }
        // return count == 1;
        if(n <=0 )  return false;
        //cout << n << " " << n-1 <<  " " << (n & (n-1)) << endl;
        return (n & (n-1)) == 0;
    }
};