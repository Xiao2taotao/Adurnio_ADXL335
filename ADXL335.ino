float Vzerog = 1.5;//ADXL335 三轴加速度计 0g 基准电压典型值
int Sensitivity = 300;//ADXL335 三轴加速度计灵敏度参数典型值
void setup()
{
    Serial.begin(115200);
}
void loop()
{
  //获取ADLX335三轴加速度计模拟量
  int x = analogRead(A0);
  int y = analogRead(A1);
  int z = analogRead(A2);
 //将模拟量转换成电压值
  float vx = x * 5.0/1024.0;
  float vy = y * 5.0/1024.0;
  float vz = z * 5.0/1024.0;
 //将模拟量转换成每个轴向的g值,1.5是三轴加速度计的0g基准电压,单位为V,300是三轴加速度计的灵敏度,单位是mv/g
  float Rx = (vx - Vzerog)/(Sensitivity / 1000.0);
  float Ry = (vy - Vzerog)/(Sensitivity / 1000.0);
  float Rz = (vz - Vzerog)/(Sensitivity / 1000.0);
 //得出重力加速度g值大小
  float R = sqrt(pow(Rx,2) + pow(Ry,2) + pow(Rz,2));
 //计算与三轴的夹角对应弧度值
  float Axr = acos(Rx/R);
  float Ayr = acos(Ry/R);
  float Azr = acos(Rz/R);
  Serial.println(Azr);
 //将水平弧度值转换为对应角度,并通过串口打印
  float anglex = 180.0 * Axr / 3.14;
  float angley = 180.0 * Ayr / 3.14;
  float anglez = 180.0 * Azr / 3.14;
  Serial.print("anglex = ");
  Serial.print(anglex);
  Serial.print("  angley = ");
  Serial.print(angley);
  Serial.print("  anglez = ");
  Serial.println(anglez);
  delay(300);  
 }
