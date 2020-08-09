---
layout: default
title: Finite State Machine for Arduino
description: This is a state machine model, object oriented applied in C++ to be used in line tracking carts (Arduino UNO).
---

## The beginning

When developing for Arduino, focusing on a cart that was able to follow a predetermined line on the floor, I realized that when making structured code in C++ it was a bad thing, it was simpler to develop the logic, but in the long run I saw myself creating several ifs.

<center><img src="https://i.imgur.com/1AraF4i.jpg" height="300"></center>

Yes, this meme represents well what I mean. I had to create checks for the sensors, **all the time**, and there were **several** so I can be sure that everything will go well.
I missed the OOP classes, where we create objects and separate things in an organized way, here the code was linear and its ability to be messy was huge.

<center><img src="https://i.imgflip.com/3mqecd.jpg" width="400"></center>

Such a code is difficult to maintain and confusing even for those who are programming, imagine for someone else outside the project.
It is simpler to do, much simpler, but it is that programmer's choice:
- <span style="color: #d43c2f">**Make simple code to never mess with it later**</span>
- <span style="color: #38ba47">**Or make a code well done to be used later**</span>

Even if you try to modulate this by creating **several methods**, it will only increase the size of the code (which is included in just one .ino file), making the programmer have to hunt down the part of the code in which he has to perform maintenance.
