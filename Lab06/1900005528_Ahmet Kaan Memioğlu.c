#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct writer_info //i am declaring structure for writer information right here.
{
    char name[15];        // char array of the name of the writer.
    char surname[20];     // char array of the surname of the writer.
    int number_of_book;   //int for the number of the books.

}writer_info;

 writer_info Writers1 = {"Carl","Sagan",25 };

 writer_info Writers2 = {"George" ,"Orwell", 39}; writer_info Writers3 = { "George","Orwell" , 39 };  writer_info Writers5 = { "George","Orwell" , 39 };

 writer_info Writers4 = {"Stephen","Hawking" , 18 };

 writer_info Writers6 = {"Leo","Tolstoy" , 29 }; writer_info Writers8 = { "Leo" ,"Tolstoy" , 29 };

 writer_info Writers7 = {"Victor"  ,"Hugo" , 32 };

 writer_info Writers9 = {"Arthur Conan" ,"Doyle" , 37 };

 writer_info Writers10 = {"Agatha" ,"Christie" , 22 };

typedef struct        //i am declaring structure for book information right here.
{
    char book_name[35];     // char array of the name of the book.
    char writer_name[30];   // char array of the name of the writer of the book.
    int first_publication_year;  // char array of the name of the first publication year.

}book_info;

 book_info Books1 = {"Cosmos" , "Carl Sagan", 1980 };   book_info Books2 = { "Nineteen Eigthy FourGeorge" , "George Orwell", 1949 };

 

 book_info Books3 = {"Animal Farm" ,"George Orwell" , 1945 };  book_info Books4 = { "A Biref History Of Stephen" ,"Stephen Hawking" , 1988 };



 book_info Books5 = {"Coming Up For Air" ,"George Orwell" , 1969 }; book_info Books6 = { "What Man Live By" ,"Leo Tolstoy" , 1885 };



 book_info Books7 = {"Les Miserables" ,"Victor Hugo" , 1862 }; book_info Books8 = { "War And Peace" ,"Leo Tolstoy" , 1865 };



 book_info Books9 = {"Sherlock Holmes" ,"Arthur Conan Doyle" , 1865 };  book_info Books10 = { "Endless Night" ,"Agatha Christie" , 1967 };


