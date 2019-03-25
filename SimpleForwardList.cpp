#include <iostream>
using namespace std;

struct ForwardList{
    int value;
    ForwardList *next;
};

ForwardList *CreateNode(int value){
    ForwardList *node = new ForwardList;
    node -> value = value;
    node -> next = nullptr;
    return node;
}

void DestroyList(ForwardList *list){
    ForwardList *l = list, *tmp;
    if (l != nullptr){
        while (l != nullptr){
            tmp = l;
            delete l;
            l = tmp -> next;
        }
    }
}

ForwardList *PushFront(ForwardList *list, int value){
    ForwardList *node = CreateNode(value);
    node -> next = list;
    return node;
}

void Append(ForwardList *list, ForwardList *tail){
    if(list == nullptr){
        list = PushFront(list, tail -> value);
    }
    else{
        while(list -> next){
            list = list -> next;
        }
        list -> next = tail;
    }
}

int main(void){
    ForwardList *list = nullptr;

    list = PushFront(list, 3);
    Append(list, CreateNode(6));
    Append(list, CreateNode(4));
    list = PushFront(list, 1);
    list = PushFront(list, 2);
    Append(list, CreateNode(5));

    while(list){
        cout << list -> value << endl;
        list = list -> next;
    }

    DestroyList(list);

    return 0;
}