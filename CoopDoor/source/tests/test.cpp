#include <stdio.h>
#include <assert.h>
#include "../common/astro.h"

int main()
{
  CAstro::Date_t date{2021, 4, 2}; // 2. April 2021
  CAstro::Time_t time{17, 45}; // 17:45
  CAstro::Pos_t pos{48.14, 17.10};
  CAstro astro;
  CAstro::State_t state = astro.Sunrise(date, pos);
  CAstro::EDayNight day = astro.CalculateSunrise(state, time);

  const char* season[] = {"spring", "summer", "autumn", "winter"};
  printf("res=%s, season=%s\n", astro.GetState(day), season[(int)state.phase/90]);
}