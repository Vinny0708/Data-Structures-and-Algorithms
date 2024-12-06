#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Assignment {
    string deadline;
    bool isCompleted;
};

// Function to get yes/no input from the user
bool getYesNoInput(const string& prompt) {
    string response;
    while (true) {
        cout << prompt << " (yes/no): ";
        getline(cin, response);
        if (response == "yes") {
            return true;
        } else if (response == "no") {
            return false;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'.\n";
        }
    }
}

void createAssignment(vector<Assignment>& assignments) {
    Assignment newAssignment;
    cin.ignore();  // Clear input buffer before reading strings
    cout << "Deadline: ";
    getline(cin, newAssignment.deadline);
    newAssignment.isCompleted = getYesNoInput("Is this assignment completed?");
    assignments.push_back(newAssignment);
    cout << "Assignment added!\n";
}

void displayAssignments(const vector<Assignment>& assignments) {
    if (assignments.empty()) {
        cout << "No assignments.\n";
        return;
    }
    cout << "Assignments:\n";
    for (size_t i = 0; i < assignments.size(); ++i) {
        cout << i + 1 << ". Deadline: " << assignments[i].deadline << "\n";
        cout << "  Completed: " << (assignments[i].isCompleted ? "Yes" : "No") << "\n";
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
    cin.ignore();  // Clear input buffer before reading strings
    index--;
    
    Assignment& assignmentToUpdate = assignments[index];
    cout << "New Deadline (" << assignmentToUpdate.deadline << "): ";
    getline(cin, assignmentToUpdate.deadline);
    assignmentToUpdate.isCompleted = getYesNoInput("Is this assignment completed?");
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
        cout << "\nAnong Balak mo sa Assignment mo??\n";
        cout << "1. Add\n";
        cout << "2. View\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        while (!(cin >> choice) || choice < 1 || choice > 5) {
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
        }
    } while (choice != 5);

    return 0;
}
