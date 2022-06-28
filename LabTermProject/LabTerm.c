#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define Deliver goto
#define Len 55
struct product

{
	char OP;

	int p_id;

	char p_name[40];

	int price;

	char lastSold[30];

	int quantity;

	int discount;

}StructArray[Len], StructRequest[Len];



void EnterProd(struct product request[], int counter, int pur_amount[], int gain[]);  //Insertation function needed for the sales record.txt file.

int FindProd(struct product *ptr[], int* index); //A function that searches and finds through the structure and finds the specific thing.

int  ProdSale(struct product *ptr[], int index); //A Discount function that applys a percantage based sale.

void ProdSell(struct product *ptr[], struct product *request[], int index);  //A sell function that changes gain and amount directly.

void UpProd(struct product *ptr[], struct product *request[], int index, int *arr[]);  //An Update function that keeps the items up to date.


void main() 
{
	char Chtr;

	FILE *request, *history, *sale_rec;

	int gain[100], pur_amount[100];

	int Inpt;

	int Operator = 0;



	int counter = 0;

	if ((sale_rec = fopen("salesrecord.txt", "r")) != NULL)  //Opens the file in reading mode 
	{

		fclose(sale_rec);

		printf("Do you want to enter new details for your warehouse ? (y / n) \n");  //Ask whether or not if you want to add new items to warehouse.

		scanf(" %c", &Chtr);



		if (Chtr == 'y')
		{
			sale_rec = fopen("salesrecord.txt", "a"); // If yes it goes to YES part which directs to salesrecord.

			Deliver WAREHOUSE;
		}


		else
		{
			Deliver OPERATION;
		}

	}


	else
	{
		
		// DEPOT

		sale_rec = fopen("salesrecord.txt", "w");

		fprintf(sale_rec, "PID\tPNAME \tPRICE\t\tLAST_SOLD\t\tQUANTITY\t\tDISCOUNT\t\tPURCHASED_AMOUNT\t\tGAIN(TL)\n");

	WAREHOUSE:

		printf("Enter the desired amount of products you are going to enter:");

		scanf("%i", &Operator);   // Gets a value of desired amount.

		printf("\n");



	}
	while (counter != Operator)  //Gets every detail of the product one by one then stores it in our structure.
	{
		printf("Product Id:");

		scanf("%d", &StructArray[counter].p_id);

		printf("\n");

		printf("Product Name:");

		scanf("%s", StructArray[counter].p_name);

		printf("\n");

		printf("Product Price:");

		scanf("%d", &StructArray[counter].price);

		printf("\n");

		printf("Product Date (dd.mm.yy):");

		scanf("%s", StructArray[counter].lastSold);

		printf("\n");

		printf("Product Quantity :");

		scanf("%d", &StructArray[counter].quantity);

		printf("\n");

		printf("Enter Discount value (1 or 0):");

		scanf("%d", &StructArray[counter].discount);

		printf("\n");

		printf("Purchased Amount:");

		scanf("%d", &pur_amount[counter]);

		if (pur_amount[counter] == 0)  //If item is not purchased gain is being set to zero.

		{
			gain[counter] = 0;
		}
		else if (pur_amount[counter] > 0)  //if its bought at least one time its updated.

		{
			gain[counter] = pur_amount[counter] * StructArray[counter].price;
		}

		printf("\n");

		counter++;
	}

	counter = 0;

	while (counter != Operator)  //here we print the file our structures stored amounts.
	{
		fprintf(sale_rec, "%d\t%s\t%d\t\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", StructArray[counter].p_id, StructArray[counter].p_name, StructArray[counter].price, StructArray[counter].lastSold, StructArray[counter].quantity, StructArray[counter].discount, pur_amount[counter], gain[counter]);

		counter++;
	}

	fclose(sale_rec);



	printf("Do you have additional requests ? (y / n): ");  //Ask the user if he/she wants to continue.

	scanf(" %c", &Chtr); 

	printf("\n");


	if (Chtr == 'n')

	{
		return;
	}

	else if (Chtr == 'y')

	{
		
		Deliver OPERATION;  //Goes to the writing  part of the request file.
	}

	

OPERATION:

	
	printf("\n");

	printf("Enter the number of operations you are going to do for request file :");  //Gets the operations amount.

	scanf("%d", &Inpt);


	int req_purch[100];

	if ((request = fopen("request.txt", "r")) != NULL)  //Looks if there is a file first it opens in "reading" mode.

	{
		fclose(request);  //closes the "reading" mode.

		request = fopen("request.txt", "a");  //then it open in "append" mode.
	}
	else

	{
		request = fopen("request.txt", "w");  //Creates a file if it cant see a file already  and opens it on "writing" mode.

		fprintf(request, "OpCode\tPID\tAmount\tDate\n");
	}

	printf("\n");

	printf("Enter your OPcode // I=Insertion S=Sell product U=Update D=Set discount to all \n");  //Navigation menu comes up.
	printf("OpCode // Product ID // Price // Quantity // Purchased Amount // Date // \n");

	printf("\n");

	for (int i = 0; i != Inpt; i++) 
	{

		printf("Entering name of your %d th product:", i + 1);  //You enter the name of the product 

		scanf("%s", StructRequest[i].p_name);  //It gets stored in p_name

		printf("\n");

		printf("%d:", i + 1);

		scanf(" %c,%d,%d,%d,%d,%s", &StructRequest[i].OP, &StructRequest[i].p_id, &StructRequest[i].price, &StructRequest[i].quantity, &req_purch[i], StructRequest[i].lastSold);
		//We scan the line that user puts in store in our struct one again to be printed soon.
		printf("\n");

		gain[i] = req_purch[i] * StructRequest[i].price;   //Gain is calculated by the amount of purchased items and price.

		fprintf(request, "%c\t%d\t%d\t%s\n", StructRequest[i].OP, StructRequest[i].p_id, StructRequest[i].quantity, StructRequest[i].lastSold); //And the values are printed.
	}
	
	fclose(request);





HISTORY:

	if ((history = fopen("History.txt", "r")) != NULL)  //Opens the file in "reading" mode.
	{ 
		fclose(history); //Closes the "reading" mode.

		history = fopen("History.txt", "a");  //Then opens the file in "append" mode once again.
	}
	else
	{
		history = fopen("History.txt", "w");  //If there is no file at the beggining opens the file in "writing" mode.
	}

	int index = 0;

	do
	{
		if (StructRequest[index].OP == 'I')  //Isertation part for the history text.
		{

			fprintf(history, "%s %d  %s (%d) inserted...\n", StructRequest[index].lastSold, StructRequest[index].p_id, StructRequest[index].p_name, StructRequest[index].quantity);

		}

		if (StructRequest[index].OP == 'U') //Update part for the history text.	(Partially Works)
		{

			fprintf(history, "%s %d  product (%s) updated...\n", StructRequest[index].lastSold, StructRequest[index].p_id, StructRequest[index].p_name);

		}
				
		if (StructRequest[index].OP == 'S') //Sell part for the history text.(Partially Works)
		{

			fprintf(history, "%s %d  %s (%d) has been sold...\n", StructRequest[index].lastSold, StructRequest[index].p_id, StructRequest[index].p_name, StructRequest[index].quantity);


		}

		if (StructRequest[index].OP == 'D')  //	Discount part for the history text.(Partially Works)
		{

			StructRequest[index].discount = 1;

			fprintf(history, "All products have been discounted by %d amount ...\n", ProdSale(&StructArray, Inpt));


		}

		index++;

	} 
	while (index != Inpt);

	fclose(history);

	//Request Operations

	int i = 0;

	while (i != Inpt)
	{

		if (StructRequest[i].OP == 'U')  //If it sees U in the Inpt 
		{

			UpProd(&StructArray, &StructRequest, i, &pur_amount);  //Recalls the function UpProd

		}

		if (StructRequest[i].OP == 'I') //If it sees I in the Inpt
		{

			EnterProd(StructRequest, i, req_purch, gain); //Recalls the function EnterProd

		}

		if (StructRequest[i].OP == 'S')  //If it sees S in the Inpt 
		{

			ProdSell(&StructArray, &StructRequest, i);  //Recalls the function ProdSell

		}
		if (StructRequest[i].OP == 'D')  //If it sees D in the Inpt
		{

			ProdSale(&StructArray, i);  // Recalls the function ProdSale.

		}

		i++;

	}

}



