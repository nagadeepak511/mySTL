#include<bits/stdc++.h>
using namespace std;

template <class T>
struct node{
    T val;
    node<T> *next = NULL;
    node(T val_): val(val_){}
    node(T val_, node<T> *next_): val(val_), next(next_){}
};

template <class T>
struct lst{
    node<T> *head = NULL, *tail = NULL;
    int size = 0;
    lst(const initializer_list<T> &v) {
        for(auto itm:v) pb(itm);
    }
    void pb(T val){
        if(size == INT_MAX) {
            cout << "Max size of list achieved, cannot insert further\n";
            return;
        }
        size++;
        if(tail == NULL) {
            head = tail = new node<T>(val);
            return;
        }
        tail->next = new node<T>(val);
        tail = tail->next;
    }
    void ppb(void){
        if(head == NULL) {
            cerr << "Cannot perform popback on empty list\n";
            return;
        }
        size--;
        if(head->next == NULL) {
            head = tail = NULL;
            return;
        }
        for(auto temp = head; temp!=NULL; temp=temp->next) 
            if(temp->next == tail) {
                tail = temp;
                temp->next = NULL;
            }
    }
    void print(void){
        for(auto temp=head;temp!=NULL;temp=temp->next) cout << temp->val << " -> ";
        cout << endl;
    }
    void insertAt(T val, int ind){
        if(size == INT_MAX) {
            cout << "Max size of list achieved, cannot insert further\n";
            return;
        }
        if(ind<0||ind>size) {
            cout << "Index out of bounds for inserting into the list\n";
            return;
        }
        size++;
        auto x = new node<T>(val);
        if(ind == 0) {
            x->next = head;
            head = x;
            return;
        }
        auto temp = head;
        for(int i=0;i<ind-1;i++) temp = temp->next;
        x->next = temp->next;
        temp->next = x;
    }
    void deleteAt(int ind){
        if(ind<0||ind>=size){
            cout << "Index out of bounds for delteting an element from the list\n";
            return;
        }
        size--;
        if(ind == 0) {
            head = head->next;
            return;
        }
        auto temp = head;
        for(int i=0;i<ind-1;i++) temp = temp->next;
        temp->next = temp->next->next;
    }
    void reverse(int l, int r){
        
    }
};

int main(){
    lst<int> x = {1,2,3,4,5};
    x.print();
    for(int i=0;i<6;i++) {
        x.insertAt(i+9,i);
        x.print();
    }
    x.insertAt(x.size, x.size);
    x.print();
    cout << "#####################################\n";
    for(int i=0;i<x.size;i++) {
        x.deleteAt(i);
        x.print();
    }
}