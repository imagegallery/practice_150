class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > mp;
        int n =paths.size();
        for(int i = 0; i < n; i++){
            stringstream path(paths[i]);
            string root;
            string files;
            getline(path, root, ' ');
            while(getline(path, files, ' ')){
                string filename = root + "/" + files.substr(0, files.find('('));
                //substr starting from '(' + 1 to ')' - '(' - 1
                int start = files.find('(');
                int end = files.find(')');
                string content = files.substr(start + 1, end - start - 1);
                mp[content].push_back(filename);
            }
        }

        vector<vector<string>> res;
        for(auto file : mp){
            if(file.second.size() > 1){
                res.push_back(file.second);
            }
        }
        return res;
        
    }
};