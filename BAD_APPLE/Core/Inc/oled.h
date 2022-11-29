#ifndef __OLED_H
#define __OLED_H

#include "main.h"

//-----------------OLED端口定义----------------  		
#define OLED_CS     BIT_ADDR(GPIOD_ODR_Addr,6)
#define OLED_RST    BIT_ADDR(GPIOG_ODR_Addr,15)
#define OLED_RS     BIT_ADDR(GPIOD_ODR_Addr,3)
#define OLED_WR     BIT_ADDR(GPIOG_ODR_Addr,14)
#define OLED_RD     BIT_ADDR(GPIOG_ODR_Addr,13)


//PC0~7,作为数据线
#define DATAOUT(x) GPIOC->ODR=(GPIOC->ODR&0xff00)|(x&0x00FF); //输出


#define OLED_CMD  	0		//写命令
#define OLED_DATA 	1		//写数据


#define ABS(x,y) ((x)<(y)?(y)-(x):(x)-(y))
#define BIT(x,i) (((x)>>(i))&1)
#define SetBit(x,i) ((x)|=1<<(i))
#define ClrBit(x,i) ((x)&=~(1<<(i)))

//OLED控制用函数
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);
void OLED_Refresh_Block(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t size);
void OLED_ShowPicture(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t bmp[], uint8_t rev);
#endif
