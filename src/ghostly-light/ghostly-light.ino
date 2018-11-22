/*******************************************************************************
 *  G P I O   C O N S T A N T S
 ******************************************************************************/
#define DAT 3                           // DAT on GPIO 3 (physical pin 2), output to WS2812B LED.
#define AN A2                           // AN on GPIO 4 (physical pin 3), used for random seed.


/*******************************************************************************
 *  C H A R A C T E R   S E L E C T I O N   C O N S T A N T S
 ******************************************************************************/
#define MIN_TIME 400                    // Time the first character is selected.
#define STEP_TIME 100                   // Time to be added to each character in the turn, added to the previous one.
#define MIN_TURNS 8                     // Minimum number of character turns before one can be selected.
#define MAX_TURNS 16                    // Maximum number of character turns, character selected randomly between `MIN_TURNS` and `MAX_TURNS`.
#define CONFIRMATION_FLASHES 4          // Number of flashes the character makes when selected.
#define FLASH_TIME 200                  // Confirmation flash duration, high and low time in milliseconds.


/*******************************************************************************
 *  A N I M A T I O N   C O N S T A N T S
 ******************************************************************************/
// List of animations
#define SOLID 0                         // Index of `SOLID` animation.
#define FADE 1                          // Index of `FADE` animation.
#define FEAR 2                          // Index of `FEAR` animation.
#define FAST_FADE 3                     // Index of `FAST_FADE` animation.
#define EASTER_EGG 4                    // Index of `EASTER_EGG` animation. Other animations must always go before this animation.
#define ANIMATIONS (EASTER_EGG + 1)     // Total number of animations. It must be the value of `EASTER_EGG` + 1.
// Ratio of animations
#define SOLID_RATIO 85                  // Percentage ratio that the `SOLID` animation will be displayed.
#define FADE_RATIO (SOLID_RATIO + 10)   // Percentage ratio that the `FADE` animation will be displayed. Value of the previous ratio plus this ratio.
#define FEAR_RATIO (FADE_RATIO + 2)     // Percentage ratio that the `FEAR` animation will be displayed. Value of the previous ratio plus this ratio.
#define FAST_FADE_RATIO 100             // Percentage ratio that the `FAST_FADE` animation will be displayed. Value of the previous ratio plus this ratio. The last animation has a ratio of 100.
#define EASTER_EGG_PERIOD 1800000UL     // The Easter egg can be run every `EASTER_EGG_PERIOD` in milliseconds, with the ratio of the previous animation.
// Animation Variables
#define SOLID_TIME 5000                 // Time in milliseconds that the `SOLID` animation is held.
#define FADE_TIMES 3                    // Number of times the 'FADE' animation is played.
#define FADE_SPEED 25                   // Time in milliseconds of each step of the 'FADE' animation. Total animation time: (`FADE_SPEED` * 25 * 2 * `FADE_TIMES`) milliseconds.
#define FEAR_TIME 3750                  // Time in milliseconds of the first part of the animation. Total animation time: (`FEAR_TIME` + (`FEAR_FLASH` * 2 * `FEAR_FLASHES`)) milliseconds.
#define FEAR_FLASHES 5                  // Number of times the character flashes before returning to normal.
#define FEAR_FLASH 200                  // Duration of animation flashing, high and low time in milliseconds.
#define FAST_FADE_TIMES 3               // Number of times the 'FAST_FADE' animation is played.
#define FAST_FADE_SPEED 10              // Time in milliseconds of each step of the 'FAST_FADE' animation. Total animation time: (`FAST_FADE_SPEED` * 25 * 2 * `FAST_FADE_TIMES`) milliseconds.
#define EASTER_EGG_STEPS 15             // Number of steps of each transition of the `EASTER_EGG` animation.
#define EASTER_EGG_STOP 50              // Pause time between transitions of the `EASTER_EGG` animation.
#define EASTER_EGG_SPEED 10             // Time in milliseconds of each step of the 'EASTER_EGG' animation. Total animation time: ((`EASTER_EGG_SPEED` * EASTER_EGG_STEPS * 13) + (`EASTER_EGG_STOP` * 10)) milliseconds.


/*******************************************************************************
 *  C H A R A C T E R   C O N S T A N T S
 ******************************************************************************/
