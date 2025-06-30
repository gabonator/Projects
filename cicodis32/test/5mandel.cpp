void sub_15e010()
{
  push32(0x0000009c);
  sub_15e27b();
  push32(ebx);
  push32(ecx);
  push32(edx);
  push32(esi);
  push32(edi);
  push32(ebp);
  esp -= 0x00000080;
  eax = 0;
  memoryASet32(ds, esp + 108, eax);
  memoryASet32(ds, esp + 112, 0xbff80000);
  memoryASet32(ds, esp + 116, eax);
  memoryASet32(ds, esp + 120, 0xbff00000);
  memoryASet32(ds, esp + 52, eax);
  edi = 0x40000000;
  memoryASet32(ds, esp + 56, edi);
  memoryASet32(ds, esp + 76, eax);
  memoryASet32(ds, esp + 80, edi);
  ebp = 0x000a0000;
  memoryASet16(ds, esp, 0x0013);
  ebx = esp;
  edx = esp;
  eax = 0x00000010;
  sub_15e2b0();
  eax = 0;
  ecx = 0;
lab_15e072:
  edx = ecx;
  eax = 0x000003c8;
  sub_15e2d0();
  memoryASet32(ds, esp + 124, ecx);
  fild32(memoryAGet32(ds, esp + 124));
  fmul64(memoryAGet64(ds, 0x17c004));
  memoryASet64(ds, esp + 36, fstp64());
  fld1();
  fmul64(memoryAGet64(ds, esp + 36));
  sub_15e2dc();
  fmul64(memoryAGet64(ds, 0x17c00c));
  fsubr64(memoryAGet64(ds, 0x17c014));
  sub_15e358();
  memoryASet64(ds, esp + 84, fistp());
  edx = memoryAGet32(ds, esp + 84);
  eax = 0x000003c9;
  sub_15e2d0();
  fld64(memoryAGet64(ds, esp + 36));
  fmul64(memoryAGet64(ds, 0x17c01c));
  sub_15e2dc();
  fmul64(memoryAGet64(ds, 0x17c00c));
  fsubr64(memoryAGet64(ds, 0x17c014));
  sub_15e358();
  memoryASet64(ds, esp + 84, fistp());
  edx = memoryAGet32(ds, esp + 84);
  eax = 0x000003c9;
  sub_15e2d0();
  fld64(memoryAGet64(ds, esp + 36));
  fmul64(memoryAGet64(ds, 0x17c024));
  sub_15e2dc();
  fmul64(memoryAGet64(ds, 0x17c00c));
  fsubr64(memoryAGet64(ds, 0x17c014));
  sub_15e358();
  memoryASet64(ds, esp + 84, fistp());
  edx = memoryAGet32(ds, esp + 84);
  eax = 0x000003c9;
  sub_15e2d0();
  ecx++;
  
  if ((int32_t)ecx < (int32_t)0x00000100) goto loc_15e072;
  ebx = 0;
  goto loc_15e140;
lab_15e133:
  ebx++;
  
  if ((int32_t)ebx >= (int32_t)0x000000c8) goto loc_15e241;
lab_15e140:
  memoryASet32(ds, esp + 124, ebx);
  fild32(memoryAGet32(ds, esp + 124));
  fmul64(memoryAGet64(ds, esp + 76));
  fdiv64(memoryAGet64(ds, 0x17c02c));
  fadd64(memoryAGet64(ds, esp + 116));
  memoryASet64(ds, esp + 68, fstp64());
  ecx = 0;
  goto loc_15e210;
lab_15e161:
  edx++;
  
  if (edx > 0x00000100) goto loc_15e1cf;
lab_15e16a:
  fld64(memoryAGet64(ds, esp + 92));
  fmul80(st(0));
  fld64(memoryAGet64(ds, esp + 100));
  fmul80(st(0));
  fsubp80(st(1));
  fadd64(memoryAGet64(ds, esp + 44));
  memoryASet64(ds, esp + 28, fstp64());
  fld64(memoryAGet64(ds, esp + 92));
  fmul64(memoryAGet64(ds, 0x17c03c));
  fmul64(memoryAGet64(ds, esp + 100));
  fadd64(memoryAGet64(ds, esp + 68));
  memoryASet64(ds, esp + 60, fstp64());
  eax = memoryAGet32(ds, esp + 28);
  memoryASet32(ds, esp + 92, eax);
  eax = memoryAGet32(ds, esp + 32);
  memoryASet32(ds, esp + 96, eax);
  eax = memoryAGet32(ds, esp + 60);
  memoryASet32(ds, esp + 100, eax);
  eax = memoryAGet32(ds, esp + 64);
  memoryASet32(ds, esp + 104, eax);
  fld64(memoryAGet64(ds, esp + 28));
  fmul80(st(0));
  fld64(memoryAGet64(ds, esp + 60));
  fmul80(st(0));
  fadd80(st(1));
  fcomp64(memoryAGet64(ds, 0x17c044));
  ax = fnstsw();
  sahf();
  if (flags.carry) goto loc_15e161;
lab_15e1cf:
  
  if (edx >= 0x00000100) goto loc_15e203;
  memoryASet32(ds, esp + 124, edx);
  fild32(memoryAGet32(ds, esp + 124));
  fmul64(memoryAGet64(ds, 0x17c04c));
  fmul64(memoryAGet64(ds, 0x17c054));
  sub_15e358();
  memoryASet32(ds, esp + 124, fistp());
  al = memoryAGet(ds, esp + 124);
  edx = ebx * 0x00000140
  edx += ebp;
  memoryASet(ds, ecx + edx, al);
lab_15e203:
  ecx++;
  
  if ((int32_t)ecx >= (int32_t)0x00000140) goto loc_15e133;
lab_15e210:
  memoryASet32(ds, esp + 124, ecx);
  fild32(memoryAGet32(ds, esp + 124));
  fmul64(memoryAGet64(ds, esp + 52));
  fdiv64(memoryAGet64(ds, 0x17c034));
  fadd64(memoryAGet64(ds, esp + 108));
  memoryASet64(ds, esp + 44, fstp64());
  edx = 0;
  memoryASet32(ds, esp + 92, edx);
  memoryASet32(ds, esp + 96, edx);
  memoryASet32(ds, esp + 100, edx);
  memoryASet32(ds, esp + 104, edx);
  goto loc_15e16a;
lab_15e241:
  sub_15e370();
  memoryASet16(ds, esp, 0x0003);
  ebx = esp;
  edx = esp;
  eax = 0x00000010;
  sub_15e2b0();
  eax = 0x00000001;
  esp += 0x00000080;
  ebp = pop32();
  edi = pop32();
  esi = pop32();
  edx = pop32();
  ecx = pop32();
  ebx = pop32();
  return;
}

