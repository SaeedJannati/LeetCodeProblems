package Problems;

import java.util.HashMap;
import java.util.HashSet;

public class LeetCode784CheckIfArrayIsGood extends  BaseProblem {
    public boolean isGood(int[] nums) {
        int length = nums.length;
        HashMap<Integer,Integer> set = new HashMap<>(length);
        int freq=0;
        for (int i = 0; i < length; i++) {
            if(nums[i]>length-1)
                return false;
            if(set.containsKey(nums[i])) {
                if(nums[i]!=length-1)
                    return false;
                freq=set.get(nums[i]);
                if(freq==2)
                    return false;
                set.put(nums[i],freq+1);
                continue;
            }
            set.put(nums[i],1);
        }
        return true;
    }

    @Override
    public void Run() {
        int[] nums = {1,3,3,2};
        System.out.println(isGood(nums));
     }
}
