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
    int key;
    string name;
    int age;

    char operation;
    cin >> operation;
    while(operation != END) {
        switch(operation) {
            case INSERT:
                cin >> key;
                cin.ignore();
                getline(cin, name);
                cin >> age;
                hash->insert(Node(key,
                                  (char*) name.c_str(),
                                  age));
                break;
            case READ:
                cin >> key;
                hash->search(key);
                break;
            case REMOVE:
                cin >> key;
                if(!hash->remove(key)) {
                    cout << "chave não encontrada "
                         << key << endl;
                }
                break;
            case TIME_SPENT:
//                cout << hash->time_spent();
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