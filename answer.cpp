/*************************************************

Author:Feifan Wang

Date:04-07-2019

Email: feifan_wang@qq.com

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
 * @deteil ⌈x1 x2⌉
 *         ⌊y1 y2⌋
 */
struct Matrix
{
    unsigned long long x1;
    unsigned long long x2;
    unsigned long long y1;
    unsigned long long y2;

    Matrix() {}
    Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
    {
        x1 = a;
        x2 = b;
        y1 = c;
        y2 = d;
    }
};

/**
 * @brief matrix multiplication
 * @param a @see Matrix
 * @param b @see Matrix
 * 
 * @return re @see Matrix
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
 * @example
 *  x^5=x*(x^4) 5=bin(101)
 *  x^9=x*(x^8) 9=bin(1001)
 * @param a @see Matrix
 * @param n //power
 * 
 * @return re @see Matrix
 */
Matrix pow(Matrix a, int n)
{
    n -= 1; //n power operates (n - 1) times
    Matrix re = a;
    while (n)
    {
        if (n & 1)
            re = mul(re, a); //re=re*a
        a = mul(a, a);       //a=a*a
        n >>= 1;
    }

    return re;
}

/**
 * @brief find the Fibonacci number of some index
 * @param index (index>=2)
 */
void Fibonacci(int index)
{
    Matrix init(1,1,1,0);
    Matrix re=pow(init, index);//the index starts from 0 in Fibonacci sequence
    cout<<re.x1<<endl;
}

int main()
{
    int n;
    cout<<"Please enter the number of steps the frog need to jump up: ";
    cin >> n;
    while(n<0)//n must be natural number
    {
        cout<<"Entered number is illegal! The number must be non-negative number!"<<endl;
        cout<<"Please enter the number of steps the frog need to jump up: ";
        cin >> n;
    }
    cout<<"The number of methods the frog can use is: ";
    if (n ==0)//the frog can not jump up steps if there are no steps
        cout << n << endl;
    else
    {
        Fibonacci(n);
    }
    
    return 0;
}

