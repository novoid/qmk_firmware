# Kinesis Neolike

This keyboard behaves like the `kinesis:default` layout (with minor bugfixes), but it has a numpad layer like the original firmware. With progm-F9, the function labeled RESET, the bootloader can be activated.

But here comes the specialty of this layout: In emulates the [Neo2](https://neo-layout.org/)-layout inside the keyboard! To switch to Neo mode, press progm-F2. To switch back to QWERTY, press progm-F3. The layout in Neo mode is similar to a regular Kinesis with the Neo2 driver on the computer and looks like this:

![layout](neolayout.png)

Blue glyphs represent numpad scancodes, red symbols represent mouse keys. To use the latter, hold shift and mod3 (labelled "caps lock") with the left pinkie.

The layout uses scancodes when possible, Unicode when necessary. You need to configure as follows:

System | Combination to enable | Keyboard layout to be selected in the OS
--- | --- | ---
Windows Classic | progm-F4 (labelled "dvork") | US International
Mac | progm-F5 (labelled "mac") | Unicode Hex Input
IBus enabled systems | progm-F6 (labelled "pc") | US International with all the dead keys
Windows Compose | progm-F7 (labelled "win") | US International (you also have to have [WinCompose](https://github.com/samhocevar/wincompose) running)

Currently, the Neo mode emulates the first 4 layers of the Neo2 layout. The right side of layer 5 is used by mouse keys. Please note that there is no numpad in Neo mode as that would be too confusing. Tha basic numpad scancodes are available on Neo layer 4, the symbols on higher numpad layers are unavailable. 

## To do

* Implement Neo layers 5 and 6. Make mouse keys optional to free layer 5 of them
* Save state to EEPROM
* Do more cool stuff with the 4 LEDs