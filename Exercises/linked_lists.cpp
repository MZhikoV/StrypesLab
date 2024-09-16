#include <iostream>

struct Node {
    int value=0;
    Node* next=nullptr;
};

struct List {
    Node* head=nullptr;
    int count=0;
};

void addFront (List & lst, int value) {
    Node * tmp=new Node;
    tmp->value=value;
    tmp->next=lst.head;
    lst.head=tmp;
    lst.count++;
};

bool removeFront(List & lst) {
    if (lst.head) {
        Node * tmp=lst.head;
        lst.head=tmp->next;
        delete tmp;
        lst.count--;
        return true;
    }
    else {
        return false;
    }
}

void printAll( List const & lst) {
    int ctr=lst.count;
    for (Node * curr=lst.head; curr!=nullptr; curr=curr->next) {
        std::cout<<curr->value<<" ";
    };
    std::cout<<std::endl;
};



int main() {

    List l1;

    for (int i:{1,2,3,4,5,6,7,8,9,0}) {
        addFront(l1,i);
        printAll(l1);
    };

    //removeFront(l1);
    for (int i=l1.count; i>0; i--) {
        removeFront(l1);
        printAll(l1);
    }
    

    system("pause");
    return 0;
}