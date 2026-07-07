package Problems;

public class LeetCode3754ConcatenateNonZeroDigitsAndMultiplyBySumI {
    public long sumAndMultiply(int n) {
        long[] digitsSum = new long[]{0};
        long zeroRemoved=removeZeroes(n, digitsSum);
        return zeroRemoved*digitsSum[0];
    }
    private long removeZeroes(int n,long[] digitsSum){
        int powOfTen=1;
        int result=0;
        while (n>0){
            if(n%10!=0){
                result+= (n%10)*powOfTen;
                digitsSum[0]+=n%10;
                powOfTen*=10;
            }
            n/=10;
        }
        return result;
    }
}
