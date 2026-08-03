package Problems;

public class LeetCode1406StoneGameIII extends BaseProblem {
    public String stoneGameIII(int[] stoneValue) {
        int length = stoneValue.length;
        long[] prefixSum = new long[length + 1];
        long[] memoisation = new long[length];
        for (int i = 0; i < length; i++) {
            memoisation[i] = Long.MIN_VALUE;
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        long aliceMax = getMaxInRange(prefixSum, memoisation, length, 0);
        long bob = prefixSum[length] - aliceMax;
        if (aliceMax > bob) {
            return "Alice";
        }
        if (aliceMax < bob) {
            return "Bob";
        }
        return "Tie";

    }

    public long getMaxInRange(long[] prefixSum, long[] memoisation, int length, int start) {
        if (start >= length) {
            return 0;
        }
        if (memoisation[start] != Long.MIN_VALUE) {
            return memoisation[start];
        }
        long sum = prefixSum[length] - prefixSum[start];
        long result = Math.min(getMaxInRange(prefixSum, memoisation, length, start + 1), getMaxInRange(prefixSum, memoisation, length, start + 2));
        result = Math.min(result, getMaxInRange(prefixSum, memoisation, length, start + 3));
        result = sum - result;
        memoisation[start] = result;
        return memoisation[start];
    }

    @Override
    public void Run() {
        int[] stones = {1, 2, 3, 6};
        System.out.println(stoneGameIII(stones));
    }
}
