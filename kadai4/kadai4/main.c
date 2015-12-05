#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"
#include "kadai4.h"

void main(void)
{
	int *g[GRAPH_ITEM_NUM];
	int vs[VERTEX_NUM][VERTEX_PROPERTY];
	int es[EDGE_NUM][EDGE_PROPERTY];
	int cs[CELL_NUM][CELL_PROPERTY];
	char *fname = "graph_kadai4.dat";

	init_graph(g, vs, es, cs);
	read_data(g, fname);
	printf("Edge Data\n");
	pr_edge_all(g);
	printf("Vertex Data\n");
	pr_vertex_all(g);
	printf("\n");

	// 最早結合点時刻
	calc_earliest_node_times(g, vs, es, cs, 8);
	// 最遅結合点時刻
	calc_latest_node_times(g, vs, es, cs, 8);
	//クリティカルパスを求める
	trace_critical_path(g, vs, es, cs, 8);

	system("pause");
}
