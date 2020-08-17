#include <iostream>
#include <fstream>
using namespace std;

void Average(int X[])
{
    ofstream out;
    out.open("outputQ3.txt");
    int A;
    for(int i=0;i<3;i++)
    {
        A=(X[i]/3);
        out<<"Employee";
        out<<(i+1);
        out<<":\t Average of salary is:\t";
        out<<A;
        out<<"\n";
        A=0;
    }
    out.close();
    return;
}

int main()
{
    int A[3][3];
    cout<<"Please give me the salaries of employees in each month\n";
    for(int i=0;i<3;i++)
    {
        cout<<"Employee "<<(i+1)<<": ";
        for(int j=0;j<3;j++)
        {
            cout<<"Month "<<(j+1)<<":\n";
            cin>>A[i][j];
        }
    }
    int X[3];
    int S;
    for(int i=0;i<3;i++)
    {
        S=0;
        for(int j=0;j<3;j++)
            S+=A[i][j];
        cout<<"Employee "<<(i+1)<<"Summation of salary is:"<<S<<endl;
        X[i]=S;
    }
    Average(X);
    cout<<"Check the output file.\n";

    return 0;

}
