//Took less time 
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  //minheap
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > kth)
            pq.pop();
        return pq.top();
        
    }
};

//compaired to this
class KthLargest {
public:
    vector<int> arr;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        nth_element(arr.begin(), arr.begin() + kth-1, arr.end(), std::greater<int>());
        return arr[kth-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */