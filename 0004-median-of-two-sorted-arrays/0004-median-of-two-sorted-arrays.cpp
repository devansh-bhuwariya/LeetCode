class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int mid = size / 2;
        vector<int> merged;

        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }

            if (merged.size() > mid + 1) {
                break;
            }
        }

        while (i < nums1.size() && merged.size() <= mid) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size() && merged.size() <= mid) {
            merged.push_back(nums2[j]);
            j++;
        }

        if (size % 2 == 0) {
            return (double)(merged[mid - 1] + merged[mid]) / 2.0;
        } else {
            return (double)merged[mid];
        }
    }
};