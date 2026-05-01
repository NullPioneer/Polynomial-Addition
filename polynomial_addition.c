#include <stdio.h>
#include <stdlib.h>
struct Poly
{
    int coeff;
    int exp;
}p1[10],p2[10],p3[10];
int readPoly(struct Poly p[10])
{
    int t,i;
    printf("\nEnter total terms in polynomial:");
    scanf("%d",&t);
    printf("\nEnter Coefficient and Exponent in Descending order:");
    for (i=0;i<t;i++)
    {
        printf(" %d Coefficient:",i+1);
        scanf("%d",&p[i].coeff);
        printf("%d Exponent:",i+1);
        scanf("%d",&p[i].exp);
    }
    return t;
}
void displayPoly(struct Poly p[10],int term)
{
    int i;
    for (i=0;i<term-1;i++)   //prints till last but one term
    {
        printf("%dx^%d+",p[i].coeff,p[i].exp);
    }
    // prints the last value so the + term doesnt come again
    printf("%dx^%d",p[term-1].coeff,p[term-1].exp); 
}
int addPoly(struct Poly p1[10],struct Poly p2[10],struct Poly p3[10],int t1, int t2)
{//Checks the exponents of both polynomials, if same, add coeffs, otherwise put the higher expo term in sum array

    int i=0,j=0,k=0;
    while (i<t1 && j<t2)
    {
        if (p1[i].exp==p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].exp=p1[i].exp;
            i++;j++;k++;
        }
        else if (p1[i].exp>p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].exp=p1[i].exp;
            i++;k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].exp=p2[j].exp;
            j++;k++;
        }
    }
    // for any leftover terms in polymonial, just directly add them to sum
    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].exp=p1[i].exp;
        i++;k++;
    }
    while(j<t2)
    {
         p3[k].coeff=p2[j].coeff;
        p3[k].exp=p2[j].exp;
        j++;k++;
    }
    return k; //returns number of terms in result poly to display it in other function
}
void main()
{
    int t1,t2,t3;
    t1=readPoly(p1);
    printf("\nFirst Polynomial:");
    displayPoly(p1,t1);
    t2=readPoly(p2);
    printf("\nSecond Polynomial:");
    displayPoly(p2,t2);

    t3=addPoly(p1,p2,p3,t1,t2);
    printf("\nResultant Polynomial after addition:");
    displayPoly(p3,t3);
}\
