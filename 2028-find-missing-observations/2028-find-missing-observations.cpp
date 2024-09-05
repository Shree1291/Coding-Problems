class Solution {
public:
   
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = accumulate(rolls.begin(),rolls.end(),0);
        int mn = rolls.size()+n;
        int sum = (mean*mn)-total;

        if(sum<n || sum>(6*n)){ return {}; }
        
        int init=1,remain=0;
        for(int i=2;i<=6;i++){
            if(i*n<=sum){
                init=i;
            }
        }
        remain=sum-(init*n);
        vector<int>ans(n,init);
        for(int i=0;i<n;i++){
            if(remain>0 && ans[i]<6){
                int diff = (6-ans[i]);
                if(diff>remain){
                    ans[i]+=remain;
                    remain=0;
                }else{
                    ans[i]+=diff;
                    remain-=diff;
                }

            }
        }
        return ans;
    }
};