#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;

        // the number of the left side
        int partitionX;
        // the number of the right side
        int partitionY;

        int maxLeftX;
        int minRightX;
        int maxLeftY;
        int minRightY;

        while (low <= high) {
            partitionX = (low + high) / 2;
            partitionY = (x + y + 1) / 2 - partitionX;

            maxLeftX = (partitionX == 0) ? INT32_MIN : nums1[partitionX - 1];
            minRightX = (partitionX == x) ? INT32_MAX : nums1[partitionX];

            maxLeftY = (partitionY == 0) ? INT32_MIN : nums2[partitionY - 1];
            minRightY = (partitionY == y) ? INT32_MAX : nums2[partitionY];


            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2 == 0) {
                    return (double) (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2;
                } else {
                    return (double) (std::max(maxLeftX, maxLeftY));
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3, 4};
    Solution so;
    double result = so.findMedianSortedArrays(nums1, nums2);

    std::cout << result << std::endl;
}