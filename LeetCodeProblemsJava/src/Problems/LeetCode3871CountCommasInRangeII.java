package Problems;

public class LeetCode3871CountCommasInRangeII {
    public long countCommas(long n) {
        long threshold=999;
        long commosCount=0;
        while (n>threshold){
            commosCount+= n-threshold;
            threshold*=1000;
            threshold+=999;
        }
        return commosCount;
    }
}
