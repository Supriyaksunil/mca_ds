#include <stdio.h>
struct DisjSet {
int parent[10];
int rank[10];
int n;
} dis;
void makeSet() {
for (int i = 0; i < dis.n; i++) {
dis.parent[i] = i; 

dis.rank[i] = 0; 
}
}
void displaySet() {
printf("\nParent Array: ");
for (int i = 0; i < dis.n; i++)
printf("%d ", dis.parent[i]);
printf("\nRank Array: ");
for (int i = 0; i < dis.n; i++)
printf("%d ", dis.rank[i]);
printf("\n");
}
int find(int x) {
if (dis.parent[x] != x)
dis.parent[x] = find(dis.parent[x]); 
return dis.parent[x];
}
void Union(int x, int y) {
int xset = find(x);
int yset = find(y);
if (xset == yset)
return;
// Union by rank
if (dis.rank[xset] < dis.rank[yset]) {
dis.parent[xset] = yset;
} else if (dis.rank[xset] >
dis.rank[yset]) {
dis.parent[yset] = xset;
} else {
dis.parent[yset] = xset;
dis.rank[xset] += 1; 
}
}
int main() {
int x, y, ch, wish;
printf("Enter the number of elements: ");
scanf("%d", &dis.n);

printf("Elements in the disjoint set will be indexed from 0 to %d.\n", dis.n - 1);
makeSet();
do {
printf("\nMENU\n");
printf("1. Union\n2. Find\n3. Display\n");
printf("Enter choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("Enter two elements to perform union (0 to %d): ", dis.n - 1);
scanf("%d %d", &x, &y);
if (x >= 0 && x < dis.n && y >= 0 &&
y < dis.n) {
Union(x, y);
} else {
printf("Invalid element values.\n");
}
break;
case 2:
printf("Enter two elements to check if they are in the same set (0 to %d): ", dis.n - 1);
scanf("%d %d", &x, &y);
if (x >= 0 && x < dis.n && y >= 0 &&
y < dis.n) {
if (find(x) == find(y))
printf("Elements %d and %d are in the same set.\n", x, y);
else
printf("Elements %d and %d are NOT in the same set.\n", x, y);
} else {
printf("Invalid element values.\n");
}
break;
case 3:
displaySet();
break;
default:
printf("Invalid choice\n");
}
printf("\nDo you wish to continue? (1/0): ");
scanf("%d", &wish);
} while (wish == 1);
return 0;
}