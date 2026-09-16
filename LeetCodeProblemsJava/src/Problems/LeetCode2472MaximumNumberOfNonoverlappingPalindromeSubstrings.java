package Problems;

import java.util.Arrays;

public class LeetCode2472MaximumNumberOfNonoverlappingPalindromeSubstrings extends BaseProblem {
    public int maxPalindromes(String s, int k) {
        char[] str = s.toCharArray();
        int length = str.length;
        int[][] dp = new int[length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                dp[i][j] = -1;
            }
        }
        int[] result = new int[length];
        Arrays.fill(result, -1);
        int output= calcResult(str,dp,result,k,length-1);
        return output;
    }

    int calcResult(char[] str,int[][] dp,int[] result, int k, int i) {
        if (i < k - 1)
            return 0;
        if(result[i] != -1){
            return result[i];
        }
        int max = 0;
        for (int j = i; j >= 0; j--) {
            max = Math.max(max, ((isPalindrome(str,dp,j,i))&& i-j+1>=k?1:0) + calcResult(str,dp,result, k, j - 1));
        }
        result[i] = max;
        return max;
    }

    boolean isPalindrome(char[] str, int[][] dp, int start, int end) {
        if (start > end)
            return false;
        if (dp[start][end] != -1)
            return dp[start][end] == 1;
        if(end-start==1){
            dp[start][end]=(str[start]==str[end]?1:0);
            return dp[start][end]==1;
        }
        if (start == end) {
            dp[start][end] = 1;
            return true;
        }
        if (str[start] != str[end]) {
            dp[start][end] = 0;
            return false;
        }
        if (isPalindrome(str, dp, start + 1, end - 1)) {
            dp[start][end] = 1;
            return true;
        }
        dp[start][end] = 0;
        return false;
    }

    @Override
    public void Run() {
        String input=
//                "aaaaa";
                "abaccdbbd";
        int k=3;
        System.out.println(maxPalindromes(input,k));
    }
}
