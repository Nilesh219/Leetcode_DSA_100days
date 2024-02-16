class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> um;

        for(auto i: arr){
            um[i]++;
        }

        multimap<int, int> mm;
        for(auto it: um){
            mm.insert({it.second, it.first});
        }

        int count = 0;

        for(auto it = mm.begin(); it != mm.end(); it++){
            k-= it->first;
            if(k<0){
                return mm.size()-count;
            }
            count++;
        }

        return 0;

    }
};