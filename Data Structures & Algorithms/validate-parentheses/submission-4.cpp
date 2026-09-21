class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> validBrackets = {
            {')','('},
            {'}','{'},
            {']','['},
        };
        std::stack<char> bracketStack;

        for (int i = 0; i < s.length(); i++) {
            if (validBrackets.find(s[i]) != validBrackets.end()) {
                if (!bracketStack.empty() && bracketStack.top() == validBrackets[s[i]]) {
                    bracketStack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                bracketStack.push(s[i]);
            }
        }

        return bracketStack.empty();
    }
};
