/*
 *  ESP32:        MPU6050:         
 *    3V3             VCC             
 *    GND             GND          
 *    D22             SCL             
 *    D21             SDA     
 */

#include <Wire.h>

const int MPU_addr=0x68;  // endereço I2C do MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x1B);  			//  selecionar range giro
  Wire.write(B00000000);  		// +-250°/s (B000xx000)
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x1C);  			//  selecionar range acel 
  Wire.write(B00000000);  		// +- 2g (B000xx000)
  Wire.endTransmission(true); 

  //Serial.println("aX,aY,aZ,gX,gY,gZ");

}


void loop()
{ 
   Wire.beginTransmission(MPU_addr);
   Wire.write(0x3B);  // iniciando com 0x3B (ACCEL_XOUT_H)
   Wire.endTransmission(false);
   Wire.requestFrom(MPU_addr,14,true);  // total de 14 registradores
   AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
   AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
   AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
   Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
   GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
   GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
   GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

   Serial.print(AcX);
   Serial.print(",");
   Serial.print(AcY); 
   Serial.print(",");
   Serial.print(AcZ); 
   Serial.print(",");
   Serial.print(GyX);
   Serial.print(",");
   Serial.print(GyY); 
   Serial.print(",");
   Serial.println(GyZ);

   delay(100);

}
