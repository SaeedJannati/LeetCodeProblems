namespace LeetCodeProblems.Problems;

public class LeetCode165CompareVersionNumbers: BaseProblemClass
{
    public int CompareVersion(string version1, string version2)
    {
        var version1Parts = version1.Split('.');
        var version1Nums= new int[version1Parts.Length];
        for(int i=0; i < version1Parts.Length;i++)
        {
            version1Nums[i] = ConvertToNumber(version1Parts[i]);
        }
        var version2Parts = version2.Split('.');
        var version2Nums= new int[version2Parts.Length];
        for(int i=0; i < version2Parts.Length;i++)
        {
            version2Nums[i] = ConvertToNumber(version2Parts[i]);
        }

        int index = 0;
        int max=int.Max(version1Nums.Length, version2Nums.Length);
        while (index<max)
        {
            if (index < version1Nums.Length && index < version2Nums.Length)
            {
                if(version1Nums[index]< version2Nums[index])
                    return -1;
                if(version1Nums[index]> version2Nums[index])
                    return 1;
            }
            else if (index < version1Nums.Length)
            {
                if (version1Nums[index] > 0)
                    return 1;
            }
            else if (index < version2Nums.Length)
            {
                if (version2Nums[index] > 0)
                    return -1;
            }
            index++;
        }
        return 0;
    }

    private int ConvertToNumber(string version)
    {
        if (version.Length == 0)
            return 0;
        int endIndex = -1;
        for (int i = 0; i < version.Length; i++)
        {
            if (version[i] != '0')
                break;
            endIndex = i;
        }

        if (endIndex == version.Length - 1)
            return 0;
        int num = 0;
        int powerOfTen = 1;
        for (int i = version.Length - 1; i > endIndex; i--)
        {
            num += (version[i] - '0') * powerOfTen;
            powerOfTen *= 10;
        }

        return num;
    }

    public override void Run()
    {
        string version1 = "1.0020";
        string version2 = "1.10";
        Console.WriteLine(CompareVersion(version1, version2));
        
    }
}