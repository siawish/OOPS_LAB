#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    list<pair<string, ToDoList>> tasks;

public:
    // add a tank 
    void addTask(const string& taskName) {
        tasks.push_back(make_pair(taskName, ToDoList()));
    }

    // add  sub-tasks
    void addSubTask(int taskIndex, const string& subTaskName) {
        auto it = tasks.begin();
        for (int i = 0; i < taskIndex; ++i) {
            ++it;
        }
        it->second.addTask(subTaskName);
    }

    //  delete a task
    void deleteTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            auto it = tasks.begin();
            for (int i = 0; i < taskIndex; ++i) {
                ++it;
            }
            tasks.erase(it);
        }
        else {
            cout << "Invalid task index!" << endl;
        }
    }

    //task done
    void markTaskDone(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            auto it = tasks.begin();
            for (int i = 0; i < taskIndex; ++i) {
                ++it;
            }
            it->first += " (Done)";
        }
        else {
            cout << "Invalid task index!" << endl;
        }
    }


    void display(int indent = 0) const {
        for (const auto& task : tasks) {

            for (int i = 0; i < indent; ++i) {
                cout << "    ";
            }

            cout << "- " << task.first << endl;

            task.second.display(indent + 1);
        }
    }
};

int main() {
    ToDoList toDo;

    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Add Sub-task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Done" << endl;
        cout << "5. Display ToDo List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string taskName;
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, taskName);
            toDo.addTask(taskName);
            break;
        }
        case '2': {
            int taskIndex;
            string subTaskName;

            cout << "Enter task index to add sub-task: ";
            cin >> taskIndex;

            cout << "Enter sub-task name: ";

            cin.ignore();
            getline(cin, subTaskName);

            toDo.addSubTask(taskIndex - 1, subTaskName);

            break;
        }
        case '3': {
            int taskIndex;

            cout << "Enter task index t delete: ";
            cin >> taskIndex;

            toDo.deleteTask(taskIndex - 1);
            break;
        }
        case '4': {
            int taskIndex;
            cout << "Enter task index to mark as done: ";
            cin >> taskIndex;
            toDo.markTaskDone(taskIndex - 1);
            break;
        }
        case '5':
            cout << "ToDo List:" << endl;
            toDo.display();
            break;
        case '6':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 to 6." << endl;
        }
    } while (choice != '6');

    return 0;
}

