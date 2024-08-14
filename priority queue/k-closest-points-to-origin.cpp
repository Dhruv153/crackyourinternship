class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (maxHeap.size() < k) {
                maxHeap.push({dist, i});
            } else if (dist < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({dist, i});
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};
