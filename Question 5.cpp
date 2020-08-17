#include <iostream>
#include <fstream>
using namespace std;

int search(int X,int A[])
{
    for(int i=0;i<5;i++)
    {
        if(X==A[i])
            return i;
    }
    return -1;
}

int main()
{
    ifstream inp;
    ofstream opt;
    int A[10];
    string S;
    cout << "please give me the name of the file\n";
    cin >> S;
    inp.open(S);
    opt.open("outputQ2.txt");
    while (!inp.is_open())
    {
        cout << "The file is not found.Try Again.\n";
        cin >> S;
        inp.open(S);
    }
    for(int i=0;i<5;i++)
        inp>>A[i];

    inp.close();
    int X;
    int y;
    cout<<"Put the integer you want to search it\n";
    cin>>X;
    y=search(X,A);
    if(y==-1)
        cout<<"The word is not found in the text!\n";
    else
       {
           cout<<"The index of the entered integer is:"<<y<<endl;
           cout<<"Check the file called output.txt\n";
           opt<<y;
           opt.close();
       }

    return 0;
}

