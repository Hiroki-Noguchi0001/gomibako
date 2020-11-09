#include <stdio.h>
#include <math.h>
#define eps 1e-8

double f(double x)//方程式
{
	return 5*x*x*x + 10*x*x -2*x -5;//違う方程式を解くときはここを変更してください
}

double dxf(double x)//導関数
{
	return 15*x*x + 20*x -2;//違う方程式を解くときはここを変更してください
}


double calculation(double *x, int nmax)//計算部分
{
	int n = 0;//nの初期化
	double delta = 0;//nの初期化

	while(n < nmax)
	{
		n++;
		delta = -f(*x) / dxf(*x);
		*x += delta;
		printf("%d回目, x = %.8f, delta = %.8f\n",n, *x, delta);//途中経過の出力
		if(fabs(delta) < eps)//誤差(delta)が1e-8以下に収束したかどうかの判定
		{
			return *x;//解を返す
		}
	}
	printf("解は収束しませんでした..\n");//解が収束しなかった場合は終了
	return 0;
}

int main(){
	int nmax;
	double x;

	printf("初期値xを入力してください\n");
	scanf("%lf", &x);
	printf("最大繰り返し回数を入力してください\n");
	scanf("%d", &nmax);

	calculation(&x, nmax);//計算部分の呼び出し
	printf("解は%.8f", x);


	return 0;

}
