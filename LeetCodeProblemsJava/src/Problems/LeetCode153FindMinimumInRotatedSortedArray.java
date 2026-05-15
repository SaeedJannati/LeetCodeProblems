package Problems;

public class LeetCode153FindMinimumInRotatedSortedArray {
    public int findMin(int[] nums) {
        int length = nums.length;
        if (length == 1)
            return nums[0];
        if (length == 2)
            return Math.min(nums[0], nums[1]);
        int begin=1,end=length-2,mid=0,found=length;
        while (begin<=end) {
            mid = (begin+end)>>1;
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                return  nums[mid];
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[mid]>nums[length-1]){
                begin=mid+1;
                continue;
            }
            end=mid-1;
        }
        return Math.min(nums[0],nums[length-1]);
    }
}
