#include "lcdutils.h"
#include "lcddraw.h"
#include "draw.h"

signed char y = 64;

void drawPixel(u_char col, u_char row, u_int colorBGR){
  lcd_setArea(col, row, col, row);
  lcd_writeColor(colorBGR);
}

void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR){
  u_char colLimit = colMin + width, rowLimit = rowMin + height;
  lcd_setArea(colMin, rowMin, colLimit -1, rowLimit -1);
  u_int total = width * height;
  u_int c = 0;
  while((c++) < total){
    lcd_writeColor(colorBGR);
  }
}

void clearScreen(u_int colorBGR){
  u_char w = screenWidth;
  u_char h = screenHeight;
  fillRectangle(0,0, screenWidth, screenHeight, colorBGR);
}

void drawChar5x7(u_char rcol, u_char rrow, char c, u_int fgColorBGR, u_int bgColorBGR){
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 4, rrow + 7);
  while(row < 8){
    while(col < 5){
      u_int colorBGR = (font_5x7[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
      
    }
    col = 0;
    bit <<= 1;
    row++;
    
  }
}

void drawChar11x16(u_char rcol, u_char rrow, char c, u_int fgColorBGR, u_int bgColorBGR){
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x01;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 10, rrow + 16);
  while(row < 17){
    while(col < 11){
      u_int colorBGR = (font_11x16[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
      
    }
    col = 0;
    bit <<= 1;
    row++;
    
  }
}

void drawString5x7(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR){
  u_char cols = col;
  while(*string){
    drawChar5x7(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 6
  }
}

void drawString11x16(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR){
  u_char cols = col;
  while(*string){
    drawChar11x16(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 12;
  }
}


