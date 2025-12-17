<h1 align="center">Laporan Praktikum Modul Graph</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">(103112400111)</p>


## Dasar Teori
Graph adalah struktur data yang terdiri dari kumpulan node dan edge yang menunjukkan hubungan antar node. Pada modul praktikum ini, graph direpresentasikan menggunakan adjacency list, yaitu setiap node menyimpan daftar node lain yang terhubung dengannya melalui edge. Graph yang digunakan bersifat tidak berarah (undirected), sehingga jika dua node dihubungkan, maka hubungan tersebut berlaku dua arah. 

Penelusuran graph dapat dilakukan dengan beberapa metode, di antaranya Depth First Search (DFS) dan Breadth First Search (BFS). DFS melakukan penelusuran dengan cara masuk sedalam mungkin ke satu cabang terlebih dahulu sebelum berpindah ke cabang lain. Penelusuran ini biasanya dilakukan secara rekursif dan menggunakan penanda visited agar node yang sudah dikunjungi tidak dikunjungi kembali. Sementara itu, BFS menelusuri graph secara melebar berdasarkan tingkatan (level). Penelusuran dimulai dari node awal, kemudian dilanjutkan ke semua node yang bertetangga langsung, lalu ke level berikutnya dan juga menggunakan penanda visited supaya setiap node hanya diproses satu kali.

## Guided 

### 1. Implementasi Graph dengan Adjacency List

File: graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info; //Menyimpan data node (misal: char/int).
    int visited; //Penanda untuk traversal (0/1) (Penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung.
    adrNode Next; // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node; //Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge Next; //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First; //Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph sebagai NOUL
adrNode AlokasiNode(infoGraph data); //alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); //Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); //function untuk mencari alamat Node berdasarkan infonya
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua Node (Undirected Graph)
void DisconnectNode(adrNode node1, adrNode node2); //prosedur untuk memutuskan hubungan dua node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus Rode X beserta semua edge yang berhubungan dengannya

void PrintInfoGraph(Graph G); //Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); //traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); //Traversal Depth First Search / DFS (Menggunakan Stack)

#endif
```

File: graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

File: main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```
Pada soal guided ini dibuat sebuah program untuk menerapkan struktur data Graph dengan menggunakan representasi Adjacency List. Graph terdiri dari node dan edge yang menunjukkan hubungan antar node. Graph yang digunakan bersifat undirected, sehingga jika dua node terhubung, hubungan tersebut berlaku dua arah.

Program dimulai dengan membuat graph kosong menggunakan prosedur CreateGraph. Setelah itu, beberapa node dimasukkan ke dalam graph menggunakan InsertNode, yaitu node A, B, C, D, E, dan F. Node-node tersebut disimpan dalam bentuk linked list.

Selanjutnya, hubungan antar node dibuat menggunakan prosedur ConnectNode. Setiap kali dua node dihubungkan, akan dibuat edge dari node pertama ke node kedua dan sebaliknya. Seluruh hubungan yang terbentuk kemudian ditampilkan menggunakan fungsi PrintInfoGraph dalam bentuk adjacency list.

Program juga melakukan penelusuran graph menggunakan dua metode, yaitu Breadth First Search (BFS) dan Depth First Search (DFS). BFS dijalankan dengan bantuan queue, sedangkan DFS menggunakan stack. Sebelum traversal dilakukan, nilai visited pada setiap node direset agar proses penelusuran berjalan dengan benar.

Selain itu, program menguji penghapusan node menggunakan prosedur DeleteNode. Pada contoh ini, node E dihapus dari graph dengan cara memutus semua edge yang terhubung dengannya, lalu menghapus node tersebut dari list graph. Setelah penghapusan dilakukan, graph kembali ditampilkan dan traversal BFS serta DFS dijalankan kembali untuk melihat perubahan struktur graph.


## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”:  
<img width="687" height="348" alt="Image" src="https://github.com/user-attachments/assets/aeeb40ed-69e3-4932-b551-0138b179be84" /><br>
Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.  
<img width="290" height="269" alt="Image" src="https://github.com/user-attachments/assets/4a6f6306-b8e0-462f-9962-37cae750c3d0" /><br>

File: graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintInfoGraph(Graph G);

#endif
```
File: graph.cpp
```cpp
#include "graph.h"

// membuat graph kosong
void CreateGraph(Graph &G) {
    G.first = NULL;
}

// alokasi node
adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

// alokasi edge
adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->node = N;
    E->next = NULL;
    return E;
}

