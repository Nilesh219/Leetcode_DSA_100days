class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = *max_element(begin(nums), end(nums));
        int n = nums.size();
        int i = 0, j = 0;
        int maxcount = 0;
        long long ans = 0;
        
        while(j < n){
            if(nums[j] == maxele){
                maxcount++;
            }
            while(maxcount >= k){
                ans += n-j;
                
                if(nums[i] == maxele){
            
                    maxcount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};