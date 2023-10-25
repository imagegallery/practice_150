class Solution {
public:
    //n solution
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> dict;
        for(auto ch:s)
            dict[ch]++;
        
        for(auto ch:t){
            dict[ch]--;
        }
        for(auto it : dict){
            //cout << it->first << " " << it->second << endl;
            if(it.second > 0)
                return false;
        }
        return true;
    }

    //nlogn solution

    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size())
    //         return false;
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());

    //     for (int i = 0; i < s.size(); i++){
    //         if(s[i] != t[i])
    //             return false;
    //     }
    //     return true;
    // }
};