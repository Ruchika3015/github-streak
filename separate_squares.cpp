class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 1e18, high = 0;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        auto areaBelow = [&](double mid) {
            double area = 0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (mid <= y) continue;
                if (mid >= y + l) area += l * l;
                else area += (mid - y) * l;
            }
            return area;
        };

        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            if (areaBelow(mid) >= target)
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};
