class Solution {
public:
    bool isMatch(unordered_map<char, int> s_map, unordered_map<char, int> t_map){
        for(auto t : t_map){
            //cout << t.first << " " << s_map[t.first] << " " << t.second << endl;
            if(s_map[t.first] < t.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;

        int m = s.size();
        int n = t.size();
        for(auto ch : t){
            t_map[ch] ++;
        }
        int start = 0, end = 0, minLen = INT_MAX;
        string minString = "", substring = "";
        for(int i = 0; i < m; i++){
            s_map[s[i]] ++;
            
            while(isMatch(s_map, t_map )){
                //cout << "start: " << start << " and end: " << end << endl; 
                
                //while(isMatch(s_map, t_map )){
                    substring = s.substr(start, i-start+1);
                    //cout << "substring is: " << substring << endl;
                    if(substring.size() < minLen ){
                        minLen = substring.size();
                        minString = substring;
                    }
                    s_map[s[start]] --;
                    start ++;  
                //}
            }
        }
        return minString;
    }
};