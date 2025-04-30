#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {
    // Sort jobs by profit (greedy choice)
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    int maxDeadline = 0;

    // Find maximum deadline
    for (auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> schedule(maxDeadline, '-'); // '-' means empty slot
    int totalProfit = 0;

    for (auto job : jobs) {
        // Try to find a free slot from job.deadline - 1 to 0
        for (int j = job.deadline - 1; j >= 0; j--) {
            if (schedule[j] == '-') {
                schedule[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";
    for (char c : schedule)
        if (c != '-')
            cout << c << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline and Profit for each job:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling(jobs);

    return 0;
}
