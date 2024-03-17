#include <iostream>
#include <list>
#include <algorithm> 

using namespace std;

void printList(const list<int>& lst) {
    for (int n : lst) cout << n << " ";
    cout << endl;
}


bool Sort(int a, int b) {

    return a > b;
}

int main() {
   
    list<int> list1 = {5, 3, 9, 2, 7};
    list<int> list2 = {4, 1, 8, 6};

    
    list1.sort(Sort);

    
    cout << "Sorted list1: "<<endl;
    printList(list1);

    
    list1.merge(list2);

    
    cout << "Merged list1: "<<endl;
    printList(list1);

    return 0;
}
