class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int area = INT_MIN;
        while(i<j){
            int currArea = min(height[i],height[j]) * (j-i);
            area = max(area , currArea);
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return area;
    }
};
