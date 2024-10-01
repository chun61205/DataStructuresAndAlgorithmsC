#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"polynomial.h"

poly *create_poly(size_t capacity)
{
    return (poly*)calloc(capacity, sizeof(poly));
}
int get_degree_poly(poly *p, size_t capacity, size_t size)
{
    return p->exp;
}
double get_lead_coef_poly(poly *p, size_t capacity, size_t size)
{
    return p->coef;
}
int get_size_poly(poly *p, size_t capacity, size_t size)
{
    int size = -1;
    for(int i=0; i<capacity; i++)
    {
        if((p+i)->coef == 0)
        {
            size = i;
            break;
        }
    }
    if(size == -1)
        size = capacity;
    return size;
}
bool is_zero_poly(poly *p, size_t capacity, size_t size)
{
    if(p->coef==0)
        return true;
    else
        return false;
}
poly *realloc_poly(poly *p, size_t capacity, size_t size, size_t new_capacity)
{
    if(new_capacity < size)
        exit(EXIT_FAILURE);
    poly *new_p = creating_poly(new_capacity);
    copy_poly(p, size, new_p, new_capacity);
    free(p);
    return new_p;
}
void remove_poly(poly *p, size_t capacity, size_t size, int exp)
{
    int index=-1;
    for(int i=0; i<size; i++)
    {
        if((p+i)->exp == exp)
        {
            index = i;
            break;
        }
    }
    if(index!=-1)
    {
        for(int i=index; i<size; i++)
        {
            (p+i)->exp = (p+i+1)->coef;
            (p+i)->coef = (p+i+1)->coef;
        }
        (p+size)->exp = 0;
        (p+size)->coef = 0;
    }
    else
        exit(EXIT_FAILURE);
    return;
}
poly *add_poly(poly *p1, size_t capacity1, size_t size1, poly *p2, size_t capacity2, size_t size2)
{
    poly *result = (poly*)calloc(size1+size2,sizeof(poly));
    int i1=0,i2=0,i=0;
    for(i=0; i1<size1 || i2<size2; i++)
    {
        if((p1+i1)->exp > (p2+i2)->exp)
        {
            (result+i)->exp=(p1+i1)->exp;
            (result+i)->coef=(p1+i1)->coef;
            i1++;
        }
        else if((p1+i1)->exp < (p2+i2)->exp)
        {
            (result+i)->exp=(p2+i2)->exp;
            (result+i)->coef=(p2+i2)->coef;
            i2++;
        }
        else
        {
            if((p1+i1)->coef+(p2+i2)->coef != 0)
            {
                (result+i)->exp=(p1+i1)->exp;
                (result+i)->coef=((p1+i1)->coef+(p2+i2)->coef);
                i1++;
                i2++;
            }
        }
    }
    if(i1 < size1 && i2 < size2)
        return result;
    else if(i1 < size1)
    {
        for(; i2 < size2; i2++, i++)
        {
            (result+i)->exp=(p2+i2)->exp;
            (result+i)->coef=(p2+i2)->coef;
        }
    }
    else if(i2 < size2)
    {
        for(; i1 < size1; i1++, i++)
        {
            (result+i)->exp=(p1+i1)->exp;
            (result+i)->coef=(p1+i1)->coef;
        }
    }
    return result;
}
poly *mult_poly(poly *p1, size_t capacity1, size_t size1, poly *p2, size_t capacity2, size_t size2)
{
    poly *result = (poly*)calloc(size1*size2,sizeof(poly));
    int size=0;
    for(int i1=0; i1<size1; i1++)
    {   
        for(int i2=0; i2<size2; i2++)
        {
            int exp=(p1+i1)->exp * (p2+i2)->exp, coef=(p1+i1)->coef * (p2+i2)->coef;
            int index=-1;
            for(int i=0; i<size; i++)
            {
                if((result+i)->exp < exp)
                {
                    index = i;
                    break;
                }
            }
            if(index!=-1)
            {
                for(int i=size-1; i>=index; i--)
                {
                    (result+i)->exp = (result+i+1)->exp;
                    (result+i)->coef = (result+i+1)->coef;
                }
                (result+index)->exp = exp;
                (result+index)->coef = coef;
            }
            else
            {
                (result+size)->exp = exp;
                (result+size)->coef = coef;
            }
            if(size==0)
            {
                result->coef = coef;
                result->exp = exp;
            }
            size++;
        }
    }
    return result;
}
double evaluate_poly(poly *p, size_t capacity, size_t size, double x)
{
    double sum;
    for(int i=0; i<size; i++)
        sum+= (p+i)->coef * pow(x,(p+i)->exp);
    return sum;
}
void copy_poly(poly *p1, size_t capacity1, size_t size1, poly *p2, size_t capacity2, size_t size2)
{
    if(capacity2 < size1)
        exit(EXIT_FAILURE);
    else
    {
        for(int i=0; i<size1; i++)
        {
            (p1+i)->coef = (p2+i)->coef;
            (p1+i)->exp = (p2+i)->exp;
        }
    }
    return;
}
void print_poly(poly *p, size_t capacity, size_t size)
{
    for(int i=0; i<size-1; i++)
        printf("%dx^%d+", (p+i)->coef, (p+i)->exp);
    printf("%dx^%d", (p+size-1)->coef, (p+size-1)->exp);
    return;
}