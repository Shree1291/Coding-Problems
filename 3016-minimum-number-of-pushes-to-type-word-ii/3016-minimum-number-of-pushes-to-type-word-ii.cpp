class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        int k_p = 0;
        int k_pos = 1;
        int k_num = 2;

        for (char ch : word) {
            mp[ch] = mp.find(ch) != mp.end() ? mp[ch] + 1 : 1;
        }

        vector<char> vec;
        for (const auto& it : mp) {
            vec.push_back(it.first);
        }

        sort(vec.begin(), vec.end(), [&](char a, char b) {
            return mp[a] > mp[b];
        });

        for (char ch : vec) {
            k_p += mp[ch] * k_pos;
            if (k_num < 9) {
                k_num += 1;
            } else {
                k_num= 2;
                k_pos += 1;
            }
        }

        return k_p;
    }
};