#include "kadai4.h"

int calc_tEj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid){
	int v1 = 0;  // �ŏ��̕ӂŐڑ����Ă���uv1�v���̒��_�ԍ�
	int eid = 0; // edge��id�ۑ��p 
	int max = 0; // �ő���������
	int tmp = 0; // �ő����������̌v�Z�p

	// �w�肵�����_�ɐڑ�����Ӄ��X�g(g, vid)�̍ŏ��̕ӂƂ��̕ӂ́uv1�v�����_��Ԃ��D
	first_v1(g, vid, &v1, &eid);
	while (1) {
		if (v1 == ARYGRAPH_NULL){
			#ifdef debug
			printf("�T�����_���Ȃ��Ȃ�܂����A�I��\n");
			#endif	
			break;
		} else if (v1 == vid){
			#ifdef debug
			printf("v1���̒��_�ԍ��ƈ����łƂ������_�ԍ�����v�A����\n", vid, eid, v1);
			printf("> ���_�FV%d -> �ڑ��ӁFE%d -> v1�����_�ԍ��F%d\n", vid, eid, v1);
			#endif	
			next_v1(g, vid, &v1, &eid);
		} else {
			tmp = vs[v1][4] + get_label_edge(es[eid]);
			if (max < tmp){
				max = tmp;
			}
			next_v1(g, vid, &v1, &eid);
		}
	}
	return max;
}


void calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){
	vs[0][4] = 0;

	printf("�ő������_����\n");
	for (int vid = 1; vid <= task_num; vid++){
		vs[vid][4] = calc_tEj(g, vs, es, vid);
		printf("tE%d = %d\n", vid, vs[vid][4]);
	}
	printf("\n");
}

int calc_tLi(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid){
	int v2 = 0;  // �ŏ��̕ӂŐڑ����Ă���uv2�v���̒��_�ԍ�
	int eid = 0; // edge��id�ۑ��p 
	int min = 1000000; // �Œx��������
	int tmp = 0; // �Œx���������̌v�Z�p

	// �w�肵�����_�ɐڑ�����Ӄ��X�g(g, vid)�̍ŏ��̕ӂƂ��̕ӂ́uv2�v�����_��Ԃ��D
	first_v2(g, vid, &v2, &eid);
	while (1) {
		if (v2 == ARYGRAPH_NULL){
			// min�̍X�V���Ȃ������灨tL5�̂Ƃ��͏����������Ƃ��̂�ɖ߂��Ă��
			if (min == 1000000){
				min = vs[vid][5];
			}
			#ifdef debug
			printf("�T�����_���Ȃ��Ȃ�܂����A�I��\n");
			#endif	
			break;
		} else if (v2 == vid){
			#ifdef debug
			printf("v2���̒��_�ԍ��ƈ����łƂ������_�ԍ�����v�A����\n", vid, eid, v2);
			printf("> ���_�FV%d -> �ڑ��ӁFE%d -> v2�����_�ԍ��F%d\n", vid, eid, v2);
			#endif	
			next_v2(g, vid, &v2, &eid);
		} else {
			tmp = vs[v2][5] - get_label_edge(es[eid]);
			#ifdef debug
			printf("%d - %d = %d\n", vs[v2][5], get_label_edge(es[eid]), tmp);
			#endif	
			if (min > tmp){
				min = tmp;
			}
			next_v2(g, vid, &v2, &eid);
		}
	}
	return min;
}


void calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){
	// �\��H���̏����l���(calc_earliest_node_times���ŏ��Ɏ��s���Ȃ���΂Ȃ�Ȃ�)
	vs[task_num][5] = vs[task_num][4];

	printf("�Œx�����_����\n");
	for (int vid = task_num; 0 < vid; vid--){
		vs[vid][5] = calc_tLi(g, vs, es, vid);
	}
	for (int vid = 1; vid <= task_num; vid++){
		printf("tL%d = %d\n", vid, vs[vid][5]);
	}
	printf("\n");
}


void trace_critical_path(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){
	// �J�n���_�ԍ��Fi��1�Ƃ���D
	int i = 1;

	// ��Ɨ��ۑ����郊�X�g�FP��{}(��ɂ���)�Ƃ���
	// ����task_num�ɂ���ă��X�gP�𓮓I�m��
	int *p;
	p = (int*)malloc((task_num+1)*sizeof(int));
	for (int i = 0; i < task_num+1; i++){
		p[i] = -1;
	}
	// �J�n�n�_�͕K�{�Ȃ̂ŏ����l�Ƃ��đ��
	p[1] = 1;

	int v2, eid;
	while(1){
		first_v2(g, p[i], &v2, &eid);

		while (1){
			if (v2 == ARYGRAPH_NULL){
				break;
			} else if (v2 == p[i]){
				next_v2(g, p[i], &v2, &eid);
			} else {
				// tLj��tEi+tij���r����
				int tEi = vs[p[i]][4];
				int tLj = vs[v2][5];
				int tij = get_label_edge(es[eid]);
				// ������v������...
				if (tLj == (tEi + tij)){
					// ���X�gP�̖�����v_i��ǉ�
					p[i+1] = v2;
					break;
				}
				next_v1(g, p[i], &v2, &eid);
			}
		}

		// vj���Ȃ���ΏI���D
		if (p[i + 1] == task_num){
			break;
		}

		i++;
	}

	printf("�N���e�B�J���p�X\n");
	printf("%d", p[1]);
	for (int j = 2; j <= i + 1; j++){
		printf(" -> ");
		printf("%d", p[j]);
	}
	printf("\n");

	// ���I�m�ۂ����z��p�̃��������
	free(p);
}