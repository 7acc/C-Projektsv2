#include "game.h"


#include "shop.h"
#include "enemy.h"
#include "images.h"
#include "ze engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


int stage_count = 0;
int stage_index = 0;
int enemy_count;
bool end = false;
player_t arena_player;
enemy_t *curr_enemy;
enemy_t stage_enemies[100];
enemy_t(*currentstage)[];

void initStage1(void)
{
    printf("STAGE ONE");

    enemy_count = 1;
  stage_enemies[0] = createSwampMonster(80, 20, 15,70);
}

void initStage2()
{
    enemy_count = 2;
    stage_index = 1;
    printf("STAGE TWO");
  stage_enemies[1] = createCupcakeThief(50, 10, 25,60);
  stage_enemies[2] = createCupcakeThief(50, 10, 25,60);

}

void initStage3()
{
    enemy_count = 1;
    stage_index = 3;
  stage_enemies[3] = createBeastman(110, 30, 50,70);
}

void setStage(int8_t stage_NR)
{
    int result = 0;

    switch(stage_NR)
    {
    case 1:
        initStage1();
        result = 1;
        break;

    case 2:
        initStage2();
        break;
    case 3:
        initStage3();
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;

    }
}

static void battle_loop()
{
    int i;

   
    printf("\nnumber of enemies: %i", enemy_count);
    printf("%i %i", stage_index, enemy_count);
    getche();
    for(i = stage_index; i < stage_index + enemy_count; i++)
    {
        curr_enemy = &stage_enemies[i];
        battle_start();
       
    }

}

void battle_start()
{
    uint8_t turn = 1;
    while(arena_player.hp > 0 && curr_enemy->base.hp > 0)
    {

        system("cls");
        GAME_battleScene();
        if(turn == 1)
        {
            actionMenu();
            turn = 0;
        }
        else if(turn == 0)
        {
            enemyAction();
            turn = 1;
        }
        getche();
    }
    printf("DUDUDUDU");
    turn = 1;

}

void GAME_battleScene()
{
    char player_stat_bar[130];


    sprintf(player_stat_bar, "%s     HP: %d                                                                      %s   HP: %d"
            , arena_player.name, arena_player.hp,curr_enemy->base.name,curr_enemy->base.hp);


    GPU_clear();
    GPU_text(0, 0, player_stat_bar);

    GPU_draw(30, 0, ground_dessert.image, ground_dessert.height, ground_dessert.width);
    GPU_draw(26, 90, curr_enemy->base.image->image, curr_enemy->base.image->height,
             curr_enemy->base.image->width);
    GPU_draw(26, 3, arena_player.image->image, arena_player.image->height,
             arena_player.image->width);


    GPU_show();

}

void actionMenu(void)
{
    int choise = 0;
    int done = 0;
    int dmg = 0;
    int heal = 10;


    printf("Choose your action!");
    scanf("%d", &choise);
    printf("%d", choise);
    while(done == 0)
    {
        switch(choise)
        {
        case 1:
            dmg = WEAPON_useWeapon(arena_player.weapon,
                                   &curr_enemy->enemy_defense);
            printf("You hit enemy for %i damage, KAPOW! ", dmg);
            playerDoDamage(dmg, curr_enemy);

            done = 1;
            break;
        case 2:
            printf(" You sleep zzzzzzzzzzzzzzzzzz!\n And gain %d hp\n"
                   "%s 's current hp is: %d", heal,
                   arena_player.name,
                   arena_player.hp += heal);


            done = 1;
            break;
        }
    }


}

void playerDoDamage(int dmg, enemy_t *opponent)
{
    opponent->base.hp -= dmg;
}

void enemyDoDamage(int dmg, player_t *opponent)
{
    opponent->hp -= dmg;
}

void enemyAction(void)
{
    int dmg;
    dmg = WEAPON_useWeapon(&curr_enemy->enemy_weapon, arena_player.defense);
    printf(" %s hit %s for %i damage, KAPOW! ",
           curr_enemy->base.name,
           arena_player.name, dmg);
    enemyDoDamage(dmg, &arena_player);

}

void battleMenu(void)
{
    int choise = 0;
    int done = 0;

    while(done == 0)
    {
        printf("Get ready for stage %i !\n\n", stage_count);

        printf("To continue press 1:\n"
               "To visit shop press 2:\n"
               "To quit game press 3:\n");

        scanf("%d", &choise);
        switch(choise)
        {
        case 1:
            battle_loop();
            done = 1;
            break;
        case 2:
            SHOP_shopMenu(&arena_player);
            break;
        case 3:
            end = true;
            return;
        }
    }

}

int8_t GAME_startArena(void)
{
    char continue_arena;

    arena_player = PLAYER_initPlayer();

    while(!end)
    {


        stage_count++;
        setStage(stage_count);
        battleMenu();

        printf("hp: %i name: %s",
               stage_enemies[0].base.hp,
               stage_enemies[0].base.name);



        getche();



    }


    // SHOP_visitShop(arena_player); 



}