void sub_15e27b()
{
  push32(eax);
  eax = memoryAGet32(ds, esp + 8);
  
  if (eax >= esp) goto loc_15e2a0;
  eax -= esp;
  eax = -eax;
  
  if (eax > memoryAGet32(ds, 0x17c234)) goto loc_15e29a;
  ax = ss;
  
lab_15e29a:
  if (eax == memoryAGet32(ds, 0x17c234)) goto loc_15e2a0;
  eax = pop32();
  return;
lab_15e2a0:
  eax = pop32();
  eax = 0x0017c1f6;
  edx = 0x00000001;
  goto loc_15e6c0;
gap 729 bytes
lab_15e589:
  push32(eax);
  goto loc_15e5bc;
lab_15e58c:
  push32(edx);
  push32(eax);
  edx = 0x0015e399;
  ax = 0x3d01;
  interrupt(0x21);
  bx = ax;
  edx = pop32();
  esi = edx;
  flags.direction = 0;
lab_15e5a0:
  lodsb<MemAuto, DirAuto>();
  
  if (!al) goto loc_15e5a0;
  ecx = esi;
  ecx -= edx;
  ecx--;
  ah = 0x40;
  interrupt(0x21);
  edx = 0x0015e39d;
  ecx = 0x00000002;
  ah = 0x40;
  interrupt(0x21);
lab_15e5bc:
  eax = 0;
  edx = 0x0000000f;
  sub_15e880();
  eax = pop32();
  ah = 0x4c;
  interrupt(0x21);
gap 243 bytes
lab_15e6c0:
  ebx = eax;
  ecx = edx;
  edx = ds;
  sub_15fa60();
  
  if (!eax) goto loc_15e6d8;
  edx = ecx;
  eax = ebx;
  goto loc_15e58c;
lab_15e6d8:
  eax = ecx;
  goto loc_15e589;
}

