#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int array[4] = {1, 3 , 5, 7};
    int tmp = 8;
    int array2[4] = {9, 10 , 11, 12};
    int* ptr = array;
    
    for(int i = 0; i < 9; i++){
        printf("%d\n", *ptr);
        ptr += 1;
    }
    return 0;
}