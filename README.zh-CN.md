# OhMyGenius
哈罗，欢迎来到冬阑（Donlan）的作品仓库！

在这个仓库中，我分享了一些简单有趣的科技电子类DIY作品，这些作品通常使用现成的电子模块或开发板，搭配独立设计的乐高框架和外壳，希望你喜欢。

Github不常在线，有问题可以来[Bilibili主页](https://space.bilibili.com/225137757)私信我，或者在对应项目视频下方评论。
<br/>

## 目录
- [Common](#Common)
- [LEGOxGBA](#LEGOxGBA)
- [BatmanHat](#BatmanHat)
- [CoinPusher](#CoinPusher)
- [Arcade](#Arcade)
<br/>

## 项目介绍
### Common
一个教程文档目录，包含树莓派Raspberry Pi、STM32、ESP32等开发板以及简单电路或代码的一些基础概念和入门教学，我会尽可能用简单易懂的方式进行讲解，以便让没什么基础的人也能快速理解和上手。

- **什么是树莓派？**
树莓派，Raspberry Pi，简单来说就是一台能够控制电路的迷你电脑，可以用来开发各种各样的小型设备：
 <img src=".\\Common\\RaspberryPi_4B.jpg" width = "256" height = "152" alt="Raspberry Pi" title="Raspberry Pi"/>
具体参考以下链接：
  - [官方网站(英文)](https://www.raspberrypi.org/)
  - [树莓派实验室(中文)](https://shumeipai.nxez.com/intro-faq)
<br/>

- **什么是STM32开发板？**
STM32是[意法半导体公司](https://www.st.com/)生产的一系列MCU（微控制单元，即常说的单片机），下图是STM32的热门型号F103C8T6：
 <img src=".\\Common\\STM32f103c8t6_MCU.png" width = "128" height = "103" alt="STM32f103c8t6" title="STM32f103c8t6"/>
这种芯片无法直接使用，于是将其集成在电路板上，引出各针脚，以便进行快速开发，这种可以批量生产销售的成品电路板就是俗称的开发板。下图是常用型号F103C8T6的一款开发板，俗称Blue Pill：
 <img src=".\\Common\\BluePill.png" width = "256" height = "151" alt="Blue Pill" title="Blue Pill"/>
  > 注意，因近两年芯片产能严重不足，STM32F103C8T6价格飙升，且市售开发板使用二手芯片、国产芯片以次充好等问题严重，如具备一定的编程能力，建议选购更有性价比的STM32F4系列或其它开发板。

  - [官方论坛(中文)](https://www.stmcu.org.cn/)

  类似的还有Arduino，这里不再详细介绍，具体参考以下链接：
  - [官方网站(英文)](https://www.arduino.cc/)
  - [Arduino实验室(中文)](https://arduino.nxez.com/)
<br/>

- **什么是ESP32开发板？**
ESP32是[乐鑫公司](https://www.espressif.com/products/socs/esp32)生产的一系列MCU系统级芯片(SoC)，支持Wi-Fi和蓝牙双模无线通信。非常适合用于制作低功耗蓝牙产品和Wi-Fi物联网设备等。该产品型号较多，市售开发板型号爆炸，新手建议购买官方或者[安信可](https://docs.ai-thinker.com/esp32)的开发板，因为硬件相对稳定，文档也比较齐全。
 <img src=".\\Common\\ESP32.png" width = "256" height = "174" alt="ESP32" title="ESP32"/>
官方提供了大量开源例程以供学习使用，在一些需求上完全可以替代STM32开发板，甚至更加方便。

关于上述各类产品更详细的使用说明见Common目录下的对应文档。
<br/>

### LEGOxGBA
GBA掌机：以树莓派开发板和RetroPie系统为核心制作的乐高GBA。
[Bilibili视频链接](https://www.bilibili.com/video/BV1gT4y1N7GM/)
<img src=".\\LEGOxGBA\\LEGOxGBA.png" width = "600" height = "400" alt="GBA" title="GBA"/>
这是一个早期项目，设计相对粗糙，仅供参考。
<br/>

### BatmanHat
蝙蝠帽：使用STM32开发板和超声波测距模块制作的帽子，用于检测眼前物品的距离，例如，当眼睛离手机或书本距离太近时会发出警告。
[Bilibili视频链接](https://www.bilibili.com/video/BV1Ch411y7vo/)
<img src=".\\BatmanHat\\BatmanHat.png" width = "600" height = "400" alt="BatmanHat" title="BatmanHat"/>
这是一个早期项目，设计相对粗糙且实用性较低，使用Keil5编写代码，使用PWM播放音频，门槛相对高一点，因此仅供参考。
<br/>

### CoinPusher
推金币机：使用STM32开发板和步进电机制作的推金币机迷你版。
[Bilibili视频链接](https://www.bilibili.com/video/BV1Y64y1D7gz/)
<img src=".\\CoinPusher\\CoinPusher.png" width = "600" height = "400" alt="CoinPusher" title="CoinPusher"/>
这是一个设计相对完整的项目，电路也比较简单，使用Keil5编写代码。
<br/>

### Arcade
街机：以树莓派开发板和RetroPie系统为核心制作的街机。
[Bilibili视频链接](https://www.bilibili.com/video/BV17U4y1j7hG/)
<img src=".\\Arcade\\Arcade.png" width = "600" height = "400" alt="Arcade" title="RaspberryPi Arcade"/>
这是一个设计相对完整的项目，框架结构和电路稍微复杂，适合学习参考。
<br/>