import Problems.*;

public class Main {
    public static void main(String[] args) {
        BaseProblem problem = new LeetCode3558NumberOfWaysToAssignEdgeWeightsI();
        problem.Run();
        printScriptName("3558. Number of Ways to Assign Edge Weights I");
        convertSquareToCurly("[[1,2],[1,3],[3,4],[3,5]]");
    }

    private static void printScriptName(String rawScriptName) {
        String name = convertScriptName(rawScriptName);
        String commitName = "feat: add " + name + " Java";
        System.out.println(name);
        System.out.println(commitName);
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
        System.out.println(new String(chars));
    }
}
