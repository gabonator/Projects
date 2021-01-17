void analyse(CArray<uint16_t>&);

    uint16_t arrSignalData[400];
    CArray<uint16_t> arrSignal(arrSignalData, COUNT(arrSignalData));

    void framerPush(int v)
    {
        if (v==-1)
        {
            if (arrSignal.GetSize() > 60 && arrSignal.GetSize() < 500)
            {
                analyse(arrSignal);
            }
                
            arrSignal.RemoveAll();
            return;
        }

        if (arrSignal.GetSize() < arrSignal.GetMaxSize())
            arrSignal.Add(v);
    }

// TODO: bug is somewhere here!
    void framerJoin(int interval)
    {
        // L:1000, H:0, L:1000, H:0, L:300, H:1000, L:0, H:1000, L:0, H:100, L:500, H:500, L:500, H:500
        // -> L:2300, H:2100, L:500, H:500, L:500, H:500

        static int interval1 = 0;
        static int interval2 = 0;
        static bool leading = true;
        static bool terminated = false;

        if (interval == -1)
        {
            interval1 = 0;
            interval2 = 0;
            leading = true;
            framerPush(-1);
            return;
        }
        if (interval1 == 0)
            interval += interval2;

        if (interval > 12000) // 12 ms max
        {
            if (!terminated)
            {
                terminated = true;
                framerPush(-1);
            }
            leading = true; // aj tak ho potom pretlaci cez interval2!!
        }

        if (interval1 != 0 && interval2 != 0)
        {
            if (leading)
                leading = false;
            else
            {
                framerPush(interval2);
                terminated = false;
            }
        }

        interval2 = interval1;
        interval1 = interval;
    }
