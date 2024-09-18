#include"header.h"

int main()
{
    int choice=0;
     matrix array;
    while(choice!=2)
    {
        cout<<"Do you want to play a game 1-Yes 2-No"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            array.game();
            break;
            case 2 : 
            cout<<"BYE :)"<<endl;
            choice=2;
            break;
            default:
            cout<<"INVALID INPUT"<<endl;
        }
    }
    return 0;
}