class Solution {
public:
    int maxProfit1(vector<int>& prices) {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75957/an-8ms-c-dp-solution-easy-to-understand

    /*

        sell[i]=max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
buy[i-1]+prices[i] represents buy the stock on day i-1 and sell it on day i; sell[i-1]-prices[i-1]+prices[i] represents you didn't sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).

buy[i]=max(sell[i-2]-prices[i], buy[i-1]+prices[i-1]-prices[i]);
sell[i-2]-prices[i] means sold the stock on day i-2 and buy it on day i (day i-1 is cooldown). buy[i-1]+prices[i-1]-prices[i] means you didn't buy the stock on day i-1 but buy it on day i.

    */

        int n = prices.size();
        int res= 0;   
        vector<int> sell(n, 0);
        vector<int> buy(n, 0);
        buy[0] = -prices[0];
        for(int i = 1;i < n; i++){
            sell[i] = max(buy[i-1] + prices[i], sell[i-1] - prices[i-1] + prices[i]);
            if(res < sell[i])
                res = sell[i];
            if(i==1)
                buy[1] = buy[0] + prices[0] - prices[1];
            else
             buy[i] = max(sell[i-2] - prices[i], buy[i-1] + prices[i-1] - prices[i]);
        }
        return res;
    }
    int util(int index, bool buying, vector<int> &prices, unordered_map<string, int> &dp){
        if(index >= prices.size())
            return 0;
        
        string key = to_string(index) + to_string(buying);
        if (dp.find(key) != dp.end())
            return dp[key];
        
        int cooldown = util(index+1, buying, prices, dp);
        if(buying){
            int buy = util(index+1, !buying, prices, dp) - prices[index];
            dp[key] = max(cooldown, buy );
        }else{
            int sell = util(index+2, !buying, prices, dp) + prices[index];
            dp[key] = max(cooldown, sell );   
        }
        return dp[key];
    }
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> dp;
        return util(0, true, prices, dp );
    }
};