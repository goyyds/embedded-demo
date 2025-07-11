#include <8051.h>

//  延时函数
//  参数  in 为延时的时间长度（单位时间很短，大约一条指令的时间）
void delay(unsigned int in)
{
    unsigned int i;
    for(i=0;i<10*in;i++) {;}
}
//  由暗变亮的子函数
//  参数 ledn 为点第几位的灯
void off_on(unsigned char ledn)
{
    unsigned int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            if(i<=j)
            {    //    模拟pwm的低电平输出
                P0 = 0;
            }
            else
            {    //    模拟PWM的高电平输出
                P0 = 1<<ledn;
            }
            delay(10);      //  这里的延时 根据灯的情况自己调整
        }
    }
}
//  由亮变暗的子函数
//  参数 ledn 为点第几位的灯
void on_off(unsigned char ledn)
{
    unsigned int i,j;
    for(i=100;i>1;i--)
    {
        for(j=0;j<100;j++)
        {
            if(i<=j)
            {        //    模拟pwm的低电平输出
                P0 = 0;
            }
            else
            {        //    模拟PWM的高电平输出
                P0 = 1<<ledn;
            }
            delay(10);                 //  这里的延时 根据灯的情况自己调整
        }
    }
}
//  主程序开始
void main()
{
    unsigned char ledn;
    while(1)
    {
        for(ledn=0;ledn<8;ledn++)
        {
            off_on(ledn);
            on_off(ledn);
        }
    }
}
