// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int K, const int N)
{
	double s = 0, a=1;
	for (int K = a; a <= N; a++)
		s += 1. / (2. * K + 1) * (2. * K + 1);
	return s;
}
double S1(const int K, const int N, const int a)
{
	if (a > N)
		return 0;
	else
		return 1. / (2. * K + 1) * (2. * K + 1) + S1(K, N, a + 1);
}
double S2(const int K, const int N, const int a)
{
	if (a < K)
		return 0;
	else
		return 1. / (2. * K + 1) * (2. * K + 1) + S2(K, N, a - 1);
}
double S3(const int K, const int N, const int a, double t)
{
	t = t + 1. / (2. * K + 1) * (2. * K + 1);
	if (a >= N)
		return t;
	else
		return S3(K, N, a + 1, t);
}
double S4(const int K, const int N, const int a, double t)
{
	t = t + 1. / (2. * K + 1) * (2. * K + 1);
	if (a <= K)
		return t;
	else
		return S4(K, N, a - 1, t);
}
int main()
{
	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(K, N) << endl;
	cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
	cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
	cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;
	return 0;
}