void EnterProd(struct product request[], int counter, int pur_amount[], int gain[])
{

	FILE *salerecord;

	if ((salerecord = fopen("salesrecord.txt", "r")) != NULL) //Opens the file in "reading" looks if there is a file.
	
	{

		fclose(salerecord);  //Closes the "reading" mode.

		salerecord = fopen("salesrecord.txt", "a");  //Opens the file in "append" mode.

	}

	else

	{

		salerecord = fopen("salesrecord.txt", "w");  //If it sees there is no file opens a file and opens it on "writing" mode.

	}

	int index = (counter);

	fprintf(salerecord, "%d\t%s\t%d\t\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", request[index].p_id, request[index].p_name, request[index].price, request[index].lastSold, request[index].quantity, request[index].discount, pur_amount[index], gain[index]);
	//once again our sturcture information is directly printed right here.

	fclose(salerecord);

}

int FindProd(struct product *ptr[], int* index)
{

	int i = 0;

	int search;

	printf("Enter the ID of product that you want to search:");  //Gets information about what you want to search 

	scanf("%d", &search);

	printf("\n");

	while (ptr[i]->p_id != (int)NULL)

	{
		if (ptr[i]->p_id == search) 
		{

			*index = i;

			return 1;

		}

		i++;
	}


	return 0;
}

int  ProdSale(struct product *ptr[], int index)  //Applys a discount from the prices of the products.

{

	FILE *sale_rec;

	int discount;

	printf("Please set a value for discount:");

	scanf("%d", &discount);   //Stores a discount value 

	ptr[index]->price = ptr[index]->price - (ptr[index]->price * discount / 100);  //Apllys the pectange discount to the prices in out structures.



	sale_rec = fopen("salesrecord.txt", "w");

	fprintf(sale_rec, "PID\tPNAME \tPRICE\t\tLAST_SOLD\t\tQUANTITY\t\tDISCOUNT\t\tPURCHASED_AMOUNT\t\tGAIN(TL)\n");

	return discount;



}

void ProdSell(struct product *ptr[], struct product *request[], int index)  //Decreases the amount and increases the purchase amount and gain accordingly.
{

	int sold_product_count, current_quantity;

	current_quantity = ptr[index]->quantity - request[index]->quantity;

	ptr[index]->quantity = current_quantity;

}



void UpProd(struct product *ptr[], struct product *request[], int index, int *arr[])   //Changes the details of the products.
{

	int check = FindProd(ptr, index);

	int price;

	if (check == 0)
	{
		printf("product not found.");

		printf("\n");

		return;
	}
	else if (check == 1)

	{
		printf("product found at %d'th row", index);

		printf("\n");
	}

	printf("Enter the new price of product:");

	scanf("%d", &price);

	ptr[index]->price = price;

	strcpy(ptr[index]->lastSold, request[index]->lastSold);

	ptr[index]->quantity = request[index]->quantity;


}