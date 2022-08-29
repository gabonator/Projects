function* sub_4d0b()
{
}

function* sub_4e87()
{
}

function* indirectCall(ofs)
{
    switch(ofs)
    {
        case 0x5dce: yield* sub_5dce(); return;
        case 0x476c: yield* sub_476c(); return; // player
        case 0x4dfd: yield* sub_4dfd(); return;
        case 0x4e87: yield* sub_4e87(); return;
        case 0x63f1: yield* sub_63f1(); return;
        case 0x63bf: yield* sub_63bf(); return;
        case 0x4d0b: yield* sub_4d0b(); return;
        case 0x4748: yield* sub_4748(); return; // jump
        case 0x47b4: yield* sub_47b7(); return;
        case 0x47fa: yield* sub_47fa(); return; // move
        case 0x4df9: yield* sub_4df9(); return; // jump
        case 0x47b7: yield* sub_47b7(); return; // down
        case 0x47d3: yield* sub_47d3(); return; // down move
        case 0x5a04: yield* sub_5a04(); return;
        case 0x4e88: yield* sub_4e88(); return; // block collision
        case 0x4d0c: yield* sub_4d0c(); return; // block collision
            
        case 0x4dc9: yield* sub_4dc9(); return; //collectable
        case 0x4d10: yield* sub_4d10(); return; //collectable
        case 0x4db1: yield* sub_4db1(); return; //collectable
        case 0x4826: yield* sub_4826(); return; // hit by homeless
        case 0x4f03: yield* sub_4f03(); return;
        case 0x4e2e: yield* sub_4e2e(); return;
        case 0x495b: yield* sub_495b(); return; // grab item
        case 0x48cc: yield* sub_48cc(); return;
        case 0x48d6: yield* sub_48d6(); return; // throw item
        case 0x622e: yield* sub_622e(); return;
        case 0x4833: yield* sub_4833(); return; // ladder
        
        case 0x14e5: /*sub_14e5();*/ return; // sound
        case 0x157c: yield* sub_157c(); return; // sound
        case 0x147a: yield* sub_147a(); return; // sound
        case 0x1585: yield* sub_1585(); return; // sound
        case 0x147d: yield* sub_147d(); return; // sound
        case 0x14dd: yield* sub_14dd(); return; // sound
        case 0x158c: yield* sub_158c(); return;
        case 0x1591: yield* sub_1591(); return;

        case 0x4814: yield* sub_4814(); return;
        case 0x4e01: yield* sub_4e01(); return;
        case 0x4dc0: yield* sub_4dc0(); return;
        case 0x4807: yield* sub_4807(); return;
    }
    console.log("Unimplemented indirect call "+ofs.toString(16));
    //throw "Indirect";
}
