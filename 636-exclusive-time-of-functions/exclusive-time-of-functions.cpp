class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (const string& log : logs) {
            size_t firstColon = log.find(":");
            size_t secondColon = log.find(":", firstColon + 1);

            int id = stoi(log.substr(0, firstColon));
            string type =
                log.substr(firstColon + 1, secondColon - firstColon - 1);
            int currentTime = stoi(log.substr(secondColon + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += currentTime - prevTime;
                }
                st.push(id);
                prevTime = currentTime;
            } else {
                ans[st.top()] += currentTime - prevTime + 1;
                st.pop();
                prevTime = currentTime + 1;
            }
        }

        return ans;
    }
};