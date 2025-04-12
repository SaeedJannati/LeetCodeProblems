using System.Text.Json;
using Newtonsoft.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode3272FindTheCountOfGoodIntegers : BaseProblemClass
{
    class NumStr
    {
        public NumStr(string s, bool fillNum = false)
        {
            str = s;
            if (!fillNum)
                return;
            num = GetNum(str);
        }

        public string str;
        public long num;

        public long GetNum(string s)
        {
            long result = 0;
            long pow = 1;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                result += pow * (str[i] - '0');
                pow *= 10;
            }

            return result;
        }
    }

    public long CountGoodIntegers(int n, int k)
    {
        long result = 0;
        if (n == 1)
        {
            for (int i = 1; i < 10; i++)
            {
                if (i % k == 0)
                    result++;
            }

            return result;
        }

        int half = n / 2;
        List<NumStr> nums = [];
        string current = "";
        long beginNum = (int)Math.Pow(10, half-1);
        long endNum = (int)Math.Pow(10, half)-1;
        for (long i = beginNum; i <= endNum; i++)
        {
            nums.Add(new NumStr(i.ToString()));
        }
        if (n % 2 == 0)
        {
            for (int i = 0, e = nums.Count; i < e; i++)
            {
                nums[i].str += new String(nums[i].str.Reverse().ToArray());
                nums[i].num = GetNum(nums[i].str);
            }
        }
        else
        {
            int length = nums.Count;
            for (int i = 1; i <= 9; i++)
            {
                for (int j = length - 1; j >= 0; j--)
                {
                    nums.Add(new($"{nums[j].str}{i}{new string(nums[j].str.Reverse().ToArray())}", true));
                }
            }

            for (int j = length - 1; j >= 0; j--)
            {
                nums[j].str = $"{nums[j].str}{0}{new string(nums[j].str.Reverse().ToArray())}";
                nums[j].num = GetNum(nums[j].str);
            }
        }

        int[] digitCount = new int[10];
        int zeroCount = 0;
        Dictionary<long, long> factMemo = [];
        factMemo[1] = 1;
        factMemo[0] = 1;
        List<int[]> addedNums = [];
        for (int i = 0, e = nums.Count; i < e; i++)
        {
            if (nums[i].num % k != 0)
                continue;
            zeroCount = 0;
            for (int j = 1; j < 10; j++)
            {
                digitCount[j] = 0;
            }

       
            for (int j = 0; j < n; j++)
            {
                if (nums[i].str[j] == '0')
                {
                    zeroCount++;
                    continue;
                }

                digitCount[nums[i].str[j] - '0']++;
            }

            int[] toadd = new int[10];
            toadd[0]=zeroCount;
            for (int ii = 1; ii < 10; ii++)
            {
                toadd[ii] = digitCount[ii];
            }
            bool shouldCheck = true;
            bool shouldContinue = false;
            foreach (var added in addedNums)
            {
                shouldContinue = false;
                if (zeroCount != added[0])
                {
                    continue;
                }

                for (int h = 1; h < 10; h++)
                {
                    if (digitCount[h] != added[h])
                    {
                        shouldContinue = true; 
                        break;
                    }
                    if(shouldContinue)
                        break;
                }

                if (!shouldContinue)
                {
                    shouldCheck = false;
                    break;
                }
            }
            if (!shouldCheck)
                continue;
            addedNums.Add(toadd);
            long delta = Fact(n, factMemo);
            for (int j = 1; j < 10; j++)
            {
                delta /= Fact(digitCount[j], factMemo);
            }

            if (zeroCount != 0)
            {
                delta /= Fact(zeroCount, factMemo);

                long num = Fact(n - 1, factMemo);
                for (int j = 1; j < 10; j++)
                {
                    num /= Fact(digitCount[j], factMemo);
                }

                num /= Fact(zeroCount - 1, factMemo);
                delta -= num;
            }

            result += delta;
        }

        return result;
    }

    public long Fact(long n, Dictionary<long, long> factMemo)
    {
        if (factMemo.TryGetValue(n, out var fact))
            return fact;
        factMemo[n] = Fact(n - 1, factMemo) * n;
        return factMemo[n];
    }

    public long GetNum(string s)
    {
        long result = 0;
        long pow = 1;
        for (int i = s.Length - 1; i >= 0; i--)
        {
            result += pow * (s[i] - '0');
            pow *= 10;
        }

        return result;
    }

    void CalcIncreasingNums(int index, int halfLength, char lastDigit, string current, List<NumStr> nums)
    {
        if (index == halfLength)
        {
            nums.Add(new(current));
            return;
        }

        current += 0.ToString();
        CalcIncreasingNums(index + 1, halfLength, lastDigit, current, nums);
        current = current[..index];
        for (var i = lastDigit - '0' + 1; i <= 9; i++)
        {
            current += i.ToString();
            CalcIncreasingNums(index + 1, halfLength, lastDigit, current, nums);
            current = current[..index];
        }
    }

    public override void Run()
    {
        int n =
            10;
        int k =
            3;
        var result = CountGoodIntegers(n, k);
        Console.WriteLine(result);
    }
}