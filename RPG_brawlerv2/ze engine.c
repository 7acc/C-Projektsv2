#include "Ze engine.h"
#include <stdint.h>
#include <stdio.h>

void GPU_clear(void)
{
  uint8_t y;
  uint8_t x;
  for(y = 0; y < SCREEN_H; y++)
    {
      for(x = 0; x < SCREEN_W; x++)
        {
          screen[y][x] = ' ';
        }
    }
}

void GPU_draw(uint8_t y,uint8_t x, char *image, uint8_t height, uint8_t width)
{
  int8_t screen_x = x;
  int8_t screen_y = y - height -1;
  uint8_t i;
  uint8_t j;
  char current_char;

  for(i = 0; i < height; i++)
    {
      for(j = 0; j < width; j++)
        {
          current_char = *(image + j + (i * width));

          if(current_char == 'S')
            {
              screen[screen_y + i][screen_x + j] = ' ';
            }
          else if(current_char == ' ')
            {
              continue;
            }
          else
            {
              screen[screen_y + i][screen_x + j] = current_char;
            }

        }
    }
};

void GPU_draw_single(uint8_t x, uint8_t y, char ch)
{
  int i;
  int j;

  screen[y][x] = ch;

}

void GPU_draw_withBoarder(uint8_t x, uint8_t y, char *image, uint8_t height, uint8_t width, char line_vert, char line_hori)
{
 
}
//////////////////////////////////////////////////////////////////////////////  

void GPU_text(int8_t y, int8_t x, char *string)
{
  int i = 0;
  char *current_char = string;

  while(*current_char != '\0')
    {
      screen[y][x + i] = *current_char;
      current_char++;
      i++;
    }




}

void GPU_text_multiline(int8_t y, int8_t x, char *string_array, int rows, int draw_space)
{
  uint8_t screen_x = x;
  uint8_t screen_y = y;
  uint8_t i;
  uint8_t j;
  int8_t k = -1;

  for(i = 0; i < rows; i++)
    {
      j = 0;
      k++;
      while(*(string_array + k) != '\0')
        {
          if(*(string_array + k) == ' ' && draw_space == 0)
            {
              j++;
              k++;
              continue;
            }
          screen[y + i][x + j] = *(string_array + k);
          j++;
          k++;
        }
    }

}

void TEST_text_multi(int8_t y, int8_t x, char *string_array, int rows, int string_size, int columns, int draw_space)
{
  int i;
  int j;
  char current_char;
  int end_of_string = 0;

  if(columns < string_size)
    {
      columns = string_size;
    }


  for(i = 0; i < rows; i++)
    {
      end_of_string = 0;

      for(j = 0; j < columns; j++)
        {

          current_char = *(string_array + j + (i * string_size));

          if(end_of_string == 1)
            {
              screen[y + i][x + j] = ' ';
            }
          else if(current_char == '\0' && draw_space == 1)
            {
              screen[y + i][x + j] = ' ';
              end_of_string = 1;

            }
          else if(current_char == '\0' && draw_space == 0)
            {
              break;
            }

          else
            {
              screen[y + i][x + j] = current_char;
            }
        }
    }
}

void GPU_text_withBoarder(int8_t y, int8_t x, char *string, char line_vert, char line_hori)
{

}

void GPU_text_multiLine_withBoarder(int8_t y, int8_t x, char *string_array,
        int rows, int string_size, int columns,
        char line_vert, char line_hori)
{
  int i;
  int j;
  char current_char;
  int end_of_string = 0;

  if(columns < string_size)
    {
      columns = string_size;
    }

  for(i = 0; i < rows; i++)
    {
      screen[y + i][x - 1] = line_vert;
      screen[y + i][x + columns] = line_vert;
      screen[y - 1][x - 1] = line_hori;
      screen[y - 1][x + columns] = line_hori;
      screen[y + rows][x - 1] = line_hori;
      screen[y + rows][x + columns] = line_hori;


      end_of_string = 0;

      for(j = 0; j < columns; j++)
        {
          if(i == 0)
            {
              screen[y - 1][x + j] = line_hori;
              screen[y + rows][x + j] = line_hori;
            }
          current_char = *(string_array + j + (i * string_size));

          if(end_of_string == 1)
            {
              screen[y + i][x + j] = ' ';
            }
          else if(current_char == '\0')
            {
              screen[y + i][x + j] = ' ';
              end_of_string = 1;

            }
          else
            {
              screen[y + i][x + j] = current_char;
            }
        }
    }
}

void GPU_show(void)
{
  uint8_t y;
  uint8_t x;
  for(y = 0; y < SCREEN_H; y++)
    {
      for(x = 0; x < SCREEN_W; x++)
        {
          printf("%c", screen[y][x]);
        }
      printf("\n");
    }
}