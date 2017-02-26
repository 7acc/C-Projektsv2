
#include "shop.h"
#include "game.h"
#include "images.h"





/*
 * 
 */
int main(int argc, char** argv)
{
  int i = 12;
  
  char string[130];
  sprintf(string,"number: %i",i);
  
  
  printf("%s", string);
 
  
    IMAGE_init();
    populateShopWeapons();
    populateShopeDefensives();
    GAME_startArena();
  /*  player_t player;

    player = PLAYER_initPlayer();
    populateShopeDefensives();
    SHOP_chooseDefenseItem(&player);
    populateShopWeapons();
    SHOP_chooseWeapon(&player);
   */
    return (EXIT_SUCCESS);
}



