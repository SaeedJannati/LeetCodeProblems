#pragma once
#include <vector>

class LeetCode2043SimpleBankSystem
{
public:
    class Bank
    {
    public:
        std::vector<long long> balances{};
        int size{};
        Bank(std::vector<long long>& balance)
        {
            size  = static_cast<int>( balance.size());
            balances.reserve(size);
            for (const auto& b : balance)
            {
                balances.push_back(b);
            }
            
        }

        bool transfer(int account1, int account2, long long money)
        {
            if (account1>size || account2>size)
                return false;
            if (balances[account1-1]<money)
                return  false;
            balances[account1-1]-=money;
            balances[account2-1]+=money;
            return true;
        }

        bool deposit(int account, long long money)
        {
            if (account>size)
                return false;
            balances[account-1]+=money;
        }

        bool withdraw(int account, long long money)
        {
            if (account>size)
                return false;
            if (balances[account-1]<money)
                return false;
            balances[account-1]-=money;
            return true;
        }
    };
};
