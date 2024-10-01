#ifndef POLY_H
#define POLY_H

typedef struct
{
    double coef;
    int exp;
}poly;

poly *create_poly(size_t);
int get_degree_poly(poly*, size_t, size_t);
double get_lead_coef_poly(poly*, size_t, size_t);
int get_size_poly(poly*, size_t, size_t);
bool is_zero_poly(poly*, size_t, size_t);
poly *realloc_poly(poly*, size_t, size_t, size_t);
///void *sort_poly;
void remove_poly(poly*, size_t, size_t, int);
//void *insert_poly;
poly *add_poly(poly*, size_t, size_t, poly*, size_t, size_t);
poly *mult_poly(poly*, size_t, size_t, poly*, size_t, size_t);
double evaluate_poly(poly*, size_t, size_t, double);
void copy_poly(poly*, size_t, size_t, poly*, size_t, size_t);
void print_poly(poly*, size_t, size_t);

#endif