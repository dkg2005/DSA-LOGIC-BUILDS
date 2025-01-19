#include <bits/stdc++.h>
using namespace std;

int main() {
    int balance;
    cin >> balance;

    int n;
    cin >> n;

    vector<pair<string, int>> task(n);
    vector<pair<int, int>> task_index(1);  // Initialize with size 1 for storing past transactions
    for (int i = 0; i < n; i++) {
        string operation;
        int val = 0;

        cin >> operation;

        if (operation != "read" && operation != "commit") {
            cin >> val;
        }

        task[i] = {operation, val};

        if (operation == "credit") {
            task_index.push_back({1, val});
        }

        if (operation == "debit") {
            task_index.push_back({0, val});
        }
    }

    int commit_count = 0, j = 0;
    vector<int> commit_balance;

    for (int i = 0; i < n; i++) {
        string operation = task[i].first;
        int val = task[i].second;

        if (operation == "read") {
            cout << balance ;
            if(i!=n-1) cout << endl;
        } else if (operation == "credit") {
            balance += val;
            j++;
        } else if (operation == "debit") {
            balance -= val;
            j++;
        } else if (operation == "commit") {
            commit_count = j;
            commit_balance.push_back(balance);
        } else if (operation == "abort") {
            if (val <= commit_count) {
                continue;
            } else {
                if (task_index[val].first) {
                    balance -= task_index[val].second;  // Debit
                } else {
                    balance += task_index[val].second;  // Credit
                }
            }
        } else if (operation == "rollback") {
            balance = commit_balance[val - 1];
        }
    }

    return 0;
}