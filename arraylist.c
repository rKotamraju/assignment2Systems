#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"

#ifndef DEBUG
#define DEBUG 0
#endif

int al_init(arraylist_t *L, size_t length)
{
    L->data = malloc(sizeof(int) * length);
    if (!L->data) return 1;

    L->length = length;
    L->used   = 0;

    return 0;
}

int al_insert(arraylist_t *list, int index, int item){

    if(index == 0 && list->used == 0){
        list->data[index] = item;
        list->used = index+1;
    }
    else if(index > list->used && index < list->length){ //i > list->used but within length
       list->data[index] = item;
       list->used = index + 1;
    
    }
    else if(index >= list->length){ //i > length of list
        int doubleSize = list->length * 2;
        int expandSize = index - list->length;
        size_t size;
        if(doubleSize > expandSize){
            size = list->length*2;
        }else{
            size = list->length + expandSize + 1;
        }

        int *p = realloc(list->data, sizeof(int) * size);
            if (!p) return 1;

            list->data = p;
            list->length = size;

            // if (DEBUG){
                printf("Increased size to %lu\n", size);
            // } 

        list->data[index] = item;
        list->used = index+1;

    }
    else{
        // double size if not enough space to insert in the middle
        if(list->length == list->used && index <list->length){
            size_t size = list->length * 2;
            int *p = realloc(list->data, sizeof(int) * size);
            if (!p) return 1;

            list->data = p;
            list->length = size;

            // if (DEBUG){
                printf("Increased size to %lu\n", size);
            // } 
        }
        //regular insert in the middle
        int temp = list->data[index];
        list->data[index] = item;
        int i = index+1;

        while(i< list->used){
            int temp2 = list->data[i];
            list->data[i] = temp;
            temp = temp2;
            i++;
        }

        printf("%s\n", "i");
        printf("%d\n", i);

        list->data[i] = temp;
         
        list->used = i + 1;
    }
    return 0;
}

void al_destroy(arraylist_t *L)
{
    free(L->data);
}


int al_append(arraylist_t *L, int item)
{
    if (L->used == L->length) {
        size_t size = L->length * 2;
        int *p = realloc(L->data, sizeof(int) * size);
        if (!p) return 1;

        L->data = p;
        L->length = size;

        if (DEBUG){
            printf("Increased size to %lu\n", size);
        } 
    }

    L->data[L->used] = item;
    ++L->used;

    return 0;
}


int al_remove(arraylist_t *L, int *item)
{
    if (L->used == 0) return 1;

    --L->used;

    if (item) *item = L->data[L->used];

    return 1;
}