/*******************************************************************************
 * %%SECTION_HEADER%%
 * This header information is automatically generated by KodeUtils.
 *
 * File 'ghostly-light.scad' edited by kwendenarmo, last modified: 2018-12-22.
 * This file is part of 'Ghostly light' package, please see the readme files 
 * for more information about this file and this package.
 *
 * Copyright (C) 2018 by Kwendenarmo <kwendenarmo@akornsys-rdi.net>
 * Released under the GNU General Public License
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * %%EOS_HEADER%%
 ******************************************************************************/


/*******************************************************************************
 *  D E D I C A T I O N:
 *  - This project was originally conceived as a gift to my friend Isi, and
 *    developed as a thank-you present.
 *
 *    Still, you're free to reuse this project for whatever you want, even if
 *    it's as shabby as decorative lights or as a gift to other people, knowing
 *    they'll never be as cool as my good friend. If you are only going to use
 *    the hardware of this project as a development environment for your own
 *    applications, make sure they are inclusive and creative. Do it for my
 *    friend. Thank you and happy hacking. -
 ******************************************************************************/


$fn=36;

%ghost();
translate([0, 0, 10]) rotate([0, 0, 180]) pcb();
%cover();

// Printing aid
*difference() {
    cylinder(r = 37 / 2, h = 0.2);
    translate([0, 0, -1]) cylinder(r = 31 / 2, h = 13);
    for(i = [0:2]) {
        rotate([0, 0, (i / 3 * 360) + 90]) translate([0, -0.75, -0.1]) translate([-32.5 / 2, 0, 0]) cube([32.5, 1.5, 2]);
    }
}

module ghost() {
    width = 37;
    height = width * 0.66;

    difference() {
        //body
        union() {
            cylinder(r = width / 2, h = height);
            translate([0, 0, height]) sphere(r = width / 2);
        }
        union() {
            //eyes
            for (i = [-27, 27]) {
                rotate([0, 0, i]) translate([0, -width / 1.9, height]) difference() {
                    sphere(d = width / 4);
                    translate([width / 8.75, width / 7 - width / 14, 0]) rotate([90, 0, 0]) cylinder(r = width / 14, h = width / 14);
                }
            }
            //legs?
            translate([0, 0, -0.1])  for(i = [0 : 5]) {
                rotate([0, 0, i / 6 * 360]) hull() {
                    translate([width / 12, -0.05, 0]) cube([0.1, 0.1, 0.1]);
                    translate([width, -(width / 3), 0]) cube([0.1, width / 1.5, 0.1]);
                    translate([width, -0.05, width / 2]) cube([0.1, 0.1, 0.1]);
                }
            }
            //mouth
            translate([0, 0, 11]) difference() {
                translate([0, -15.5, 0]) for(i = [-5,0,5]) {
                    translate([i, 0, 0]) union() {
                        hull() {
                            translate([-1, 0, 5]) cube([2, 4, 0.1]);
                            translate([-3.5, 0, 0]) cube([2, 4, 0.1]);
                        }
                        hull() {
                            translate([-1, 0, 5]) cube([2, 4, 0.1]);
                            translate([1.5, 0, 0]) cube([2, 4, 0.1]);
                        }
                    }
                }
                difference() {
                    translate([0,0,-1]) cylinder(r=37/2, h=7);
                    translate([0,0,-2]) cylinder(r=32/2, h=9);
                }
            }
            //pcb opening
            translate([0, 0, -1]) cylinder(r = 31 / 2, h = 13);
            //pcb stop
            translate([0, 0, 11.9]) cylinder(r1 = 31 / 2, r2 = 29 / 2, h = 1.7);
            //upper hollow
            translate([0, 0, 13.5]) cylinder(r1 = 29 / 2, r2 = 20 / 2, h = 20);
            //tabs cover
            for(i = [0:2]) {
                rotate([0, 0, (i / 3 * 360) + 90]) translate([0, -0.75, 2.35]) hull() {
                    translate([-32.5 / 2, 0, 0]) cube([32.5, 1.5, 0.1]);
                    translate([-30.5 / 2, 0, 2.25]) cube([30.5, 1.5, 0.1]);
                }
                rotate([0, 0, (i / 3 * 360) + 90]) translate([0, -0.75, -0.1]) translate([-32.5 / 2, 0, 0]) cube([32.5, 1.5, 2]);
            }
            //connectors pins
            rotate([0, 0, 180]) for (i = [ [(24.192388 - 15), (15 - 5.807612), 11], [(26.006552 - 15), (15 - 8.082211), 11], [(27.269412 - 15), (15 - 10.703313), 11], [(27.917714 - 15), (15 - 13.539631), 11], [(27.918983 - 15), (15 - 16.449096), 11], [(27.273157 - 15), (15 - 19.285979), 11], [(26.012586 - 15), (15 - 21.908182), 11], [(24.200407 - 15), (15 - 24.184362), 11] ]) {
                translate(i) cylinder(r=1, h=10);
            }
            //switch hole
            translate([-4.35, (width / 2) -5, 10.6]) cube([8.7, 6, 3.4]);
            //debug
            *translate([0, -width / 2, -0.1]) cube(width);
            *translate([-width / 2, 0, -0.1]) cube(width);
        }
    }
}

