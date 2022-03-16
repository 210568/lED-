/*
*��Ŀ���ƣ�LED��ѭ����˸
*��Ŀ���󣺼�������һ��ZigBeeģ��,
          ����LED0��LED1�ֱ�P0�Ķ˿�3(P0_3 )�Ͷ˿�5(P0_5 )����,
          �ߵ�ƽ����LED,���д����ʵ������LED�ƵĽ�����˸��
*��Ŀ��дʱ�䣺2022��3��11��
*��Ŀ��д�ˣ����
*/

#include "ioCC2530.h"
#define LED0 P0_3
#define LED1 P0_5

/*
*��������delay()
*������ڣ�void delay(unsigned int time)
*�������ܣ��ӳ�
*��������ֵ����
*�����βΣ�unsigned int time
*/
void delay(unsigned int time)
{
  for(unsigned int i = 0;i < time; i++)
    for(unsigned char j = 0; j < 240; j++)
    {
      asm("NOP");       //����һ��ָ��
      asm("NOP");
      asm("NOP");
    }
}

/*
*��������Initial_GPIO()
*������ڣ�void Initial_GPIO()
*�������ܣ���ʼ��GPIO
*��������ֵ����
*�����βΣ���
*/
void Initial_GPIO()
{
  P0SEL &= ~0x28;       //����P0_3��P0_5ΪGPIO
  P0DIR |= 0x28;        //����P0_3��P0_5Ϊ�����
}

/*
*�������ƣ�main()
*������ڣ�void main(void)
*�������ܣ���������������ں���
*��������ֵ����
*�����βΣ���
*/
void main(void)
{
  Initial_GPIO();       //��ʼ��GPIO
  P0 = ~0x28;           //�ر�LED��
  while(1)
  {
    LED0 = 1;           //����LED0
    LED1 = 0;           //Ϩ��LED1
    delay(1000);        //�ӳ�һ��
    LED0 = 0;           //Ϩ��LED0
    LED1 = 1;           //����LED1
    delay(1000);        //�ӳ�һ��
  }
}