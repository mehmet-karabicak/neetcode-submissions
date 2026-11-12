class Solution {
public:
    bool isValid(const std::string &expression)
    {
        std::stack<char> my_stack;

        char opening_symbols[3] = {'(', '[', '{'};
        char closing_symbols[3] = {')', ']', '}'};

        for (char c : expression){ 
            bool is_opening = false;
            for (int i=0; i<3; ++i){
                if (c==opening_symbols[i]){
                    is_opening = true;
                    my_stack.push(closing_symbols[i]);
                    break;
                }
            }

            if (!is_opening){
                if (my_stack.empty()){
                    return false;
                }
                
                char top_stack = my_stack.top();
                if (c!=top_stack){
                    return false;
                } else {
                    my_stack.pop();
                }
            }
        }

        if (!my_stack.empty()){ //if there are unmatched characters, false
            return false;
        }

        return true;
    }
};
