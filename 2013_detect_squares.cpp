/*
Solution 1: Given p1, try all points p3 (p1 and p3 form diagonal)

To compute count(p1):
We try all points p3 which together with p1 form the diagonal of non-empty square, it means abs(p1.x-p3.x) == abs(p1.y-p3.y) && abs(p1.x-p3.x) > 0
Since we have 2 points p1 and p3, we can form a square by computing the positions of 2 remain points p2, p4.
p2 = (p1.x, p3.y)
p4 = (p3.x, p1.y)
*/
class DetectSquares1 {
    //unordered_map<vector<int>, int> mp;
    map<vector<int>,int>mp;
    vector<vector<int>> lst;
public:
    DetectSquares1() { }
    
    void add(vector<int> point) {
        mp[point] +=1;
        lst.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        for(int i = 0; i < lst.size(); i++){
            vector<int> pt = lst[i];
            if(abs(pt[0] - x) != abs(pt[1] - y) || x == pt[0] || y == pt[1])
                continue;
            res += mp[{pt[0], y}] * mp[{x,pt[1]}];
        }
        return res;
    }
};
/*
Solution 2: Given p1, try all points p2 (same x-axis) then compute the positions of 2 remain points p3, p4

To compute count(p1):
We try all the points p2 which has the same x-axis with p1, it means p2.x = p1.x
Since we have 2 points p1 and p2, we can form a square by computing the positions of 2 remain points p3, p4.
Calculate sideLen = abs(p1.y - p2.y)
Case 1: p3, p4 points are in the left side of line p1p2
p3 = (p1.x - sideLen, p2.y)
p4 = (p1.x - sideLen, p1.y)
Case 2: p3, p4 points are in the right side of line p1p2
p3 = (p1.x + sideLen, p2.y)
p4 = (p1.x + sideLen, p1.y)
*/
class DetectSquares {
    //unordered_map<vector<int>, int> mp;
    map<vector<int>,int>cnt_map;
    map<int, vector<int>> mp;
public:
    DetectSquares() { }
    
    void add(vector<int> point) {
        mp[point[0]].push_back(point[1]);
        cnt_map[point] ++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        vector<int> possible_y = mp[x];
        for (auto y_dash : possible_y){
            if(y_dash == y)
                continue;
            
            //case 1: left side
            int len = abs(y - y_dash);
            int x3 = x - len, y3 = y;
            int x4 = x-len, y4 = y_dash; 
            res += cnt_map[{x3, y3}] * cnt_map[{x4,y4}];

            //case2: right side
            x3 = x + len, y3 = y;
            x4 = x + len, y4 = y_dash; 
            res += cnt_map[{x3, y3}] * cnt_map[{x4,y4}];
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */