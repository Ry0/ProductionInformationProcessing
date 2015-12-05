#ifndef _KADAI4_DEF_
#define _KADAI4_DEF_

#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"

// #define debug //デバッグ用のprintf

// 任意の地点での最早結合点時刻を求める
int calc_tEj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int vid);
// すべての地点での最早結合点時刻を画面出力する
void calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

// 任意の地点での最遅結合点時刻を求める
int calc_tLi(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid);
// すべての地点での最遅結合点時刻を画面出力する
void calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

// クリティカルパスを求める
void trace_critical_path(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);
#endif