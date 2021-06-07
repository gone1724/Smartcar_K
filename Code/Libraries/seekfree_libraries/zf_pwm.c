/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		pwm
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK5.27
 * @Target core		STC16F40K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-4-14
 ********************************************************************************************************************/

#include "zf_pwm.h"
#include "board.h"
#include "zf_gpio.h"
#include "zf_uart.h"
#include "stdio.h"


//#pragma warning disable = 208


//����Ƚ�ģʽ�Ĵ���
const uint32 PWM_CCMR_ADDR[] = {0x7efec8, 0x7efec9, 0x7efeca ,0x7efecb, 
								0x7efee8, 0x7efee9, 0x7efeea, 0x7efeeb};
//����Ƚ�ʹ�ܼĴ���
const uint32 PWM_CCER_ADDR[] = {0x7efecc, 0x7efecd, 
								0x7efeec ,0x7efeed};
//���ƼĴ���,��8λ��ַ  ��8λ��ַ + 1����
const uint32 PWM_CCR_ADDR[] = {0x7efed5, 0x7efed7, 0x7efed9, 0x7efedb,
							   0x7efef5, 0x7efef7, 0x7efef9, 0x7efefb};
	
							   //���ƼĴ���,��8λ��ַ  ��8λ��ַ + 1����
const uint32 PWM_ARR_ADDR[] = {0x7efed2,0x7efef2};

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM_gpio��ʼ�����ڲ�ʹ���û�������ģ�
//  @param      pwmch       PWMͨ���ż�����
//  @return     void
//  Sample usage:           
//-------------------------------------------------------------------------------------------------------------------
void pwm_set_gpio(PWMCH_enum pwmch)
{
	switch(pwmch)
	{
		case PWMA_CH1P_P10:
		{
			gpio_mode(P1_0,GPO_PP);
			break;
		}
		case PWMA_CH1N_P11:
		{
			gpio_mode(P1_1,GPO_PP);
			break;
		}
		case PWMA_CH1P_P20:
		{
			gpio_mode(P2_0,GPO_PP);
			break;
		}
		case PWMA_CH1N_P21:
		{
			gpio_mode(P2_1,GPO_PP);
			break;
		}
		case PWMA_CH1P_P60:
		{
			gpio_mode(P6_0,GPO_PP);
			break;
		}
		case PWMA_CH1N_P61:
		{
			gpio_mode(P6_1,GPO_PP);
			break;
		}
		
		case PWMA_CH2P_P12:
		{
			gpio_mode(P1_2,GPO_PP);
			break;
		}
		case PWMA_CH2N_P13:
		{
			gpio_mode(P1_3,GPO_PP);
			break;
		}
		case PWMA_CH2P_P22:
		{
			gpio_mode(P2_2,GPO_PP);
			break;
		}
		case PWMA_CH2N_P23:
		{
			gpio_mode(P2_3,GPO_PP);
			break;
		}
		case PWMA_CH2P_P62:
		{
			gpio_mode(P6_2,GPO_PP);
			break;
		}
		case PWMA_CH2N_P63:
		{
			gpio_mode(P6_3,GPO_PP);
			break;
		}
		
		case PWMA_CH3P_P14:
		{
			gpio_mode(P1_4,GPO_PP);
			break;
		}
		case PWMA_CH3N_P15:
		{
			gpio_mode(P1_5,GPO_PP);
			break;
		}
		case PWMA_CH3P_P24:
		{
			gpio_mode(P2_4,GPO_PP);
			break;
		}
		case PWMA_CH3N_P25:
		{
			gpio_mode(P2_5,GPO_PP);
			break;
		}
		case PWMA_CH3P_P64:
		{
			gpio_mode(P6_4,GPO_PP);
			break;
		}
		case PWMA_CH3N_P65:
		{
			gpio_mode(P6_5,GPO_PP);
			break;
		}
		
		
		case PWMA_CH4P_P16:
		{
			gpio_mode(P1_6,GPO_PP);
			break;
		}
		case PWMA_CH4N_P17:
		{
			gpio_mode(P1_7,GPO_PP);
			break;
		}
		case PWMA_CH4P_P26:
		{
			gpio_mode(P2_6,GPO_PP);
			break;
		}
		case PWMA_CH4N_P27:
		{
			gpio_mode(P2_7,GPO_PP);
			break;
		}
		case PWMA_CH4P_P66:
		{
			gpio_mode(P6_6,GPO_PP);
			break;
		}
		case PWMA_CH4N_P67:
		{
			gpio_mode(P6_7,GPO_PP);
			break;
		}
		case PWMA_CH4P_P34:
		{
			gpio_mode(P3_4,GPO_PP);
			break;
		}
		case PWMA_CH4N_P33:
		{
			gpio_mode(P3_3,GPO_PP);
			break;
		}
		
		
		case PWMB_CH1_P20:
		{
			gpio_mode(P2_0,GPO_PP);
			break;
		}
		case PWMB_CH1_P17:
		{
			gpio_mode(P1_7,GPO_PP);
			break;
		}
		case PWMB_CH1_P00:
		{
			gpio_mode(P0_0,GPO_PP);
			break;
		}
		case PWMB_CH1_P74:
		{
			gpio_mode(P7_4,GPO_PP);
			break;
		}
		
		case PWMB_CH2_P21:
		{
			gpio_mode(P2_1,GPO_PP);
			break;
		}
		case PWMB_CH2_P54:
		{
			gpio_mode(P5_4,GPO_PP);
			break;
		}
		case PWMB_CH2_P01:
		{
			gpio_mode(P0_1,GPO_PP);
			break;
		}
		case PWMB_CH2_P75:
		{
			gpio_mode(P7_5,GPO_PP);
			break;
		}

		
		case PWMB_CH3_P22:
		{
			gpio_mode(P2_2,GPO_PP);
			break;
		}
		case PWMB_CH3_P33:
		{
			gpio_mode(P3_3,GPO_PP);
			break;
		}
		case PWMB_CH3_P02:
		{
			gpio_mode(P0_2,GPO_PP);
			break;
		}
		case PWMB_CH3_P76:
		{
			gpio_mode(P7_6,GPO_PP);
			break;
		}

		
		case PWMB_CH4_P23:
		{
			gpio_mode(P2_3,GPO_PP);
			break;
		}
		case PWMB_CH4_P34:
		{
			gpio_mode(P3_4,GPO_PP);
			break;
		}
		case PWMB_CH4_P03:
		{
			gpio_mode(P0_3,GPO_PP);
			break;
		}
		case PWMB_CH4_P77:
		{
			gpio_mode(P7_7,GPO_PP);
			break;
		}
		
	}
	
}
	
		
//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM��ʼ��
//  @param      pwmch       PWMͨ���ż�����
//  @param      freq        PWMƵ��(10Hz-3000000Hz)
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           
//						 pwm_init(PWMA_CH2N_P13,10000,100*20);    
                 //��ʼ��PWM0  ʹ������P13  ���PWMƵ��10000HZ   ռ�ձ�Ϊ�ٷ�֮ 20*100 / PWM_DUTY_MAX*100
