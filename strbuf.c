#include <stdlib.h>
#include <stdio.h>
#include "strbuf.h"

#ifndef DEBUG
#define DEBUG 0
#endif

int sb_init(strbuf_t *sb, size_t length)
{

    sb->data = malloc(sizeof(char)*length);
    if (!sb->data) return 1;

    sb->length = length;
    sb->used   = 0;

    sb->data[length-1] = '\0';

    return 0;
   
}

void sb_destroy(strbuf_t *sb){
    free(sb->data);
}

int sb_append(strbuf_t *sb, char item){

    if (sb->used == sb->length-1) {
        size_t size = sb->length * 2;
        char *p = realloc(sb->data, sizeof(char) * size);
        if (!p) return 1;

        sb->data = p;
        sb->length = size;

        // if (DEBUG){
            printf("Increased size to %lu\n", size);
        // } 
    }

    sb->data[sb->used] = item;
    
    ++sb->used;
    sb->data[sb->used] = '\0';
    
    return 0;
}


int sb_remove(strbuf_t *sb, char *item){
    if (sb->used == 0) return 1;

    --sb->used;


    if (item) *item = sb->data[sb->used];
    sb->data[sb->used] = '\0';
    return 1;
  
}

int sb_insert(strbuf_t *sb, int index, char item){
    if(index == 0 && sb->used == 0){
        sb->data[index] = item;
        sb->used = index+1;
        
    }
    else if(index > sb->used && index < sb->length){ //i > list->used but within length
       sb->data[index] = item;
       sb->used = index + 1;
    
    }
    else if(index >= sb->length){ //i > length of list
        int doubleSize = sb->length * 2;
        int expandSize = index - sb->length;
        size_t size;
        if(doubleSize > expandSize){
            size = sb->length*2;
        }else{
            size = sb->length + expandSize + 1;
        }

        char *p = realloc(sb->data, sizeof(char) * size);
            if (!p) return 1;

            sb->data = p;
            sb->length = size;

            // if (DEBUG){
                printf("Increased size to %lu\n", size);
            // } 

        sb->data[index] = item;
        sb->used = index+1;

    }
    else{
        // double size if not enough space to insert in the middle
        if(sb->length == sb->used && index <sb->length){
            size_t size = sb->length * 2;
            char *p = realloc(sb->data, sizeof(char) * size);
            if (!p) return 1;

            sb->data = p;
            sb->length = size;

            // if (DEBUG){
                printf("Increased size to %lu\n", size);
            // } 
        }
        //regular insert in the middle
        int temp = sb->data[index];
        sb->data[index] = item;
        int i = index+1;

        while(i< sb->used){
            int temp2 = sb->data[i];
            sb->data[i] = temp;
            temp = temp2;
            i++;
        }

        sb->data[i] = temp;
         
        sb->used = i + 1;
    }
    sb->data[sb->used] = '\0';
    return 0;
}
int sb_concat(strbuf_t *sb, char *str){
    char * t; // first copy the pointer to not change the original
    int size = 1;

    for (t = str; *t != '\0'; t++) {
        size++;
        
    }

    for(int i = 0; i < size; i++){
        sb_append(sb, str[i]);
    }
    
    return 0;
}

