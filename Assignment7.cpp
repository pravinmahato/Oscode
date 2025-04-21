#include<iostream>
#include<vector>
using namespace std;

void printframes(vector<int>& frame, int f) {
    for (int i = 0; i < f; i++) {
        if (frame[i] == -1)
            cout << " -";
        else
            cout << " " << frame[i] << " ";
    }
    cout << endl;
}

// FCFS Page Replacement
void fcfs(vector<int>& pages, int n, int f) {
    vector<int> frame(f, -1);
    int faults = 0, k = 0;
    cout << "\nFCFS Page Replacement:\n";
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            frame[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }
        printframes(frame, f);
    }
    cout << "Total page faults: " << faults << endl;
}

// Helper for LRU
int findlru(vector<int>& time, int f) {
    int min = time[0], pos = 0;
    for (int i = 1; i < f; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

// LRU Page Replacement
void lru(vector<int>& pages, int n, int f) {
    vector<int> frames(f, -1), time(f);
    int faults = 0, counter = 0;

    cout << "\nLRU Page Replacement:\n";
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = true;
                break;
            }
        }

        if (!found) {
            int pos = -1;
            for (int j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findlru(time, f);

            counter++;
            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }

        printframes(frames, f);
    }

    cout << "Total page faults: " << faults << endl;
}

// MAIN FUNCTION
int main() {
    int f, n;
    cout << "Enter the number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> f;

    fcfs(pages, n, f);
    lru(pages, n, f);

    return 0;
}
