class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //sol1 using min heap
        int n = nums.size();
        if(n == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int a = pq.top();
        pq.pop();
        //cout << "a is: " << a << endl;
        int maxCount = 1, count = 1;
        while(!pq.empty()){
            int b = pq.top();
            pq.pop();
            //cout << "b is: " << b << endl;

            if(abs(b - a) == 1 ){
                count ++;

                if(maxCount < count)
                    maxCount = count;
            }else if(a == b){
                continue;
            }else{
                count = 1;
            }
            a = b;

        }
        return maxCount;
        // int n = nums.size();
        // set<int> s;
        // for(auto num: nums){
        //     s.insert(num);
        // }
        // int res = 0;
        // for(auto num: s){
        //     if(s.count(num-1) == 0){
        //        int a = num;
        //         int count = 1;
        //         while(s.count(a + 1) == 1){
        //             a++;
        //             count ++;
        //         }
        //         res = max(res, count);
        //     }
        // }
        // return res;
    }
};