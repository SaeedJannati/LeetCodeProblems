package Problems;

public class LeetCode1979FindGreatestCommonDivisorOfArray {
    public int findGCD(int[] nums) {
        int min=1001,max=2;
        for(var num:nums){
            min=Math.min(min,num);
            max=Math.max(max,num);
        }
        return greatestCommonDivisor(min,max);
    }
    private  int greatestCommonDivisor(int a,int b){
        if(b==0){
            return a;
        }
        return greatestCommonDivisor(b,a%b);
    }
}
