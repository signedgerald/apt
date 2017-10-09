#include "addressbook.h"

/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
* 
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/

int main(int argc, char **argv)
{
	AddressBookList *addressBookList;
	char input[BUFSIZ];
	char load[BUFSIZ];
	char fileN[BUFSIZ];
	int moves;
	char *fileName;
	char *token;
	char *ptr;
	showStudentInformation();
	do
	{
		printf("Enter your command: \n");
		fgets(input, sizeof(input), stdin);
		token = strtok(input, " \n");
		if (token)
		{
			strcpy(load, token);
		}
		else
		{
			load[0] = '\0';
		}
		token = strtok(NULL, " \n");
		if (token)
		{
			strcpy(fileN, token);
			fileName = fileN;
		}
		else
		{
			fileN[0] = '\0';
		}

		if (strcmp(load, COMMAND_LOAD) == 0)
		{
			addressBookList = commandLoad(fileName);
		}
		else if (strcmp(load, COMMAND_UNLOAD) == 0)
		{
			commandUnload(addressBookList);
			printf("> The list is unloaded\n");
		}
		else if (strcmp(load, COMMAND_DISPLAY) == 0)
		{
			commandDisplay(addressBookList);
		}
		else if (strcmp(load, COMMAND_QUIT) == 0)
		{
			printf("> Goodbye.\n");
		}
		else if (strcmp(load, COMMAND_FORWARD) == 0)
		{
			moves = strtol(fileName, &ptr, 10);
			commandForward(addressBookList, moves);
			/*commandDisplay(addressBookList);*/
		}
		else if (strcmp(load, COMMAND_BACKWARD) == 0)
		{
			moves = strtol(fileName, &ptr, 10);
			commandBackward(addressBookList, moves);
			/*commandDisplay(addressBookList);*/
		}
		else if (strcmp(load, COMMAND_INSERT) == 0)
		{
			/*commandInsert(addressBookList, )*/
		}
		else if(strcmp(load, COMMAND_ADD) == 0)
		{
			commandAdd(addressBookList, fileName);
		}
		else if(strcmp(load, COMMAND_FIND) == 0)
		{
			commandFind(addressBookList, fileName);
		}
		else if(strcmp(load, COMMAND_DELETE) == 0)
		{
			commandDelete(addressBookList);
		}
		else
		{
			printf("> Invalid input\n\n");
		}
	} while (strcmp(load, COMMAND_QUIT) != 0);
	commandUnload(addressBookList);
	return EXIT_SUCCESS;
}
void showStudentInformation()
{
	printf("----------------------------------------------------------------- \n");
	printf("Name: ");
	printf(STUDENT_NAME);
	printf("\n");
	printf("Student ID: ");
	printf(STUDENT_ID);
	printf("\n");
	printf("Advanced Programming Techniques, Assignment Two, Semester 1, 2017");
	printf("\n");
	printf("----------------------------------------------------------------- \n");
}
