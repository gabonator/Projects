void sub_8518(); 
void sub_8fe1(); 
void sub_85e7(); 
void sub_841e(); 
void sub_8457(); 
void sub_84cb(); 
void sub_8569(); 
void sub_81f6(); 
void sub_83ec(); 
void sub_84b5(); 
void sub_84f7(); 
void sub_85a8(); 
void sub_8242(); 
void sub_8405(); 
void sub_860a(); 
void sub_83b2(); 
void sub_84e1(); 
void sub_83cf(); 
void sub_834e(); 
void sub_8618(); 
void sub_8659(); 
void sub_81d5(); 
void sub_82dc(); 
void sub_832d(); 
void sub_84a2(); 
void sub_87ce(); 
void sub_880a(); 
void sub_8391(); 
void sub_86b2(); 
void sub_86e3(); 
void sub_869a(); 
void sub_86cb(); 
void sub_8702(); 
void sub_871b(); 
void sub_87b6(); 
void sub_87f2(); 
void sub_8760(); 
void sub_878b(); 
void sub_47c9(); 
void sub_4286(); 
void sub_42f3(); 
void sub_4340(); 
void sub_435e(); 
void sub_43a7(); 
void sub_43da(); 
void sub_447d(); 
void sub_4180(); 
void sub_6214(); 
void sub_6307(); 
void sub_3d2e(); 
void sub_3d60(); 
void sub_3d92(); 
void sub_3e0e(); 
void sub_4008(); 
void sub_40b7(); 
void sub_bb32(); 
void sub_c91e(); 
void sub_df4f(); 
void sub_fb7f(); 
void sub_c27e(); 
void sub_f9c4(); 
void sub_e600(); 
void sub_e2e4(); 
void sub_ca60(); 
void sub_ca8b(); 
void sub_12245();
void sub_d016(); 
void sub_d080(); 
void sub_d0d7(); 
void sub_d500(); 
void sub_d530(); 
void sub_d250(); 
void sub_d283(); 
void sub_dac0(); 
void sub_dae7(); 
void sub_fbb9(); 
void sub_fdcd(); 
void sub_e067(); 
void sub_fe71(); 
void sub_d810(); 
void sub_d840(); 
void sub_d593(); 
void sub_3d0d(); 
void sub_d37f(); 
void sub_d65d(); 
void sub_d665(); 
void sub_4191(); 
void sub_6c8f(); 
void sub_6f29(); 
void sub_6d99(); 
void sub_6f3f(); 
void sub_6e1e(); 
void sub_41a2(); 
void sub_6ef5(); 
void sub_6f0f(); 
void sub_6d14(); 
void sub_46e0(); 

