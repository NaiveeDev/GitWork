#include "includes.h"


using namespace std;

template<class T>
class DLL {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d, Node* p = nullptr, Node* n = nullptr)
            : data(d), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    int size;
public:

    DLL() : head(nullptr), tail(nullptr), size(0) {}


    ~DLL() {
        clear();
    }


    void push_back(const T& data) {
        try {
            Node* newNode = new Node(data, tail, nullptr);
            if (tail == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }
        catch (bad_alloc& e) {
            cerr << "Ошибка: " << e.what() << endl;
            throw;
        }
    }

    
    void pop_front() {
        if (head == nullptr) {
            cerr << "Ошибка! Пустой список" << endl;
            throw OutOfRange("Пытаюсь втолкнуть в пустой список");
        }
        Node* oldHead = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete oldHead;
        size--;
    }

    
    void clear() {
        while (head != nullptr) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        size = 0;
    }
};