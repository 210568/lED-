/*
*项目名称：LED灯循环闪烁
*项目需求：假设现有一个ZigBee模块,
          它的LED0和LED1分别被P0的端口3(P0_3 )和端口5(P0_5 )控制,
          高电平点亮LED,请编写程序实现两个LED灯的交替闪烁。
*项目编写时间：2022年3月11日
*项目编写人：李俊辉
*/

#include "ioCC2530.h"
#define LED0 P0_3
#define LED1 P0_5

/*
*函数名：delay()
*函数入口：void delay(unsigned int time)
*函数功能：延迟
*函数返回值：无
*函数形参：unsigned int time
*/
void delay(unsigned int time)
{
  for(unsigned int i = 0;i < time; i++)
    for(unsigned char j = 0; j < 240; j++)
    {
      asm("NOP");       //消耗一个指令
      asm("NOP");
      asm("NOP");
    }
}

/*
*函数名称Initial_GPIO()
*函数入口：void Initial_GPIO()
*函数功能：初始化GPIO
*函数返回值：无
*函数形参：无
*/
void Initial_GPIO()
{
  P0SEL &= ~0x28;       //设置P0_3、P0_5为GPIO
  P0DIR |= 0x28;        //设置P0_3、P0_5为输出口
}

/*
*函数名称：main()
*函数入口：void main(void)
*函数功能：程序主函数，入口函数
*函数返回值：无
*函数形参：无
*/
void main(void)
{
  Initial_GPIO();       //初始化GPIO
  P0 = ~0x28;           //关闭LED灯
  while(1)
  {
    LED0 = 1;           //点亮LED0
    LED1 = 0;           //熄灭LED1
    delay(1000);        //延迟一秒
    LED0 = 0;           //熄灭LED0
    LED1 = 1;           //点亮LED1
    delay(1000);        //延迟一秒
  }
}