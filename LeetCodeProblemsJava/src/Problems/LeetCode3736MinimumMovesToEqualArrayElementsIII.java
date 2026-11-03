package Problems;

public class LeetCode3736MinimumMovesToEqualArrayElementsIII {
    public int minMoves(int[] nums) {
        int length=nums.length;
        if(length<=1){
            return 0;
        }
        int maxNum=nums[0];
        int delta=0;
        int minorDelta=0;
        for (int i=1;i<length;i++){
            if(nums[i]>maxNum){
                minorDelta=nums[i]-maxNum;
                delta+=i*minorDelta;
                maxNum=nums[i];
            }else{
                delta+=maxNum-nums[i];
            }
        }
        return delta;
    }
}
