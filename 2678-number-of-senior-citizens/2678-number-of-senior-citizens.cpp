class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            string temp = details[i].substr(11,2);
            if(stoi(temp)>60){
                cnt++;
            }
        }
        return cnt;
    }
};