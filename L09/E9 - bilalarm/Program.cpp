#pragma comment(lib, "RaspberryPI.lib")
#include <RaspberryDLL.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define MOTION_THRESHOLD 25

enum AlarmState
{
  NONE,
  DEACTIVATED,
  ACTIVATED,
  DETECTED
};

typedef struct
{
  bool remoteActive;
  bool doorSensorActive;
  bool motionSensorActive;
  bool exitActive;
} Inputs;

AlarmState deactivated(Inputs *);
AlarmState activated(Inputs *);
AlarmState detected(Inputs *);

int main()
{
  if (!Open())
  {
    printf("Error with connection\n");
    exit(1);
  }

  printf("Connected to Raspberry Pi\n");

  AlarmState state = DEACTIVATED;
  Inputs input = {};

  while (input.exitActive != true)
  {
    AlarmState nextState;
    // Read inputs from user
    char userInput = NULL;
    if (_kbhit())
      userInput = _getch();

    // Set inputs based on user input
    // REMOTE:        use button on RPi
    // DOOR SENSOR:   use the tactile switch on RPi
    // MOTION SENSOR: use the light sensor on RPi
    if (keyPressed(P1))
    {
      printf_s("Remote pressed\n");
      input.remoteActive = true;
    }

    if (switchOn() != input.doorSensorActive)
    {
      printf_s("Door sensor triggered, door is: %s\n", switchOn() ? "OPEN" : "CLOSED", 6);
      input.doorSensorActive = switchOn();
    }

    if (getIntensity() < MOTION_THRESHOLD)
    {
      printf_s("Motion sensor trigged: %d%%\n", getIntensity());
      input.motionSensorActive = true;
    }
    else
    {
      input.motionSensorActive = false;
    }

    if (keyPressed(P2))
    {
      printf_s("Exit button pressed\n");
      input.exitActive = true;
    }

    // Debug
    /*     switch (userInput)
    {
    case 'r':
      input.remoteActive = true;
      std::cout << "Remote pressed!" << std::endl;
      break;
    case 'd':
      input.doorSensorActive = !input.doorSensorActive;
      std::cout << "Door sensor set to: " << (input.doorSensorActive ? "ACTIVATED" : "DEACTIVATED") << std::endl;
      break;
    case 'm':
      input.motionSensorActive = !input.motionSensorActive;
      std::cout << "Motion sensor set to: " << (input.motionSensorActive ? "ACTIVATED" : "DEACTIVATED") << std::endl;
      break;
    case 's':
      std::cout << "Current state: " << state << std::endl;
      break;
    case 'x':
    case 'q':
      input.exitActive = true;
      break;
    } */

    // State machine that runs code based on the current state
    switch (state)
    {
    case DEACTIVATED:
      nextState = deactivated(&input);
      break;
    case ACTIVATED:
      nextState = activated(&input);
      break;
    case DETECTED:
      nextState = detected(&input);
      break;
    }

    // Update the active state
    if (nextState)
    {
      state = nextState;
      Wait(250);
    }
  }
}

AlarmState deactivated(Inputs *input)
{
  if (input->remoteActive)
  {
    // EXIT: Remote
    input->remoteActive = false;
    return ACTIVATED;
  }

  return NONE;
}

AlarmState activated(Inputs *input)
{
  if (input->remoteActive)
  {
    // EXIT: Remote
    input->remoteActive = false;
    return DEACTIVATED;
  }

  // EXIT: Sensors
  if (input->doorSensorActive || input->motionSensorActive)
    return DETECTED;

  // LOOP
  ledOn(6);
  Wait(100);
  ledOff(6);
  Wait(1000);

  return NONE;
}

AlarmState detected(Inputs *input)
{
  if (input->remoteActive)
  {
    // EXIT: Remote
    input->remoteActive = false;
    ledOff(6);
    return DEACTIVATED;
  }

  // ENTER
  ledOn(6);

  // LOOP
  ledOn(1);
  ledOn(3);
  ledOn(5);
  Wait(200);
  ledOff(1);
  ledOff(3);
  ledOff(5);

  ledOn(2);
  ledOn(4);
  Wait(200);
  ledOff(2);
  ledOff(4);

  return NONE;
}
