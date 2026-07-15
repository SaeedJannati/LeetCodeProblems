package Problems;

public class LeetCode3658GCDOfOddAndEvenSums {
    public int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;

        oddSum = (n) * (n);
        evenSum = (1 + n) * (n);

        return greatestCommonDivisor(oddSum, evenSum);

    }

    private int greatestCommonDivisor(int a, int b) {
        if (b == 0) {
            return a;
        }
        return greatestCommonDivisor(b, a % b);
    }
}
