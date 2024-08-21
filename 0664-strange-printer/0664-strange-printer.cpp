class Solution {
    string removeAdjChar(string& s){
        int n = s.length();
        string newStr = "";
        int i=0;
        while(i<n){
            newStr+=s[i];
            char ch = s[i];
            while(i<n && s[i]==ch){
                i++;
            }
        }
        return newStr;
    }
    int minTurns(int s,int e,string& str,vector<vector<int>>&dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];

        int mini = 1 + minTurns(s+1,e,str,dp);

        for(int i=s+1;i<=e;i++){
            if(str[i]==str[s]){
                int temp = minTurns(s,i-1,str,dp) + minTurns(i+1,e,str,dp);
                mini = min(mini,temp);
            }
        }

        return dp[s][e] = mini;
    }
public:
    int strangePrinter(string s) {
        s = removeAdjChar(s);
        int n = s.length();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        int res = minTurns(0,n-1,s,dp);
        return res;
    }
};