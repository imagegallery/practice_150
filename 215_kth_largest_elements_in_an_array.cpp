class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
        //another sol
        // priority_queue<int, vector<int>, greater<int> > pq;
        // for(auto i: nums){
        //     pq.push(i);
        //     if(pq.size() > k)
        //         pq.pop();
        // }
        
        // return pq.top();
    }
};