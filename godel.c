#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    pre-generated for demonstration, but could be done dynamically
*/
int primes[] = { 
    2, 3, 5, 7, 11, 13, 17, 19, 23, 
    29, 31, 37, 41, 43, 47, 53, 59, 
    61, 67, 71, 73, 79, 83, 89, 97
};

struct Stack {
    unsigned long top;
    int primeindex;
};

int factors(int n, struct Stack *stack)
{
    int mul = primes[stack->primeindex - 1];
    int ret = 0;
    while (n % mul == 0) {
        n = n / mul;
        ret += 1;
    }
    return ret;
}

void
push(struct Stack *stack, int val)
{
    int lo = primes[stack->primeindex++];
    stack->top *= pow(lo, val);
}

int
pop(struct Stack *stack)
{
    int ret = factors(stack->top, stack);
    stack->primeindex--;
    stack->top = (stack->top / pow(primes[stack->primeindex], ret));
    return ret;
}

int
main(int argc, char *argv[])
{
    struct Stack stack;
    int ret; 

    stack.top = 1;
    stack.primeindex = 0;
    push(&stack, 3);
    push(&stack, 5);
    ret = pop(&stack);
    printf("%d\n", ret);
    push(&stack, 7);
    push(&stack, 6);
    ret = pop(&stack);
    printf("%d\n", ret);
    return 0;
}
