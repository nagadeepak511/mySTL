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
    node<T>* ithNode(int i){
        if(i<0||i>size) return NULL;
        int count = 0;
        auto temp = head;
        while(count<i) {
            count++;
            temp = temp->next;
        }
        return temp;
    }
    void reverse(int l, int r){
        if(l<0||r<0||l>size||r>size||l>=r) {
            cout << "Invalid arguments provided for reverse list function\n";
            return;
        }
        node<T> *first = NULL, *second = ithNode(l), *last = ithNode(r), *temp;
        while(second!=last){
            temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        if(l==0) head = first;
        else ithNode(l-1)->next = first;
        for(auto temp = first; temp!=NULL; temp=temp->next) if(temp->next == NULL) {
            temp->next = last;
            return;
        }
    }
};

