#include "LeetCode3477FruitsIntoBasketsII.h"
using namespace std;

int LeetCode3477FruitsIntoBasketsII::numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
{
    int fruitsPlaced{0};
    for (auto fruit : fruits)
    {
        for (int i = 0, e = static_cast<int>(baskets.size()); i < e; i++)
        {
            if (baskets[i] < fruit)
                continue;
            baskets[i] = -1;
            fruitsPlaced++;
            break;
        }
    }
    return fruits.size() - fruitsPlaced;
}
