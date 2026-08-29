class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pq;
        int n=position.size();
        
        for(int i=0;i<n;i++)
            pq.push({position[i],speed[i]});
        
        int fleet=0;
        double time=0;
        
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            
            double curr_time=(double)(target-tp.first)/tp.second;
            
            if(curr_time>time){
                time=curr_time;
                fleet++;
            }
        }
        
        return fleet;
    }
};