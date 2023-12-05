class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0);
        int sz1 = s1.size();
        int sz2 = s2.size();
        
        for(auto a:s1){
            count1[a - 'a'] ++;
        }
        vector<int> count2(26, 0);
        int i = 0, j = 0;
        while(j < sz2){
            count2[s2[j] - 'a'] ++;
            if(j-i+1 == sz1){
                if(count1 == count2)
                    return true;
            }
            if(j-i+1 < sz1)
                j++; //increment end as window is < of s1 size
            else{
                count2[s2[i]-'a'] --;
                i++;
                j++;
            }
        }
        return false; 
    }
};