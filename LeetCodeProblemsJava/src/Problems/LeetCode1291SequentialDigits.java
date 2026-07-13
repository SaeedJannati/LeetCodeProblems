package Problems;

import java.util.ArrayList;
import java.util.List;

public class LeetCode1291SequentialDigits {
    public List<Integer> sequentialDigits(int low, int high) {
        int minDigitCount=getDigitCount(low);
        int maxDigitCount=getDigitCount(high);
        List<Long> candidates=new ArrayList<>();
        long numToAdd=0;
        boolean found=false;
        for (int i=minDigitCount; i<=maxDigitCount; i++) {
            for(int j=1;j<=9;j++){
                numToAdd=j;
                found=true;

                for(int k=1;k<i;k++){
                    if (j+k>9){
                        found=false;
                        break;
                    }
                    numToAdd*=10;
                    numToAdd+=j+k;
                }
                if(found){
                    candidates.add(numToAdd);
                }
            }
        }
        List<Integer> result=new ArrayList<>();
        for(var num:candidates){
            if(num>=low && num<=high){
                result.add(num.intValue() );
            }
        }
        return result;
    }
    private int getDigitCount(int num) {
        int count = 0;
        while (num != 0) {
            num /= 10;
            count++;
        }
        return count;
    }
}
