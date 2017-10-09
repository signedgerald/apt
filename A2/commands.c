#include "commands.h"

/**
 * Note this file is to contain console output,
 * meaning printf's are expected to be seen in this file.
 */

AddressBookList *commandLoad(char *fileName)
{
    /**
    * Loads the given file and returns a new AddressBookList.
    * 
    * If the file doesn't exist or corruption is found in the file
    * then NULL is returned.
    */
    AddressBookList *addressBookList;
    AddressBookNode *addressBookNode;
    AddressBookArray *addressBookArray;
    int id, i, count;
    char *ptr;
    char line[BUFSIZ];
    char name[NAME_LENGTH];
    char telestring[BUFSIZ];
    char telephone[TELEPHONE_LENGTH];
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("> Failed to load\n");
        return NULL;
    }
    else
    {
        addressBookList = createAddressBookList();
        addressBookArray = createAddressBookArray();
        printf("> Opening the file ");
        printf("%s.\n", fileName);
        printf("> Loading the file ...\n");
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            char *p = line;
            if (*p == '#')
                continue;
            for (i = 0, count = 0; i < line[i]; i++)
            {
                count += (line[i] == ',');
            }
            if (count == 1)
            {
                id = strtol(strtok(line, ",\n"), &ptr, 10);
                strcpy(name, strtok(NULL, ",\n"));
                addressBookNode = createAddressBookNode(id, name);
                insertNode(addressBookList, addressBookNode);
            }
            else if (count >= 2)
            {
                p = strtok(telestring, ",");
                id = strtol(strtok(line, ",\n"), &ptr, 10);
                strcpy(name, strtok(NULL, ",\n"));
                addressBookNode = createAddressBookNode(id, name);
                insertNode(addressBookList, addressBookNode);
                strcpy(telestring, strtok(NULL, "\n"));
                strcpy(telephone, strtok(telestring, ","));
                while(p != NULL)
                {
                    strcpy(telephone, p);
                    addTelephone(addressBookArray, telephone);
                    p = strtok(NULL, ","); 
                    printf("%s\n", telephone);
                }

                /*printf("%s\n", telestring);*/
            }
            else
            {
                printf("Unable to load file");
            }
        }
        printf("> %d phone book entries have been loaded from the file\n", addressBookList->size);
        return addressBookList;
    }
    return addressBookList;
}

void commandUnload(AddressBookList *list)
{
    AddressBookNode *temp;
    while (list->head != NULL)
    {
        temp = list->head;
        list->head = temp->nextNode;
        free(temp);
    }
}

void commandDisplay(AddressBookList *list)
{
    /* loop through lists to find largest name*/
    char *currentLocation;
    int i = 0;
    AddressBookNode *temp;
    /*AddressBookArray *array;*/
    temp = list->head;
    /*array = temp->array;*/
    currentLocation = "CUR";
    /*printf("%s\n", temp->array->telephones[i]);*/
    printf("---------------------------------------------\n");
    printf("| Pos | Serial | ID | Name | Telephones |\n");
    printf("---------------------------------------------\n");
    while (list->current != NULL)
    {
        if (temp == list->current)
        {
            printf("| %-4s|    %-4d| %d|%-7s|\n", currentLocation, i + 1, list->current->id, list->current->name);
            
        }
        else
        {
            printf("|     |    %-4d| %d|%-7s|\n", i + 1, list->current->id, list->current->name);
        }
        list->current = list->current->nextNode;
        i++;
    }
    printf("---------------------------------------------\n");
    printf("| Total phone book entries: %d              |\n", i);
    printf("---------------------------------------------\n");
    /*printf("|%-4s| %-7d| %-4d| %-8s|\n", currentLocation, counter, current->id, current->name, current->telephones);*/
}

void commandForward(AddressBookList *list, int moves)
{
    int i;
    AddressBookNode *temp;
    list->current = list->head;
    while (list->current->nextNode != NULL)
    {
        for (i = 0; i < moves; i++)
        {
            temp = list->head;
            list->head = temp->nextNode;
        }
        return;
    }
}
void commandBackward(AddressBookList *list, int moves)
{
    int i;
    AddressBookNode *temp;
    list->current = list->head;
    while (list->current->nextNode != NULL)
    {
        for (i = 0; i < moves; i++)
        {
            temp = list->tail;
            list->tail = temp->previousNode;
        }
        return;
    }
}
void commandInsert(AddressBookList *list, int id, char *name, char *telephone)
{
    AddressBookNode *node = malloc(sizeof(*node));
    AddressBookArray *array = malloc(sizeof(*array));
    addTelephone(array, telephone);
    node = createAddressBookNode(id, name);
    if (insertNode(list, node) == FALSE)
    {
        printf("> Non-unique ID inserted.");
    }
}
void commandAdd(AddressBookList *list, char *telephone)
{
    if (addTelephone(list->current->array, telephone) == FALSE)
    {
        printf("> Phone number already exists");
        return;
    }
}
void commandFind(AddressBookList *list, char *name)
{
    AddressBookNode *temp;
    temp = list->head;
    while(temp != NULL)
    {
        while(strcmp(temp->name, name) != 0)
        {
            temp = temp->nextNode;
        }
        temp = list->current;
        return;
    }
}
void commandDelete(AddressBookList *list)
{
    AddressBookNode *temp;
    temp = list->head;

    if(list->current == list->head)
    {
        list->current = list->current->nextNode;
        free(temp);
        return;
    }
}
void commandRemove(AddressBookList *list, char *telephone)
{
    AddressBookNode *temp;
    temp = list->head;

    if(list->current == list->head)
    {
        temp->previousNode->nextNode = temp->nextNode;
        list->current = list->current->nextNode;
        free(temp);
        return;
    }

}
void commandSort(
    AddressBookList *list,
    int sort(const void *node, const void *otherNode))
{
    /* Sort the nodes within list in ascending order using the
     * provided sort function to compare nodes.
     */
}
int compareName(const void *node, const void *otherNode)
{
    /* Compare node name with otherNode name.
     * 
     * return < 0 when node name is smaller than otherNode name.
     * return 0 when the names are equal.
     * return > 0 when node name is bigger than otherNode name.
     */
    return 0;
}
int compareID(const void *node, const void *otherNode)
{
    /* Compare node id with otherNode id.
     * 
     * return < 0 when node id is smaller than otherNode id.
     * return 0 when the ids are equal.
     * return > 0 when node id is bigger than otherNode id.
     */
    return 0;
}
void commandSave(AddressBookList *list, char *fileName)
{
}