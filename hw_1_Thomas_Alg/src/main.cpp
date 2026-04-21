#include <iostream>
#include <vector>

std::vector <float> Thomas_Alg(const std::vector<float>& a, 
const std::vector<float>& b, const std::vector<float>& c, const 
std::vector<float>& d)
{

	int n = b.size();
	std::vector <float> alpha(n), beta(n), x(n);
	
	alpha[0] = - c[0] / b[0];
	beta[0] = d[0] / b[0];

	for (int i=1; i < n; i++)
	{

		float denom = b[i]+a[i]*alpha[i-1];
		alpha[i] = -c[i] / denom;
		beta[i] = (d[i] - a[i]*beta[i-1]) / denom;

	}

	x[n-1] = beta[n-1];
	for (int i = (n-2); i >=0; i--)
	{

		x[i] = alpha[i]*x[i+1]+beta[i];

	}

	return x;

}

int main()
{

	int n;
	std::cin >> n;

	std::vector <float> a(n), b(n), c(n), d(n);

	for (int i=0; i<n; i++) std::cin >> a[i];
	for (int i=0; i<n; i++) std::cin >> b[i];
	for (int i=0; i<n; i++) std::cin >> c[i];
	for (int i=0; i<n; i++) std::cin >> d[i];
	
	std::vector <float> x = Thomas_Alg (a, b, c, d);

	for (float xi : x)
	{

		std::cout << xi << " ";

	}
	std::cout << std::endl;
}