#include <fstream>
#include "Hashing.h"
#include "DoubleHashing.h"
#include "LinkedHashing.h"

using namespace std;

#define TAMANHO_ARQUIVO 11

#define DOUBLE_HASHING 'd'

#define INSERT 'i'
#define READ 'c'
#define REMOVE 'r'
#define PRINT 'p'
#define TIME_SPENT 'm'
#define END 'e'

void operate(Hashing *hash) {
    int keyValue;
    string name;
    int age;

    char operation;
    cin >> operation;
    while(operation != END) {
        switch(operation) {
            case INSERT:
                cin >> keyValue;
                cin.ignore();
                getline(cin, name);
                cin >> age;
                hash->insert(Node(keyValue, (char*) name.c_str(), age));
                break;
            case READ:
                int index;
                cin >> index;
                hash->getItem(index);
                break;
            case REMOVE:
                break;
            case TIME_SPENT:
                break;
            default: // Print
                hash->read();
                break;
        }
       cin >> operation;
    }
}

int main() {
    char type;
    cin >> type;
    if(type == DOUBLE_HASHING) {
        DoubleHashing hash = DoubleHashing(TAMANHO_ARQUIVO);
        operate(&hash);
    } else {
        LinkedHashing hash = LinkedHashing(TAMANHO_ARQUIVO);
        operate(&hash);
    }
    return 0;
}