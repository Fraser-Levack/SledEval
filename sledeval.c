#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "sledeval.h"

void skipwhite(const char **p)
{
    while(isspace(**p)) (*p)++;
}
int evalexpr(const char **);

int gettok(const char **p, int *vp)
{
    skipwhite(p);
    const char c = **p;
    if(isdigit(c))
    {
        char *p2;
        const int v = strtol(*p, &p2, 0);
        *p = p2;
        if(vp) *vp = v;
        return '1';
    }
    (*p)++;
    return c;
}

void ungettok(int, const char **p)
{
    (*p)--;
}

int evalpri(const char **p)
{
    int v;
    int op = gettok(p, &v);
    switch(op) {
        case '1': return v;
        case '-': return -evalpri(p);
        case '(':
            v = evalexpr(p);
            op = gettok(p, NULL);
            if(op != ')'){
                fprintf(stderr, "missing )\n");
                ungettok(op, p);
            }
            return v;
        default: fprintf(stderr, "unexpected token %c\n", op); return 0;
    }
}


int evalterm(const char **p)
{
    int r = evalpri(p);
    while(1) {
        const int op = gettok(p, NULL);
        switch(op) {
            case '*': r *= evalpri(p); break;
            case '/': r /= evalpri(p); break;
            default: ungettok(op, p); return r;
        }

    }
}

int evalexpr(const char **p)
{
    int r = evalterm(p);
    while(1) {
        const int op = gettok(p, NULL);
        switch(op) {
            case '+': r += evalterm(p); break;
            case '-': r -= evalterm(p); break;
            default: ungettok(op, p); return r;
        }
    }
}


int eval(const char *expr)
{
    return evalexpr(&expr);
}

