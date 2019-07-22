/*
MIT License

Copyright (c) 2018 Brian T. Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Arduino.h> // Serial
#include "Printer.h"

// All other SAMD boards define SERIAL_PORT_MONITOR as SerialUSB, except for
// the Zero, which defines it to be Serial, which doesn't work. Clobber it.
#if defined(ARDUINO_SAMD_ZERO)
  #undef SERIAL_PORT_MONITOR
  #define SERIAL_PORT_MONITOR SerialUSB
#elif defined(__linux__) or defined(__APPLE__)
  #undef SERIAL_PORT_MONITOR
  #define SERIAL_PORT_MONITOR Serial
#endif

namespace aunit {

Print* Printer::sPrinter = &SERIAL_PORT_MONITOR;

}
