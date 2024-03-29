//Maintains a parts database (linked list version)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;  //points to the first part 

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
void printReverse(struct part *in);


 /*   
 * main: Prompts the user to enter an operation code,
 *       then calls a function to perform the requested action.
 *       Repeats until the user enters the command 'q'. Prints an
 *       error message if the user enters an illegel code
*/
int main(void) {
    char code;

    for (; ;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch(code) {
            case 'i': 
                insert(); break;
            case 's': 
                search(); break;
            case 'u': 
                update(); break;
            case 'p': 
                print(); break;
            case 'e':
                erase(); break;
            case 'q': return 0;

            case 'r':
                printReverse(inventory);

            default: 
                printf("invalid code\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
 
/**
 * find_part: Looks up a part in the inventory list. Returns
 *            a pointer to the node containing the part number;
 *            if the part number is not found, returns NULL.
*/
struct part *find_part(int number) {

    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/**
 * insert: Prompts the user for information about a new
 *         part and then inserts the part into the 
 *         inventory list; the list ramains sorted by
 *         prematurely, if the parts already exist or space
 *         could not be allocated for the part.
 *         part numb. Prints an error message and returns
 *         part numb. Prints an error message and returns
 */
void insert(void) {

    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Databse is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next);
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/**
 * search: Prompts the user to enter a part num, then
 *         looks up the part in the databse. If the part
 *         exists, prints the name and quantity on hand;
 *         if not, prints an error message
*/
void search(void) {

    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } 
    else
        printf("part not found.\n");
}

/**
 * update: prompts the user to enter a part number.
 *         prints and errolr message if the part doesn't exist;
 *         otherwise, prompts the user to enter chainge in the 
 *         quantity on hand and updates it in database
*/
void update(void) {
    int number, changes;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);

    p = find_part(number);
    if(p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &changes);

        p->on_hand += changes;
    }
    else
        printf("Part not found\n");
}

/**
 * Print: Prints a listing of all parts in the database,
 *        showing thepart number, part name, and quantity on hand.
*/
void print(void) {
    
    struct part *p;

    printf("Part Number    Part Name\
            Quantity on Hand\n");
    
    for (p = inventory; p != NULL; p = p->next) {
        printf("%7d      %-25s%11d\n", p->number, p->name,
                                      p->on_hand); 
    }
}

void printReverse(struct part *in)
{

    if(in == NULL)
        return;

    printReverse(in->next);

    printf("%s ", in->name);
}

/**
 * erase: Prompts user to enter a part number, then 
 *        searches through database. If part is found
 *        warns user and prompts user to comfirm the delete
 *        then deletes part
*/
void erase(void) {

    struct part *p, *cur, *prev;
    int number;
    char ch;

    printf("Enter part number: ");
    scanf("%d", &number);

    for (cur = inventory, prev = NULL;
         cur != NULL && cur->number != number;
         prev = cur, cur = cur->next)
        ;

    printf("WARNING! deleting part %d\n", number);
    printf("Continue ? (Y/N): ");
    scanf(" %c", &ch);
    if ((toupper(ch) == 'Y')) {
    
        if (cur->number == number) {
            prev->next = cur->next;
            free(cur); 
            return;
        }
    }
    
    else {
        printf("operation aborted.\n");
        return;
    }

    if (!cur)
        printf("Part not found.\n");
    
}