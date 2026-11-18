#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // Pair up each car's position and speed
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        
        // Sort cars by position in descending order (closest to target first)
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        stack<double> st;
        
        // Iterate through each car
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // If the stack is not empty and the current car takes LESS or EQUAL time 
            // than the fleet ahead of it, it merges into that fleet.
            if (!st.empty() && time <= st.top()) {
                continue;
            }
            
            // Otherwise, it forms a new fleet
            st.push(time);
        }
        
        // The size of the stack represents the total number of independent fleets
        return st.size();
    }
};