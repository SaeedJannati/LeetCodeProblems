//
// Created by saeed on 9/19/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3484DESIGNSPREADSHEET_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3484DESIGNSPREADSHEET_H
#include <string>
#include <vector>
using namespace std;

class LeetCode3484DesignSpreadsheet {
    class Spreadsheet {
    private:
        vector<vector<int> > spreadsheet{};
        pair<int, int> cellInfo{};
        bool isCellInfo(string & input) {
            if (input.empty())
                return false;
            if (input[0]>='A' && input[0]<='Z')
                return true;
            return false;
        }
        void fillCellInfo(string & cell) {
            cellInfo.first=cell[0]-'A';
            cellInfo.second=0;
            for (int i=1,e=cell.size(); i<e; i++) {
                cellInfo.second*=10;
                cellInfo.second+=cell[i]-'0';
            }
            cellInfo.second--;
        }
        int getStringValue(string & input) {
            if (isCellInfo(input)) {
                fillCellInfo(input);
                return spreadsheet[cellInfo.first][cellInfo.second];
            }
            int result = 0;
            for (int i=0,e=input.size(); i<e; i++) {
                result = result*10+input[i]-'0';
            }
            return result;
        }
    public:
        Spreadsheet(int rows) {
            spreadsheet = vector<vector<int> >(26, vector<int>(rows, 0));
        }

        void setCell(string cell, int value) {
            fillCellInfo(cell);
            spreadsheet[cellInfo.first][cellInfo.second]=value;
        }

        void resetCell(string cell) {
            fillCellInfo(cell);
            spreadsheet[cellInfo.first][cellInfo.second]=0;
        }

        int getValue(string formula) {
            int result{};
            string first{};
            int length=formula.length();
            int value{};
            for (int i=1,e=length; i<e; i++) {
                if (formula[i]=='+') {
                    result=getStringValue(first);
                    first={};
                    continue;
                }
                first+=formula[i];
            }
            result+=getStringValue(first);
            return result;
        }
    };
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3484DESIGNSPREADSHEET_H
