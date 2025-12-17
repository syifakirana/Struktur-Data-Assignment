#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    // insert node sesuai soal
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // hubungkan node sesuai gambar kaya di soal
    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));

    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'E'));

    ConnectNode(FindNode(G,'C'), FindNode(G,'F'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'G'));

    ConnectNode(FindNode(G,'D'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'E'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'F'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'G'), FindNode(G,'H'));

    cout << "Representasi Graph :" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "BFS Traversal : ";
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}
