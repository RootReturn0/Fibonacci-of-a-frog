# A Frog Jumps Up Steps
There is a frog need to jump up steps. How many methods it can use if the frog can only jump up one or two steps each time.  
## Requirement
C++ compilation environment is required.
## How to use
### 1. Compile
```g++ answer.cpp```
### 2. Open
**Window**  

`./a.exe`  

**MacOS / Linux**   

`./a.out`
## How to solve the problem
**1. If the number of steps is 0**
  
    The frog can not jump up steps.  
    The number of methods is 0.
    
**2. If the number of steps is 1**

    The frog can only jump up a single step.  
    The number of methods is 1.
    
**3. Else**

    Assume the number of steps is n, the number of methods is F(n)
    
    If the frog jumps up one step the first time,
    
    then there are n-1 steps left, the number of methods is F(n-1)
    
    Else the frog jumps up two steps the first time
    
    then there are n-2 steps left, the number of methods is F(n-2)
    
    Hence, F(n)=F(n-1)+F(n+2), which is a Fibonacci sequence
**4. An alternative formula for the Fibonacci sequence**
    
    ⌈F(n+2)⌉=⌈1 1⌉·⌈F(n+1)⌉
    ⌊F(n+1)⌋ ⌊1 0⌋ ⌊ F(n) ⌋
    
    Assume A=⌈1 1⌉, F(0)=0, F(1)=1
             ⌊1 0⌋
             
    A^n = ⌈F(n)   F(n-1)⌉
          ⌊F(n-1) F(n-2)⌋ (n>=2)  
          
$$  
\\[  
\\left\\{ {\\begin{array}{*{20}c}  
1 & 2 \\\  
3 & 4 \\\  
\\end{array}} \\right\\} + \\left\\{ {\begin{array}{*{20}c}  
1 & 2 \\\  
3 & 4 \\\  
\\end{array}} \\right\\} = \\left\\{ {\\begin{array}{*{20}c}  
1 & 2 \\\  
3 & 4 \\\  
\\end{array}} \\right\\}  
\\]  
$$   

## Fast Exponentiation

> **For example**  
>  
> a ^ 11 = a ^ ( 2 ^ 0 + 2 ^ 1 + 2 ^ 3 ) = a ^ 8 \* a ^ 2 \* a ^ 1  
> *which only multiple 3 times rather than 11 times*  
>  
> 11 = 2³ × ***1*** + 2²× ***0*** + 2¹× ***1*** + 2º× ***1***  
>  
> 11 = bin( ***1011*** )  
>  
> Hence, if n=11  
>  
> when the final bit of n is 1, result*=a  
>  
> a*=a
>  
> drop the final bit  
>  
> loop the previous 3 steps until n==0
  
```c++
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
```

## Time Complexity  
**O(log(n))**

