#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main()
{
  time_t current_time;
  struct tm * time_info;
  char timeString[9];  // space for "HH:MM:SS"

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  puts(timeString);

}
