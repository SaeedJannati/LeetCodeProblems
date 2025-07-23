#include "LeetCode1717MaximumScoreFromRemovingSubstrings.h"

#include <stack>
using namespace std;
int LeetCode1717MaximumScoreFromRemovingSubstrings::maximumGain( string s, int x, int y)
{
    stack<char> remaining{};
    int score{};
    string firstTarget=x>y?"ab":"ba";
    int firstScore=x>y?x:y;
    string secondTarget=x>y?"ba":"ab";
    int secondScore=x>y?y:x;
    for (char c:s)
    {
        if (remaining.empty())
        {
            remaining.push(c);
            continue;
        }
        auto top=remaining.top();
        if (top==firstTarget[0] && c==firstTarget[1])
        {
            remaining.pop();
            score+=firstScore;
            continue;
        }
        remaining.push(c);
    }
    stack<char> secondRemaining{};
    while (!remaining.empty())
    {
        auto c=remaining.top();
        remaining.pop();
        if (secondRemaining.empty())
        {
            secondRemaining.push(c);
            continue;
        }
        auto top=secondRemaining.top();
        if (top==secondTarget[1] && c==secondTarget[0])
        {
            secondRemaining.pop();
            score+=secondScore;
            continue;
        }
        secondRemaining.push(c);
    }
    return score;
}
