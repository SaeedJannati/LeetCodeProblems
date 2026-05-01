import Problems.BaseProblem;
import Problems.LeetCode396RotateFunction;

public class Main {
    public static void main(String[] args) {
        BaseProblem problem = new LeetCode396RotateFunction();
        problem.Run();
        printScriptName("396. Rotate Function");
    }
    private static void printScriptName(String rawScriptName) {
         String name=convertScriptName(rawScriptName);
         String commitName= "feat: add "+name+" Java";
         IO.println(name);
         IO.println(commitName);
    }
    private static String convertScriptName(String rawScriptName) {
           var result=new StringBuilder();
           int rawLength=rawScriptName.length();
           for (int i=0;i<rawLength;i++){
               if (rawScriptName.charAt(i)!=' ' && rawScriptName.charAt(i)!='-' &&rawScriptName.charAt(i)!='.' &&
                       rawScriptName.charAt(i)!='(' && rawScriptName.charAt(i)!=')' &&rawScriptName.charAt(i)!='[' &&
                       rawScriptName.charAt(i)!=']' && rawScriptName.charAt(i)!='{' &&rawScriptName.charAt(i)!='}' &&
                       rawScriptName.charAt(i)!='\'' && rawScriptName.charAt(i)!='/'
               ){
                    result.append(rawScriptName.charAt(i));
               }
           }
        return  "LeetCode"+result;
    }
}
