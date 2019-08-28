/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: mob
 *
 * Created on 29 agosto 2019, 0.36
 */

#ifndef BITS_MAN_H
#define BITS_MAN_H

static unsigned int pack(char flag, int obj, int sub_obj);
static void unpack(unsigned int binary, char *flag, int *obj, int *sub_obj);

#endif /* BITS_MAN_H */

