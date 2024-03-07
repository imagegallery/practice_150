class Solution {
public:
    bool checkValidString(string s) {
        //time: O(n), memory : O(1)
        int n = s.size();
        int open = 0, close = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == '(' || s[i] == '*'){
                open ++;
            }else
                open --;

            if(s[n-1-i] == ')' || s[n-1-i] == '*')
                close ++;
            else 
                close--;
            if(open < 0 || close < 0)
                return false;
        }
        
        return true;

        //time: O(n), memory : O(n)
        // stack<int> open, star;
        // for (int i = 0; i < n; i++){
        //     if(s[i] == '('){
        //         open.push(i);
        //     }else if(s[i] == '*'){
        //         star.push(i);
        //     }else{
        //         if(!open.empty())
        //             open.pop();
        //         else if(!star.empty())
        //             star.pop();
        //         else
        //             return false;
        //     }
        // }

        // while(!open.empty()){
        //     if(star.empty())
        //         return false;
        //     else if(open.top() < star.top()){
        //         open.pop();
        //         star.pop();
        //     }else
        //         return false;
        // }
        // return true;

    }
};