namespace CicoContext
{
  void cicocontext_t::callIndirect(int a)
  {
//    char temp[128];
//    sprintf(temp, "callIndirect(%x)", a);
//    apiPrint(temp);
    switch (a)
    {
        case 0x8518: sub_8518(); return; // 01ed:6648
        case 0x8fe1: sub_8fe1(); return; // 01ed:7111
        case 0x85e7: sub_85e7(); return; // 01ed:6717
        case 0x841e: sub_841e(); return; // 01ed:654e
        case 0x8457: sub_8457(); return; // 01ed:6587
        case 0x84cb: sub_84cb(); return; // 01ed:65fb
        case 0x8569: sub_8569(); return; // 01ed:6699
        case 0x81f6: sub_81f6(); return; // 01ed:6326
        case 0x83ec: sub_83ec(); return; // 01ed:651c
        case 0x84b5: sub_84b5(); return; // 01ed:65e5
        case 0x84f7: sub_84f7(); return; // 01ed:6627
        case 0x85a8: sub_85a8(); return; // 01ed:66d8
        case 0x8242: sub_8242(); return; // 01ed:6372
        case 0x8405: sub_8405(); return; // 01ed:6535
        case 0x860a: sub_860a(); return; // 01ed:673a
        case 0x83b2: sub_83b2(); return; // 01ed:64e2
        case 0x84e1: sub_84e1(); return; // 01ed:6611
        case 0x83cf: sub_83cf(); return; // 01ed:64ff
        case 0x834e: sub_834e(); return; // 01ed:647e
        case 0x8618: sub_8618(); return; // 01ed:6748
        case 0x8659: sub_8659(); return; // 01ed:6789
        case 0x81d5: sub_81d5(); return; // 01ed:6305
        case 0x82dc: sub_82dc(); return; // 01ed:640c
        case 0x832d: sub_832d(); return; // 01ed:645d
        case 0x84a2: sub_84a2(); return; // 01ed:65d2
        case 0x87ce: sub_87ce(); return; // 01ed:68fe
        case 0x880a: sub_880a(); return; // 01ed:693a
        case 0x8391: sub_8391(); return; // 01ed:64c1
        case 0x86b2: sub_86b2(); return; // 01ed:67e2
        case 0x86e3: sub_86e3(); return; // 01ed:6813
        case 0x869a: sub_869a(); return; // 01ed:67ca
        case 0x86cb: sub_86cb(); return; // 01ed:67fb
        case 0x8702: sub_8702(); return; // 01ed:6832
        case 0x871b: sub_871b(); return; // 01ed:684b
        case 0x87b6: sub_87b6(); return; // 01ed:68e6
        case 0x87f2: sub_87f2(); return; // 01ed:6922
        case 0x8760: sub_8760(); return; // 01ed:6890
        case 0x878b: sub_878b(); return; // 01ed:68bb
            
            // sub_3cd2
        case 0x47c9: sub_47c9(); return; // 01ed:28f9
        case 0x4286: sub_4286(); return; // 01ed:23b6
        case 0x42f3: sub_42f3(); return; // 01ed:2423
        case 0x4340: sub_4340(); return; // 01ed:2470
        case 0x435e: sub_435e(); return; // 01ed:248e
        case 0x43a7: sub_43a7(); return; // 01ed:24d7
        case 0x43da: sub_43da(); return; // 01ed:250a
        case 0x447d: sub_447d(); return; // 01ed:25ad
        case 0x4180: sub_4180(); return; // 01ed:22b0
        case 0x6214: sub_6214(); return; // 01ed:4344
        case 0x6307: sub_6307(); return; // 01ed:4437
        case 0x3d2e: sub_3d2e(); return; // 01ed:1e5e
        case 0x3d60: sub_3d60(); return; // 01ed:1e90
        case 0x3d92: sub_3d92(); return; // 01ed:1ec2
        case 0x3e0e: sub_3e0e(); return; // 01ed:1f3e
        case 0x4008: sub_4008(); return; // 01ed:2138
        case 0x40b7: sub_40b7(); return; // 01ed:21e7

        case 0xbb32: sub_bb32(); return;
        case 0xc91e: sub_c91e(); return;
        case 0xdf4f: sub_df4f(); return;
        case 0xfb7f: sub_fb7f(); return;
        case 0xc27e: sub_c27e(); return;
        case 0xf9c4: sub_f9c4(); return;
        case 0xe600: sub_e600(); return;
        case 0xe2e4: sub_e2e4(); return;
        case 0xca60: sub_ca60(); return;
        case 0xca8b: sub_ca8b(); return;
        case 0x12245: sub_12245(); return;
        case 0xd016: sub_d016(); return;
        case 0xd080: sub_d080(); return;
        case 0xd0d7: sub_d0d7(); return;
        case 0xd500: sub_d500(); return;
        case 0xd530: sub_d530(); return;
        case 0xd250: sub_d250(); return;
        case 0xd283: sub_d283(); return;
        case 0xdac0: sub_dac0(); return;
        case 0xdae7: sub_dae7(); return;
        case 0xfbb9: sub_fbb9(); return;
        case 0xfdcd: sub_fdcd(); return;
        case 0xe067: sub_e067(); return;
        case 0xfe71: sub_fe71(); return;
        case 0xd810: sub_d810(); return;
        case 0xd840: sub_d840(); return;
        case 0xd593: sub_d593(); return;                        
        case 0x3d0d: sub_3d0d(); return;
        case 0xd37f: sub_d37f(); return;
        case 0xd65d: sub_d65d(); return;
        case 0xd665: sub_d665(); return;
        case 0x4191: sub_4191(); return;
        case 0x6c8f: sub_6c8f(); return;
        case 0x6f29: sub_6f29(); return;
        case 0x6d99: sub_6d99(); return;
        case 0x6f3f: sub_6f3f(); return;
        case 0x6e1e: sub_6e1e(); return;
        case 0x41a2: sub_41a2(); return;
        case 0x6ef5: sub_6ef5(); return;
        case 0x6f0f: sub_6f0f(); return;
        case 0x6d14: sub_6d14(); return;
        case 0x46e0: sub_46e0(); return;
        default:
            assert(0);
    }
   }
}
