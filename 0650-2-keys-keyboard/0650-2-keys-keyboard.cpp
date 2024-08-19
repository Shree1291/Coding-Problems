class Solution {
public:
    int sol(int n,int curr,int paste){
        if(curr == n) return 0;
        if(curr>n) return 1000;

        int t1 = 2 + sol(n,curr*2,curr);
        int t2 = 1 + sol(n,curr+paste,paste);

        return min(t1,t2);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1 + sol(n,1,1);
    }
};