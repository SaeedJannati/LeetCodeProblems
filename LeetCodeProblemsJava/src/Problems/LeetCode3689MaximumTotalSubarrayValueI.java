package Problems;

public class LeetCode3689MaximumTotalSubarrayValueI {
    public long maxTotalValue(int[] nums, int k) {
        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        for( var num: nums ) {
            maxVal = Math.max(maxVal, num);
            minVal = Math.min(minVal, num);
        }
        return (long)k*(long)(maxVal-minVal);
    }
}
