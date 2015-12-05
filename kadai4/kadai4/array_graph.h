/* --------------------------------------------------
 グラフ操作関数：配列による実装例
　注意：数値は全て整数でなければならない．

 各グラフ要素を表す１次元配列の内容
　頂点の属性：0:接続辺数，1:先頭リストセル，2:末尾リストセル，3:一時リストセル，4-:ラベル用数値(複数個も可能)．
　辺　の属性：0:頂点番号１，1:頂点番号２，2:ラベル用数値．
　セルの属性：0:辺番号，1:次セル番号．

 グラフデータファイルの書式
　(1)接続辺の情報だけをタブ区切りで列挙する．
　(2)データ行の書式：<v1側頂点番号><タブ><v2側頂点番号><タブ><辺ラベル>
　(3)「v1」「v2」の意味は使用者が決める．対等に扱えば無向辺になり，どちらかを「始点」として扱えば有向辺になる．
-------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_ITEM_NUM 3    /* グラフを構成する配列の個数．*/
#define VERTEX_LABEL_NUM 2  /* 頂点のラベル個数．１以上でなければならない．*/
#define VERTEX_PROPERTY (4 + VERTEX_LABEL_NUM) /* 頂点の属性数 */
#define EDGE_PROPERTY 3     /* 辺の属性数 */
#define CELL_PROPERTY 3     /* リストセルの属性数 */
#define ARYGRAPH_NULL (-1)  /* NULLを表す数値．負の整数でなければならない．*/

#define VERTEX_NUM 10          /* 頂点総数 */
#define EDGE_NUM 100           /* 辺総数-1 */
#define CELL_NUM (2 * EDGE_NUM)  /* リストセル総数-1 */
#define LINE_LENGTH 300        /* グラフデータファイルの１行の文字数 */


/* ---------------------------------------------------------------------- データファイルの操作 */
/* グラフ用データファイルを読み込み，グラフを表す各配列にデータを設定する．
g (O) グラフデータをまとめた配列．init_graphで初期化済みでなければならない．
fname (I) 適切なパスを含むデータファイル名． */
void read_data(int *g[GRAPH_ITEM_NUM], char *fname);


/* ---------------------------------------------------------------------- グラフ全体の操作 */
/* グラフを表す配列を初期設定する．配列要素の初期化も行うため，使用前に必ず実行しなければならない．
g (O) グラフデータをまとめた配列．
vs (I) グラフ頂点用配列．
es (I) グラフ辺用配列．
cs (I) グラフ辺リスト用リストセル配列． */
void init_graph(int *g[GRAPH_ITEM_NUM], int vs[][VERTEX_PROPERTY], int es[][EDGE_PROPERTY], int cs[][CELL_PROPERTY]);

/* 指定した辺の属性を表示する．
 e (I) 辺情報を格納する１次元配列．*/
void pr_edge(int e[EDGE_PROPERTY]);

/* 生成済みの全ての辺について各属性を表示する．
 es (I) 辺情報を格納する配列．*/
void pr_edge_all(int *g[GRAPH_ITEM_NUM]);


/* ---------------------------------------------------------------------- グラフ頂点の操作 */
/* グラフをまとめた配列から指定した頂点番号のグラフ頂点を得る．
 g (I) グラフデータをまとめた配列．
 vid (I) 頂点番号．自然数でなければならない．
 (R) グラフ頂点を表す１次元配列．*/
int *g2v(int *g[GRAPH_ITEM_NUM], int vid);

/* 指定した頂点に接続する辺リストの最初の辺とその辺の「v1」側頂点を返す．
　頂点に接続する辺を列挙する時に，最初に実行しなければならない．
 g (I) グラフデータをまとめた配列．
 vid (I) 頂点番号．自然数でなければならない．
 v1 (O) 最初の辺で接続している「v1」側の頂点番号．
 eid (O) 最初の辺番号． */
void first_v1(int *g[GRAPH_ITEM_NUM], int vid, int *v1, int *eid);

/* 指定した頂点に接続する辺リストの最初の辺とその辺の「v2」側頂点を返す．
　頂点に接続する辺を列挙する時に，最初に実行しなければならない．
 g (I) グラフデータをまとめた配列．
 vid (I) 頂点番号．自然数でなければならない．
 v2 (O) 最初の辺で接続している「v2」側の頂点番号．
 eid (O) 最初の辺番号． */
void first_v2(int *g[GRAPH_ITEM_NUM], int vid, int *v2, int *eid);