void print_book_info(book_info* book_list)      //Function for the printing of the books 
{
     
	 
     printf("\tBook Name\t\t\tWriter Name Surname\t\t\tFirst Publication Year\n\n");     
	 book_list = &Books1;     //using book_list and adding &Books1 to the list in order to print out the solution
     printf("1.\t%s\t\t\t\t%s\t\t\t\t%d\n",book_list->book_name,book_list->writer_name,book_list->first_publication_year);
	 book_list = &Books2;     //using book_list and adding &Books2 to the list in order to print out the solution
	 printf("2.\t%s\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books3;     //using book_list and adding &Books3 to the list in order to print out the solution
	 printf("3.\t%s\t\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books4;     //using book_list and adding &Books4 to the list in order to print out the solution
	 printf("4.\t%s\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books5;     //using book_list and adding &Books5 to the list in order to print out the solution
	 printf("5.\t%s\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books6;     //using book_list and adding &Books6 to the list in order to print out the solution
	 printf("6.\t%s\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books7;     //using book_list and adding &Books7 to the list in order to print out the solution
	 printf("7.\t%s\t\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books8;     //using book_list and adding &Books8 to the list in order to print out the solution
	 printf("8.\t%s\t\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books9;     //using book_list and adding &Books9 to the list in order to print out the solution
	 printf("9.\t%s\t\t\t%s\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
	 book_list = &Books10;    //using book_list and adding &Books10 to the list in order to print out the solution
	 printf("10.\t%s\t\t\t%s\t\t\t\t%d\n", book_list->book_name, book_list->writer_name, book_list->first_publication_year);
 }


void search_book(writer_info *writer_info,book_info *book_list)  //To search the book name with the given information to the code.(i have tried but couldn't get this one to work.)
{
	int selection;    //Here we declare an integer for selection of the menu .
	char input[30];    //char array for the switch cases.
	int public=0;     //and an integer for the publication year part.
	printf("Please chose one of the options for searching the book.");
	printf("1.		Book Name");
	printf("2.		Writers Name");
	printf("3.		Writers Surname");
	printf("4.		Publication Date");
	scanf("%d", &selection);

	switch (selection) // switch cases for the manu above
	{
	case(1):
		printf("Enter Book name:");
		scanf("%s", &input);
		book_list = &Books1;
		if (strcmp(book_list->book_name,input)==0)
		{
			printf("Number of book is 1");
		}
		book_list = &Books2;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 2");
		}
		book_list = &Books3;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 3");
		}
		book_list = &Books4;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 4");
		}
		book_list = &Books5;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 5");
		}
		book_list = &Books6;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 6");
		}
		book_list = &Books7;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 7");
		}
		book_list = &Books8;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 8");
		}
		book_list = &Books9;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 9");
		}
		book_list = &Books10;
		if (strcmp(book_list->book_name, input) == 0)
		{
			printf("Number of book is 10");
		}
		break;

	case(2):
		printf("Enter Writers name");
			writer_info = &Writers1;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 1");
		}
		writer_info = &Writers2;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 2");
		}
		writer_info = &Writers3;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 3");
		}
		writer_info = &Writers4;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 4");
		}
		writer_info = &Writers5;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 5");
		}
		writer_info = &Writers6;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 6");
		}
		writer_info = &Writers7;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 7");
		}
		writer_info = &Writers8;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 8");
		}
		writer_info = &Writers9;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 9");
		}
		writer_info = &Writers10;
		if (strcmp(writer_info->name, input) == 0)
		{
			printf("Number of book is 10");
		}
		break;

	case(3):
		printf("Enter Writers surname");
		writer_info = &Writers1;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 1");
		}
		writer_info = &Writers2;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 2");
		}
		writer_info = &Writers3;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 3");
		}
		writer_info = &Writers4;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 4");
		}
		writer_info = &Writers5;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 5");
		}
		writer_info = &Writers6;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 6");
		}
		writer_info = &Writers7;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 7");
		}
		writer_info = &Writers8;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 8");
		}
		writer_info = &Writers9;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 9");
		}
		writer_info = &Writers10;
		if (strcmp(writer_info->surname, input) == 0)
		{
			printf("Number of book is 10");
		}
		break;
	case(4):
		printf("Enter Publication date");
		book_list = &Books1;
		if (book_list->first_publication_year== public)
		{
			printf("Number of book is 1");
		}
		book_list = &Books2;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 2");
		}
		book_list = &Books3;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 3");
		}
		book_list = &Books3;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 3");
		}
		book_list = &Books4;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 4");
		}
		book_list = &Books5;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 5");
		}
		book_list = &Books6;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 6");
		}
		book_list = &Books7;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 7");
		}
		book_list = &Books8;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 8");
		}
		book_list = &Books9;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 9");
		}
		book_list = &Books10;
		if (book_list->first_publication_year == public)
		{
			printf("Number of book is 10");
		}
			break;
	default:
		break;
	}
}

void find_writer_info(writer_info *writer_list, book_info *book_list, char *book_name) //Function for program to find the given details of the writer.(couldn't get this one to work either sorry.)
{

	printf("%s has found in the list:");
	printf("Writer Name : %s", writer_list->writer_name);
	printf("Number of writer's books : ");

}


book_info create_new_book(char* bName, writer_info writer, int pubYear)
{

}

void add_new_book(book_info *book_listc
{

}

void remove_book(book_info *book_list)
{

}

int main()
{
    int menu_select;   //integer for our main menu variable.

	char WriterInf[30];   //char array for the Writer information 

	book_info *book_info;  //structures of book info

	writer_info *writer_info; // and writer info.

	printf("Enter a number of option that you want to do :\n");

    Start:  //Goto function gets us here
    while(1) //infinite loop to get the menu after the first job.
	{

 
 printf("\n");
 
 printf("1.\tPrint Book List\n");
 
 printf("2.\tSearch Book\n");

 printf("3.\tSearch Writer Info Of Book\n");
 
 printf("4.\tAdd New Book\n");
 
 printf("5.\tRemove Book From List\n");
 
 printf("6.\tQuit\n");
 
 printf("\n");
 
 printf("Your Choice:");
 
 scanf_s("%d",&menu_select);  //Here we get the menu select's integer.
 
 printf("\n");
 
 switch(menu_select)
 {
     case 1:

     print_book_info(1);  //first function that prints the list of the books & writer's name.

     break;

     case 2:

		 search_book(writer_info, book_info); //Second function that searches for the writers information with the given things.

     break;

     case 3:

		 printf("Enter book name to find book's writer info : ");   //third function that gives the writers info when you give the books name.

		 scanf("%s", WriterInf);

		 find_writer_info(writer_info, book_info, WriterInf);
		 
     break;

     case 4:

     break;

     case 5:

     break;

     case 6:   //Quits the function.

		 exit(0);
     default:

     printf("Invalid number please enter a valid number.\n");

     printf("\n");

     goto Start;
 }
    }
    return 0;
}