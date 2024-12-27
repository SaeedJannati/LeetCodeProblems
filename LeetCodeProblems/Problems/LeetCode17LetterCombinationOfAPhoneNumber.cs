using System.Reflection.Metadata.Ecma335;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode17LetterCombinationOfAPhoneNumber : BaseProblemClass
{
    private Dictionary<char, List<char>> keyBoard = new Dictionary<char, List<char>>()
    {
        { '2', ['a', 'b', 'c'] },
        { '3', ['d', 'e', 'f'] },
        { '4', ['g', 'h', 'i'] },
        { '5', ['j', 'k', 'l'] },
        { '6', ['m', 'n', 'o'] },
        { '7', ['p', 'q', 'r', 's'] },
        { '8', ['t', 'u', 'v'] },
        { '9', ['w', 'x', 'y', 'z'] }
    };

    public IList<string> LetterCombinations(string digits)
    {
        if (digits == null)
            return [];
        if (digits.Length == 0)
            return [];
        List<string> output = [];
        for (int i = 0, e = digits.Length; i < e; i++)
        {
            AddNewLetter(digits[i],ref output);
        }

        return output;
    }

    private void AddNewLetter(char letter,ref List<string>outPut) 
    {
        List<string> temp = [];
        if (outPut.Count == 0)
        {
            keyBoard[letter].ForEach(k => { temp.Add($"{k}"); });
        }

        outPut.ForEach(i => { keyBoard[letter].ForEach(k => { temp.Add(i + k); }); });
        outPut= [..temp];
    }

    public override void Run()
    {
        string input = "23";
        var combinations = LetterCombinations(input);
        Console.WriteLine(JsonSerializer.Serialize(combinations));
    }
}