// Indexes of `characters[][3]`
#define BLINKY 0                        // Index for `BLINKY` character.
#define CLYDE 1                         // Index for `CLYDE` character.
#define PINKY 2                         // Index for `PINKY` character.
#define INKY 3                          // Index for `INKY` character.
#define CHARACTERS (INKY + 1)           // Total number of characters. It must be the value of `INKY` + 1.
#define FEAR_BLUE 4                     // Index for the first part of the animation `FEAR`.
#define FEAR_WHITE 5                    // Index for the second part of the animation `FEAR`.
#define NONE 6                          // Index for no selected character (`NONE`).
// Colors
#define BLINKY_COLOR {127, 0, 0}        // RGB color array for the character `BLINKY`.
#define CLYDE_COLOR {127, 48, 0}        // RGB color array for the character `CLYDE`.
#define PINKY_COLOR {96, 24, 56}        // RGB color array for the character `PINKY`.
#define INKY_COLOR {0, 96, 56}          // RGB color array for the character `INKY`.
#define FEAR_BLUE_COLOR {0, 0, 127}     // RGB color array for the first part of the animation `FEAR`.
#define FEAR_WHITE_COLOR {72, 72, 72}   // RGB color array for the second part of the animation  `FEAR`.
#define NONE_COLOR {0, 0, 0}            // RGB color array for no character selected (`NONE`).


/*******************************************************************************
 *  E A S T E R   E G G   C O N S T A N T S
 *  - G S R D I   F L A G   C O L O R S -
 ******************************************************************************/
#define FLAGS 5                         // Total number of flags. Maximum index of `flags[FLAGS][10][3]`.
// Colors
#define BLACK_COLOR {4, 4, 4}           // RGB color array for `BLACK_COLOR`.
#define GREY_COLOR {32, 32, 32}         // RGB color array for `GREY_COLOR`.
#define WHITE_COLOR {96, 96, 96}        // RGB color array for `WHITE_COLOR`.
#define BROWN_COLOR {64, 35, 7}         // RGB color array for `BROWN_COLOR`.
#define RED_COLOR {96, 0, 0}            // RGB color array for `RED_COLOR`.
#define PINK_COLOR {127, 40, 70}        // RGB color array for `PINK_COLOR`.
#define ORANGE_COLOR {127, 44, 0}       // RGB color array for `ORANGE_COLOR`.
#define YELLOW_COLOR {127, 96, 0}       // RGB color array for `YELLOW_COLOR`.
#define GREEN_COLOR {0, 96, 0}          // RGB color array for `GREEN_COLOR`.
#define CYAN_COLOR {0, 112, 112}        // RGB color array for `CYAN_COLOR`.
#define BLUE_COLOR {0, 12, 127}         // RGB color array for `BLUE_COLOR`.
#define PURPLE_COLOR {74, 0, 96}        // RGB color array for `PURPLE_COLOR`.
// Definition of flags, 10 colors per flag.
#define RAINBOW_FLAG { BLACK_COLOR, BROWN_COLOR, PINK_COLOR, RED_COLOR, ORANGE_COLOR, YELLOW_COLOR, GREEN_COLOR, CYAN_COLOR, BLUE_COLOR, PURPLE_COLOR }
#define TRANS_FLAG { CYAN_COLOR, CYAN_COLOR, PINK_COLOR, PINK_COLOR, WHITE_COLOR, WHITE_COLOR, PINK_COLOR, PINK_COLOR, CYAN_COLOR, CYAN_COLOR }
#define PAN_FLAG { PINK_COLOR, PINK_COLOR, PINK_COLOR, YELLOW_COLOR, YELLOW_COLOR, YELLOW_COLOR, YELLOW_COLOR, CYAN_COLOR, CYAN_COLOR, CYAN_COLOR }
#define ACE_FLAG { BLACK_COLOR, BLACK_COLOR, GREY_COLOR, GREY_COLOR, GREY_COLOR, WHITE_COLOR, WHITE_COLOR, WHITE_COLOR, PURPLE_COLOR, PURPLE_COLOR }
#define NB_FLAG { YELLOW_COLOR, YELLOW_COLOR, WHITE_COLOR, WHITE_COLOR, WHITE_COLOR, PURPLE_COLOR, PURPLE_COLOR, PURPLE_COLOR, BLACK_COLOR, BLACK_COLOR }


