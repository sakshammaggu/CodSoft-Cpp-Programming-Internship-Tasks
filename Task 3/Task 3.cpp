#include <iostream>
#include <vector>
using namespace std;
class Task 
{
public:
    string description;
    bool completed;

    Task(const string& desc)
    {
        description=desc;
        completed=false;
    }
};

class ToDoListManager 
{
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) 
    {
        tasks.emplace_back(desc);
        cout << "Task added." << endl;
    }

    void viewTasks() 
    {
        if (tasks.empty()) 
        {
            cout << "No tasks to display." << endl;
        } 
        else 
        {
            cout << "Tasks:" << endl;
            for (int i = 0; i < tasks.size(); ++i) 
            {
                const Task& task = tasks[i];
                cout << i + 1 << ". " << task.description << " - " << (task.completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskCompleted(int taskIndex) 
    {
        if (taskIndex < tasks.size()) 
        {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed." << endl;
        } 
        else 
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex) 
    {
        if (taskIndex < tasks.size()) 
        {
            tasks.erase(tasks.begin() + taskIndex);
            cout << "Task removed." << endl;
        } 
        else 
        {
            cout << "Invalid task index." << endl;
        }
    }
};
int main() 
{
    ToDoListManager todoList;

    while (true) 
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDesc;
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: 
            {
                int taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex - 1);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex - 1);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                exit;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }
}
