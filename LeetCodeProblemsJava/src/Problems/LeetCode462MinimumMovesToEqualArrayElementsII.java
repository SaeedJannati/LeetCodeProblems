package Problems;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class LeetCode462MinimumMovesToEqualArrayElementsII {
    public int minMoves2(int[] nums) {
        int length=nums.length;
        if(length==1){
            return 0;
        }
        Arrays.sort(nums);
       int median;
       if(length%2==1){
           median=nums[length/2];
       }else{
           median=(nums[length/2+1]+nums[length/2])/2;
       }
       int delta=0;
       for(var num:nums){
           delta+= Math.abs(num-median);
       }
       return delta;
    }
}
