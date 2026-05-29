package Problems;

public class LeetCode3300MinimumElementAfterReplacementWithDigitSum {
    public int minElement(int[] nums) {
        int minNum= 1<<30;
        for (var num : nums) {
            minNum=Math.min(minNum,getDigitSum(num));
        }
        return minNum;
    }
    int getDigitSum(int num) {
        int sum=0;
        while (num!=0) {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
}
