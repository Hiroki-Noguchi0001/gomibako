#include <stdio.h>

double dxf_1(double x)
{
	return x*x + 2*x - 1;
}

double cal_y(double delta_x, double n){
	
	double y[1000];
	double sum, ans;
	double x = 0;

	for(int i = 1; i <= n; i++){
		
		y[i] = dxf_1(x);
		x += delta_x;
	}

	for(int i = 1; i <= n; i++){

		if(i == 1 || i == n){
			sum += y[i];
		}

		else{
		sum += 2 * y[i];
		}
	}

	ans = (delta_x / 2) * sum;

	return ans;
	
}




int main(){

	double n, delta_x, ans;

	printf("台形公式をおこないます。範囲を何等分するか入力してください\n");
	scanf("%lf", &n);

	delta_x = 5 / n;
	printf("delta = %lf\n", delta_x);

	ans = cal_y(delta_x, n);

	printf("答えは...%lf\n",ans);
	}


