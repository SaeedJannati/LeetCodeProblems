package Problems;

public class LeetCode3751TotalWavinessOfNumbersInRangeI {
    public int totalWaviness(int num1, int num2) {
        int result = 0;
        for (int i = num1; i <= num2; i++) {
            result += getWaviness(i);
        }
        return result;
    }
    private int getWaviness(int num) {
        int previous=num%10;
        num/=10;
        int current=0;
        int result=0;
        int next=0;
        while (num>0){
            current=num%10;
            num/=10;
            if(num==0)
                break;
            next=num%10;
            if( current>previous && current>next)
                result++;
            if( current<previous && current<next)
                result++;
            previous=current;
        }
        return result;
    }
}
