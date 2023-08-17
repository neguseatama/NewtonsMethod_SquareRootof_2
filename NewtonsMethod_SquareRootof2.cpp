/*
 Newton's method and Square root of 2 in C++
 C++によるニュートン法の実装と√2の計算
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

double start,error;
//初期値の入力をstartで受け取り、
//誤差限界の入力をerrorで受け取る。

//微分を実行する関数
pair<ll,ll> differentiate(pair<ll,ll> p){
    return {p.first*p.second,p.second-1};
}

//ニュートン法の反復計算を実行する関数
double newton(void){
    //√2を求める場合、
    //f(x)=x^2-2とおいてf(x)=0となる解を考える。
    //また、f'(x)=2*xである。
    double ans=start;
    double ans2=start-(start*start-2)/(2*start);
    while(abs(ans-ans2)>=error){
        ans=ans2;
        ans2=ans-(ans*ans-2)/(2*ans);
    }
    return ans2;
}

int main(void){
    cin>>start>>error;
    cout<<fixed<<setprecision(30)<<
			newton()<<endl; //求まった近似値を出力
    return 0;
}



//ChatGPT
#include <iostream>
#include <cmath>

double newton_sqrt_approximation(double initial_guess, double tolerance, int max_iterations) {
    double x_n = initial_guess;
    
    for (int i = 0; i < max_iterations; ++i) {
        // 関数と導関数の計算
        double f_x = x_n * x_n - 2;
        double f_prime_x = 2 * x_n;
        
        // ニュートン法の更新式
        double x_n_plus_1 = x_n - f_x / f_prime_x;
        
        // 収束判定
        if (std::abs(x_n_plus_1 - x_n) < tolerance) {
            return x_n_plus_1;
        }
        
        x_n = x_n_plus_1;
    }
    
    return x_n;
}

int main() {
    // 初期値、誤差の許容上限、最大反復回数を指定
    double initial_guess; cin>>initial_guess;  // 任意の初期値
    double tolerance; cin>>tolerance;     // 任意の誤差の許容上限
    int max_iterations = 1000;   // 最大反復回数
    
    // 近似値を求める
    double approximation = newton_sqrt_approximation(initial_guess, tolerance, max_iterations);
    std::cout << "Approximation of square root of 2: " << approximation << std::endl;
    
    return 0;
}