module cover() {
    width = 30.5;
    height = 9.75;

    difference() {
        union() {
            //body
            cylinder(r = width / 2, h = height);
            //tabs
            for(i = [0:2]) {
                rotate([0, 0, (i / 3 * 360) + 90]) translate([0, -0.5, 2.5]) hull() {
                    translate([-32 / 2, 0, 0]) cube([32, 1, 0.1]);
                    translate([-width / 2, 0, 2]) cube([width, 1, 0.1]);
                }
            }
        }
        union() {
            //legs?
            translate([0, 0, -0.1])  for(i = [0 : 5]) {
                rotate([0, 0, i / 6 * 360]) hull() {
                    translate([width / 12, -0.05, 0]) cube([0.1, 0.1, 0.1]);
                    translate([width, -(width / 3), 0]) cube([0.1, width / 1.5, 0.1]);
                    translate([width, -0.05, width / 2]) cube([0.1, 0.1, 0.1]);
                }
            }
            //coin cell socket
            translate([-1, 0, height - 4.25]) hull() {
                translate([1, 0, 0]) cylinder(r = 10.5, h = 5);
                translate([-1, 0, 0]) cylinder(r = 10.5, h = 5);
                translate([-3.81, -11.02, 0]) cube([10.15, 22.25, 5]);
                translate([8, 8.5, 0]) cylinder(r = 1.5, h = 5);
                translate([8, -8.5, 0]) cylinder(r = 1.5, h = 5);
            }
            translate([-3, -12.12, height - 3.25]) cube([6, 24.25, 5]);
            //connectors pins
            rotate([0, 0, 180]) for (i = [ [(24.192388 - 15), (15 - 5.807612), 8], [(26.006552 - 15), (15 - 8.082211), 8], [(27.269412 - 15), (15 - 10.703313), 8], [(27.917714 - 15), (15 - 13.539631), 8], [(27.918983 - 15), (15 - 16.449096), 8], [(27.273157 - 15), (15 - 19.285979), 8], [(26.012586 - 15), (15 - 21.908182), 8], [(24.200407 - 15), (15 - 24.184362), 8] ]) {
                translate(i) cylinder(r=1.25, h=3);
            }
            //debug
            *translate([-width / 2, 0, -0.1]) cube(width);
        }
    }
}

module pcb() {
    substrate=1.6;

