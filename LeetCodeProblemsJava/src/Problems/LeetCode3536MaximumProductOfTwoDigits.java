package Problems;

import java.util.Arrays;

public class LeetCode3536MaximumProductOfTwoDigits {
    public int maxProduct(int n) {
        int[] digitFrequencies = new int[10];
        while (n > 0) {
            digitFrequencies[n % 10]++;
            n /= 10;
        }
        int chosenCount=0;
        int maxProduct=1;
        for (int i=9;i>=0;i--){
            while(digitFrequencies[i]>0&&chosenCount<2){
                chosenCount++;
                digitFrequencies[i]--;
                maxProduct*=i;
            }
        }
        return maxProduct;
    }
}
