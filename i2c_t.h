#ifndef  __I2C_H__
#define  __I2C_H__

void i2c_init(void);
void delay1(unsigned int n);

void I2CStart(void);
void I2CStop(void);
void I2CSendAck(void);
void I2CSendNotAck(void);
unsigned char I2CWaitAck(void);

void I2CSendByte(unsigned char cSendByte);
unsigned char I2CReceiveByte(void);
void I2cWrite(unsigned char address,unsigned char data);
unsigned char I2cRead(unsigned char address);

#endif

#define Single_ReadI2C     I2cRead
#define Single_WriteI2C    I2cWrite
#define IIC_Init           i2c_init
  