    //PCB
    color("green") cylinder(r = 15, h = substrate);
    //Top components
    translate([0, 0, substrate]) union() {
        //PLCC4
        union() {
            color("ivory") translate([-2.5, -2.5, 0]) cube([5, 5, 1.65]);
            color("lightgray") for (i = [-1.65, 1.65]) {
                translate([-2.7, i - 0.45, 0]) cube([5.4, 0.9, 0.7]);
            }
        }
        //SOIC8
        translate([15.113 - 15, 15 - 5.715, 0]) union() {
            color("dimgrey") translate([-2, -2.5, 0]) cube([4, 5, 1.75]);
            color("lightgray") for (i = [-1.905, -0.635, 0.635, 1.905]) {
                translate([-3.1, i - 0.255, 0]) cube([6.2, 0.51, 1.13]);
            }
        }
        //SOT23
        translate([4.826 - 15, 15 - 14.986, 0]) union() {
            color("dimgrey") translate([-0.875, -1.525, 0]) cube([1.75, 3.05, 1.1]);
            color("lightgray") for (i = [-0.95, 0,0.95]) {
                translate([-1.525, i - 0.25, 0]) cube([3.05, 0.5, 0.6]);
            }
        }
        //PCM12
        translate([14.986 - 15,15 - 27.051, 0]) union() {
            color("silver") translate([-3.35, -1.3, 0]) cube([6.7, 2.6, 1.4]);
            color("grey") translate([-0.65 + 0.75, -1.5 - 1.3, 0]) cube([1.3, 1.5, 1.1]); //OFF
            color("grey") translate([-0.65 - 0.75, -1.5 - 1.3, 0]) cube([1.3, 1.5, 1.1]); //ON
            color("lightgray") for (i = [-1.09, 1.09]) {
                translate([-3.65, i - 0.2, 0]) cube([7.3, 0.4, 0.2]);
            }
            color("lightgray") for (i = [-2.25, 0.75, 2.25]) {
                translate([i - 0.2, -1.29, 0]) cube([0.4, 3.5, 0.2]);
            }
        }
        //0603 R
        translate([(15.113 - 15), (15 - 2.159), 0]) union() {
            color("slategray") translate([-0.775, -0.425, 0]) cube([1.55, 0.85, 0.45]);
            color("lightgray") for (i = [-0.65, 0.65]) {
                translate([i - 0.15, -0.425, 0]) cube([0.3, 0.85, 0.5]);
            }
        }
        translate([(4.826 - 15), (15 - 19.304), 0]) union() {
            color("slategray") translate([-0.775, -0.425, 0]) cube([1.55, 0.85, 0.45]);
            color("lightgray") for (i = [-0.65, 0.65]) {
                translate([i - 0.15, -0.425, 0]) cube([0.3, 0.85, 0.5]);
            }
        }
        translate([(4.826 - 15), (15 - 17.653), 0]) union() {
            color("slategray") translate([-0.775, -0.425, 0]) cube([1.55, 0.85, 0.45]);
            color("lightgray") for (i = [-0.65, 0.65]) {
                translate([i - 0.15, -0.425, 0]) cube([0.3, 0.85, 0.5]);
            }
        }
        translate([(7.62 - 15), (15 - 14.859), 0]) rotate([0, 0, 90]) union() {
            color("slategray") translate([-0.775, -0.425, 0]) cube([1.55, 0.85, 0.45]);
            color("lightgray") for (i = [-0.65, 0.65]) {
                translate([i - 0.15, -0.425, 0]) cube([0.3, 0.85, 0.5]);
            }
        }
        //0603 C
        translate([(13.462 - 15), (15 - 11.303), 0]) union() {
            color("tan") translate([-0.8, -0.4, 0]) cube([1.6, 0.8, 0.8]);
            color("lightgray") for (i = [-0.68, 0.68]) {
                translate([i  -0.125, -0.425, 0]) cube([0.25, 0.85, 0.85]);
            }
        }
        translate([(9.144  -15), (15 - 14.859), 0]) rotate([0, 0, 90]) union() {
            color("tan") translate([-0.8, -0.4, 0]) cube([1.6, 0.8, 0.8]);
            color("lightgray") for (i = [-0.68, 0.68]) {
                translate([i-0.125, -0.425, 0]) cube([0.25, 0.85, 0.85]);
            }
        }
        translate([(4.826 - 15), (15 - 10.033), 0]) union() {
            color("tan") translate([-0.8, -0.4, 0]) cube([1.6, 0.8, 0.8]);
            color("lightgray") for (i = [-0.68, 0.68]) {
                translate([i - 0.125, -0.425, 0]) cube([0.25, 0.85, 0.85]);
            }
        }
        //1007 L
        translate([(4.826 - 15), (15 - 11.938), 0]) union() {
            color("darkgray") translate([-1.25, -0.9, 0]) cube([2.5, 1.8, 1.8]);
            color("lightgray") for (i = [-1.1, 1.1]) {
                translate([i-0.25, -0.925, 0]) cube([0.5, 1.85, 1.85]);
            }
        }
        //Conn
        union() {
            translate([(24.192388 - 15), (15 - 5.807612), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(26.006552 - 15), (15 - 8.082211), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(27.269412 - 15), (15 - 10.703313), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(27.917714 - 15), (15 - 13.539631), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(27.918983 - 15), (15 - 16.449096), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(27.273157 - 15), (15 - 19.285979), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(26.012586 - 15), (15 - 21.908182), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
            translate([(24.200407 - 15), (15 - 24.184362), 0]) union() {
                color("gold") translate([-0.32, -0.32, -3.05]) cube([0.64, 0.64, 11.43]);
                color("dimgrey") translate([-1.22, -1.22, 0]) cube([2.44, 2.44, 2.54]);
            }
        }
    }
    //Bottom components
    mirror([0, 0, 1]) union() {
        //Coin cell
        translate([0, 0, 0.01]) union() {
            color("gainsboro") cylinder(r = 10, h = 3.2);
            color("silver") difference() {
                translate([(15.01 - 15) - 8.73, (15 - 15.01) - 10.605, 0]) cube([16.12, 21.21, 4.06]);
                union() {
                    translate([7.5, 7, -1]) rotate([0, 0, 45]) cube(6);
                    mirror([0, 1, 0]) translate([7.5, 7, -1]) rotate([0, 0, 45]) cube(6);
                    translate([-10, 8, -1]) rotate([0, 0, 30]) cube(6);
                    mirror([0, 1, 0]) translate([-10, 8, -1]) rotate([0, 0, 30]) cube(6);
                    translate([-16.72, 0, -1]) cylinder(r = 10, h = 6);
                }
            }
            color("lightgray") for (i = [-1.525, 1.525]) {
                translate([i - 1.015, -11.62, 0]) cube([2.03, 23.24, 0.2]);
            }
        }
    }
}

