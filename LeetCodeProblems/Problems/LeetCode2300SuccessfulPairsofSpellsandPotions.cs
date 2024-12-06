using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2300SuccessfulPairsofSpellsandPotions: BaseProblemClass
{
    public int[] SuccessfulPairs(int[] spells, int[] potions, long success) {
        Array.Sort(potions);
        int length = potions.Length;
        long product = 0;
        for (int i = 0, e = spells.Length; i < e; i++)
        {
            product = (long)spells[i] * potions[0];
            if (product >= success)
            {
                spells[i] = length;
                continue;
            }
            product = (long)spells[i] * potions[^1];
            if(product<success)
            {
                spells[i] = 0;
                continue;
            }
            spells[i] = length- FindIndex(spells[i],potions,success)-1;
        }

        return spells;
    }

    private int FindIndex(int spell, int[] potions, long success)
    {
        int begin = 0;
        int last = potions.Length - 1;
        int end = last;
        int mid = 0;
        int next = 0;
        long product = 0;
        long nextProduct = 0;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            next=mid<last?mid+1 : mid ;
                product =(long)spell * potions[mid] ;
         
                nextProduct =(long)spell*potions[next];
         
            
            if (product < success && nextProduct >= success)
            {
                return mid;
            }
            if(product<success)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        if (mid == 0 && product >= success)
            return -1;
        return mid;
    }

    public override void Run()
    {
        int[] spells = [];
        int[] potions = [];
        long success = 9505642132;
        Console.WriteLine(JsonSerializer.Serialize(SuccessfulPairs(spells, potions, success)));
    }
}