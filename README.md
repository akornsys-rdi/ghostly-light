# Ghostly Light

Ghostly light is a small toy project powered by a coin cell, which is inspired by the ghosts of the classic pacman game.
This small toy consists of a plastic shell designed to be 3d-printed, a specific hardware, and a software that generates the different effects.
The plastic shell has the shape of a pacman ghost. It consists of two parts, which allows you to remove the PCB and change the battery. It's recommended to print in translucent neutral color to get a better finish.
The hardware consists of a low power step-up, an ATtiny85 microcontroller and an WS2812B addressable LED. All the pins of the microcontroller are exposed in a header, which makes this PCB also ideal as a development environment for this microcontroller.
When the toy is turned on, it will randomly choose one of the four pacman ghosts. Once (automatically) selected, it will show different animations over time, which are also randomized. The toy does not require any type of interaction with the user, being ideal as a decorative element.

## Dedication:

> This project was originally conceived as a gift to my friend Isi, and developed as a thank-you present.  
> Still, you're free to reuse this project for whatever you want, even if it's as shabby as decorative lights or as a gift to other people, knowing they'll never be as cool as my good friend. If you are only going to use the hardware of this project as a development environment for your own applications, make sure they are inclusive and creative. Do it for my friend. Thank you and happy hacking.

## 3D Printing

For the printing of the plastic shell, it is recommended to use transparent or translucent filament of neutral color. I have used transparent PLA. After some tests, I have achieved the best finish with a maximum layer height of 0.2mm, non-linear infill pattern, such as Slic3r-PE "_Archimedean Chords_" and random seams.

The transparent filament often gives first layer adhesion issues, and since the shell has few contact points on the bed, print may fail. For this reason, I have tried to find the parameters that have worked for me to achieve first layer adhesion and be able to print the shell:

- Bed temperature, 70ºC first layer, 65ºC other layers.
- Two first layers without layer fan.
- First layer speed at 35%.
- Reduce speed to 75% manually to a height of approximately 10mm, restore to 100% after this height.
- 120% extrusion width (flow) in first layer.
- Lower the Z-offset 50µm (**carefully modify not to block the flow of the nozzle or damage the bed!**).

Even so, if the problems persist, I have also generated a plastic shell file `ghost-aid.stl` with a perimeter ring, which should give much less adhesion issues. In return, you have to cut the surplus once printed.

You only need to print a copy of the `ghost.stl` and `ghost-cover.stl` files. No support structure is required for any of the files.

## Electronic design

The electronic design has been made in KiCad EDA, providing a small step-up regulator with on-off switch, power from a coin cell, an ATtiny85 microcontroller with a large breakout header, and a WS2812b addressable LED.

The manufacturing files are located in the `out` folder:

- BoM & CPL: `ghostly-light.xls`
- Gerbers files: `ghostly-light.zip`

The board is also intended as a development environment for ATtiny85 with a reduced form factor and coin cell powered. All microcontroller pins are exposed at the header. The board can be powered externally via the header, as long as the switch is in the off position, without damaging the regulator (see [this post from Texas instruments technical forum](https://e2e.ti.com/support/power-management/f/196/p/198340/707580#707580)).

**NOTE:** No battery life calculation or load adequacy has been performed for this battery. The circuit consumes an average of 40-50 mA.

## Firmware

The code has been made in C for Arduino, for a Digistump board, since it has better support and compilation optimization than other packages with support for the ATtiny85 microcontroller. All the code is extensively commented and documented. Also attached is the compiled binary file.

The compilation has been done with the following software version:

- Arduino IDE 1.8.4-linux64
- Compiler: avr-gcc 4.8.1-arduino5
- Library: Adafruit_NeoPixel 1.1.7
- Board package: Digistump AVR Boards 1.6.7

## Assembly

- Carry out the assembly of the board with all its components. It is recommended to first assemble all of the top side, then the battery holder and finally the header. Three or four unassembled PCB can be used to hold the pins in position while soldering.
- Using the header, and with external power, first burn the fuses of the microcontroller and then upload the program. It should start working. An AVR programmer is required.
- Remove all cables from the header and insert a coin cell. **Make sure that the battery has correctly inserted into its position and with the correct polarity.** When you turn on the board with the switch it should start to work. Switch off.
- Place the PCB over the printed cover. Only fit in one position, with the battery on the underside and the header on the corresponding side.
- Place the shell on top. The hole for the switch on the rear side must be aligned with the switch on the PCB. It may be necessary to remove any unwanted burrs and reliefs from the inside of the shell.
- Lower the shell until it almost closes. Press the shell down until it clicks into place.

To remove the PCB, use a thin element to lever out the cover on each of the legs of the shell.

## License

Copyright (C) 2018 kwendenarmo. This file is part of Ghostly Light

Ghostly Light is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

Ghostly Light is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details

You should have received a copy of the GNU General Public License along with this program. If not, see <[http://www.gnu.org/licenses/](http://www.gnu.org/licenses/ "http://www.gnu.org/licenses/")>.
