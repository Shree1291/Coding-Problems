class Solution {
public:
    int M = 1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1005,0));
        
        for(int sum=0;sum<=nums[0];sum++){
            dp[0][sum]=1;
        }
        
        for(int ind=1;ind<n;ind++){
            int cnt=0;
            int prev_num=0;
            for(int curr_num=0;curr_num<=nums[ind];curr_num++){
                if(prev_num <= min(curr_num,curr_num+nums[ind-1]-nums[ind])){
                    cnt = (cnt%M + dp[ind-1][prev_num]%M)%M;
                    prev_num++;
                }
                dp[ind][curr_num]=cnt;
            }
        }
        
        int res=0;
        for(int curr=0;curr<=1000;curr++){
            res = (res%M + dp[n-1][curr]%M)%M;
        }
        
        return res;
    }
};