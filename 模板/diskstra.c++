class Solution {
    vector<long> dijkstra(vector<vector<pair<int, int>>> &g, int start) {
        vector<long> dis(g.size(), LONG_MAX / 3);
        dis[start] = 0;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d > dis[x]) continue;
            for (auto [y, wt]: g[x]) {
                long newD = dis[x] + wt;
                if (newD < dis[y]) {
                    dis[y] = newD;
                    pq.emplace(newD, y);
                }
            }
        }
        return dis;
    }

public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> g(n), rg(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1], wt = e[2];
            g[x].emplace_back(y, wt);
            rg[y].emplace_back(x, wt);
        }

        auto d1 = dijkstra(g, src1);
        auto d2 = dijkstra(g, src2);
        auto d3 = dijkstra(rg, dest);

        long ans = LONG_MAX / 3;
        for (int x = 0; x < n; ++x)
            ans = min(ans, d1[x] + d2[x] + d3[x]);
        return ans < LONG_MAX / 3 ? ans : -1;
    }
};