// insert node ke graph
void InsertNode(Graph &G, infoGraph X) {
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

// mencari node pake info
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// menghubungkan node
void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = AlokasiEdge(N2);
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = AlokasiEdge(N1);
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

// menampilkan graph 
void PrintInfoGraph(Graph G) {
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
```
File: main.cpp
```cpp
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

    return 0;
}
```
#### Output:
<img width="708" height="255" alt="Image" src="https://github.com/user-attachments/assets/a7649b36-abf4-4d95-9e53-8ea3e82e34df" /><br>

Program ini dibuat untuk mengimplementasikan struktur data graph menggunakan representasi adjacency list. Graph tersusun dari beberapa node yang saling terhubung melalui edge. Graph pada program ini bersifat tidak berarah (undirected), sehingga setiap hubungan antar dua node berlaku dua arah.

Program diawali dengan pembuatan graph kosong menggunakan CreateGraph, yang mengatur pointer First bernilai NULL. Setelah itu, beberapa node dimasukkan ke dalam graph menggunakan InsertNode, yaitu node A, B, C, D, E, F, G dan H. Node-node tersebut disimpan dalam bentuk linked list.

Selanjutnya, hubungan antar node dibuat menggunakan ConnectNode yang digunakan untuk menghubungkan dua node dengan menambahkan edge pada masing-masing node, sehingga terbentuk graph tidak berarah. Terakhir, isi graph ditampilkan menggunakan prosedur PrintInfoGraph. Output yang dihasilkan menunjukkan setiap node beserta daftar node lain yang terhubung dengannya dalam bentuk adjacency list.

#### Full code Screenshot:
<img width="1919" height="1020" alt="Image" src="https://github.com/user-attachments/assets/3a11ac20-eead-47ee-9d01-c6ccb2e0f391" /><br>

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

File : graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N); //tambahan

#endif
```

File : graph.cpp
```cpp
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
void PrintDFS(Graph G, adrNode N) { //tambahan
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
```

File : main.cpp
```cpp
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

    cout << "DFS Traversal : ";
    PrintDFS(G, FindNode(G, 'A'));
    cout << endl;


    return 0;
}
```

#### Output:
<img width="559" height="275" alt="Image" src="https://github.com/user-attachments/assets/b1ae7443-268f-4d6b-8c98-f8f475493079" /><br>

Program ini menambahkan fitur penelusuran Depth First Search (DFS) pada graph yang sudah dibuat sebelumnya. Graph direpresentasikan menggunakan adjacency list dan bersifat tidak berarah, sehingga setiap edge menghubungkan dua node secara dua arah.

Di dalam main.cpp, graph dibuat dan diisi node A sampai H, lalu node-node tersebut dihubungkan sesuai dengan gambar pada soal. Setelah graph ditampilkan menggunakan PrintInfoGraph, program memanggil prosedur PrintDFS(G, FindNode(G, 'A')) untuk menampilkan hasil penelusuran DFS yang dimulai dari node A.

Prosedur PrintDFS akan mengunjungi node awal terlebih dahulu, kemudian menelusuri node-node tetangganya secara mendalam (depth) sebelum berpindah ke cabang lain. Setiap node yang sudah dikunjungi akan ditandai agar tidak dikunjungi kembali. Hasil DFS yang ditampilkan menunjukkan urutan kunjungan node berdasarkan algoritma DFS pada graph tersebut.

#### Full code Screenshot:
<img width="1917" height="973" alt="Image" src="https://github.com/user-attachments/assets/075fbf2b-6d10-477c-8e72-4ef980aae202" /><br>

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

File: graph.h
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N); 

void PrintBFS(Graph G, adrNode N); //tambahan

#endif
```

File: graph.cpp
```cpp
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

```

File: main.cpp
```cpp
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
```

#### Output :
<img width="750" height="432" alt="Image" src="https://github.com/user-attachments/assets/07941c4b-5188-4991-9973-a9e367e4884b" /><br>

Program ini menambahkan fitur penelusuran BFS (Breadth First Search) pada graph yang sudah dibuat sebelumnya. Graph direpresentasikan menggunakan adjacency list, di mana setiap node menyimpan daftar node lain yang terhubung dengannya.

PrintBFS(Graph G, adrNode N) digunakan untuk menampilkan hasil penelusuran graph secara BFS, yaitu menelusuri graph per level. Penelusuran dimulai dari node awal (dalam program ini node A). Node yang sudah dikunjungi ditandai dengan variabel visited agar tidak diproses berulang.

Pada BFS, program menggunakan queue sederhana (array) untuk menyimpan urutan node yang akan diproses. Node awal dimasukkan ke queue terlebih dahulu, lalu node tersebut dicetak. Setelah itu, semua tetangga yang belum dikunjungi dimasukkan ke queue. Proses ini diulang sampai queue kosong. Urutan pada output sesuai dengan prinsip BFS, karena node-node yang berada dekat dengan node awal akan diproses lebih dulu sebelum berpindah ke level berikutnya.

#### Full code screenshoot :
<img width="1919" height="1007" alt="Image" src="https://github.com/user-attachments/assets/60cf8d56-af11-4c3f-8b49-2e586d4347cc" /><br>

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa struktur data graph digunakan untuk menggambarkan hubungan antar data dengan lebih fleksibel. Dengan menggunakan adjacency list, setiap node dapat menyimpan daftar node lain yang terhubung dengannya sehingga hubungan antar node mudah dilihat dan diproses.
Pada praktikum ini juga dipelajari dua metode penelusuran graph, yaitu DFS (Depth First Search) dan BFS (Breadth First Search). DFS menelusuri graph dengan cara masuk sedalam mungkin ke satu jalur sebelum berpindah ke jalur lain, sedangkan BFS menelusuri graph secara bertahap berdasarkan level atau jarak dari node awal. Kedua metode ini menggunakan penanda visited agar setiap node hanya dikunjungi satu kali dan tidak terjadi pengulangan.
