#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "polynomial.h"

poly *createPoly(size_t capacity)
{
    poly *p = (poly*)malloc(sizeof(poly));
    if(!p){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    p->function = (functionPoly*)calloc(capacity, sizeof(functionPoly));
    if(!p->function){
        free(p);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    p->function->coef = 0;
    p->function->exp = 0;
    p->capacity = capacity;
    p->size = 0;
    return p;
}
int getDegreePoly(poly *p){
    if(p->size == 0)
        return 0;
    return p->function->exp;
}
double getLeadCoefPoly(poly *p){
    if(p->size == 0)
        return 0;
    return p->function->coef;
}
bool isZeroPoly(poly *p){
    return(p->size == 0 || (p->size == 1 && p->function->coef == 0));
}
poly *reallocPoly(poly *p, size_t newCapacity){
    if(newCapacity < p->size){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }
    functionPoly *newFunction = (functionPoly*)realloc(p->function, newCapacity * sizeof(functionPoly));
    if(!newFunction){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    p->function = newFunction;
    p->capacity = newCapacity;
    return p;
}
void removePoly(poly *p, int exp){
    int index = -1;
    for(int i = 0; i < p->size; i++){
        if((p->function + i)->exp == exp){
            index = i;
            break;
        }
    }
    if(index != -1){
        for(int i = index; i < (p->size) - 1; i++){
            p->function[i] = p->function[i + 1];
        }
        
        p->size--;
    }else{
        fprintf(stderr, "The term with exponent %d is not found!\n", exp);
    }
}
poly *addPoly(poly *p1, poly *p2) {
    poly *result = createPoly(p1->size + p2->size);
    size_t i1 = 0, i2 = 0, i = 0;

    while(i1 < p1->size && i2 < p2->size){
        if((p1->function + i1)->exp > (p2->function + i2)->exp){
            result->function[i++] = p1->function[i1++];
        }else if((p1->function + i1)->exp < (p2->function + i2)->exp){
            result->function[i++] = p2->function[i2++];
        }else{
            double sum = (p1->function + i1)->coef + (p2->function + i2)->coef;
            if(sum != 0){  // Only add if the coefficient is non-zero
                (result->function + i)->exp = (p1->function + i1)->exp;
                (result->function + i)->coef = sum;
                i++;
            }
            i1++;
            i2++;
        }
    }

    while(i1 < p1->size)
        result->function[i++] = p1->function[i1++];
    while(i2 < p2->size)
        result->function[i++] = p2->function[i2++];
    
    result->size = i;
    return result;
}
poly *multPoly(poly *p1, poly *p2){
    poly *result = createPoly(p1->size * p2->size);
    for(int i = 0; i < p1->size; i++){
        for(int j = 0; j < p2->size; j++){
            int exp = (p1->function + i)->exp + (p2->function + j)->exp;
            double coef = (p1->function + i)->coef * (p2->function + j)->coef;

            if(coef != 0){
                bool found = false;
                for(size_t k = 0; k < result->size; k++){
                    if ((result->function + k)->exp == exp){
                        (result->function + k)->coef += coef;
                        found = true;
                        break;
                    }
                }

                if(!found){
                    (result->function +result->size)->exp = exp;
                    (result->function + result->size)->coef = coef;
                    result->size++;
                }
            }
        }
    }
    return result;
}
double evaluatePoly(poly *p, double x){
    double result = 0.0;
    for(int i = 0; i < p->size; i++){
        result += (p->function + i)->coef * pow(x, (p->function + i)->exp);
    }
    return result;
}
void copyPoly(poly *p1, poly *p2)
{
    if(p2->capacity < p1->size){
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < p1->size; i++){
        (p2->function + i)->coef = (p1->function + i)->coef;
        (p2->function + i)->exp = (p1->function + i)->exp;
    }

    p2->size = p1->size;

    return;
}
void printPoly(poly *p){
    if(p->size == 0){
        printf("0\n");
        return;
    }
    for(int i = 0; i < p->size - 1; i++){
        printf("%.2lfx^%d + ", (p->function + i)->coef, (p->function + i)->exp);
    }
    printf("%.2lfx^%d\n", (p->function + p->size - 1)->coef, (p->function + p->size - 1)->exp);
}