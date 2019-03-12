
#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
 string data;
 int freq;
 struct Node* next;
 struct Node* prev;
};
struct Node* head;
void freqency()
{
 Node* temp1=head;
 while(temp1!=NULL)
 {
 int count = 1;
 struct Node* temp2=temp1->next;
 while(temp2!=NULL)
 {
 if(temp1->data==temp2->data)
 {
 count++;
 temp2->freq=0;
 }
 temp2=temp2->next;
 }
 if(temp1->freq!=0)
 temp1->freq=count;
 temp1=temp1->next;
 }
}
struct Node* getNewNode(string x)
{
 Node* temp=new Node;
 temp->data=x;
 temp->freq=-1;
 temp->prev=NULL;
 temp->next=NULL;
 return temp;
}
void insertAtHead(string x)
{
 struct Node* temp=getNewNode(x);
 if(head==NULL)
 {
 head=temp;
 return;
 }
 head->prev=temp;
 temp->next=head;
 head=temp;
}
void Print()
{
 Node* temp=head;
 if(temp==NULL)
 return;
 while(temp!=NULL)
 {
 cout<<temp->data<<" ";
 cout<<temp->freq<<"\n";
 temp=temp->next;
 }
}
void sorted()
{
 struct Node* temp=head;
 struct Node* temp1;
 while(temp!=NULL)
 {
 temp1=temp->next;
 while(temp1!=NULL)
 {
 string str1=temp->data;
 string str2=temp1->data;
 transform(str1.begin(),str1.end(),str1.begin(),::tolower);
 transform(str2.begin(),str2.end(),str2.begin(),::tolower);
 if(str1>str2)
 {
 string st=temp->data;
 temp->data=temp1->data;
 temp1->data=st;
 int fr=temp->freq;
 temp->freq=temp1->freq;
 temp1->freq=fr;
 }
 temp1=temp1->next;
 }
 temp=temp->next;
 }
}
void deleteEx()
{
 struct Node* current=head;
 struct Node* next;
 while(current!=NULL)
 {
 if(current->freq==0)
 {
 next=current->next;
 current->next->prev=current->prev;
 current->prev->next=current->next;
 delete current;
 current=next;
 }
 else
 current=current->next;
 }
}
int main()
{
 ifstream f1;
 f1.open("mohit.txt");
 int i=0,j;
 string a;
 while(!f1.eof())
 {
 f1>>a;
 insertAtHead(a);
 i++;
 }
 freqency();
 deleteEx();
 sorted();
 Print();
 return 0;
}
