#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;

struct Queue
{
    // Initialize front and rear
    char rear, front;

    // Circular Queue
    int size;
    char *arr;

    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new char[s];
    }

    void enQueue(char value);
    int deQueue();
    void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(char value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        cout<<"\nQueue is Full";
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
    cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i];
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i];

        for (int i = 0; i <= rear; i++)
            cout<<arr[i];
    }
}


string UtoL(string X)
{
    for(int i=0;i<X.length();i++)
    {
        if(X[i] == ' ')
            continue;
        if(X[i]<='z' && X[i]>='a')
            X[i]=X[i]-32;
        else
            X[i]+=32;
    }
    return X;
}

int isPalindrome(string str)
{
    int len = str.length();

    // Allocating the memory for the stack
    Queue q(len);

    // Finding the mid
    int i, mid = len / 2;

    for (i = 0; i < mid; i++) {
        q.enQueue(str[i]);
    }

    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (len % 2 != 0) {
        i++;
    }

    // While not the end of the string
    while (str[i] != '\0') {
        char element = q.deQueue();

        // If the characters differ then the
        // given string is not a palindrome
        if (element != str[i])
            return 0;
        i++;
    }

    return 1;
}

int main()
{
    string X;
    cout<<"Give me a text:\t";
    getline(cin,X);
    X=UtoL(X);
    cout<<X;
    Queue q(X.length());
    for(int i=0;i<X.length();i++)
    {
        q.enQueue(X[i]);
    }
    q.displayQueue();
    cout<<"\n";
    if (isPalindrome(X)) {
        cout<<"YES, palindrome\n";
    }
    else {
       cout<<"NO, Not palindrome\n";
    }
}
