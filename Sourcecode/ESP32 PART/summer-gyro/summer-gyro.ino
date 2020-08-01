#include "sea_esp32_qspi.h"
#include "aa_esp32_start.h"
#include "esp32wifi.h"
float rea(int fir)
{
    uint8_t data0[2];
    int16_t *ad_data;
    SeaTrans.read(fir, data0, 2);
    ad_data = (int16_t*)data0;
    return *ad_data / 10000.0;    
}
////////
void setup()
{ esp23_start();//load the bitsream
  aws_begin();
  aws_receive();
  Serial.begin(115200);
  SeaTrans.begin();
}
uint8_t i=0;
int flag=0;//Indicates whether to reset the module
char x[512];
void loop()
{ 
 uint32_t tim,TIM;
  while(rea(0)>1.50||rea(2)>1.50||rea(4)>1.50)//Calculation number module
   { if(flag==1)
      {
        flag=0;
       i=0;
      }
       i++;
      if(i==1)
    { if(tim<60000)//The design has a timing function of 60s.
       {
       tim=millis();//Record time
       }
       else
       {
       tim=0;
       }
      TIM=millis();
      sprintf(x,"Start the clock"); 
      aws_print(x);//Transfer to AWS
    }
     else
    {
            tim=millis()-TIM;//Recording time difference
      }
    if(tim<60000)  
    {
    sprintf(x,"%3d %.2fs",i,i==1?0:tim/1000.0);//Output times and time
    aws_print(x);
    }          
    else if(flag==0)
      {
        sprintf(x,"The clock is over, and your number of shakes is %d",i-1);//Total number of output
        aws_print(x);
        flag=1;
     }          
  delay(300);
 }        
}
