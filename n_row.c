#include <stdio.h>
#include <math.h>
#define eps 1e-6

double f(double x)
{
	return 5*x*x*x + 10*x*x -2*x -5;
}

double dxf(double x)
{
	return 15*x*x + 20*x -2;
}


double calculation(double *x, int nmax)
{
	int n = 0;
	double delta = 0;

	while(n < nmax)
	{
		delta = -f(*x) / dxf(*x);
		*x += delta;
		printf("x = %lf, delta = %lf\n", *x, delta);
		if(fabs(delta) < eps)
		{
			return *x;
		}
		n++;
	}

	printf("解は収束しませんでした..\n");


}

int main(){

	int nmax;
	double x;

	printf("初期値xを入力してください\n");
	scanf("%lf", &x);
	printf("最大繰り返し回数を入力してください\n");
	scanf("%d", &nmax);

	calculation(&x, nmax);
	printf("解は%lf", x);


	return 0;

}
