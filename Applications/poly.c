//implementation of polynomial ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"

void display (poly_ptr);
void displayOrig (poly_ptr);
poly_ptr sumPoly (poly_ptr,poly_ptr);
char* getTerm (poly_ptr);
char* getAbsTerm (poly_ptr);
poly_ptr parsePoly (char[]);
void parseTerm (char[],poly_ptr);
void dispMenu();

void display (poly_ptr poly) {
	if (!poly) {
		printf("NULL\n");
		return;
		}
	poly_ptr temp = poly;
	if (temp->coeff < 0)
		printf("-");
	while (temp->next!=NULL) {
		if ((temp->next)->coeff >= 0)
			printf("%s + ",getAbsTerm(temp));
		else
			printf("%s - ",getAbsTerm(temp));
		temp = temp->next;
		}
	printf("%s\n",getAbsTerm(temp));
	}

poly_ptr sumPoly (poly_ptr poly1, poly_ptr poly2) {
	if (!poly1 || !poly2) {
		if (poly1)
			return poly1;
		else if (poly2)
			return poly2;
		else
			return NULL;
		}
	poly_ptr poly = NULL, temp1 = poly1, temp2 = poly2;
	int sum=0;
	while (temp1 && temp2) {
		if (temp1->exp == temp2->exp) {
			sum = (temp1->coeff)+(temp2->coeff);
			InsertOrder(&poly,sum,temp1->exp);
			temp1 = temp1->next;
			temp2 = temp2->next;
			}
		else if (temp1->exp > temp2->exp) {
			InsertOrder(&poly,temp1->coeff,temp1->exp);
			temp1 = temp1->next;
			}
		else {
			InsertOrder(&poly,temp2->coeff,temp2->exp);
			temp2 = temp2->next;
			}
		}
	while (temp1) {
		InsertOrder(&poly,temp1->coeff,temp1->exp);
		temp1 = temp1->next;
		}
	while (temp2) {
		InsertOrder(&poly,temp2->coeff,temp2->exp);
		temp2 = temp2->next;
		}
	return poly;
	}
	
int main() {
	/*//declaring polynomial list
	poly_ptr p1 = NULL, p2 = NULL;
	
	InsertOrder(&p1,2,5);
	InsertOrder(&p1,-7,6);
	InsertOrder(&p1,4,2);
	display(p1);
	
	InsertOrder(&p2,3,2);
	InsertOrder(&p2,6,6);
	InsertOrder(&p2,-8,0);
	display(p2);
	
	poly_ptr psum = sumPoly(p1,p2);
	display(psum);
	
	printf("Coefficient of sum x^6: %d\n",Coefft(psum,6));*/
	
	//implementation of functions - menu form
	
	poly_ptr p1 = NULL, p2 = NULL, p3 = NULL;
	
	int choice;
	dispMenu();
	do {		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice){
			case 1: {
				int coefft, expt, ch;
				p1 = NULL;
				p2 = NULL;
				
				printf("\n__Polynomial1:__\n");
				printf("Enter term? (Enter 1 for yes, 2 for no): ");
				scanf("%d",&ch);
				while (ch==1) {
					printf("\tEnter coefficient: ");
					scanf("%d",&coefft);
					printf("\tEnter exponent: ");
					scanf("%d",&expt);
					
					if (coefft!=0)
						InsertOrder(&p1,coefft,expt);
					
					printf("Enter another term? (Enter 1 for yes, 2 for no): ");
					scanf("%d",&ch); 
					}
					
				printf("\n__Polynomial2:__\n");
				printf("Enter term? (Enter 1 for yes, 2 for no): ");
				scanf("%d",&ch);
				while (ch==1) {
					printf("\tEnter coefficient: ");
					scanf("%d",&coefft);
					printf("\tEnter exponent: ");
					scanf("%d",&expt);
					
					if (coefft!=0)
						InsertOrder(&p2,coefft,expt);
					
					printf("Enter another term? (Enter 1 for yes, 2 for no): ");
					scanf("%d",&ch); 
					}
					
				/*char expr[50];
				printf("Enter polynomial expression: ");
				scanf("%s",expr);
				p1 = parsePoly(expr);
				display(parsePoly(expr));*/
				break;
				}
				
			case 2: {
				p3 = NULL;
				printf("Adding the two polynomials...\n");
				p3 = sumPoly(p1,p2);
				
				/*char expr1[50], expr2[50];
				printf("Enter first polynomial: ");
				scanf("%s",expr1);
				printf("Enter second polynomial: ");
				scanf("%s",expr2);
				p1 = parsePoly(expr1);
				p2 = parsePoly(expr2);*/
				break;
				}
				
			case 3: {
				printf("Polynomial 1: ");
				display(p1);
				printf("Polynomial 2: ");
				display(p2);
				printf("Polynomial 3: ");
				display(p3);
				break;
				}
				
			case 0: printf("Exiting the menu...\n");
				break;
			
			case -1: dispMenu();
				break;
				
			default: printf("Invalid option. Choice must be an integer in the range [-1,3].\n"); break;
			}
			
		} while (choice != 0);
	
	return 0;
	}
	
void parseTerm (char str[], poly_ptr poly) {
	char subStr[8];
	int coefft, expt;
	for (int i=0; str[i]!='\0'; i++) {
		if (str[i]!='x')
			strncat(subStr,&str[i],1);
		else {
			coefft = atoi(subStr);
			strcpy(subStr,"");
			}
		}
	expt = atoi(subStr);
	
	InsertOrder(&poly,coefft,expt);
	}
	
poly_ptr parsePoly (char exprn[]) {
	printf("in\n");
	poly_ptr newPoly = (poly_ptr) malloc(sizeof(poly_node));
	char subStr[8];
	for (int i=0; exprn[i]!='\0'; i++) {
		if (i==0 || exprn[i]!='+' || exprn[i]!='-')
			strncat(subStr,&exprn[i],1);
		else {
			parseTerm(subStr,newPoly);
			strcpy(subStr,"");
			if (exprn[i]=='-')
				strcat(subStr,"-");
			}
		}
	parseTerm(subStr,newPoly);
	return newPoly;
	}
	
char* getAbsTerm (poly_ptr term) {
	char* part1 = (char*) malloc(sizeof(char)*8);
	char part2[3];
	sprintf(part1,"%d",abs(term->coeff));
	sprintf(part2,"%d",term->exp);
	if (abs(term->coeff) == 1)
		strcpy(part1,"");
	if (term->exp != 0) {
		strcat(part1,"x^");
		strcat(part1,part2);
		}
	return part1;
	}
	
void dispMenu() {
	printf("__MENU__\n");
	printf(" 1: readPoly()-read a polynomial\n 2: sumPoly()-add two polynomials\n");
	printf(" 3: display()-display a polynomial\n 0: exit menu\n-1: display menu\n");
	}

char* getTerm (poly_ptr term) {
	char* part1 = (char*) malloc(sizeof(char)*8);
	char part2[3];
	sprintf(part1,"%d",term->coeff);
	sprintf(part2,"%d",term->exp);
	if ((term->coeff) == 1)
		strcpy(part1,"");
	else if ((term->coeff) == -1)
		strcpy(part1,"-");
	if (term->exp != 0) {
		strcat(part1,"x^");
		strcat(part1,part2);
		}
	return part1;
	}
	
void displayOrig (poly_ptr poly) {
	if (!poly)
		return;
	poly_ptr temp = poly;
	while (temp->next!=NULL) {
		printf("%s + ",getTerm(temp));
		temp = temp->next;
		}
	printf("%s\n",getTerm(temp));
	}