/*******************************************************************************
 *  L I B R A R I E S
 ******************************************************************************/
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel ws2812 = Adafruit_NeoPixel(1, DAT, NEO_GRB + NEO_KHZ800);


/*******************************************************************************
 *  G L O B A L   A R R A Y S
 ******************************************************************************/
const unsigned char characters[][3] = { BLINKY_COLOR, CLYDE_COLOR, PINKY_COLOR, INKY_COLOR, FEAR_BLUE_COLOR, FEAR_WHITE_COLOR, NONE_COLOR };
const unsigned char flags[FLAGS][10][3] = { RAINBOW_FLAG, TRANS_FLAG, PAN_FLAG, ACE_FLAG, NB_FLAG };


void setup() {
    ws2812.begin();
    ws2812.setPixelColor(0, ws2812.Color(characters[NONE][0], characters[NONE][1], characters[NONE][2]));
    ws2812.show();
    randomSeed(analogRead(AN));
}

void loop() {
    static boolean char_selection_done = false;     // Selected character status, to make the selection at the beginning.
    unsigned char char_random = 0;                  // Number of character turns to select a character.
    static unsigned char selected_char = 0;         // Selected character.
    unsigned int char_selection_time = 0;           // Pause time between character turns.
    unsigned char animation_random = 0;             // Random number for the selection of animation according to its probability.
    unsigned char animation = 0;                    // Selected animation.
    static unsigned long t_easter_egg = 0;          // Time counter for the animation `EASTER_EGG`.

    // Only in the first run
    if (!char_selection_done) {
        // Character selection
        char_random = random(MIN_TURNS, MAX_TURNS);
        for(unsigned char i = 0; i < char_random; i++) {
            selected_char = i % CHARACTERS;
            char_selection_time = MIN_TIME + ((i + 1) * STEP_TIME);
            ws2812.setPixelColor(0, ws2812.Color(characters[selected_char][0], characters[selected_char][1], characters[selected_char][2]));
            ws2812.show();
            delay(char_selection_time);
        }
        // Character confirmation
        delay(char_selection_time);
        for(unsigned char i = 0; i < CONFIRMATION_FLASHES; i++) {
            ws2812.setPixelColor(0, ws2812.Color(0, 0, 0));
            ws2812.show();
            delay(FLASH_TIME);
            ws2812.setPixelColor(0, ws2812.Color(characters[selected_char][0], characters[selected_char][1], characters[selected_char][2]));
            ws2812.show();
            delay(FLASH_TIME);
        }
        char_selection_done = true;
    }
    // Animations run continuously, first select an animation
    animation_random = random(1, 100);
    if (animation_random <= SOLID_RATIO) animation = SOLID;
    else if (animation_random <= FADE_RATIO) animation = FADE;
    else if (animation_random <= FEAR_RATIO) animation = FEAR;
    else if (animation_random <= FAST_FADE_RATIO) animation = FAST_FADE;
    if (millis() - t_easter_egg >= EASTER_EGG_PERIOD) {
        t_easter_egg = millis();
        animation++; // The `EASTER_EGG` animation can be displayed every time the set time is reached, if the selected animation is the penultimate one.
    }
    // And then run it
    switch (animation) {
      case SOLID:
        solid(selected_char);
        break;
      case FADE:
        // Fade in and out.
        for(unsigned char i = 0; i < FADE_TIMES; i++) {
            fade_color(characters[selected_char][0], characters[selected_char][1], characters[selected_char][2], 0, 0, 0, 25, FADE_SPEED);
            fade_color(0, 0, 0, characters[selected_char][0], characters[selected_char][1], characters[selected_char][2], 25, FADE_SPEED);
        }
        break;
      case FEAR:
        fear(selected_char);
        solid(selected_char); // `FEAR` animation does not happen twice in a row.
        break;
      case FAST_FADE:
        // Fade in and out.
        for(unsigned char i = 0; i < FAST_FADE_TIMES; i++) {
            fade_color(characters[selected_char][0], characters[selected_char][1], characters[selected_char][2], (characters[selected_char][0] / 2), (characters[selected_char][1] / 2), (characters[selected_char][2] / 2), 25, FAST_FADE_SPEED);
            fade_color((characters[selected_char][0] / 2), (characters[selected_char][1] / 2), (characters[selected_char][2] / 2), characters[selected_char][0], characters[selected_char][1], characters[selected_char][2], 25, FAST_FADE_SPEED);
        }
        break;
      // Insert new animations here
      case EASTER_EGG:
        easter_egg(selected_char);
        break;
    }
}

