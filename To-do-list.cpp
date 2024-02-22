// Taha Rahman

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task> &tasks, const string &description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully.\n";
}

// Function to view all tasks with their status
void viewTasks(const vector<Task> &tasks) {
    cout << "Tasks:\n";
    for (const Task &task : tasks) {
        cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&](const Task &task) {
        return task.description == description;
    });
    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&](const Task &task) {
        return task.description == description;
    });
    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Task not found.\n";
    }
}

int main() {
    srand(time(0));

    vector<Task> tasks;

    cout << "Welcome to Task Manager!\n\n";

    while (true) {
        cout << "Options:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                string taskDescription;
                cout << "Enter task description to mark as completed: ";
                cin.ignore();
                getline(cin, taskDescription);
                markTaskAsCompleted(tasks, taskDescription);
                break;
            }
            case 4: {
                string taskDescription;
                cout << "Enter task description to remove: ";
                cin.ignore();
                getline(cin, taskDescription);
                removeTask(tasks, taskDescription);
                break;
            }
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}
