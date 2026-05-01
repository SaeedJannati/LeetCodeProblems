package Problems;

public class LeetCode396RotateFunction extends BaseProblem {

    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int currentSum = 0;
        int elementsSum = nums[0];
        for (int i = 1; i < n; i++) {
            currentSum += i * nums[i];
            elementsSum += nums[i];
        }
        int maxSum = currentSum;
        for (int i = 1; i < n; i++) {
            currentSum += elementsSum - n * nums[n - i];
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }

    @Override
    public void Run() {
        int[] nums = new int[]{4, 3, 2, 6};
        IO.println(maxRotateFunction(nums));
    }
}
