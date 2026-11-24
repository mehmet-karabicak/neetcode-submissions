class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n+1,0);

        for(int i=1; i<=n; i++){
            int count = 0;

            int m = i;

            while(m>0){
                count += (m & 1);
                m >>= 1;
            }

            vec[i] = count;
        }

        return vec;
    }
};
