class Solution {
public:
    int maxDepth(string s) {
        int openbracket = 0;
        int n = s.length();
        int result = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                openbracket++;
            
            else if(s[i] == ')')
                openbracket--;
            
            result = max(result, openbracket);
        }
        
        return result;
        
    }
};
