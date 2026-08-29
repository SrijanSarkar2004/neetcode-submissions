class Solution {
public:
    long long f(vector<int>& piles,int mid){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=ceil((double)piles[i]/mid);
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles,int h){
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int low=1,high=piles[n-1];
        int ans=1e9;

        while(low<=high){
            int mid=low+(high-low)/2;
            long long count=f(piles,mid);

            if(count<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};