class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        
        for(auto it: nums){
            sum += it;
            maxsum = max(sum, maxsum);
            if(sum<0) sum=0;
        }
        return maxsum;
    }
};