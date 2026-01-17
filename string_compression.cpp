class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int n = 1;

        for (int i = 0; i < chars.size(); i++) {
            if (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                n++;
            } 
            else {  // SAFE condition
                ans.push_back(chars[i]);

                if (n > 1) {
                    string s = to_string(n);
                    for (char c : s) {
                        ans.push_back(c);
                    }
                }
                n = 1; // ✅ always reset
            }
        }

        chars = ans;        // copy back
        return ans.size();  // return new length
    }
};
