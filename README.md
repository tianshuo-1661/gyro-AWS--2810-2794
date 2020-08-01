#A13 摇摇乐（陀螺仪+AWS）项目介绍

摇动开发板并利用板载陀螺仪采集数据，并且将数据处理之后通过QSPI接口传给ESP32然后上传到AWS的云端服务器，在服务器端显示出一分钟内开发板被摇动的次数。利用FPGA高速的特点，将其获得的数据传给ESP32并且传给云端服务器，能够实现对数据和开发板状态的监测。

本项目包含两个部分：FPGA部分和ESP32部分

FPGA部分在vivado上通过Verilog语言实现，ESP32部分在Arduino上通过C++语言实现，
板卡型号为Xilinx公司的xc7s15ftgb196-1，无需外设即可使用
![](/Images/SEA.jpg)

#仓库目录介绍

Sourcecode：存放有项目源代码，包含FPGA部分和ESP32部分
ExecutableFiles：存放有可直接下载到板卡使用的FPGA比特流文件

| 序号 | 名称                                                      | 描述                                |
| ---- | ------------------------------------------------------------ | ------------------------------------------ |
| 1    | [FPGA PART](/Sourcecode/FPGA PART)                           | FPGA部分的工程，基于vivado2018.3，语言verilog  |
| 2    | [ESP32 PART](/Sourcecode/ESP32 PART)                           | ESP32部分的工程，基于Arduino，语言C++  |

作品照片

![](/Images/AWS.jpg)