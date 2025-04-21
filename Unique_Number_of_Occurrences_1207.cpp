#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool UniqueCount(vector<int>& arr){
    vector<int> v;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size(); i++){
        int count = 1;
        
        while(i+1 < arr.size() && arr[i] == arr[i+1]){
            count++;
            i++;
        }
        
        v.push_back(count);

    }
    
    sort(v.begin(), v.end());
    
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]){
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<int> arr;
    arr = {1,1,2,3,3,3};
    
    bool uni = UniqueCount(arr);
    if(!uni){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}
