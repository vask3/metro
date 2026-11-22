# metro 🚇

so basically this is my custom PCB project called **metro** — it's a mini LED map of the Sofia metro line 2 because why not make hardware projects about public transport B)

## what's on the board?
- **ESP32-C3-MINI-1-N4** (the brain driving the LEDs and handling USB stuff)[cite: 2]
- **13x WS2812B-2020** addressable LEDs wired in a chain along the line (from Obelya all the way to Vitosha)[cite: 2]
- **16-pin USB-C** connector for power and programming over `IO18`/`IO19`[cite: 2]
- **AMS1117-3.3** voltage regulator stepping 5V down to 3.3V[cite: 2]
- **BOOT** button (`TS-1187A-B-A-B`) on `IO9` and a 10kΩ pull-up on `EN`[cite: 1, 2]
- 5.1kΩ CC resistors on USB-C, decoupling capacitors, and a data resistor on the LED line so it doesn't instantly fry[cite: 2, 3]

## how it works
- the ESP32 sends data out on `DATA_OUT` through the resistor into the first WS2812B, then each LED passes the signal along to the next one[cite: 2, 3]
- power comes in through USB-C (`+5V` feeds the LED chain and the AMS1117-3.3 regulator, which gives `+3V3` to the ESP32)[cite: 2, 3]
- laid out in EasyEDA Pro (v4.1) with aligned LEDs and a metro map graphic on top[cite: 7, 10, 12]

## files in here:
- `SCH_Schematic1_2026-11-13.pdf` — the circuit schematic I drew in EasyEDA
- PCB layout files — board layout, routing, and design files in EasyEDA Pro[cite: 7, 10]
- test firmware — simple Arduino NeoPixel sketch to blink/sweep all 13 LEDs and check the chain

## status
schematic is checked and DRC is clear[cite: 2], PCB layout and routing are wrapped up/getting cleaned up before ordering boards[cite: 11, 12], next up is soldering and flashing the test code
