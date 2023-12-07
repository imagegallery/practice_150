class MinStack {
    vector<pair<int, int>> st;
    int min_val;
public:
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
            min_val = INT_MAX;
        min_val = min(val, min_val);
        st.push_back(make_pair(val, min_val));
        return;
    }
    
    void pop() {
        st.pop_back();
        if(st.empty())
            min_val = INT_MAX;
        else
            min_val = st[st.size()-1].second;
        return;
    }
    
    int top() {
        int sz = st.size();
        pair p = st[sz-1];
        return p.first;
    }
    
    int getMin() {
        int sz = st.size();
        pair p = st[sz-1];
        return p.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */