#include <stdio.h>

double dxf_1(double x)
{
	return x*x + 2*x - 1;
}

double trape_cal_y(double delta_x, int n){
	
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


double simpson_cal_y(double delta_x, int n){
	
	double y[1000];
	double sum, ans = 0;
	double x = 0;

	for(int i = 1; i <= n; i++){
		
		y[i] = dxf_1(x);
		x += delta_x;
	}

	sum = y[1] + y[n];

	printf("sum1 = %lf\n", sum);
	printf("y = %lf\n", y[n]);

	for(int i = 2; i < n; i+=2){ //×4
		sum += 4 * y[i];
		
	printf("y2... = %lf\n", y[i]);
	}

	for(int i = 3; i < n; i+=2){//×2
		sum += 2 * y[i];

	printf("y3.... = %lf\n", y[i]);
	}

	printf("sum = %lf\n", sum);

	ans = (delta_x / 3) * sum;

	return ans;
}




int main(){

	int n;
	double delta_x, trape_ans, simp_ans;

	printf("台形公式をおこないます。範囲を何等分するか入力してください\n");
	scanf("%d", &n);

	delta_x = 5.0 / n;
	printf("delta = %lf\n", delta_x);

	trape_ans = trape_cal_y(delta_x, n);
	simp_ans = simpson_cal_y(delta_x, n);


	printf("台形法を使用した答えは...%lf\n",trape_ans);
	printf("シンプソン法を使用した答えは...%lf\n", simp_ans);
	}


