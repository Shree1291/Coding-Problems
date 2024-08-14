class Solution {
public:
    int maxOperations(string s) {
        vector<int>vec;
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }else if(s[i]=='0' && cnt>0){
                vec.push_back(cnt);
                cnt=0;
            }
            if(i==n-1 && cnt>0){
                vec.push_back(cnt);
            }
        }
        if(s[n-1]!='1'){
            vec.push_back(1);
        }
        int ans = 0;
        vector<int>pre(vec.size());
        for(int i=0;i<vec.size();i++){
            ans+=vec[i];
            pre[i]=ans;
        }
        int res = 0;
        for(int i=0;i<vec.size()-1;i++){
           res+=pre[i];
        }
        return res;
    }
};