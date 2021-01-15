#pragma once

#define CONFIGURATION_H_VERSION 020007
#define STRING_CONFIG_H_AUTHOR "Piotr Kostański"
#define CUSTOM_MACHINE_NAME "Ender-5 PiKor"

#define SHOW_BOOTSCREEN

#define SERIAL_PORT 2
#define SERIAL_PORT_2 -1
#define BAUDRATE 115200

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V1_2
#endif

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75
#define EXTRUDERS 1
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1

#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME     10  // (seconds) Time to wait for hotend to "settle" in M109
#define TEMP_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target

#define TEMP_BED_RESIDENCY_TIME 10  // (seconds) Time to wait for bed to "settle" in M190
#define TEMP_BED_WINDOW          1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_BED_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target

#define HEATER_0_MINTEMP   5
#define HEATER_0_MAXTEMP 250

#define BED_MINTEMP        5
#define BED_MAXTEMP      125

#define PIDTEMP
#define BANG_MAX 255
#define PID_MAX BANG_MAX
#define PID_K1 0.95
#define DEFAULT_Kp 19.60
#define DEFAULT_Ki 1.25
#define DEFAULT_Kd 76.99

#define PIDTEMPBED
#define MAX_BED_POWER 255
#define DEFAULT_bedKp 85.23
#define DEFAULT_bedKi 16.36
#define DEFAULT_bedKd 296.08

#define PID_FUNCTIONAL_RANGE 10

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 600

#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG

#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Disable ENDSTOPPULLUPS to set pullups individually
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Disable ENDSTOPPULLDOWNS to set pulldowns individually
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.

#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209

#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 102 }

/**
 * Default Max Feed Rate (mm/s)
 * Override with M203
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 100, 100, 5, 120 }

//#define LIMITED_MAX_FR_EDITING        // Limit edit via M203 or LCD to DEFAULT_MAX_FEEDRATE * 2
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...or, set your own edit limits
#endif

/**
 * Default Max Acceleration (change/s) change = mm/s
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 500, 500, 100, 5000 }

//#define LIMITED_MAX_ACCEL_EDITING     // Limit edit via M201 or LCD to DEFAULT_MAX_ACCELERATION * 2
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits
#endif

/**
 * Default Acceleration (change/s) change = mm/s
 * Override with M204
 *
 *   M204 P    Acceleration
 *   M204 R    Retract Acceleration
 *   M204 T    Travel Acceleration
 */
#define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   500    // X, Y, Z acceleration for travel (non printing) moves

#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3

  #define TRAVEL_EXTRA_XYJERK 5.0     // Additional jerk allowance for all travel moves

  //#define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

#define DEFAULT_EJERK    15.0  // May be used by Linear Advance

// #if DISABLED(CLASSIC_JERK)
//   #define JUNCTION_DEVIATION_MM 0.08  // (mm) Distance from real junction edge
//   #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
//                                       // for small segments (< 1mm) with large junction angles (> 135°).
// #endif

#define S_CURVE_ACCELERATION

#define BLTOUCH
#define USE_PROBE_FOR_Z_HOMING
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
#define NOZZLE_TO_PROBE_OFFSET { 41, 8, -0.5 }
#define PROBING_MARGIN 40
#define XY_PROBE_SPEED (HOMING_FEEDRATE_XY)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

#define Z_CLEARANCE_DEPLOY_PROBE 4 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES 2 // Z Clearance between probe points
#define Z_CLEARANCE_MULTI_PROBE 2 // Z Clearance between multiple probes

#define Z_PROBE_LOW_POINT -2

#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false

#define DISABLE_INACTIVE_EXTRUDER

#define INVERT_X_DIR false
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true
#define INVERT_E0_DIR true

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define X_BED_SIZE 225
#define Y_BED_SIZE 225

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 300

#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#define AUTO_BED_LEVELING_LINEAR
#define GRID_MAX_POINTS_X 5
#define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

#define Z_PROBE_END_SCRIPT "G28 X Y"

#define Z_SAFE_HOMING
#define Z_SAFE_HOMING_X_POINT X_CENTER
#define Z_SAFE_HOMING_Y_POINT Y_CENTER

#define HOMING_FEEDRATE_XY (20*60)
#define HOMING_FEEDRATE_Z  (4*60)

#define VALIDATE_HOMING_ENDSTOPS

#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_BOOT_SILENT
#define EEPROM_AUTO_INIT

#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 185
#define PREHEAT_1_TEMP_BED     45
#define PREHEAT_1_FAN_SPEED   255 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED   255 // Value from 0 to 255

#define NOZZLE_PARK_FEATURE
#define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
#define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
#define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
#define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)

#define PRINTJOB_TIMER_AUTOSTART

#define LCD_LANGUAGE en

#define SDSUPPORT

#define CR10_STOCKDISPLAY

#define SOFT_PWM_SCALE 0