// Holds a solid color.
// Required arguments:
//      Index of the selected character.
void solid(unsigned char character) {
    ws2812.setPixelColor(0, ws2812.Color(characters[character][0], characters[character][1], characters[character][2]));
    ws2812.show();
    delay(SOLID_TIME);
}

// Makes a smooth transition between two colors.
// Required arguments: 
//      R-value of the origin color;
//      G-value of the origin color;
//      B-value of the origin color;
//      R-value of the destination color;
//      G-value of the destination color;
//      B-value of the destination color;
//      Number of transition steps;
//      Time of each transition step.
void fade_color(unsigned char origin_r, unsigned char origin_g, unsigned char origin_b, unsigned char dest_r, unsigned char dest_g, unsigned char dest_b, unsigned char steps, unsigned char t) {
    int step_r = 0;
    int step_g = 0;
    int step_b = 0;

    for (unsigned char i = 0; i < steps; i++) {
        step_r = ((dest_r - origin_r) * i) / steps;
        step_g = ((dest_g - origin_g) * i) / steps;
        step_b = ((dest_b - origin_b) * i) / steps;
        ws2812.setPixelColor(0, ws2812.Color(origin_r + step_r, origin_g + step_g, origin_b + step_b));
        ws2812.show();
        delay(t);
    }
    ws2812.setPixelColor(0, ws2812.Color(dest_r, dest_g, dest_b));
    ws2812.show();
}

// Play pacman's original fear animation.
// Required arguments:
//      Index of the selected character.
void fear(unsigned char character) {
    ws2812.setPixelColor(0, ws2812.Color(characters[FEAR_BLUE][0], characters[FEAR_BLUE][1], characters[FEAR_BLUE][2]));
    ws2812.show();
    delay(FEAR_TIME);
    for (unsigned char i = 0; i < FEAR_FLASHES; i++) {
        ws2812.setPixelColor(0, ws2812.Color(characters[FEAR_BLUE][0], characters[FEAR_BLUE][1], characters[FEAR_BLUE][2]));
        ws2812.show();
        delay(FEAR_FLASH);
        ws2812.setPixelColor(0, ws2812.Color(characters[FEAR_WHITE][0], characters[FEAR_WHITE][1], characters[FEAR_WHITE][2]));
        ws2812.show();
        delay(FEAR_FLASH);
    }
    ws2812.setPixelColor(0, ws2812.Color(characters[character][0], characters[character][1], characters[character][2]));
    ws2812.show();
}

// Reproduces the colors of a random flag.
// Required arguments:
//      Index of the selected character.
void easter_egg(unsigned char character) {
    unsigned char flag = 0;
    
    flag = random(0, FLAGS); // The flag is selected randomly each time.
    // Transition from selected character to no character.
    fade_color(characters[character][0], characters[character][1], characters[character][2], characters[NONE][0], characters[NONE][1], characters[NONE][2], EASTER_EGG_STEPS, EASTER_EGG_SPEED);
    // Then to first color of the flag.
    fade_color(characters[NONE][0], characters[NONE][1], characters[NONE][2], flags[flag][0][0], flags[flag][0][1], flags[flag][0][2], EASTER_EGG_STEPS, EASTER_EGG_SPEED);
    delay(EASTER_EGG_STOP);
    // Scroll through each color of the flag.
    for (unsigned char i = 1; i < 10; i++){
        fade_color(flags[flag][i-1][0], flags[flag][i-1][1], flags[flag][i-1][2], flags[flag][i][0], flags[flag][i][1], flags[flag][i][2], EASTER_EGG_STEPS, EASTER_EGG_SPEED);
        delay(EASTER_EGG_STOP);
    }
    // Transition from the last color of the flag to no character.
    fade_color(flags[flag][9][0], flags[flag][9][1], flags[flag][9][2], characters[NONE][0], characters[NONE][1], characters[NONE][2], EASTER_EGG_STEPS, EASTER_EGG_SPEED);
    // Then to selected character.
    fade_color(characters[NONE][0], characters[NONE][1], characters[NONE][2], characters[character][0], characters[character][1], characters[character][2], EASTER_EGG_STEPS, EASTER_EGG_SPEED);
}

