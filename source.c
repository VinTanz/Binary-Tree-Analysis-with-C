#include "header.h"

address alokasi(buku B){
	address N = NULL;
	
	N = (node*) malloc(sizeof(node));
	
	if(N == NULL) return NULL;
	else {
		N->B = B;
		N->left = N->right = NULL;
		return N;
	}
}

void createEmpty(binaryTree *BT){
	(*BT) = NULL;
}

bool isEmpty(binaryTree BT){
	return BT==NULL;
}

bool isLeaf(binaryTree BT){
	return (isEmpty(BT->left) && isEmpty(BT->right));
}

bool isFound(binaryTree BT, int id){
	if(isEmpty(BT)){
		return false;
	} else {
		return(BT->B.id == id || isFound(BT->left,id) || isFound(BT->right,id));
	}
}

void insTreeBST(binaryTree *BT, address B){
	if(isEmpty(*BT)) (*BT) = B;
	else {
		if(B->B.id < (*BT)->B.id){
			insTreeBST(&(*BT)->left,B);
		} else {
			insTreeBST(&(*BT)->right,B);
		}
	}
}

void deleteLeaf(address *B){
	address N = (*B);
	(*B) = NULL;
	free(N);
}

void delTree(binaryTree *BT){
	if(isEmpty(*BT)){
		return;
	} else {
		delTree(&(*BT)->left);
		delTree(&(*BT)->right);
		deleteLeaf(&(*BT));
	}
}

void delTreeAt(binaryTree *BT, int id){
	if(isFound((*BT)->left, id)){
		delTreeAt(&((*BT)->left), id);
	} else if(isFound((*BT)->right, id)){
		delTreeAt(&((*BT)->right), id);
	} else {
		address temp;
		if((*BT)->left == NULL){
			temp = (*BT)->right;
			free((*BT));
			(*BT) = temp;
		} else if((*BT)->right == NULL){
			temp = (*BT)->left;
			free((*BT));
			(*BT) = temp;
		} else {
			temp = search((*BT)->right, smallestID((*BT)->right, (*BT)->right->B.id));
			(*BT)->B = temp->B;
			delTreeAt(&(*BT)->right, temp->B.id);
		}
	}
}

void updateTree(binaryTree *BT, int id, buku B){
	if((*BT)->B.id == id) (*BT)->B = B;
	else {
		if(isFound((*BT)->left,id)) updateTree(&(*BT)->left,id,B);
		else updateTree(&(*BT)->right,id,B);
	}
}

void preOrder(binaryTree BT, bool detail){
	if(!isEmpty(BT)){
		if(detail){
			printf("\n===============================================");
			printf("\nID              : %d", BT->B.id);
			printf("\nJudul           : %s", BT->B.judul);
			printf("\nPenulis         : %s", BT->B.pengarang);
			printf("\nPages           : %d", BT->B.pages);
			printf("\n===============================================\n");
		} else {
			printf("%s [%d] - ", BT->B.judul, BT->B.id);
		}
		preOrder(BT->left, detail);
		preOrder(BT->right, detail);
	}
}

void inOrder(binaryTree BT, bool detail){
	if(!isEmpty(BT)){
		inOrder(BT->left, detail);
		if(detail){
			printf("\n===============================================");
			printf("\nID              : %d", BT->B.id);
			printf("\nJudul           : %s", BT->B.judul);
			printf("\nPenulis         : %s", BT->B.pengarang);
			printf("\nPages           : %d", BT->B.pages);
			printf("\n===============================================\n");
		} else {
			printf("%s [%d] - ", BT->B.judul, BT->B.id);
		}
		inOrder(BT->right, detail);
	}
}

void postOrder(binaryTree BT, bool detail){
	if(!isEmpty(BT)){
		postOrder(BT->left, detail);
		postOrder(BT->right, detail);
		if(detail){
			printf("\n===============================================");
			printf("\nID              : %d", BT->B.id);
			printf("\nJudul           : %s", BT->B.judul);
			printf("\nPenulis         : %s", BT->B.pengarang);
			printf("\nPages           : %d", BT->B.pages);
			printf("\n===============================================\n");
		} else {
			printf("%s [%d] - ", BT->B.judul, BT->B.id);
		}
	}
}