//							PWM_DUTY_MAX��zf_pwm.h�ļ��� Ĭ��Ϊ10000
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(PWMCH_enum pwmch,uint32 freq, uint16 duty)
{
	
	uint16 match_temp;
	uint16 period_temp; 
	uint16 freq_div = 0;
	
	
	P_SW2 |= 0x80;
	
	//GPIO��Ҫ����Ϊ�������
	pwm_set_gpio(pwmch);

	if(freq > 500)
	{
		//��Ƶ���㣬���ڼ��㣬ռ�ձȼ���
		freq_div = (sys_clk / freq) >> 16;							//���ٷ�Ƶ
		period_temp = sys_clk / freq ;			
		period_temp = period_temp / (freq_div + 1) - 1;				//����
	}
	else
	{
		freq_div = (sys_clk / freq / PWM_DUTY_MAX) - 1;					//���ٷ�Ƶ
		period_temp = PWM_DUTY_MAX;			
	}
	match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);	//ռ�ձ�

	
	if(PWMB_CH1_P20 <= pwmch)				//PWM5-8
	{
		//ͨ��ѡ������ѡ��
		PWM2_ENO |= (1 << ((2 * ((pwmch >> 4) - 4))));					//ʹ��ͨ��	
		PWM2_PS |= ((pwmch & 0x03) << ((2 * ((pwmch >> 4) - 4))));		//�����ѡ��
		
		// ����ͨ�����ʹ�ܺͼ���	
		(*(unsigned char volatile far *) (PWM_CCER_ADDR[pwmch>>5])) |= (uint8)(1 << (((pwmch >> 4) & 0x01) * 4));
		
		//����Ԥ��Ƶ
		PWM2_PSCRH = (uint8)(freq_div>>8);
		PWM2_PSCRL = (uint8)freq_div;
		
		PWM2_BKR = 0x80; 	//�����ʹ�� �൱���ܿ���
		PWM2_CR1 = 0x01;	//PWM��ʼ����
	}
	else
	{
		PWM1_ENO |= (1 << (pwmch & 0x01)) << ((pwmch >> 4) * 2);	//ʹ��ͨ��	
		PWM1_PS  |= ((pwmch & 0x07) >> 1) << ((pwmch >> 4) * 2);    //�����ѡ��
		
		// ����ͨ�����ʹ�ܺͼ���	
		(*(unsigned char volatile far *) (PWM_CCER_ADDR[pwmch>>5])) |= (1 << ((pwmch & 0x01) * 2 + ((pwmch >> 4) & 0x01) * 0x04));

		
		//����Ԥ��Ƶ
		PWM1_PSCRH = (uint8)(freq_div>>8);
		PWM1_PSCRL = (uint8)freq_div;

		PWM1_BKR = 0x80; 	// �����ʹ�� �൱���ܿ���
		PWM1_CR1 = 0x01;	//PWM��ʼ����
	}
	
	//����
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6])) = (uint8)(period_temp>>8);		//��8λ
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6] + 1)) = (uint8)period_temp;		//��8λ

	//���ò���ֵ|�Ƚ�ֵ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4]))		= match_temp>>8;			//��8λ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4] + 1))  = (uint8)match_temp;		//��8λ
	
	//��������
	(*(unsigned char volatile far *) (PWM_CCMR_ADDR[pwmch>>4])) |= 0x06<<4;		//����ΪPWMģʽ1
	(*(unsigned char volatile far *) (PWM_CCMR_ADDR[pwmch>>4])) |= 1<<3;		//����PWM�Ĵ�����Ԥװ�ع�
	

