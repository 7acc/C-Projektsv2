/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "images.h"
#include "player.h"

image_t image_player;
const char hero_data1[15][18] = {
  "    ,,,,,         ",
  "   (o  o)         ",
  "   / . .\\         ",
  "   (_____)        ",
  "     : :          ",
  "    ##O##         ",
  "  ,,, : :,,,      ",
  " _)\\ : : / (____  ",
  "{ \\ /        ___} ",
  "  \\ /) (( /       ",
  "  (_______)       ",
  "     : :          ",
  "     : :          ",
  "   / \\ / \\        ",
  "  ^^^  ^^^        "
};
const char the_swamp_monster_image[IMG_MAX_H][IMG_MAX_W] = {
  "                  \0",
  "    _  _          \0",
  "   (_\\/_)         \0",
  "   (O  O)   .##   \0",
  "    \\`'/  .'.(\\ \0",
  "   .-`'_.' '  ||  \0",
  " ,' .-'. \\' -' /  \0",
  "( -<, ' _/__-'    \0",
  " `-./B / |        \0",
  "  \\__.' _|        \0",
  "  // \\_/ )        \0",
  " ('(  | /         \0",
  "  \\ \\ |/          \0",
  "   ) \\|\\_,      \0",
  "   \\_/,_/ -'      \0"
};
image_t image_camel;
const char camel_data[8][19] = {
  "     //            ",
  "   _00\\            ",
  "  (__/S\\  _  _      ",
  "     \\SS\\/S\\/S\\    ",
  "     (SSSSSSSSS)   ",
  "      \\SSSSSSS/ \\  ",
  "       [[] [[]   * ",
  "       [[] [[]     "
};


image_t ground_dessert;
const char ground_dessert_data[7][119] = 
{
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",               
"  \/..__..--  .      \/  .  ..   \/         \/ \/    \/          \/        \/    \/ __...--..__..__       .      \/.  ",
"        .  \/              \/    ..                .   \/     .__...   ..__..__       .      \/   \/     \/    __.    ",
"   __...   ..__..__       .      \/..__..--  .     \/     \/    __..--..\/       \/ \/    \/          \/        \/ \/ ",
"  \/..__..--  .      \/  .  \/         \/     \/                \/     .   . \/       .  ..  \/         \/       \/   ",
"        .  \/                    .. \/             .   \/     \/    __..--..      .  \/              \/    ..         ",
"   \/  .  ..  \/       .     \/     .   .    \/     \/    __..--.     \/ \/  .   \/     \/    __..--.        \/  .    ",

};


void IMAGE_init()
{

  image_player.image = &hero_data1;
  image_player.height = 15;
  image_player.width = 18;


  image_camel.image = &camel_data;
  image_camel.height = 8;
  image_camel.width = 19;
  
  
  ground_dessert.image = &ground_dessert_data;
  ground_dessert.height = 7;
  ground_dessert.width = 119;

}