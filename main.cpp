#include <iostream>
#include "stack.h"

using namespace std;

void printHeader();
void printState(Stack<int>& a, Stack<int>& b, Stack<int>& c);
void moveDisk(Stack<int>& from, Stack<int>& to, char nameFrom, char nameTo);
void hanoi(int n, Stack<int>& origin, Stack<int>& aux, Stack<int>& destination,
           char nameOrigin, char nameAux, char nameDest, int& moves,
           Stack<int>& a, Stack<int>& b, Stack<int>& c);

template <typename T>
void printStack(Stack<T>& s){
    cout << "[";

    Node<T>* current = s.top;
    bool first = true;

    while(current != nullptr){
        if (!first) cout << ", ";
        cout << current->value;
        first = false;
        current = current->next;
    }

    cout << "]";
}

int main(){ 
    int moves = 0;
    int n;
    
    printHeader();

    cout << "Number of Disks: ";
    cin >> n;

    if (n < 1 || n > 10){
        cout << "Invalid number of disks." << endl;
        return 0;
    }

    Stack<int> a, b, c;
    a.init(0);
    b.init(0);
    c.init(0);

    for(int i = n; i >= 1; i--){ 
        a.push(i);
    }

    cout << "\nInitial State:\n";
    printState(a, b, c);
    cout << "------------------------\n";

    hanoi(n, a, b, c, 'A', 'B', 'C', moves, a, b, c);

    cout << "\nMoves in total: " << moves << endl; 

    a.destroy();
    b.destroy();
    c.destroy();

    return 0;
}

void printHeader(){
    cout << "\n";
    cout << "========================================\n";
    cout << "           TOWER OF HANOI\n";
    cout << "----------------------------------------\n";
    cout << " Move all disks from A to C\n";
    cout << " Rules:\n";
    cout << "  - Move one disk at a time\n";
    cout << "  - Never place a larger disk on a smaller one\n";
    cout << "  - Maximum of 10 disks\n";
    cout << "========================================\n\n";
}

void printState(Stack<int>& a, Stack<int>& b, Stack<int>& c){ 
    cout << "A: "; printStack(a);
    cout << "\nB: "; printStack(b);
    cout << "\nC: "; printStack(c);
    cout << endl;
}

void moveDisk(Stack<int>& from, Stack<int>& to, char nameFrom, char nameTo){ 
    int disk;
    int topDest;

    if(from.peek(&disk)){
        if(to.peek(&topDest)){
            if(disk > topDest){
                cout << "Invalid move attempted from " << nameFrom << " to " << nameTo << endl;
                return;
            }
        }

        from.pop(&disk);
        to.push(disk);
        cout << "Moving disk " << disk << " from " << nameFrom << " to " << nameTo << endl;
    }
}

void hanoi(int n, Stack<int>& origin, Stack<int>& aux, Stack<int>& destination,
           char nameOrigin, char nameAux, char nameDest, int& moves,
           Stack<int>& a, Stack<int>& b, Stack<int>& c) { 

    if (n <= 0) return;

    hanoi(n - 1, origin, destination, aux, nameOrigin, nameDest, nameAux, moves, a, b, c);

    moveDisk(origin, destination, nameOrigin, nameDest);
    moves++;
    printState(a, b, c);
    cout << "------------------------\n";

    hanoi(n - 1, aux, origin, destination, nameAux, nameOrigin, nameDest, moves, a, b, c);
}