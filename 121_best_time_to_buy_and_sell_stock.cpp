class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int n = prices.size();
        if(n <= 1)
            return 0;
        int buy = prices[0];
        for(auto sell: prices){
            if(sell < buy)
                buy = sell;
            else
                maxP = max(maxP, sell-buy);
            
        }
        
        return maxP;
    }
};
