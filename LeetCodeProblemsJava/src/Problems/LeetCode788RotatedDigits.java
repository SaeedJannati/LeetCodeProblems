package Problems;

import java.util.HashSet;
import java.util.Set;

public class LeetCode788RotatedDigits {

    public int rotatedDigits(int n) {
        HashSet<Integer> changeAble = new HashSet<Integer>(Set.of(2, 5, 6, 9));
        Set<Integer> nosSuitable = new HashSet<Integer>(Set.of(4, 7,3));
        int validNumCount = 0;
        boolean changeAbleFlag = false;
        boolean notSuitableFlag = false;
        int digit = 0;
        int num = 0;
        for (int i = 2; i <= n; i++) {
            num = i;
            changeAbleFlag = false;
            notSuitableFlag = false;
            while (num > 0) {
                digit = num % 10;
                num = num / 10;
                if(nosSuitable.contains(digit)) {
                    notSuitableFlag = true;
                    break;
                }
                if(changeAble.contains(digit)) {
                    changeAbleFlag = true;
                }
            }
            if(notSuitableFlag) {
                continue;
            }
            if(changeAbleFlag) {
                validNumCount++;
            }
        }
        return validNumCount;
    }
}
