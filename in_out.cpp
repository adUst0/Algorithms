#include <iostream>
using namespace std;

int main() {
	int x;
	char c, buff[1001];
	while (scanf("%d", &x) != EOF) {}
	while (cin >> x) {}
	while ((c = getchar()) != EOF) {}
	while (cin.getline(buff, 1000)) {}

	printf("%lf\n", 3.14); // 3.140000
	printf("%.2lf\n", 3.14); // 3.14
	printf("%03d\n", 3); // 003

	return 0;
}