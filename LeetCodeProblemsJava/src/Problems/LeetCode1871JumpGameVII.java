package Problems;

import java.util.Arrays;

public class LeetCode1871JumpGameVII extends BaseProblem {


    public boolean canReach(String s, int minJump, int maxJump) {
        int length = s.length();
        if (s.charAt(length - 1) == '1') {
            return false;
        }
        int[] prefixSum = new int[length];
        int minInd=0;
        int maxInd=0;
        for (int i = 0; i < length; i++) {
            if(i>0){
                prefixSum[i]+=prefixSum[i-1];
                if(prefixSum[i]==0)
                    continue;
            }
            if(s.charAt(i) == '1') {
                continue;
            }


            minInd=i+minJump;
            if(minInd>length-1)
                continue;
            maxInd=i+maxJump;
            prefixSum[minInd]++;
            if(maxInd+1>length-1)
                continue;
            prefixSum[maxInd+1]--;
        }

        return prefixSum[length-1] > 0;
    }

    @Override
    public void Run() {
        String s = "011010";
        int minJump = 2;
        int maxJump = 3;
        IO.println(canReach(s, minJump, maxJump));
    }
}