//	P_SW2 &= 0x7F;

}

/*-------------------------------------------------------------------------------------------------------------------
//  @brief      PWMռ�ձ�����
//  @param      pwmch       PWMͨ���ż�����
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           pwm_duty(PWM0_P00, 2000);
//		PWM_DUTY_MAX��fsl_pwm.h�ļ��� �Ѿ���ΪΪ2000��

�� pwm_duty(PWMA_CH1N_P11,2000);//ʹ������P11��ռ�ձ�Ϊ�ٷ�֮ duty/2000
   pwm_duty(PWMA_CH2N_P13,1000);//ʹ������P13��ռ�ձ�Ϊ�ٷ�֮ duty/2000

PWMռ�ȵĸ������ָһ�����������ڣ���Ч����ʱ���ƽռ������������֮��

ͨ����ͬռ�ձȵ�PWM���ƣ�ʩ�ӵĵ���˵�ѹ������Ϊ��ص�ѹE��ռ�ձ�d�ĳ˻���
�ı�ռ�ձ�d�Ϳ��Ե��Ƴ���ͬ�ĵ���˵�ѹ��������˵�ѹ������ת�ٳ�һ����ϵ���Ӷ��õ���ͬ�ĵ��ת��

���磬���ڵ�����ʽ��ֻ����һ�ֵ�ѹ����d��0ʱ������˵�ѹΪ0�����ͣת��
��d��50%ʱ������˵�ѹ��Чֵ��ЧΪ��ص�ѹ��һ�룬������е��ٶ���ת��
��d��100%ʱ������˵�ѹ���ڵ�ص�ѹ.//��ת��Խ��Ť��ԽС����ʱŤ�غ�С���п����������˵����

�������õ���H�ţ�˫���ԣ���ͨ��һ�����������ѹ��һ·���Ʒ����ѹ������ʵ������ת��


//-------------------------------------------------------------------------------------------------------------------*/
void pwm_duty(PWMCH_enum pwmch, uint16 duty)
{
	uint16 match_temp;
	uint16 arr = ((*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6]))<<8) | (*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6] + 1 ));

