#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    map<int, vector<int>> myMap;
    for (int i = 0; i<m; ++i){
        int col, row;
        char direction;
        scanf("%d %d %c", &col, &row, &direction);

        vector<int> doesExists = myMap[col];

        if (doesExists.size() == 0) {
            if (direction == 'U') {
                myMap[col].push_back(col);
                myMap[col].push_back(row);
                myMap[col].push_back(1);

                auto low1 = myMap.lower_bound(col + 1);
                auto findThat = myMap.find(col);
                if (--myMap.end() == findThat) {
                    printf("%d\n", row);
                    myMap[col].push_back(row);
                } else {
                    vector<int> toWhich = (*low1).second;
                    if (toWhich[2] == 1) { //Up
                        printf("%d\n", toWhich[3] + row - toWhich[1]);
                        myMap[col].push_back(toWhich[3] + row - toWhich[1]);
                    } else { //Left
                        printf("%d\n", row - toWhich[1]);
                        myMap[col].push_back(row - toWhich[1]);
                    }
                }
            } else {
                myMap[col].push_back(col);
                myMap[col].push_back(row);
                myMap[col].push_back(0);

                auto low1 = myMap.find(col);
                if (low1 == myMap.begin()) {
                    printf("%d\n", col);
                    myMap[col].push_back(col);
                } else {
                    low1--;
                    vector<int> toWhich = (*low1).second;
                    if (toWhich[2] == 1) { //Up
                        printf("%d\n", col - toWhich[0]);
                        myMap[col].push_back(col - toWhich[0]);
                    } else { //Left
                        printf("%d\n", toWhich[3] + col - toWhich[0]);
                        myMap[col].push_back(toWhich[3] + col - toWhich[0]);
                    }
                }
            }
        }
        else{
            printf("%d\n", 0);
        }
    }
    return 0;
}