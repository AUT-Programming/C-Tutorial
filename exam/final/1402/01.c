#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fname[32], lname[32];
    char number[32];
} contact;

typedef struct DateList{
    contact value;
    struct DateList *next;
} contactlist;

contactlist *nx(contactlist *head, int i) {
    if (i == 0) return head;
    return nx(head->next, i - 1);
}

int cmp(contact a, contact b) {
    if (strcmp(a.lname, b.lname)) return (strcmp(a.lname, b.lname) > 0);
    if (strcmp(a.fname, b.fname)) return (strcmp(a.fname, b.fname) > 0);
    if (strcmp(a.number, b.number)) return (strcmp(a.number, b.number) > 0);
    return 0;
}

int add(contactlist **head, contact mmd) {
    contactlist *nw = malloc(sizeof(contactlist));
    nw->value = mmd;
    if (*head == NULL) {
        nw->next = NULL;
        *head = nw;
        return 0;
    }

    if (cmp((*head)->value, mmd)) {
        nw->next = *head;
        *head = nw;
        return 0;
    }

    contactlist *i = *head;
    int j = 1;
    for (; i->next; i = i->next, j++) {
        if (cmp(i->next->value, mmd)) {
            nw->next = i->next;
            i->next = nw;
            return j;
        }
    }

    i->next = nw;
    nw->next = NULL;
    return j;
}

void rm(contactlist **head, int i) {
    if (i == 0) {
        contactlist *tmp = (*head)->next;
        free(*head);
        *head = tmp;
        return;
    }

    contactlist *last = nx(*head, i - 1);
    contactlist *current = last->next;
    last->next = current->next;
    free(current);
}

int size(contactlist *head) {
    if (head == NULL) return 0;
    return size(head->next) + 1;
}

int strcasecmpmani(char a[], char b[]) {
    int i = 0;
    for (; a[i] && b[i] && a[i] == b[i]; i++);

    if (a[i] == '\0') return 1;
    return 0;
}

int hammadial(char a[], char b[]) {
    for (int i = 0; b[i]; i++) {
        if (strcasecmpmani(a, b + i)) return 1;
    }
    return 0;
}

void find(contactlist *head, char fname[], char lname[]) {
    int found = 0;
    for (contactlist *i = head; i; i = i->next) {
        int s1 = (fname[0] == '*' || hammadial(fname, i->value.fname));
        int s2 = (lname[0] == '*' || hammadial(lname, i->value.lname));
        if (s1 && s2) {
            printf("%s\n", i->value.number);
            found++;
        }
    }
    if (!found) {
        printf("NotFound\n");
    }
}

void del(contactlist **head, char num[32]) {
    contactlist *i = *head;
    int found = 0;
    for (int j = 0; i; i = i->next, j++) {
        if (strcasecmp(i->value.number, num) == 0) {
            printf("D %d\n", j + 1);
            found++;
        }
    }

    if (found == 0) {
        printf("NotFound\n");
    }

    i = *head;
    for (int j = 0; i; j++) {
        if (strcasecmp(i->value.number, num) == 0) {
            i = i->next;
            rm(head, j);
            j--;
            continue;
        }

        i = i->next;
    }
}

int main(void) {

    contactlist *head = NULL;

    int n;
    scanf(" %d", &n);

    while (n--) {
        char inp[20];
        scanf(" %s", inp);
        if (strcasecmp(inp, "Add") == 0) {
            contact mmd;
            scanf(" %s %s %s", mmd.fname, mmd.lname, mmd.number);
            printf("%d\n", add(&head, mmd) + 1);
        } else if (strcasecmp(inp, "Search") == 0) {
            char fname[32], lname[32];
            scanf(" %s %s", fname, lname);
            find(head, fname, lname);
        } else {
            char number[32];
            scanf(" %s", number);
            del(&head, number);
        }
    }

    return 0;
}


/*

14
Add Ali Ahmadi 66889944
Add Ali Rezvani 07126324653
Add Javad Nikoei 09123456770
Search Yashar Imani
Add Yashar Imani 37384234
Add Ebrahim Javadi 09901234567
Add MohammadJavad Akbari 15551234
Search Ali *
Add Amirali Amani 56782323
Delete 66889944
Add Ali Jalilvand 09876543210
Add Ebrahim Javadi 09121234567
Add Omid Akbari 09135363789
Search * Akbar

*/