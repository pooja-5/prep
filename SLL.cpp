//SINGLY LINKED LIST 

#include<iostream>
using namespace std;

class Node{
        int data;
        Node *next;

        public:
                Node(){
                        data=0;
                        next=NULL;
                }
                void setData(int data){
                        this->data=data;
                }
                void setNext(Node *next){
                        this->next=next;
                }
                int getData(){
                        return data;
                }
                Node *getNext(){
                        return next;
                }
};

class LL{
        Node *head;

        public:
                LL(){
                        head=NULL;
                }
                Node *createNode(int);
                void insertNode(int,int);
                void printNodes();
                void deleteNode(int);
};
Node* LL::createNode(int data){
	Node *newNode=new Node();
	newNode->setData(data);
        newNode->setNext(NULL);
        return newNode;
}
void LL::insertNode(int data,int pos){
        Node *newNode=createNode(data);
        if(pos==1){
                cout<<"\nInsert beginning: "<<data<<endl;
                //Node *newNode=createNode(data);
                //newNode->setData(data);
                //newNode->setNext(NULL);
                Node *temp=head;
                newNode->setNext(head);
                head=newNode;
        }
        else if(pos==-1){
                cout<<"\nInsert end: "<<data<<endl;
                Node *ptr=head;
  		if(ptr==NULL)
                        head=newNode;
                else{
                        while(ptr->getNext()!=NULL)
                                ptr=ptr->getNext();
                        ptr->setNext(newNode);

                }

        }
        else{
                cout<<"\nInsert "<<data<<" after position :"<<pos<<endl;
                Node *ptr=head;
                int count=1;
                while(count<pos){
                        count++;
                        ptr=ptr->getNext();
                }
                newNode->setNext(ptr->getNext());
                ptr->setNext(newNode);
            	newNode->setNext(ptr->getNext());
                ptr->setNext(newNode);
        }


}
void LL::printNodes(){
        Node *ptr=head;
        cout<<"\nLinked list:"<<endl;
        if(ptr==NULL)
                cout<<"List empty"<<endl;
        else{
                while(ptr!=NULL){
                        cout<<ptr->getData()<<" ";
                        ptr=ptr->getNext();
                }
        }
}
int main(){
        LL l;
        l.insertNode(1,1);
        l.insertNode(2,1);
 	l.insertNode(3,1);
        l.insertNode(4,1);
        l.insertNode(5,-1);
        l.insertNode(6,-1);
        l.insertNode(7,3);
        l.insertNode(8,4);
        l.printNodes();
        return 0;
}





