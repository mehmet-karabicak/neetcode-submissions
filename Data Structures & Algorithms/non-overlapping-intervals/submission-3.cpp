class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int nonOverlappingCount = 0;
        int prevEnd = INT_MIN;

        for (const vector<int>& interval : intervals) {
            // If the current interval starts at or after the previous included interval's end, keep it
            if (interval[0] >= prevEnd) {
                nonOverlappingCount++;
                prevEnd = interval[1];
            }
        }

        // Minimum removals = total intervals - maximum non-overlapping intervals
        return intervals.size() - nonOverlappingCount;
    }
};