void sub_15e2b0()
{
  push32(ecx);
  push32(esi);
  esp -= 0x0000000c;
  esi = eax;
  eax = esp;
  ecx = esp;
  sub_15e6e0();
  eax = esi;
  sub_15e710();
  esp += 0x0000000c;
  esi = pop32();
  ecx = pop32();
  return;
}

void sub_15e2d0()
{
  push32(ecx);
  ecx = eax;
  al = dl;
  edx = ecx;
  out(dx, al);
  ecx = pop32();
  return;
}

void sub_15e2dc()
{
lab_15e2dc:
  fcos();
  sub_15e2f0();
  if (!flags.carry) goto loc_15e2dc;
  return;
}

void sub_15e2f0()
{
  push32(ebp);
  ebp = esp;
  push32(eax);
  
  memoryASet16(ds, ebp + 65534, fnstsw());
  
  ah = memoryAGet(ds, ebp + 65535);
  ah |= 0x01;
  sahf();
  if (!flags.parity) goto loc_15e31a;
  fld80(memoryAGet80(ds, 0x17c208));
  fxch(st(0));
lab_15e30a:
  fprem();
  
  memoryASet16(ds, ebp + 65534, fnstsw());
  
  ah = memoryAGet(ds, ebp + 65535);
  sahf();
  if (flags.parity) goto loc_15e30a;
  st(1) = fstp80();
  flags.carry = 0;
lab_15e31a:
  eax = pop32();
  ebp = pop32();
  return;
}

void sub_15e358()
{
  push32(0x00000c3f);
  memoryASet16(ds, esp + 2, fnstcw());
  fldcw(memoryAGet16(ds, esp));
  frndtint();
  fldcw(memoryAGet16(ds, esp + 2));
  esp = esp + 4;
  return;
}

void sub_15e370()
{
  push32(edx);
  edx = 0;
  eax = memoryAGet32(ds, 0x17c244);
  memoryASet32(ds, 0x17c244, edx);
  
  if (eax) goto loc_15e384;
  edx = pop32();
  return;
lab_15e384:
  ah = 0x08;
  interrupt(0x21);
  eax &= 0x000000ff;
  edx = pop32();
  return;
}

void sub_15e6e0()
{
  push32(edx);
  edx = eax;
  eax = cs;
  memoryASet16(ds, edx + 2, ax);
  eax = ds;
  memoryASet16(ds, edx + 6, ax);
  eax = es;
  memoryASet16(ds, edx, ax);
  eax = ss;
  memoryASet16(ds, edx + 4, ax);
  eax = fs;
  memoryASet16(ds, edx + 8, ax);
  eax = gs;
  memoryASet16(ds, edx + 10, ax);
  edx = pop32();
  return;
}

void sub_15e710()
{
  push32(esi);
  push32(edi);
  push32(ebp);
  edi = edx;
  ebp = ebx;
  eax &= 0x000000ff;
  ebx = ecx;
  edx = ebp;
  sub_15fa88();
  eax = memoryAGet32(ds, ebp);
  ebp = pop32();
  edi = pop32();
  esi = pop32();
  return;
}

