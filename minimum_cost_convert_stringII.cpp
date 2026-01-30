class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        const long long INF = 1e18;

        unordered_map<string,int> id;
        int idx = 0;

        auto getId = [&](const string& s) {
            if (!id.count(s)) id[s] = idx++;
            return id[s];
        };

        int m = original.size();
        for (int i = 0; i < m; i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int nNodes = idx;
        vector<vector<long long>> dist(nNodes, vector<long long>(nNodes, INF));

        for (int i = 0; i < nNodes; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall
        for (int k = 0; k < nNodes; k++)
            for (int i = 0; i < nNodes; i++)
                for (int j = 0; j < nNodes; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);

        unordered_set<int> lens;
        for (auto &s : original) lens.insert(s.size());

        int n = source.size();
        vector<long long> dp(n+1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i])
                dp[i+1] = min(dp[i+1], dp[i]);

            for (int L : lens) {
                if (i + L > n) continue;

                string x = source.substr(i, L);
                string y = target.substr(i, L);

                if (!id.count(x) || !id.count(y)) continue;

                long long c = dist[id[x]][id[y]];
                if (c < INF)
                    dp[i+L] = min(dp[i+L], dp[i] + c);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
