package Problems;

import java.util.ArrayList;
import java.util.List;

public class LeetCode2089FindTargetIndicesAfterSortingArray {
    public List<Integer> targetIndices(int[] nums, int target) {
        var output = new ArrayList<Integer>();
        int numsBeforeCount=0;
        int targetCount=0;
        int len = nums.length;
        for (int num : nums) {
            if (num == target) {
                targetCount++;
                continue;
            }
            if (num < target) {
                numsBeforeCount++;
            }
        }
        for(int i=0;i<targetCount;i++){
            output.add(numsBeforeCount+i);
        }
        return output;
    }

}
