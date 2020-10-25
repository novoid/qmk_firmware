# The Helix neolike Layout

For me, the maximum productivity tool is a portable split ortholinear 60% keyboard, the [Helix](../../..), paired with an ergonomic layout, [Neo2](https://neo-layout.org/). To be truely portable, the keyboard has to act like a standard US keyboard, though, so no special driver is required on any computer I connect it to. That's why I created this special layout that does the conversion into scancode for a US keyboard in the firmware and sends all characters not present as Unicode characters.

## Layout

The layout is created in http://www.keyboard-layout-editor.com/. The data is in [neolike.kbd.json](neolike.kbd.json). The layout is based on the Neo2 layout as it worked on my Kinesis Advantage2, but because this 60% keyboard (you could build a 40% 4-row Helix, but then, this layout wouldn't work) has less keys they a 100% keyboard and I had to include mouse mode and some special QMK functions, some Neo2-characters will not be accessible. Also, there's no right Ctrl key and since I had to make the two shifted layers different QMK layers to implement Neo2's caps-lock function, pressing a shift key will not be noticed by the host unless you press another key with it.

All characters that are no part of the standard US keyboard will be sent out using QMK's Unicode function. For that to work, you have to switch to IBus mode (Mod5-x) for Linux, Mac mode (Mod5-u) for Macs and iDevices and WinC mode (Mod5-ü) for Windows, and Windows devices need WinCompose running.


## Customize

see `qmk_firmware/keyboards/helix/rev2/keymaps/neolike/rules.mk`

```
# Helix Spacific Build Options
# you can uncomment and edit follows 7 Variables
#  jp: 以下の7つの変数を必要に応じて編集し、コメントアウトをはずします。
# HELIX_ROWS = 5              # Helix Rows is 4 or 5
# OLED_ENABLE = no            # OLED_ENABLE
# LOCAL_GLCDFONT = no         # use each keymaps "helixfont.h" insted of "common/glcdfont.c"
# LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
# LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
# LED_ANIMATIONS = yes        # LED animations
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```
## Compile

go to qmk top directory.
```
$ cd qmk_firmware
```

build
```
$ make helix:neolike
$ make helix/rev2/back:neolike               # with backlight
$ make HELIX=no_ani helix/rev2/back:neolike  # with backlight without animation
$ make helix/rev2/under:neolike              # with underglow
$ make helix/rev2/oled:neolike               # with oled
$ make helix/rev2/oled/back:neolike          # with oled and backlight
$ make helix/rev2/oled/under:neolike         # with oled and underglow
```

build (experimental use of split_common)
```
$ make helix/rev2/sc:neolike
$ make helix/rev2/sc/back:neolike
$ make helix/rev2/sc/under:neolike
$ make helix/rev2/sc/oled:neolike
$ make helix/rev2/sc/oledback:neolike
$ make helix/rev2/sc/oledunder:neolike
```

flash to keyboard
```
$ make helix:neolike:flash
$ make helix/rev2/back:neolike:flash               # with backlight
$ make HELIX=no_ani helix/rev2/back:neolike:flash  # with backlight without animation
$ make helix/rev2/under:neolike:flash              # with underglow
$ make helix/rev2/oled:neolike:flash               # with oled
$ make helix/rev2/oled/back:neolike:flash          # with oled and backlight
$ make helix/rev2/oled/under:neolike:flash         # with oled and underglow

```

## Link
* more detail wrote in Japanese [helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)
* [Helix top](https://github.com/MakotoKurauchi/helix)

