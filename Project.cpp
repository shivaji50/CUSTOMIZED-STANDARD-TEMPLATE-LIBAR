#include<iostream>
#include <cstring>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////
//
//  This is structure for SinglyLinear,SinglyCircular,DoublyLinear,DoublyCircular.
//
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct node
{
	T data;
	struct node *next;
	struct node *prev; 
};


/////////////////////////////////////////////////////////////////////////////////////////
//
//  This is structure for Binary Search Tree
//
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodet
{
    T data;
    struct nodet *lchild;
    struct nodet *rchild;
};

//------------------------------------------------SinglyLinear----------------------------------------------//

//////////////////////////////////////////////////////////
//
//  This is class for SinglyLinear
//
//////////////////////////////////////////////////////////
template <class T>
class SinglyLL 
{
     private:
     	int iSize;
     	struct node<T> *Head;
     public:
     // Decleration done here	
     	SinglyLL();
        ~SinglyLL();
     	void InsertFirst(T iNo);
     	void InsertLast(T iNo);
     	void InsertAtPos(T iNo,int iPos);
     	void DeleteFirst();
     	void DeleteLast();
     	void DeleteAtPos(int iPos);
     	int Display();
     	int Count();
        int FirstOcc(T);
        int LastOcc(T);
        int AllOcc(T);
        int ReverseList();
     	
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//
// Function name : SinglyLL(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::~SinglyLL()
{
    Head=NULL;
    iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(Tcurrent!=NULL)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
        }
    }
    Head=Tprev;
    return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::AllOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        if(temp->data==iNo)
        {
            iCnt++;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}


