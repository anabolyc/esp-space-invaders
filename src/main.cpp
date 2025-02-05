/**
 * http://www.emutalk.net/threads/38177-Space-Invaders
 */
#include <stdarg.h>
#include <SPI.h>
#include <r65emu.h>
#include <ports.h>
#include <i8080.h>

#include "io.h"
#include "display.h"
#include "vblank.h"
#include "config.h"

#include "rome.h"
#include "romf.h"
#include "romg.h"
#include "romh.h"

prom e(rome, sizeof(rome));
prom f(romf, sizeof(romf));
prom g(romg, sizeof(romg));
prom h(romh, sizeof(romh));

IO io;
i8080 cpu(memory, io);
ram page;
Display display;
vblank vb(cpu);

static bool paused = false;

static void reset(void) {
	hardware_reset();
	display.begin();
	io.begin();
	paused = false;
}

void setup(void) {

#if defined(DEBUG)
	Serial.begin(SERIAL_BAUD);
#endif

	hardware_init(cpu);
	
	memory.put(h, 0x0000);
	memory.put(g, 0x0800);
	memory.put(f, 0x1000);
	memory.put(e, 0x1800);
	
	// 1k of RAM at 0x2000
	memory.put(page, 0x2000);

	// 7k display RAM at 0x2400
	memory.put(display, 0x2400);

	reset();

	// FIXME: SPI init steals our pin
	pinMode(PIN_BTN_R, INPUT);
	
	Serial.print("RESET");
}

void loop(void) {
	if (kpd.available()) {
		Serial.print('*');
		unsigned scan = kpd.read2();
		Serial.printf("%x\n", scan);
		byte key = scan & 0xff;
		if (is_down(scan))
			io.down(scan);
		else
			switch(key) {
			case PS2_F1:
				reset();
				break;
			case PAUSE:
				paused = !paused;
				break;
			default:
				io.up(key);
				break;
			}
	} else 
	if (!paused && !cpu.halted()) {
		cpu.run(1000);
		vb.tick(millis());
	}
}
