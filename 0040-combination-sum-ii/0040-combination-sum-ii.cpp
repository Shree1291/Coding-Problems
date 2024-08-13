class Solution {
public:
    void sol(int ind,int tar,int n,vector<int>&temp,vector<vector<int>>&ans,vector<int>&candidates){
        if(tar==0){
            ans.push_back(temp);
            return;
        }
       // if(ind>=n){ return; }

        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>tar) break;

            temp.push_back(candidates[i]);
            sol(i+1,tar-candidates[i],n,temp,ans,candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sol(0,target,n,temp,ans,candidates);
        return ans;
    }
};