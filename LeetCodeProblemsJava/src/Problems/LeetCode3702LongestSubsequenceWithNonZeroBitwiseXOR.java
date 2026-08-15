package Problems;

public class LeetCode3702LongestSubsequenceWithNonZeroBitwiseXOR {
    public int longestSubsequence(int[] nums) {
        int xor=0;
        int len=nums.length;
        boolean hasNoneZero=false;
        for(int num:nums){
            if(num>0){
                hasNoneZero=true;
            }
            xor^=num;
        }
        if(xor!=0){
            return len;
        }
        if(!hasNoneZero){
            return 0;
        }
        return len-1;
    }
}
