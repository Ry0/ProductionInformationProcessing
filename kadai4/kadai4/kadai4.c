#include "kadai4.h"

int calc_tEj(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid){
	int v1 = 0;  // 最初の辺で接続している「v1」側の頂点番号
	int eid = 0; // edgeのid保存用 
	int max = 0; // 最早結合時刻
	int tmp = 0; // 最早結合時刻の計算用

	// 指定した頂点に接続する辺リスト(g, vid)の最初の辺とその辺の「v1」側頂点を返す．
	first_v1(g, vid, &v1, &eid);
	while (1) {
		if (v1 == ARYGRAPH_NULL){
			#ifdef debug
			printf("探す頂点がなくなりました、終了\n");
			#endif	
			break;
		} else if (v1 == vid){
			#ifdef debug
			printf("v1側の頂点番号と引数でとった頂点番号が一致、次へ\n", vid, eid, v1);
			printf("> 頂点：V%d -> 接続辺：E%d -> v1側頂点番号：%d\n", vid, eid, v1);
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

	printf("最早結合点時刻\n");
	for (int vid = 1; vid <= task_num; vid++){
		vs[vid][4] = calc_tEj(g, vs, es, vid);
		printf("tE%d = %d\n", vid, vs[vid][4]);
	}
	printf("\n");
}

int calc_tLi(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int vid){
	int v2 = 0;  // 最初の辺で接続している「v2」側の頂点番号
	int eid = 0; // edgeのid保存用 
	int min = 1000000; // 最遅結合時刻
	int tmp = 0; // 最遅結合時刻の計算用

	// 指定した頂点に接続する辺リスト(g, vid)の最初の辺とその辺の「v2」側頂点を返す．
	first_v2(g, vid, &v2, &eid);
	while (1) {
		if (v2 == ARYGRAPH_NULL){
			// minの更新がなかったら→tL5のときは初期化したときのやつに戻してやる
			if (min == 1000000){
				min = vs[vid][5];
			}
			#ifdef debug
			printf("探す頂点がなくなりました、終了\n");
			#endif	
			break;
		} else if (v2 == vid){
			#ifdef debug
			printf("v2側の頂点番号と引数でとった頂点番号が一致、次へ\n", vid, eid, v2);
			printf("> 頂点：V%d -> 接続辺：E%d -> v2側頂点番号：%d\n", vid, eid, v2);
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
	// 予定工期の初期値代入(calc_earliest_node_timesを最初に実行しなければならない)
	vs[task_num][5] = vs[task_num][4];

	printf("最遅結合点時刻\n");
	for (int vid = task_num; 0 < vid; vid--){
		vs[vid][5] = calc_tLi(g, vs, es, vid);
	}
	for (int vid = 1; vid <= task_num; vid++){
		printf("tL%d = %d\n", vid, vs[vid][5]);
	}
	printf("\n");
}


void trace_critical_path(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY], int task_num){
	// 開始頂点番号：i←1とする．
	int i = 1;

	// 作業列を保存するリスト：P←{}(空にする)とする
	// 引数task_numによってリストPを動的確保
	int *p;
	p = (int*)malloc((task_num+1)*sizeof(int));
	for (int i = 0; i < task_num+1; i++){
		p[i] = -1;
	}
	// 開始地点は必須なので初期値として代入
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
				// tLjとtEi+tijを比較する
				int tEi = vs[p[i]][4];
				int tLj = vs[v2][5];
				int tij = get_label_edge(es[eid]);
				// もし一致したら...
				if (tLj == (tEi + tij)){
					// リストPの末尾にv_iを追加
					p[i+1] = v2;
					break;
				}
				next_v1(g, p[i], &v2, &eid);
			}
		}

		// vjがなければ終了．
		if (p[i + 1] == task_num){
			break;
		}

		i++;
	}

	printf("クリティカルパス\n");
	printf("%d", p[1]);
	for (int j = 2; j <= i + 1; j++){
		printf(" -> ");
		printf("%d", p[j]);
	}
	printf("\n");

	// 動的確保した配列pのメモリ解放
	free(p);
}