/* 指定した頂点に接続する辺リストの列挙済みの辺の次の辺とその辺の「v1」側頂点を返す．
　繰り返し実行すれば，接続する辺を全て列挙することができる．
　ただし，最初に１回だけ「first_v1」を実行しなければならない．
 g (I) グラフデータをまとめた配列．
 vid (I) 頂点番号．自然数でなければならない．
 v1 (O) 次の辺で接続している「v1」側の頂点番号．存在しない場合は「ARYGRAPH_NULL」を返す．
 eid (O) 次の辺番号．存在しない場合は「ARYGRAPH_NULL」を返す． */
void next_v1(int *g[GRAPH_ITEM_NUM], int vid, int *v1, int *eid);

/* 指定した頂点に接続する辺リストの列挙済みの辺の次の辺とその辺の「v2」側頂点を返す．
　繰り返し実行すれば，接続する辺を全て列挙することができる．
　ただし，最初に１回だけ「first_v2」を実行しなければならない．
 g (I) グラフデータをまとめた配列．
 vid (I) 頂点番号．自然数でなければならない．
 v2 (O) 次の辺で接続している「v2」側の頂点番号．存在しない場合は「ARYGRAPH_NULL」を返す．
 eid (O) 次の辺番号．存在しない場合は「ARYGRAPH_NULL」を返す． */
void next_v2(int *g[GRAPH_ITEM_NUM], int vid, int *v2, int *eid);

/* 指定した頂点の属性を表示する．
 v (I) 頂点情報を格納する１次元配列．
 cs (I) 辺リストセル情報を格納する配列．
 es (I) 辺情報を格納する配列．*/
void pr_vertex(int *g[GRAPH_ITEM_NUM], int vid);

/* 接続辺を持つ頂点について各属性を表示する．
 vs (I) 頂点情報を格納する配列．
 cs (I) 辺リストセル情報を格納する配列．
 es (I) 辺情報を格納する配列．*/
void pr_vertex_all(int *g[GRAPH_ITEM_NUM]);


/* ---------------------------------------------------------------------- グラフ辺の操作 */
/* グラフをまとめた配列から指定した辺番号のグラフ辺を得る．
 g (I) グラフデータをまとめた配列．
 eid (I) 辺番号．自然数でなければならない．
 (R) グラフ辺を表す１次元配列．*/
int *g2e(int *g[GRAPH_ITEM_NUM], int eid);

/* 指定した辺のラベル用数値を返す．
 e (I) 辺情報を格納する１次元配列．
 (R) ラベル用数値．*/
int get_label_edge(int e[EDGE_PROPERTY]);

/* 指定した頂点にn番目のラベル用数値を設定する．
 v (O) 頂点情報を格納する１次元配列．
 n (I) 設定するラベル番号．０以上の正の整数でなければならない．
 label (I) ラベル用数値．*/
void set_nth_label_vertex(int v[VERTEX_PROPERTY], int n, int label);

/* 指定した頂点のn番目のラベル配列を返す．
 v (I) 頂点情報を格納する１次元配列．
 n (I) ラベル番号．０以上の正の整数でなければならない．
 (R) ラベル用数値．*/
int get_nth_label_vertex(int v[VERTEX_PROPERTY], int n);


/* ---------------------------------------------------------------------- 基本操作関数
 以下の関数は使わずに「PERT/CPM」は実装できる．
 ---------------------------------------------------------------------- */
/* -------------------------------------------------- 頂点操作関数 */
/* グラフをまとめた配列からグラフ頂点用配列を得る．
g (I) グラフデータをまとめた配列．
(R) グラフ頂点用配列．*/
int *get_vertexs(int *g[GRAPH_ITEM_NUM]);

/* グラフをまとめた配列からグラフ辺用配列を得る．
g (I) グラフデータをまとめた配列．
(R) グラフ辺用配列．*/
int *get_edges(int *g[GRAPH_ITEM_NUM]);

/* グラフをまとめた配列からグラフ辺リスト用リストセル配列を得る．
g (I) グラフデータをまとめた配列．
(R) グラフ辺リスト用リストセル配列．*/
int *get_cells(int *g[GRAPH_ITEM_NUM]);

/* 指定した頂点の辺リストの要素数を更新する．
 v (O) 頂点情報を格納する１次元配列．*/
void inc_elistlen_vertex(int v[VERTEX_PROPERTY]);

/* 指定した頂点の辺リストの要素数を返す．
 v (I) 頂点情報を格納する１次元配列．
 (R) 辺リストの要素数．*/
int get_elistlen_vertex(int v[VERTEX_PROPERTY]);

/* 指定した頂点の辺リストの先頭リストセルを設定する．
 v (O) 頂点情報を格納する１次元配列．
 cid (I) 先頭リストセル．*/
