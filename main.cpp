#include <iostream>
#include <iomanip>

#include "data.hpp"

void print(double x1, double x2, double x3, double x4, double p2, double p3)
{
  std::cout << "x1: " << std::setw(4) << x1 << '\t';
  std::cout << "| p2: " << std::setw(8) << p2 << '\t';
  std::cout << "| p3: " << std::setw(13) << std::right << p3 << '\t';
  std::cout << "| x2: " << std::setw(8) << x2 << '\t';
  std::cout << "| x3: " << std::setw(4) << x3 << '\t';
  std::cout << "| x4: " << std::setw(8) << x4 << '\t';
  std::cout << '\n';
}

void doCalculation(double h)
{
  double x1 = h;
  int num_steps = 4.0 / h;
  for (int i = 2; i <= num_steps; ++i) {
    double p3 = get_p3(x1);
    double p2 = get_p2(x1, p3);
    double x2 = get_x2(x1, p3);
    double x3 = get_x3(x1);
    double x4 = get_x4(x1, p3);

    if (i == num_steps / 2) {
      continue;
    }
    print(x1, x2, x3, x4, p2, p3);

    x1 = h * i;
  }
}

void doCalculation2(double h)
{
  double x1 = 2;
  double x3 = 2;
  double p3 = h;
  double x2 = get_x2(x1, p3);
  double x4 = get_x4(x1, p3);
  double p2 = get_p2(x1, p3);
  while (p3 < 4.0) {
    print(x1, x2, x3, x4, p2, p3);

    p3 += h;
    x2 = get_x2(x1, p3);
    x4 = x2;
    p2 = get_p2(x1, p3);
  }
}

void check(double x1)
{
  std::cout << "x1_dt = " << std::fixed << x1_dt(x1) << '\n';
  std::cout << "x2_dt = " << x2_dt(x1) << '\n';
  std::cout << "x3_dt = " << x3_dt(x1) << '\n';
  std::cout << "x4_dt = " << x4_dt(x1) << '\n';

  std::cout << "determinant = " << determinant(x1) << '\n';
  std::cout << "determinant dp2 = " << determinant_dp2(x1) << '\n';
  std::cout << "determinant dp3 = " << determinant_dp3(x1) << '\n';

}

int main()
{
  double h = 0.1;
  doCalculation(h);
  std::cout << "----\n";
  doCalculation2(h);
  std::cout << "----\n";
  check(1.0);
  return 0;
}
