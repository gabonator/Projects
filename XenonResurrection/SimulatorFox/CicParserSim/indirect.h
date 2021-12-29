void sub_5dce();
void sub_476c();
void sub_4dfd();
void sub_4e87();
void sub_63f1();
void sub_63bf();
void sub_4d0b();
void sub_4748();
void sub_47b7();
void sub_47fa();
void sub_4df9();
void sub_47b7();
void sub_47d3();
void sub_5a04();
void sub_4e88();
void sub_4d0c();
void sub_4dc9();
void sub_4d10();
void sub_4db1();
void sub_4826();
void sub_4f03();
void sub_4e2e();
void sub_495b();
void sub_48cc();
void sub_48d6();
void sub_622e();
void sub_4833();
void sub_14e5();
void sub_157c();
void sub_147a();
void sub_147d();
void sub_1585();
void sub_14dd();
void sub_158c();
void sub_1591();

void sub_4d0b()
{
    return;
}

void _indirectCall(int ofs)
{
    switch(ofs)
    {
        case 0x5dce: sub_5dce(); return;
        case 0x476c: sub_476c(); return; // player
        case 0x4dfd: sub_4dfd(); return;
        case 0x4e87: sub_4e87(); return;
        case 0x63f1: sub_63f1(); return;
        case 0x63bf: sub_63bf(); return;
        case 0x4d0b: sub_4d0b(); return;
        case 0x4748: sub_4748(); return; // jump
        case 0x47b4: sub_47b7(); return;
        case 0x47fa: sub_47fa(); return; // move
        case 0x4df9: sub_4df9(); return; // jump
        case 0x47b7: sub_47b7(); return; // down
        case 0x47d3: sub_47d3(); return; // down move
        case 0x5a04: sub_5a04(); return;
        case 0x4e88: sub_4e88(); return; // block collision
        case 0x4d0c: sub_4d0c(); return; // block collision
            
        case 0x4dc9: sub_4dc9(); return; //collectable
        case 0x4d10: sub_4d10(); return; //collectable
        case 0x4db1: sub_4db1(); return; //collectable
        case 0x4826: sub_4826(); return; // hit by homeless
        case 0x4f03: sub_4f03(); return;
        case 0x4e2e: sub_4e2e(); return;
        case 0x495b: sub_495b(); return; // grab item
        case 0x48cc: sub_48cc(); return;
        case 0x48d6: sub_48d6(); return; // throw item
        case 0x622e: sub_622e(); return;
        case 0x4833: sub_4833(); return; // ladder
        
        case 0x14e5: /*sub_14e5();*/ return; // sound
        case 0x157c: sub_157c(); return; // sound
        case 0x147a: sub_147a(); return; // sound
        case 0x1585: sub_1585(); return; // sound
        case 0x147d: sub_147d(); return; // sound
        case 0x14dd: sub_14dd(); return; // sound
        case 0x158c: sub_158c(); return;
        case 0x1591: sub_1591(); return;
    }
    std::cout << "Ignore indirect " << ofs << "\n";
    //_ASSERT(0);
}

