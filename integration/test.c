#include <stdio.h>

double f(int x){  //関数定義
  double fx = 0;
  fx = x*x*x*x - 2*x*x*x + x*x - 3*x + 1;
  return fx;
}

int n, a;
float delta, i;
double s_1 = 0, s_2 = 0, s = 0;
double y[1000];   //yを配列で定義する

int main(){
  printf("台形公式を行います\n積分区間は何等分しますか？\n");
  scanf("%d", &n);

  delta = (double) 3 / n;  //デルタの計算

  for(i = 0, a = 0; a <= n; i = i + delta, a++){  //関数に数字を一つずついれ結果をｙに入れる
    y[a] = f(i);
  }


  s_1 = (y[0] + y[n]) / 2;  //y_0,y_nの足し算を2で割る

  for(int t = 1; t < n; t++){  //y_1からy_n-1まで足し算
    s_2 = s_2 + y[t];
  }
  s = delta * (s_1 + s_2);  //s_1とs_2をたしデルタをかける

  printf("答えは%lfです\n", s);  //答えｓを出力

  return 0;
}
