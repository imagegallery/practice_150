class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n)
            return -1;
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[n-1];
        //int res = right;
        while(left <= right){
            int mid = (left + right)/2;
            //cout << "mid is: " << mid << endl;
            long long sum = 0;
            for(int i = 0; i < n; i++){
                sum += ceil(1.0*piles[i]/mid);
                //cout << "sum is: " << sum << endl;
            }
            if(sum <= h){
                //res = min(res, mid);
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};