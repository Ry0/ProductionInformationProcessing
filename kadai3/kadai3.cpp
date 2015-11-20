#include "kadai3.h"

#include <iostream>
using namespace std;

void set_param_vector(double pv[BDIM+1], double t){
	for (int i = 0; i < 4; ++i){
		pv[i] = pow(t, i);
		cout << pv[i] << endl;
	}
}

void mulMVb(double u[BDIM+1], double mb[BDIM+1][BDIM+1], double v[BDIM+1]){
	for (int i = 0; i < BDIM+1; ++i){
		u[i] = 0.0;
	}
	for (int i = 0; i< BDIM+1; ++i) {
		for (int j = 0; j < BDIM+1; ++j) {
			u[i] += mb[i][j] * v[j];
		}
	}

	#ifdef DEBUG
	printf("Vec = \n");
	for (int i = 0; i < BDIM+1; ++i) {
		printf("%lf\n", u[i]);
	}
	#endif
}

void mulLCpVb(double u[HDIM], double cps[HDIM][BDIM+1], double v[BDIM+1]){
	double calc_tmp[HDIM][BDIM+1];

	for (int i = 0; i < HDIM; ++i){
		u[i] = 0.0;
	}

	for (int i = 0; i < HDIM; ++i){
		for (int j = 0; j < HDIM-1; ++j){
			calc_tmp[i][j] = cps[i][j] * v[i];
		}
		calc_tmp[i][HDIM-1] = 1;
	}

	for (int i = 0; i < HDIM; ++i){
		for (int j = 0; j < HDIM-1; ++j)
		{
			u[j] += calc_tmp[i][j];
		}
	}
	u[3] = 1;
	#ifdef DEBUG
	printf("Vec = \n");
	for (int i = 0; i < BDIM+1; ++i) {
		printf("%lf\n", u[i]);
	}
	#endif
}

void on_bezier3_curve(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][HDIM], double t){
	double vec_t[BDIM+1];
	set_param_vector(vec_t, t);

	double vec_M[BDIM+1];
	mulMVb(vec_M, mb, vec_t);

	mulLCpVb(q, cps, vec_M);
}

void draw_bezier3(){
  double m[HDIM][BDIM+1] = {{1,-3,3,-1}, {0,3,-6,3}, {0,0,3,-3}, {0,0,0,1}};
	double p[HDIM][HDIM] = {{1,3,5,1}, {3,-3,6,1}, {6,6,-3,1}, {8,3,-1,1}};
	double q[HDIM];
	FILE *fp1, *fp2;

	if((fp1 = fopen("../plot/point.dat", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		for (int i = 0; i < BDIM+1; i++){
			fprintf(fp1, "%lf %lf %lf\n", p[i][0], p[i][1], p[i][2]);
		}
		fclose(fp1);
	}

	if((fp2 = fopen("../plot/data.dat", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		for (double i = 0; i <= 1; i+=0.01){
			on_bezier3_curve(q, m, p, i);
			fprintf(fp2, "%lf %lf %lf\n", q[0], q[1], q[2]);
		}
		fclose(fp2);
	}
}

// reset
// set xlabel 'x'
// set ylabel 'y'
// set zlabel 'z'
// set xrange[-10:10]
// set yrange[-10:10]
// set zrange[-10:10]
// set view equal xyz
// set ticslevel 0
// splot 'point.dat' using 1:2:3 with points pt 7 ps 2 lt rgb "#ff9900" title 'Point',\
// 'data.dat' using 1:2:3 with lines lt 1 lc rgb "#EA2525" lw 5 title 'Bezier'