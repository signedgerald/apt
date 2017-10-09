#include "addressbook_list.h"

/**handles doubly linked lists
* Note this file is *NOT* to contain console output,
* meaning printf's are *NOT* to be present in this file.
*/

AddressBookList *createAddressBookList()
{
    /**
    * Allocates and initialises a new AddressBookList.
    * malloc or calloc are expected to be used to create the
    * AddressBookList memory.
    * 
    * If memory cannot be allocated for the list NULL is returned.
    * use memset
    * Note head, tail and current should all be initialised to NULL.
    */
    AddressBookList *addressBookList = malloc(sizeof(*addressBookList));
    addressBookList->head = NULL;
    addressBookList->tail = NULL;
    addressBookList->current = NULL;
    addressBookList->size = 0;
    return addressBookList;
    /*return NULL;*/
}

void freeAddressBookList(AddressBookList *list)
{
    /**
     * Free's all nodes within the list and the AddressBookList itself.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     */
}

AddressBookNode *createAddressBookNode(int id, char *name)
{
    /**
    read id and name from file to create from array
    * Allocates and initialises a new AddressBookNode.
    * malloc or calloc are expected to be used to create the
    * AddressBookNode memory.
    * 
    * Note the array of the node should also be created and initialised,
    * which should be done with the createAddressBookArray(...) function.
    * 
    * If memory cannot be allocated for the node or array NULL is returned.
    * 
    * Note previousNode and nextNode should both be initialised to NULL.
    */
    AddressBookNode *addressBookNode = malloc(sizeof(*addressBookNode));
    strcpy(addressBookNode->name, name);
    addressBookNode->array = createAddressBookArray();
    addressBookNode->previousNode = NULL;
    addressBookNode->nextNode = NULL;
    addressBookNode->id = id;
    return addressBookNode;
}

void freeAddressBookNode(AddressBookNode *node)
{
    /**
    * Free's the array within the node and the AddressBookNode itself.
    * 
    * Note the freeAddressBookArray(...) function is used to free the array.
    */
    /*AddressBookNode * addressBookNode = addressbooklist->head;
    while(addressBookNode != NULL)
    {
        AddressBookNode * temp = addressBookNode;
        addressBookNode = addressBookNode->next;

        free(temp->id);
        free(temp);
    }
    free(addressbooklist);*/
}

Boolean insertNode(AddressBookList *list, AddressBookNode *node)
{
    /**
     * Inserts the node into the list and returns TRUE.
     * 
     * If the list already contains a node with the same id
     * then FALSE is returned and the node is not inserted.
     */
    int i;
    AddressBookNode *temp;
    temp = list->head;
    for (i = 0; i < list->size; i++)
    {
        if (node->id == temp->id)
        {
            return FALSE;
        }
        temp = temp->nextNode;
    }
    if (list->size == 0)
    {
        list->head = node;
        list->tail = node;
        list->size = 1;
        list->current = list->head;
        return TRUE;
    }
    else if (list->size == 1)
    {
        list->tail = node;
        list->size = 2;
        list->tail->previousNode = list->head;
        list->head->nextNode = list->tail;
        return TRUE;
    }
    else
    {
        list->tail->nextNode = node;
        node->previousNode = list->tail;
        list->tail = node;
        list->size++;
    }
    return TRUE;
}

Boolean deleteCurrentNode(AddressBookList *list)
{
    /**
     * Delete's and free's the current node in the list and returns TRUE.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     * 
     * If the list has no nodes (i.e., there is no current node)
     * then FALSE is returned.
     */

    return FALSE;
}

Boolean forward(AddressBookList *list, int forward)
{
    /**
     * Moves the current node forward in the list by the number provided
     * and returns TRUE.
     * 
     * If the current node cannot be moved forward by that many positions
     * then FALSE is returned and current remains unchanged.
     */

    return FALSE;
}

Boolean backward(AddressBookList *list, int backward)
{
    /**
    * Moves the current node backward in the list by the number provided
    * and returns TRUE.
    * 
    * If the current node cannot be moved backward by that many positions
    * then FALSE is returned and current remains unchanged.
    */

    return FALSE;
}

AddressBookNode *findByID(AddressBookList *list, int id)
{
    /**
     * Returns the node that matches the id provided.
     * 
     * If no node with a matching id exists then NULL is returned.
     */

    return NULL;
}

AddressBookNode *findByName(AddressBookList *list, char *name)
{
    /**
    * Sets current to the first node that matches the name provided
    * and returns this node.
    * 
    * If no node with a matching name exists then NULL is returned
    * and current remains unchanged.
    */

    return NULL;
}
