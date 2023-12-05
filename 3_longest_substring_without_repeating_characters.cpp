class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sol 1 but it takes longer to execute
        // int sz = s.size();
        // if(sz == 0)
        //     return 0;
        // int l = 0, r = 1;
        // int maxLen = 1;
        // string str = "";
        // str += s[l];
        // int start = l;
        // while(l < r && r < sz){
        //     auto index = str.find(s[r]);
        //     if(index > str.size()){
        //         str += s[r];
        //         r++;
        //         maxLen = max(maxLen, r-l);
        //     }
        //     else{
        //         start = l;
        //         l = (int)index+1+start;
        //         if(l == r)
        //             str = s[r];
        //         else
        //             str = str.substr(index+1)+s[r];
        //         r++;
        //     }
        // }
        // return maxLen;

        vector<int> chars(128, -1);
        //int chars[128];
        //fill_n(chars, 128, -1); 
        int st = 0, maxL = 0;
        for(int e = 0; e < s.size(); e++){
            char ch = s[e];
            if(chars[ch] >= st)
                st = chars[ch]+1;
            chars[ch] = e;
            maxL = max(maxL, e-st+1);
        }
        return maxL;
    }
};