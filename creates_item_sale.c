#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>C

struct item
{
    char * itemName;
    int * quantity;
    float * price;
    float amount;
};


int readItem(struct item * pstructParam);
int printItem(const struct item * pstructParam);

int main(void){
    struct item anItemStruct;
    struct item * panItemStruct = NULL;
    panItemStruct = &anItemStruct;

    readItem(panItemStruct);
    printItem(panItemStruct);

    return 0;
};


int readItem(struct item * pstructParam)
{
    char itemNameInput[50];
    int quantityInput;
    float priceInput;
    float amountResult;

    printf("Please type the name of an item for sale: ");
    scanf(" ");
    gets(itemNameInput);
    // Now we need to dereference the pointer to the structure so that we can access the actual structure
    pstructParam->itemName = (char*)calloc(strlen(itemNameInput), sizeof(char));
    strcpy(pstructParam->itemName, itemNameInput);
    // CAN ALSO DO: scanf("%s", pstructParam->itemName);

    printf("Now the quantity: ");
    scanf("%d", &quantityInput);
    pstructParam->quantity = &quantityInput;
    // CAN ALSO DO: scanf("%s", pstructParam->quantity);
    //scanf("%d", pstructParam->quantity);

    printf("Finally, the price: ");
    scanf("%f", &priceInput);
    pstructParam->price = &priceInput;
    // CAN ALSO DO: scanf("%s", pstructParam->price);
    //scanf("%f", pstructParam->price);

    amountResult = priceInput * (float)quantityInput;
    pstructParam->amount = amountResult;

    return 0;
};


int printItem(const struct item * pstructParam)
{
	printf("The name of the item is: %s - %p\n", pstructParam->itemName, pstructParam->itemName);
	printf("Its quantity is: %d - %p\n", *pstructParam->quantity, pstructParam->quantity);
	printf("Its price is: %.2f - %p\n", *pstructParam->price, pstructParam->price);
	printf("Finally, the total amount is: %.2f - %p\n", pstructParam->amount, &pstructParam->amount);
	printf("The address of this struct: %p\n", pstructParam);

	return 0;
};