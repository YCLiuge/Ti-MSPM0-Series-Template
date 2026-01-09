#include "MYI2C1/myi2c.h"

//打开SDA引脚（输出）
void SDA_OUT(void)   
{
    DL_GPIO_initDigitalOutput(GPIO_I2C_1_IOMUX_SDA);     
	DL_GPIO_setPins(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN);	   
    DL_GPIO_enableOutput(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN); 
}

//打开SCL引脚（输出）
void SCL_OUT(void)   
{
    DL_GPIO_initDigitalOutput(GPIO_I2C_1_IOMUX_SCL);     
	DL_GPIO_setPins(GPIO_I2C_1_SCL_PORT, GPIO_I2C_1_SCL_PIN);	   
    DL_GPIO_enableOutput(GPIO_I2C_1_SCL_PORT, GPIO_I2C_1_SCL_PIN); 
}

//关闭SDA引脚（输入）
void SDA_IN(void)
{
    DL_GPIO_initDigitalInputFeatures(GPIO_I2C_1_IOMUX_SDA,
	DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
	DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
}

void Delay_us(uint16_t us)
{
    while(us--)
    delay_cycles(80);
}
/*引脚配置层*/

void Delay_ms(uint16_t ms)
{
    while(ms--)
    delay_cycles(80000);
}

/**
  * 函    数：I2C写SCL引脚电平
  * 参    数：BitValue 协议层传入的当前需要写入SCL的电平，范围0~1
  * 返 回 值：无
  * 注意事项：此函数需要用户实现内容，当BitValue为0时，需要置SCL为低电平，当BitValue为1时，需要置SCL为高电平
  */
void MyI2C_W_SCL(uint8_t BitValue)
{
    if(BitValue)
        DL_GPIO_setPins(GPIO_I2C_1_SCL_PORT, GPIO_I2C_1_SCL_PIN);
    else
        DL_GPIO_clearPins(GPIO_I2C_1_SCL_PORT, GPIO_I2C_1_SCL_PIN);
	Delay_us(8);	//延时8us，防止时序频率超过要求
}

/**
  * 函    数：I2C写SDA引脚电平
  * 参    数：BitValue 协议层传入的当前需要写入SDA的电平，范围0~0xFF
  * 返 回 值：无
  * 注意事项：此函数需要用户实现内容，当BitValue为0时，需要置SDA为低电平，当BitValue非0时，需要置SDA为高电平
  */
void MyI2C_W_SDA(uint8_t BitValue)
{
    SDA_OUT();
    if(BitValue)
        DL_GPIO_setPins(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN);
    else
        DL_GPIO_clearPins(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN);
	Delay_us(8);					//延时8us，防止时序频率超过要求
}

/**
  * 函    数：I2C读SDA引脚电平
  * 参    数：无
  * 返 回 值：协议层需要得到的当前SDA的电平，范围0~1
  * 注意事项：此函数需要用户实现内容，当前SDA为低电平时，返回0，当前SDA为高电平时，返回1
  */
uint8_t MyI2C_R_SDA(void)
{
	uint8_t b;
    uint32_t BitValue;
    SDA_IN();
	BitValue = DL_GPIO_readPins(GPIO_I2C_1_SDA_PORT, GPIO_I2C_1_SDA_PIN);		//读取SDA电平
    {
        if(BitValue)   b=1;
        else           b=0;
    }
	Delay_us(8);		//延时8us，防止时序频率超过要求
	return b;	        //返回SDA电平
}

/**
  * 函    数：I2C初始化
  * 参    数：无
  * 返 回 值：无
  * 注意事项：此函数需要用户实现内容，实现SCL和SDA引脚的初始化
  */
void MyI2C_Init(void)
{
	/*设置默认电平*/
	SCL_OUT();
	SDA_OUT();
	DL_GPIO_setPins(GPIOA, GPIO_I2C_1_SDA_PIN |
		GPIO_I2C_1_SCL_PIN);//设置PA8和PA9引脚初始化后默认为高电平（释放总线状态）
}

/*协议层*/

/**
  * 函    数：I2C起始
  * 参    数：无
  * 返 回 值：无
  */
void MyI2C_Start(void)
{
    SDA_OUT();
	MyI2C_W_SDA(1);				//释放SDA，确保SDA为高电平
	MyI2C_W_SCL(1);				//释放SCL，确保SCL为高电平
	MyI2C_W_SDA(0);				//在SCL高电平期间，拉低SDA，产生起始信号
	MyI2C_W_SCL(0);				//起始后拉低SCL，为了占用总线，方便总线时序的拼接
}

/**
  * 函    数：I2C终止
  * 参    数：无
  * 返 回 值：无
  */
void MyI2C_Stop(void)
{
    SDA_OUT();
	MyI2C_W_SDA(0);							//拉低SDA，确保SDA为低电平
	MyI2C_W_SCL(1);							//释放SCL，使SCL呈现高电平
	MyI2C_W_SDA(1);							//在SCL高电平期间，释放SDA，产生终止信号
}

//产生IIC起始信号
void IIC_Start(void)
{
	SDA_OUT();     //sda线输出
	MyI2C_W_SDA(1);	  	  
	MyI2C_W_SCL(1);
	delay_us(4);
 	MyI2C_W_SDA(0);//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	MyI2C_W_SCL(0);//钳住I2C总线，准备发送或接收数据 
}  

//产生IIC停止信号
void IIC_Stop(void)
{
	SDA_OUT();//sda线输出
	MyI2C_W_SCL(0);
	MyI2C_W_SDA(0);//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	MyI2C_W_SCL(1); 
	MyI2C_W_SDA(1);//发送I2C总线结束信号
	delay_us(4);							   	
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
	MyI2C_W_SCL(1);delay_us(1);	   
	MyI2C_W_SDA(1);delay_us(1);	 
	while(MyI2C_R_SDA())
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	MyI2C_W_SCL(0);//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	MyI2C_W_SCL(0);
	SDA_OUT();
	MyI2C_W_SDA(0);
	delay_us(2);
	MyI2C_W_SCL(1);
	delay_us(2);
	MyI2C_W_SCL(0);
	MyI2C_W_SDA(1);
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	MyI2C_W_SCL(0);
	SDA_OUT();
	MyI2C_W_SDA(1);
	delay_us(2);
	MyI2C_W_SCL(1);
	delay_us(2);
	MyI2C_W_SCL(0);
}					 	

//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    MyI2C_W_SCL(0);//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {              
        MyI2C_W_SDA((txd&0x80)>>7);
        txd<<=1; 	  
		delay_us(2);   //对TEA5767这三个延时都是必须的
		MyI2C_W_SCL(1);
		delay_us(2); 
		MyI2C_W_SCL(0);	
		delay_us(2);
    }	 
} 	   

	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA设置为输入
    for(i=0;i<8;i++ )
	{
        MyI2C_W_SCL(0); 
        delay_us(2);
		MyI2C_W_SCL(1);
        receive<<=1;
        if(MyI2C_R_SDA())receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK   
    return receive;
}

