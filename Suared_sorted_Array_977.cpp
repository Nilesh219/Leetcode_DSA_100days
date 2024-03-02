class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int>output(nums.size(),0);
        
        for(int i = nums.size()-1; i >= 0; i--){
            if(abs(nums[left]) > nums[right]){
                output[i] = nums[left]*nums[left];
                left++;
            }
            else{
                output[i] = nums[right]*nums[right];
                right--;
            }
            
        }
        return output;
        
    }
};