class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letters(26, 0);
        for (char task : tasks) {
            letters[task - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int count : letters) {
            if (count > 0) {
                pq.push(count);
            }
        }
        
        queue<pair<int, int>> q; // stores {remaining_count, available_time}
        int time = 0;
        
        while (!pq.empty() || !q.empty()) {
            time++;
            
            if (!pq.empty()) {
                int currentCount = pq.top();
                pq.pop();
                currentCount--;
                
                if (currentCount > 0) {
                    q.push({currentCount, time + n});
                }
            }
            
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};