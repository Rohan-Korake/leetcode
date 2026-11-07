class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
      int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busyServers;
        
        long long current_time = 0;
        
        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);
            
            if (freeServers.empty()) {
                current_time = max(current_time, busyServers.top()[0]);
            }
            
            while (!busyServers.empty() && busyServers.top()[0] <= current_time) {
                long long free_time = busyServers.top()[0];
                int weight = busyServers.top()[1];
                int index = busyServers.top()[2];
                busyServers.pop();
                freeServers.push({weight, index});
            }
            
            auto best_server = freeServers.top();
            freeServers.pop();
            
            int weight = best_server.first;
            int server_index = best_server.second;
            
            ans[j] = server_index;
            
            long long finish_time = current_time + tasks[j];
            busyServers.push({finish_time, weight, server_index});
        }
        
        return ans;
    }
};