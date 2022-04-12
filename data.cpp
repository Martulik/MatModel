#include <cmath>
#include <iostream>
#include "data.hpp"

double p1 = 2.0;

double get_p2(double _x1, double _p3)
{
  double a2 = get_a2(_x1);
  double b2 = get_b2(_x1);
  double c2 = get_c2(_x1);
  double d2 = get_d2(_x1);
  return -(a2 * _p3 * _p3 + b2 * _p3 + d2) / (c2 * _p3);
}

double get_p4(double _p3)
{
  return 10 * _p3;
}

double get_x2(double _x1, double _p3)
{
  double p2 = get_p2(_x1, _p3);
  double x3 = get_x3(_x1);
  return std::pow(_x1, -2) * (p2 * _x1 - 0.5 * (x3 - _x1) * (1 + 2 * _p3));
}

double get_x3(double _x1)
{
  return 2 * p1 - _x1;
}

double get_x4(double _x1, double _p3)
{
  double x2 = get_x2(_x1, _p3);
  double x3 = get_x3(_x1);
  double p4 = get_p4(_p3);
  return x2 - (std::pow(2 * p4, -1) * (x3 - _x1) * (1 + 2 * _p3));
}

double get_a1(double _x1)
{
  double x3 = get_x3(_x1);
  return 20 * (_x1 * _x1 + x3 * x3);
}

double get_b1(double _x1)
{
  double x3 = get_x3(_x1);
  return 10 * (_x1 * _x1 + x3 * x3) + 2 * _x1 * _x1 * x3 * x3;
}

double get_c1(double _x1)
{
  double x3 = get_x3(_x1);
  return -20 * _x1 * x3;
}

double get_d1(double _x1)
{
  double x3 = get_x3(_x1);
  return _x1 * _x1 * x3 * x3;
}

double get_a2(double _x1)
{
  double x3 = get_x3(_x1);
  return 20 * (_x1 * _x1 + x3 * x3) - (80 * p1 * x3 * (_x1 - p1)) / _x1;
}

double get_b2(double _x1)
{
  double x3 = get_x3(_x1);
  return 10 * (_x1 * _x1 + x3 * x3) + 2 * _x1 * _x1 * x3 * x3 - 4 * x3 * (_x1 - p1) * (_x1 * _x1 + 10 * p1 / _x1);
}

double get_c2(double _x1)
{
  double x3 = get_x3(_x1);
  return 10 * (_x1 * _x1 + x3 * x3 - 4 * p1 * x3);
}

double get_d2(double _x1)
{
  double x3 = get_x3(_x1);
  return _x1 * _x1 * x3 * x3 - 2 * _x1 * _x1 * x3 * (_x1 - p1);
}

double get_p3(double _x1)
{
  double c1 = get_c1(_x1);
  double c2 = get_c2(_x1);
  double a = get_a1(_x1) * c2 - get_a2(_x1) * c1;
  double b = get_b1(_x1) * c2 - get_b2(_x1) * c1;
  double c = get_d1(_x1) * c2 - get_d2(_x1) * c1;
  if ((b * b - 4 * a * c) >= 0) {
    return (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
    //double second = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a); // < 0, по условию пролетает
  } else {
    std::cout << "D < 0\n";
    return -1;
  }
}

double x1_dt(double _x1)
{
  double p3 = get_p3(_x1);
  double p2 = get_p2(_x1, p3);
  double x2 = get_x2(_x1, p3);
  double x3 = get_x3(_x1);
  return p1 - (p2 + 1) * _x1 + _x1 * _x1 * x2 + p3 * (x3 - _x1);
}

double x2_dt(double _x1)
{
  double p3 = get_p3(_x1);
  double p4 = get_p4(p3);
  double p2 = get_p2(_x1, p3);
  double x2 = get_x2(_x1, p3);
  double x4 = get_x4(_x1, p3);
  return p2 * _x1 - _x1 * _x1 * x2 + p4 * (x4 - x2);
}

double x3_dt(double _x1)
{
  double p3 = get_p3(_x1);
  double p2 = get_p2(_x1, p3);
  double x4 = get_x4(_x1, p3);
  double x3 = get_x3(_x1);
  return p1 - (p2 + 1) * x3 + x3 * x3 * x4 - p3 * (x3 - _x1);
}

double x4_dt(double _x1)
{
  double p3 = get_p3(_x1);
  double p4 = get_p4(p3);
  double p2 = get_p2(_x1, p3);
  double x2 = get_x2(_x1, p3);
  double x4 = get_x4(_x1, p3);
  double x3 = get_x3(_x1);
  return p2 * x3 - x3 * x3 * x4 - p4 * (x4 - x2);
}

double determinant(double _x1)
{
  double p3 = get_p3(_x1);
  double p2 = get_p2(_x1, p3);
  double a1 = get_a1(_x1);
  double b1 = get_b1(_x1);
  double c1 = get_c1(_x1);
  double d1 = get_d1(_x1);
  return (_x1 - p1) * (a1 * p3 * p3 + (b1 + c1 * p2) * p3 + d1);
}

double determinant_dp2(double _x1)
{
  double p3 = get_p3(_x1);
  double p4 = get_p4(p3);
  double p2 = get_p2(_x1, p3);
  double x4 = get_x4(_x1, p3);
  double x3 = get_x3(_x1);

  return 4 * p4 * _x1 * _x1 * x3 * x4 - 2 * p4 * _x1 * _x1 - p4 * x3 * x3 - 2 * p2 * p4 * _x1 * _x1 -
         2 * p3 * p4 * _x1 * _x1 - 2 * p3 * p4 * x3 * x3 - 2 * p3 * _x1 * _x1 * x3 * x3 - 2 * _x1 * _x1 * x3 * x3;
}

double determinant_dp3(double _x1)
{
  double p3 = get_p3(_x1);
  double p4 = get_p4(p3);
  double x3 = get_x3(_x1);
  return (std::pow(_x1, 4) * x3 * x3 + p4 * std::pow(_x1, 4) + p4 * _x1 * _x1 * x3 * x3 -
          p4 * _x1 * x3 * x3 + p4 * x3 * x3 * x3) / _x1 * _x1;
}
