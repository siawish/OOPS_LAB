#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
    vector<char> grades;

    char choice;

    do {
        
        cout << "\n  -: Menu :- ";
        cout << "\n1. Add a grade";
        cout << "\n2. Display all grades";
        cout << "\n3. Quit";
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        system("CLS");

        switch (choice) {
            
            case '1': 
            {
                char grade;
                cout << "Enter grade [ A, B, C, D, or F ] : ";
                cin >> grade;

                grade = toupper(grade);

                if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F'){
                    grades.push_back(grade);
                    
                    cout << "\n Grade successfully added.";
                } 
                else 
                { system("CLS");
                
                    cout << "\n Invalid grade."
                    <<"Please enter A, B, C, D, or F.";
                }
                break;
            }
            case '2': 
            { system("CLS");
            
                cout << "\n -; Grades :-";

                if (grades.empty()){
                    
                    cout << "\n No grades entered "<<endl<<endl;
                } 
                else {
                    cout<<"\n --------------"<<endl;
                    
                    for (char grade :grades) {
                        
                        cout << grade ;
                    }
                }
                break;
            }
            case '3':
            system("CLS");
            
                cout <<"\n Exiting program.";
                break;
                
                
            default:
            system("CLS");
            
                cout <<"\n Invalid choice. "
                     <<"\n Please enter a valid option.";
        }

    } while (choice != '3');

    return 0;
}
