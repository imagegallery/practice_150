class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for(auto ch: chars){
            mp[ch] += 1;
        }
        int n = words.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            bool flag = true;
            string word = words[i];
            unordered_map<char, int> word_mp;

            for(auto ch: word){
                if(word_mp[ch] + 1 > mp[ch])
                {
                    flag = false;
                    break;
                }
                word_mp[ch] += 1;
            }
            
            if(flag)
                sum += word.size();
        }
        return sum;
    }
};