void sub_204d();
void sub_5d62();
void sub_8e60();
void sub_9032();
void sub_43e0();
void sub_45b7();
void sub_9082();
void sub_4611();
void sub_4862();
void sub_4778();
void sub_8edf();
void sub_4430();
void sub_8f3c();
void sub_4677();
void sub_90d3();
void sub_4666();
void sub_86d9();
void sub_90e2();
void sub_44c3();
void sub_8fb6();
void sub_9112();
void sub_47b2();
void sub_9028();
void sub_8ed9();
void sub_444c();
void sub_8fa0();
void sub_4bde();
void sub_4bd1();
void sub_4918();
void sub_8f74();
void sub_4464();
void sub_4628();
void sub_8f86();
void sub_4693();
void sub_4928();
void sub_9014();
void sub_473c();
void sub_8fa9();
void sub_43f0();

void CicoContext::cicocontext_t::callIndirect(int a)
{
//    sync();
    switch (a)
    {
        case 0x204d: sub_204d(); return;
        case 0x5d62: sub_5d62(); return;
        case 0x402e: return;
        case 0x8e60: sub_8e60(); return;
        case 0x9032: sub_9032(); return;
        case 0x43e0: sub_43e0(); return;
        case 0x45b7: sub_45b7(); return;
        case 0x9082: sub_9082(); return;
        case 0x4611: sub_4611(); return;
        case 0x4862: sub_4862(); return;
        case 0x4778: sub_4778(); return;
        case 0x8edf: sub_8edf(); return;
        case 0x4430: sub_4430(); return;
        case 0x8f3c: sub_8f3c(); return;
        case 0x4677: sub_4677(); return;
        case 0x90d3: sub_90d3(); return;
        case 0x4666: sub_4666(); return;
        case 0x86d9: sub_86d9(); return;
        case 0x90e2: sub_90e2(); return;
        case 0x44c3: sub_44c3(); return;
        case 0x8fb6: sub_8fb6(); return;
        case 0x9112: sub_9112(); return;
        case 0x47b2: sub_47b2(); return;
        case 0x9028: sub_9028(); return;
        case 0x8ed9: sub_8ed9(); return;
        case 0x444c: sub_444c(); return;
        case 0x8fa0: sub_8fa0(); return;
        case 0x4bde: sub_4bde(); return;
        case 0x4bd1: sub_4bd1(); return;
        case 0x4918: sub_4918(); return;
        case 0x8f74: sub_8f74(); return;
        case 0x4464: sub_4464(); return;
        case 0x1a50a: /* mouse */;
            ctx._cs = pop(); // retf
            ctx.a.r16 = 0xffff;
            ctx.b.r16 = 3;            
            return; //0A57:0000FF9A int 33
        case 0x4628: sub_4628(); return;
        case 0x8f86: sub_8f86(); return;
        case 0x4693: sub_4693(); return;
        case 0x4928: sub_4928(); return;
        case 0x9014: sub_9014(); return;
        case 0x473c: sub_473c(); return;
        case 0x8fa9: sub_8fa9(); return;
        case 0x43f0: sub_43f0(); return;
        default:
            assert(0);
     }
}
