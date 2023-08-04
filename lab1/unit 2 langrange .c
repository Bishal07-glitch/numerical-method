#include<stdio.h>
#include<math.h>
#define MAX 15

int main()
{
    int n, i, j;
    float x[MAX], f[MAX], fp, _if, sum, xp;
    char q;
    
    printf("\nInput the number of data pairs: ");
    scanf("%d", &n);
    
    printf("\nPrint data pairs x(i) and values f(i) (one set in each line):");
    for(i = 0; i < n; i++)
        scanf("%f%f", &x[i], &f[i]);
    
    do {
        printf("\nInput x at which interpolation is required: ");
        scanf("%f", &xp);
        
        sum = 0.0;
        for(i = 0; i < n; i++) {
            _if = 1.0;
            for(j = 0; j < n; j++) {
                if(i != j)
                    _if = _if * (xp - x[j]) / (x[i] - x[j]);
            }
            sum = sum + _if * f[i];
        }
        
        fp = sum;
        printf("\nInterpolation function value at x = %f is %f.", xp, fp);
        
        printf("\nDo you want to input another value? (y/n): ");
        scanf(" %c", &q);
    } while(q == 'y');
    
    return 0;
}
