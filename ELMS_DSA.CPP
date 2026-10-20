#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class ELMS_DSA {

public:

    // Linear Search
    void linearSearch(vector<int> data, int target) {

        cout << "\n===== LINEAR SEARCH =====\n";

        for (int i = 0; i < data.size(); i++) {

            if (data[i] == target) {
                cout << "Element " << target
                     << " found at index " << i << endl;
                return;
            }
        }

        cout << "Element not found.\n";
    }

    // Binary Search
    void binarySearch(vector<int> data, int target) {

        cout << "\n===== BINARY SEARCH =====\n";

        sort(data.begin(), data.end());

        int left = 0;
        int right = data.size() - 1;

        while (left <= right) {

            int middle = left + (right - left) / 2;

            if (data[middle] == target) {

                cout << "Element " << target
                     << " found at index "
                     << middle << " in sorted data.\n";

                return;
            }

            if (data[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        cout << "Element not found.\n";
    }

    // Sorting
    void sortData(vector<int>& data) {

        cout << "\n===== SORTING =====\n";

        sort(data.begin(), data.end());

        cout << "Sorted data: ";

        for (int value : data)
            cout << value << " ";

        cout << endl;
    }

    // Queue
    void demonstrateQueue() {

        cout << "\n===== QUEUE =====\n";

        queue<string> learningQueue;

        learningQueue.push("Java");
        learningQueue.push("C++");
        learningQueue.push("DSA");

        cout << "Learning Queue:\n";

        while (!learningQueue.empty()) {

            cout << learningQueue.front() << endl;

            learningQueue.pop();
        }
    }

    // Stack
    void demonstrateStack() {

        cout << "\n===== STACK =====\n";

        stack<string> recentCourses;

        recentCourses.push("Java");
        recentCourses.push("C++");
        recentCourses.push("DSA");

        cout << "Recent Courses:\n";

        while (!recentCourses.empty()) {

            cout << recentCourses.top() << endl;

            recentCourses.pop();
        }
    }
};


int main() {

    ELMS_DSA dsa;

    vector<int> data = {
        45, 12, 78, 23, 9
    };

    cout << "====================================\n";
    cout << "       ELMS DSA MODULE\n";
    cout << "====================================\n";

    cout << "\nOriginal Data: ";

    for (int value : data)
        cout << value << " ";

    cout << endl;

    dsa.linearSearch(data, 23);

    dsa.sortData(data);

    dsa.binarySearch(data, 23);

    dsa.demonstrateQueue();

    dsa.demonstrateStack();

    cout << "\n====================================\n";
    cout << "      DSA MODULE COMPLETED\n";
    cout << "====================================\n";

    return 0;
}