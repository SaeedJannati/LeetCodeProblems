namespace LeetCodeProblems.Auxilaries;

public class ScriptNameConvertor
{
    public static void PrintScriptName(string scriptName)
    {
        var name = ConvertScriptName(scriptName);
        var commitName = $"feat: add {name}";
        Console.WriteLine(name);
        Console.WriteLine(commitName);
    }
    private static string ConvertScriptName(string input)
    {
        var charArray = input.ToCharArray();
        for (int i = 0, e = charArray.Length - 1; i < e; i++)
        {
            if (charArray[i] == ' ')
                charArray[i + 1] = $"{charArray[i + 1]}".ToUpper().First();
        }
        input = string.Join("", charArray);
        input=input
            .Replace(" ","")
            .Replace("-","")
            .Replace(".", "")
            .Replace("(", "")
            .Replace(")", "")
            .Replace("[", "")
            .Replace("]", "")
            .Replace("{", "")
            .Replace("}", "");
        input = $"LeetCode{input}";
        return input;
    }
}