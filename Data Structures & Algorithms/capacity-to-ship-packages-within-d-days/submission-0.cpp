class Solution {
public:
    int f(vector<int>& weights, int mid){
        int cur=0,count=0;
        for(auto x: weights){
            if(cur+x<=mid){
                cur+=x;
            }
            else{
                cur=x;
                count++;
            }
        }
        count++;
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=1e9;
        int low=*max_element(weights.begin(), weights.end()),high=0;
        for(auto x: weights)
        high+=x;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            int count=f(weights, mid);

            if(count<=days){
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};