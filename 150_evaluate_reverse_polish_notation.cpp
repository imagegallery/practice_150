class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1 = 0, op2 = 0;
        for(auto i : tokens){
            if(i == "+"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push( op1 + op2);
            }else if(i == "-"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1 - op2);
            }else if(i == "*"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1 * op2);
            }else if(i == "/"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1 / op2);
            }
            else{
                st.push(stoi(i));
            }
        }
        
        return st.top();
    }
};