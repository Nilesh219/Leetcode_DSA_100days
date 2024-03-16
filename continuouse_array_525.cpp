class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxcount = 0;

        int n = nums.size();

        unordered_map <int, int> mp;

        mp[0] = -1;

        int result = 0;

        for(int i  =0; i<n; i++){
            maxcount += (nums[i] == 1) ? 1 : -1;

            if(mp.find(maxcount) != mp.end()){
                result = max(result, i - mp[maxcount]);
            }
            else{
                mp[maxcount] = i;
            }
        }
        return result;
    }
};