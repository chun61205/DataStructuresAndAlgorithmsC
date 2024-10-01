#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"

stack *createStack(size_t capacity)
{
    return (stack*)malloc(capacity*sizeof(stack));
}
bool isFullStack(stack *s, size_t capacity, int top)
{
    return ((top >= (capacity-1)) && (top != -1)); //The size_t data type is unsigned which means if top is equal to -1, the function will return true, and this if out of the requirement. Therefor we add a statement "top != -1" behind.
}
bool isEmptyStack(stack *s, size_t capacity, int top)
{
    return (top==-1);
}
stack *reallocStack(stack *s, size_t capacity, int top, size_t newCapacity)
{
    if(top >= newCapacity)
        exit(EXIT_FAILURE);
    stack *new_s = create_stack(newCapacity);
    for(int i=0; i<=top; i++)
        (new_s+i)->data = (s+i)->data;
    free(s);
    return new_s;
}
void pushStack(stack *s, size_t capacity, int top, stack item)
{
    if(is_full_stack(s, capacity, top))
        exit(EXIT_FAILURE);
    top++;
    s[top] = item;
    return;
}
void popStack(stack *s, size_t capacity, int top)
{
    if(isEmptyStack(s, capacity, top))
        exit(EXIT_FAILURE);
    top--;
    return;
}