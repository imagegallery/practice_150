class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size() -1;
        vector<int> ans (n+1, 0);
        st.push(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and temperatures[i] >= temperatures[st.top()])
                st.pop();
            
            if(!st.empty())
                ans[i] = st.top() - i;               
                    
            st.push(i);
        }
        return ans;
    }
};