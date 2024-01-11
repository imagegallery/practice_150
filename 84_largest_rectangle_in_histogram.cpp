class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0, area = 0;
        stack<pair<int, int> > st; //index, height
        st.push(make_pair(0, heights[0]));
        pair<int, int> temp;
        for(int i = 1; i < n; i++){
            if(!st.empty() && st.top().second > heights[i]){
                while(!st.empty() && st.top().second > heights[i]){
                    temp = st.top();
                    st.pop();
                    area = (i - temp.first) * temp.second;
                    if(area > maxArea)
                        maxArea = area;
                }
                st.push(make_pair(temp.first, heights[i]));
            }else{
                st.push(make_pair(i, heights[i]));
            }
        }
        while(!st.empty()){
            temp = st.top();
            st.pop();
            area = (n - temp.first) * temp.second;
            if(area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};