class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            if (x % 2 == 0) {
                ans.push_back(-1);
                continue;
            }

            int t = 0, temp = x;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }

            int a = x - (1 << (t - 1));
            ans.push_back(a);
        }

        return ans;
    }
};
