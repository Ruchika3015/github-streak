class Solution {
public:
    struct Event {
        long double y;
        int type;
        long long x1, x2;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    vector<long long> xs;
    vector<long double> seg;
    vector<int> cover;

    void push(int node, int l, int r) {
        if (cover[node] > 0) {
            seg[node] = xs[r] - xs[l];
        } else if (r - l == 1) {
            seg[node] = 0;
        } else {
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= l || ql >= r) return;
        if (ql <= l && r <= qr) {
            cover[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid, r, ql, qr, val);
        push(node, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        xs.clear();

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            events.push_back({(long double)y, +1, x, x + l});
            events.push_back({(long double)y + l, -1, x, x + l});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int n = xs.size();
        seg.assign(4 * n, 0);
        cover.assign(4 * n, 0);

        sort(events.begin(), events.end());

        vector<long double> yStart, width, pref;
        long double totalArea = 0;
        long double prevY = events[0].y;

        for (auto& e : events) {
            long double dy = e.y - prevY;
            if (dy > 0 && seg[1] > 0) {
                long double area = seg[1] * dy;
                yStart.push_back(prevY);
                width.push_back(seg[1]);
                totalArea += area;
                pref.push_back(totalArea);
            }
            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();
            update(1, 0, n - 1, l, r, e.type);
            prevY = e.y;
        }

        long double target = totalArea / 2.0;
        long double prevArea = 0;

        for (int i = 0; i < pref.size(); i++) {
            if (pref[i] >= target) {
                long double need = target - prevArea;
                return (double)(yStart[i] + need / width[i]);
            }
            prevArea = pref[i];
        }

        return (double)yStart.back();
    }
};

