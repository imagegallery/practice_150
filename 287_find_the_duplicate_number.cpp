class Solution {
public:
    //By modifying the given array
    // int findDuplicate(vector<int>& nums) {
    //     int i = 0;
    //     while(nums[i] > 0){
    //         int temp = nums[i];
    //         nums[i] = -nums[i];
    //         i = temp;
    //     }
    //     return i;
    // }
    //without modifying the givenn array
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];

        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        fast = nums[0];
        while(fast != slow){
            slow= nums[slow];
            fast = nums[fast];
        } 
        return slow;
    }
};