#include <bits/stdc++.h>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> visitedd;
unordered_map<int, vector<int>> nodes_and_their_neighbourss;

int node_counter_in_each_island = 0;
int main_answer = INT_MIN;
int largest1 = INT_MIN;
int largest2 = INT_MIN;

int dfs(int s) {
    int adjListSize = nodes_and_their_neighbourss[s].size();
    visitedd.at(s) = true;
    node_counter_in_each_island += 1;
    if (s > largest1) {
        largest2 = largest1;
        largest1 = s;
    } else if (s > largest2) {
        largest2 = s;
    }
    for (int &i : nodes_and_their_neighbourss.at(s)) {
        if (!visitedd.at(i)) {
            adjListSize += dfs(i);
        }
    }
    return adjListSize;
}

void maxEdges() {
    for (auto &it : visitedd) {
        if (!it.second) {
            node_counter_in_each_island = 0;
            int answer = dfs(it.first) / 2;
            if (answer > node_counter_in_each_island) {
                main_answer = -1;
                break;
            } else if (answer == node_counter_in_each_island && largest1 > main_answer) {
                main_answer = largest1;
            } else if (largest2 > main_answer) {
                main_answer = largest2;
            }
            largest1 = INT_MIN;
            largest2 = INT_MIN;
        }
    }
}

int main() {
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; ++i) {
        int first;
        int second;
        scanf("%d %d", &first, &second);
        if (nodes_and_their_neighbourss.find(first) != nodes_and_their_neighbourss.end()) {
            nodes_and_their_neighbourss[first].push_back(second);
        } else {
            visitedd.insert({first, false});
            vector<int> value;
            value.push_back(second);
            nodes_and_their_neighbourss.insert({first, value});
        }
        if (nodes_and_their_neighbourss.find(second) != nodes_and_their_neighbourss.end()) {
            nodes_and_their_neighbourss[second].push_back(first);
        } else {
            visitedd.insert({second, false});
            vector<int> value;
            value.push_back(first);
            nodes_and_their_neighbourss.insert({second, value});
        }
    }
    maxEdges();
    cout << main_answer;
    return 0;
}