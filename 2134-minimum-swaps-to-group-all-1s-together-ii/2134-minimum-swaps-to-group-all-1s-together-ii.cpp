class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = count(nums.begin(),nums.end(),1);
        for(int i=0;i<totalOnes;i++){
            nums.push_back(nums[i]);
        }
        int len = nums.size();
        int cntZero=0,cntOne=0,mini=1e5;
        int i=0,j=0;
        
        for(;j<totalOnes;j++){
            if(nums[j]==0) cntZero++;
        }
        mini = min(mini,cntZero);
        while(j<len){
            if(nums[j++]==0) cntZero++;
            if(nums[i++]==0) cntZero--;
            
            mini = min(mini,cntZero);
        }
        return mini;
    }
};