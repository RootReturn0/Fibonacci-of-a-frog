/*************************************************

Author:Feifan Wang

Date:04-07-2019

Description: The answer of how many methods the frog
             can use when it jumps to n steps, which
             can jump up one or two steps each time.            
**************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * @brief 2 * 2 matrix 
 * ⌈x1 x2⌉
 * ⌊y1 y2⌋
 */
struct Matrix
{
    unsigned long long x1;
    unsigned long long x2;
    unsigned long long y1;
    unsigned long long y2;

    Matrix(){}
    Matrix(unsigned long long a,unsigned long long b,unsigned long long c, unsigned long long d)
    {
        x1=a;
        x2=b;
        y1=c;
        y2=d;
    }
};

/**
 * @brief matrix multiplication
 * @param a @see Matrix
 * @param b @see Matrix
 */
Matrix mul(const Matrix &a, const Matrix &b)
{
    Matrix re;
    re.x1 = a.x1 * b.x1 + a.x2 * b.y1;
    re.x2 = a.x1 * b.x2 + a.x2 * b.y2;
    re.y1 = a.y1 * b.x1 + a.y2 * b.y1;
    re.y2 = a.y1 * b.x2 + a.y2 * b.y2;

    return re;
}

/** 
 * @brief matrix power
 * @param a @see Matrix
 * @param n //power
 */
Matrix pow(Matrix a, int n)
{
    Matrix re(1,1,1,1);
    while(n)
    {
        if(n&1)
            re=mul(re,a);//re=re*a
        a=mul(a,a);//a=a*a
        n>>=1;
    }

    return re;
}

/**
 * Fibonacci number
 * @brief Find the Fibonacci number of some index
 * @param index (index>=2)
 */
void Fibonacci(int index)
{
    Matrix init(1,1,1,0);
    Matrix fin=pow(init, index-1);//index starts from 0 in Fibonacci sequence
    cout<<fin.x1<<endl;
}

int main()
{
    int n;
    cout<<"Please enter the number of steps the frog need to jump up: ";
    cin >> n;
    cout<<"The number of methods the frog can use is: ";
    if (n ==0)//the frog can not jump up steps if there are no steps
        cout << n << endl;
    else
    {
        Fibonacci(n);
    }

    return 0;
}