#ifndef _KADAI4_DEF_
#define _KADAI4_DEF_

#include <stdio.h>
#include <stdlib.h>
#include "array_graph.h"

// #define debug //�f�o�b�O�p��printf

// �C�ӂ̒n�_�ł̍ő������_���������߂�
int calc_tEj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int vid);
// ���ׂĂ̒n�_�ł̍ő������_��������ʏo�͂���
void calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

// �C�ӂ̒n�_�ł̍Œx�����_���������߂�
int calc_tLi(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid);
// ���ׂĂ̒n�_�ł̍Œx�����_��������ʏo�͂���
void calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);

// �N���e�B�J���p�X�����߂�
void trace_critical_path(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num);
#endif