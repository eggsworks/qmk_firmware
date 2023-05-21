# egg58:dance2die

This is a custom keymap for @dance2die for egg58

🛈**NOTE**: The document was created and tested on Windows 11 version 22621.1702


## How it was created

_Personal cheatsheat_

### Download source code

- Clone the repository

```bash
git clone https://github.com/dance2die/qmk_firmware_egg58
cd qmk_firmware_egg58
```

- Check out the egg58 branch

```bash
# This can take about a minute initially
git checkout egg58
```


### Configure environment defaults

- https://docs.qmk.fm/#/newbs_building_firmware?id=configure-your-build-environment-defaults-optional

```bash
alias q=qmk
alias c=clear
q config user.keyboard=egg58
q config user.keymap=dance2die
```

### Set up QMK

```bash
# this takes a few minutes
q setup
```

### Create a new keymap

- https://docs.qmk.fm/#/newbs_building_firmware?id=create-a-new-keymap
- This will use the profile in the previous step to create a keyboard for dance2die

```bash
q new-keymap
# To be explicit,
q new-keymap -kb egg58 -keymap dance2die
```

## Flashing the Egg58 firmware

- Open QMK MSYS
- Build the source (Do this once)

```bash
q compile
# wit explicit arguments
q compile -kb egg58 -km dance2die
```

The output will looks like below

```bash
[dance@LAPTOP-4L4BKQ0U qmk_firmware_egg58]$ q compile
Ψ Compiling keymap with make --jobs=1 egg58:dance2die


QMK Firmware egg58-2023-04-13
☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
Making egg58 with keymap dance2die

☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
avr-gcc.exe (GCC) 8.5.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text    data     bss     dec     hex filename
      0   19612       0   19612    4c9c egg58_dance2die.hex

Compiling: keyboards/egg58/keymaps/dance2die/keymap.c                                               [OK]
Linking: .build/egg58_dance2die.elf                                                                 [OK]
Creating load file for flashing: .build/egg58_dance2die.hex                                         [OK]
Copying egg58_dance2die.hex to qmk_firmware folder                                                  [OK]
Checking file size of egg58_dance2die.hex                                                           [OK]
 * The firmware size is fine - 19612/28672 (68%, 9060 bytes free)
```

-  Run the flash command

```bash
q flash
# with explicit arguments
q flash -kb egg58 -km dance2die
```

```bash
[dance@LAPTOP-4L4BKQ0U qmk_firmware_egg58]$ q flash
Ψ Compiling keymap with make --jobs=1 egg58:dance2die:flash


QMK Firmware egg58-2023-04-13
☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
Making egg58 with keymap dance2die and target flash

☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
avr-gcc.exe (GCC) 8.5.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text    data     bss     dec     hex filename
      0   19612       0   19612    4c9c egg58_dance2die.hex

Copying egg58_dance2die.hex to qmk_firmware folder                                                  [OK]
Checking file size of egg58_dance2die.hex                                                           [OK]
 * The firmware size is fine - 19612/28672 (68%, 9060 bytes free)
Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)............
```

At this point, the command will look for Egg58 in bootloader mode

### Bootloader mode

- You can turn on the bootloader mode by resetting the keyboard
  - Quickly touch "RESET" + "GRND" twice

The final output looks like this

```bash
[dance@LAPTOP-4L4BKQ0U qmk_firmware_egg58]$ q flash
Ψ Compiling keymap with make --jobs=1 egg58:dance2die:flash


QMK Firmware egg58-2023-04-13
☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
Making egg58 with keymap dance2die and target flash

☒ egg58: NO_ACTION_MACRO in config.h is no longer a valid option
☒ egg58: NO_ACTION_FUNCTION in config.h is no longer a valid option
avr-gcc.exe (GCC) 8.5.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Size before:
   text    data     bss     dec     hex filename
      0   19612       0   19612    4c9c egg58_dance2die.hex

Copying egg58_dance2die.hex to qmk_firmware folder                                                  [OK]
Checking file size of egg58_dance2die.hex                                                           [OK]
 * The firmware size is fine - 19612/28672 (68%, 9060 bytes free)
Waiting for USB serial port - reset your controller now (Ctrl+C to cancel)............................................................................
Device /dev/ttyS4 has appeared; assuming it is the controller.
Remapped USB port to COM5

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude.exe: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude.exe: Device signature = 0x1e9587 (probably m32u4)
avrdude.exe: NOTE: "flash" memory has been specified, an erase cycle will be performed
             To disable this feature, specify the -D option.
avrdude.exe: erasing chip
avrdude.exe: reading input file ".build/egg58_dance2die.hex"
avrdude.exe: input file .build/egg58_dance2die.hex auto detected as Intel Hex
avrdude.exe: writing flash (19612 bytes):

Writing | ################################################## | 100% 2.20s

avrdude.exe: 19612 bytes of flash written
avrdude.exe: verifying flash memory against .build/egg58_dance2die.hex:
avrdude.exe: input file .build/egg58_dance2die.hex auto detected as Intel Hex

Reading | ################################################## | 100% 0.70s

avrdude.exe: 19612 bytes of flash verified

avrdude.exe done.  Thank you.

[dance@LAPTOP-4L4BKQ0U qmk_firmware_egg58]$
```

## Testing with QMK Toolbox

- Open QMK Toolkit
- Go to menu item, "Tools -> Key Tester" to test


