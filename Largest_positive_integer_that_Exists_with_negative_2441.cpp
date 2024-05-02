class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maxpos = -1;
        for(int i =0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] == -nums[j] && abs(nums[i]) > maxpos){
                    maxpos = abs(nums[i]);
                }
             
            }
        }      
       return maxpos;
    }
};