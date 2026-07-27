package Problems;

public class LeetCode1464MaximumProductOfTwoElementsInAnArray {
    public int maxProduct(int[] nums) {
        int[] greatests=new int[2];
        for(var num:nums){
            if(num>greatests[0]){
                greatests[1]=greatests[0];
                greatests[0]=num;
                continue;
            }
            if(num>greatests[1]){
                greatests[1]=num;
            }
        }
        return  (greatests[0]-1)*(greatests[1]-1);
    }
}
