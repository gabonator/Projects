# Motor inverter RS485 interface with arduino

Supports Invt Good drive inverters with MAX485 RS485 interface, serial config 19200 bauds, 8 data bits, even parity, one stop bit (8E1).
Methods for easy creation of read and write packets, simple packet and failure decoder.

- Arduino - initial testing application for regular arduino (including log)
- Esp32 - esp32 web server sending realtime vfd data over internet

More resources can be found in LA104 repository. There is advanced visualization tool and also Invt GD10 mini simulator.
