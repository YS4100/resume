//Filename:201701045_Assignment5.cpp
//Name : Yashvi Shah
//ID-201701045
//Assignment Number-5
//Last Changed-21/2/18
//Description-Use of linked lists,switch case,pure virtual functions
//On every insert and append the current element is shifted

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
template <typename E>
struct node
{
E data;
node *nextElement;
};

template <typename E>
class List
{
    void operator = (const List&) {}
    List(const List&) {}
   
    public:
        //constructors and destructors
        List() {}
        virtual ~List() {}
       
        //Return the number of elements in the List
        virtual int NumberOfElements() const = 0;
       
        //Return the Location of current element
        virtual int CurrentLocation() const = 0;
       
        //Return the data of current element
        virtual const E& getData() const = 0;
       
        //clear all the data from the List
        virtual void clear() = 0;
        
        //insert a data in the List at current location
        virtual void insert(const E& data) = 0;
       
        //insert a data in the end of the List
        virtual void append(const E& data) = 0;
       
        //delete a data at the current Location
        virtual E remove() = 0;
       
        //set the current Location to the start of the List
        virtual void setListLocationToStart() = 0;
       
        //set the current Location to the end of the List
        virtual void setListLocationToEnd() = 0;
       
        //set the current Location to the element on left side
        // of current element
        virtual void previousElement() = 0;
       
        //set the current Location to the element on left side
        // of current element
        virtual void nextElement() = 0;
       
        //Set current Location to a new Location
        virtual int setToNewLocation(int location) = 0;
       
};

template <typename E>
class linkList: public List<E>
{
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;
    int currentLocation;//Current Location is started with 1
   
    public:
        //constructors and destructors
        linkList()
        {
            firstElement = lastElement = currentElement = new node<E>;
            sizeOfList = 0;
            currentLocation=0;
          
        }
        ~linkList()
        {
            for(currentElement = firstElement;firstElement != NULL;firstElement = firstElement->nextElement)
            {
                delete currentElement;
            }   
        }
        int NumberOfElements() const   //displays the number of elements in the linked list
        {
        return sizeOfList;       
        }
        int CurrentLocation() const   //displays the current location
        {
        
        return currentLocation;
        }
        const E& getData() const    //display the data at the current location
        {
        return currentElement->data;
        }
        void clear()
        {
        node <E> *temp=firstElement;
        currentElement=firstElement;
        while(temp!=NULL)
        {
        currentElement=temp->nextElement;
        delete temp;
        temp=currentElement;
        }
        firstElement=NULL;
        sizeOfList=0;
        }
        void insert(const E& data)  //inserts the data at the current location
        {
       
        node <E> *temp=firstElement;
        node <E> *newNode = new node <E>;
        newNode->data=data;
        
        if(sizeOfList!=0)
        {
        if(currentElement->nextElement!=NULL)
        {
        while(temp!=currentElement)
        {
         temp=temp->nextElement;
        }
        newNode->nextElement=temp->nextElement;
        temp->nextElement=newNode;
        currentElement=temp;    
        }
        else
        {
        while(temp->nextElement!=NULL)
        {
         temp=temp->nextElement;
        }
        temp->nextElement=newNode;
        newNode->nextElement=NULL;
        }
        currentElement=currentElement->nextElement;
        
        }
        else
        {
        firstElement=newNode;
        currentElement=firstElement;
        firstElement->nextElement=NULL;
        
        }
        sizeOfList++;
        currentLocation++;
       
        }
        void append(const E& data)  //appends the element at the end of the list
        {
        node <E> *temp=firstElement;
        node <E> *newNode = new node <E>;
        newNode->data=data;
        
        if(sizeOfList!=0)
        {
        while(temp->nextElement!=NULL)
        {
         temp=temp->nextElement;
        }
        temp->nextElement=newNode;
        newNode->nextElement=NULL;
        currentElement=newNode;
             
        }
        else
        {
        firstElement=newNode;
        newNode->nextElement=NULL;
        }
        sizeOfList++;
        currentLocation++; 
        }
       
