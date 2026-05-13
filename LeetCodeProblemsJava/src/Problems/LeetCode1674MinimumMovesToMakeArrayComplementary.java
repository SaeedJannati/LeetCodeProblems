package Problems;

import java.util.Arrays;

public class LeetCode1674MinimumMovesToMakeArrayComplementary {

    public int minMoves(int[] nums, int limit) {
        int length = nums.length;
        int[] sums = new int[length / 2];
        int[] minSums = new int[length / 2];
        int[] maxSums = new int[length / 2];
        int minSum = 2 * limit;
        int maxSum = 2;
        for (int i = 0; i < length / 2; i++) {
            sums[i] = nums[i] + nums[length - 1 - i];
            minSums[i] = Math.min(nums[i], nums[length - 1 - i]) + 1;
            maxSums[i] = Math.max(nums[i], nums[length - 1 - i]) + limit;
            maxSum = Math.max(maxSum, sums[i]);
            minSum = Math.min(minSum, sums[i]);
        }
        Arrays.sort(minSums);
        Arrays.sort(maxSums);
        Arrays.sort(sums);

        int pairCount = length / 2;
        int diffsCount = 0;
        int minDiffsCount = length;
        int begin = 0;
        int end = pairCount - 1;
        int mid = 0;
        int found = 0;
        int greaterSumIndex, lesserSumIndex, zeroChange, twoChanges, oneChanges = 0;

        for (int target = minSum; target <= maxSum; target++) {
            greaterSumIndex = pairCount;
            lesserSumIndex = -1;

            begin = 0;
            end = pairCount - 1;
            found = pairCount;
            while (begin <= end) {
                mid = (begin + end) >> 1;
                if (sums[mid] > target) {
                    found = Math.min(found, mid);
                    end = mid - 1;
                    continue;
                }
                begin = mid + 1;
            }
            if (found != pairCount) {
                greaterSumIndex = found;
            }

            begin = 0;
            end = pairCount - 1;
            found = -1;
            while (begin <= end) {
                mid = (begin + end) >> 1;
                if (sums[mid] < target) {
                    found = Math.max(found, mid);
                    begin = mid + 1;
                    continue;
                }
                end = mid - 1;
            }
            if (found != -1) {
                lesserSumIndex = found;
            }

            zeroChange = greaterSumIndex - lesserSumIndex - 1;
            begin = 0;
            end = pairCount - 1;
            found = pairCount;
            while (begin <= end) {
                mid = (begin + end) >> 1;
                if (minSums[mid] > target) {
                    found = Math.min(found, mid);
                    end = mid - 1;
                    continue;
                }
                begin = mid + 1;
            }

            twoChanges = 0;
            if (found != pairCount) {
                twoChanges = pairCount - found;
            }

            begin = 0;
            end = pairCount - 1;
            found = -1;
            while (begin <= end) {
                mid = (begin + end) >> 1;
                if (maxSums[mid] < target) {
                    found = Math.max(found, mid);
                    begin = mid + 1;
                    continue;
                }
                end = mid - 1;
            }

            if (found != -1) {
                twoChanges += found + 1;
            }

            oneChanges = pairCount - zeroChange - twoChanges;
            diffsCount = oneChanges + 2 * twoChanges;
            minDiffsCount = Math.min(minDiffsCount, diffsCount);
        }
        return minDiffsCount;
    }
}
