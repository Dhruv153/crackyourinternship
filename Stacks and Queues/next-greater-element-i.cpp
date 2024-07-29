class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(-1);
        int n = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            while (st.top() <= nums2[i] && st.top() != -1) {
                st.pop();
            }
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
