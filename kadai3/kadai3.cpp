#include "kadai3.h"

#include <iostream>
using namespace std;

void set_param_vector(double pv[BDIM+1], double t){
	for (int i = 0; i < 4; ++i){
		pv[i] = pow(t, i);
	}

	#ifdef DEBUG
	printVec(pv);
	#endif
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
	printVec(u);
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
	printVec(u);
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
	FILE *fp1, *fp2, *plotfp;

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
		for (double i = 0; i < 1.01; i+=0.01){
			on_bezier3_curve(q, m, p, i);
			fprintf(fp2, "%lf %lf %lf\n", q[0], q[1], q[2]);
		}
		fclose(fp2);
	}

	if((plotfp = fopen("../plot/plot.plt", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		fprintf(plotfp, "reset\n");
		fprintf(plotfp, "set xlabel \'x\'\n");
		fprintf(plotfp, "set ylabel \'y\'\n");
		fprintf(plotfp, "set zlabel \'z\'\n");
		fprintf(plotfp, "set xrange[-10:10]\n");
		fprintf(plotfp, "set yrange[-10:10]\n");
		fprintf(plotfp, "set zrange[-10:10]\n");
		fprintf(plotfp, "set view equal xyz\n");
		fprintf(plotfp, "set ticslevel 0\n");
		fprintf(plotfp, "splot \'point.dat\' using 1:2:3 with points pt 7 ps 2 lt rgb \"#ff9900\" title \'Point\',\\\n");
		fprintf(plotfp, "\'data.dat\' using 1:2:3 with lines lt 1 lc rgb \"#EA2525\" lw 5 title \'Bezier\'\n");
		fclose(plotfp);
	}
}

void InputDatFile(double p[BDIM+1][BDIM+1][HDIM], char *fname){
	FILE *fp, *fp1;
	int u,v;
	double point[3]={0.0};

	fp = fopen( fname, "r" );
	if( fp == NULL ){
		printf( "%sのファイルが開けません\n", fname);
	}else{
		for (int i = 0; i < 16; ++i){
			if (fscanf(fp, "%d %d %lf %lf %lf", &u, &v, &point[0], &point[1], &point[2])){
				for (int i = 0; i < 3; ++i){
					p[u][v][i] = point[i];
				}
				p[u][v][3] = 1;
			}
		}
		fclose(fp);
	}


	if((fp1 = fopen("../plot/point.dat", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		for (int u = 0; u < BDIM+1; ++u){
			for (int v = 0; v < BDIM+1; ++v){
					fprintf(fp1, "%lf %lf %lf\n", p[u][v][0], p[u][v][1], p[u][v][2]);
			}
		}
		fclose(fp1);
	}

	#ifdef DEBUG
	for (int u = 0; u < BDIM+1; ++u){
		for (int v = 0; v < BDIM+1; ++v){
				printf("(u, v) = (%d, %d), (x, y, z, 1) = (%lf, %lf, %lf, %lf)\n", u, v, p[u][v][0], p[u][v][1], p[u][v][2], p[u][v][3]);
		}
	}
	#endif
}

void mulMCpVb(double lcp[BDIM+1][HDIM], double mcp[BDIM+1][BDIM+1][HDIM], double v[BDIM+1]){
	zeroMat4h(lcp);
	for (int i = 0; i< BDIM+1; ++i) {
		for (int j = 0; j < BDIM+1; ++j) {
			for(int k = 0; k < HDIM-1; ++k){
				lcp[i][k] += mcp[i][j][k] * v[j];
			}
		}
	}
}

void on_bezier3_surface(double q[HDIM], double mb[BDIM+1][BDIM+1], double cps[BDIM+1][BDIM+1][HDIM], double u, double v){
	double vec_u[BDIM+1], vec_v[BDIM+1];
	set_param_vector(vec_u, u);
	set_param_vector(vec_v, v);

	double MPM[BDIM+1][BDIM+1][HDIM];
	double MPMv[BDIM+1][HDIM];
	calc_M_tPM(MPM, cps, mb);
	mulMCpVb(MPMv, MPM, vec_v);

	mulLCpVb(q, MPMv, vec_u);
}

void calc_M_tPM(double output[BDIM+1][BDIM+1][HDIM], double input[BDIM+1][BDIM+1][HDIM], double M[BDIM+1][BDIM+1]){
	double trM[BDIM+1][BDIM+1];
	double tmpoutput[BDIM+1][BDIM+1][HDIM];
	transposedMat4h(trM, M);
	// 出力用行列初期化
	for (int u = 0; u < BDIM+1; ++u){
		for (int v = 0; v < BDIM+1; ++v){
			for (int xyz = 0; xyz < BDIM+1; ++xyz){
				output[u][v][xyz] = 0.0;
				tmpoutput[u][v][xyz] = 0.0;
			}
		}
	}

	// P * M_B
	for (int i = 0; i< BDIM+1; ++i) {
		for (int j = 0; j < BDIM+1; ++j) {
			for (int k = 0; k < BDIM+1; ++k) {
				for (int l = 0; l < HDIM-1; ++l) {
					tmpoutput[i][j][l] += input[i][k][l] * M[k][j];
				}
				tmpoutput[i][j][3] = 1.0;
			}
		}
	}
	// M_B^T * P * M_B
	for (int i = 0; i< BDIM+1; ++i) {
		for (int j = 0; j < BDIM+1; ++j) {
			for (int k = 0; k < BDIM+1; ++k) {
				for (int l = 0; l < HDIM-1; ++l) {
					output[i][j][l] += trM[i][k] * tmpoutput[k][j][l];
				}
				output[i][j][3] = 1.0;
			}
		}
	}
	#ifdef DEBUG
	for (int u = 0; u < BDIM+1; ++u){
		for (int v = 0; v < BDIM+1; ++v){
				printf("(u, v) = (%d, %d), (x, y, z, 1) = (%lf, %lf, %lf, %lf)\n", u, v, output[u][v][0], output[u][v][1], output[u][v][2], output[u][v][3]);
		}
	}
	#endif
}

void draw_bezier3_surface(){
	double m[HDIM][BDIM+1] = {{1,-3,3,-1}, {0,3,-6,3}, {0,0,3,-3}, {0,0,0,1}};
	double q[HDIM];
	FILE *data, *plotfp;

	double input[BDIM+1][BDIM+1][HDIM];
  InputDatFile(input, (char*)"../plot/InputPoint.dat");

	if((data = fopen("../plot/surfacedata.dat", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		for (double u = 0; u < 1.05; u+=0.05){
			for (double v = 0; v < 1.05; v+=0.05){
				on_bezier3_surface(q, m, input, u, v);
				fprintf(data, "%lf %lf %lf\n", q[0], q[1], q[2]);
			}
			fprintf(data, "\n\n\n");
		}

		for (double v = 0; v < 1.05; v+=0.05){
			for (double u = 0; u < 1.05; u+=0.05){
				on_bezier3_surface(q, m, input, u, v);
				fprintf(data, "%lf %lf %lf\n", q[0], q[1], q[2]);
			}
			fprintf(data, "\n\n\n");
		}

	}
	fclose(data);

	if((plotfp = fopen("../plot/plot.plt", "w"))==NULL){
		printf("ファイルをオープンできません\n");
	} else {
		fprintf(plotfp, "reset\n");
		fprintf(plotfp, "set xlabel \'x\'\n");
		fprintf(plotfp, "set ylabel \'y\'\n");
		fprintf(plotfp, "set zlabel \'z\'\n");
		fprintf(plotfp, "set xrange[0:10]\n");
		fprintf(plotfp, "set yrange[0:10]\n");
		fprintf(plotfp, "set zrange[-7:7]\n");
		fprintf(plotfp, "set view equal xyz\n");
		fprintf(plotfp, "set ticslevel 0\n");
		fprintf(plotfp, "set cbrange[-2:2]\n");
		fprintf(plotfp, "splot \'point.dat\' using 1:2:3 with points pt 7 ps 1 lt rgb \"#ff9900\" title \'Point\',\\\n");
		// fprintf(plotfp, "\'data.dat\' using 1:2:3 with lines lt 1 lc rgb \"#EA2525\" lw 1 title \'Bezier\'\n");
		fprintf(plotfp, "\'surfacedata.dat\' using 1:2:3 with lines lt 1 lc palette lw 2 title \'Bezier\'\n");
		fclose(plotfp);
	}
}

int OpenGnuplot(){
  FILE *fp = popen("cd ../plot && gnuplot -persist", "w");
  if (fp == NULL) {
    return -1;
  }
  fputs("set mouse\n", fp);
  fputs("load \"plot.plt\"\n", fp);

  fflush(fp);
  pclose(fp);
  return 0;
}