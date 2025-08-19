class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      const size_t m = nums1.size(), n = nums2.size();
      size_t i = 0, j = 0;
      size_t mid1 = ((m + n - 1) / 2), mid2 = ((m + n) / 2);
      int pval = 0, nval = 0;
      for (size_t k = 0; k <= mid2; ++k) {
        pval = nval;
        if ((i < m) && (j >= n || nums1[i] <= nums2[j]))
          nval = nums1[i++];
        else if((j < n) && (i >= m || nums1[i] >= nums2[j]))
          nval = nums2[j++];  
      }
      return (mid1 == mid2) ? (float) nval : (float) ((pval + nval) / 2.0f);
    }
};
