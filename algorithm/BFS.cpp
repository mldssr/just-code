// https://blog.csdn.net/jnu_simba/article/details/8868235

#include <queue>
using namespace std;

// 邻接矩阵
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9

typedef struct {
    VertexType vexs[MAXVEX];      /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵，可看作边表 */
    int numVertexes, numEdges;    /* 图中当前的顶点数和边数 */
} MGraph;

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G) {
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++) visited[i] = false;
    InitQueue(&Q); /* 初始化一辅助用的队列 */

    for (i = 0; i < G.numVertexes; i++) /* 对每一个顶点做循环 */
    {
        if (!visited[i]) /* 若是未访问过就处理 */
        {
            visited[i] = true;        /* 设置当前顶点访问过 */
            cout << G.vexs[i] << ' '; /* 打印顶点，也可以其它操作 */
            EnQueue(&Q, i);           /* 将此顶点入队列 */
            while (!QueueEmpty(Q))    /* 若当前队列不为空 */
            {
                DeQueue(&Q, &i); /* 将队对元素出队列，赋值给i */
                for (j = 0; j < G.numVertexes; j++) {
                    /* 判断其它顶点若与当前顶点存在边且未访问过  */
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = true; /* 将找到的此顶点标记为已访问 */
                        cout << G.vexs[j] << ' '; /* 打印顶点 */
                        EnQueue(&Q, j); /* 将找到的此顶点入队列  */
                    }
                }
            }
        }
    }
}

// 邻接表
typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点 */
{
    int adjvex; /* 邻接点域,存储该顶点对应的下标 */
    int weight; /* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode *next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
    int in;              //结点入度
    char data;           /* 顶点域,存储顶点信息 */
    EdgeNode *firstedge; /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges; /* 图中当前顶点数和边数 */
} graphAdjList, *GraphAdjList;

/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL) {
    int i, j;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++) visited[i] = false;
    InitQueue(&Q); /* 初始化一辅助用的队列 */

    for (i = 0; i < GL->numVertexes; i++) /* 对每一个顶点做循环 */
    {
        if (!visited[i]) /* 若是未访问过就处理 */
        {
            visited[i] = true; /* 设置当前顶点访问过 */
            cout << GL->adjList[i].data << ' '; /* 打印顶点，也可以其它操作 */
            EnQueue(&Q, i);                     /* 将此顶点入队列 */
            while (!QueueEmpty(Q))              /* 若当前队列不为空 */
            {
                DeQueue(&Q, &i); /* 将队对元素出队列，赋值给i */
                p = GL->adjList[i].firstedge; /* 找到当前顶点的边表链表头指针 */

                while (p) {
                    /* 判断其它顶点若与当前顶点存在边且未访问过  */
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] =
                            true; /* 将找到的此顶点标记为已访问 */
                        cout << GL->adjList[p->adjvex].data
                             << ' ';            /* 打印顶点 */
                        EnQueue(&Q, p->adjvex); /* 将找到的此顶点入队列  */
                    }
                    p = p->next; /* 指针指向下一个邻接点 */
                }
            }
        }
    }
}