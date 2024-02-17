class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i;
        //4 12 2 7 3 18 20 3 19
        //b = 10, l = 2
        priority_queue<int,vector<int>>pq;
        for(i = 0; i < heights.size()-1; i++){
            int difference = heights[i+1] - heights[i]; //12 - 4 = 8 // 7 -2 = 5

            if(difference > 0){ // 8 > 0 //5 > 0 
                //having to use a brick or ladder
                bricks-= difference; // 10-8 = 2 // 2 - 5 = -3
                pq.push(difference); //{8, 5}
                if(bricks < 0){
                    if(ladders<=0) return i;
                    int getbackbricks = pq.top(); //{8} //{5}
                    bricks+=getbackbricks; //bricks = -3 + 8 = 5
                    ladders--;// ladders =1
                    pq.pop();//{ ,5}
                }
            } 
        }
        return i;
    }
};