/**
  * 函    数：I2C发送一个字节
  * 参    数：Byte 要发送的一个字节数据，范围：0x00~0xFF
  * 返 回 值：无
  */
void MyI2C_SendByte(uint8_t Byte)
{
    SDA_OUT();
	uint8_t i;
	for (i = 0; i < 8; i ++)				//循环8次，主机依次发送数据的每一位
	{
		MyI2C_W_SDA(Byte & (0x80 >> i));	//使用掩码的方式取出Byte的指定一位数据并写入到SDA线
		MyI2C_W_SCL(1);						//释放SCL，从机在SCL高电平期间读取SDA
		Delay_us(1);
		MyI2C_W_SCL(0);						//拉低SCL，主机开始发送下一位数据
	}
}

/**
  * 函    数：I2C接收一个字节
  * 参    数：无
  * 返 回 值：接收到的一个字节数据，范围：0x00~0xFF
  */
uint8_t MyI2C_ReceiveByte(void)
{
    SDA_OUT();
	uint8_t i, Byte = 0x00;	//定义接收的数据，并赋初值0x00
	MyI2C_W_SDA(1);			//接收前，主机先确保释放SDA，避免干扰从机的数据发送
	for (i = 0; i < 8; i ++)	//循环8次，主机依次接收数据的每一位
	{
        SDA_IN();
		MyI2C_W_SCL(1);						//释放SCL，主机机在SCL高电平期间读取SDA
		if (MyI2C_R_SDA() == 1){Byte |= (0x80 >> i);}	//读取SDA数据，并存储到Byte变量
	//当SDA为1时，置变量指定位为1，当SDA为0时，不做处理，指定位为默认的初值0
		MyI2C_W_SCL(0);						//拉低SCL，从机在SCL低电平期间写入SDA
	}
	return Byte;							//返回接收到的一个字节数据
}

// 从指定地址读取数据
int8_t sensirion_i2c_read(uint8_t* data, uint16_t count) {
    int8_t ret;
	uint8_t send_ack;
    uint16_t i;
    
    for (i = 0; i < count; i++) {
        // 如果不是最后一个字节，则发送ACK
		 send_ack = i > (count - 1); /* last byte must be NACK'ed */
        data[i] = MyI2C_ReceiveByte();  // 读取数据
		MyI2C_SendAck(send_ack);
    }
    return 0;
}

/**
  * 函    数：I2C发送应答位
  * 参    数：Byte 要发送的应答位，范围：0~1，0表示应答，1表示非应答
  * 返 回 值：无
  */
void MyI2C_SendAck(uint8_t AckBit)
{
    SDA_OUT();
	MyI2C_W_SDA(AckBit);					//主机把应答位数据放到SDA线
	MyI2C_W_SCL(1);							//释放SCL，从机在SCL高电平期间，读取应答位
	MyI2C_W_SCL(0);							//拉低SCL，开始下一个时序模块
}

/**
  * 函    数：I2C接收应答位
  * 参    数：无
  * 返 回 值：接收到的应答位，范围：0~1，0表示应答，1表示非应答
  */