int height(binaryTree BT, int h){
	if(BT == NULL){
		return h;
	} else {
		int a,b;
		a = height(BT->left, h+1);
		b = height(BT->right, h+1);
		return (a > b ? a : b);
	}
}

void levelOrder(binaryTree BT, int i, int h){
	if(i <= h){
		displayNode(BT, i);
		printf("\n");
		levelOrder(BT, i+1, h);
	}
}

void displayNode(binaryTree BT, int lv){
	if(BT == NULL){
		printf(" N "); 
		return;
	} 
	
	if(lv == 1){
		printf(" %d ", BT->B.id);
	} else if(lv > 1){
		displayNode(BT->left, lv - 1);
		displayNode(BT->right, lv - 1);
	}
}

int level(binaryTree BT, address node, int lv){
	if(isEmpty(BT)){
		return 0;
	} else {
		if(BT == node) {
			return lv;
		} else {
			return level(BT->left,node,lv+1) + level(BT->right,node,lv+1);
		}
	}
}

address search(binaryTree BT, int id){
	if(!isFound(BT,id)){
		return NULL;
	} else {
		
		if(BT->B.id == id){
			return BT;
		}
		
		address left, right;
		
		left = search(BT->left, id);
		right =  search(BT->right, id);
		
		if(left == NULL){
			return right;
		} else {
			return left;
		}
		
	}
}

address searchBST(binaryTree BT, int id){
	if (BT == NULL || BT->B.id == id) {
        return BT;
    }

    if (id < BT->B.id) {
        return search(BT->left, id);
    } else {
        return search(BT->right, id);
    }
}

int smallestID(binaryTree BT, int id){
	if(isLeaf(BT)){
		return BT->B.id;
	} else{
		
		int a, b;
		
		if(BT->B.id <= id){
			id = BT->B.id;
		}
		
		if(BT->left != NULL){
			a = smallestID(BT->left,id);
		} else {
			a = id;
		}
		
		if(BT->right != NULL){
			b = smallestID(BT->right,id);
		} else {
			b = id;
		}
		
		if(a < b) return a;
		return b;
	}
}

int Height(binaryTree BT){
	if(isEmpty(BT)) return -1;
	else if(isLeaf(BT)) return 0;
	else return (Height(BT->left) > Height(BT->right) ? 1+Height(BT->left) : 1+Height(BT->right));
}


int abs(int a){
	if (a < 0) a *= -1; 
	return a;
}

bool isBalancedTree(binaryTree BT){
	
	if(isEmpty(BT)) return true;
	
	else if (isLeaf(BT)) return true;
	
	else {
		return abs(Height(BT->left)-Height(BT->right))<=1 && isBalancedTree(BT->left) && isBalancedTree(BT->right);
	}
	
}

void Balancing(binaryTree *BT){
	
	address X,Y;
	
	if(!isBalancedTree(*BT)) {
		
		if(Height((*BT)->left) > Height((*BT)->right)) {	
			
			if(isBalancedTree((*BT)->left)) {
				
				if(Height((*BT)->left->left) < Height((*BT)->left->right)) {
					X = (*BT)->left;
					Y = X->right;
					X->right = Y->left;
					Y->left = X;
					(*BT)->left = Y->right;
					Y->right = (*BT);
					(*BT) = Y;
				} else {
					X = (*BT)->left;
					(*BT)->left = X->right;
					X->right = (*BT);
					(*BT) = X;
				}
				
			} else {			
				Balancing(&(*BT)->left);
			}
			
		} else {
			
			if(isBalancedTree((*BT)->right)){
				
				if(Height((*BT)->right->right) < Height((*BT)->right->left)){
					X = (*BT)->right;
					Y = X->left;
					X->left = Y->right;
					Y->right = X;
					(*BT)->right = Y->left;
					Y->left = (*BT);
					(*BT) = Y;
				} else {
					X = (*BT)->right;
					(*BT)->right = X->left;
					X->left = (*BT);
					(*BT) = X;
				}
				
			} else	{
				Balancing(&(*BT)->right);
			}
		}
		
		Balancing(BT);
	}
}

