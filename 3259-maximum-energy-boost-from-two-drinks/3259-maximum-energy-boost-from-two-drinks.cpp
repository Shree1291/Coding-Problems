class Solution {
public:
    long long sol(int ind, bool prev, int n, vector<int>& A, vector<int>& B, vector<vector<long long>>& dp) {
        if (ind >= n) return 0;

        if (dp[ind][prev] != -1) return dp[ind][prev];

        long long take = 0, notake = 0;

        if (prev) {
            take = A[ind] + sol(ind + 1, 1, n, A, B, dp);
            notake = sol(ind + 1, 0, n, A, B, dp);
        } else {
            take = B[ind] + sol(ind + 1, 0, n, A, B, dp);
            notake = sol(ind + 1, 1, n, A, B, dp);
        }

        return dp[ind][prev] = max(take, notake);
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        long long ans1 = energyDrinkA[0] + sol(1, 1, n, energyDrinkA, energyDrinkB, dp);
        long long ans2 = energyDrinkB[0] + sol(1, 0, n, energyDrinkA, energyDrinkB, dp);

        return max(ans1, ans2);
    }
};
