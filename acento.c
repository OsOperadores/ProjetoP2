#include <stdio.h>

double carro_um (double vi, double ac, double t)
{
	double total;
	total = vi + ac * t;
	return total * 3.6;
}
double carro_dois (double vi2, double ac2, double t2)
{
	double total2;
	total2 = vi2 + ac2 * t2;
	return total2 * 3.6;
}
double carro_tres (double vi3, double ac3, double t3)
{
	double total3;
	total3 = vi3 + ac3 * t3;
	return total3 * 3.6;
}


int main()
{
	double vi, ac, t, vi2, ac2, t2, vi3, ac3, t3, troca;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &vi, &ac, &t, &vi2, &ac2, &t2, &vi3, &ac3, &t3);
    printf("%.2lf\n%.2lf\n%.2lf\n", carro_um(vi, ac, t), carro_dois(vi2, ac2, t2), carro_tres(vi3, ac3, t3) );
    
}