int random(int min, int max){
	return (rand() % (max - min +1)) + min;
}

void createNama(string temp){
	string vocal = "aiueo";
	strcpy(temp,"");
	int i, limit;
	
	// first name
	limit = random(12,20);
	for(i = 0 ; i < limit ; i++){
		if(i == 0 || i == (limit/2)+1){
			temp[i] = random(65,90);
		} else if(i == limit/2){
			temp[i] = 32;
		} else if(i%2 == 0){
			temp[i] = vocal[random(0,4)];
		} else {
			temp[i] = random(97,122);
		}
	}
	
	// akhir string
	temp[i+1] = '\0';
}

void createJudul(string temp){
	string vocal = "aiueo";
	strcpy(temp,"");
	int i, limit;
	
	// first name
	limit = random(6,10);
	for(i = 0 ; i < limit ; i++){
		if(i == 0){
			temp[i] = random(65,90);
		} else if(i%2 == 0){
			temp[i] = vocal[random(0,4)];
		} else {
			temp[i] = random(97,122);
		}
	}
	
	temp[i+1] = '\0';
}

void insNBook(binaryTree *BT){
	buku B;
	int i;
	for(i = 0 ; i < NBook ; i++){
		B.id = i+1;
		createJudul(B.judul);
		createNama(B.pengarang);
		B.pages = random(20,100);
		insTreeBST(BT, alokasi(B));
	}
}

address sequentialSearch(binaryTree BT, int id, int *comparasion){
	
	(*comparasion) += 1;
	
	if(!isFound(BT,id)){
		return NULL;
	} else {
		
		if(BT->B.id == id){
			
			return BT;
		}
		
		address left, right;
		
		left = sequentialSearch(BT->left, id, comparasion);
		right =  sequentialSearch(BT->right, id, comparasion);
		
		if(left == NULL){
			return right;
		} else {
			return left;
		}
		
	}
}

address binarySearch(binaryTree BT, int id, int *comparasion){
	
	(*comparasion) += 1;
	
	if (BT == NULL || BT->B.id == id) {
        return BT;
    }

    if (id < BT->B.id) {
        return binarySearch(BT->left, id, comparasion);
    } else {
        return binarySearch(BT->right, id, comparasion);
    }
}

void seqSearchAll(binaryTree *BT, int *comparasion, double *mean, double *t){
	time_t start, end;
	int i;
	double total_time = 0;
	double total_compare = 0;
	
	for(i = 1 ; i <= NBook ; i++){
		
		(*comparasion) = 0;
		
		start = time(NULL);
		
		sequentialSearch(*BT, i, comparasion);
		
		end = time(NULL);
		(*t) = difftime(end, start);
		
		total_time += (*t);
		total_compare += (*comparasion);
		
		printf("\nSearch id : %d done in %.2f seconds, total comparasion : %d", i, (*t), (*comparasion));
	}
	
	(*comparasion) = total_compare;
	(*mean) = (*comparasion)/NBook;
	(*t) = total_time;
}

void binSearchAll(binaryTree *BT, int *comparasion, double *mean, double *t){
	time_t start, end;
	int i;
	double total_time = 0;
	double total_compare = 0;
	
	for(i = 1 ; i <= NBook ; i++){
		
		(*comparasion) = 0;
		
		start = time(NULL);
		
		binarySearch(*BT, i, comparasion);
		
		end = time(NULL);
		(*t) = difftime(end, start);
		
		total_time += (*t);
		total_compare += (*comparasion);
		
		printf("\nSearch id : %d done in %.2f seconds, total comparasion : %d", i, (*t), (*comparasion));
	}
	
	(*comparasion) = total_compare;
	(*mean) = (*comparasion)/NBook;
	(*t) = total_time;
}