//	P_SW2 |= 0x80;

	match_temp = arr * ((float)duty/PWM_DUTY_MAX);				//ռ�ձ�
							
	
	//���ò���ֵ|�Ƚ�ֵ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4]))		= match_temp>>8;			//��8λ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4] + 1))  = (uint8)match_temp;		//��8λ

//	P_SW2 &= ~0x80;
	
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWMƵ������
//  @param      pwmch       PWMͨ���ż�����
//  @param      freq        PWMƵ��(10Hz-3MHz)
//  @param      duty        PWMռ�ձ�
//  @return     void
//  Sample usage:           pwm_freq(PWM0_P00, 50, 5000);     
                             //�޸Ļ�PWM0  ʹ������P0.0  ���PWMƵ��50HZ   ռ�ձ�Ϊ�ٷ�֮ 5000/PWM_DUTY_MAX*100
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(PWMCH_enum pwmch, uint32 freq, uint16 duty)
{
	uint32 match_temp;
    uint32 period_temp; 
	uint16 freq_div = 0;

	
	if(freq > 500)
	{
		//��Ƶ���㣬���ڼ��㣬ռ�ձȼ���
		freq_div = (sys_clk / freq) >> 16;							//���ٷ�Ƶ
		period_temp = sys_clk / freq ;			
		period_temp = period_temp / (freq_div + 1) - 1;				//����
	}
	else
	{
		freq_div = (sys_clk / freq / PWM_DUTY_MAX) - 1;					//���ٷ�Ƶ
		period_temp = PWM_DUTY_MAX;			
	}
	match_temp = period_temp * ((float)duty / PWM_DUTY_MAX);	//ռ�ձ�
	

	
//	P_SW2 |= 0x80;
	
	
	if(PWMB_CH1_P20 <= pwmch)				//PWM5-8
	{
		//����Ԥ��Ƶ
		PWM2_PSCRH = (uint8)(freq_div>>8);
		PWM2_PSCRL = (uint8)freq_div;
	}
	else
	{
		//����Ԥ��Ƶ
		PWM1_PSCRH = (uint8)(freq_div>>8);
		PWM1_PSCRL = (uint8)freq_div;
	}
	
	//����
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6])) = (uint8)(period_temp>>8);		//��8λ
	(*(unsigned char volatile far *) (PWM_ARR_ADDR[pwmch>>6] + 1)) = (uint8)period_temp;		//��8λ
	
		//���ò���ֵ|�Ƚ�ֵ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4]))		= match_temp>>8;			//��8λ
	(*(unsigned char volatile far *) (PWM_CCR_ADDR[pwmch>>4] + 1))  = (uint8)match_temp;		//��8λ
	
//	P_SW2 &= ~0x80;
}

