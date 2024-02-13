class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ck = INT_MIN;
        int life = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++ ){
            if(ck == nums[i])
                life++;
            else if(life == 0){
                ck = nums[i];
                life = 1;
            }
            else life--;
        }
        return ck;
    }
};