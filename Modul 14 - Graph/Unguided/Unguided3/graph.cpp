#include "graph.h"
void CreateGraph(Graph &G) { // membuat graph kosong
    G.first = NULL;
}
adrNode AlokasiNode(infoGraph X) { // alokasi node
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
adrEdge AlokasiEdge(adrNode N) { // alokasi edge
    adrEdge E = new ElmEdge;
    E->node = N;
    E->next = NULL;
    return E;
}
void InsertNode(Graph &G, infoGraph X) { // insert node ke graph
    adrNode P = AlokasiNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
adrNode FindNode(Graph G, infoGraph X) { // mencari node pake info
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void ConnectNode(adrNode N1, adrNode N2) { // menghubungkan node
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G) { // menampilkan graph 
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
void PrintDFS(Graph G, adrNode N) { 
    if (N == NULL) return;
    if (N->visited == 1) return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

void PrintBFS(Graph G, adrNode N) { //tambahan
    if (N == NULL) return;

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
    adrNode Q[100];
    int front = 0, rear = 0;
    Q[rear++] = N;
    N->visited = 1;

    while (front < rear) {
        adrNode curr = Q[front++];
        cout << curr->info << " ";

        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q[rear++] = E->node;
            }
            E = E->next;
        }
    }
}
