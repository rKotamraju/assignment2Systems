#include <stdio.h>
#include <stdlib.h>
#include "strbuf.h"


// int cmp(const void *a, const void *b)
// {
//     int x = *(int*)a;
//     int y = *(int*)b;
//     if (x < y) return -1;
//     if (x == y) return 0;
//     return 1;
// }

int main(int argc, char **argv)
{
    
    int i;
    strbuf_t sb;
    sb_init(&sb, 5);
    char d;

    
    // for (i = 0; i < N; ++i) {
    //     sb_concat(sb, input[i]);
    // }
    
    

    while (1 == scanf(" %c", &d)) {
        if(d >='a' && d<='z'){
             sb_append(&sb, d);
            // sb_concat(&sb,d );
        }
	    else{
            break;
        }
    }
     
    // printf("%s\n", "Used is at this element");
    // printf("%c\n", sb.data[sb.used]);
    
    
     sb_insert(&sb, 5, 'z');

    printf("%s\n", "printing current in strbuf");
    for (i = 0; i < sb.used; ++i) {
	    printf("%c\n", sb.data[i]);
    }

    // char  var = 'c';   /* actual variable declaration */
    // char  *ip;        /* pointer variable declaration */

    // ip = &var;
    // sb_remove(&sb, ip);
    char*  var2 = "hello\0";   /* actual variable declaration */
    // char  *ip2;        /* pointer variable declaration */

    // ip2 = &var2;
    sb_concat(&sb, var2);

    printf("%s\n", "printing current in strbuf");
    for (i = 0; i < sb.used; ++i) {
	    printf("%c\n", sb.data[i]);
    }

//done
      sb_destroy(&sb);

    return EXIT_SUCCESS;
}

