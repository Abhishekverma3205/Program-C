Knapsack Problem
#include <stdio.h>
struct Item
{
 int weight;
 int profit;
 float ratio;
};
void sort(struct Item arr[], int n)
{
 int i, j;
 struct Item temp;
 for(i = 0; i < n-1; i++)
 {
 for(j = 0; j < n-i-1; j++)
 {
 if(arr[j].ratio < arr[j+1].ratio)
 {
 temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 }
 }
}
int main()
{
 int n, i;
 float capacity, totalProfit = 0.0;
 printf("Enter number of items: ");
 scanf("%d", &n);
 struct Item arr[n];
 for(i = 0; i < n; i++)
 {
 printf("Enter weight and profit of item %d: ", i+1);
 scanf("%d %d", &arr[i].weight, &arr[i].profit);
 arr[i].ratio = (float)arr[i].profit / arr[i].weight;
 }
 printf("Enter knapsack capacity: ");
 scanf("%f", &capacity);
 sort(arr, n);
 for(i = 0; i < n; i++)
 {
 if(capacity >= arr[i].weight)
 {
 capacity -= arr[i].weight;
 totalProfit += arr[i].profit;
 }
 else
 {
 totalProfit += arr[i].ratio * capacity;
 break;
 }
 }
 printf("Maximum Profit = %.2f", totalProfit);
 return 0;
}