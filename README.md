# metro 🚇

That's my custom PCB project called **metro** — it's a mini LED map of the Sofia metro line 2

## what's on the board?
- **ESP32-C3-MINI-1-N4** (the brain )
- **13x WS2812B-2020** addressable LEDs wired in a chain along the line (from Obelya to Vitosha)
- **16-pin USB-C** connector for power and programming over `IO18`/`IO19`
- **AMS1117-3.3** voltage regulator stepping 5V down to 3.3V
- **BOOT** button (`TS-1187A-B-A-B`) on `IO9` and a 10kΩ pull-up on `EN`
- 5.1kΩ CC resistors on USB-C, 

<img width="483" height="621" alt="Screenshot 2026-11-13 201517" src="https://github.com/user-attachments/assets/fa414ce0-8324-4c33-b8e8-984af208c110" />
<img width="1080" height="921" alt="Screenshot_20261114_063259_Samsung Browser" src="https://github.com/user-attachments/assets/8b1175bf-6353-472f-a1e7-dc17965042cd" />

## how it works
- the ESP32 sends data out on `DATA_OUT` through the resistor into the first WS2812B, then each LED passes the signal along to the next one
- power comes in through USB-C (`+5V` feeds the LED chain and the AMS1117-3.3 regulator, which gives `+3V3` to the ESP32)
- laid out in EasyEDA Pro (v4.1) with aligned LEDs and a metro map graphic on top

## files in here:
- `SCH_Schematic1_2026-11-13.pdf` — the circuit schematic
- PCB layout files — board layout, routing
- test firmware — simple Arduino NeoPixel sketch to blink all 13 LEDs and check the chain

## status
schematic is checked and DRC is clear, PCB layout and routing are wrapped up/getting cleaned up before ordering boards, next up is soldering and flashing the test code. Awaiting fabrication!
