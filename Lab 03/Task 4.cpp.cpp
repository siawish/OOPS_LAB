#include <iostream>
#include <vector>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(new Task(desc));
    }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i]->completed ? "[X] " : "[ ] ") << tasks[i]->description << endl;
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1]->completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1]->description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    ~ToDoList() {
        for (auto& task : tasks) {
            delete task;
        }
    }
};

int main() {
    int n;
    ToDoList myList;
    myList.addTask("Recite Quran");
    myList.addTask("100 push ups ");
    myList.addTask("code implimentatiion");

    myList.listTasks();

    cout << "Enter the Sr. Number of Task Completed: ";
    cin >> n;
    myList.markAsCompleted(n);
    myList.listTasks();

    return 0;
}
