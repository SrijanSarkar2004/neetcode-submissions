class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>v(n,0);
        stack<pair<int,int>>q;
        q.push({1000,-1});
        for(int i=0;i<n;i++){
            int x=temperatures[i];
                
                while(x>q.top().first){
                    auto node=q.top();
                    q.pop();
                    int ind=node.second;
                    v[ind]=i-ind;
                }
                q.push({x,i});
        }
        return v;
    }
};