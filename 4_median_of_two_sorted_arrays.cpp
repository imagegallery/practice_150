class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int c1 = nums1.size();
        int c2 = nums2.size();

        int lo = 0, hi = c1;
        while(lo <= hi){
            int partition1 = (lo + hi)/ 2;
            int partition2 = (c1 + c2 + 1) / 2 - partition1;
            //cout << partition1 << " " << partition2 << endl;
            int maxLeft1 = (partition1 > 0) ? nums1[partition1 - 1] : INT_MIN;
            int maxLeft2 = (partition2 > 0) ? nums2[partition2 - 1] : INT_MIN;
            int minRight1 = (partition1 < c1) ? nums1[partition1] : INT_MAX;
            int minRight2 = (partition2 < c2) ? nums2[partition2] : INT_MAX;

            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
                if((c1 + c2) % 2 == 0){
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2.0;
                }else{
                    return (double)max(maxLeft1, maxLeft2);
                }
            }else if(maxLeft1 > minRight2)
                hi = partition1 - 1;
            else
                lo = partition1 + 1;
        }
        return -1;

    }
};