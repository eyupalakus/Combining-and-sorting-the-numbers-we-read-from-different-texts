#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* first_start=NULL;
struct node* first_temp=NULL;
struct node* second_start=NULL;
struct node* second_temp=NULL;
struct node* third_start=NULL;
struct node* third_temp=NULL;

int counter;

void sort(){
	int i=0;
	while(i<counter){
	    third_temp=third_start;
	    while(third_temp->next!=NULL){
	        if(third_temp->data > third_temp->next->data){
	        	struct node* prew=(struct node*)malloc(sizeof(struct node));
	            prew->data=third_temp->next->data;
	            third_temp->next->data=third_temp->data;
	            third_temp->data=prew->data;
	        }
	        third_temp=third_temp->next;
	    }
	    i++;
	}
    third_temp=third_start;
	while(third_temp->next !=NULL){
		printf("%d ",third_temp->data);
		third_temp=third_temp->next;
	}
	printf("%d",third_temp->data);
}

void add(int data){
	struct node* third_linked = (struct node*)malloc(sizeof(struct node));
	third_linked->data=data;
	third_linked->next=NULL;
	if(third_start==NULL){
		third_start=third_linked;
	}
	else{
		third_temp=third_start;
		while(third_temp->next != NULL){
			third_temp=third_temp->next;
		}
		third_temp->next=third_linked;
	}
}	

int main(int argc, char *argv[]) {
	int number;
	FILE *first = fopen("first_text.txt","r");	
	while(!feof(first)){
		struct node* first_linked = (struct node*)malloc(sizeof(struct node));
		fscanf(first,"%d",&number);
		add(number);
		counter++;
		first_linked->data=number;
		first_linked->next=NULL;
		if(first_start==NULL){
			first_start=first_linked;
		}
		else{
			first_temp=first_start;
			while(first_temp->next != NULL){
				first_temp=first_temp->next;
			}
			first_temp->next=first_linked;			
		}
	}
	
	third_temp->next=NULL;
	
	FILE *second = fopen("second_text.txt","r");
	while(!feof(second)){
		struct node* second_linked = (struct node*)malloc(sizeof(struct node));
		fscanf(second,"%d",&number);
		add(number);
		counter++;
		second_linked->data=number;
		second_linked->next=NULL;
		if(second_start==NULL){
			second_start=second_linked;
		}
		else{
			second_temp=second_start;
			while(second_temp->next != NULL){
				second_temp=second_temp->next;
			}
			second_temp->next=second_linked;			
		}
	}

	third_temp->next=NULL;
	
	printf("ILK BAGLI LISTE : ");
	first_temp=first_start;
	while(first_temp->next != NULL){
		printf("%d ",first_temp->data);
		first_temp=first_temp->next;
	}
	
	printf("\nIKINCI BAGLI LISTE : ");
	second_temp=second_start;
	while(second_temp->next != NULL){
		printf("%d ",second_temp->data);
		second_temp=second_temp->next;
	}
	
	printf("\nSIRALANMAMIS BAGLI LISTE : ");
	third_temp=third_start;
	while(third_temp->next != NULL){
		printf("%d ",third_temp->data);
		third_temp=third_temp->next;
	}
	printf("%d",third_temp->data);
	
	printf("\nSIRALANMIS BAGLI LISTE : ");
	sort();
}
