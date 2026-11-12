class Solution {
public:
    int operation(int num1, char op, int num2){
        switch(op){
            case '+':
                return num1+num2;
                break;
            case '*':
                return num1*num2;
                break;
            case '-':
                return num1-num2;
                break;
            case '/':
                return num1/num2;
                break;
            default:
                break;       
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for(auto c: tokens){
            if (c.size() > 1 || isdigit(c[0])){
                int num = stoi(c);
                numbers.push(num);
            } else{
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();

                numbers.push(operation(num1, c[0], num2));
            }
        }

        return numbers.top();
    }
};
