#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef char string[255];
typedef struct node* address;
typedef struct node* binaryTree;

#define NBook 31

typedef struct {
	int id;
	string judul;
	string pengarang;
	int pages;
} buku;

typedef struct node{
	buku B;
	address left;
	address right;
} node;

// fungsi & prosedur dasar
address alokasi(buku B);
void createEmpty(binaryTree *BT);
bool isEmpty(binaryTree BT);
bool isLeaf(binaryTree BT);
bool isFound(binaryTree BT, int id);
void insTreeBST(binaryTree *BT, address B);
void deleteLeaf(address *B);
void delTree(binaryTree *BT);
void delTreeAt(binaryTree *BT, int id);
void updateTree(binaryTree *BT, int id, buku B);
void preOrder(binaryTree BT, bool detail);
void inOrder(binaryTree BT, bool detail);
void postOrder(binaryTree BT, bool detail);
int height(binaryTree BT, int h);
void levelOrder(binaryTree BT, int i, int h);
void displayNode(binaryTree BT, int lv);
int level(binaryTree BT, address node, int lv);
address search(binaryTree BT, int id);
address searchBST(binaryTree BT, int id);
int smallestID(binaryTree BT, int id);

// Tugas
int Height(binaryTree BT);
int abs(int a);
bool isBalancedTree(binaryTree BT);
void Balancing(binaryTree *BT);
int random(int min, int max);
void createNama(string temp);
void createJudul(string temp);
void insNBook(binaryTree *BT);
address sequentialSearch(binaryTree BT, int id, int *comparasion);
address binarySearch(binaryTree BT, int id, int *comparasion);
void seqSearchAll(binaryTree *BT, int *comparasion, double *mean, double *t);
void binSearchAll(binaryTree *BT, int *comparasion, double *mean, double *t);
