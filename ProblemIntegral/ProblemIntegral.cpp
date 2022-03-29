// ProblemIntegral.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

double integral_1(double a, double b, unsigned int n, double(* f)(double))
{
	double dx = (b - a) / n, ans = 0.0, c = 0.0;
	for (double x = a; x < b; x += dx) {
		double y = dx * f(x) - c;
		double t = ans + y;
		c = (t - ans) - y;
		ans = t;
	}
	return ans;
}

double integral_2(double a, double b, unsigned int n, double(* f)(double))
{
	double dx = (b - a) / n, ans = 0.0, c = 0.0;
	for (double x = a; x < b; x += dx) {
		double y = dx * (f(x) + f(x + dx)) / 2.0 - c;
		double t = ans + y;
		c = (t - ans) - y;
		ans = t;
	}
	return ans;
}

double integral_3(double a, double b, unsigned int n, double(*f)(double))
{
	double dx = (b - a) / n, ans = 0.0, c = 0.0;
	for (double x = a; x < b; x += dx) {
		double	x1 = x - dx, y1 = f(x1),
				x2 = x, y2 = f(x2),
				x3 = x + dx, y3 = f(x3);
		double	a_ = (y3 - (x3 * (y2 - y1) + x2 * y1 - x1 * y2) / (x2 - x1)) / (x3 * (x3 - x1 - x2) + x1 * x2),
				b_ = (y2 - y1) / (x2 - x1) - a_ * (x1 + x2),
				c_ = (x2 * y1 - x1 * y2) / (x2 - x1) + a_ * x1 * x2;
		double y = 	a_ * pow(x3, 3) / 3.0 + b_ * pow(x3, 2) / 2.0 + c_ * x3 - 
					a_ * pow(x2, 3) / 3.0 - b_ * pow(x2, 2) / 2.0 - c_ * x2 - c;
		double t = ans + y;
		c = (t - ans) - y;
		ans = t;
	}
	return ans;
}

int main()
{
	double a, b;
	unsigned int n;
	std::cin >> a >> b >> n;
	std::cout << "For sin(x):\n";
	std::cout << integral_1(a, b, n, [](double x) { return sin(x); }) << '\n';
	std::cout << integral_2(a, b, n, [](double x) { return sin(x); }) << '\n';
	std::cout << integral_3(a, b, n, [](double x) { return sin(x); }) << '\n';
	std::cin >> a >> b >> n;
	std::cout << "For pow(x, 2):\n";
	std::cout << integral_1(a, b, n, [](double x) { return pow(x, 2); }) << '\n';
	std::cout << integral_2(a, b, n, [](double x) { return pow(x, 2); }) << '\n';
	std::cout << integral_3(a, b, n, [](double x) { return pow(x, 2); }) << '\n';
	std::cin >> a >> b >> n;
	std::cout << "For log(x):\n";
	std::cout << integral_1(a, b, n, [](double x) { return log(x); }) << '\n';
	std::cout << integral_2(a, b, n, [](double x) { return log(x); }) << '\n';
	std::cout << integral_3(a, b, n, [](double x) { return log(x); }) << '\n';
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
