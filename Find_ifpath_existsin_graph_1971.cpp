class Solution {
public:
    bool ans(unordered_map<int, vector<int>>& mp, int s, int d, vector<bool>& visited){
        if(s == d) return true;
        
        if(visited[s] == true)
            return false;
        visited[s] = true;
        
        //explore
        for(auto &node: mp[s]){
            if(ans(mp, node, d, visited) == true)
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>mp;
        
        for(vector<int> &edge: edges){

            int u = edge[0];
            int v = edge[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, 0);
        
        return ans(mp, source, destination, visited);
    }
};