package Problems;

public class LeetCode1510StoneGameIV {
    public boolean winnerSquareGame(int n) {
        byte[] memoisation=new byte[n+1];
        for(int i=1;i<=n;i++){
            memoisation[i]=2;
        }
        return canWin(memoisation,n);
    }

    boolean canWin(byte[] memoisation,int num) {
        if(memoisation[num]!=2){
            return memoisation[num]==1;
        }
        int squareRoot = (int) Math.sqrt(num);
        if (squareRoot * squareRoot == num) {
            memoisation[num] = 1;
            return memoisation[num]==1;
        }
        int square=0;
        for (int i=1;i<=squareRoot;i++){
            square=i*i;
            if(!canWin(memoisation,num-square)){
                memoisation[num] = 1;
                return memoisation[num]==1;
            }
        }
        memoisation[num] = 0;
        return memoisation[num]==1;
    }
}