void sub_15e880()
{
  push32(ebx);
  push32(ecx);
  push32(esi);
  push(es);
  bl = al;
  dh = dl;
  esi = 0x0017c690;
lab_15e88d:
  eax = 0x0017c68a;
  ecx = esi;
  dl = bl;
  
  if (esi <= eax) goto loc_15e8b4;
lab_15e89a:
  
  if (memoryAGet(ds, eax) == 0x02) goto loc_15e8aa;
  bh = memoryAGet(ds, eax + 1);
  
  if (dl > bh) goto loc_15e8aa;
  ecx = eax;
  dl = bh;
lab_15e8aa:
  eax += 0x00000006;
  
  if (eax < 0x0017c690) goto loc_15e89a;
lab_15e8b4:
  
  if (ecx == 0x0017c690) goto loc_15e8d0;
  
  if (dh >= memoryAGet(ds, ecx + 1)) goto loc_15e8c6;
lab_15e8c1:
  memoryASet(ds, ecx, 0x02);
  goto loc_15e88d;
lab_15e8c6:
  eax = ecx + 2;
  sub_15e820();
  goto loc_15e8c1;
lab_15e8d0:
  es = pop();
  esi = pop32();
  ecx = pop32();
  ebx = pop32();
  return;
}

void sub_15e820()
{
  push(es);
  
  if (memoryAGet32(ds, eax) != 0x00000000) goto loc_15e828;
  es = pop();
  return;
lab_15e828:
  push(ds);
  es = pop();
  callIndirect(memoryAGet32(ds, eax));
  es = pop();
  return;
}

void sub_15fa60()
{
  
  if (memoryAGet(ds, 0x17c38c) != 0x00) goto loc_15fa6c;
  eax = 0;
  return;
lab_15fa6c:
  edx &= 0x0000ffff;
  push32(edx);
  push32(eax);
  stop();
  goto loc_15fa7d;
gap 6 bytes
lab_15fa7d:
  eax = 0x00000001;
  esp += 0x00000008;
  return;
}

void sub_15fa88()
{
  pushfd();
  push32(ebp);
  push(es);
  push(ds);
  push32(edx);
  push32(ebx);
  edx = 0;
  sub_15fac8();
  push(ds);
  push32(edx);
  ebp = esp;
  ds = memoryAGet16(ds, ebp + 16);
  edx = memoryAGet32(ds, ebp + 12);
  memoryASet32(ds, edx, eax);
  memoryASet32(ds, edx + 4, ebx);
  memoryASet32(ds, edx + 8, ecx);
  memoryASet32(ds, edx + 12, pop32());
  memoryASet32(ds, edx + 16, esi);
  memoryASet32(ds, edx + 20, edi);
  eax = -flags.carry;
  eax &= 0x00000001;
  memoryASet32(ds, edx + 24, eax);
  eax = pop32();
  ebx = pop32();
  memoryASet16(ds, ebx, es);
  memoryASet16(ds, ebx + 6, ax);
  edx = pop32();
  ds = pop();
  es = pop();
  ebp = pop32();
  popfd();
  return;
}

void sub_15fac8()
{
  eax = eax + eax*2;
  eax = eax + 64371;
  push32(eax);
  ah = dl;
  sahf();
  es = memoryAGet16(ds, ebx);
  bp = memoryAGet16(ds, ebx + 6);
  eax = memoryAGet32(ds, edi);
  ebx = memoryAGet32(ds, edi + 4);
  ecx = memoryAGet32(ds, edi + 8);
  edx = memoryAGet32(ds, edi + 12);
  esi = memoryAGet32(ds, edi + 16);
  edi = memoryAGet32(ds, edi + 20);
  ds = bp;
  return;
}
