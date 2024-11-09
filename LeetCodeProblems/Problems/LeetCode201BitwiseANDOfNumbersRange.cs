namespace LeetCodeProblems.Problems;

public class LeetCode201BitwiseANDOfNumbersRange: BaseProblemClass
{
    public int RangeBitwiseAnd(int left, int right)
    {
        if (left == right)
            return left;
        if ((int) (Math.Log(right) / Math.Log(2)) - (int) (Math.Log(left) / Math.Log(2)) >= 1)
            return 0;
        var rightBinary = GetBinary(right);
        var leftBinary = GetBinary(left);
        return FindNext(leftBinary,rightBinary);
    }

    int FindNext(List<bool> left, List<bool> right)
    {
        HashSet<int> counts = [];
        while (true)
        {
            if (left.Count == 0) 
                break;

            if (!left[^1] && right[^1]) 
                break;
            if (left[^1] && right[^1]) counts.Add(left.Count-1);
            left.RemoveAt(left.Count - 1);
            right.RemoveAt(right.Count - 1);
        }

        int outPut = 0;
        foreach (var num in counts)
        {
            outPut += (int)Math.Pow(2,num);
        }

        return outPut;
    }

    List<bool> GetBinary(int num)
    {
        List<bool> result = [];
        while (num > 0)
        {
            result.Add(num % 2 == 1);
            num /= 2;
        }

        return result;
    }

    public override void Run()
    {
        Console.WriteLine(RangeBitwiseAnd(2,3));
    }
}