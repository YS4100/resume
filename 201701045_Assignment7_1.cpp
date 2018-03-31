//Filename : 201701045_Assignment7_1.cpp
//Author :Yashvi Shah
//SID : 201701045
//Assignment number : 7_1
//Description : Circular Queue using linked list.
//Last changed : 30-3-2018
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

template <typename E>
struct node{
E data;
node *nextElement;
};

template <typename E>
class linkList
{
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;

    public:
        //constructors and destructors
        linkList()
        {
	    firstElement = lastElement = currentElement =new node<E>;
            firstElement = lastElement = currentElement =NULL;
            sizeOfList = 0;
        }
        ~linkList()
        {
	    node<E> *temp;
            for(currentElement = temp = firstElement;currentElement != NULL;  currentElement)
            {
		temp=currentElement->nextElement;
                delete currentElement;
		currentElement=temp;
            }
        }
	int NumberOfElements() const  		 //Return the number of elements in the List
	{
		return sizeOfList;
	}
	const E getData() const  		 //Return the data of current element
	{
		return (currentElement->data);
	}
	void clear()   				 //clear all the data from the List
	{
		node<E> *temp;
        for(currentElement = temp = firstElement;currentElement != NULL;  currentElement)
	    {
		temp=currentElement->nextElement;
	    delete currentElement;
		currentElement=temp;
	    }
		firstElement = lastElement = currentElement =NULL;
		sizeOfList=0;
		cout<<"All element has deleted"<<endl;
	}

	void append(const E& data1)		//insert a data in the end of the List
	{
		node<E> *newNode=new node<E>;
		newNode->data = data1;
		newNode->nextElement=NULL;
		if(sizeOfList==0)
		{
		firstElement = lastElement = currentElement =newNode;
		}
		else
		{
		lastElement->nextElement=newNode;
		lastElement=newNode;
		}
		sizeOfList++;

	}
	void remove()				//delete a data at the current Location
	{
		if(sizeOfList!=0)
		{
		cout<<"The removed element is :"<<currentElement->data<<endl;
		if(firstElement==currentElement)
		{
		firstElement=firstElement->nextElement;
		delete currentElement;
		currentElement=firstElement;
		}
		else
		{
		node<E> *temp=new node<E>;
		node<E> *temp1=new node<E>;
		for(temp=temp1=firstElement;temp!=currentElement;temp=temp->nextElement)
		{
		temp1=temp;
		}
		temp1->nextElement=temp->nextElement;
		if(currentElement==lastElement)
		currentElement=temp1;
		else
		currentElement=temp1->nextElement;
		delete temp;
		}
		sizeOfList--;
		}
		else
		cout<<"List is empty"<<endl;
	}
	void setListLocationToStart()		//set the current Location to the start of the List
	{
	currentElement=firstElement;
	}
	void display()
	{
	node<E>* temp=new node<E>;
	temp=firstElement;
	cout<<"The queue is  :"<<endl;
	for(int i=1;i<=sizeOfList;i++,temp=temp->nextElement)
	cout<<temp->data<<" ";
	}
};

template <typename E>
class Queue
{
    void operator = (const Queue&) {}
    Queue(const Queue&) {}

    public:
        //constructors and destructors
        Queue() {}
        virtual ~Queue() {}

        // Insert an element at the end of the queue
        virtual void insert(const E &) = 0;

        //Remove the first element of the queue
        virtual E Remove() = 0;

        // Return the length of the queue
        virtual int length() const = 0;

        //Return a copy of the first element
        virtual const E FirstElement() const= 0;

        // Remove all the elements from the Queue
        // and free the occupied memory without causing
        // memory leak
        virtual void clearQueue() = 0;

};

template <typename E>
class QueueLinkList:  public Queue<E>
{
    //size of the link list
    int size;
    // Array for storing the data
    linkList<E>* QueueList;


    public:
        //constructors and destructors
        //constructors and destructors
        QueueLinkList()
        {
            QueueList = new linkList<E>();
        }
        ~QueueLinkList()
        {
            //for the next statement ensure
            // that you have implemented
            // destructor in the linkList class.
            delete QueueList;
        }
    void insert(const E& data)		// Insert an element at the end of the queue
	{
	QueueList->append(data);
    }
	E Remove()				//Remove the first element of the queue
	{
	E x;
	QueueList->setListLocationToStart();
	x=QueueList->getData();
	QueueList->remove();
	return x;
	}
	int length() const		// Return the length of the queue
	{
	return QueueList->NumberOfElements();
	}
	const E FirstElement() const	//Return a copy of the first element
	{
	E x;
	QueueList->setListLocationToStart();
	x=QueueList->getData();
	return x;
	}
	void clearQueue()		 // Remove all the elements from the Queue
	{
	QueueList->clear();
	}
	void displayq()
	{
	if(length()>0)
	{
	QueueList->display();
	}
	else
	cout<<" Queue is empty"<<endl;
	}
};

int main()
{
    int size,n,k=1,n1;
    QueueLinkList<int> q1;


    while(k==1)
    {
    cout<<"\n1. Length of Queue ";
    cout<<"\n2. Insert a data in queue";
    cout<<"\n3. Delete a data from queue";
    cout<<"\n4. Get first element of queue";
    cout<<"\n5. Clear queue";
    cout<<"\n6. Display ";
    cout<<"\n7. Exit"<<endl;
    cout<<"Enter the choice number :"<<endl;
    cin>>n;


   switch(n)
   {
   case 1:{if(q1.length()>0)
   {
   cout<<" Length of queue :"<<q1.length()<<endl;}
   else
   cout<<" Length of queue : 0"<<endl;
   break;
   }

	case 2:
   {
   int x;
   cout<<" Enter a data which you want to enter in queue :";
   cin>>x;
   q1.insert(x);
   cout<<"  After insertion :"<<endl;
	break;
   }

	case 3:
    {
    if(q1.length()>0)
	{
    int x;
	x=q1.Remove();
	}
    else
	cout<<"  Queue is empty"<<endl;
	break;
    }

	case 4:
    {
    if(q1.length()>0)
	{
    cout<<" First element of queue :"<<q1.FirstElement()<<endl;
    }
	else
	cout<<"  Queue is empty"<<endl;
	break;
    }

 	case 5:
    {
    if(q1.length()>0)
	q1.clearQueue();
	else
	cout<<"  Queue is empty"<<endl;
	break;
    }

    case 6:
    {
    if(q1.length()>0)
    q1.displayq();
    else
    cout<<"The queue is empty:"<<endl;
    break;
    }
 	case 7:
    {
    exit(1);
	break;
    }

	default:
    {
    cout<<"\nEnter correct choice"<<endl;
	exit(1);
    }
  }
 }
 return 0;
}


