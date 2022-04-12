#ifndef RGR_DATA_HPP
#define RGR_DATA_HPP

double get_p2(double _x1, double _p3);
double get_p3(double _x1);
double get_p4(double _p3);

double get_x2(double _x1,double _p3);
double get_x3(double _x1);
double get_x4(double _x1, double _p3);

double get_a1(double _x1);
double get_b1(double _x1);
double get_c1(double _x1);
double get_d1(double _x1);

double get_a2(double _x1);
double get_b2(double _x1);
double get_c2(double _x1);
double get_d2(double _x1);

double x1_dt(double _x1);
double x2_dt(double _x1);
double x3_dt(double _x1);
double x4_dt(double _x1);

double determinant(double _x1);

double determinant_dp2(double _x1);
double determinant_dp3(double _x1);

#endif
