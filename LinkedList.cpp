//Project : Linked List


#include<iostream>
using namespace std;
// struct of node
struct node{
	int data;
	int index;
	node* next;
};
// struct for whole linked list
struct linkedlist{
	node* start=NULL;
	node* last=NULL;
	int length=0;

// to display the value and index of node
	void display(){
		node* temp=start;
		for(int i=0;i<length;i++){
			cout<<temp->index<<" "<<temp->data<<endl;
			temp=temp->next;
		}
	}
//	method to add node at the beginning
	void insertbegin(int value){
	if(isempty()){
			node* n=new node;
			n->data=value;
			n->index=0;
			n->next=start;
			start=n;
			if(length==0){
					last=n;
			}
		
			length++;
			
		}
		else{
			node* n=new node;
			n->data=value;
			n->index=0;
			n->next=start;
			start=n;
			length++;
			updateindices();
		}
	
	}
//  method to add node at endding 
	void insertend(int value){
		if(isempty()){
		node* n=new node;
		n->data=value;
		n->index=length;
		n->next=NULL;
		start=n;
		last=n;
		length++;
		updateindices();
	}
	else{
		node* n=new node;
		n->data=value;
		n->index=length;
		n->next=NULL;
		last->next=n;
		last=n;
		length++;
		updateindices();
	}
	}
// method to add node at any index 
	void insertat(int index,int value){
		  if (index < 0 || index > length) {
            cout << "No such index found." << endl;
            return;
        }
	
		if (index==0){
			insertbegin(value);
		}
		else if (index==length-1){
			insertend(value);
		}
		else{
			node* temp=start;
			for(int i=0;i<index-1;i++){
				temp=temp->next;
			}
			node* n=new node;
			n->data=value;
			n->index=index;
			n->next=temp->next;
			temp->next=n;
			length++;
			updateindices();
		}

}
// method to delete the first node
	void deletebegin(){
		if(isempty()){
			cout<<"List is Empty . "<<endl;
		}
		else{
		node* todelete=start;
		start=start->next;
		delete todelete;
		length--;
		updateindices();	
		}
	}
// method to delete the last node
	void deleteend(){
			if(isempty()){
			cout<<"List is Empty . "<<endl;
		}
		else{
		node* temp=start;
		for(int i=0;i<length-2;i++){
			temp=temp->next;
		}
		node* tobedeleted=last;
		last=temp;
		last->next=NULL;
		delete tobedeleted;
		length--;
	}	}
// method to delete node at any index	
	void deleteat(int index){
		
		if(isempty()){
			cout<<"List is Empty . "<<endl;
		}
		else{
			if(index==0){
				deletebegin();
			}
			else if(index==length-1){
				deleteend();
			}
			else if(index>0 && index<length-1){
				node* prev=start;
				node* temp=start;
				for(int i=0;i<index;i++){
					prev=temp;
					temp=temp->next;
				}
			
				prev->next=temp->next;
				delete temp;
				length--;
				updateindices();	
			} 
			else{
				cout<<"Index not found in the List.";
			}
		}
	}	
// Deletes a node containing the specified value from the linked list.
void deletenodebyvalue(int value) {
    if (isempty()) {
        cout << "List is empty, nothing to delete." << endl;
    } else {
        if (checkvalue(value)) {
            if (start->data == value) {
                deletebegin();
            } else if (last->data == value) {
                deleteend();
            } else {
                node* prev = start;
                node* temp = start;
                for (int i = 0; i < length; i++) {
                    if (temp->data == value) {
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                delete temp;
                length--;
                updateindices();
            }
        } else {
            cout << "Value doesnot exists in the list." << endl;
        }
    }
}

// Retrieves and prints the data at a specific index in the linked list.
void findbyindex(int index) {
    if (isempty()) {
        cout << "The list is empty, nothing to search for." << endl;
    } else {
        if (index >= 0 && index < length) {
            node* temp = start;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            cout << "The Data at given index is: " << temp->data << endl;
        } else {
            cout << "No data found on this index." << endl;
        }
    }
}

// Finds and prints the index of the node containing the specified value.
void findbyvalue(int value) {
    if (isempty()) {
        cout << "List empty." << endl;
    } else {
        if (checkvalue(value)) {
            node* temp = start;
            for (int i = 0; i < length; i++) {
                if (temp->data == value) {
                    break;
                }
                temp = temp->next;
            }
            cout << "The data is on the index: " << temp->index << endl;
        } else {
            cout << "The value is not present in the list." << endl;
        }
    }
}



		//	helping functions
// will execute if list will be empty 
	bool isempty(){
		return start==NULL;
	}
// for the updation of indexes after changes
	void updateindices(){
		node* temp=start;
		for(int i=0;i<length;i++){
			temp->index=i;
			temp=temp->next;
		}
	}
// checks for if the value exists in the list or not	
	    bool checkvalue(int value){
        node* temp = start;
       

        for(int i = 0 ; i < length ; i++){
            if(temp->data == value){
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
};

int main(){
	linkedlist list;
	int choice,index,value;
while(true){
	cout<<"Choose 1 to insert node at start : "<<endl;
	cout<<"Choose 2 to insert node at end : "<<endl;
	cout<<"Choose 3 to insert node at any place you want : "<<endl;
	cout<<"Choose 4 to delete node from start : "<<endl;
	cout<<"Choose 5 to delete node from end : "<<endl;
	cout<<"Choose 6 to delete node from any place you want : "<<endl;	
	cout<<"Choose 7 to delete node by giving a value : "<<endl;
	cout<<"Choose 8 to print data at a specific index : "<<endl;
	cout<<"Choose 9 to print index containing a specific value : "<<endl;
	cout<<"Choose 10 to display : "<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter Value : ";
			cin>>value;
			list.insertbegin(value);
			break;
		case 2:
			cout<<"Enter Value : ";
			cin>>value;
			list.insertend(value);
			break;
		case 3:
			cout<<"Enter index : ";
			cin>>index;
			cout<<"Enter value : ";
			cin>>value;
			list.insertat(index,value);
			break;
		case 4:
			list.deletebegin();
			break;
		case 5:
			list.deleteend();
			break;
		case 6:
			cout<<"Enter index : ";
			cin>>index;
			list.deleteat(index);
			break;
		case 7:
			cout<<"Enter value  : ";
			cin>>value;
			list.deletenodebyvalue(value);
			break;
		case 8:
			cout<<"Enter Index : ";
			cin>>index;
			list.findbyindex(index);
			break;
		case 9:
			cout<<"Enter Value : ";
			cin>>value;
			list.findbyvalue(value);
			break;
		case 10:
			list.display();
			break;
			}
							
}
	
}
