#include "kadai4.h"

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){

}

int calc_tj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int vid){
	int v1 = 0;  // �ŏ��̕ӂŐڑ����Ă���uv1�v���̒��_�ԍ�
	int eid = 0; // edge��id�ۑ��p 
	int max = 0; // �ő���������
	int tmp = 0; // �ő����������̌v�Z�p

	//�w�肵�����_�ɐڑ�����Ӄ��X�g(g, vid)�̍ŏ��̕ӂƂ��̕ӂ́uv1�v�����_��Ԃ��D
	first_v1(g, vid, &v1, &eid);
	while (1) {
		if (v1 != ARYGRAPH_NULL){
			break;
		} else if (v1 = vid){
			printf("v1���̒��_�ԍ��ƈ����łƂ������_�ԍ�����v�A����\n", vid, eid, v1);
			printf("> ���_�FV%d -> �ڑ��ӁFE%d -> v1�����_�ԍ��F%d\n", vid, eid, v1);
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