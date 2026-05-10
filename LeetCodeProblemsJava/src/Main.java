import Problems.*;

public class Main {
    public static void main(String[] args) {
        BaseProblem problem = new LeetCode2770MaximumNumberOfJumpsToReachTheLastIndex();
        problem.Run();
        printScriptName("2770. Maximum Number of Jumps to Reach the Last Index");
        convertSquareToCurly("[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]");
    }

    private static void printScriptName(String rawScriptName) {
        String name = convertScriptName(rawScriptName);
        String commitName = "feat: add " + name + " Java";
        IO.println(name);
        IO.println(commitName);
    }

    private static String convertScriptName(String rawScriptName) {
        var result = new StringBuilder();
        int rawLength = rawScriptName.length();
        for (int i = 0; i < rawLength; i++) {
            if (rawScriptName.charAt(i) == ' ' && i + 1 < rawLength) {
                result.append(Character.toUpperCase(rawScriptName.charAt(i + 1)));
                ++i;
                continue;
            }
            if (rawScriptName.charAt(i) != ' ' && rawScriptName.charAt(i) != '-' && rawScriptName.charAt(i) != '.' &&
                    rawScriptName.charAt(i) != '(' && rawScriptName.charAt(i) != ')' && rawScriptName.charAt(i) != '[' &&
                    rawScriptName.charAt(i) != ']' && rawScriptName.charAt(i) != '{' && rawScriptName.charAt(i) != '}' &&
                    rawScriptName.charAt(i) != '\'' && rawScriptName.charAt(i) != '/'
            ) {
                result.append(rawScriptName.charAt(i));
            }
        }
        return "LeetCode" + result;
    }

    private static void convertSquareToCurly(String raw) {
        char[] chars = raw.toCharArray();
        for (int i = 0; i < raw.length(); i++) {
            if (chars[i] == '[') {
                chars[i] = '{';
            } else if (chars[i] == ']') {
                chars[i] = '}';
            }
        }
        IO.println(new String(chars));
    }
}
