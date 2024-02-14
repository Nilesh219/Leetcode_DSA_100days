class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n  = nums.size();
        vector<int> ans(n,0);
        int postindex = 0, negaindex = 1; 
        for(int i= 0; i < n; i++){
            if(nums[i] < 0){
                ans[negaindex] = nums[i];
                negaindex += 2;
            }
            else{
                ans[postindex] = nums[i];
                postindex += 2;
            }

        }
        return ans;
    }
};