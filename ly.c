/*
Problem: Check if a year is a leap year.

Solution: See code. Compile with gcc ly.c -o ly -lm
*/

#include <stdio.h>
#include <math.h>
#define a(_) sin(_)
#define b(_) sin(a(_))
#define c(_) sin(b(_))
#define d(_) sin(c(_))
#define e(_) sin(d(_))
#define f(_) sin(e(_))
#define g(_) sin(f(_))
#define h(_) sin(g(_))
#define i(_) sin(h(_))
#define j(_) sin(i(_))
#define k(_) sin(j(_))
#define l(_) sin(k(_))
#define m(_) sin(l(_))
#define n(_) sin(m(_))
#define o(_) sin(n(_))
#define p(_) sin(o(_))
#define q(_) sin(p(_))
#define r(_) sin(q(_))
#define s(_) sin(r(_))
#define t(_) sin(s(_))
#define u(_) sin(t(_))
#define v(_) sin(u(_))
#define w(_) sin(v(_))
#define x(_) sin(w(_))
#define y(_) sin(x(_))
#define z(_) sin(y(_))
//self-documenting code
#define magic(_) pow(t(h(e(m(a(i(n(t(r(i(c(k(t(h(a(t(t(h(i(s(c(o(d(e(i(s(e(x(p(l(o(i(t(i(n(g(i(s(t(h(e(f(a(c(t(t(h(a(t(n(e(s(t(i(n(g(s(i(n(e(i(n(s(i(d(e(o(f(i(t(s(e(l(f(t(h(o(u(s(a(n(d(s(o(f(t(i(m(e(s(p(r(o(d(u(c(e(s(a(c(u(r(v(e(s(i(m(i(l(a(r(t(o(a(s(q(u(a(r(e(w(a(v(e(w(e(c(a(n(t(h(e(n(s(q(u(a(r(e(t(h(i(s(t(o(g(e(t(a(c(u(r(v(e(t(h(a(t(i(s(z(e(r(o(i(n(a(f(e(w(l(o(c(a(t(i(o(n(s(a(n(d(o(n(e(e(v(e(r(y(w(h(e(r(e(e(l(s(e(b(y(c(h(o(o(s(i(n(g(s(p(e(c(i(f(i(c(i(n(p(u(t(p(a(r(a(m(e(t(e(r(s(w(e(c(a(n(m(a(k(e(c(u(r(v(e(s(t(h(a(t(a(r(e(z(e(r(o(a(t(o(n(e(h(u(n(d(r(e(d(t(w(o(h(u(n(d(r(e(d(a(n(d(t(h(r(e(e(h(u(n(d(r(e(d(a(n(d(a(d(d(t(h(e(m(t(o(g(e(t(h(e(r(t(o(g(e(t(a(c(u(r(v(e(t(h(a(t(h(a(s(d(i(p(s(a(t(t(h(e(s(e(l(o(c(a(t(i(o(n(s(c(o(m(b(i(n(e(d(w(i(t(h(a(s(i(m(p(l(e(s(i(n(e(c(u(r(v(e(t(h(a(t(s(p(e(a(k(s(e(v(e(r(y(f(o(u(r(w(e(c(a(n(c(r(e(a(t(e(a(c(u(r(v(e(t(h(a(t(i(s(l(a(r(g(e(w(h(e(n(t(h(e(i(n(p(u(t(i(s(a(m(u(l(t(i(p(l(e(o(f(f(o(u(r(o(r(o(n(e(h(u(n(d(r(e(d(t(w(o(h(u(n(d(r(e(d(o(r(t(h(r(e(e(h(u(n(d(r(e(d(a(n(d(s(m(a(l(l(o(t(h(e(r(w(i(s(e(w(h(a(t(a(m(a(g(i(c(a(l(s(o(l(u(t(i(o(n(t(o(t(h(e(l(e(a(p(y(e(a(r(p(r(o(b(l(e(m(_)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))),2)
#define is_leap_year(_) cos(M_PI*_/2)+magic(M_PI*(_+100)/400)+magic(M_PI*(_+200)/400)+magic(M_PI*(_+300)/400)>1.000969//Don't ask why it's 1.00969
int main(){for(int i=0;i<=2021;++i)printf("Is %d a leap year? %s\n",i,is_leap_year(i)?"Yes":"No");}//UNLEASH THE MAGIC!!!
