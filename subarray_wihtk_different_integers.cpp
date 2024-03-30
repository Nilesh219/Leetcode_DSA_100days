class Solution {
public:
    int slidingWindow(vector<int>& nums, int k){
        unordered_map <int, int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        
        while(j < n){

            mp[nums[j]]++;
            while(mp.size() > k){
                //shrink window of i 
                mp[nums[i]]--;
                if(mp[nums[i] == 0]){
        
                    mp.erase(nums[i]);
                }
                i++;
            }
            count =+ (j-i+1);
            j++;
        }
        
        
    }
        
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};