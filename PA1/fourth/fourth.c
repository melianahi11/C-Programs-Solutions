#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 struct Node {
	int x;
	struct Node* next;
};
	struct Node* head;

//it SHOULD sort the list !
void Insert(int n){

	struct Node* newN= (struct Node*)malloc(sizeof(struct Node));
	
	newN-> x = n;
	newN -> next = NULL;

	struct Node* now= head;
		if(head == NULL || (head) -> x >= newN -> x) {
		newN -> next = head;
		head = newN;
		}
		else{
	
		while(now != NULL) {
			if(now ->next == NULL) {
			 now ->next = newN;
			}
		else if(now ->next -> x == newN ->x){
			return;
			}
		else if(now->next->x < newN -> x) {
			now = now ->next;
			}
			else{
			newN -> next = now ->next;
			now -> next = newN;
		
		}
}
 }

	
}

void List(){
	struct Node* temp = head;
		while(temp != NULL) {
			printf("%d ", temp->x);
			temp = temp ->next; 
		}
		printf("\n");
}


int Delete(int n){
	if(head==NULL){
	return 0;
	}
	struct Node* prev = NULL;
	struct Node* cur= head;
		
		if(cur->x ==n){
		head = cur->next;
		free(cur);
		return 1;
		}
		else {
		cur = head -> next;
		prev = head;

		while(cur!=NULL){
			if(cur->x==n){
				prev->next =cur->next;
				free(cur);
				return 1;
			}
			else{
			prev= cur;
			cur = cur->next;
			}
		}
	}
	return 0;
}

int main(int argc, char* argv[argc+1]) {
	FILE* fp = fopen(argv[1], "r");

head= NULL; 
char str_in[20]= "";
int n1;
	while(fscanf(fp, "%s%d\n", str_in, &n1) != EOF){
		if(strcmp(str_in, "INSERT") ==0){
			Insert(n1);
			List();
		}
		if(strcmp(str_in, "DELETE") ==0){
			int result = Delete(n1);
			
			if(result ==1) {
			printf("%s\n", "SUCCESS"); 
			}
			else printf("%s\n","FAILED");

		}
		

	}
		
		
return EXIT_SUCCESS;
}
