namespace LeetCodeProblems.Problems;

public class LeetCode443StringCompression: BaseProblemClass
{
    public int Compress(char[] chars)
    {
        if (chars == null || chars.Length == 0)
            return 0;
        int length = chars.Length;
        int firstPointer = 0;
        int secondPointer = 1;
        int counter = 1;
        int totalCounter = 0;
        char currentChar = chars[firstPointer];
        while (secondPointer < length)
        {
            if (currentChar == chars[secondPointer])
            {
                counter++;
            }
            else
            {
                chars[firstPointer] = currentChar;
                currentChar = chars[secondPointer];
                if (counter > 1)
                {
                    var numChars = GetChars(counter);
                    for (int i = 0, e = numChars.Count; i < e; i++)
                    {
                        firstPointer++;
                        chars[firstPointer] = numChars[i];
                    }
                    firstPointer++;
                }
                else
                {
                    firstPointer++;
                }
                counter = 1;
            }
            secondPointer++;
        }
     
        chars[firstPointer] = currentChar;
        if (counter > 1)
        {
            var numChars = GetChars(counter);
            for (int i = 0, e = numChars.Count; i < e; i++)
            {
                firstPointer++;
                chars[firstPointer] = numChars[i];
            }
        }
        firstPointer++;
        return Math.Max(firstPointer,1);
    }

   private List<char> GetChars(int num)
    {
        var output = new List<char>();
        while (num > 0)
        {
            output.Add(GetChar(num%10));
            num /= 10;
        }
        output.Reverse();
        return output;
    }

    private char GetChar(int num)
    {
        return num switch
        {
            1 => '1',
            2 => '2',
            3 => '3',
            4 => '4',
            5 => '5',
            6 => '6',
            7 => '7',
            8 => '8',
            9 => '9',
            0 => '0',
            _ => '_'
        };
    }

    public override void Run()
    {
        char[] chars =
            ['a', 'a', 'a', 'a', 'a', 'b'];
            // ['a', 'a', 'a', 'b', 'b', 'a', 'a']; 
            // ['a'];
            // ['a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']; 
            // ['a', 'a', 'b', 'b', 'c', 'c', 'c'];
        var length=Compress(chars);
        Console.WriteLine($"{length}|{new string(chars)}");
    }
}