#include <stdio.h>
void merge_and_sort(int s1, int s2) {
int s3 = s1 + s2;
int i, j, temp, k = s1;
int a1[s1], a2[s2], a3[s3];

printf("Enter the elements in the 1st array:\n");
for(i = 0; i < s1; i++) {
scanf("%d", &a1[i]);
a3[i] = a1[i]; 

}

printf("\nEnter the elements in the 2nd array:\n");
for(i = 0; i < s2; i++) {
scanf("%d", &a2[i]);
a3[k] = a2[i]; 
k++;
}

printf("\nThe merged array before sorting:\n\t");
for(i = 0; i < s3; i++) {
printf("%d ", a3[i]);
}

printf("\nThe merged array after sorting:\n\t");
for(i = 0; i < s3 - 1; i++) {
for(j = i + 1; j < s3; j++) {
if(a3[i] > a3[j]) {
temp = a3[i];
a3[i] = a3[j];
a3[j] = temp;
}
}
}
for(i = 0; i < s3; i++) {
printf("%d ", a3[i]);
}
printf("\n");}
int main() {
int s1, s2;

printf("Enter the size of the 1st array: ");
scanf("%d", &s1);
printf("\nEnter the size of the 2nd array: ");
scanf("%d", &s2);

merge_and_sort(s1, s2);
return 0;}