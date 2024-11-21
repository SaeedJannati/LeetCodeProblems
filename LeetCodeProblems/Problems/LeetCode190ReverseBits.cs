namespace LeetCodeProblems.Problems;

public class LeetCode190ReverseBits
{
    public uint reverseBits(uint n)
    {
        Stack<bool> binary = [];

        for (int i = 0; i < 32; i++)
        {
            binary.Push(n % 2 == 1);
            n /= 2;
        }

        uint result = 0;
        uint coefficient = 0;
        for (int i = 0; i < 32; i++)
        {
            coefficient=(uint)(binary.Pop()? 1 : 0);
            if(coefficient == 0)
                continue;
            result += coefficient*(uint)Math.Pow(2, i);
        }

        return result;
    }
}