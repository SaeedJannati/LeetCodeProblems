//
// Created by saeed on 9/21/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1912DESIGNMOVIERENTALSYSTEM_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1912DESIGNMOVIERENTALSYSTEM_H
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class LeetCode1912DesignMovieRentalSystem {
    class MovieRentingSystem {
    private:
        unordered_map<int, map<int, set<int> > > availableMovies{}; //[movie][price][shop]
        map<int, map<int, set<int>> > cheapest{}; //[price][shop][movie]
        unordered_map<int, unordered_map<int, int> > inventory{}; //[shop][movie]-> price
    public:
        MovieRentingSystem(int n, vector<vector<int> > &entries) {
            for (auto &entry: entries) {
                if (!inventory.contains(entry[0])) {
                    inventory[entry[0]] = {};
                }
                inventory[entry[0]][entry[1]] = entry[2];
                if (!availableMovies.contains(entry[1])) {
                    availableMovies[entry[1]] = {};
                }
                if (!availableMovies[entry[1]].contains(entry[2])) {
                    availableMovies[entry[1]][entry[2]] = {};
                }
                availableMovies[entry[1]][entry[2]].insert(entry[0]);
            }
        }

        vector<int> search(int movie) {
            vector<int> result{};
            if (!availableMovies.contains(movie)) {
                return result;
            }
            int itemCount{};
            for (auto it=availableMovies[movie].begin(); it!=availableMovies[movie].end(); ++it) {
                for (auto jt=it->second.begin(); jt!=it->second.end(); ++jt) {
                    result.push_back(*jt);
                    itemCount++;
                    if (itemCount==5)
                        return result;
                }
            }
            return result;
        }

        void rent(int shop, int movie) {
            auto price = inventory[shop][movie];
            availableMovies[movie][price].erase(shop);
            if (!cheapest.contains(price)) {
                cheapest[price] = {};
            }
            if (!cheapest[price].contains(shop)) {
                cheapest[price][shop] = {};
            }
            cheapest[price][shop].insert(movie);
        }

        void drop(int shop, int movie) {
            auto price = inventory[shop][movie];
            availableMovies[movie][price].insert(shop);
            cheapest[price][shop].erase(movie);
            if (cheapest[price][shop].empty()) {
                cheapest[price].erase(shop);
            }
            if (cheapest[price].empty()) {
                cheapest.erase(price);
            }
        }

        vector<vector<int> > report() {
            int itemCount{};
            vector<vector<int> > result{};
            for (auto it = cheapest.begin(); it != cheapest.end(); ++it) {
                for (auto i = it->second.begin(); i != it->second.end(); ++i) {
                   for (auto j = i->second.begin(); j != i->second.end(); ++j) {
                       result.push_back({i->first,*j});
                       itemCount++;
                       if (itemCount == 5)
                           return result;
                   }

                }
            }
            return result;
        }
    };
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1912DESIGNMOVIERENTALSYSTEM_H
