struct DateTime_t
{
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  uint8_t day;
  uint8_t month;
  uint16_t year;

  bool IsDls()
  {
    if (month < 3 && month > 10)
      return false;
    if (month > 3 && month < 10)
      return true;
    if (month == 3)
    {
      if (day >= (31 - (5*year/4 + 4) % 7) && hour >= 1)
        return true;
      else
        return false;
    }
    if (month == 10)
    {
      if (day >= (31 - (5*year/4 + 1) % 7) && hour >= 1)
        return false;
      else
        return true;
    }
    assert(0);
    return false;
  }

  int GetTimezone()
  {
    return IsDls() ? +2 : +1;
  }

  int GetTimestamp()
  {
    return hour*60 + minute;
  }

  // local
  int LocalHour()
  {
    return (hour + GetTimezone())%24;
  }
  int LocalMinute()
  {
    return minute;
  }
  int LocalDay()
  {
    return day + ((hour + GetTimezone() >= 24) ? 1 : 0);
  }
  int LocalMonth()
  {
    return month; // lazy
  }
  int LocalYear()
  {
    return year; // lazy
  }
};

