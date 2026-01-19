class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i-1][j-1] 
                            + pre[i-1][j] 
                            + pre[i][j-1] 
                            - pre[i-1][j-1];
            }
        }
        
        int low = 0, high = min(m, n), ans = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;
            
            for (int i = 0; i + mid <= m && !found; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    int sum = pre[i + mid][j + mid]
                            - pre[i][j + mid]
                            - pre[i + mid][j]
                            + pre[i][j];
                    
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
            }
            
            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
