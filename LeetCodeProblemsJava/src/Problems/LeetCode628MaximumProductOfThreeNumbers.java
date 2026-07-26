package Problems;

import java.util.ArrayList;

public class LeetCode628MaximumProductOfThreeNumbers {
    public int maximumProduct(int[] nums) {
        if(nums.length==3){
            return  nums[0]*nums[1]*nums[2];
        }
        ArrayList<Integer> positives = new ArrayList<>();
        ArrayList<Integer> negatives = new ArrayList<>();
        for(var num : nums){
            if(num<0){
                negatives.add(num);
                continue;
            }
                positives.add(num);
        }
        positives.sort(Integer::compareTo);
        negatives.sort(Integer::compareTo);
        if(negatives.size()<2){
            return positives.getLast()*positives.get(positives.size()-2)*positives.get(positives.size()-3);
        }
        if(positives.isEmpty()){
            return negatives.getLast()*negatives.get(negatives.size()-2)*negatives.get(negatives.size()-3);
        }
      int result = negatives.getFirst()*negatives.get(1)*positives.getLast();
        if(positives.size()>2){
            result= Math.max(result,positives.getLast()*positives.get(positives.size()-2)*positives.get(positives.size()-3)) ;
        }
        return result;
    }
}
