# invaders

Space Invaders emulation on
[Stellarpad](http://www.energia.nu/Guide_StellarisLaunchPad.html) using 
[Energia](http://energia.nu/).

For more information, see this 
[thread](http://www.emutalk.net/threads/38177-Space-Invaders).

The i8080 emulation isn't perfect but good enough to play Space Invaders properly.
I used this [testsuite](http://www.idb.me.uk/sunhillow/8080.html) to find bugs.

Kudos to [MoleskiCoder](https://github.com/MoleskiCoder/invaders) for
pointers to sound emulation.

## Hardware

Please check on [linked repository](https://github.com/anabolyc/esp8266-radio-box)

![image](https://user-images.githubusercontent.com/5459747/214706479-fb7e05c2-70d4-4175-8b42-7f2b41fac433.png)
![image](https://user-images.githubusercontent.com/5459747/214706526-cc0a864f-6939-46cd-b47f-48b1271820fb.png)

## How to use

Since [my device](https://www.tindie.com/products/sonocotta/esp8266-tamagotchi-diy-kit/) has only 3 keys, I had to assign actions to both short and long press.

|             | LEFT           | MIDDLE        | RIGHT          |
|-------------|----------------|---------------|----------------|
| SHORT PRESS | PLAYER 1 LEFT  | PLAYER 1 FIRE | PLAYER 1 RIGHT |
| LONG PRESS  | PLAYER 1 START | PLAYER 1 COIN | PAUSE GAME     

As you can see Player 2 is not mapped at all. Although emulator capable of it, this game is single player only.
