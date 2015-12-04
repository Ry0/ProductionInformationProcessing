#include "kadai4.h"

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){

}

int calc_tj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int vid){
	int v1 = 0;  // 最初の辺で接続している「v1」側の頂点番号
	int eid = 0; // edgeのid保存用 
	int max = 0; // 最早結合時刻
	int tmp = 0; // 最早結合時刻の計算用

	//指定した頂点に接続する辺リスト(g, vid)の最初の辺とその辺の「v1」側頂点を返す．
	first_v1(g, vid, &v1, &eid);
	while (1) {
		if (v1 != ARYGRAPH_NULL){
			break;
		} else if (v1 = vid){
			printf("v1側の頂点番号と引数でとった頂点番号が一致、次へ\n", vid, eid, v1);
			printf("> 頂点：V%d -> 接続辺：E%d -> v1側頂点番号：%d\n", vid, eid, v1);
			next_v1(g, vid, &v1, &eid);
		} else {
			tmp = vs[v1][4] + get_label_edge(es[eid]);
			if (max < tmp){
				max = tmp;
			}
			next_v1(g, vid, &v1, &eid);
		}
		return max;
	}

}


int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int eid){

}