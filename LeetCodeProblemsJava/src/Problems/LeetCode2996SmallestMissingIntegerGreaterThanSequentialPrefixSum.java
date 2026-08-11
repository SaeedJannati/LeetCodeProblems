package Problems;

import java.util.Arrays;
import java.util.HashSet;

public class LeetCode2996SmallestMissingIntegerGreaterThanSequentialPrefixSum extends BaseProblem {
    public int missingInteger(int[] nums) {
        int length = nums.length;
        HashSet<Integer> set = new HashSet<>();
        int sum = nums[0];
        set.add(sum);
        boolean sequential = true;
        for (int i = 1; i < length; i++) {
            set.add(nums[i]);
            if (!sequential)
                continue;
            if (nums[i] - nums[i - 1] != 1) {
                sequential = false;
                continue;
            }
            sum += nums[i];
        }
        while (set.contains(sum)) {
            sum++;
        }
        return sum;
    }

    @Override
    public void Run() {
        int[] nums = {3, 4, 5, 1, 12, 14, 13};
        System.out.println(missingInteger(nums));
    }
}
