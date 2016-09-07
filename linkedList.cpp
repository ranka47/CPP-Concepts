#include "linkedList.h"


int main()
{
    linkedList <int>l;
    while(1)
    {
        int option;
        cout<<"Press 1: addAtHead"<<endl;
        cout<<"Press 2: insertAtSpecificLocation"<<endl;
        cout<<"Press 3: addAtTail"<<endl;
        cout<<"Press 4: deleteAtSpecificLocation"<<endl;
        cout<<"Press 5: searchAndDelete"<<endl;
        cout<<"Press 6: display"<<endl;
        cout<<"Press 7: exit"<<endl;
        cin>>option;
        switch(option)    
        {
            case 1:
            {
                int temp;
                cout<<"Enter the element to be inserted. ";
                cin>>temp;
                l.addHead(temp);
                break;
            }
            case 2:
            {
                int temp;
                int location;
                cout<<"Enter the element to be inserted. ";
                cin>>temp;
                cout<<"At what location? ";
                cin>>location;
                l.insertAt(location, temp);
                break;
            }
            case 3:
            {
                int temp;
                cout<<"Enter the element to be inserted. ";
                cin>>temp;
                l.addTail(temp);
                break;
            }
            case 4:
            {
                int location;
                cout<<"Enter the location to be deleted. ";
                cin>>location;
                l.deleteAt(location);
                break;
            }
            case 5:
            {
                int temp;
                cout<<"Enter the element to be deleted. ";
                cin>>temp;
                l.del(temp);
                break;
            }
            case 6:
            {
                l.display();
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            cout<<"Invalid option."<<endl;
        }
    }
    return 0;
}

