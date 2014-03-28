---
layout: post
title: "SICP第一章“过程抽象”的一个练习--换零钱"
date: 2014-03-28 19:37:13 +0800
comments: false
categories: SICP lisp
---

最近一直想学习动态规划，无意中翻到了SICP这本书，以前读到的一个地方刚好涉及动态规划的记忆化技术。

SICP的第一章的第二节讲了递归过程和迭代过程的区别，举了Fibonacci数列的例子，虽然用递归的办法来定义函数非常直接（接近数学表达式），但是由于做了许多冗余的计算，效率特别低（时间复杂度为指数级）。一个改进的办法是从0开始迭代到要求的那一个数，这样效率大大提高而且空间复杂度大大降低，降到了O(n)级别。

举完Fibonacci数列之后书里提出了一个“换零钱”问题：你现在用面值1、5、10、25、50的硬币，给定一个金额，求出凑硬币的方式所有可能的个数。同样地，用递归写这个程序法很直接，但是效率很低。


换零钱程序-递归式：
```
(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
	((or (< amount 0) (= kinds-of-coins 0)) 0)
	(else (+ (cc amount
		     (- kinds-of-coins 1))
		 (cc (- amount (first-denomination kinds-of-coins))
		     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
	((= kinds-of-coins 2) 5)
	((= kinds-of-coins 3) 10)
	((= kinds-of-coins 4) 25)
	((= kinds-of-coins 5) 50)))
```		     


我把它翻译成了C++代码：
```
#include <cstdio>

int CountChange(int amount);
int cc(int amount, int kinds);
int FirstDenomination(int kinds);

int main()
{
    int amount;
    scanf("%d", &amount);
    printf("%d\n", CountChange(amount));
    return 0;
}

int CountChange(int amount)
{
    return cc(amount, 5);
}

int cc(int amount, int kinds)
{
    if (amount == 0)
	return 1;
    else if (amount < 0 || kinds == 0)
	return 0;
    else {
	return cc(amount, kinds-1) + \
	    cc(amount - FirstDenomination(kinds), kinds);
    }
}

int FirstDenomination(int kinds)
{
    if (kinds == 1) return 1;
    if (kinds == 2) return 5;
    if (kinds == 3) return 10;
    if (kinds == 4) return 25;
    else return 50;
}
```		 


通过声明一个数组储存状态从而避免过多的重复计算，这种办法叫做记忆化(Memoization):
```
#include <cstdio>
#include <cstring>
#include <cstdlib>

long long int CountChange(long long int amount);
long long int cc(long long int amount, long long int kinds);
long long int FirstDenomination(long long int kinds);

long long int m[10000][6]; 
/* Assume that the amount to be calculated is less than 10000; */

int main()
{
    long long int amount;
    memset(m, -1, sizeof(m));
    scanf("%lld", &amount);
    printf("%lld\n", CountChange(amount));
    return 0;
}

long long int CountChange(long long int amount)
{
    return cc(amount, 5);
}

long long int cc(long long int amount, long long int kinds)
{
    if (amount == 0)
	return 1;
    else if (amount < 0 || kinds == 0)
	return 0;
    else {
	if (m[amount][kinds] == -1)
	    m[amount][kinds] = 
		cc(amount, kinds-1) + cc(amount - FirstDenomination(kinds), kinds);
	/* debug */
	if (m[amount][kinds] < 0)
	    exit(1);
    }
    
    return m[amount][kinds];
}

long long int FirstDenomination(long long int kinds)
{
    if (kinds == 1) return 1;
    if (kinds == 2) return 5;
    if (kinds == 3) return 10;
    if (kinds == 4) return 25;
    else return 50;
}
```
加入记忆化以后的程序效率大大提高，递归式输入1000很久都不会出结果，记忆化输入1000是秒出结果。

EOF