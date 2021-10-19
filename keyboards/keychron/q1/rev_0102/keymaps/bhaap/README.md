# Bhaap's Keychron Q1 keymap

- Encoder functionality added with CTRL and SHIFT working as modifiers to change its behaviour 
- RCTRL and RSHFT is not present and are replaces by two Macro keys
- Old Caps Lock key is now Backspace
- Double SHift tap activates CAPS_LOCK
- On macOS, F3 opens Mission Control and F4 opens Launchpad without needing to configure shortcuts in System Preferences
- RGB lighting turns off when the computer sleeps
- Caps Lock and alpha keys turn red to indicate when Caps Lock is on
- When the Fn layer is active, RGB lighting turns off for keys that are not assigned

## Changelog

### 18/10/2021 - 1.0.0

- Encoder support with modifier keys added
- Replaced RCTRL and RSHFT with Macrokeys
- Removed normal Caps lock and replaced it with double tap shift
- Old Caps lock is now Backspace
- Added some reactive RGB lightning

### 18/10/2021 - 1.0.0

- Feature: When the Fn layer is active, RGB lighting turns off for keys that are not assigned
- Added Caps Lock indicator (my implementation is different, but this was inspired by mkillewald)
- Mission Control and Launchpad custom keycodes are now defined using the VIA user keycodes range so they can be labeled properly in VIA
- Initial release
