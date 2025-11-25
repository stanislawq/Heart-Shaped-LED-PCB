# Heart-Shaped LED PCB

This repository contains a complete hardware and firmware project for a custom heart-shaped LED PCB powered by an ATmega328P-AU microcontroller.  
The board was designed as a pet-project and combines PCB design in Altium Designer, embedded C/C++ firmware (Arduino-compatible) and manual SMD assembly.
I must highlight that this project is ready for commercial production.

The device forms a portable, battery-powered LED keychain with multiple operating modes controlled by a single push button.

---

## Features

- **Heart-shaped LED layout** with 16 surface-mount LEDs arranged along the outline of a heart.
- **ATmega328P-AU microcontroller** (Arduino-compatible), using the internal oscillator.
- **Single tactile button**:
  - short press: toggles between “all off” and “all on” modes
  - long press: enables a “beating heart” animation
- **Multiple LED modes**
  1. All LEDs off  
  2. All LEDs on  
  3. Animated sequence that lights LED pairs around the heart perimeter
- **In-system programming (ISP)** pads broken out on the bottom side (MISO, MOSI, SCK, RESET, VCC, GND).
- **Production-ready files**:
  - Altium project (`.PrjPcb`, `.SchDoc`, `.PcbDoc`)
  - Gerber and drill files
  - BOM and pick-and-place data
  - Design rule check reports and status reports

---

## Repository Structure

```text
heart-shaped-led-pcb/
├── docs/
│   └── Report.pdf                   # project documentation
├── firmware/
│   └── heart_led.ino                # Arduino-compatible firmware
├── hardware/
│   ├── altium/                      # source Altium project
│   │   ├── present_pcb.PrjPcb
│   │   ├── PCB3.PcbDoc
│   │   ├── Sheet3.SchDoc
│   │   ├── PcbLib1.PcbLib
│   │   └── present_pcb.BomDoc
│   ├── bom/
│   │   └── present_pcb.xlsx         # BOM exported from Altium
│   ├── exports/                     # reports and auxiliary files
│   │   ├── Design Rule Check - PCB3.drc
│   │   ├── Design Rule Check - PCB3.html
│   │   ├── PCB3-macro.APR_LIB
│   │   ├── PCB3.REP
│   │   ├── Pick Place for PCB3.csv
│   │   ├── Pick Place for PCB3.txt
│   │   └── Status Report.Txt
│   └── gerbers/                     # production files for manufacturing
│       ├── PCB3.GBL
│       ├── PCB3.GBO
│       ├── PCB3.GBP
│       ├── PCB3.GBS
│       ├── PCB3.GD1
│       ├── PCB3.GG1
│       ├── PCB3.GKO
│       ├── PCB3.GM
│       ├── PCB3.GM1
│       ├── PCB3.GM13
│       ├── PCB3.GM20
│       ├── PCB3.GM23
│       ├── PCB3.GM5
│       ├── PCB3.GPB
│       ├── PCB3.GPT
│       ├── PCB3.GTL
│       ├── PCB3.GTO
│       ├── PCB3.GTP
│       ├── PCB3.GTS
│       ├── PCB3.LDP
│       └── PCB3.TXT
└── images/
    ├── 3D_Model_Back.png
    ├── 3D_Model_Top.png
    ├── bare_pcb_back.jpg
    ├── bare_pcb_front.jpg
    ├── heart_pcb_assembled_back.jpg
    ├── heart_pcb_assembled_front.jpg
    ├── Mechanical_top_layout.png
    ├── pcb_top_layout.png
    └── Schematic.png