uint8_t MyI2C_ReceiveAck(void)
{
    SDA_OUT();
	uint8_t AckBit;							//定义应答位变量
	MyI2C_W_SDA(1);							//接收前，主机先确保释放SDA，避免干扰从机的数据发送
	MyI2C_W_SCL(1);							//释放SCL，主机机在SCL高电平期间读取SDA
    SDA_IN();
	AckBit = MyI2C_R_SDA();					//将应答位存储到变量里
	MyI2C_W_SCL(0);							//拉低SCL，开始下一个时序模块
	return AckBit;							//返回定义应答位变量
}


void AT240C2_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	MyI2C_Start();						//I2C起始
	MyI2C_SendByte(0xA0);	//发送从机地址，读写位为0，表示即将写入
	
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(RegAddress);				//发送要写入寄存器的数据
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(Data);				//发送要写入寄存器的数据
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_Stop();						//I2C终止
	delay_ms(10);
}

uint8_t AT240C2_ReadReg(uint8_t RegAddress)
{
	uint8_t data=0;
	
	MyI2C_Start();						//I2C起始
	MyI2C_SendByte(0xA0);	//发送从机地址，读写位为0，表示即将写入
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(RegAddress);			//发送寄存器地址
	MyI2C_ReceiveAck();					//接收应答
	
	MyI2C_Start();						//I2C重复起始
	MyI2C_SendByte(0xA0 | 0x01);	//发送从机地址，读写位为1，表示即将读取
	MyI2C_ReceiveAck();					//接收应答
	data = MyI2C_ReceiveByte();			//接收指定寄存器的数据
	MyI2C_SendAck(1);					//发送应答，给从机非应答，终止从机的数据输出
	MyI2C_Stop();						//I2C终止
	return data;
}

uint8_t AT24C02_ReadReg(uint8_t RegAddress)
{
	uint8_t data=0;
	
	MyI2C_Start();						//I2C起始
	MyI2C_SendByte(0xA0);	//发送从机地址，读写位为0，表示即将写入
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(RegAddress);			//发送寄存器地址
	MyI2C_ReceiveAck();					//接收应答
	
	MyI2C_Start();						//I2C重复起始
	MyI2C_SendByte(0xA0 | 0x01);	//发送从机地址，读写位为1，表示即将读取
	MyI2C_ReceiveAck();					//接收应答
	data = MyI2C_ReceiveByte();			//接收指定寄存器的数据
	MyI2C_SendAck(1);					//发送应答，给从机非应答，终止从机的数据输出
	MyI2C_Stop();						//I2C终止
	return data;
}


/* AT24C02 的 7-bit I2C 地址 */
#define AT24C02_ADDR_7BIT    (0xA0U)

/* 要读取的 EEPROM 内部地址 */
#define EEPROM_TARGET_ADDR   (0x22U)

/* 全局变量用于时钟计算（参考官方示例） */
DL_I2C_ClockConfig gI2CclockConfig;
volatile uint32_t gClockSelFreq;
volatile uint32_t gDelayCycles;

/* 延迟函数（假设已定义） */
extern void delay_cycles(uint32_t cycles);

/*
 * 从 AT24C02 指定地址读取 1 字节
 */
uint8_t read_AT24C02_byte(uint8_t memAddr)
{
    uint8_t txData[1] = {memAddr};  // 要写入的地址
    uint8_t rxData = 0;

    /* ===== 第一阶段：写入目标地址 ===== */
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, txData, 1);

    /* 等待总线空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));

    /* 发起写传输：START + ADDR(W) + memAddr + STOP */
    DL_I2C_startControllerTransfer(
        I2C_0_INST,
        AT24C02_ADDR_7BIT,
        DL_I2C_CONTROLLER_DIRECTION_TX,
        1  // 1 byte to send
    );

    /* Errata I2C_ERR_13 workaround */
    delay_cycles(gDelayCycles);

    /* 等待传输完成 */
    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY);

//    /* 检查错误 */
//    if (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_ERROR) {
//        __BKPT(0); // 或其他错误处理
//    }

    /* 等待总线再次空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));

    /* 可选：加一点间隔（AT24C02 写周期很短，读无需等待，但保险起见） */
    delay_cycles(1000);

    /* ===== 第二阶段：读取 1 字节数据 ===== */
    /* 发起读传输：START + ADDR(R) + read 1 byte + STOP */
    DL_I2C_startControllerTransfer(
        I2C_0_INST,
        AT24C02_ADDR_7BIT,
        DL_I2C_CONTROLLER_DIRECTION_RX,
        1  // 1 byte to receive
    );

    /* 等待 RX FIFO 有数据 */
    while (DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST));

    /* 读取数据 */
    rxData = DL_I2C_receiveControllerData(I2C_0_INST);

//    /* 等待传输结束（STOP 完成） */
//    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY);

//    /* 检查读操作是否有错误 */
//    if (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_ERROR) {
//        __BKPT(0);
//    }

    return rxData;
}
