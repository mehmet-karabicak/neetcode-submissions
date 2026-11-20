class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> answer(n);

        // Store {enqueueTime, processingTime, originalIndex}
        vector<array<int, 3>> orderedTasks;
        orderedTasks.reserve(n);
        for (int i = 0; i < n; ++i) {
            orderedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(orderedTasks.begin(), orderedTasks.end(),
             [](const array<int, 3>& a, const array<int, 3>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[2] < b[2];
             });

        // Min-heap of {processingTime, originalIndex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long long currTime = 0;
        int taskIdx = 0;
        int outIdx = 0;

        while (outIdx < n) {
            // If CPU is idle and no tasks have arrived yet, jump forward to the next arrival
            if (pq.empty() && currTime < orderedTasks[taskIdx][0]) {
                currTime = orderedTasks[taskIdx][0];
            }

            // Enqueue all tasks that have arrived by currTime
            while (taskIdx < n && orderedTasks[taskIdx][0] <= currTime) {
                pq.push({orderedTasks[taskIdx][1], orderedTasks[taskIdx][2]});
                ++taskIdx;
            }

            // Pick shortest processingTime, breaking ties by smallest originalIndex
            auto [procTime, origIdx] = pq.top();
            pq.pop();

            answer[outIdx++] = origIdx;
            currTime += procTime;
        }

        return answer;
    }
};