#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to fit an exponential equation using least squares method
void exponentialFit(float x[], float y[], int n, float *a, float *b)
{
    float sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += log(y[i]);
        sumXY += x[i] * log(y[i]);
        sumX2 += x[i] * x[i];
    }

    float denominator = (n * sumX2) - (sumX * sumX);
    *a = exp(((sumY * sumX2) - (sumX * sumXY)) / denominator);
    *b = ((n * sumXY) - (sumX * sumY)) / denominator;
}

int main()
{
    float x[MAX], y[MAX];
    int n;

    printf("Enter the number of data points (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of data points.\n");
        return 1;
    }

    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f%f", &x[i], &y[i]);
    }

    float a, b;
    exponentialFit(x, y, n, &a, &b);

    printf("Exponential equation: y = %.2fe^(%.2fx)\n", a, b);

    return 0;
}
