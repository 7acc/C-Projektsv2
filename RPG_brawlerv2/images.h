/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   images.h
 * Author: 7acc
 *
 * Created on den 21 februari 2017, 09:02
 */

#ifndef IMAGES_H
#define IMAGES_H

#include <stdio.h>
#include <stdint.h>

#define IMG_MAX_H   16
#define IMG_MAX_W   20

typedef struct image
{
    uint8_t height;
    uint8_t width;

    const char *image;


} image_t;

extern image_t image_player;
extern image_t image_camel;
extern image_t ground_dessert;
#endif /* IMAGES_H */

