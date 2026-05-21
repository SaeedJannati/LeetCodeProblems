package Problems;

public class LeetCode2657FindThePrefixCommonArrayOfTwoArrays extends BaseProblem {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        long firstPrefix = 0;
        long secondPrefix = 0;
        int lengthA = A.length;
        int[] result = new int[lengthA];
        int delta = 0;
        long aElement=0;
        long bElement=0;
        for (int i = 0; i < lengthA; i++) {
            aElement = ((long) 1) << A[i];
            bElement = ((long) 1) << B[i];
            firstPrefix |= aElement;
            secondPrefix |= bElement;
            delta = 0;
            if (A[i] == B[i]) {
                ++delta;
            } else {
                if ((firstPrefix & aElement) > 0 && (secondPrefix & aElement) > 0) {
                    ++delta;
                }
                if ((firstPrefix & bElement) > 0 && (secondPrefix & bElement) > 0) {
                    ++delta;
                }
            }
            result[i] = delta + (i > 0 ? result[i - 1] : 0);
        }
        return result;
    }

    @Override
    public void Run() {
        int[] A = {1, 3,2,4};
        int[] B = {3, 1, 2, 4};
        Auxileries.Print(findThePrefixCommonArray(A, B));
    }
}
