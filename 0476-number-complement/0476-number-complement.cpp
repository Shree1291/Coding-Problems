class Solution {
public:
    int findComplement(int num) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        bool gotIt = false;

        for(int i = 30; i >= 0; i--) {
            if((num & (1 << i)) != 0) {
                gotIt = true;
            }
            if(gotIt) {
                num ^= (1 << i);
            }
        }
        return num;
    }
};
