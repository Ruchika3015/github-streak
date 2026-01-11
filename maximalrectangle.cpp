#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols + 1, 0);  // extra 0 to flush stack
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {

            // Build histogram for current row
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1')
                    heights[c]++;
                else
                    heights[c] = 0;
            }

            // Largest Rectangle in Histogram
            stack<int> st;
            for (int i = 0; i <= cols; i++) {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    maxArea = max(maxArea, h * width);
                }
                st.push(i);
            }
        }

        return maxArea;
    }
};
