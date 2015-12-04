#ifndef _KADAI4_DEF_
#define _KADAI4_DEF_

#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"

/*
g(O) グラフデータをまとめた配列．
vs(I) グラフ頂点用配列．
es(I) グラフ辺用配列．
cs(I) グラフ辺リスト用リストセル配列． */

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

int calc_tj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int eid);

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int eid){
}


#endif