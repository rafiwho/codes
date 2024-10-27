#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
    bool completed;
};

void FCFS(vector<Process> &processes) {
    int currentTime = 0;
    for (auto &process : processes) {
        currentTime = max(currentTime, process.arrivalTime);
        process.waitingTime = currentTime - process.arrivalTime;
        currentTime += process.burstTime;
        process.turnaroundTime = process.waitingTime + process.burstTime;
    }
}

void SJF_NonPreemptive(vector<Process> &processes) {
    int currentTime = 0, completed = 0;
    while (completed != processes.size()) {
        int idx = -1, minBurst = INT_MAX;
        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime = min_element(processes.begin(), processes.end(), [&](const Process & a, const Process & b) {
                return a.arrivalTime < b.arrivalTime && !a.completed;
            })->arrivalTime;
            continue;
        }

        processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
        currentTime += processes[idx].burstTime;
        processes[idx].turnaroundTime = processes[idx].waitingTime + processes[idx].burstTime;
        processes[idx].completed = true;
        completed++;
    }
}

void Priority_NonPreemptive(vector<Process> &processes) {
    int currentTime = 0, completed = 0;
    while (completed != processes.size()) {
        int idx = -1, highestPriority = INT_MAX;
        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime = min_element(processes.begin(), processes.end(), [&](const Process & a, const Process & b) {
                return a.arrivalTime < b.arrivalTime && !a.completed;
            })->arrivalTime;
            continue;
        }

        processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
        currentTime += processes[idx].burstTime;
        processes[idx].turnaroundTime = processes[idx].waitingTime + processes[idx].burstTime;
        processes[idx].completed = true;
        completed++;
    }
}

void SJF_Preemptive(vector<Process> &processes) {
    int currentTime = 0, completed = 0;
    auto cmp = [&](int a, int b) { return processes[a].remainingTime > processes[b].remainingTime; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    while (completed != processes.size()) {
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrivalTime == currentTime && !processes[i].completed) {
                pq.push(i);
            }
        }

        if (!pq.empty()) {
            int idx = pq.top();
            pq.pop();
            processes[idx].remainingTime--;

            if (processes[idx].remainingTime == 0) {
                processes[idx].completed = true;
                completed++;
                processes[idx].waitingTime = currentTime + 1 - processes[idx].arrivalTime - processes[idx].burstTime;
                processes[idx].turnaroundTime = processes[idx].waitingTime + processes[idx].burstTime;
            } else {
                pq.push(idx);
            }
            currentTime++;
        } else {
            currentTime++;
        }
    }
}

void Priority_Preemptive(vector<Process> &processes) {
    int currentTime = 0, completed = 0;
    auto cmp = [&](int a, int b) { return processes[a].priority > processes[b].priority; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    while (completed != processes.size()) {
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrivalTime == currentTime && !processes[i].completed) {
                pq.push(i);
            }
        }

        if (!pq.empty()) {
            int idx = pq.top();
            pq.pop();
            processes[idx].remainingTime--;

            if (processes[idx].remainingTime == 0) {
                processes[idx].completed = true;
                completed++;
                processes[idx].waitingTime = currentTime + 1 - processes[idx].arrivalTime - processes[idx].burstTime;
                processes[idx].turnaroundTime = processes[idx].waitingTime + processes[idx].burstTime;
            } else {
                pq.push(idx);
            }
            currentTime++;
        } else {
            currentTime++;
        }
    }
}

void RoundRobin(vector<Process> &processes, int timeQuantum) {
    int currentTime = 0, completed = 0;
    deque<int> q;

    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrivalTime <= currentTime && !processes[i].completed) {
            q.push_back(i);
        }
    }

    while (completed != processes.size()) {
        if (!q.empty()) {
            int idx = q.front();
            q.pop_front();

            int execTime = min(timeQuantum, processes[idx].remainingTime);
            currentTime += execTime;
            processes[idx].remainingTime -= execTime;

            if (processes[idx].remainingTime == 0) {
                processes[idx].completed = true;
                completed++;
                processes[idx].turnaroundTime = currentTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
            } else {
                q.push_back(idx);
            }

            for (int i = 0; i < processes.size(); i++) {
                if (processes[i].arrivalTime <= currentTime && !processes[i].completed && find(q.begin(), q.end(), i) == q.end()) {
                    q.push_back(i);
                }
            }
        } else {
            currentTime++;
        }
    }
}

void displayResults(const vector<Process> &processes) {
    cout << left << setw(10) << "Process" << setw(15) << "Burst Time" << setw(15) << "Arrival Time" << setw(15) << "Priority"
         << setw(15) << "Waiting Time" << setw(15) << "Turnaround Time" << endl;
    for (const auto &process : processes) {
        cout << left << setw(10) << process.id << setw(15) << process.burstTime << setw(15) << process.arrivalTime
             << setw(15) << (process.priority != INT_MAX ? process.priority : '-') << setw(15) << process.waitingTime
             << setw(15) << process.turnaroundTime << endl;
    }
}

int main() {
    int numProcesses, choice, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n2. SJF (Non-Preemptive)\n3. Priority (Non-Preemptive)\n";
    cout << "4. SJF (Preemptive)\n5. Round Robin\n6. Priority (Preemptive)\n";
    cout << "Enter choice: ";
    cin >> choice;

    for (int i = 0; i < numProcesses; ++i) {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;

        if (choice == 3 || choice == 6) {
            cout << "Enter Priority for Process " << i + 1 << ": ";
            cin >> processes[i].priority;
        } else {
            processes[i].priority = INT_MAX;
        }
    }

    switch (choice) {
    case 1:
        FCFS(processes);
        break;
    case 2:
        SJF_NonPreemptive(processes);
        break;
    case 3:
        Priority_NonPreemptive(processes);
        break;
    case 4:
        SJF_Preemptive(processes);
        break;
    case 5:
        cout << "Enter Time Quantum: ";
        cin >> timeQuantum;
        RoundRobin(processes, timeQuantum);
        break;
    case 6:
        Priority_Preemptive(processes);
        break;
    default:
        cout << "Invalid choice!";
        return 0;
    }

    displayResults(processes);
    return 0;
}
