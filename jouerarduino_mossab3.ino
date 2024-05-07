#<h.LiquidCrystal <include
2 BUTTON_PIN define#
1 AUTOPLAY_PIN define#
10 READWRITE_PIN define#
12 CONTRAST_PIN define#
1 RUN1_SPRITE define#
2 RUN2_SPRITE define#
3 JUMP_SPRITE define#
head the for character '.' the Use '.' // UPPER_JUMP_SPRITE define#
4 LOWER_JUMP_SPRITE define#
character ' ' the User ' ' // EMPTY_TERRAIN_SPRITE define#
18/6
5 SOLID_TERRAIN_SPRITE define#
6 RIGHT_SOLID_TERRAIN_SPRITE define#
7 LEFT_SOLID_TERRAIN_SPRITE define#
screen on hero of position Horizontal // 1 POSITION_HORIZONTAL_HERO define#
16 WIDTH_TERRAIN define#
0 EMPTY_TERRAIN define#
1 BLOCK_LOWER_TERRAIN define#
2 BLOCK_UPPER_TERRAIN define#
invisible is Hero // 0 OFF_POSITION_HERO define#
(1 pose (row lower on running is Hero // 1 1_LOWER_RUN_POSITION_HERO define#
(2 pose // (2 2_LOWER_RUN_POSITION_HERO define#
jump a Starting // 3 1_JUMP_POSITION_HERO define#
up way-Half // 4 2_JUMP_POSITION_HERO define#
row upper on is Jump // 5 3_JUMP_POSITION_HERO define#
row upper on is Jump // 6 4_JUMP_POSITION_HERO define#
row upper on is Jump // 7 5_JUMP_POSITION_HERO define#
row upper on is Jump // 8 6_JUMP_POSITION_HERO define#
down way-Half // 9 7_JUMP_POSITION_HERO define#
land to About // 10 8_JUMP_POSITION_HERO define#
(1 pose (row upper on running is Hero // 11 1_UPPER_RUN_POSITION_HERO define#
(2 pose // (12 2_UPPER_RUN_POSITION_HERO define#
;(3, 4, 5, 6, 9, 11(lcd LiquidCrystal
;[1 + WIDTH_TERRAIN[terrainUpper char static
;[1 + WIDTH_TERRAIN[terrainLower char static
;false = buttonPushed bool static
}()initializeGraphics void
} = []graphics byte static
1 position Run//
,B01100
,B01100
,B00000
,B01110
,B11100
,B01100
,B11010
,B10011
2 position Run//
,B01100
,B01100
,B00000
,B01100
,B01100
,B01100
,B01100
,B01110
Jump//
,B01100
,B01100
18/7
,B00000
,B11110
,B01101
,B11111
,B10000
,B00000
lower Jump//
,B11110
,B01101
,B11111
,B10000
,B00000
,B00000
,B00000
,B00000
Ground//
,B11111
,B11111
,B11111
,B11111
,B11111
,B11111
,B11111
,B11111
right Ground//
,B00011
,B00011
,B00011
,B00011
,B00011
,B00011
,B00011
,B00011
left Ground//
,B11000
,B11000
,B11000
,B11000
,B11000
,B11000
,B11000
,B11000
;{
;i int
to used be to() print.lcd allows this, 0 character using Skip//
characters multiple draw quickly//
} (i; ++7 < i; 0 = i (for
;([8 * i[graphics, &1 + i(createChar.lcd
{
} (i; ++WIDTH_TERRAIN < i; 0 = i (for
;EMPTY_TERRAIN_SPRITE] = i[terrainUpper
;EMPTY_TERRAIN_SPRITE] = i[terrainLower
{
18/8
{
increments character-half in left the to terrain the Slide//
//
}(newTerrain byte, terrain* char(advanceTerrain void
} (i; ++WIDTH_TERRAIN < i; 0 = i int (for
;[i[terrain = current char
;[1+i[terrain : newTerrain) ? 1-WIDTH_TERRAIN == i = (next char
}(current (switch
:EMPTY_TERRAIN_SPRITE case
: RIGHT_SOLID_TERRAIN_SPRITE) ? SOLID_TERRAIN_SPRITE == next] = (i[terrain
;EMPTY_TERRAIN_SPRITE
;break
:SOLID_TERRAIN_SPRITE case
: LEFT_SOLID_TERRAIN_SPRITE) ? EMPTY_TERRAIN_SPRITE == next] = (i[terrain
;SOLID_TERRAIN_SPRITE
;break
:RIGHT_SOLID_TERRAIN_SPRITE case
;SOLID_TERRAIN_SPRITE] = i[terrain
;break
:LEFT_SOLID_TERRAIN_SPRITE case
;EMPTY_TERRAIN_SPRITE] = i[terrain
;break
{
{
{
int unsigned, terrainLower* char, terrainUpper* char, position byte(drawHero bool
} (score
;false = collide bool
;[POSITION_HORIZONTAL_HERO[terrainUpper = upperSave char
;[POSITION_HORIZONTAL_HERO[terrainLower = lowerSave char
;lower, upper byte
} (position (switch
:OFF_POSITION_HERO case
;EMPTY_TERRAIN_SPRITE = lower = upper
;break
:1_LOWER_RUN_POSITION_HERO case
;EMPTY_TERRAIN_SPRITE = upper
;RUN1_SPRITE = lower
;break
:2_LOWER_RUN_POSITION_HERO case
;EMPTY_TERRAIN_SPRITE = upper
;RUN2_SPRITE = lower
;break
:1_JUMP_POSITION_HERO case
:8_JUMP_POSITION_HERO case
;EMPTY_TERRAIN_SPRITE = upper
;JUMP_SPRITE = lower
;break
:2_JUMP_POSITION_HERO case
:7_JUMP_POSITION_HERO case
;UPPER_JUMP_SPRITE = upper
;LOWER_JUMP_SPRITE = lower
18/9
;break
:3_JUMP_POSITION_HERO case
:4_JUMP_POSITION_HERO case
:5_JUMP_POSITION_HERO case
:6_JUMP_POSITION_HERO case
;JUMP_SPRITE = upper
;EMPTY_TERRAIN_SPRITE = lower
;break
:1_UPPER_RUN_POSITION_HERO case
;RUN1_SPRITE = upper
;EMPTY_TERRAIN_SPRITE = lower
;break
:2_UPPER_RUN_POSITION_HERO case
;RUN2_SPRITE = upper
;EMPTY_TERRAIN_SPRITE = lower
;break
{
} (' ' =! upper (if
;upper] = POSITION_HORIZONTAL_HERO[terrainUpper
;true : false) ? EMPTY_TERRAIN_SPRITE == upperSave = (collide
{
} (' ' =! lower (if
;lower] = POSITION_HORIZONTAL_HERO[terrainLower
;true : false) ? EMPTY_TERRAIN_SPRITE == lowerSave |= (collide
{
< score : (3) ? 99 > score : (4) ? 999 > score : (5) ? 9999 > score = (digits byte
;1 : 2) ? 9
scene the Draw//
;'0] = '\WIDTH_TERRAIN[terrainUpper
;'0] = '\WIDTH_TERRAIN[terrainLower
;[digits-16[terrainUpper = temp char
;'0] = '\digits-16[terrainUpper
;(0,0(setCursor.lcd
;(terrainUpper(print.lcd
;temp] = digits-16[terrainUpper
;(1,0(setCursor.lcd
;(terrainLower(print.lcd
;(0,digits - 16(setCursor.lcd
;(score(print.lcd
;upperSave] = POSITION_HORIZONTAL_HERO[terrainUpper
;lowerSave] = POSITION_HORIZONTAL_HERO[terrainLower
;collide return
{
interrupt an as push button the Handle//
} ()buttonPush void
;true = buttonPushed
{
}()setup void
;(OUTPUT, READWRITE_PIN(pinMode
;(LOW, READWRITE_PIN(digitalWrite
;(OUTPUT, CONTRAST_PIN(pinMode
18/10
;(LOW, CONTRAST_PIN(digitalWrite
;(INPUT, BUTTON_PIN(pinMode
;(HIGH, BUTTON_PIN(digitalWrite
;(OUTPUT, AUTOPLAY_PIN(pinMode
;(HIGH, AUTOPLAY_PIN(digitalWrite
0 interrupt to maps 2 pin Digital//
;(FALLING, buttonPush*/, BUTTON_PIN/*0(attachInterrupt
;()initializeGraphics
;(2, 16(begin.lcd
{
}()loop void
;1_LOWER_RUN_POSITION_HERO = heroPos byte static
;EMPTY_TERRAIN = newTerrainType byte static
;1 = newTerrainDuration byte static
;false = playing bool static
;false = blink bool static
;0 = distance int unsigned static
} (playing (!if
distance, terrainLower, terrainUpper, heroPos : OFF_POSITION_HERO) ? blink((drawHero
;(3>>
} (blink (if
;(0,0(setCursor.lcd
;("Start Press("print.lcd
{
;(250(delay
;blink = !blink
} (buttonPushed (if
;()initializeGraphics
;1_LOWER_RUN_POSITION_HERO = heroPos
;true = playing
;false = buttonPushed
;0 = distance
{
;return
{
left the to terrain the Shift//
? BLOCK_LOWER_TERRAIN == newTerrainType, terrainLower(advanceTerrain
;(EMPTY_TERRAIN_SPRITE : SOLID_TERRAIN_SPRITE
? BLOCK_UPPER_TERRAIN == newTerrainType, terrainUpper(advanceTerrain
;(EMPTY_TERRAIN_SPRITE : SOLID_TERRAIN_SPRITE
right the on enter to terrain new Make//
} (0 == newTerrainDuration (--if
} (EMPTY_TERRAIN == newTerrainType (if
;BLOCK_LOWER_TERRAIN : BLOCK_UPPER_TERRAIN) ? 0) == 3(random = (newTerrainType
;(10(random + 2 = newTerrainDuration
} else}
;EMPTY_TERRAIN = newTerrainType
;(10(random + 10 = newTerrainDuration
{
{
} (buttonPushed (if
;1_JUMP_POSITION_HERO = heroPos) 2_LOWER_RUN_POSITION_HERO <= heroPos (if
18/11
;false = buttonPushed
{
} ((3 >> distance, terrainLower, terrainUpper, heroPos(drawHero (if
.bad Too. something with collided hero The; // false = playing
} else}
} (8_JUMP_POSITION_HERO == heroPos || 2_LOWER_RUN_POSITION_HERO == heroPos (if
;1_LOWER_RUN_POSITION_HERO = heroPos
&& (5_JUMP_POSITION_HERO <= heroPos && 3_JUMP_POSITION_HERO >= heroPos ((if else}
} (EMPTY_TERRAIN_SPRITE] != POSITION_HORIZONTAL_HERO[terrainLower
;1_UPPER_RUN_POSITION_HERO = heroPos
&& 1_UPPER_RUN_POSITION_HERO >= heroPos (if else}
} (EMPTY_TERRAIN_SPRITE] == POSITION_HORIZONTAL_HERO[terrainLower
;5_JUMP_POSITION_HERO = heroPos
} (2_UPPER_RUN_POSITION_HERO == heroPos (if else}
;1_UPPER_RUN_POSITION_HERO = heroPos
} else}
;heroPos++
{
;distance++
== [2 + POSITION_HORIZONTAL_HERO[terrainLower, AUTOPLAY_PIN(digitalWrite
;(LOW : HIGH ? EMPTY_TERRAIN_SPRITE
{
;(100(delay
{
