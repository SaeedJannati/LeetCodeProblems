package Problems;

public class LeetCode2540MinimumCommonValue {
    public int getCommon(int[] nums1, int[] nums2) {
        int firstLength = nums1.length;
        int secondLength = nums2.length;
        int firstPointer = 0;
        int secondPointer = 0;
        int firstIndex = 0;
        int secondIndex = 0;
        while (firstPointer < firstLength || secondPointer < secondLength) {
            firstIndex = Math.min(firstPointer, firstLength - 1);
            secondIndex = Math.min(secondPointer, secondLength - 1);
            if (nums1[firstIndex] == nums2[secondIndex]) {
                return nums1[firstIndex];
            }
            if (nums1[firstIndex] > nums2[secondIndex]) {
                if (secondPointer < secondLength) {
                    secondPointer++;
                } else {
                    firstPointer++;
                }

                continue;
            }
            if (firstPointer < firstLength) {
                firstPointer++;
                continue;
            }
            secondPointer++;
        }
        return -1;
    }
}