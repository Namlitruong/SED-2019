
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "lab0.h"


int main(int argc, char **argv) {
  struct list_item root;

  root.value = -1;
  root.next = NULL;

  // Test

	print (&root);
	append (&root, 11);
	append (&root, 21);
	append (&root, 31);
	prepend (&root, 51);
	prepend (&root, 41);
	print (&root);
  printf("-----\n");
  input_sorted(&root, 10);
  input_sorted(&root, 20);
  input_sorted(&root, 30);
  input_sorted(&root, 40);
  print(&root);
  clear(&root);
  print(&root);

}

void print(struct list_item *first) {
  if (first->next != NULL) {
    printf("%d\n", first->next->value);
    print(first->next);
  }
}

void append(struct list_item *first, int x) {
   if (first->next != NULL) {
     append(first->next, x);
   } else {
     first->next = (struct list_item*)malloc(sizeof(struct list_item));
     first->next->value = x;
     first->next->next = NULL;
   }
}

void prepend(struct list_item *first, int x) {
  struct list_item *temp;
  temp = first->next;
  first->next = (struct list_item*)malloc(sizeof(struct list_item));
  first->next->value = x;
  first->next->next = temp;
}

void input_sorted(struct list_item *first, int x) {
  if (first->next != NULL) {
    if (first->next->value > x) {
      prepend(first, x);
    } else {
      input_sorted(first->next, x);
    }
  } else {
    append(first, x);
  }
}

void clear(struct list_item *first) {
 /* if (first->next->next != NULL) {
    clear(first->next);
  }*/
  free(first->next);
  first->next = NULL;
}

