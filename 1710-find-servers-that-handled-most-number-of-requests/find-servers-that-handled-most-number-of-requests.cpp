class Solution {
public:
    typedef pair<int, int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> availableServers;
        for (int i = 0; i < k; i++) {
            availableServers.insert(i);
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countOfRequest(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while (!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;
                busyServers.pop();
                availableServers.insert(server);
            }

            int target = i % k;

            auto id = availableServers.lower_bound(target);

            if (id == availableServers.end()) {
                id = availableServers.begin();
            }
            if (availableServers.empty())
                continue;

            int targetServer = *id;
            availableServers.erase(id);
            busyServers.push({time + load[i], targetServer});
            countOfRequest[targetServer]++;
        }

        int maxCount = *max_element(begin(countOfRequest), end(countOfRequest));
        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (countOfRequest[i] == maxCount) {
                result.push_back(i);
            }
        }
        return result;
    }
};