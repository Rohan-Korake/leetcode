class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m, 0);

        vector<pair<int, int>> q(m);
        for (int i = 0; i < m; ++i) {
            q[i] = {queries[i], i};
        }

        sort(q.begin(), q.end());

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int l = 0, r = 0;
        int logs_size = logs.size();
        vector<int> server_count(n + 1, 0);
        int active_servers = 0;

        for (int i = 0; i < m; ++i) {
            int query_time = q[i].first;
            int original_index = q[i].second;
            int start_time = query_time - x;

            while (r < logs_size && logs[r][1] <= query_time) {
                int server_id = logs[r][0];
                if (server_count[server_id] == 0) {
                    active_servers++;
                }
                server_count[server_id]++;
                r++;
            }

            while (l < r && logs[l][1] < start_time) {
                int server_id = logs[l][0];
                server_count[server_id]--;
                if (server_count[server_id] == 0) {
                    active_servers--;
                }
                l++;
            }

            ans[original_index] = n - active_servers;
        }

        return ans;
    }
};