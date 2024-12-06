#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Assignment {
    string courseName;
    string deadline;
    string submissionStatus;
};

void createAssignment(vector<Assignment>& assignments) {
    Assignment newAssignment;
    cout << "Course Name: ";
    getline(cin, newAssignment.courseName);
    cout << "Deadline (YYYY-MM-DD): ";
    getline(cin, newAssignment.deadline);
    cout << "Submission Status: ";
    getline(cin, newAssignment.submissionStatus);
    assignments.push_back(newAssignment);
    cout << "Added!\n";
}

void displayAssignments(const vector<Assignment>& assignments) {
    if (assignments.empty()) {
        cout << "No assignments.\n";
        return;
    }
    cout << "Assignments:\n";
    for (size_t i = 0; i < assignments.size(); ++i) {
        cout << i + 1 << ". "
             << assignments[i].courseName << ", "
             << assignments[i].deadline << ", "
             << assignments[i].submissionStatus << "\n";
    }
}

void updateAssignment(vector<Assignment>& assignments) {
    if (assignments.empty()) {
        cout << "No assignments.\n";
        return;
    }
    int index;
    cout << "Assignment number to update: ";
    while (!(cin >> index) || index <= 0 || index > assignments.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Enter a valid number: ";
    }
    index--;
    Assignment& assignmentToUpdate = assignments[index];
    cout << "New Course Name (" << assignmentToUpdate.courseName << "): ";
    getline(cin, assignmentToUpdate.courseName);
    cout << "New Deadline (" << assignmentToUpdate.deadline << "): ";
    getline(cin, assignmentToUpdate.deadline);
    cout << "New Submission Status (" << assignmentToUpdate.submissionStatus << "): ";
    getline(cin, assignmentToUpdate.submissionStatus);
    cout << "Updated!\n";
}

void deleteAssignment(vector<Assignment>& assignments) {
    if (assignments.empty()) {
        cout << "No assignments.\n";
        return;
    }
    int index;
    cout << "Assignment number to delete: ";
    while (!(cin >> index) || index <= 0 || index > assignments.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Enter a valid number: ";
    }
    index--;
    assignments.erase(assignments.begin() + index);
    cout << "Deleted!\n";
}

int main() {
    vector<Assignment> assignments;
    int choice;

    do {
        cout << "\nAssignment Tracker\n";
        cout << "1. Add\n";
        cout << "2. View\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number (1-5): ";
        }

        switch (choice) {
            case 1:
                createAssignment(assignments);
                break;
            case 2:
                displayAssignments(assignments);
                break;
            case 3:
                updateAssignment(assignments);
                break;
            case 4:
                deleteAssignment(assignments);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}