//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::LastOcc(T iNo)
{
    struct node<T> * temp=Head;
    int iCnt=0,i=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        while(temp!=NULL)
        {
            i++;
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}


//////////////////////////////////////////////////////////
//
// Function name : SinglyLL(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
SinglyLL<T>::SinglyLL()
{
	iSize=0;
	Head=NULL;
}

//////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Argument      : 1  
// Description   : This function is use to insert node at
//                 First position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
  struct node<T> *newn=new struct node<T>;
  //Initilaze
  newn->data=iNo;
  newn->next=NULL;

  //Inserted at 1 position
  newn->next=Head;
  Head=newn;
  iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Argument      : 1  
// Description   : This function is use to insert node at
//                 Last position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
	struct node<T> *newn=new struct node<T>;
	//Initialize
    newn->data=iNo;
    newn->next=NULL;
    //Tempory variable
    struct node<T> *temp=Head;

    //Inserted at last position
    if(Head==NULL)
    {
    	Head=newn;
    }
    else
    {
    	while(temp->next!=NULL)
    	{
    		temp=temp->next;
    	}
    	temp->next=newn;
    }
    iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Argument      : 2  
// Description   : This function is use to insert node at
//                 any position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
{
	//If Position is wrong
   if((iPos<1)||(iPos>iSize+1))
   {
   	   cout<<"Wrong option\n";
   	   return;
   }

   //Initilization
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;

   //Tempory variable
   struct node<T> *temp=Head;

   //For First
   if(iPos==1)
   {
   	 newn->next=Head;
   	 Head=newn;
   }
   else if(iPos==iSize+1) //For Last
   {
   	   if(Head==NULL)
   	   {
   	   	 Head=newn;
   	   }
   	   else
   	   {
   	   	  while(temp->next!=NULL)
    	 {
    		 temp=temp->next;
    	 }
    	 temp->next=newn;
       }
   }
   else  //For specific position
   {
   	  for(int i=1;i<iPos-1;i++)
   	  {
   	  	temp=temp->next;
   	  }
   	  newn->next=temp->next;
   	  temp->next=newn;
   }
   iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Argument      : 0
// Description   : This function is to delete the First node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    //Empty node
    if(Head==NULL)
    {
    	cout<<"Empty node";
    	return;
    }

    //Temporary variable
    struct node<T> *temp=Head;

    if(Head->next==NULL)  //Only one node
    {
    	delete Head;
    	Head=NULL;
    }
    else
    {
       Head=Head->next;
       delete temp;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Argument      : 0
// Description   : This function is to delete the Last node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
	//Empty node
    if(Head==NULL)
    {
    	cout<<"Empty node";
    	return;
    }

    //Temporary variable
    struct node<T> *temp=Head;

    if(Head->next==NULL)  //Only one node
    {
    	delete Head;
    	Head=NULL;
    }
    else
    {
       while(temp->next->next!=NULL)
       {
       	 temp=temp->next;
       }
       delete temp->next;
       temp->next=NULL;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Argument      : 1
// Description   : This function is to delete the node
//                 at Position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	//If Position is wrong
   if((iPos<1)||(iPos>iSize))
   {
   	   cout<<"Wrong option\n";
   	   return;
   }

   //Tempory variable
   struct node<T> *temp=Head;
   //Temporary variable for delete at position
   struct node<T> *target=NULL;

   if(iPos==1) //For First node
   {	
   	   if(Head->next==NULL)  //Only one node
      {
    	 delete Head;
    	 Head=NULL;
      }
      else
     {
        Head=Head->next;  //More then one node
        delete temp;
     }
   }
   else if(iPos==iSize)
   {
   	  if(Head->next==NULL)  //Only one node
      {
    	 delete Head;
    	 Head=NULL;
      }
      else
      {
          while(temp->next->next!=NULL) //More then one node
        {
       	    temp=temp->next;
        }
         delete temp->next;
         temp->next=NULL;
      }
   }
   else
   {
   	  for(int i=1;i<iPos-1;i++)
   	  {
   	  	temp=temp->next;
   	  }
   	  target=temp->next;
   	  temp->next=target->next;
   	  delete target;
   } 
   iSize--;
}

//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0
// Description   : This function is to display all the data
//                 of nodes
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::Display()
{
   struct node<T> *temp=Head; 

   if(temp==NULL)
   {
    return-1;
   }
   else
   {
     while(temp!=NULL)
     {
        cout<<temp->data<<"\t";
        temp=temp->next;
     }
       cout<<"\n";
   }
   return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0
// Description   : This function is use to count the nodes 
//                 in LinkList. 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::Count()
{
	return iSize;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::FirstOcc(T iNo)
{
    int iCnt=0,i=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        i++;
        if(temp->data==iNo)
        {
            iCnt=i;
            break;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}


//--------------------------------------------------End of SinglyLinear----------------------------------------//


//--------------------------------------------------Doubly Linear----------------------------------------------//

//////////////////////////////////////////////////////////
//
//  This is class for DoublyLinear
//
//////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
     private:
     	int iSize;
     	struct node<T> *Head;

     public:
     // Decleration done here	
     	DoublyLL();
        ~DoublyLL();
     	void InsertFirst(T iNo);
     	void InsertLast(T iNo);
     	void InsertAtPos(T iNo,int iPos);
     	void DeleteFirst();
     	void DeleteLast();
     	void DeleteAtPos(int iPos);
     	int Display();
     	int Count();
        int FirstOcc(T);
        int LastOcc(T);
        int AllOcc(T);
        int ReverseList();
     	
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(Tcurrent!=NULL)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tcurrent->prev=Tnext;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
        }
    }
    Head=Tprev;
    return 0;
}




//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::AllOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        if(temp->data==iNo)
        {
            iCnt++;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}

//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::LastOcc(T iNo)
{
    struct node<T> * temp=Head;
    int iCnt=0,i=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        while(temp!=NULL)
        {
            i++;
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}

//////////////////////////////////////////////////////////
//
// Function name : DoublyLL(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::~DoublyLL()
{
    Head=NULL;
    iSize=0;
}


//////////////////////////////////////////////////////////
//
// Function name : DoublyLL(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
DoublyLL<T>::DoublyLL()
{
	iSize=0;
	Head=NULL;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Argument      : 1  
// Description   : This function is use to insert node at
//                 First position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)  //For empty node
    {
    	Head=newn;
    }
    else     //For more then one node
    {
    	newn->next=Head;
    	Head->prev=newn;
    	Head=newn;
    }
    iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Argument      : 1  
// Description   : This function is use to insert node at
//                 Last position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
	struct node<T> *newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    //Tempory variable
    struct node<T> *temp=Head; 

    if(Head==NULL)  //For empty node
    {
    	Head=newn;
    }
    else     //For more then one node
    {
    	while(temp->next!=NULL)
    	{
    		temp=temp->next;
    	}
    	temp->next=newn;
    	newn->prev=temp;
    }
    iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Argument      : 2  
// Description   : This function is use to insert node at
//                 any position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::InsertAtPos(T iNo,int iPos)
{
	//If Position is wrong
   if((iPos<1)||(iPos>iSize+1))
   {
   	   cout<<"Wrong option\n";
   	   return;
   }

   //Initilization
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;
   newn->prev=NULL;

   //Tempory variable
   struct node<T> *temp=Head;

   //For First
   if(iPos==1)
   {
   	      if(Head==NULL)  //For empty node
         {
    	     Head=newn;
         }
         else     //For more then one node
         {
    	     newn->next=Head;
    	     Head->prev=newn;
    	     Head=newn;
         }
   } 
   else if(iPos==iSize+1)
   {
   	    if(Head==NULL)  //For empty node
        {
    	      Head=newn;
        }
        else     //For more then one node
       {
    	     while(temp->next!=NULL)
    	     {
    		    temp=temp->next;
    	     }
    	     temp->next=newn;
    	    newn->prev=temp;
       }
   }
   else
   {
   	   for(int i=1;i<iPos-1;i++)
   	  {
   	  	temp=temp->next;
   	  }
   	   newn->next=temp->next;
       temp->next->prev=newn;  
       temp->next=newn;
       newn->prev=temp;
   } 
   iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Argument      : 0
// Description   : This function is to delete the First node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head==NULL)   // 0 Node
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
        Head->prev=NULL;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Argument      : 0
// Description   : This function is to delete the Last node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::DeleteLast()
{
    //Temporay variable
    struct node<T> *temp=Head;
	if(Head==NULL)   // 0 Node
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head->next==NULL) //For one node
    {
        delete Head;
        Head=NULL;
    }
    else //For more then one node
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Argument      : 1
// Description   : This function is to delete the First node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	//If Position is wrong
   if((iPos<1)||(iPos>iSize))
   {
       cout<<"Wrong option\n";
       return;
   }
  
   //Temporary variable
   struct node<T> *temp=Head;

   if(iPos==1) //For first
   {
       if(Head->next==NULL)
      {
        delete Head;
        Head=NULL;
      }
       else
      {
        Head=Head->next;
        delete Head->prev;
        Head->prev=NULL;
      }
   }
   else if(iPos==iSize)
   {
       if(Head->next==NULL) //For one node
      {
        delete Head;
        Head=NULL;
       }
      else //For more then one node
      {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
      }
   }
   else
   {
       for(int i=1;i<iPos-1;i++)
      {
        temp=temp->next;
      }
      temp->next=temp->next->next;
      delete temp->next->prev;
      temp->next->prev=temp;
   }
   iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0
// Description   : This function is to display all the data
//                 of nodes
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::Display()
{
   struct node<T> *temp=Head; 

   if(temp==NULL)
   {
    return-1;
   }
   else
   {
     while(temp!=NULL)
     {
        cout<<temp->data<<"\t";
        temp=temp->next;
     }
       cout<<"\n";
   }
   return 0;
}



//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0
// Description   : This function is use to count the nodes 
//                 in LinkList. 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::Count()
{
	return iSize;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyLL<T>::FirstOcc(T iNo)
{
    int iCnt=0,i=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        i++;
        if(temp->data==iNo)
        {
            iCnt=i;
            break;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}





//--------------------------------------------------End of Doublyinear----------------------------------------//


//--------------------------------------------------Singly Circular----------------------------------------------//


//////////////////////////////////////////////////////////
//
//  This is class for SinglyLinear
//
//////////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
     private:
        int iSize;
        struct node<T> *Head;
        struct node<T> *Tail;
     public:
     // Decleration done here   
        SinglyCL();
        ~SinglyCL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int Display();
        int Count();
        int FirstOcc(T);
        int LastOcc(T);
        int AllOcc(T);
        int ReverseList();
        
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;
    int i=1;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(i<=iSize)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
            i++;
        }
    }
    Tail=Head;
    Head=Tprev;
    Tail->next=Head;
    return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::AllOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            if(temp->data==iNo)
            {
                iCnt++;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}

//////////////////////////////////////////////////////////
//
// Function name : SinglyCL(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
SinglyCL<T>::~SinglyCL()
{
    Head=NULL;
    iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::LastOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}



//////////////////////////////////////////////////////////
//
// Function name : SinglyCL(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
SinglyCL<T>::SinglyCL()
{
    iSize=0;
    Head=NULL;
    Tail=NULL;
}

//////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Argument      : 1  
// Description   : This function is use to insert node at
//                 First position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;

   if(Head==NULL)
   {
     Head=newn;
     Tail=newn;
   }
   else  // More then one node
   {
     newn->next=Head;
     Head=newn;
   }
   iSize++;
   Tail->next=Head;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Argument      : 1  
// Description   : This function is use to insert node at
//                 Last position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;

   if(Head==NULL)
   {
     Head=newn;
     Tail=newn;
   }
   else  // More then one node
   {
     Tail->next=newn;
     Tail=newn;
   }
   iSize++;
   Tail->next=Head;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Argument      : 2  
// Description   : This function is use to insert node at
//                 any position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertAtPos(T iNo,int iPos)
{
    //If Position is wrong
   if((iPos<1)||(iPos>iSize+1))
   {
       cout<<"Wrong option\n";
       return;
   }

   //Initilization
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;

   //Tempory variable
   struct node<T> *temp=Head;

   //For First
   if(iPos==1)
   {
       if(Head==NULL)
      {
          Head=newn;
          Tail=newn;
      }
       else  // More then one node
      {
         newn->next=Head;
         Head=newn;
      }

   } 
   else if(iPos==iSize+1)  //For last
   {
        if(Head==NULL)
       {
          Head=newn;
          Tail=newn;
       }
       else  // More then one node
      {
         Tail->next=newn;
         Tail=newn;
      }
   }
   else  //For position
   {
       for(int i=1;i<iPos-1;i++)
      {
        temp=temp->next;
      }
       newn->next=temp->next;
       temp->next=newn;
   } 
   iSize++;
   Tail->next=Head;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Argument      : 0
// Description   : This function is to delete the First node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(Head==NULL)
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete Tail->next;
        Tail->next=Head;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Argument      : 0
// Description   : This function is to delete the Last node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteLast()
{
    //Temporary variable
    struct node<T> *temp=Head;
    if(Head==NULL)
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        for(int i=1;i<iSize-1;i++)
        {
            temp=temp->next;
        }
        delete Tail;
        Tail=temp;
        Tail->next=Head;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Argument      : 1
// Description   : This function is to delete the node
//                 at Position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    //If Position is wrong
   if((iPos<1)||(iPos>iSize))
   {
       cout<<"Wrong option\n";
       return;
   }
  
   //Temporary variable
   struct node<T> *temp=Head;
   struct node<T> *target=NULL;

   if(iPos==1) //For first
   {
       if(Head==Tail)
       {
          delete Head;
          Head=NULL;
          Tail=NULL;
       }
      else
       {
         Head=Head->next;
         delete Tail->next;
         Tail->next=Head;
       }
   }
   else if(iPos==iSize)
   {
       if(Head==Tail)
      {
        delete Head;
        Head=NULL;
        Tail=NULL;
      }
       else
      {
          for(int i=1;i<iSize-1;i++)
         { 
             temp=temp->next;
         }
         delete Tail;
         Tail=temp;
         Tail->next=Head;
      }
   }
   else
   {
       for(int i=1;i<iPos-1;i++)
      {
        temp=temp->next;
      }
      target=temp->next;
      temp->next=target->next;
      delete target;
      Tail->next=Head;// This is optional    
   }
   iSize--;
}

//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0
// Description   : This function is to display all the data
//                 of nodes
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Display()
{
    struct node<T> *temp=Head;

 if(temp==NULL)
 {
    return-1;
 }
 else
 {
    for(int i=1;i<=iSize;i++)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
 }
 return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0
// Description   : This function is use to count the nodes 
//                 in LinkList. 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Count()
{
    return iSize;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::FirstOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            
            if(temp->data==iNo)
            {
                iCnt=i;
                break;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}





//--------------------------------------------------End of SinglyCircular----------------------------------------//


//--------------------------------------------------Doubly Circular----------------------------------------------//


//////////////////////////////////////////////////////////
//
//  This is class for Doublycircular
//
//////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
     private:
        int iSize;
        struct node<T> *Head;
        struct node<T> *Tail;
     public:
     // Decleration done here   
        DoublyCL();
        ~DoublyCL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int Display();
        int Count();
        int FirstOcc(T);
        int LastOcc(T);
        int AllOcc(T);
        int ReverseList();
        
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;
    int i=1;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(i<=iSize)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tcurrent->prev=Tnext;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
            i++;
        }
    }
    Tail=Head;
    Head=Tprev;
    Tail->next=Head;
    Head->prev=Tail;
    return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::AllOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            if(temp->data==iNo)
            {
                iCnt++;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}



//////////////////////////////////////////////////////////
//
// Function name : DoublyCL(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
DoublyCL<T>::~DoublyCL()
{
    Head=NULL;
    iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::LastOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}




//////////////////////////////////////////////////////////
//
// Function name : DoublyCL(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
DoublyCL<T>::DoublyCL()
{
    iSize=0;
    Head=NULL;
    Tail=NULL;
}

//////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Argument      : 1  
// Description   : This function is use to insert node at
//                 First position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
     Head=newn;
     Tail=newn;
   }
   else
   {
      newn->next=Head;
      Head->prev=newn;
      Head=newn;
   }
   Tail->next=Head;
   Head->prev=Tail;
   iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Argument      : 1  
// Description   : This function is use to insert node at
//                 Last position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;
   newn->prev=NULL;

   if(Head==NULL)
   {
     Head=newn;
     Tail=newn;
   }
   else
   {
      Tail->next=newn;
      newn->prev=Tail;
      Tail=newn;
   }
   Tail->next=Head;
   Head->prev=Tail;
   iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Argument      : 2  
// Description   : This function is use to insert node at
//                 any position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertAtPos(T iNo,int iPos)
{
    //If Position is wrong
   if((iPos<1)||(iPos>iSize+1))
   {
       cout<<"Wrong option\n";
       return;
   }

   struct node<T> *newn=new struct node<T>;
   newn->data=iNo;
   newn->next=NULL;
   newn->prev=NULL;

   //Temporary variable
   struct node<T> *temp=Head;

   if(iPos==1)
   {
      if(Head==NULL)
      {
          Head=newn;
          Tail=newn;
      }
      else
      {
         newn->next=Head;
         Head->prev=newn;
         Head=newn;
      }
       Tail->next=Head;
       Head->prev=Tail;
   }
   else if(iPos==iSize+1)
   {
       if(Head==NULL)
       {
          Head=newn;
          Tail=newn;
       }
       else
       {
         Tail->next=newn;
         newn->prev=Tail;
         Tail=newn;
       }
       Tail->next=Head;
       Head->prev=Tail;
   }
   else
   {
       for(int i=1;i<iPos-1;i++)
      {
        temp=temp->next;
      }
      newn->next=temp->next;
      temp->next->prev=newn;
      temp->next=newn;
      newn->prev=temp;
   }
   iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Argument      : 0
// Description   : This function is to delete the First node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteFirst()
{
   if(Head==NULL)
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete Head->prev;
        Tail->next = Head;
        Head->prev = Tail;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Argument      : 0
// Description   : This function is to delete the Last node
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(Head==NULL)
    {
        cout<<"The LinkList is empty\n";
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Tail=Tail->prev;
        delete Head->prev;
        Tail->next = Head;
        Head->prev = Tail;
    }
    iSize--;
}


//////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Argument      : 1
// Description   : This function is to delete the node
//                 at Position
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    //If Position is wrong
   if((iPos<1)||(iPos>iSize+1))
   {
       cout<<"Wrong option\n";
       return;
   }

   //Temporary Variabe
   struct node<T> *temp=Head;

   if(iPos==1)
   {
       if(Head==NULL)
       {
          cout<<"The LinkList is empty\n";
          return;
       }
       else if(Head==Tail)
       {
          delete Head;
          Head=NULL;
          Tail=NULL;
       }
       else
       {
         Head=Head->next;
         delete Head->prev;
         Tail->next = Head;
         Head->prev = Tail;
       }
   }
   else if(iPos==iSize)
   {
        if(Head==NULL)
        {
           cout<<"The LinkList is empty\n";
           return;
        }
        else if(Head==Tail)
        {
           delete Head;
           Head=NULL;
           Tail=NULL;
        }
       else
       {
          Tail=Tail->prev;
          delete Head->prev;
          Tail->next = Head;
          Head->prev = Tail;
       }
   }
   else
       {
          for(int i=1;i<iPos-1;i++)
          {
            temp = temp->next;
          }
          temp->next = temp->next->next;
          delete(temp->next->prev);
          temp->next->prev = temp;
       }
       iSize--;
}

//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0
// Description   : This function is to display all the data
//                 of nodes
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::Display()
{
    struct node<T> *temp=Head;

 if(temp==NULL)
 {
    return-1;
 }
 else
 {
    for(int i=1;i<=iSize;i++)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
 }
 return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0
// Description   : This function is use to count the nodes 
//                 in LinkList. 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::Count()
{
    return iSize;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::FirstOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            
            if(temp->data==iNo)
            {
                iCnt=i;
                break;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}

//--------------------------------------------------End of DoublyCircular----------------------------------------//


//---------------------------------------------------------Stack-------------------------------------------------//

//////////////////////////////////////////////////////////
//
//  This is class for Stack-Linklist
//
//////////////////////////////////////////////////////////

template<class T>
class Stack
{
  private:
    int iSize;
    struct node<T> *Head;
  public:
  // Deleration done here
     Stack();
     ~Stack();
     void Push(T iNo);
     T Pop();
     T Peek();
     int Display();
     int Count();
     int FirstOcc(T);
     int LastOcc(T);
     int AllOcc(T);
     int ReverseList();

};


//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(Tcurrent!=NULL)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
        }
    }
    Head=Tprev;
    return 0;
}




//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::AllOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        if(temp->data==iNo)
        {
            iCnt++;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}


//////////////////////////////////////////////////////////
//
// Function name : Stack(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
Stack<T>::~Stack()
{
    Head=NULL;
    iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::LastOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        for(int i=1;i<=iSize;i++)
        {
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}




//////////////////////////////////////////////////////////
//
// Function name : Stack(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
Stack<T>::Stack()
{
    iSize=0;
    Head=NULL;
}

//////////////////////////////////////////////////////////
//
// Function name : Push
// Argument      : 1  
// Description   : This function is use to Push the
//                 elements in the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Push(T iNo)
{
    //Temporary variable
    struct node<T> *temp=Head;
    struct node<T> *newn=new struct node<T>;
    //Initialize
    newn->data=iNo;
    newn->next=NULL;

    //Inserted at last position
    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;

    }
    iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : Pop
// Argument      : 0  
// Description   : This function is use to Pop(delete) the
//                 elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Pop()
{
    //Temporary variable
    struct node<T> *temp=Head;
    T iRet=0;
    if(Head==NULL) //Empty Stack
    {
        cout<<"Empty Stack\n";
        return -1;
    }
    else if(Head->next==NULL) //only one element in stack
    {
        delete Head;
        Head=NULL;
        iSize--;
    }
    else
    {
        Head=Head->next;
        iRet=temp->data;
        delete temp;
        iSize--;
    } 
    return iRet;
      
}


//////////////////////////////////////////////////////////
//
// Function name : Peek
// Argument      : 0  
// Description   : This function is use to Peep the
//                 elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Peek()
{
    if(iSize==0)
    {
        cout<<"Stack is empty";
        return -1;
    }
    else
    {
        return Head->data;
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0  
// Description   : This function is use to Dispaly
//                 all the elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Display()
{
   struct node<T> *temp=Head; 

   if(temp==NULL)
   {
    return-1;
   }
   else
   {
     while(temp!=NULL)
     {
        cout<<temp->data<<"\t";
        temp=temp->next;
     }
       cout<<"\n";
   }
   return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0  
// Description   : This function is use to Count the number
//                 of elements in the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Count()
{
    return iSize;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Stack<T>::FirstOcc(T iNo)
{
    int iCnt=0,i=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        i++;
        if(temp->data==iNo)
        {
            iCnt=i;
            break;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}



//--------------------------------------------------End of Stack----------------------------------------//


//--------------------------------------------------Stack using Array----------------------------------//

//////////////////////////////////////////////////////////
//
//  This is class for Stack-Using Array
//
//////////////////////////////////////////////////////////
template <class T>
class StackA
{
  private:
    T *Arr;
    int iTop;
    int iSize;
  public:
  StackA();
  ~StackA();
  void ArraySize(int);
  void Push(T);
  T Pop();
  T Peek();
  int Display();
  int FirstOcc(T);
  int LastOcc(T);
  int AllOcc(T);   
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int StackA<T>::AllOcc(T iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            
            if(Arr[i]==iNo)
            {
                iCnt++;
            }
        }
    }
    return iCnt;
}





//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int StackA<T>::LastOcc(T iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            
            if(Arr[i]==iNo)
            {
                iCnt=i+1;
            }
        }
    }
    return iCnt;
}



//////////////////////////////////////////////////////////
//
// Function name : Stack(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
StackA<T>::StackA()
{
    iTop=-1;
}


//////////////////////////////////////////////////////////
//
// Function name : Stack(Destructor)
// Description   : This function is use to delete 
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
StackA<T>::~StackA()
{
   delete []Arr;
   iTop=-1;
}

//////////////////////////////////////////////////////////
//
// Function name : ArraySize
// Argument      : 1  
// Description   : This function is use to create the 
//                 Array
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void StackA<T>::ArraySize(int iNo)
{
    Arr=new T[iNo];
    iSize=iNo;
}


//////////////////////////////////////////////////////////
//
// Function name : Push
// Argument      : 1  
// Description   : This function is use to Push the
//                 elements in the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////

template <class T>
void StackA<T>::Push(T iNo)
{
    if(iTop==iSize-1)
    {
        cout<<"Stack is Full\n";
        return;
    }
    else
    {
        iTop++;
        Arr[iTop]=iNo;
    }

}


//////////////////////////////////////////////////////////
//
// Function name : Pop
// Argument      : 0  
// Description   : This function is use to Pop(delete) the
//                 elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
T StackA<T>::Pop()
{
    if(iTop==-1)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else
    {
        T iNo=Arr[iTop];
        iTop--;
        return iNo;
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Peek
// Argument      : 0  
// Description   : This function is use to Peep the
//                 elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
T StackA<T>::Peek()
{
    if(iTop==-1)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else
    {
        int iNo=Arr[iTop];
        return iNo;
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0  
// Description   : This function is use to Dispaly
//                 all the elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int StackA<T>::Display()
{
    if(iTop==-1)
    {
        return -1;
        
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}


//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 1
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int StackA<T>::FirstOcc(T iNo)
{
    int iCnt=0;

    if(iTop==-1)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<=iTop;i++)
        {
            
            if(Arr[i]==iNo)
            {
                iCnt=i+1;
                break;
            }
        }
    }
    return iCnt;
}


//--------------------------------------------------End of Stack using Array--------------------------------//


//--------------------------------------------------------Queue-LinkList-----------------------------------//

//////////////////////////////////////////////////////////
//
//  This is class for Queue - Linklist
//
//////////////////////////////////////////////////////////
template <class T>
class Queue
{
  private:
    struct node<T> *Head;
    int iSize;
  public:
    Queue();
    ~Queue();
    void Push(T);
    T Pop();
    int Count();
    int Display(); 
    int FirstOcc(T);
    int LastOcc(T);
    int AllOcc(T);
    int ReverseList();
};


//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
// Function name : ReverseList
// Argument      : 0
// Description   : This function is use to Reverse the 
//                 linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::ReverseList()
{
    struct node<T> *Tcurrent=Head;
    struct node<T> *Tprev=NULL;
    struct node<T> *Tnext=NULL;

    if(Tcurrent==NULL)
    {
        return -1;
    }
    else
    {
        while(Tcurrent!=NULL)
        {
            Tnext=Tcurrent->next;
            Tcurrent->next=Tprev;
            Tprev=Tcurrent;
            Tcurrent=Tnext;
        }
    }
    Head=Tprev;
    return 0;
}





//////////////////////////////////////////////////////////
//
// Function name : AllOcc
// Argument      : 1
// Description   : This function is use to Find the Alloccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::AllOcc(T iNo)
{
    int iCnt=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        if(temp->data==iNo)
        {
            iCnt++;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}



//////////////////////////////////////////////////////////
//
// Function name : Queue(Destructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
Queue<T>::~Queue()
{
    Head=NULL;
    iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : LastOcc
// Argument      : 1
// Description   : This function is use to Find the Lasttoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::LastOcc(T iNo)
{
    struct node<T> *temp=Head;
    int iCnt=0,i=0;

    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        while(temp!=NULL)
        {
            i++;
            if(temp->data==iNo)
            {
                iCnt=i;
            }
            temp=temp->next;
        }
    }
    return iCnt;
}



//////////////////////////////////////////////////////////
//
// Function name : Queue(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
Queue<T>::Queue()
{
    Head=NULL;
    iSize=0;
}


//////////////////////////////////////////////////////////
//
// Function name : Push
// Argument      : 1  
// Description   : This function is use to Push the
//                 elements in the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void Queue<T>::Push(T iNo)
{
    struct node<T> *newn=NULL;
    struct node<T>  *temp;
    newn =new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iSize++;
}


//////////////////////////////////////////////////////////
//
// Function name : Pop
// Argument      : 0  
// Description   : This function is use to Pop(delete) the
//                 elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
T Queue<T>::Pop()
{
    
    T iNo;
    struct node<T> *temp;

    if(iSize==0)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

     iNo=Head->data;
    if(Head->next==NULL)
    {
       
        delete Head;
        Head=NULL;
    }
    else
    {
        
        temp=Head;
        Head=Head->next;
        delete temp;

    }
    iSize--;
    return iNo;
}


//////////////////////////////////////////////////////////
//
// Function name : Display
// Argument      : 0  
// Description   : This function is use to Dispaly
//                 all the elements from the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Display()
{
   struct node<T> *temp=Head; 

   if(temp==NULL)
   {
    return-1;
   }
   else
   {
     while(temp!=NULL)
     {
        cout<<temp->data<<"\t";
        temp=temp->next;
     }
       cout<<"\n";
   }
   return 0;
}

//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 0  
// Description   : This function is use to Count the number
//                 of elements in the stack
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Count()
{
    return iSize;
}



//////////////////////////////////////////////////////////
//
// Function name : FirstOcc
// Argument      : 0
// Description   : This function is use to Find the firstoccurance 
//                 of given elements from the linklist 
// Author name   : Shivaji das
// Date          : 26-05-2021
//////////////////////////////////////////////////////////
template <class T>
int Queue<T>::FirstOcc(T iNo)
{
    int iCnt=0,i=0;
    struct node<T> *temp=Head;

    if(temp==NULL)
    {
        return-1;
    }
    else
    {

     while(temp!=NULL)
     {
        i++;
        if(temp->data==iNo)
        {
            iCnt=i;
            break;
        }
        temp=temp->next;
     }
    } 
    return iCnt;
}


//--------------------------------------------------End of Queue-LinkList--------------------------------------//



//--------------------------------------------------Binary Search Tree--------------------------------------//


//////////////////////////////////////////////////////////
//
//  This is class for Binary Search Tree
//
//////////////////////////////////////////////////////////
template <class T>
class BST
{
  private:
    struct nodet<T> *Head;
    int iSize;
  public:

    BST();
    ~BST();
    void InsertNode(struct nodet<T> **,T);
    void Inorder(struct nodet<T> *);
    void Preorder(struct nodet<T> *);
    void Postorder(struct nodet<T> *);
    void Count(struct nodet<T> *,int *);
    void CountParents(struct nodet<T> *,int *);
    void CountLeaf(struct nodet<T> *,int *);
    bool SearchRecursion(struct nodet<T> *,T);
    bool SearchNormal(T);
    int NormalCount();  
};

//////////////////////////////////////////////////////////
//
//  Here all the defination of the function are done
//
//////////////////////////////////////////////////////////

template <class T>
 BST<T>::~BST()
{
        Head=NULL;
        iSize=0;
}

//////////////////////////////////////////////////////////
//
// Function name : Stack(Constructor)
// Description   : This function is use to initialize
//                 the class charestics.
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
 BST<T>::BST()
{
        Head=NULL;
        iSize=0;
}


//////////////////////////////////////////////////////////
//
// Function name : InsertNode
// Argument      : 2  
// Description   : This function is use to insert
//                 elements in the BST
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::InsertNode(struct nodet<T> **Root,T iNo)
{
    struct nodet<T> *temp = Head;
    struct nodet<T> *newn = NULL;
    newn = new struct nodet<T>;
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(Head == NULL)
    {
        
        Head = newn;
        *Root = Head;
        iSize++;
        
    }
    else
    {
        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iSize++;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iSize++;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)
            {
                cout<<"Duplicate elements\n";
                delete newn;
                break;
            }
        }
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Inorder
// Argument      : 1 
// Description   : This function is use to Dispaly
//                 elements of BST inoreder
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::Inorder(struct nodet<T> *Head1)
{
    
    if(Head1!=NULL)
    {
        
        Inorder(Head1->lchild);
        cout<<Head1->data<<"\t";
        Inorder(Head1->rchild);
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Preorder
// Argument      : 1 
// Description   : This function is use to Dispaly
//                 elements of BST Preorder
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::Preorder(struct nodet<T> *Head1)
{
    if(Head1!=NULL)
    {
        cout<<Head1->data<<"\t";
        Preorder(Head1->lchild);
        Preorder(Head1->rchild);
    }

}


//////////////////////////////////////////////////////////
//
// Function name : Preorder
// Argument      : 1 
// Description   : This function is use to Dispaly
//                 elements of BST Preorder
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::Postorder(struct nodet<T> *Head1)
{
     if(Head1!=NULL)
    {
        
        Postorder(Head1->lchild);
        Postorder(Head1->rchild);
        cout<<Head1->data<<"\t";
    }
}


//////////////////////////////////////////////////////////
//
// Function name : Count
// Argument      : 1 
// Description   : This function is use to Count
//                 elements in BST using recursion
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::Count(struct nodet<T> *Head1,int *i)
{
    if(Head1!=NULL)
    {
        (*i)++;
        Count(Head1->lchild,i);
        Count(Head1->rchild,i);
    }
}


//////////////////////////////////////////////////////////
//
// Function name : CountLeaf
// Argument      : 1 
// Description   : This function is use to CountLeaf(nodes)
//                 elements in BST using recursion
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::CountLeaf(struct nodet<T> *Head1,int *i)
{
    if(Head1!=NULL)
    {
        if((Head1->lchild==NULL)&&(Head1->rchild==NULL))
        {
            (*i)++;
        }
        CountLeaf(Head1->lchild,i);
        CountLeaf(Head1->rchild,i);
    }
}


//////////////////////////////////////////////////////////
//
// Function name : CountParents
// Argument      : 1 
// Description   : This function is use to CountParents(nodes)
//                 elements in BST using recursion
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
void BST<T>::CountParents(struct nodet<T> *Head1,int *i)
{
    if(Head1!=NULL)
    {
        if((Head1->lchild!=NULL)||(Head1->rchild!=NULL))
        {
            (*i)++;
        }
        CountParents(Head1->lchild,i);
        CountParents(Head1->rchild,i);
    }
}


//////////////////////////////////////////////////////////
//
// Function name : SearchRecursion
// Argument      : 2 
// Description   : This function is use to search
//                 elements in BST using recursion
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
bool BST<T>::SearchRecursion(struct nodet<T> *Head1,T iNo)
{
    if(Head1!=NULL)
    {
        if(iNo > Head1->data)
        {
            return SearchRecursion(Head1->rchild,iNo);
        }
        else if(iNo < Head1->data)
        {
            return SearchRecursion(Head1->lchild,iNo);
        }
        else if(iNo==Head1->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


//////////////////////////////////////////////////////////
//
// Function name : SearchRecursion
// Argument      : 2 
// Description   : This function is use to search
//                 elements in BST using loop
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
bool BST<T>::SearchNormal(T iNo)
{
   struct nodet<T> *temp = Head;

   if(temp==NULL)
   {
    return false;
   }
   else
   {
     while(1)
     {
         if(iNo > temp->data)
         {
             if(temp->rchild==NULL)
             {
                break;
             }
             temp = temp->rchild;
         }
         else if(iNo < temp->data)
         {
             if(temp->lchild==NULL)
             {
                break;
             }
             temp = temp->lchild;
         }
         else if(iNo==temp->data)
         {
            break;
         }
     }
   }

   if(iNo==temp->data)
   {
     return true;
   }
   else
   {
     return false;
   }
}


//////////////////////////////////////////////////////////
//
// Function name : NormalCount
// Argument      : 0 
// Description   : This function is use to count
//                 elements in BST normally
// Author name   : Shivaji das
// Date          : 28-07-2021
//////////////////////////////////////////////////////////
template <class T>
int BST<T>::NormalCount()
{
    return iSize;
}


void Authentication()
    {
    static int i=0;
    char pass[20];

    if(i==3)
    {
        cout<<"You Entered Wrong Password 3 times..Sorry!\n";
        exit(0);
    }

    cout<<"Enter Correct Password:\n";
    cin>>pass;

    if(strcmp(pass,"SHIVAJI")==0)
    {
      cout<<"You Entered Correct Password..Welcome..!\n";
    }
    else
    {
        cout<<"Wrong Password..!\n";
        i++;
        Authentication();
    }

}


//-----------------------------------------------End of Binary Search Tree--------------------------------------//



//////////////////////////////////////////////////////////
//
//  This is the main function with 5 Menu .
//
//////////////////////////////////////////////////////////

int main()
{
    cout<<"\n\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t**                                                         **\n";
   cout<<"\t\t\t**          CUSTOMIZED STANDARD TEMPLATE LIBAERY           **\n";
   cout<<"\t\t\t**                                                         **\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t*************************************************************\n";
    Authentication();
    //This variable are for int type
	int iChoice=1;
    int iValue=0,iChoic=1,iPos=0,iRet=0;
    int Avalue=0; //This is for Stack Array
    char cValue='\0',cRet='\0';//This variable are for char type
    float fValue=0.0,fRet=0.0;//This variable are for float type
    double dValue=0.00,dRet=0.00;////This variable are for double type
    int i=0;//For BST

    DoublyCL<int>Dobj;
    DoublyLL<int>Dobj1;
    SinglyCL<int>Sobj;
    SinglyLL<int>Sobj1;
    Stack<int>St;
    StackA<char>StA;
    Queue<float>Qu;
    BST<double>Bst;
    struct nodet<double> *Root = NULL; //Pointer of BST

    //This Variable are for char type

    

    while(iChoice!=0)
    {
        cout<<"\n";
        cout<<"\n\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t**                                                         **\n";
   cout<<"\t\t\t**                       MAIN MENU                         **\n";
   cout<<"\t\t\t**                                                         **\n";
   cout<<"\t\t\t*************************************************************\n";
   cout<<"\t\t\t*************************************************************\n";
        cout<<"Enter your Choice\n";
        cout<<"1 :Doubly Circular LinkList--{ int type  }\n";
        cout<<"2 :Doubly Linear LinkList----{ int type  }\n";
        cout<<"3 :Singly Circular LinkList--{ int type  }\n";
        cout<<"4 :Singly Linear LinkList----{ int type  }\n";
        cout<<"5 :Stack using LinkList------{ int type  }\n";
        cout<<"6 :Stack using Array---------{ char type   }\n";
        cout<<"7 :Queue using LinkList------{ float type  }\n";
        cout<<"8 :Binary Search Tree--------{ double type }\n";
        cout<<"0 :Exit\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
            
    while(iChoic!=0)
    {
        cout<<"\n";
        cout<<"Doubly Circular LinkList Menu\n";
        cout<<"Enter your choice\n";
        cout<<"1 :InsertFirst\n";
        cout<<"2 :InsertLast\n";
        cout<<"3 :Insert At Position\n";
        cout<<"4 :DeleteFirst\n";
        cout<<"5 :DeleteLast\n";
        cout<<"6 :Delete At Position\n";
        cout<<"7 :Display\n";
        cout<<"8 :Count\n";
        cout<<"9 :FirstOccurance\n";
        cout<<"10:LastOccurance\n";
        cout<<"11:ALLOccurance\n";
        cout<<"12:ReverseList\n";
        cout<<"0 :Back to main Menu\n";
        cin>>iChoic;

        switch(iChoic)
        {
            case 1:
            cout<<"Enter the number\n";
            cin>>iValue;
            Dobj.InsertFirst(iValue);
            break;

            case 2:
            cout<<"Enter the number\n";
            cin>>iValue;
            Dobj.InsertLast(iValue);
            break;

            case 3:
            cout<<"Enter the number\n";
            cin>>iValue;
            cout<<"Enter the Position\n";
            cin>>iPos;
            Dobj.InsertAtPos(iValue,iPos);
            break;

            case 4:
            Dobj.DeleteFirst();
            break;

            case 5:
            Dobj.DeleteLast();
            break;

            case 6:
            cout<<"Enter the Position\n";
            cin>>iPos;
            Dobj.DeleteAtPos(iPos);
            break;

            case 7:
            iRet=Dobj.Display();
            if(iRet==-1)
            {
                cout<<"List is empty\n";
            }
            break;

            case 8:
            cout<<"Length of the linked list is "<<Dobj.Count()<<"\n";
            break;

            case 9:
            cout<<"Enter the Element to find it first Occurance\n";
            cin>>iValue;
            iRet=Dobj.FirstOcc(iValue);
            if(iRet>0)
            {
                cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 10:
            cout<<"Enter the Element to find it last Occurance\n";
            cin>>iValue;
            iRet=Dobj.LastOcc(iValue);
            if(iRet>0)
            {
                cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 11:
            cout<<"Enter the Element to find its All Occurance\n";
            cin>>iValue;
            iRet=Dobj.AllOcc(iValue);
            if(iRet>0)
            {
                cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 12:
            iRet=Dobj.ReverseList();
            if(iRet==-1)
            {
                cout<<"List is Empty\n";
            }
            else
            {
                cout<<"List Reversed Succesfully\n";
            }
            break;



            case 0:
            Dobj.~DoublyCL();
            break;

            default:
            cout<<"wromg option\n";
            break;
           }
        }
            iChoic=1;
            break;  //This is break for Case 1

            case 2:
            while(iChoic!=0)
    {
        cout<<"\n";
        cout<<"Doubly Linear LinkList Menu\n";
        cout<<"Enter your choice\n";
        cout<<"1 :InsertFirst\n";
        cout<<"2 :InsertLast\n";
        cout<<"3 :Insert At Position\n";
        cout<<"4 :DeleteFirst\n";
        cout<<"5 :DeleteLast\n";
        cout<<"6 :Delete At Position\n";
        cout<<"7 :Display\n";
        cout<<"8 :Count\n";
        cout<<"9 :FirstOccurance\n";
        cout<<"10:LastOccurance\n";
        cout<<"11:ALLOccurance\n";
        cout<<"12:ReverseList\n";
        cout<<"0 :Back to main Menu\n";
        cin>>iChoic;

        switch(iChoic)
        {
            case 1:
            cout<<"Enter the number\n";
            cin>>iValue;
            Dobj1.InsertFirst(iValue);
            break;

            case 2:
            cout<<"Enter the number\n";
            cin>>iValue;
            Dobj1.InsertLast(iValue);
            break;

            case 3:
            cout<<"Enter the number\n";
            cin>>iValue;
            cout<<"Enter the Position\n";
            cin>>iPos;
            Dobj1.InsertAtPos(iValue,iPos);
            break;

            case 4:
            Dobj1.DeleteFirst();
            break;

            case 5:
            Dobj1.DeleteLast();
            break;

            case 6:
            cout<<"Enter the Position\n";
            cin>>iPos;
            Dobj1.DeleteAtPos(iPos);
            break;

            case 7:
            iRet=Dobj1.Display();
            if(iRet==-1)
            {
                cout<<"List is empty\n";
            }
            break;

            case 8:
            cout<<"Length of the linked list is "<<Dobj1.Count()<<"\n";
            break;

            case 9:
            cout<<"Enter the Element to find it first Occurance\n";
            cin>>iValue;
            iRet=Dobj1.FirstOcc(iValue);
            if(iRet>0)
            {
                cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;


            case 10:
            cout<<"Enter the Element to find it last Occurance\n";
            cin>>iValue;
            iRet=Dobj1.LastOcc(iValue);
            if(iRet>0)
            {
                cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;



            case 11:
            cout<<"Enter the Element to find its All Occurance\n";
            cin>>iValue;
            iRet=Dobj1.AllOcc(iValue);
            if(iRet>0)
            {
                cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 12:
            iRet=Dobj1.ReverseList();
            if(iRet==-1)
            {
                cout<<"List is Empty\n";
            }
            else
            {
                cout<<"List Reversed Succesfully\n";
            }
            break;


            case 0:
            Dobj1.~DoublyLL();
            break;

            default:
            cout<<"wrong option\n";
            break;
           }
        }
            iChoic=1;
            break;  //This is break for Case 2


            case 3:
            while(iChoic!=0)
    {
        cout<<"\n";
        cout<<"Singly Circular LinkList Menu\n";
        cout<<"Enter your choice\n";
        cout<<"1 :InsertFirst\n";
        cout<<"2 :InsertLast\n";
        cout<<"3 :Insert At Position\n";
        cout<<"4 :DeleteFirst\n";
        cout<<"5 :DeleteLast\n";
        cout<<"6 :Delete At Position\n";
        cout<<"7 :Display\n";
        cout<<"8 :Count\n";
        cout<<"9 :FirstOccurance\n";
        cout<<"10:LastOccurance\n";
        cout<<"11:ALLOccurance\n";
        cout<<"12:ReverseList\n";
        cout<<"0 :Back to main Menu\n";
        cin>>iChoic;

        switch(iChoic)
        {
            case 1:
            cout<<"Enter the number\n";
            cin>>iValue;
            Sobj.InsertFirst(iValue);
            break;

            case 2:
            cout<<"Enter the number\n";
            cin>>iValue;
            Sobj.InsertLast(iValue);
            break;

            case 3:
            cout<<"Enter the number\n";
            cin>>iValue;
            cout<<"Enter the Position\n";
            cin>>iPos;
            Sobj.InsertAtPos(iValue,iPos);
            break;

            case 4:
            Sobj.DeleteFirst();
            break;

            case 5:
            Sobj.DeleteLast();
            break;

            case 6:
            cout<<"Enter the Position\n";
            cin>>iPos;
            Sobj.DeleteAtPos(iPos);
            break;

            case 7:
            iRet=Sobj.Display();
            if(iRet==-1)
            {
                cout<<"List is empty\n";
            }
            break;

            case 8:
            cout<<"Length of the linked list is "<<Sobj.Count()<<"\n";
            break;

            case 9:
            cout<<"Enter the Element to find it first Occurance\n";
            cin>>iValue;
            iRet=Sobj.FirstOcc(iValue);
            if(iRet>0)
            {
                cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;


            case 10:
            cout<<"Enter the Element to find it last Occurance\n";
            cin>>iValue;
            iRet=Sobj.LastOcc(iValue);
            if(iRet>0)
            {
                cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;


            case 11:
            cout<<"Enter the Element to find its All Occurance\n";
            cin>>iValue;
            iRet=Sobj.AllOcc(iValue);
            if(iRet>0)
            {
                cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 12:
            iRet=Sobj.ReverseList();
            if(iRet==-1)
            {
                cout<<"List is Empty\n";
            }
            else
            {
                cout<<"List Reversed Succesfully\n";
            }
            break;


            case 0:
            Sobj.~SinglyCL();
            break;

            default:
            cout<<"wromg option\n";
            break;
           }
        }
            iChoic=1;
            break;  //This is break for Case 3

            case 4:
             while(iChoic!=0)
    {
        cout<<"\n";
        cout<<"Singly Linear LinkList Menu\n";
        cout<<"Enter your choice\n";
        cout<<"1 :InsertFirst\n";
        cout<<"2 :InsertLast\n";
        cout<<"3 :Insert At Position\n";
        cout<<"4 :DeleteFirst\n";
        cout<<"5 :DeleteLast\n";
        cout<<"6 :Delete At Position\n";
        cout<<"7 :Display\n";
        cout<<"8 :Count\n";
        cout<<"9 :FirstOccurance\n";
        cout<<"10:LastOccurance\n";
        cout<<"11:ALLOccurance\n";
        cout<<"12:ReverseList\n";
        cout<<"0 :Back to main Menu\n";
        cin>>iChoic;

        switch(iChoic)
        {
            case 1:
            cout<<"Enter the number\n";
            cin>>iValue;
            Sobj1.InsertFirst(iValue);
            break;

            case 2:
            cout<<"Enter the number\n";
            cin>>iValue;
            Sobj1.InsertLast(iValue);
            break;

            case 3:
            cout<<"Enter the number\n";
            cin>>iValue;
            cout<<"Enter the Position\n";
            cin>>iPos;
            Sobj1.InsertAtPos(iValue,iPos);
            break;

            case 4:
            Sobj1.DeleteFirst();
            break;

            case 5:
            Sobj1.DeleteLast();
            break;

            case 6:
            cout<<"Enter the Position\n";
            cin>>iPos;
            Sobj1.DeleteAtPos(iPos);
            break;

            case 7:
            iRet=Sobj1.Display();
            if(iRet==-1)
            {
                cout<<"List is empty\n";
            }
            break;

            case 8:
            cout<<"Length of the linked list is "<<Sobj1.Count()<<"\n";
            break;

            case 9:
            cout<<"Enter the Element to find it first Occurance\n";
            cin>>iValue;
            iRet=Sobj1.FirstOcc(iValue);
            if(iRet>0)
            {
                cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;


            case 10:
            cout<<"Enter the Element to find it last Occurance\n";
            cin>>iValue;
            iRet=Sobj1.LastOcc(iValue);
            if(iRet>0)
            {
                cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;


            case 11:
            cout<<"Enter the Element to find its All Occurance\n";
            cin>>iValue;
            iRet=Sobj1.AllOcc(iValue);
            if(iRet>0)
            {
                cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
            }
            else if(iRet==-1)
            {
                cout<<"Empty list\n";
            }
            else
            {
                cout<<"Element Not Present in the List\n";
            }
            break;

            case 12:
            iRet=Sobj1.ReverseList();
            if(iRet==-1)
            {
                cout<<"List is Empty\n";
            }
            else
            {
                cout<<"List Reversed Succesfully\n";
            }
            break;
            

            case 0:
            Sobj1.~SinglyLL();
            break;

            default:
            cout<<"wromg option\n";
            break;
           }
        }
            iChoic=1;
            break;  //This is break for Case 4

            case 5:
            while(iChoic!=0)
            {
                cout<<"\n";
                cout<<"Stack using LinkList Menu\n";
                cout<<"1 : Push the element\n";
                cout<<"2 : Pop the element\n";
                cout<<"3 : Display the elements\n";
                cout<<"4 : Count number of elements\n";
                cout<<"5 : Peek the element\n";
                cout<<"6 : FirstOccurance\n";
                cout<<"7 : LastOccurance\n";
                cout<<"8 : ALLOccurance\n";
                cout<<"9 : ReverseList\n";
                cout<<"0 : Back to main Menu\n";
                cin>>iChoic;

                switch(iChoic)
                {
                    case 1:
                    cout<<"Enter the elements to Push\n";
                    cin>>iValue;
                    St.Push(iValue);
                    break;

                    case 2:
                    iRet=St.Pop();
                    cout<<"Poped element is : "<<iRet<<"\n";
                    break;

                    case 3:
                    iRet=St.Display();
                    if(iRet==-1)
                    {
                       cout<<"List is empty\n";
                    }
                    break;

                    case 4:
                    iRet=St.Count();
                    cout<<"Number of elements in stack are : "<<iRet<<"\n";
                    break;

                    case 5:
                    iRet=St.Peek();
                    cout<<"Value of top element is : "<<iRet<<"\n";
                    break;

                    case 6:
                    cout<<"Enter the Element to find it first Occurance\n";
                    cin>>iValue;
                    iRet=St.FirstOcc(iValue);
                    if(iRet>0)
                    {
                         cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                        cout<<"Empty list\n";
                    }
                    else
                    {
                         cout<<"Element Not Present in the List\n";
                    }
                    break;

                    case 7:
                    cout<<"Enter the Element to find it last Occurance\n";
                    cin>>iValue;
                    iRet=St.LastOcc(iValue);
                    if(iRet>0)
                    {
                       cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                      cout<<"Empty list\n";
                    }
                    else
                    {
                       cout<<"Element Not Present in the List\n";
                    }
                    break;


                    case 8:
                    cout<<"Enter the Element to find its All Occurance\n";
                    cin>>iValue;
                    iRet=St.AllOcc(iValue);
                    if(iRet>0)
                    {
                         cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                        cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;


                    case 9:
                    iRet=St.ReverseList();
                    if(iRet==-1)
                    {
                        cout<<"List is Empty\n";
                    }
                    else
                    {
                        cout<<"List Reversed Succesfully\n";
                    }
                    break;
            

                    case 0:
                    St.~Stack();
                    break;

                    default:
                    cout<<"Wrong option\n";
                    break;
                }
            }
            iChoic=1;
            break;//This is break for Case 5

            case 6:
                
                cout<<"Enter The Size of the Array\n";
                cin>>Avalue;
                StA.ArraySize(Avalue);
            while(iChoic!=0)
            {
                cout<<"\n";
                cout<<"Stack using Array Menu\n";
                cout<<"1 : Push Elements in Stack\n";
                cout<<"2 : Pop Elements in stack\n";
                cout<<"3 : Peek Elements in Stack\n";
                cout<<"4 : Display all Elements from stack\n";
                cout<<"5 : FirstOccurance\n";
                cout<<"6 : LastOccurance\n";
                cout<<"7 : ALLOccurance\n";
                cout<<"0 :Exit\n";
                cin>>iChoic;

                switch(iChoic)
                {
                    case 1:
                    cout<<"Enter the Element\n";
                    cin>>cValue;
                    StA.Push(cValue);
                    break;

                    case 2:
                    cRet=StA.Pop();
                    cout<<"The Poped Elements is :"<<cRet<<"\n";
                    break;

                    case 3:
                    cRet=StA.Peek();
                    cout<<"The Topmost Element in the Stack is:"<<cRet<<"\n";
                    break;

                    case 4:
                    iRet=StA.Display();
                    if(iRet==-1)
                    {
                        cout<<"List is empty\n";
                    }
                    break;

                    case 5:
                    cout<<"Enter the Element to find it first Occurance\n";
                    cin>>cValue;
                    iRet=StA.FirstOcc(cValue);
                    if(iRet>0)
                    {
                       cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                       cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;

                    case 6:
                    cout<<"Enter the Element to find it last Occurance\n";
                    cin>>cValue;
                    iRet=StA.LastOcc(cValue);
                    if(iRet>0)
                    {
                        cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                        cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;

                    case 7:
                    cout<<"Enter the Element to find its All Occurance\n";
                    cin>>cValue;
                    iRet=StA.AllOcc(cValue);
                    if(iRet>0)
                    {
                        cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                        cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;
            

                    case 0:
                    StA.~StackA();
                    //delete obj;   //Do this only when object is created dynamicaly
                    break;

                    default:
                    cout<<"Wrong option\n";
                    break;
                }
            }
            iChoic=1;
            break;//This is break for Case 6

            case 7:
            while(iChoic!=0)
            {
                cout<<"\n";
                cout<<"Queue LinkList Menu\n";
                cout<<"1 : Push Element\n";
                cout<<"2 : Pop Element\n";
                cout<<"3 : Count Element\n";
                cout<<"4 : Display\n";
                cout<<"5 : FirstOccurance\n";
                cout<<"6 : LastOccurance\n";
                cout<<"7 : ALLOccurance\n";
                cout<<"8 : ReverseList\n";
                cout<<"0 : Exit\n";
                cin>>iChoic;

                switch(iChoic)
                {
                    case 1:
                    cout<<"Enter The Element\n";
                    cin>>fValue;
                    Qu.Push(fValue);
                    break;

                    case 2:
                    fRet=Qu.Pop();
                    cout<<"The Poped Element is :"<<fRet<<"\n";
                    break;

                    case 3:
                    iRet=Qu.Count();
                    cout<<"Number of Elements in the Queue is :"<<iRet<<"\n";
                    break;

                    case 4:
                    iRet=Qu.Display();
                    if(iRet==-1)
                    {
                        cout<<"List is empty\n";
                    }
                    break;

                    case 5:
                    cout<<"Enter the Element to find it first Occurance\n";
                    cin>>fValue;
                    iRet=Qu.FirstOcc(fValue);
                    if(iRet>0)
                    {
                       cout<<"The FirstOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                       cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;

                    case 6:
                    cout<<"Enter the Element to find it last Occurance\n";
                    cin>>fValue;
                    iRet=Qu.LastOcc(fValue);
                    if(iRet>0)
                    {
                        cout<<"The LastOccurance is at Position :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                       cout<<"Empty list\n";
                    }
                    else
                    {
                       cout<<"Element Not Present in the List\n";
                    }
                    break;


                    case 7:
                    cout<<"Enter the Element to find its All Occurance\n";
                    cin>>fValue;
                    iRet=Qu.AllOcc(fValue);
                    if(iRet>0)
                    {
                         cout<<"The All Occurance of the Given number is :"<<iRet<<"\n";
                    }
                    else if(iRet==-1)
                    {
                         cout<<"Empty list\n";
                    }
                    else
                    {
                        cout<<"Element Not Present in the List\n";
                    }
                    break;

                    case 8:
                    iRet=Qu.ReverseList();
                    if(iRet==-1)
                    {
                        cout<<"List is Empty\n";
                    }
                    else
                    {
                        cout<<"List Reversed Succesfully\n";
                    }
                    break;
            

                    case 0:
                    Qu.~Queue();
                    break;

                    default:
                    cout<<"Wrong option\n";
                    break;
                }

            }
            iChoic=1;
            break;//This is break for Case 7

            
            case 8:
            while(iChoic!=0)
            {
                cout<<"\n";
                cout<<"Binary Search Tree Menu\n";
                cout<<"Enter your choice\n";
                cout<<"1  : InsertNode\n";
                cout<<"2  : Inorder\n";
                cout<<"3  : Preorder\n";
                cout<<"4  : Postorder\n";
                cout<<"5  : Count\n";
                cout<<"6  : NormalCount\n";
                cout<<"7  : CountParents\n";
                cout<<"8  : CountLeaf\n";
                cout<<"9  : Search using Recursion\n";
                cout<<"10 : Normal Search\n";
                cout<<"0  : Exit\n";
                cin>>iChoic;

                switch(iChoic)
                {
                    case 1:
                    cout<<"Enter The Element\n";
                    cin>>dValue;
                    Bst.InsertNode(&Root,dValue);
                    break;

                    case 2:
                    cout<<"Inorder traversal\n";
                    Bst.Inorder(Root);
                    break;

                    case 3:
                    cout<<"Preorder traversal\n";
                    Bst.Preorder(Root);
                    break;

                    case 4:
                    cout<<"Postorder traversal\n";
                    Bst.Postorder(Root);
                    break;

                    case 5:
                    i=0;
                    Bst.Count(Root,&i);
                    cout<<"Numbers of Elements in BST is :"<<i<<"\n";
                    break;

                    case 6:
                    dRet=Bst.NormalCount();
                    cout<<"Numbers of Elements in BST is :"<<dRet<<"\n";
                    break;

                    case 7:
                    i=0;
                    Bst.CountParents(Root,&i);
                    cout<<"Numbers of Parents nodes are "<<i<<"\n";
                    break;

                    case 8:
                    i = 0;
                    Bst.CountLeaf(Root,&i);
                    cout<<"Numbers of Leaf nodes are "<<i<<"\n";
                    break;


                    case 9:
                    cout<<"Enter the number to search\n";
                    cin>>dValue;
                    iRet=Bst.SearchRecursion(Root,dValue);
                    if(iRet==true)
                    {
                        cout<<dValue<<" is Present in BST\n";
                    }
                    else
                    {
                        cout<<dValue<<" is Not Present in BST\n";
                    }   
                    break;

                    
                    case 10:
                    cout<<"Enter the number to search\n";
                    cin>>dValue;
                    iRet=Bst.SearchNormal(dValue);
                    if(iRet==true)
                    {
                        cout<<dValue<<" is Present in BST\n";
                    }
                    else
                    {
                        cout<<dValue<<" is Not Present in BST\n";
                    }   
                    break;


                    case 0:
                    Bst.~BST();
                    break;

                    default:
                    cout<<"wrong input\n";
                    break;
                }
            }
            iChoic=1;
            break;//This is break for Case 8

            case 0:
            cout<<"\n\n";
   cout<<"\t\t\t**************************************************************\n";
   cout<<"\t\t\t**************************************************************\n";
   cout<<"\t\t\t**                                                          **\n";
   cout<<"\t\t\t** THANK-YOU FOR USING CUSTOMIZED STANDARD TEMPLATE LIBAERY **\n";
   cout<<"\t\t\t**                                                          **\n";
   cout<<"\t\t\t**************************************************************\n";
   cout<<"\t\t\t**************************************************************\n";
            break;

            default:
            cout<<"Wrong option\n";
            break;
        }
    }
	return 0;
}