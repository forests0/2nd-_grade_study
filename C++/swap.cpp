#include <iostream>
void swap(int *a, int *b) {
	int x;
	x = *a;
	*a = *b;
	*b = x;
}
void swap(char *a, char *b) {
	char x;
	x = *a;
	*a = *b;
	*b = x;
}

void swap(double *a, double *b) {
	double x;
	x = *a;
	*a = *b;
	*b = x;
}
int main()
{
	int num1 = 20, num2 = 30;
	swap(&num1,&num2);
	std::cout<<num1<<' '<<num2<<' ';
	
	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1,&ch2);
	std::cout<<ch1<<' '<<ch2<<' ';
	
	double db1 = 1.111, db2 = 5.555;
	swap(&db1,&db2);
	std::cout<<db1<<' '<<db2<<' ';
}
