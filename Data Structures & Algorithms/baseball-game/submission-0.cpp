class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto op: operations){
            if(op=="C"){
                st.pop();
            } else if(op=="D"){
                st.push(2*st.top());
            } else if(op=="+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
            } else{
                st.push(stoi(op));
            }
        }

        int total = 0;
        while(!st.empty()){
            total+= st.top();
            st.pop();
        }
        return total;
    }
};