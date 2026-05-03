package Problems;

public class LeetCode796RotateString extends BaseProblem {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length())
            return false;
        int index=0;
        for(int i=0,e=s.length();i<e;i++){
             if(s.charAt(0)!=goal.charAt(i)){
                 continue;
             }
             boolean isMatch=true;
             for(int j=1;j<e;j++){
                 index=(i+j)%s.length();
                 if(s.charAt(j)!=goal.charAt(index)) {
                     isMatch=false;
                     break;
                 }
             }
             if(isMatch){return  true;}
        }
        return false;
    }

    @Override
    public void Run() {
      String s="gcmbf";
      String goal="fgcmb";
      IO.println(rotateString(s,goal));
    }
}
