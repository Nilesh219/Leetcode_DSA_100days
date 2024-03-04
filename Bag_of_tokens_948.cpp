class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxscore = 0;
        int n = tokens.size();
        sort(begin(tokens),end(tokens));
        int i = 0, j = n-1;
        while(i<=j){
            if(power>= tokens[i]){
                power-=tokens[i];
                score+=1;
                i++;
                maxscore = max(maxscore, score);
            }
            else if(score>=1){
                power+=tokens[j];
                score-=1;
                j--;
            }
            else{
                return maxscore;
            }
        }
        return maxscore; // Added return statement outside of the while loop
    }
};
