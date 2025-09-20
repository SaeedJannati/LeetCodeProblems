#pragma once
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class LeetCode3508ImplementRouter
{
    class Router
    {
        queue<vector<int>> packets{};
        int memoryLimit;
        unordered_map<int, unordered_map<int, unordered_set<int>>> map{};
        unordered_map<int,vector<int>> destMap{};
    public:
        Router(int memoryLimit)
        {
            this->memoryLimit = memoryLimit;
        }
        bool addPacket(int source, int destination, int timestamp)
        {
            if (map.contains(source))
            {
                if (map[source].contains(destination))
                {
                    if (map[source][destination].contains(timestamp))
                        return false;
                }
            }
            if (packets.size()==memoryLimit)
            {
                forwardPacket();
            }
            packets.push({source, destination, timestamp});
            if (!map.contains(source))
            {
                map[source]={};
            }
            if (!map[source].contains(destination))
            {
                map[source][destination]={};
            }
            map[source][destination].insert(timestamp);
            if (!destMap.contains(destination))
            {
                destMap[destination]={};
            }
            destMap[destination].push_back(timestamp);
            return true;
        }

        vector<int> forwardPacket()
        {
            if (packets.empty())
                return {};
            auto packet = packets.front();
            packets.pop();
            map[packet[0]][packet[1]].erase(packet[2]);
            if (map[packet[0]][packet[1]].empty())
            {
                map[packet[0]].erase(packet[1]);
                if (map[packet[0]].empty())
                {
                    map.erase(packet[0]);
                }
            }
           int begin{};
            int end=destMap[packet[1]].size()-1;
            int mid{};
            while (begin<=end)
            {
                mid=(begin+end)>>1;
                if (destMap[packet[1]][mid]==packet[2])
                {
                    break;
                }
                if (destMap[packet[1]][mid]<packet[2])
                {
                    begin=mid+1;
                    continue;
                }
                end=mid-1;
            }
            destMap[packet[1]].erase(destMap[packet[1]].begin()+mid);
            if (destMap[packet[1]].empty())
            {
                destMap.erase(packet[1]);
            }
            return packet;
        }

        int getCount(int destination, int startTime, int endTime)
        {
            int size=destMap[destination].size();
            int minInd{size};
            int begin{};
            int end=size-1;
            int mid{};
            while (begin<=end)
            {
                mid=(begin+end)>>1;
                if (destMap[destination][mid]>=startTime)
                {
                    end=mid-1;
                    minInd=min(minInd, mid);
                    continue;
                }
                begin=mid+1;
            }
            if (minInd==size)
                return 0;
           int maxInd{-1};
            begin=0;
            end=size-1;
            while (begin<=end)
            {
                mid=(begin+end)>>1;
                if (destMap[destination][mid]<=endTime)
                {
                    begin=mid+1;
                    maxInd=max(maxInd, mid);
                    continue;
                }
                
                end=mid-1;
            }
            if (maxInd==-1||maxInd<minInd)
                return 0;
            return maxInd-minInd+1;
        }
    };
};
