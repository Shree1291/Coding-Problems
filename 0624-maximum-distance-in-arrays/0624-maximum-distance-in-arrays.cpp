class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        cin.tie(nullptr)->sync_with_stdio(false);
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();

        int ans = 0;
        for(int i=1; i<arrays.size(); ++i)
        {
            const auto &arr = arrays[i];
            ans = max(ans, abs(arr.back() - minVal));
            ans = max(ans, abs(arr.front() - maxVal));

            minVal = min(minVal, arr.front());
            maxVal = max(maxVal, arr.back());
        }

        return ans;
    }
};