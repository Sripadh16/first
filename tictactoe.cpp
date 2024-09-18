#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> create()
{
    vector<vector<int>> arr(3, vector<int>(3, -1));
    return arr;
}


int checkfull(vector<vector<int>>arr)
{
    int flag=0;
    for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        if(arr[i][j] == -1){flag=1;}
    }
    }
 return flag;
}

int checkwin(vector<vector<int>> arr)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != -1) || 
            (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != -1)) {
            return arr[i][0]; 
        }
    }
    // Check diagonals
    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != -1) || 
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != -1)) {
        return arr[1][1];
    }
    return 0;
}

void display(vector<vector<int>> arr)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] == -1) {
                cout << "- ";
            } else if (arr[i][j] == 1) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
}

void game(vector<vector<int>>arr)
{
    string p1,p2;
    cout<<"Enter your name player 1"<<endl;
    cin>>p1;
    cout<<"Enter your name player 2"<<endl;
    cin>>p2;
    int k=1;
    int r,c;
    while(k!=3)
    {
        display(arr);
        switch(k){
            case 1 : cout<<p1<<"'s turn"<<endl;
                cout<<"enter the row and column index "<<endl;
                cin>>r>>c;

                while(r<0||r>=3||c<0||c>=3||arr[r][c]!=-1)
                {
                    {cout<<"INVALID INPUT ENTER AGAIN"<<endl;cin>>r>>c;}
                }

                arr[r][c]=1;
                k=2;
                break;

            case 2:cout<<p2<<"'s turn"<<endl;
                cout<<"enter the row and column index "<<endl;
                cin>>r>>c;

                while(r<0||r>=3||c<0||c>=3||arr[r][c]!=-1)
                {
                    {cout<<"INVALID INPUT ENTER AGAIN"<<endl;cin>>r>>c;}
                }

                arr[r][c]=0;
                k=1;
                break;
        }
        if (checkwin(arr)) 
            {
                display(arr); 
                if (checkwin(arr) == 1) {
                    cout << p1 << " wins!" << endl;
                } else {
                    cout << p2 << " wins!" << endl;
                }
                k=3;
                break;
            }

        if(checkfull(arr)==0)
        {
            display(arr); 
            cout << "It's a draw!" << endl;
            k=3;
            break;
        }
    }
}



int main()
{
    int choice=0;
    vector<vector<int>>arr;
    while(choice!=2)
    {
        cout<<"Do you want to play a game 1-Yes 2-No"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            arr=create();
            game(arr);
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
