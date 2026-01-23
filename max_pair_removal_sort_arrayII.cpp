class Solution {
public:
    struct Node {
        long long val;
        int prev, next;
        bool alive;
        Node(long long v = 0) : val(v), prev(-1), next(-1), alive(true) {}
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<Node> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = Node(nums[i]);
            nodes[i].prev = i - 1;
            nodes[i].next = (i + 1 < n ? i + 1 : -1);
        }

        int bad = 0;
        for (int i = 0; i + 1 < n; i++)
            if (nums[i] > nums[i + 1]) bad++;

        if (bad == 0) return 0;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        for (int i = 0; i + 1 < n; i++)
            pq.push({(long long)nums[i] + nums[i + 1], i});

        auto isBad = [&](int a, int b) {
            return nodes[a].alive && nodes[b].alive &&
                   nodes[a].val > nodes[b].val;
        };

        int ops = 0;

        while (bad > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            if (!nodes[i].alive) continue;
            int j = nodes[i].next;
            if (j == -1 || !nodes[j].alive) continue;

            long long realSum = nodes[i].val + nodes[j].val;
            if (realSum != sum) continue;

            int p = nodes[i].prev;
            int k = nodes[j].next;

            if (p != -1 && isBad(p, i)) bad--;
            if (isBad(i, j)) bad--;
            if (k != -1 && isBad(j, k)) bad--;

            nodes[i].val += nodes[j].val;
            nodes[j].alive = false;

            nodes[i].next = k;
            if (k != -1) nodes[k].prev = i;

            if (p != -1 && isBad(p, i)) bad++;
            if (k != -1 && isBad(i, k)) bad++;

            if (p != -1) pq.push({nodes[p].val + nodes[i].val, p});
            if (k != -1) pq.push({nodes[i].val + nodes[k].val, i});

            ops++;
        }

        return ops;
    }
};
