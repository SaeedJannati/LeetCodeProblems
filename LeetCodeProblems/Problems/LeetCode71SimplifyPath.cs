using System.Text;
using Microsoft.VisualBasic;

namespace LeetCodeProblems.Problems;

public class LeetCode71SimplifyPath : BaseProblemClass
{
    //stack
    public string SimplifyPath(string path)
    {
        var words = path.Split('/').ToList();
        words = words.Where(i => i.Length > 0 && !i.Contains('/')).ToList();
        Stack<string> stack = new();
        foreach (var word in words)
        {
            if (word == ".")
                continue;
            if (word == "..")
            {
                if (stack.Count > 0)
                    stack.Pop();
                continue;
            }
            stack.Push(word);
        }
        words=stack.ToList();
        words.Reverse();
        var builder = new StringBuilder();
        builder.Append('/');
        builder.Append( string.Join("/", words));
        return builder.ToString();
    }
    //mySolution
    // public string SimplifyPath(string path)
    // {
    //     var words = path.Split('/').ToList();
    //     words = words.Where(i => i.Length > 0 && !i.Contains('/')).ToList();
    //     int chainedBack = 0;
    //     for (int i = words.Count - 1; i >= 0; i--)
    //     {
    //         if (words[i] == "..")
    //         {
    //             words.RemoveAt(i);
    //             if (i > 0)
    //             {
    //                 if (words[i - 1] == "..")
    //                 {
    //                     chainedBack++;
    //                     continue;
    //                 }
    //                 for (int j = 0; j <= chainedBack; j++)
    //                 {
    //                
    //                     if (i > 0)
    //                     {
    //                         i--;
    //                         if (words[i] == ".")
    //                             j--;
    //                         if (words[i] == "..")
    //                         {
    //                             chainedBack++;
    //                             j--;
    //                         }
    //
    //                         words.RemoveAt(i);
    //                     }
    //                 }
    //
    //                 chainedBack = 0;
    //             }
    //
    //             continue;
    //         }
    //
    //         if (words[i] == ".")
    //         {
    //             words.RemoveAt(i);
    //             continue;
    //         }
    //     }
    //
    //     var builder = new StringBuilder();
    //     builder.Append('/');
    //     builder.Append(string.Join("/", words));
    //     return builder.ToString();
    // }

    public override void Run()
    {
        string path = "/home/of/foo/../../bar/../../is/./here/.";
        Console.WriteLine(SimplifyPath(path));
    }
}