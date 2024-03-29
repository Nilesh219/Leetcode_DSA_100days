class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> count(101); //unordered_map<int, int>mp;
        
        int maxFreq = 0;
        
        for(int &nums : nums){
            count[nums]++; //incresing the freq of num
            maxFreq = max(maxFreq, count[nums]);
        }
        
        int result = 0;
        
        for(int i = 0; i < 101; i++){
            if(count[i] == maxFreq ){
                result += maxFreq;
            }
        }
        return result;
        
    }
};