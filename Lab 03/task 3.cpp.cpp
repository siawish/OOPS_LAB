#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float grade;

public:
    Student(int id, const string& name, float grade) : id(id), name(name), grade(grade) {}

    int getId() const {
        return id;
    }
        
    const string& getName() const {
        return name; 
    }
    
    float getGrade() const {
        return grade; 
        
    }

    void setGrade(float newGrade) { 
        grade = newGrade;
    }
};

class StudentManager {
    
private:
    vector<Student> records;

public:
    void addStudent(int id, const string& name, float grade) {
        
        records.emplace_back(id, name, grade);
    }

    bool updateGrade(int id, float newGrade) {
        
        for (auto& student : records) {
            
            if (student.getId() == id) {
                
                student.setGrade(newGrade);
                
                return true;
            }
        }
        
        return false; // ID not found
    }

    void displayRecords() const {
        
        for (const auto& student : records) {
            
            cout << "\n ID: " << student.getId() << ", Name: " << student.getName() << ", Grade: " << student.getGrade() << endl;
        }
    }
};

int main() {
    char continueOption;
    int newId, updateId;
    string newName;
    float newGrade, updatedGrade;

    StudentManager sm;

    
    sm.addStudent(1, "syed", 92.5);
    sm.addStudent(2, "ali", 88.0);
    sm.addStudent(3, "haider", 80.0);
    sm.displayRecords();

    cout << "----------------" << endl;

    sm.updateGrade(1, 95.0);
    
    cout << "Updated Grades" << endl;
    sm.displayRecords();
    cout << endl;

    do {
        cout << "Do you want to add a new student? (y/n): ";
        cin >> continueOption;

        if (tolower(continueOption) == 'y') {
            
            cout << "Enter details for a new student:" << endl;
                 << "ID: ";
            cin >> newId;
            
            cout << "Name: ";
            cin.ignore();
            getline(cin, newName);
            
            cout << "Grade: ";
            cin >> newGrade;

            sm.addStudent(newId, newName, newGrade);

            cout << "After adding a new student:" << endl;
            sm.displayRecords();
            cout << "------------------" << endl;
        }

        cout << "Do you want to update a student's grade? (y/n): ";
        cin >> continueOption;

        if (tolower(continueOption) == 'y') {
            cout << "Enter the ID of the student whose grade you want to update: ";
            cin >> updateId;
            
            cout << "Enter the new grade: ";
            cin >> updatedGrade;

            if (sm.updateGrade(updateId, updatedGrade)) {
                
                cout << "After updating the grade:" << endl;
                sm.displayRecords();
                cout << "------------------" << endl;
            } 
            else 
            {
                cout << "Student ID not found." << endl;
            }
        }
    } while (tolower(continueOption) == 'y');

    return 0;
}
