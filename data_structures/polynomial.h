#ifndef POLY_H
#define POLY_H

typedef struct{
    double coef;
    int exp;
}functionPoly;

typedef struct{
    functionPoly *function;
    size_t capacity;
    size_t size;
}poly;

poly *createPoly(size_t);
int getDegreePoly(poly*);
double getLeadCoefPoly(poly*);
bool isZeroPoly(poly*);
poly *reallocPoly(poly*, size_t);
void removePoly(poly*, int);
//void *insertPoly;
poly *addPoly(poly*, poly*);
poly *multPoly(poly*, poly*);
double evaluatePoly(poly*, double);
void copyPoly(poly*, poly*);
void printPoly(poly*);

#endif