class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int num: asteroids){
            if(num>0){
                st.push(num);
            } else{
                while(!st.empty() and abs(num)>st.top() and st.top()>0){
                    st.pop();
                }
                if(!st.empty() and abs(num)==st.top() and st.top()>0){
                    st.pop();
                } else if(st.empty() or st.top()<0){
                    st.push(num);
                }
            }
        }

        vector<int> result;

        while(!st.empty()){
            result.insert(result.begin()+0, st.top());
            st.pop();
        }

        return result;
    }
};