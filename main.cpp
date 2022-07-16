#include <bits/stdc++.h>
#include <chrono>

using namespace std;
 
// Returns number of bins required using next fit
// online algorithm
int nextFit(int weight[], int n, int c)
{
    // Initialize result (Count of bins) and remaining
    // capacity in current bin.
    int res = 0, bin_rem = c;
 
    // Place items one by one
    for (int i = 0; i < n; i++) {
        // If this item can't fit in current bin
        if (weight[i] > bin_rem) {
            res++; // Use a new bin
            bin_rem = c - weight[i];
        }
        else
            bin_rem -= weight[i];
    }
    return res;
}
 
// Driver program
int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
const long long TIMES_TO_RUN{500};
const long long NUM_ITEMS{100};
    vector<double> algoRuntimes;
    double algoTotalRuntime;
    double algoAverageRuntime;



    for (int i = 0; i < TIMES_TO_RUN; i++) {

        int weight[NUM_ITEMS];

        for (int i = 0; i < NUM_ITEMS; ++i) {
            weight[i] = rand() % 10;
        }


        int c = 10;
        int n = sizeof(weight) / sizeof(weight[0]);

        auto algoStart = high_resolution_clock::now();
        int result = nextFit(weight, n, c);
        auto algoEnd = high_resolution_clock::now();
        duration<double, std::milli> algoRuntime = algoEnd - algoStart;
        algoRuntimes.push_back(algoRuntime.count());
    }

    for (double runtime:algoRuntimes) {
        //cout << runtime;
        algoTotalRuntime += algoTotalRuntime;
    }

    algoAverageRuntime = algoTotalRuntime / algoRuntimes.size();

    cout << "Total run time: " << algoTotalRuntime << "\n";
    cout << "Average run time: " << algoAverageRuntime << "\n";


    return 0;
}