void set_headcell_vertex(int v[VERTEX_PROPERTY], int cid);

/* 指定した頂点の辺リストの先頭リストセルを返す．
 v (I) 頂点情報を格納する１次元配列．
 (R) 先頭リストセル．*/
int get_headcell_vertex(int v[VERTEX_PROPERTY]);

/* 指定した頂点の辺リストの末尾リストセルを設定する．
 v (O) 頂点情報を格納する１次元配列．
 cid (I) 末尾リストセル．*/
void set_tailcell_vertex(int v[VERTEX_PROPERTY], int cid);

/* 指定した頂点の辺リストの末尾リストセルを返す．
 v (I) 頂点情報を格納する１次元配列．
 (R) 末尾リストセル．*/
int get_tailcell_vertex(int v[VERTEX_PROPERTY]);

/* 指定した頂点にラベル用数値を設定する．
 v (O) 頂点情報を格納する１次元配列．
 label (I) ラベル用数値．*/
void set_label_vertex(int v[VERTEX_PROPERTY], int label);

/* 指定した頂点のラベル用数値を返す．
 v (I) 頂点情報を格納する１次元配列．
 (R) ラベル用数値．*/
int get_label_vertex(int v[VERTEX_PROPERTY]);

/* 指定した頂点の辺リストに辺番号を追加する．
 v (O) 頂点情報を格納する１次元配列．
 cs (O) 辺リストセル情報を格納する配列．
 eid (I) 辺番号．*/
void add_edge_vertex(int *g[GRAPH_ITEM_NUM], int v[VERTEX_PROPERTY], int eid);

/* -------------------------------------------------- 辺操作関数 */
/* 新しい辺番号を返す．
 es (IO) 辺情報を格納する配列．
 (R) 新しい辺番号．*/
int new_edge(int *g[GRAPH_ITEM_NUM]);

/* グラフを構成する辺の総数を返す．
 */
int get_edge_number(int *g[GRAPH_ITEM_NUM]);

/* 辺の属性値を設定する．
 e (O) 辺情報を格納する１次元配列．
 v1, v2 (I) 接続している頂点番号．
 label (I) 辺のラベル用数値． */
void set_edge_property(int e[EDGE_PROPERTY], int v1, int v2, int label);

/* 指定した辺の頂点１を返す．
 e (I) 辺情報を格納する１次元配列．
 (R) 頂点１の頂点番号．*/
int get_v1_edge(int e[EDGE_PROPERTY]);

/* 指定した辺の頂点２を返す．
 e (I) 辺情報を格納する１次元配列．
 (R) 頂点２の頂点番号．*/
int get_v2_edge(int e[EDGE_PROPERTY]);

/* 指定した辺のラベル用数値を返す．
 e (I) 辺情報を格納する１次元配列．
 (R) ラベル用数値．*/
int get_label_edge(int e[EDGE_PROPERTY]);

/* 指定した辺の指定した頂点でないもう一方の頂点を返す．
 e (I) 辺情報を格納する１次元配列．
 vid (I) 頂点番号．
 (R) ラベル用数値．*/
int get_mate_edge(int e[EDGE_PROPERTY], int vid);

/* -------------------------------------------------- リストセル操作関数 */
/* 新しいリストセル番号を返す．
 cs (IO) 辺リストセル情報を格納する配列．
 (R) 新しいリストセル番号．*/
int new_cell(int *g[GRAPH_ITEM_NUM], int eid);

/* グラフをまとめた配列からグラフ辺リスト用リストセル配列を得る．
g (I) グラフデータをまとめた配列．
(R) リストセル用配列．*/
int *g2c(int *g[GRAPH_ITEM_NUM], int cid);

/* 指定したセルに辺番号を設定する．
 c (O) リストセル情報を格納する１次元配列．
 eid (I) 辺番号．*/
void set_edge_cell(int c[CELL_PROPERTY], int eid);

/* 指定したセルに次のリスト要素のセル番号を設定する．
 c (O) リストセル情報を格納する１次元配列．
 nextid (I) 次のセル番号．*/
int get_edge_cell(int c[CELL_PROPERTY]);

/* 指定したセルに次のリスト要素のセル番号を設定する．
 c (O) リストセル情報を格納する１次元配列．
 nextid (I) 次のセル番号．*/
void set_next_cell(int c[CELL_PROPERTY], int nextid);

/* 指定したセルの次のリスト要素のセル番号を返す．
 c (I) リストセル情報を格納する１次元配列．
 (R) 次のセル番号．*/
int get_next_cell(int c[CELL_PROPERTY]);


/* ********** end of array_graph.h ********** */
