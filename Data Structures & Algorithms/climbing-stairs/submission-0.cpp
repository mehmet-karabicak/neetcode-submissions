class Solution {
private:
    unordered_map<int, int> map_;

public:
    int climbStairs(int n) {
        if(map_.count(n)) return map_[n];
        if(n==1) return 1;
        if(n==2) return 2;

        int ret = climbStairs(n-1) + climbStairs(n-2);

        map_[n] = ret;

        return ret;
    }
};
