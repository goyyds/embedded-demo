#include "REGX52.H" // STC89C52RC 专用头文件

void delay(unsigned int ms)
{
    unsigned int i, j;
    for(i=ms; i>0; i--)
        for(j=110; j>0; j--);
}

void main()
{
    while(1)
    {
        P2_0 = 0;  // 点亮 LED（低电平点亮）
        delay(500);
        P2_0 = 1;  // 熄灭 LED
        delay(500);
    }
}
