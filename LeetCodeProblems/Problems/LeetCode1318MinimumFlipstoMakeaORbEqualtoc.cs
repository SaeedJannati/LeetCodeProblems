namespace LeetCodeProblems.Problems;

public class LeetCode1318MinimumFlipstoMakeaORbEqualtoc
{
    public int MinFlips(int a, int b, int c) 
    {
        var binaryA=ConvertToBinary(a);
        var binaryB=ConvertToBinary(b);
        var binaryC=ConvertToBinary(c);
        int target = 0;
        int flips = 0;
        int aDigit = 0;
        int bDigit = 0;
        while (binaryC.Count>0)
        {
            target = binaryC.Dequeue();
            aDigit = GetNext(binaryA).value;
            bDigit = GetNext(binaryB).value;
            if (target == 0)
            {
                if(aDigit==1)
                    flips++;
                if(bDigit==1)
                    flips++;
                continue;
            }
            if(aDigit==1 || bDigit==1)
                continue;
            flips++;
        }

        while (binaryA.Count>0)
        {
            if (binaryA.Dequeue()==0)
                continue;
            flips++;
        }

        while (binaryB.Count>0)
        {
            if(binaryB.Dequeue()==0)
                continue;
            flips++;
        }
        return flips;
    }

    private (bool hasValue, int value) GetNext(Queue<int> queue)
    {
        if(queue.Count == 0)
            return (false, 0);
        return (true, queue.Dequeue());
    }

    private Queue<int> ConvertToBinary(int num)
    {
        var output = new Queue<int>();
        while (num>0)
        {
            output.Enqueue(num % 2);
            num /= 2;
        }

        return output;
    }

  
}