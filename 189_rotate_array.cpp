class Solution {
public:
    void reverse(vector<int>&nums, int i , int j ){
        while( i < j){
            swap(nums[i++] , nums[j--] );
        }
    }
    void rotate(vector<int>& nums, int k) {
        // sol 1 remove last k elements into another array, shift the remaining array and paste back the removed array
        // int n = nums.size();
        // if(k > n)
        //     k = k % n;
        // if(n == k)
        //     return;
        // cout << n << " and " << k << endl;
        // vector<int> temp(k, 0);
        // int index = k-1;
        // int i = n-1;
        // while(index >= 0){
        //     temp[index] = nums[i];
        //     index--;
        //     i--;
        // }
        // index = n-1;
        // for(int i = n-1-k; i>= 0; i--){
        //     nums[index] = nums[i];
        //     index--;
        // }
       
        // for(int i = 0; i < k; i++){
        //     nums[i] = temp[i];
        // }
        // return;

        //Sol 2, reverse first (n-k) elements, reverse last k elements, reverse whole array
        int n = nums.size();
        k = k % n;
        reverse(nums, 0,  n - k-1);
        reverse(nums, n -k, n-1);
        reverse(nums, 0, n-1);
    }
};