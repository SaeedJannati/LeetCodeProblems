namespace LeetCodeProblems.Problems;

public class LeetCode58LengthOfLastWord
{
    public int LengthOfLastWord(string s)
    {
        var words = s.Split(' ');
        string current = "";
        for (int i = words.Length-1; i >= 0; i--)
        {
            current = words[i].Replace(" ","");
            if(current.Length>0)
                return current.Length;
        }

        return 0;
    }
}