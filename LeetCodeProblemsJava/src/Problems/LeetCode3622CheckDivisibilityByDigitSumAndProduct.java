package Problems;

public class LeetCode3622CheckDivisibilityByDigitSumAndProduct {
    public boolean checkDivisibility(int n) {
            long digitProduct = 1;
            long digitSum = 0;
            int digit;
            int m=n;
            while(n>0){
                digit = n%10;
                digitSum += digit;
                digitProduct = digitProduct*digit;
                n = n/10;
            }
            return (m%(digitSum+digitProduct))==0;
    }
}
