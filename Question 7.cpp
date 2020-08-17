#include <iostream>
#include <fstream>
using namespace std;

int Avg(int A[])
{
    int S=0;
    for(int i=0;i<5;i++)
    {
        S+=A[i];
    }
    S/=5;
    return S;
}

int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    ifstream inp;
    ofstream out;
    string S;
    cout << "please give me the name of the file\n";
    cin >> S;
    inp.open(S);
    out.open("outputQ4.txt");
    while (!inp.is_open())
    {
        cout << "The file is not found.Try Again.\n";
        cin >> S;
        inp.open(S);
    }
    int A[5];
    for(int i=0;i<5;i++)
        inp>>A[i];
    int Average=Avg(A);
    cout<<"The average of the integers is "<<Average<<endl;
    int N=factorial(Average);
    cout<<"The factorial of the average is "<<N<<endl;
    cout<<"Check the output file\n";
    out<<"The factorial of ";
    out<<Average;
    out<<" is:\t";
    out<<N;
    out.close();
    return 0;
}
