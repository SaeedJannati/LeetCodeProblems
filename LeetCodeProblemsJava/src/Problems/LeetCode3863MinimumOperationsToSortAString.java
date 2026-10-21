package Problems;

public class LeetCode3863MinimumOperationsToSortAString  extends  BaseProblem{
    public int minOperations(String s) {
        boolean isSorted=true;
        int length=s.length();
        char previous=0;
        char minChar=255;
        int minCharOccurrences =0;
        int minCharMaxPos=0;

        char maxChar=0;
        int maxCharOccurrences =0;
        int maxCharMinPos=0;

        for(int i=0;i<length;i++){
            if(s.charAt(i)<previous){
                isSorted=false;
            }
            previous=s.charAt(i);
            if (s.charAt(i)==maxChar){
                maxCharOccurrences++;
            }
            else if(s.charAt(i)>maxChar){
                maxCharOccurrences=1;
                maxChar=s.charAt(i);
                maxCharMinPos=i;
            }
            if(s.charAt(i)==minChar){
                minCharOccurrences++;
                minCharMaxPos=i;
            }else if(s.charAt(i)<minChar){
                minCharOccurrences=1;
                minChar=s.charAt(i);
                minCharMaxPos=i;
            }
        }
        if(isSorted){
            return 0;
        }
        if(length==2){
            return -1;
        }
        if(s.charAt(0)==minChar ||  s.charAt(length-1)==maxChar){
            return 1;
        }
        if((maxCharMinPos==0 && maxCharOccurrences==1)&&(minCharMaxPos==length-1 && minCharOccurrences==1)){
            return 3;
        }
        return 2;
    }

    @Override
    public void Run() {
        String s="cab";
        System.out.println(minOperations(s));
    }
}
