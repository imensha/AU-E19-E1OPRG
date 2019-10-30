#pragma once

// Connect to the RPi and return error code if connection failed
int Open();

// Turn an LED on/off
void ledOn(int id);
void ledOn(int id, int intensity);
void ledOff(int id);

// Monitor button presses
int keyPressed(int id);

// Get switch status
int switchOn();
void flipSwitch();

// Get sensor measurements
double getTemperature();
int getIntensity();

// Delay program
void Wait(int ms);
