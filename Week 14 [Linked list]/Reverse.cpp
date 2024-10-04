#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* head;
void reverse(Node* p){
    if(p->next==NULL){
        head=p;
        return;
    }
    reverse(p->next);
    p->next->next=p;
    p->next=NULL;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    return 0;
}