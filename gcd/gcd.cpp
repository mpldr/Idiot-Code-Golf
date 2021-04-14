/*
Problem: Find the greatest common divisor of two numbers.

Solution: Euclidean algorithm except modulos are computed using trig functions!
*/

#include <bits/stdc++.h>
int gcd(int a,int b){while(a^b)std::swap(b,a=b*(M_PI/2-atan(cos(M_PI*a/b)/sin(M_PI*a/b)))/M_PI+1e-9);return a;}
int main(){std::cout<<gcd(126,84);}
