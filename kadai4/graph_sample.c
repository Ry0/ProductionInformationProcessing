/* --------------------------------------------------
 グラフ操作関数ライブラリ：array_graph2015.lib の使用例．
　注意：
　・マクロ定数値は変更してはならない．変更するとライブラリと（おそらく）整合しなくなる．
-------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"

void main(void)
{
	int *g[GRAPH_ITEM_NUM];
	int vs[VERTEX_NUM][VERTEX_PROPERTY];
	int es[EDGE_NUM][EDGE_PROPERTY];
	int cs[CELL_NUM][CELL_PROPERTY];
	char *fname = "graph.dat";
	int vid, v1, v2, eid;

	init_graph(g, vs, es, cs);
	read_data(g, fname);
	printf("Edge Data\n");
	pr_edge_all(g);
	printf("Vertex Data\n");
	pr_vertex_all(g);

	vid = 2;
	printf("V%d接続辺の列挙例\n", vid);
	printf("> [v1側頂点]\n");
	first_v1(g, vid, &v1, &eid);
	while (v1 != ARYGRAPH_NULL) {
	     printf("> 頂点：V%d -> 接続辺：E%d -> v1側頂点番号：%d\n", vid, eid, v1);
	     next_v1(g, vid, &v1, &eid);
	}
	printf("> [v2側頂点]\n");
	first_v2(g, vid, &v2, &eid);
	while (v2 != ARYGRAPH_NULL) {
	     printf("> 頂点：V%d -> 接続辺：E%d -> v2側頂点番号：%d\n", vid, eid, v2);
	     next_v2(g, vid, &v2, &eid);
	}

}

/* ********** end of include_sample.c ********** */
