/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mob
 *
 * Created on 28 agosto 2019, 23.23
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int flags;
} Flag;

static unsigned int pack(char flag, int obj, int sub_obj) {
    unsigned int result = (flag << 31) | ((obj & 0x7FFFFF) << 8) | (sub_obj & 0xFF);
    return result;
}

static void unpack(unsigned int binary, char *flag, int *obj, int *sub_obj) {
    *flag = (binary >> 31) & 1;
    *obj = (binary >> 8) & 0x7FFFFF;
    *sub_obj = binary & 0xFF;
}

int main(int argc, char** argv) {
    Flag f;
    f.flags = 0; // 32 bits to '0'
    // 4 bits to 1
    f.flags |= 1; // Set first bit to 1
    f.flags |= 2; // Set second bit to 1
    f.flags |= 4; // Set third bit to 1
    f.flags |= 8; // Set fourth bit to 1

    // Now f.flags == 1111 (base-2) which is 15 (base-10)
    printf("\n\nFLAGS: %d\n", f.flags);
    if (f.flags & 4) {
        printf("3rd bit set to 1\n");
    }

    /*** SHIFTING AND SPLITTING BITS ***/
    unsigned int c = 0xAABBCCDD; // 32 bits to '1'
    //0xAABBCCDD;
    unsigned int r = (c >> 24) & 0xFF; // 0xAABBCCDD ---> only 0xAA left
    unsigned int g = (c >> 16) & 0xFF; // 0xAABBCCDD ---> 0xAABB & 0xFF ---> 0xBB
    unsigned int b = (c >> 8) & 0xFF; // 0xAABBCCDD ---> 0xAABBCC & 0xFF
    unsigned int a = (c & 0xFF); // 0xAABBCCDD ---> 0xAABBCCDD & 0xFF
    printf("\nSPLITTED NUMBER 'C': \n - R: 0x%X\n - G: 0x%X\n - B: 0x%X\n - A: 0x%X\n", r, g, b, a);

    /*** REBUILT OUR 32 BITS NUMBER 'C' ***/
    c = (r << 24) | (g << 16) | (b << 8) | a;
    printf("\nREBUILT NUMBER 'C': \n - C: 0x%X\n", c);

    /*** LAST EXAMPLE: SUPPOSE WE HAVE
     * 1 BIT FOR THE FLAG
     * 23 BITS FOR OBJECT
     * 8 BITS FOR SUB-OBJECT
     * SO 32 BITS TOTALLY FOR A DATA, FOR EXAMPLE A MESSAGE
     ***/

    unsigned int data = pack(1, 1000001, 120);
    printf("\nPACK: 0x%X\n\n", data);

    char flag;
    int obj;
    int sub_obj;
    unpack(data, &flag, &obj, &sub_obj);
    printf("UNPACK: %d - %d - %d\n", flag, obj, sub_obj);
    return (EXIT_SUCCESS);
}

