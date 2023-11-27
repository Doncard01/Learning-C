#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 32

int main()
{
    // int c, nwhite, nother; // int could be a char 
    // int ndigit[10];
    
    // c = nwhite = nother = 0;
    // for(int i=0; i<10; i++) {
    //     ndigit[i] = 0;
    // }
    
    // while((c=getchar()) != EOF) {
    //     if(c >= '0' && c <='9')
    //         ++ndigit[c-'0'];
    //     else if(c == ' ' || c == '\n' || c == '\t') {
    //         ++nwhite;
    //     } else {
    //         ++nother;
    //     }
    // }
    
    // printf("Cyfry: ");
    // for(int i=0; i<10; i++) {
    //     printf("%d ", ndigit[i]);        
    // }
    
    // printf(", biale: %d, inne: %d\n", nwhite, nother);
    
    //histogram-------------------------------------
    int wc, lenght, new, max_lenght;
    char c;
    wc = lenght = max_lenght = 0;
    new = FALSE;
    int words[MAX_WORDS];
    
    for (int i=0; i<MAX_WORDS; i++) {
        words[i] = 0;
    }
    
    while((c=getchar()) != EOF) {
        if(new == FALSE) {
            if(c==' ' || c=='\t' || c=='\n') {
                continue;
            }
            else {
                new = TRUE;
            }    
        } else if (new == TRUE) {
            if(c==' ' || c=='\t' || c=='\n') {
                words[wc] = lenght;
                if(lenght > max_lenght)
                    max_lenght = lenght;
                ++wc;
                lenght = 0;
                new = FALSE;
            } else {
                ++lenght;
            }
        }
    }
    
    printf("Wszystkie slowa: %d\n", wc);
    printf("\nHistogram kolejnych slow: ");
    for(int i=0; i<wc; i++) {
        if(words[i] == 0) {
            break;
        }
        printf("%d | ", words[i]);
    }
    printf("\n                         -----------------------------------");

    for(int i=0; i<max_lenght; i++) {
        printf("\n                          ");
        for(int j=0; j<wc; j++) {
            if(words[j] != 0) {
                printf("***|");
                --words[j];
            } else {
                printf("   |");
            }
        }
    }
    
    
    
    return 0;
}