        E remove()   //removes the element at the current location
        {
        E e=currentElement->data;
        node <E> *temp1=firstElement;
        node <E> *temp2= new node <E>;
        if(sizeOfList!=0)
        {
   
        if(currentElement==firstElement)
        {
  
        firstElement=currentElement->nextElement;
        currentElement=firstElement;
       
        }
       
        else if(currentElement->nextElement==NULL)
        {
        while(temp1!=currentElement)
        {
       
        temp2=temp1;
        temp1=temp1->nextElement;
       
        }
        currentElement=temp2;
        temp2->nextElement=NULL;
        
        delete temp1;
       
      
        }
       
        else
        {
      
         while(temp1!=currentElement)
        {
       
        temp2=temp1;
        temp1=temp1->nextElement;
       
        }
        temp2->nextElement=temp1->nextElement;
        currentElement=temp2;
        delete temp1;
       
        }
        }
        if(sizeOfList==0)
        cout<<endl<<"Linked List is Empty!"<<endl;
        sizeOfList--;
        currentLocation--;
        return e;
        }
        void setListLocationToStart()   //sets the current location to the starting of the list 
        {
        currentLocation=1;
        currentElement=firstElement;
        cout<<currentElement->data;
        }
        void setListLocationToEnd()   //sets the current location to the end of the list
        {
        currentLocation=sizeOfList;
        node <E> *temp=firstElement;
        while(temp->nextElement!=NULL)
        {
        temp=temp->nextElement;
        }
        currentElement=temp;
        cout<<currentElement->data;
        }
        void previousElement()     //sets the location to the previous element
        {
        node <E> *temp=firstElement;
        while(temp->nextElement!=currentElement)
        {
        temp=temp->nextElement;
        }
        currentElement=temp;
        cout<<currentElement->data;
        }
        void nextElement()    //sets the location to the next element
        {
        node <E> *temp=firstElement;
        while(currentElement->nextElement!=temp)
        {
        temp=temp->nextElement;
        }
        currentElement=temp;
       
        cout<<currentElement->data;
        }
        
        int setToNewLocation(int location) //sets the location to the given location by user
        {
        currentLocation=location;
        int count=1;
        node <E> *temp=firstElement;
        while(currentLocation!=count)
        {
        temp=temp->nextElement;
        count++;
        }
        currentElement=temp;
        cout<<currentElement->data<<endl;
        return currentLocation;
        }
        void display()  //displays the entire list
        {
        if(sizeOfList==0)
        {
        cout<<endl<<"List is empty cannot Display"<<endl;
        }
        else
        {
        cout<<endl;
        node <E> *temp=firstElement;
        cout<<temp->data<<" - > ";
        while(temp->nextElement!=NULL)
        {
        temp=temp->nextElement;
        cout<<temp->data<<" - > ";
        }
        cout<<"NULL";
        }
        }
};

int main()
{
linkList<int> p;
while(1)
{
cout<<endl<<"Enter any choice from following:"<<endl<<"1.Number of elements in the list"<<endl<<"2.Current Location in the list"<<endl<<"3.Get Data at the current location"<<endl<<"4.Clear the entire list"<<endl<<"5.Insert the element at the current location"<<endl<<"6.Append the element at the end of the list"<<endl<<"7.Remove the element from the current location"
<<endl<<"8.Set current location to the Starting Location"<<endl<<"9.Set current location to the End Location"<<endl<<"10.Set current location to the Previous Location"<<endl<<"11.Set current location to the Next Location"<<endl<<"12.Set current location to the New Location"<<endl<<"13.Display the entire list"<<endl<<endl;

int choice,a,b,c;
cout<<"Enter the choice number :"<<endl;
cin>>choice;

switch(choice)
{
case 1:cout<<"Number of elements:"<<p.NumberOfElements()<<endl;
       break;
case 2:cout<<"Current Location is:"<<p.CurrentLocation()<<endl;
       break;
case 3:cout<<"Data at location is:"<<p.getData()<<endl;
       break;
case 4:p.clear();
       break;
case 5:cout<<endl<<"Enter element to insert at the current location:";
       cin>>a;
       p.insert(a);
       break;
case 6:cout<<endl<<"Enter element to append at the location:";
       cin>>b;
       p.append(b);
       break;
case 7:cout<<endl<<"Removed Element is:"<<p.remove()<<endl;
      
        break;
case 8:p.setListLocationToStart();
        break;
case 9:p.setListLocationToEnd();
        break;
case 10:p.previousElement();
        break;
case 11:p.nextElement();
        break;
case 12:cout<<"Enter the desired location:";
        cin>>c;
        //Enter the location such that it is less than current size
        p.setToNewLocation(c);
        break;
case 13:p.display();
        break;
default:exit(1);
}
}
return 0;
}

