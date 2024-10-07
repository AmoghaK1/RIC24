#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node *prev;
    node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

class List {
    public:
    node *head;
    List(){head = NULL;};
    void insert(int data){
        node *p = new node(data);
        if(head==NULL){
            head = p;
            p->next = head;
            
            

        } else {
            node *temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next = p;
            p->prev = temp;
            p->next = head;
            head->prev = p;
            
        }
    }
    void display (){
        int count=0;
        node *temp = head;
        cout<<temp->data<<" ";
        temp=temp->next;
        while(temp!= head->next->next || count<8){
            cout<<temp->data<<" ";
            temp = temp->next;
            count++;
        }

        cout<<"...";

    }

};

int main(){
    List l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    
    l1.display();
}