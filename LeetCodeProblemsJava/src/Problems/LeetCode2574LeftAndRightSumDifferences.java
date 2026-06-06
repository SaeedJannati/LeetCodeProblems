package Problems;

public class LeetCode2574LeftAndRightSumDifferences {
    public int[] leftRightDifference(int[] nums) {
        int length = nums.length;
        int[] left = new int[length];
        int[] right = new int[length];
        for (int i = 1; i < length; i++) {
            left[i]=left[i-1]+nums[i-1];
            right[length-i-1]=right[length-i]+nums[length-i];
        }
        for (int i = 0; i < length; i++) {
            nums[i] = Math.abs(left[i]-right[i]) ;
        }
        return nums;
     }
}
