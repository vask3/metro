# metro — build journal 🚇

a running log of designing, routing, and putting together my custom sofia metro line 2 PCB.

### nov 13, 2026 — schematic & initial PCB layout

* **the idea:** wanted to make a cool hardware desk piece, and since public transport is great, a mini LED map of sofia metro line 2 (from obelya down to vitosha) made total sense.
* **component selection:**
  * went with the **ESP32-C3-MINI-1-N4** since it has native USB (`IO18`/`IO19`), saving board space by skipping an external USB-to-UART chip.
  * picked **13x WS2812B-2020** addressable RGB LEDs—small enough to fit cleanly along the route without crowding the silkscreen graphic.
  * added a 16-pin USB-C port (with the proper 5.1kΩ CC resistors so C-to-C cables actually work), an **AMS1117-3.3** LDO, a `BOOT` button on `IO9`, decoupling caps, and a series resistor on the `DATA_OUT` line to keep the first LED happy.
* **easyeda pro:** drew the schematic (`SCH_Schematic1_2026-11-13.pdf`), laid out the board in EasyEDA Pro v4.1, aligned the LEDs to the metro line graphic, and got a clean DRC check. exported the initial gerbers, BOM, and pick-and-place files.

### nov 14, 2026 — repo setup, production files & docs

* **github repo:** pushed the initial files to `vask3/metro` and added an MIT license.
* **organizing fabrication files:** moved `Gerber.zip`, `BOM_Board1_PCB1_2026-11-13.xlsx`, and `PickAndPlace_PCB1_2026_11_13.xlsx` into a dedicated `production/` folder so the root directory stays clean and ready for JLCPCB.
* **documentation:** wrote up the `README.md` with the hardware breakdown and added screenshots of the schematic and board layout to visualize how it's coming together.

### nov 22, 2026 — CAD files, EasyEDA project backup & test firmware

* **source & mechanical files:** uploaded the full EasyEDA Pro project file (`ProPrj_metro track...`) and added a `cad/` folder (getting ready for an enclosure/stand or 3D fit checks).
* **firmware:** wrote and pushed `firmware.ino`—a simple Arduino NeoPixel test sketch to blink and sweep through all 13 stations so I can immediately verify the LED chain and data signal once the boards arrive.
* **cleanup:** refactored the `README.md` for better readability and formatting.

### up next

* [ ] order PCBs and components
* [ ] solder the board (especially carefully around those tiny 2020 LEDs and USB-C pins)
* [ ] flash `firmware.ino` over native USB and verify all 13 stations light up properly
* [ ] design/print a case or stand from the `cad/` files
