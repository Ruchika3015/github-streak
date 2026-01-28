class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        // 1) compress values
        vector<int> vals;
        for (auto &r : grid)
            for (int x : r)
                vals.push_back(x);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int V = vals.size();
        vector<vector<int>> vid(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                vid[i][j] = lower_bound(vals.begin(), vals.end(), grid[i][j]) - vals.begin();

        // dist[t][i][j]
        vector<vector<vector<int>>> dist(
            k + 1, vector<vector<int>>(m, vector<int>(n, INF))
        );

        dist[0][0][0] = 0;

        // 2) layers
        for (int t = 0; t <= k; t++) {

            // Dijkstra for normal moves
            priority_queue<
                tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                greater<>
            > pq;

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (dist[t][i][j] < INF)
                        pq.push({dist[t][i][j], i, j});

            while (!pq.empty()) {
                auto [cost, i, j] = pq.top();
                pq.pop();
                if (cost != dist[t][i][j]) continue;

                if (i + 1 < m) {
                    int nc = cost + grid[i + 1][j];
                    if (nc < dist[t][i + 1][j]) {
                        dist[t][i + 1][j] = nc;
                        pq.push({nc, i + 1, j});
                    }
                }
                if (j + 1 < n) {
                    int nc = cost + grid[i][j + 1];
                    if (nc < dist[t][i][j + 1]) {
                        dist[t][i][j + 1] = nc;
                        pq.push({nc, i, j + 1});
                    }
                }
            }

            if (t == k) break;

            // teleport DP
            vector<int> best(V, INF);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    best[vid[i][j]] = min(best[vid[i][j]], dist[t][i][j]);

            // SUFFIX minimum (IMPORTANT)
            for (int v = V - 2; v >= 0; v--)
                best[v] = min(best[v], best[v + 1]);

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    dist[t + 1][i][j] = min(dist[t + 1][i][j], best[vid[i][j]]);
        }

        int ans = INF;
        for (int t = 0; t <= k; t++)
            ans = min(ans, dist[t][m - 1][n - 1]);

        return ans;
    }
};
