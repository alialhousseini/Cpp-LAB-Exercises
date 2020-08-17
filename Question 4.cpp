#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int search(string X,string A[])
{
    int count1=X.length();
    int count2=0;
    int i=0;
    for(i=0;i<5;i++)
    {
       if(count1==A[i].length())
       {
           count2=0;
           for(int j=0;j<count1;j++)
                if(A[i][j]==X[j])
                    count2++;
       }
       if(count1==count2)
        return i;
    }
    return -1;
}

int main()
{
    ifstream inp;
    ofstream opt;
    string A[5];
    string S;
    cout << "please give me the name of the file\n";
    cin >> S;
    inp.open(S);
    opt.open("outputQ1.txt");
    while (!inp.is_open())
    {
        cout << "The file is not found.Try Again.\n";
        cin >> S;
        inp.open(S);
    }
    for(int i=0;i<5;i++)
        inp>>A[i];
    inp.close();
    string Z;
    int y;
    cout<<"Put the word you want to search it\n";
    cin>>Z;
    y=search(Z,A);
    if(y==-1)
        cout<<"The word is not found in the text!\n";
    else
       {
           cout<<"The index of the word is:"<<y<<endl;
           cout<<"Check the file called output.txt\n";
           opt<<y;
           opt.close();
       }

    return 0;
}

