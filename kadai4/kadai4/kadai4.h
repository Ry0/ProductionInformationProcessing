#ifndef _KADAI4_DEF_
#define _KADAI4_DEF_

#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"

/*
g(O) �O���t�f�[�^���܂Ƃ߂��z��D
vs(I) �O���t���_�p�z��D
es(I) �O���t�ӗp�z��D
cs(I) �O���t�Ӄ��X�g�p���X�g�Z���z��D */

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

int calc_tj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int eid);

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int eid){
}


#endif