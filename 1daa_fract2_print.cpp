// final code with simple print function

#include <bits/stdc++.h>
using namespace std;

void printTable(const vector<vector<float>>& items) {
    
    cout << "Profit Weight P/W" << endl;

  
    for (const auto& item : items) {
        cout << fixed << setprecision(2) 
             << item[1] << "    " 
             << item[2] << "    " 
             << item[0] << endl;
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
    printTable(items);

    sort(items.begin(), items.end(), greater<>()); // Sort in descending order of P/W

    float totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (items[i][2] <= maxWeight) {
            maxWeight -= items[i][2];
            totalProfit += items[i][1];
        } else {
            float fraction = maxWeight / items[i][2];
            totalProfit += items[i][1] * fraction;
            break; // Knapsack is full
        }
    }

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