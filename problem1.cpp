#include<iostream>
#include <iomanip>
#include<string>
#include<cstdlib> // must be included for linkedlist

using namespace std;
struct node
{
    int data;
    node * next;
};
class list
{
    private:
        node *head;
        
    public:
        list()
        {
            head = nullptr;
        }
        void createNode(int value) // this adds at end
        {
            node* temp = new node;
            temp->data = value;
            temp->next = nullptr;

            node * curr;
            node * prev;
            curr = head;

            while(head != nullptr)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = temp;
            temp->next = nullptr;
            
            

        }
        void addFront(int value)
        {
            node * temp = new node;
            temp->data= value;
            temp->next= head;// "i want what ever temp->next to point to where head is pointing to"
            head = temp;
        
        }
        void insertAtLocation(int value, int position)
        {
            //create 3 node objs
            node*cursor = new node;
            cursor = head;//to traverse the list

            node*temp = new node;
            temp->data = value;
            
            node * test = new node;
            //use this to update the cursor position
            for (int a = 0; a < position; a++)
            {
                test = cursor;// i want the cursor to point to where every test points to
                cursor = cursor->next;
            }
            //im now at my position
            test->next=temp;
            temp->next = cursor;
        }

        void displayList()
        {
            node*cursor= new node;
            cursor = head; //starting point
            while (cursor != nullptr)
            {
                cout <<cursor->data<< " ";
                cursor = cursor->next;
            }
            cout<<endl;
        }
        int findAverage()
        {
            double ave;
            int counter=0;
            node * cursor = new node;
            cursor = head; // starting point
            while(cursor != nullptr)
            {
                counter++;
                ave += cursor->data;
                cursor = cursor->next;
            }
            ave = ave/counter;
            return ave;

        }
        void whoIsAboveAverage(int ave)
        {
            node * cursor = new node;
            cursor = head; // starting point

            int averageCounter = 0;
            cout<< "List of numbers above average: ";
            while(cursor != nullptr)
            {
                if(ave < cursor->data)
                {
                    averageCounter++;
                    cout << cursor->data << " ";
                }
                cursor= cursor ->next;
            }
            //print out people
            cout << "There are "<< averageCounter<< " people whose age are above average age"<<endl;



        }

};

int main()
{
    //Given array
    int Age[5] = {19,21,17,22,33}; //construct a linked list with this
    cout<<"size of array: "<<5<<endl;

    list LinkedList;

    for(int a = 0; a < 5;a++)
    {
        LinkedList.createNode(Age[a]);
        
    }
    LinkedList.displayList();
    cout <<endl;
    LinkedList.createNode(26);
    cout << "adding 26 to the end"<<endl;
    LinkedList.displayList();
    LinkedList.addFront(10);
    cout <<"adding 10 to the front"<<endl;
    LinkedList.displayList();
    LinkedList.insertAtLocation(20,3);
    cout << "adding 20 to the index position 3"<<endl;
    LinkedList.displayList();
    cout << endl;

    //average
    int ave = LinkedList.findAverage();
    cout << "The average age is "<<ave <<endl;

    LinkedList.whoIsAboveAverage(ave);




    return(0);
}