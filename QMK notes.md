# QMK notes

## Dactyl-manuform

### Make

``` make handwired/dactyl_manuform/4x6:proxy-hatch```

### Flash

##### Dactyl-manuform

QMK Toolbox doesn't like Arduino Pro Micro

```bash
avrdude.exe -p atmega32u4 -c avr109 -U flash:w:"D:\Shawn\Documents\Arduino\keeb\qmk_firmware\handwired_dactyl_manuform_4x6_proxy-hatch.hex":i -P 
    C:\Users\Shawn\AppData\Local\QMK\QMK Toolbox\0.0.14\avrdude.exe: option requires an argument -- P
    Usage: avrdude.exe [options]
    Options:
    ...
```

Instead use terminal 

```bash
avrdude.exe -p atmega32u4 -c avr109 -U flash:w:"D:\Shawn\Documents\Arduino\keeb\qmk_firmware\handwired_dactyl_manuform_4x6_proxy-hatch.hex":i -P COM7
```





## GH60

### Setup and Commands

Use Msys MINGW64

~~~bash
qmk compile -kb gh60/satan -km default
# unhelpful console log
make gh60/satan:default

$ qmk config user.keyboard=gh60/satan
user.keyboard: None -> gh60/satan
INFO Wrote configuration to D:/msys64/mingw64/bin/qmk.exe.ini
qmk config user.keymap=proxy-hatch

$ qmk config user.keymap=proxy-hatch
user.keymap: None -> proxy-hatch
INFO Wrote configuration to D:/msys64/mingw64/bin/qmk.exe.ini

qmk new-keymap
qmk compile -kb gh60/satan -km proxy-hatch
~~~

### Dev

1. tweak keymap

2. Build

   ```
   qmk compile
   ```
   
3.  [Flash0(https://docs.qmk.fm/#/newbs_flashing)

   "failed: this case, you’ll have to fall back on specifying the bootloader. See the [Flashing Firmware](https://docs.qmk.fm/#/flashing) Guide for more details."

   ```
   qmk flash
   ```

4. Profit

### Paste Bin

```
qmk compile -kb <keyboard> -km default
gh60/satan
qmk compile && qmk flash
```

----

log - jun1

last iter problem: 

~~can't do tilda~~ fixed

- ~~turn off ovrride shift for graves~~

Impl:

- Keyboard Config layer (MAGIC_TOGGLE_CTL_GUI @ lctrl)

TODO https://docs.qmk.fm/#/feature_dynamic_macros

----



## GH60 Resources

- [Hasu Keymap](https://github.com/tmk/tmk_keyboard/blob/master/keyboard/gh60/keymap_hasu.c)

# Common Resource

- Navigate to your proj dir:

  ~~~
  cd /d/Shawn/Documents/Arduino/keeb/src/qmk_firmware
  ~~~

- [Pulling new code](https://docs.qmk.fm/#/newbs_git_using_your_master_branch)

  ```
  git checkout master
  git pull upstream master
  git push origin master
  ```
  
- Handy Docs for making new keymap

  - [Key Codes](https://docs.qmk.fm/#/keycodes)
  - [Layer Modifiers](https://beta.docs.qmk.fm/using-qmk/software-features/feature_layers)

- [Boot Magic Hotkeys](https://docs.qmk.fm/#/feature_bootmagic?id=hotkeys)

  Hold down the Bootmagic key (Space by default) and the desired hotkey while plugging in your keyboard. For example, holding Space+`B` should cause it to enter the bootloader.

  | Hotkey       | Description                                |
  | ------------ | ------------------------------------------ |
  | Escape       | Ignore Bootmagic configuration in EEPROM   |
  | `B`          | Enter the bootloader                       |
  | `D`          | Toggle debugging over serial               |
  | `X`          | Toggle key matrix debugging                |
  | `K`          | Toggle keyboard debugging                  |
  | `M`          | Toggle mouse debugging                     |
  | `L`          | Set “Left Hand” for EE_HANDS handedness    |
  | `R`          | Set “Right Hand” for EE_HANDS handedness   |
  | Backspace    | Clear the EEPROM                           |
  | Caps Lock    | Toggle treating Caps Lock as Left Control  |
  | Left Control | Toggle swapping Caps Lock and Left Control |
  | Left Alt     | Toggle swapping Left Alt and Left GUI      |
  | Right Alt    | Toggle swapping Right Alt and Right GUI    |
  | Left GUI     | Toggle the GUI keys (useful when gaming)   |
  | ```          | Toggle swapping ``` and Escape             |
  | `\`          | Toggle swapping `\` and Backspace          |
  | `N`          | Toggle N-Key Rollover (NKRO)               |
  | `0`          | Make layer 0 the default layer             |
  | `1`          | Make layer 1 the default layer             |
  | `2`          | Make layer 2 the default layer             |
  | `3`          | Make layer 3 the default layer             |
  | `4`          | Make layer 4 the default layer             |
  | `5`          | Make layer 5 the default layer             |
  | `6`          | Make layer 6 the default layer             |
  | `7`          | Make layer 7 the default layer             |