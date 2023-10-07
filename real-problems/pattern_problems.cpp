#include <iostream>
using namespace std;

void printInvertedNumber(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printBinary(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printRay(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0)||((i==2)&&(j%4==0)))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printRohmbus(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 5; i >= 1; i--)
    {
        for (int z = 1; z <= i - 1; z++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printNumberPiramid(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int z = 1; z <= n-i; z++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j<< " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printPalindromicPiramid(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int z = 1; z <= n-i; z++)
        {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j<< " ";
        }
            for (int j = 2; j <= i; j++)
            {
            cout << j<< " ";
            }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}
void printMirrorPiramid(int n)
{
    cout << "-----------------------------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int z = 1; z <= n-i; z++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int z = 1; z <= n-i; z++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

int main()
{
    int n;
    cin >> n;
    printInvertedNumber(n);
    printBinary(n);
    printRay(n);
    printRohmbus(n);
    printNumberPiramid(n);
    printPalindromicPiramid(n);
    printMirrorPiramid(n);

    return 0;
}
