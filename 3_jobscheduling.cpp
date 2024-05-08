#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;       
    int deadline; 
    int profit;
};

class Jobscheduling
{
    public:
    
    int findMaxDeadline(Job arr[], int n);
    void findMaxProfitSchedule(Job arr[], int n);
};

bool compare(Job a, Job b) 
    {
       return (a.profit > b.profit);
    }


int Jobscheduling::findMaxDeadline(Job arr[], int n) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > max_deadline)
            max_deadline = arr[i].deadline;
    }
    return max_deadline;
}

void Jobscheduling::findMaxProfitSchedule(Job arr[], int n) 
{
    // Step 1: Sort the jobs in descending order of profit
    sort(arr, arr + n, compare);

    // Step 2: Find the maximum deadline among all jobs
    int max_deadline = findMaxDeadline(arr, n);

    // Step 3: Initialize an array to keep track of scheduled jobs
    int schedule[max_deadline];
    for(int k = 0; k < max_deadline; k++)
    {
        schedule[k] = -1; // Initialize all slots to -1 (indicating empty)
    }

    // Step 4: Initialize total profit
    int total_profit = 0;

    // Step 5: Iterate through each job in the sorted order
    for (int i = 0; i < n; i++) {
        // Step 6: Iterate through each deadline slot for the current job
        for (int j = min(max_deadline, arr[i].deadline) - 1; j >= 0; j--) {
            // Step 7: Check if the current slot is empty
            if (schedule[j] == -1) {
                // Step 8: If slot is empty, schedule the job and update total profit
                schedule[j] = arr[i].id;
                total_profit += arr[i].profit;
                // Step 9: Break the loop to proceed to the next job
                break;
            }
        }
    }

    // Step 10: Print the maximum profit job schedule
    cout << "Maximum profit job schedule:" << endl;
    for (int i = 0; i < max_deadline; i++) {
        // Step 11: Print scheduled jobs for each slot
        if (schedule[i] != -1) {
            cout << "Job " << schedule[i] << " ";
        }
    }
    cout << endl;
    // Step 12: Print the total profit earned
    cout << "Total profit: " << total_profit << endl;
}


int main() {
    Jobscheduling j1;
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter deadline and profit for job " << i+1 << ": ";
        cin >> arr[i].deadline >> arr[i].profit;
        arr[i].id = i + 1;
    }

    j1.findMaxProfitSchedule(arr, n);

    return 0;
}
