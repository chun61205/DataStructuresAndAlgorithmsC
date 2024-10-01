#include<stdlib.h>
#include"sparce_matrix.h"

sm *create_sm(int capacity, size_t row, size_t col)
{
    sm *A=(sm*)malloc(capacity*sizeof(sm));
    A->row = row;
    A->col = col;
    A->val = 0;
    return A;
}
sm *realloc_sm(sm *A, size_t capacity, size_t new_capacity)
{
    if(new_capacity < (A->val+1))
        exit(EXIT_FAILURE);
    sm *new_A = creating_poly(new_capacity, A->row, A->col);
    copy_sm(A, new_A, new_capacity);
    free(A);
    return new_A;
}
void *insert_sm(sm *A, size_t capacity, int row, int col, double val)
{
    if(val == 0 || (A->val+1+1)>=capacity || row>(A->row)-1 || col>(A->col)-1)
        exit(EXIT_FAILURE);
    int index=-1;
    for(int i=A->val; i>=1; i--)
    {
        int j=i;
        while((A+i)->row <= row)
        {
            if((A+j)->row == row && (A+j)->col > col)
            {
                j--;
            }
            else
            {
                index=j+1;
                goto out;
            }
        }
        index=i+1;
    }
    out:if(index == -1)
    {
        index = 1;
    }
    for(int i=A->val; i>=index; i--)
    {
        (A+i+1)->row = (A+i)->row;
        (A+i+1)->col = (A+i)->col;
        (A+i+1)->val = (A+i)->val;
    }
    (A+index)->row = row;
    (A+index)->col = col;
    (A+index)->val = val;
    A->val++;
    return 0;
}
sm *transpose_sm(sm *A, size_t capacity)
{
    int row_terms[A[0].col],starting_pos[A[0].col];
    int i,j;
    sm *result=create_sm((int)(A->val+1), A->col, A->row);
    if(A->val > 0)
    {
        for(i=0;i<A->col;i++)
        {
            row_terms[i]=0;
        }
        for(i=1;i<=A->val;i++)
        {
            row_terms[A[i].col]++;
        }
        starting_pos[0]=1;
        for(i=1;i<A->col;i++)
        {
            starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
        }
        result->row=A->col;
        result->col=A->row;
        result->val=A->val;
        for(i=1;i<=A->val;i++)
        {
            j=starting_pos[(A+i)->col]++;
            (result+j)->row=(A+i)->col;
            (result+j)->col=(A+i)->row;
            (result+j)->val=(A+i)->val;
        }
    }
    return result;
}
sm *add_sm(sm *A, size_t capacityA, sm *B, size_t capacityB)
{
    if(A->row != B->row || A->col != B->col)
        exit(EXIT_FAILURE);
    sm *result=create_sm((int)(A->val+B->val+1), result->row = A->col, result->col = A->row);
    int a = 1, b = 1, r = 1;
    while(A->val >= a || B->val >= b )
    {
        if((A+a)->row == (B+b)->row)
        {
            if((A+a)->col == (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val + (B+b)->val;
                a++;
                b++;
                r++;
            }
            else if ((A+a)->col > (B+b)->col)
            {
                (result+r)->row = (B+b)->row;
                (result+r)->col = (B+b)->col;
                (result+r)->val = (B+b)->val;
                b++;
                r++;
            }
            else if((A+a)->col < (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val;
                a++;
                r++;
            }
        }
        else if((A+a)->row > (B+b)->row)
        {
            if((A+a)->col == (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val + (B+b)->val;
                a++;
                b++;
                r++;
            }
            else if ((A+a)->col > (B+b)->col)
            {
                (result+r)->row = (B+b)->row;
                (result+r)->col = (B+b)->col;
                (result+r)->val = (B+b)->val;
                b++;
                r++;
            }
            else if((A+a)->col < (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val;
                a++;
                r++;
            }
        }
        else if((A+a)->row < (B+b)->row)
        {
            if((A+a)->col == (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val + (B+b)->val;
                a++;
                b++;
                r++;
            }
            else if ((A+a)->col > (B+b)->col)
            {
                (result+r)->row = (B+b)->row;
                (result+r)->col = (B+b)->col;
                (result+r)->val = (B+b)->val;
                b++;
                r++;
            }
            else if((A+a)->col < (B+b)->col)
            {
                (result+r)->row = (A+a)->row;
                (result+r)->col = (A+a)->col;
                (result+r)->val = (A+a)->val;
                a++;
                r++;
            }
        }
    }
    if(A->val < a)
    {
        while(B->val >= b)
        {
            (result+r)->row = (B+b)->row;
            (result+r)->col = (B+b)->col;
            (result+r)->val = (B+b)->val;
            b++;
            r++;
        }
    }
    if(B->val < b)
    {
        while(A->val >= a)
        {
            (result+r)->row = (A+a)->row;
            (result+r)->col = (A+a)->col;
            (result+r)->val = (A+a)->val;
            a++;
            r++;
        }
    }
    result->val = (r-1);
    return result;
}
sm *mult_sm(sm *A, size_t capacityA, sm *B, size_t capacityB)
{
    if(A->col != B->row)
        exit(EXIT_FAILURE);
    sm *transposed_B = create_sm((int)(B->val+1), B->col, B->row);
    transposed_B = transpose_sm(B);
    sm *result = create_sm((int)(A->val+B->val+1),A->row,B->col);
    int sum[result->col];
    for(int i=0; i<result->col; i++)
        sum[i]=0;
    int row=0;
    int index_result=1;
    for(int a=1; a<=A->val;)
    {
        if((A+a)->row == row)
        {
            for(int b=1; b<=B->val; b++)
            {
                if((A+a)->col == (B+b)->col)
                {
                    sum[(B+b)->row] += ((A+a)->val * (B+b)->val);
                }
            }
            a++;
        }
        else
        {
            for(int i=0; i<result->col; i++)
            {
                if(sum[i] != 0)
                {
                    (result+index_result) -> row = row;
                    (result+index_result) -> col = i;
                    (result+index_result) -> val = sum[i];
                    index_result++;
                    sum[i]=0;
                }
            }
            row++;
        }
    }
    for(int i=0; i<result->col; i++)
    {
        if(sum[i] != 0)
        {
            (result+index_result) -> row = row;
            (result+index_result) -> col = i;
            (result+index_result) -> val = sum[i];
        }
    }
    result->val = index_result;
    return result;
}
void copy_sm(sm *A, size_t capacityA, sm *B, size_t capacityB)
{
    if(capacityB < (A->val+1))
        exit(EXIT_FAILURE);
    for(int i=0; i<=A->val; i++)
    {
        (B+i)->row = (A+i)->row;
        (B+i)->col = (A+i)->col;
        (B+i)->val = (A+i)->val;
    }
    return;
}