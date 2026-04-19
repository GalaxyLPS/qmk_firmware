#pragma once

#ifdef RGBLIGHT_ENABLE

// RGBLIGHT Effekte
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif

#define TAPPING_TERM 200    // Zeit in ms, ab wann Halten als Mod erkannt wird
#define PERMISSIVE_HOLD      // Erleichtert das Auslösen von Mods bei schnellen Tastenkombinationen
#define QUICK_TAP_TERM 0     // Verhindert versehentliche Wiederholungen von Mods