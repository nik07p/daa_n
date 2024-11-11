#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void printTable(const vector<vector<float>>& items, bool isResult) {
    const int cellWidth = 10;

    cout << setw(cellWidth) << left << "Profit     |";
    cout << setw(cellWidth) << left << "Weight     |";
    // if (isResult)
    //     cout << setw(cellWidth) << left << "Fraction    |";
    // else
        cout << setw(cellWidth) << left << "P/W        |";

    cout << endl;

    for (int i = 0; i < 3; ++i)
        cout << "+----------+";

    cout << endl;
    for (const auto& item : items) {
        cout << setfill(' ') << setw(cellWidth) << left << item[1] << " |";
        cout << setw(cellWidth) << left << item[2] << " |";
        cout << setw(cellWidth) << left << item[0] << " |";
        cout << endl;
    }
    cout << endl;
}

void takeInput(vector<vector<float>>& items, int& n, float& maxWeight) {
    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        float profit, weight, pw;
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> profit;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> weight;
        cout << endl;
        
        pw = profit / weight;
        items.push_back({pw, profit, weight});
    }

    cout << "Enter maximum weight allowed: ";
    cin >> maxWeight;
    cout << endl;
}

int main() {
    vector<vector<float>> items;
    int n;
    float maxWeight;
    takeInput(items, n, maxWeight);

    cout << "Entered Elements are:\n";
    printTable(items, false);

    sort(items.begin(), items.end(), greater<>()); // Sort in descending order of P/W

    // vector<vector<float>> result = items; // Copy items for result tracking
    float totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (items[i][2] <= maxWeight) {
            maxWeight -= items[i][2];
            totalProfit += items[i][1];
           /// result[i][0] = 1; // Full item taken
        } else {
            float fraction = maxWeight / items[i][2];
            totalProfit += items[i][1] * fraction;
           // result[i][0] = fraction; // Partial item taken
            break; // Knapsack is full
        }
    }

    // cout << "Final Result:\n";
    // printTable(result, true);

    cout << "Total Profit: " << totalProfit << endl;
    return 0;
}
/*
Enter number of items: 3
Enter profit for item 1: 25
Enter weight for item 1: 18

Enter profit for item 2: 24
Enter weight for item 2: 15

Enter profit for item 3: 15
Enter weight for item 3: 10

Enter maximum weight allowed: 20

Entered Elements are:
Profit     |Weight     |P/W        |
+----------++----------++----------+
25         |18         |1.38889    |
24         |15         |1.6        |
15         |10         |1.5        |

Total Profit: 31.5
*/