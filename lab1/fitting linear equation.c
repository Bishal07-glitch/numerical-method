#include <stdio.h>

#define MAX 10

// Function to fit a linear equation using least squares method
void linearFit(float x[], float y[], int n, float *slope, float *intercept)
{
    float sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    float denominator = (n * sumX2) - (sumX * sumX);
    *slope = ((n * sumXY) - (sumX * sumY)) / denominator;
    *intercept = (sumY - (*slope * sumX)) / n;
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

    float slope, intercept;
    linearFit(x, y, n, &slope, &intercept);

    printf("Linear equation: y = %.2fx + %.2f\n", slope, intercept);

    return 0;
}
