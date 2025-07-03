#include "cico32.h"

void fixReloc(uint16_t seg);
void sub_10010();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1d20;
    cs = 0x1000;
    ds = 0x0ff0;
    es = 0x0ff0;
    ss = 0x1cfc;
    sp = 0x0100;
    load("", "GOOSE.EXE", 53684);
    fixReloc(cs);
    sub_10010();
}

void fixReloc(uint16_t seg)
{
    memoryASet16(seg, 0x0011, memoryAGet16(seg, 0x0011) + seg); // 03a5 -> 103a5
    memoryASet16(seg, 0x04d1, memoryAGet16(seg, 0x04d1) + seg); // 03a5 -> 103a5
    memoryASet16(seg, 0x05d8, memoryAGet16(seg, 0x05d8) + seg); // 03a5 -> 103a5
    memoryASet16(seg, 0x0b59, memoryAGet16(seg, 0x0b59) + seg); // 03a5 -> 103a5
}

void sub_10010();
void sub_100a9();
void sub_100cf();
void sub_100fd();
void sub_10103();
void sub_1019d();
void sub_101ad();
void sub_101c0();
void sub_1033b();
void sub_10442();
void sub_104a5();
void sub_104f3();
void sub_10529();
void sub_10541();
void sub_10588();
void sub_10591();
void sub_105bc();
void sub_105ec();
void sub_10600();
void sub_10637();
void sub_10644();
void sub_1064d();
void sub_10674();
void sub_1069a();
void sub_107af();
void sub_107fd();
void sub_108ba();
void sub_1094a();
void sub_109a4();
void sub_109b5();
void sub_109e9();
void sub_10a1b();
void sub_10a51();
void sub_10ad5();
void sub_10b58();
void sub_10b7c();
void sub_10b8e();
void sub_10bc5();
void sub_10bdc();
void sub_10c24();
void sub_10d98();
void sub_10da7();
void sub_10dc0();
void sub_10e07();
void sub_10e3d();
void sub_10e84();
void sub_10f3c();
void sub_10f9d();
void sub_10fda();
void sub_110a0();
void sub_110c6();
void sub_110f3();
void sub_11108();
void sub_112a7();
void sub_112cb();
void sub_112eb();
void sub_11384();
void sub_113a8();
void sub_11429();
void sub_114f0();
void sub_115fc();
void sub_116d6();
void sub_116df();
void sub_116fe();
void sub_1171f();
void sub_11740();
void sub_1176c();
void sub_11783();
void sub_117ac();
void sub_117d6();
void sub_117f4();
void sub_118a9();
void sub_118c7();
void sub_1196f();
void sub_11993();
void sub_119c2();
void sub_11a04();
void sub_11a9e();
void sub_11b09();
void sub_11b4a();
void sub_11b57();
void sub_11b80();
void sub_11bb9();
void sub_11c0a();
void sub_11c33();
void sub_11c56();
void sub_11c78();
void sub_11cd9();
void sub_11d1e();
void sub_11def();
void sub_11e7d();
void sub_11f0b();
void sub_11fba();
void sub_12005();
void sub_12047();
void sub_12092();
void sub_12099();
void sub_120a0();
void sub_120db();
void sub_120f0();
void sub_12121();
void sub_1215b();
void sub_121dc();
void sub_12200();
void sub_1220d();
void sub_122b1();
void sub_122c1();
void sub_122e1();
void sub_122f9();
void sub_12311();
void sub_12329();
void sub_1237c();
void sub_1239b();
void sub_123d4();
void sub_123ec();
void sub_12404();
void sub_1241c();
void sub_12434();
void sub_1244c();
void sub_12464();
void sub_1250b();
void sub_1252f();
void sub_12536();
void sub_12542();
void sub_12553();
void sub_12577();
void sub_1257e();
void sub_1258a();
void sub_1259b();
void sub_125bf();
void sub_125c6();
void sub_125d2();
void sub_125e3();
void sub_1264a();
void sub_12662();
void sub_12676();
void sub_1268a();
void sub_1269e();
void sub_12714();
void sub_12762();
void sub_1279f();
void sub_12809();
void sub_12872();
void sub_128da();
void sub_12907();
void sub_12959();
void sub_1296f();
void sub_129ae();
void sub_129db();
void sub_12a64();
void sub_12a7f();
void sub_12b28();
void sub_12c07();
void sub_12c45();
void sub_12c9a();
void sub_12cc7();
void sub_12cea();
void sub_12d9a();
void sub_12ddc();
void sub_12df6();
void sub_12e02();
void sub_12f50();
void sub_12fe8();
void sub_1300a();
void sub_13059();
void sub_13084();
void sub_1309d();
void sub_13130();
void sub_1315e();
void sub_13170();
void sub_13181();
void sub_13191();
void sub_131a4();
void sub_131e7();
void sub_13209();
void sub_13291();
void sub_132fe();
void sub_1333c();
void sub_13383();
void sub_133b3();
void sub_133d7();
void sub_133e5();
void sub_13423();
void sub_13439();
void sub_13472();
void sub_13498();
void sub_134a8();
void sub_135bc();
void sub_136d4();
void sub_13801();
void sub_1382a();
void sub_13840();
void sub_13914();
void sub_139a3();
void sub_139b8();

/*10 mov ax, 0x3a5*/
/*13 mov ds, ax*/
/*15 mov bx, 0x9670*/
/*18 add bx, 0xf*/
/*1b shr bx, 1*/
/*1d shr bx, 1*/
/*1f shr bx, 1*/
/*21 shr bx, 1*/
/*23 add ax, bx*/
/*25 mov word ptr [0x94e8], ax*/
/*28 add ax, 0x800*/
/*2b mov word ptr [0x94ea], ax*/
/*2e add ax, 0x800*/
/*31 mov word ptr [0x94ec], ax*/
/*34 add ax, 0x800*/
/*37 mov word ptr [0x94ee], ax*/
/*3a add ax, 0x800*/
/*3d mov word ptr [0x94f0], ax*/
/*40 add ax, 0x800*/
/*43 mov word ptr [0x94f2], ax*/
/*46 add ax, 0x800*/
/*49 mov word ptr [0x94f4], ax*/
/*4c add ax, 0x800*/
/*4f mov word ptr [0x94f6], ax*/
/*52 int 0x12*/
/*54 cmp ax, 0x200*/
/*57 jae 0x67*/
/*59 mov dx, 7*/
/*5c mov ah, 9*/
/*5e int 0x21*/
/*60 mov ax, 0x4c00*/
/*63 int 0x21*/
/*67 mov dx, 0x2a*/
/*6a mov ah, 9*/
/*6c int 0x21*/
/*6e call 0x600*/
/*71 call 0x333c*/
/*74 call 0x2762*/
/*77 call 0x5ec*/
/*7a call 0x442*/
/*7d call 0x588*/
/*80 call 0x591*/
/*83 call 0x382a*/
/*86 mov byte ptr [0], 0*/
/*8b call 0xa9*/
/*8e call 0xcf*/
/*91 call 0xfd*/
/*94 jmp 0x8b*/
void sub_10010()
{
  ax = 0x03a5;
  ds = ax;
  bx = 0x9670;
  bx += 0x000f;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  ax += bx;
  memoryASet16(ds, 0x94e8, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94ea, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94ec, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94ee, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94f0, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94f2, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94f4, ax);
  ax += 0x0800;
  memoryASet16(ds, 0x94f6, ax);
  interrupt(0x12);
  
  if (ax >= 0x0200) goto loc_10067;
  dx = 0x0007;
  ah = 0x09;
  interrupt(0x21);
  ax = 0x4c00;
  interrupt(0x21);
  stop();
  // gap 2 bytes
loc_10067:
  dx = 0x002a;
  ah = 0x09;
  interrupt(0x21);
  sub_10600();
  sub_1333c();
  sub_12762();
  sub_105ec();
  sub_10442();
  sub_10588();
  sub_10591();
  sub_1382a();
  memoryASet(ds, 0x9501, 0x00);
loc_1008b:
  sub_100a9();
  sub_100cf();
  sub_100fd();
  goto loc_1008b;
}

/*a9 call 0x103*/
/*ac mov byte ptr [0], 0*/
/*b1 mov byte ptr [0], 1*/
/*b6 mov byte ptr [0], 0x10*/
/*bb mov byte ptr [0], 0*/
/*c0 mov byte ptr [0], 0*/
/*c5 call 0xda7*/
/*c8 call 0x3423*/
/*cb call 0x21dc*/
/*ce ret */
void sub_100a9()
{
  sub_10103();
  memoryASet(ds, 0x9500, 0x00);
  memoryASet(ds, 0x94fe, 0x01);
  memoryASet(ds, 0x94fc, 0x10);
  memoryASet(ds, 0x94ff, 0x00);
  memoryASet(ds, 0x9502, 0x00);
  sub_10da7();
  sub_13423();
  sub_121dc();
  return;
}

/*cf call 0x1c0*/
/*d2 call 0xfda*/
/*d5 mov al, byte ptr [0x94ff]*/
/*d8 cmp al, 0*/
/*da jne 0xe4*/
/*dc call 0x32fe*/
/*df call 0xb8e*/
/*e2 jmp 0xed*/
/*e4 call 0x34a8*/
/*e7 call 0x31a4*/
/*ea call 0xb8e*/
/*ed call 0x220d*/
/*f0 call 0x3383*/
/*f3 mov al, byte ptr [0x9500]*/
/*f6 cmp al, 0*/
/*f8 jne 0xfc*/
/*fa jmp 0xcf*/
/*fc ret */
void sub_100cf()
{
loc_100cf:
  sub_101c0();
  sub_10fda();
  al = memoryAGet(ds, 0x94ff);
  
  if (al != 0x00) goto loc_100e4;
  sub_132fe();
  sub_10b8e();
  goto loc_100ed;
loc_100e4:
  sub_134a8();
  sub_131a4();
  sub_10b8e();
loc_100ed:
  sub_1220d();
  sub_13383();
  al = memoryAGet(ds, 0x9500);
  
  if (al != 0x00) goto loc_100fc;
  goto loc_100cf;
loc_100fc:
  return;
}

/*fd mov byte ptr [6], 1*/
/*102 ret */
void sub_100fd()
{
  memoryASet(ds, 0x0006, 0x01);
  return;
}

/*103 mov al, byte ptr [6]*/
/*106 cmp al, 0*/
/*108 je 0x115*/
/*10a mov word ptr [0], 0xda*/
/*110 call 0x279f*/
/*113 jmp 0x11e*/
/*115 mov word ptr [0], 0xe9*/
/*11b call 0x28da*/
/*11e call 0x39b8*/
/*121 call 0x3472*/
/*124 mov byte ptr [0], 1*/
/*129 mov word ptr [0], 0*/
/*12f call 0xd98*/
/*132 call 0x1c0*/
/*135 call 0xfda*/
/*138 call 0x3498*/
/*13b call 0xb8e*/
/*13e call 0x3383*/
/*141 mov ax, word ptr [0x954c]*/
/*144 test ax, 0x80*/
/*147 jne 0x197*/
/*149 inc word ptr [0]*/
/*14d mov bx, word ptr [0]*/
/*151 test bx, 7*/
/*155 jne 0x195*/
/*157 shr bx, 1*/
/*159 shr bx, 1*/
/*15b shr bx, 1*/
/*15d add bx, word ptr [0]*/
/*161 mov al, byte ptr [bx]*/
/*163 cmp al, 0*/
/*165 je 0x195*/
/*167 cmp al, 0xff*/
/*169 je 0x197*/
/*16b cmp al, 0xfe*/
/*16d jne 0x180*/
/*16f mov al, byte ptr [0x9546]*/
/*172 cmp al, 0*/
/*174 je 0x17b*/
/*176 call 0x29db*/
/*179 jmp 0x17e*/
/*17b call 0x1ad*/
/*17e jmp 0x195*/
/*180 test al, 0x80*/
/*182 jne 0x189*/
/*184 call 0x19d*/
/*187 jmp 0x195*/
/*189 and al, 0x3f*/
/*18b push ax*/
/*18c call 0x19d*/
/*18f pop ax*/
/*190 inc al*/
/*192 call 0x19d*/
/*195 jmp 0x132*/
/*197 mov byte ptr [0], 0*/
/*19c ret */
void sub_10103()
{
  al = memoryAGet(ds, 0x0006);
  
  if (al == 0x00) goto loc_10115;
  memoryASet16(ds, 0x8e7e, 0x00da);
  sub_1279f();
  goto loc_1011e;
loc_10115:
  memoryASet16(ds, 0x8e7e, 0x00e9);
  sub_128da();
loc_1011e:
  sub_139b8();
  sub_13472();
  memoryASet(ds, 0x9503, 0x01);
  memoryASet16(ds, 0x8e80, 0x0000);
  sub_10d98();
loc_10132:
  sub_101c0();
  sub_10fda();
  sub_13498();
  sub_10b8e();
  sub_13383();
  ax = memoryAGet16(ds, 0x954c);
  
  if (!(ax & 0x0080)) goto loc_10197;
  memoryASet16(ds, 0x8e80, memoryAGet16(ds, 0x8e80) + 1);
  bx = memoryAGet16(ds, 0x8e80);
  
  if (!(bx & 0x0007)) goto loc_10195;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx += memoryAGet16(ds, 0x8e7e);
  al = memoryAGet(ds, bx);
  
  if (al == 0x00) goto loc_10195;
  
  if (al == 0xff) goto loc_10197;
  
  if (al != 0xfe) goto loc_10180;
  al = memoryAGet(ds, 0x9546);
  
  if (al == 0x00) goto loc_1017b;
  sub_129db();
  goto loc_1017e;
loc_1017b:
  sub_101ad();
loc_1017e:
  goto loc_10195;
loc_10180:
  
  if (!(al & 0x80)) goto loc_10189;
  sub_1019d();
  goto loc_10195;
loc_10189:
  al &= 0x3f;
  push(ax);
  sub_1019d();
  ax = pop();
  al++;
  sub_1019d();
loc_10195:
  goto loc_10132;
loc_10197:
  memoryASet(ds, 0x9503, 0x00);
  return;
}

/*19d mov si, 0x109*/
/*1a0 mov byte ptr [si + 4], al*/
/*1a3 mov bx, 0x120*/
/*1a6 call 0x2121*/
/*1a9 call 0xb58*/
/*1ac ret */
void sub_1019d()
{
  si = 0x0109;
  memoryASet(ds, si + 4, al);
  bx = 0x0120;
  sub_12121();
  sub_10b58();
  return;
}

/*1ad mov cx, 0x1f40*/
/*1b0 push cx*/
/*1b1 call 0x1c0*/
/*1b4 pop cx*/
/*1b5 mov ax, word ptr [0x954c]*/
/*1b8 test al, 0x80*/
/*1ba je 0x1bd*/
/*1bc ret */
/*1bd loop 0x1b0*/
/*1bf ret */
void sub_101ad()
{
  cx = 0x1f40;
loc_101b0:
  push(cx);
  sub_101c0();
  cx = pop();
  ax = memoryAGet16(ds, 0x954c);
  
  if (al & 0x80) goto loc_101bd;
  return;
loc_101bd:
  if (--cx) goto loc_101b0;
  return;
}

/*96 call 0x39a3*/
/*99 call 0x5bc*/
/*9c call 0x4a5*/
/*9f mov ax, 3*/
/*a2 int 0x10*/
/*a4 mov ax, 0x4c00*/
/*a7 int 0x21*/
/*1c0 mov bx, 0x8e8a*/
/*1c3 mov si, 0x3d*/
/*1c6 mov al, byte ptr [bx + si]*/
/*1c8 cmp al, 0*/
/*1ca je 0x1d5*/
/*1cc mov si, 0x3e*/
/*1cf mov al, byte ptr [bx + si]*/
/*1d1 cmp al, 0*/
/*1d3 je 0x1cf*/
/*1d5 mov si, 0x3b*/
/*1d8 mov al, byte ptr [bx + si]*/
/*1da cmp al, 0*/
/*1dc je 0x1e1*/
/*1de call 0x33b*/
/*1e1 mov bx, 0x8e8a*/
/*1e4 mov si, word ptr [0]*/
/*1e8 mov al, byte ptr [bx + si]*/
/*1ea cmp al, 0*/
/*1ec je 0x1f6*/
/*1ee mov word ptr [0], 1*/
/*1f4 jmp 0x20e*/
/*1f6 mov si, word ptr [0]*/
/*1fa mov al, byte ptr [bx + si]*/
/*1fc cmp al, 0*/
/*1fe je 0x208*/
/*200 mov word ptr [0], 2*/
/*206 jmp 0x20e*/
/*208 mov word ptr [0], 0*/
/*20e mov si, word ptr [0]*/
/*212 mov al, byte ptr [bx + si]*/
/*214 cmp al, 0*/
/*216 je 0x21f*/
/*218 or word ptr [0], 4*/
/*21d jmp 0x22e*/
/*21f mov si, word ptr [0]*/
/*223 mov al, byte ptr [bx + si]*/
/*225 cmp al, 0*/
/*227 je 0x22e*/
/*229 or word ptr [0], 8*/
/*22e mov si, word ptr [0]*/
/*232 mov al, byte ptr [bx + si]*/
/*234 cmp al, 0*/
/*236 je 0x23e*/
/*238 or word ptr [0], 0x80*/
/*23e mov si, word ptr [0]*/
/*242 mov al, byte ptr [bx + si]*/
/*244 cmp al, 0*/
/*246 je 0x24d*/
/*248 or word ptr [0], 0x40*/
/*24d mov si, word ptr [0]*/
/*251 mov al, byte ptr [bx + si]*/
/*253 cmp al, 0*/
/*255 je 0x25c*/
/*257 or word ptr [0], 0x20*/
/*25c mov si, word ptr [0]*/
/*260 mov al, byte ptr [bx + si]*/
/*262 cmp al, 0*/
/*264 je 0x28c*/
/*266 call 0x2c45*/
/*269 mov bx, 0x8e8a*/
/*26c mov al, byte ptr [bx + 0x15]*/
/*26f cmp al, 0*/
/*271 jne 0x27c*/
/*273 mov al, byte ptr [bx + 0x31]*/
/*276 cmp al, 0*/
/*278 jne 0x27c*/
/*27a jmp 0x26c*/
/*27c mov bx, 0x8e8a*/
/*27f mov al, byte ptr [bx + 0x15]*/
/*282 cmp al, 0*/
/*284 je 0x289*/
/*286 jmp 0x96*/
/*289 call 0x529*/
/*28c mov bx, 0x8e8a*/
/*28f mov si, 0x3c*/
/*292 mov al, byte ptr [bx + si]*/
/*294 cmp al, 0*/
/*296 je 0x2c5*/
/*298 mov al, byte ptr [0x9505]*/
/*29b cmp al, 0*/
/*29d jne 0x2b0*/
/*29f mov al, 0xe*/
/*2a1 call 0x3840*/
/*2a4 mov byte ptr [0], 1*/
/*2a9 mov byte ptr [0], 0*/
/*2ae jmp 0x2c3*/
/*2b0 cmp al, 2*/
/*2b2 jne 0x2c3*/
/*2b4 mov byte ptr [0], 3*/
/*2b9 mov byte ptr [0], 1*/
/*2be mov al, 0xd*/
/*2c0 call 0x3840*/
/*2c3 jmp 0x2dc*/
/*2c5 mov al, byte ptr [0x9505]*/
/*2c8 cmp al, 1*/
/*2ca jne 0x2d3*/
/*2cc mov byte ptr [0], 2*/
/*2d1 jmp 0x2dc*/
/*2d3 cmp al, 3*/
/*2d5 jne 0x2dc*/
/*2d7 mov byte ptr [0], 0*/
/*2dc mov al, byte ptr [0x8f0a]*/
/*2df cmp al, 0*/
/*2e1 jne 0x2e4*/
/*2e3 ret */
/*2e4 mov ax, 3*/
/*2e7 int 0x33*/
/*2e9 test bx, 1*/
/*2ed je 0x2f5*/
/*2ef or word ptr [0], 0x80*/
/*2f5 test bx, 2*/
/*2f9 je 0x300*/
/*2fb or word ptr [0], 0x20*/
/*300 mov ax, word ptr [0x954c]*/
/*303 and ax, 0xf*/
/*306 je 0x309*/
/*308 ret */
/*309 mov ax, 0xb*/
/*30c int 0x33*/
/*30e cmp cx, -5*/
/*311 jge 0x31a*/
/*313 or word ptr [0], 1*/
/*318 jmp 0x324*/
/*31a cmp cx, 5*/
/*31d jle 0x324*/
/*31f or word ptr [0], 2*/
/*324 cmp dx, -0xa*/
/*327 jge 0x330*/
/*329 or word ptr [0], 4*/
/*32e jmp 0x33a*/
/*330 cmp dx, 0xa*/
/*333 jle 0x33a*/
/*335 or word ptr [0], 8*/
/*33a ret */
void sub_101c0()
{
  goto loc_101c0;
loc_10096:
  sub_139a3();
  sub_105bc();
  sub_104a5();
  ax = 0x0003;
  interrupt(0x10);
  ax = 0x4c00;
  interrupt(0x21);
  stop();
  // gap 279 bytes
loc_101c0:
  bx = 0x8e8a;
  si = 0x003d;
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_101d5;
  si = 0x003e;
loc_101cf:
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_101cf;
loc_101d5:
  si = 0x003b;
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_101e1;
  sub_1033b();
loc_101e1:
  bx = 0x8e8a;
  si = memoryAGet16(ds, 0x8f0d);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_101f6;
  memoryASet16(ds, 0x954c, 0x0001);
  goto loc_1020e;
loc_101f6:
  si = memoryAGet16(ds, 0x8f0f);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_10208;
  memoryASet16(ds, 0x954c, 0x0002);
  goto loc_1020e;
loc_10208:
  memoryASet16(ds, 0x954c, 0x0000);
loc_1020e:
  si = memoryAGet16(ds, 0x8f11);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1021f;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0004);
  goto loc_1022e;
loc_1021f:
  si = memoryAGet16(ds, 0x8f13);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1022e;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0008);
loc_1022e:
  si = memoryAGet16(ds, 0x8f15);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1023e;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0080);
loc_1023e:
  si = memoryAGet16(ds, 0x8f17);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1024d;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0040);
loc_1024d:
  si = memoryAGet16(ds, 0x8f19);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1025c;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0020);
loc_1025c:
  si = memoryAGet16(ds, 0x8f1b);
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_1028c;
  sub_12c45();
  bx = 0x8e8a;
loc_1026c:
  al = memoryAGet(ds, bx + 21);
  
  if (al != 0x00) goto loc_1027c;
  al = memoryAGet(ds, bx + 49);
  
  if (al != 0x00) goto loc_1027c;
  goto loc_1026c;
loc_1027c:
  bx = 0x8e8a;
  al = memoryAGet(ds, bx + 21);
  
  if (al == 0x00) goto loc_10289;
  goto loc_10096;
loc_10289:
  sub_10529();
loc_1028c:
  bx = 0x8e8a;
  si = 0x003c;
  al = memoryAGet(ds, bx + si);
  
  if (al == 0x00) goto loc_102c5;
  al = memoryAGet(ds, 0x9505);
  
  if (al != 0x00) goto loc_102b0;
  al = 0x0e;
  sub_13840();
  memoryASet(ds, 0x9505, 0x01);
  memoryASet(ds, 0x9506, 0x00);
  goto loc_102c3;
loc_102b0:
  
  if (al != 0x02) goto loc_102c3;
  memoryASet(ds, 0x9505, 0x03);
  memoryASet(ds, 0x9506, 0x01);
  al = 0x0d;
  sub_13840();
loc_102c3:
  goto loc_102dc;
loc_102c5:
  al = memoryAGet(ds, 0x9505);
  
  if (al != 0x01) goto loc_102d3;
  memoryASet(ds, 0x9505, 0x02);
  goto loc_102dc;
loc_102d3:
  
  if (al != 0x03) goto loc_102dc;
  memoryASet(ds, 0x9505, 0x00);
loc_102dc:
  al = memoryAGet(ds, 0x8f0a);
  
  if (al != 0x00) goto loc_102e4;
  return;
loc_102e4:
  ax = 0x0003;
  interrupt(0x33);
  
  if (bx & 0x0001) goto loc_102f5;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0080);
loc_102f5:
  
  if (bx & 0x0002) goto loc_10300;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0020);
loc_10300:
  ax = memoryAGet16(ds, 0x954c);
  ax &= 0x000f;
  if (!ax) goto loc_10309;
  return;
loc_10309:
  ax = 0x000b;
  interrupt(0x33);
  
  if ((short)cx >= (short)0xfffb) goto loc_1031a;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0001);
  goto loc_10324;
loc_1031a:
  
  if ((short)cx <= (short)0x0005) goto loc_10324;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0002);
loc_10324:
  
  if ((short)dx >= (short)0xfff6) goto loc_10330;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0004);
  goto loc_1033a;
loc_10330:
  
  if ((short)dx <= (short)0x000a) goto loc_1033a;
  memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0008);
loc_1033a:
  return;
}

/*33b call 0x2c07*/
/*33e mov al, 4*/
/*340 call 0x2c9a*/
/*343 call 0x4f3*/
/*346 mov word ptr [0x8f15], ax*/
/*349 mov al, 0*/
/*34b call 0x2c9a*/
/*34e call 0x4f3*/
/*351 cmp ax, word ptr [0]*/
/*355 je 0x34e*/
/*357 mov word ptr [0x8f0d], ax*/
/*35a mov al, 1*/
/*35c call 0x2c9a*/
/*35f call 0x4f3*/
/*362 cmp ax, word ptr [0]*/
/*366 je 0x35f*/
/*368 cmp ax, word ptr [0]*/
/*36c je 0x35f*/
/*36e mov word ptr [0x8f0f], ax*/
/*371 mov al, 2*/
/*373 call 0x2c9a*/
/*376 call 0x4f3*/
/*379 cmp ax, word ptr [0]*/
/*37d je 0x376*/
/*37f cmp ax, word ptr [0]*/
/*383 je 0x376*/
/*385 cmp ax, word ptr [0]*/
/*389 je 0x376*/
/*38b mov word ptr [0x8f11], ax*/
/*38e mov al, 3*/
/*390 call 0x2c9a*/
/*393 call 0x4f3*/
/*396 cmp ax, word ptr [0]*/
/*39a je 0x393*/
/*39c cmp ax, word ptr [0]*/
/*3a0 je 0x393*/
/*3a2 cmp ax, word ptr [0]*/
/*3a6 je 0x393*/
/*3a8 cmp ax, word ptr [0]*/
/*3ac je 0x393*/
/*3ae mov word ptr [0x8f13], ax*/
/*3b1 mov al, 6*/
/*3b3 call 0x2c9a*/
/*3b6 call 0x4f3*/
/*3b9 cmp ax, word ptr [0]*/
/*3bd je 0x3b6*/
/*3bf cmp ax, word ptr [0]*/
/*3c3 je 0x3b6*/
/*3c5 cmp ax, word ptr [0]*/
/*3c9 je 0x3b6*/
/*3cb cmp ax, word ptr [0]*/
/*3cf je 0x3b6*/
/*3d1 cmp ax, word ptr [0]*/
/*3d5 je 0x3b6*/
/*3d7 mov word ptr [0x8f17], ax*/
/*3da mov al, 7*/
/*3dc call 0x2c9a*/
/*3df call 0x4f3*/
/*3e2 cmp ax, word ptr [0]*/
/*3e6 je 0x3df*/
/*3e8 cmp ax, word ptr [0]*/
/*3ec je 0x3df*/
/*3ee cmp ax, word ptr [0]*/
/*3f2 je 0x3df*/
/*3f4 cmp ax, word ptr [0]*/
/*3f8 je 0x3df*/
/*3fa cmp ax, word ptr [0]*/
/*3fe je 0x3df*/
/*400 cmp ax, word ptr [0]*/
/*404 je 0x3df*/
/*406 mov word ptr [0x8f19], ax*/
/*409 mov al, 5*/
/*40b call 0x2c9a*/
/*40e call 0x4f3*/
/*411 cmp ax, word ptr [0]*/
/*415 je 0x40e*/
/*417 cmp ax, word ptr [0]*/
/*41b je 0x40e*/
/*41d cmp ax, word ptr [0]*/
/*421 je 0x40e*/
/*423 cmp ax, word ptr [0]*/
/*427 je 0x40e*/
/*429 cmp ax, word ptr [0]*/
/*42d je 0x40e*/
/*42f cmp ax, word ptr [0]*/
/*433 je 0x40e*/
/*435 cmp ax, word ptr [0]*/
/*439 je 0x40e*/
/*43b mov word ptr [0x8f1b], ax*/
/*43e call 0x529*/
/*441 ret */
void sub_1033b()
{
  sub_12c07();
  al = 0x04;
  sub_12c9a();
  sub_104f3();
  memoryASet16(ds, 0x8f15, ax);
  al = 0x00;
  sub_12c9a();
loc_1034e:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_1034e;
  memoryASet16(ds, 0x8f0d, ax);
  al = 0x01;
  sub_12c9a();
loc_1035f:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_1035f;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_1035f;
  memoryASet16(ds, 0x8f0f, ax);
  al = 0x02;
  sub_12c9a();
loc_10376:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_10376;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_10376;
  
  if (ax == memoryAGet16(ds, 0x8f0f)) goto loc_10376;
  memoryASet16(ds, 0x8f11, ax);
  al = 0x03;
  sub_12c9a();
loc_10393:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_10393;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_10393;
  
  if (ax == memoryAGet16(ds, 0x8f0f)) goto loc_10393;
  
  if (ax == memoryAGet16(ds, 0x8f11)) goto loc_10393;
  memoryASet16(ds, 0x8f13, ax);
  al = 0x06;
  sub_12c9a();
loc_103b6:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_103b6;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_103b6;
  
  if (ax == memoryAGet16(ds, 0x8f0f)) goto loc_103b6;
  
  if (ax == memoryAGet16(ds, 0x8f11)) goto loc_103b6;
  
  if (ax == memoryAGet16(ds, 0x8f13)) goto loc_103b6;
  memoryASet16(ds, 0x8f17, ax);
  al = 0x07;
  sub_12c9a();
loc_103df:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_103df;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_103df;
  
  if (ax == memoryAGet16(ds, 0x8f0f)) goto loc_103df;
  
  if (ax == memoryAGet16(ds, 0x8f11)) goto loc_103df;
  
  if (ax == memoryAGet16(ds, 0x8f13)) goto loc_103df;
  
  if (ax == memoryAGet16(ds, 0x8f17)) goto loc_103df;
  memoryASet16(ds, 0x8f19, ax);
  al = 0x05;
  sub_12c9a();
loc_1040e:
  sub_104f3();
  
  if (ax == memoryAGet16(ds, 0x8f15)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f0d)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f0f)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f11)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f13)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f17)) goto loc_1040e;
  
  if (ax == memoryAGet16(ds, 0x8f19)) goto loc_1040e;
  memoryASet16(ds, 0x8f1b, ax);
  sub_10529();
  return;
}

/*442 mov word ptr [0], 0*/
/*448 mov word ptr [0], 0x4b*/
/*44e mov word ptr [0], 0x4d*/
/*454 mov word ptr [0], 0x48*/
/*45a mov word ptr [0], 0x50*/
/*460 mov word ptr [0], 0x39*/
/*466 mov word ptr [0], 0x31*/
/*46c mov word ptr [0], 0x32*/
/*472 mov word ptr [0], 0x10*/
/*478 mov ax, ds*/
/*47a mov es, ax*/
/*47c mov ax, 0*/
/*47f mov cx, 0x40*/
/*482 mov di, 0x8e8a*/
/*485 rep stosw word ptr es:[di], ax*/
/*487 mov al, 9*/
/*489 mov ah, 0x35*/
/*48b int 0x21*/
/*48d mov word ptr [0], bx*/
/*491 mov word ptr [0], es*/
/*495 push ds*/
/*496 mov dx, 0x4b7*/
/*499 mov ax, cs*/
/*49b mov ds, ax*/
/*49d mov al, 9*/
/*49f mov ah, 0x25*/
/*4a1 int 0x21*/
/*4a3 pop ds*/
/*4a4 ret */
void sub_10442()
{
  memoryASet16(ds, 0x8f0b, 0x0000);
  memoryASet16(ds, 0x8f0d, 0x004b);
  memoryASet16(ds, 0x8f0f, 0x004d);
  memoryASet16(ds, 0x8f11, 0x0048);
  memoryASet16(ds, 0x8f13, 0x0050);
  memoryASet16(ds, 0x8f15, 0x0039);
  memoryASet16(ds, 0x8f17, 0x0031);
  memoryASet16(ds, 0x8f19, 0x0032);
  memoryASet16(ds, 0x8f1b, 0x0010);
  ax = ds;
  es = ax;
  ax = 0x0000;
  cx = 0x0040;
  di = 0x8e8a;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  al = 0x09;
  ah = 0x35;
  interrupt(0x21);
  memoryASet16(ds, 0x8e84, bx);
  memoryASet16(ds, 0x8e82, es);
  push(ds);
  dx = 0x04b7;
  ax = cs;
  ds = ax;
  al = 0x09;
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
  return;
}

/*4a5 mov dx, word ptr [0]*/
/*4a9 mov ax, word ptr [0x8e82]*/
/*4ac push ds*/
/*4ad mov ds, ax*/
/*4af mov al, 9*/
/*4b1 mov ah, 0x25*/
/*4b3 int 0x21*/
/*4b5 pop ds*/
/*4b6 ret */
void sub_104a5()
{
  dx = memoryAGet16(ds, 0x8e84);
  ax = memoryAGet16(ds, 0x8e82);
  push(ds);
  ds = ax;
  al = 0x09;
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
  return;
}

/*4f3 cld */
/*4f4 mov si, 0x8e8a*/
/*4f7 lodsb al, byte ptr [si]*/
/*4f8 cmp al, 0*/
/*4fa je 0x520*/
/*4fc mov ax, si*/
/*4fe sub ax, 0x8e8b*/
/*501 cmp ax, 0x3b*/
/*504 je 0x520*/
/*506 cmp ax, 0x3c*/
/*509 je 0x520*/
/*50b cmp ax, 0x3d*/
/*50e je 0x520*/
/*510 cmp ax, 0x3e*/
/*513 je 0x520*/
/*515 cmp ax, 0x2a*/
/*518 je 0x520*/
/*51a cmp ax, 0x36*/
/*51d je 0x520*/
/*51f ret */
/*520 cmp si, 0x8f0a*/
/*524 jne 0x4f7*/
/*526 jmp 0x4f4*/
void sub_104f3()
{
  flags.direction = 0;
loc_104f4:
  si = 0x8e8a;
loc_104f7:
  al = lodsb<DS_SI>();
  
  if (al == 0x00) goto loc_10520;
  ax = si;
  ax -= 0x8e8b;
  
  if (ax == 0x003b) goto loc_10520;
  
  if (ax == 0x003c) goto loc_10520;
  
  if (ax == 0x003d) goto loc_10520;
  
  if (ax == 0x003e) goto loc_10520;
  
  if (ax == 0x002a) goto loc_10520;
  
  if (ax == 0x0036) goto loc_10520;
  return;
loc_10520:
  
  if (si != 0x8f0a) goto loc_104f7;
  goto loc_104f4;
}

/*529 mov si, 0x8e8a*/
/*52c mov ah, 0*/
/*52e lodsb al, byte ptr [si]*/
/*52f cmp al, 0*/
/*531 je 0x535*/
/*533 inc ah*/
/*535 cmp si, 0x8f0a*/
/*539 jne 0x52e*/
/*53b cmp ah, 0*/
/*53e jne 0x529*/
/*540 ret */
void sub_10529()
{
loc_10529:
  si = 0x8e8a;
  ah = 0x00;
loc_1052e:
  al = lodsb<DS_SI>();
  
  if (al == 0x00) goto loc_10535;
  ah++;
loc_10535:
  
  if (si != 0x8f0a) goto loc_1052e;
  
  if (ah != 0x00) goto loc_10529;
  return;
}

/*588 mov ax, 0*/
/*58b int 0x33*/
/*58d mov byte ptr [0x8f0a], al*/
/*590 ret */
void sub_10588()
{
  ax = 0x0000;
  interrupt(0x33);
  memoryASet(ds, 0x8f0a, al);
  return;
}

/*591 mov al, 0x1c*/
/*593 mov ah, 0x35*/
/*595 int 0x21*/
/*597 mov word ptr [0], bx*/
/*59b mov word ptr [0], es*/
/*59f push ds*/
/*5a0 mov dx, 0x5ce*/
/*5a3 mov ax, cs*/
/*5a5 mov ds, ax*/
/*5a7 mov al, 0x1c*/
/*5a9 mov ah, 0x25*/
/*5ab int 0x21*/
/*5ad pop ds*/
/*5ae mov al, 0x36*/
/*5b0 out 0x43, al*/
/*5b2 mov ax, 0x4d0e*/
/*5b5 out 0x40, al*/
/*5b7 mov al, ah*/
/*5b9 out 0x40, al*/
/*5bb ret */
void sub_10591()
{
  al = 0x1c;
  ah = 0x35;
  interrupt(0x21);
  memoryASet16(ds, 0x8e88, bx);
  memoryASet16(ds, 0x8e86, es);
  push(ds);
  dx = 0x05ce;
  ax = cs;
  ds = ax;
  al = 0x1c;
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
  al = 0x36;
  out8(0x43, al);
  ax = 0x4d0e;
  out8(0x40, al);
  al = ah;
  out8(0x40, al);
  return;
}

/*5bc mov dx, word ptr [0]*/
/*5c0 mov ax, word ptr [0x8e86]*/
/*5c3 push ds*/
/*5c4 mov ds, ax*/
/*5c6 mov al, 0x1c*/
/*5c8 mov ah, 0x25*/
/*5ca int 0x21*/
/*5cc pop ds*/
/*5cd ret */
void sub_105bc()
{
  dx = memoryAGet16(ds, 0x8e88);
  ax = memoryAGet16(ds, 0x8e86);
  push(ds);
  ds = ax;
  al = 0x1c;
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
  return;
}

/*5ec push ds*/
/*5ed mov dx, 0x5fc*/
/*5f0 mov ax, cs*/
/*5f2 mov ds, ax*/
/*5f4 mov al, 0x24*/
/*5f6 mov ah, 0x25*/
/*5f8 int 0x21*/
/*5fa pop ds*/
/*5fb ret */
void sub_105ec()
{
  push(ds);
  dx = 0x05fc;
  ax = cs;
  ds = ax;
  al = 0x24;
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
  return;
}

/*600 mov dx, 0x1e2*/
/*603 mov ax, word ptr [0x94e8]*/
/*606 call 0x637*/
/*609 mov dx, 0x1ea*/
/*60c mov ax, word ptr [0x94ea]*/
/*60f call 0x637*/
/*612 mov dx, 0x1f2*/
/*615 mov ax, word ptr [0x94ec]*/
/*618 call 0x637*/
/*61b mov dx, 0x1f9*/
/*61e mov ax, word ptr [0x94ee]*/
/*621 call 0x637*/
/*624 mov dx, 0x203*/
/*627 mov ax, word ptr [0x94f0]*/
/*62a call 0x637*/
/*62d mov dx, 0x20b*/
/*630 mov ax, word ptr [0x94f2]*/
/*633 call 0x637*/
/*636 ret */
void sub_10600()
{
  dx = 0x01e2;
  ax = memoryAGet16(ds, 0x94e8);
  sub_10637();
  dx = 0x01ea;
  ax = memoryAGet16(ds, 0x94ea);
  sub_10637();
  dx = 0x01f2;
  ax = memoryAGet16(ds, 0x94ec);
  sub_10637();
  dx = 0x01f9;
  ax = memoryAGet16(ds, 0x94ee);
  sub_10637();
  dx = 0x0203;
  ax = memoryAGet16(ds, 0x94f0);
  sub_10637();
  dx = 0x020b;
  ax = memoryAGet16(ds, 0x94f2);
  sub_10637();
  return;
}

/*637 mov word ptr [0x8f20], ax*/
/*63a mov di, 0*/
/*63d mov cx, 0x7d00*/
/*640 call 0x64d*/
/*643 ret */
void sub_10637()
{
  memoryASet16(ds, 0x8f20, ax);
  di = 0x0000;
  cx = 0x7d00;
  sub_1064d();
  return;
}

/*64d push di*/
/*64e push cx*/
/*64f mov ax, 0x3d00*/
/*652 int 0x21*/
/*654 pop cx*/
/*655 pop dx*/
/*656 jae 0x659*/
/*658 ret */
/*659 mov word ptr [0x8f1e], ax*/
/*65c mov bx, ax*/
/*65e mov ax, word ptr [0x8f20]*/
/*661 push ds*/
/*662 mov ds, ax*/
/*664 mov ax, 0x3f00*/
/*667 int 0x21*/
/*669 pop ds*/
/*66a mov ax, 0x3e00*/
/*66d mov bx, word ptr [0]*/
/*671 int 0x21*/
/*673 ret */
void sub_1064d()
{
  push(di);
  push(cx);
  ax = 0x3d00;
  interrupt(0x21);
  cx = pop();
  dx = pop();
  if (!flags.carry) goto loc_10659;
  return;
loc_10659:
  memoryASet16(ds, 0x8f1e, ax);
  bx = ax;
  ax = memoryAGet16(ds, 0x8f20);
  push(ds);
  ds = ax;
  ax = 0x3f00;
  interrupt(0x21);
  ds = pop();
  ax = 0x3e00;
  bx = memoryAGet16(ds, 0x8f1e);
  interrupt(0x21);
  return;
}

/*b58 mov ax, 0x3a5*/
/*b5b mov es, ax*/
/*b5d mov di, 0x1b8a*/
/*b60 mov al, byte ptr [di]*/
/*b62 test al, 0x80*/
/*b64 jne 0xb78*/
/*b66 test al, 1*/
/*b68 jne 0xb73*/
/*b6a push di*/
/*b6b mov cx, 0x17*/
/*b6e cld */
/*b6f rep movsb byte ptr es:[di], byte ptr [si]*/
/*b71 pop si*/
/*b72 ret */
/*b73 add di, 0x17*/
/*b76 jmp 0xb60*/
/*b78 mov si, 0*/
/*b7b ret */
void sub_10b58()
{
  ax = 0x03a5;
  es = ax;
  di = 0x1b8a;
loc_10b60:
  al = memoryAGet(ds, di);
  
  if (!(al & 0x80)) goto loc_10b78;
  
  if (!(al & 0x01)) goto loc_10b73;
  push(di);
  cx = 0x0017;
  flags.direction = 0;
  for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
  si = pop();
  return;
loc_10b73:
  di += 0x0017;
  goto loc_10b60;
loc_10b78:
  si = 0x0000;
  return;
}

/*b8e mov ax, word ptr [0x94f8]*/
/*b91 mov word ptr [0x942e], ax*/
/*b94 mov word ptr cs:[0xd93], 0x28*/
/*b9b mov word ptr [0], 1*/
/*ba1 mov cx, 7*/
/*ba4 mov si, 0x1b8a*/
/*ba7 mov al, byte ptr [si]*/
/*ba9 test al, 0x80*/
/*bab jne 0xbc2*/
/*bad test al, 1*/
/*baf je 0xbbd*/
/*bb1 cmp cl, byte ptr [si + 2]*/
/*bb4 jne 0xbbd*/
/*bb6 push cx*/
/*bb7 push si*/
/*bb8 call 0xbdc*/
/*bbb pop si*/
/*bbc pop cx*/
/*bbd add si, 0x17*/
/*bc0 jmp 0xba7*/
/*bc2 loop 0xba4*/
/*bc4 ret */
void sub_10b8e()
{
  ax = memoryAGet16(ds, 0x94f8);
  memoryASet16(ds, 0x942e, ax);
  memoryASet16(cs, 0x0d93, 0x0028);
  memoryASet16(ds, 0x9430, 0x0001);
  cx = 0x0007;
loc_10ba4:
  si = 0x1b8a;
loc_10ba7:
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_10bc2;
  
  if (al & 0x01) goto loc_10bbd;
  
  if (cl != memoryAGet(ds, si + 2)) goto loc_10bbd;
  push(cx);
  push(si);
  sub_10bdc();
  si = pop();
  cx = pop();
loc_10bbd:
  si += 0x0017;
  goto loc_10ba7;
loc_10bc2:
  if (--cx) goto loc_10ba4;
  return;
}

/*bdc mov al, byte ptr [si + 0xb]*/
/*bdf cwde */
/*be0 mov bx, word ptr [si + 5]*/
/*be3 sub bx, ax*/
/*be5 push bx*/
/*be6 mov al, byte ptr [si + 3]*/
/*be9 add al, byte ptr [si + 0xc]*/
/*bec cwde */
/*bed neg ax*/
/*bef add ax, word ptr [si + 7]*/
/*bf2 push ax*/
/*bf3 mov al, byte ptr [si + 9]*/
/*bf6 mov ah, 0*/
/*bf8 push ax*/
/*bf9 mov al, byte ptr [si + 0xa]*/
/*bfc mov ah, 0*/
/*bfe push ax*/
/*bff mov bx, word ptr [si + 0xd]*/
/*c02 mov bx, word ptr [bx - 0x6b18]*/
/*c06 mov al, byte ptr [si + 0x11]*/
/*c09 mov byte ptr cs:[0xd95], al*/
/*c0d mov cl, al*/
/*c0f shl cl, 1*/
/*c11 shl cl, 1*/
/*c13 shl cl, 1*/
/*c15 shl cl, 1*/
/*c17 or al, cl*/
/*c19 mov byte ptr cs:[0xd96], al*/
/*c1d mov si, word ptr [si + 0xf]*/
/*c20 call 0xc24*/
/*c23 ret */
void sub_10bdc()
{
  al = memoryAGet(ds, si + 11);
  true ? cbw() : cwde();
  bx = memoryAGet16(ds, si + 5);
  bx -= ax;
  push(bx);
  al = memoryAGet(ds, si + 3);
  al += memoryAGet(ds, si + 12);
  true ? cbw() : cwde();
  ax = -ax;
  ax += memoryAGet16(ds, si + 7);
  push(ax);
  al = memoryAGet(ds, si + 9);
  ah = 0x00;
  push(ax);
  al = memoryAGet(ds, si + 10);
  ah = 0x00;
  push(ax);
  bx = memoryAGet16(ds, si + 13);
  bx = memoryAGet16(ds, bx + 38120);
  al = memoryAGet(ds, si + 17);
  memoryASet(cs, 0x0d95, al);
  cl = al;
  cl <<= 0x01;
  cl <<= 0x01;
  cl <<= 0x01;
  cl <<= 0x01;
  al |= cl;
  memoryASet(cs, 0x0d96, al);
  si = memoryAGet16(ds, si + 15);
  sub_10c24();
  return;
}

/*c24 push bp*/
/*c25 mov bp, sp*/
/*c27 mov ax, word ptr [0x9430]*/
/*c2a cmp ax, 0*/
/*c2d jne 0xc32*/
/*c2f jmp 0xcbc*/
/*c32 mov ax, word ptr [bp + 8]*/
/*c35 sub ax, word ptr [0]*/
/*c39 and ax, 0x3ff*/
/*c3c test ax, 0x200*/
/*c3f je 0xc44*/
/*c41 or ax, 0xfc00*/
/*c44 mov word ptr [bp + 8], ax*/
/*c47 cmp ax, 0*/
/*c4a jge 0xc77*/
/*c4c add word ptr [bp + 4], ax*/
/*c4f jns 0xc54*/
/*c51 jmp 0xd8f*/
/*c54 jne 0xc59*/
/*c56 jmp 0xd8f*/
/*c59 neg ax*/
/*c5b shl ax, 1*/
/*c5d shl ax, 1*/
/*c5f shl ax, 1*/
/*c61 mov cx, ax*/
/*c63 shl ax, 1*/
/*c65 shl ax, 1*/
/*c67 add cx, ax*/
/*c69 shl cx, 1*/
/*c6b shl cx, 1*/
/*c6d add si, cx*/
/*c6f mov ax, 0*/
/*c72 mov word ptr [bp + 8], ax*/
/*c75 jmp 0xc8f*/
/*c77 add ax, word ptr [bp + 4]*/
/*c7a sub ax, 0xa0*/
/*c7d js 0xc8f*/
/*c7f neg ax*/
/*c81 add ax, word ptr [bp + 4]*/
/*c84 cmp ax, 0*/
/*c87 jg 0xc8c*/
/*c89 jmp 0xd8f*/
/*c8c mov word ptr [bp + 4], ax*/
/*c8f mov ax, 0x20*/
/*c92 add word ptr [bp + 0xa], ax*/
/*c95 mov ax, 8*/
/*c98 add word ptr [bp + 8], ax*/
/*c9b mov ax, word ptr [bp + 0xa]*/
/*c9e cmp ax, 0x20*/
/*ca1 jge 0xcab*/
/*ca3 mov ax, 0x20*/
/*ca6 mov word ptr [bp + 0xa], ax*/
/*ca9 jmp 0xcbc*/
/*cab add ax, word ptr [bp + 6]*/
/*cae cmp ax, 0x120*/
/*cb1 jle 0xcbc*/
/*cb3 mov ax, 0x120*/
/*cb6 sub ax, word ptr [bp + 6]*/
/*cb9 mov word ptr [bp + 0xa], ax*/
/*cbc push ds*/
/*cbd push bx*/
/*cbe mov dx, 0x3ce*/
/*cc1 mov ax, 0xa05*/
/*cc4 out dx, ax*/
/*cc5 mov ax, 7*/
/*cc8 out dx, ax*/
/*cc9 mov ax, word ptr [bp + 0xa]*/
/*ccc mov bx, word ptr [bp + 8]*/
/*ccf push cx*/
/*cd0 shl bx, 1*/
/*cd2 shl bx, 1*/
/*cd4 shl bx, 1*/
/*cd6 mov cx, word ptr cs:[0xd93]*/
/*cdb cmp cx, 0x28*/
/*cde jne 0xce4*/
/*ce0 mov di, bx*/
/*ce2 jmp 0xce7*/
/*ce4 mov di, 0*/
/*ce7 shl bx, 1*/
/*ce9 shl bx, 1*/
/*ceb add di, bx*/
/*ced mov cl, al*/
/*cef shr ax, 1*/
/*cf1 shr ax, 1*/
/*cf3 shr ax, 1*/
/*cf5 add di, ax*/
/*cf7 and cl, 7*/
/*cfa mov ax, 0x80*/
/*cfd shr ax, cl*/
/*cff mov ah, al*/
/*d01 mov bx, word ptr [0]*/
/*d05 mov es, bx*/
/*d07 pop cx*/
/*d08 mov cx, word ptr [bp + 6]*/
/*d0b shr cx, 1*/
/*d0d mov al, 8*/
/*d0f pop ds*/
/*d10 mov bx, word ptr [bp + 4]*/
/*d13 push ax*/
/*d14 push bx*/
/*d15 push cx*/
/*d16 push di*/
/*d17 push si*/
/*d18 mov bh, byte ptr cs:[0xd96]*/
/*d1d mov bl, byte ptr [si]*/
/*d1f inc si*/
/*d20 cmp bh, bl*/
/*d22 jne 0xd3a*/
/*d24 shr ah, 1*/
/*d26 jne 0xd2f*/
/*d28 mov ah, 0x40*/
/*d2a inc di*/
/*d2b loop 0xd1d*/
/*d2d jmp 0xd6d*/
/*d2f shr ah, 1*/
/*d31 jne 0xd36*/
/*d33 mov ah, 0x80*/
/*d35 inc di*/
/*d36 loop 0xd1d*/
/*d38 jmp 0xd6d*/
/*d3a mov bh, bl*/
/*d3c shr bl, 1*/
/*d3e shr bl, 1*/
/*d40 shr bl, 1*/
/*d42 shr bl, 1*/
/*d44 cmp bl, byte ptr cs:[0xd95]*/
/*d49 je 0xd4f*/
/*d4b out dx, ax*/
/*d4c and byte ptr es:[di], bl*/
/*d4f shr ah, 1*/
/*d51 jne 0xd56*/
/*d53 mov ah, 0x80*/
/*d55 inc di*/
/*d56 and bh, 0xf*/
/*d59 cmp bh, byte ptr cs:[0xd95]*/
/*d5e je 0xd64*/
/*d60 out dx, ax*/
/*d61 and byte ptr es:[di], bh*/
/*d64 shr ah, 1*/
/*d66 jne 0xd6b*/
/*d68 mov ah, 0x80*/
/*d6a inc di*/
/*d6b loop 0xd18*/
/*d6d pop si*/
/*d6e add si, 0xa0*/
/*d72 pop di*/
/*d73 add di, word ptr cs:[0xd93]*/
/*d78 and di, 0x7fff*/
/*d7c pop cx*/
/*d7d pop bx*/
/*d7e pop ax*/
/*d7f dec bx*/
/*d80 jne 0xd13*/
/*d82 pop ds*/
/*d83 mov ax, 0xff08*/
/*d86 out dx, ax*/
/*d87 mov ax, 5*/
/*d8a out dx, ax*/
/*d8b mov ax, 0xf07*/
/*d8e out dx, ax*/
/*d8f pop bp*/
/*d90 ret 8*/
void sub_10c24()
{
  push(bp);
  bp = sp;
  ax = memoryAGet16(ds, 0x9430);
  
  if (ax != 0x0000) goto loc_10c32;
  goto loc_10cbc;
loc_10c32:
  ax = memoryAGet16(ss, bp + 8 - 2);
  ax -= memoryAGet16(ds, 0x9528);
  ax &= 0x03ff;
  
  if (ax & 0x0200) goto loc_10c44;
  ax |= 0xfc00;
loc_10c44:
  memoryASet16(ss, bp + 8 - 2, ax);
  
  if ((short)ax >= (short)0x0000) goto loc_10c77;
  memoryASet16(ss, bp + 4 - 2, memoryAGet16(ss, bp + 4 - 2) + ax);
  if ((short)memoryAGet16(ss, bp + 4 - 2) >= 0) goto loc_10c54;
  goto loc_10d8f;
loc_10c54:
  if (memoryAGet16(ss, bp + 4 - 2)) goto loc_10c59;
  goto loc_10d8f;
loc_10c59:
  ax = -ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  cx = ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  cx += ax;
  cx <<= 0x0001;
  cx <<= 0x0001;
  si += cx;
  ax = 0x0000;
  memoryASet16(ss, bp + 8 - 2, ax);
  goto loc_10c8f;
loc_10c77:
  ax += memoryAGet16(ss, bp + 4 - 2);
  ax -= 0x00a0;
  if ((short)ax < 0) goto loc_10c8f;
  ax = -ax;
  ax += memoryAGet16(ss, bp + 4 - 2);
  
  if ((short)ax > (short)0x0000) goto loc_10c8c;
  goto loc_10d8f;
loc_10c8c:
  memoryASet16(ss, bp + 4 - 2, ax);
loc_10c8f:
  ax = 0x0020;
  memoryASet16(ss, bp + 10 - 2, memoryAGet16(ss, bp + 10 - 2) + ax);
  ax = 0x0008;
  memoryASet16(ss, bp + 8 - 2, memoryAGet16(ss, bp + 8 - 2) + ax);
  ax = memoryAGet16(ss, bp + 10 - 2);
  
  if ((short)ax >= (short)0x0020) goto loc_10cab;
  ax = 0x0020;
  memoryASet16(ss, bp + 10 - 2, ax);
  goto loc_10cbc;
loc_10cab:
  ax += memoryAGet16(ss, bp + 6 - 2);
  
  if ((short)ax <= (short)0x0120) goto loc_10cbc;
  ax = 0x0120;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  memoryASet16(ss, bp + 10 - 2, ax);
loc_10cbc:
  push(ds);
  push(bx);
  dx = 0x03ce;
  ax = 0x0a05;
  out16(dx, ax);
  ax = 0x0007;
  out16(dx, ax);
  ax = memoryAGet16(ss, bp + 10 - 2);
  bx = memoryAGet16(ss, bp + 8 - 2);
  push(cx);
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  cx = memoryAGet16(cs, 0x0d93);
  
  if (cx != 0x0028) goto loc_10ce4;
  di = bx;
  goto loc_10ce7;
loc_10ce4:
  di = 0x0000;
loc_10ce7:
  bx <<= 0x0001;
  bx <<= 0x0001;
  di += bx;
  cl = al;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  di += ax;
  cl &= 0x07;
  ax = 0x0080;
  ax >>= cl;
  ah = al;
  bx = memoryAGet16(ds, 0x942e);
  es = bx;
  cx = pop();
  cx = memoryAGet16(ss, bp + 6 - 2);
  cx >>= 0x0001;
  al = 0x08;
  ds = pop();
  bx = memoryAGet16(ss, bp + 4 - 2);
loc_10d13:
  push(ax);
  push(bx);
  push(cx);
  push(di);
  push(si);
loc_10d18:
  bh = memoryAGet(cs, 0x0d96);
loc_10d1d:
  bl = memoryAGet(ds, si);
  si++;
  
  if (bh != bl) goto loc_10d3a;
  ah >>= 0x01;
  if (ah) goto loc_10d2f;
  ah = 0x40;
  di++;
  if (--cx) goto loc_10d1d;
  goto loc_10d6d;
loc_10d2f:
  ah >>= 0x01;
  if (ah) goto loc_10d36;
  ah = 0x80;
  di++;
loc_10d36:
  if (--cx) goto loc_10d1d;
  goto loc_10d6d;
loc_10d3a:
  bh = bl;
  bl >>= 0x01;
  bl >>= 0x01;
  bl >>= 0x01;
  bl >>= 0x01;
  
  if (bl == memoryAGet(cs, 0x0d95)) goto loc_10d4f;
  out16(dx, ax);
  memoryASet(es, di, memoryAGet(es, di) & bl);
loc_10d4f:
  ah >>= 0x01;
  if (ah) goto loc_10d56;
  ah = 0x80;
  di++;
loc_10d56:
  bh &= 0x0f;
  
  if (bh == memoryAGet(cs, 0x0d95)) goto loc_10d64;
  out16(dx, ax);
  memoryASet(es, di, memoryAGet(es, di) & bh);
loc_10d64:
  ah >>= 0x01;
  if (ah) goto loc_10d6b;
  ah = 0x80;
  di++;
loc_10d6b:
  if (--cx) goto loc_10d18;
loc_10d6d:
  si = pop();
  si += 0x00a0;
  di = pop();
  di += memoryAGet16(cs, 0x0d93);
  di &= 0x7fff;
  cx = pop();
  bx = pop();
  ax = pop();
  bx--;
  if (bx) goto loc_10d13;
  ds = pop();
  ax = 0xff08;
  out16(dx, ax);
  ax = 0x0005;
  out16(dx, ax);
  ax = 0x0f07;
  out16(dx, ax);
loc_10d8f:
  bp = pop();
  return;
}

/*d98 mov word ptr [0], 0x1a*/
/*d9e mov byte ptr [0], 0*/
/*da3 call 0xb7c*/
/*da6 ret */
void sub_10d98()
{
  memoryASet16(ds, 0x9528, 0x001a);
  memoryASet(ds, 0x9513, 0x00);
  sub_10b7c();
  return;
}

/*b7c mov si, 0x1b8a*/
/*b7f mov al, byte ptr [si]*/
/*b81 test al, 0x80*/
/*b83 jne 0xb8d*/
/*b85 mov byte ptr [si], 0*/
/*b88 add si, 0x17*/
/*b8b jmp 0xb7f*/
/*b8d ret */
void sub_10b7c()
{
  si = 0x1b8a;
loc_10b7f:
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_10b8d;
  memoryASet(ds, si, 0x00);
  si += 0x0017;
  goto loc_10b7f;
loc_10b8d:
  return;
}

/*da7 call 0x9a4*/
/*daa call 0x69a*/
/*dad mov byte ptr [0], 0*/
/*db2 mov byte ptr [0], 0*/
/*db7 mov byte ptr [0], 0*/
/*dbc call 0xe3d*/
/*dbf ret */
void sub_10da7()
{
  sub_109a4();
  sub_1069a();
  memoryASet(ds, 0x9519, 0x00);
  memoryASet(ds, 0x951a, 0x00);
  memoryASet(ds, 0x951b, 0x00);
  sub_10e3d();
  return;
}

/*69a mov al, byte ptr [0x9501]*/
/*69d mov bl, al*/
/*69f shl bl, 1*/
/*6a1 add bl, al*/
/*6a3 add bl, byte ptr [0]*/
/*6a7 mov bh, 0*/
/*6a9 shl bx, 1*/
/*6ab mov si, word ptr [bx + 0x244]*/
/*6af mov di, 0x9229*/
/*6b2 mov cx, 0x40*/
/*6b5 mov ax, ds*/
/*6b7 mov es, ax*/
/*6b9 mov ax, 0*/
/*6bc cld */
/*6bd rep stosw word ptr es:[di], ax*/
/*6bf mov di, 0x9229*/
/*6c2 lodsb al, byte ptr [si]*/
/*6c3 cmp al, 0xff*/
/*6c5 je 0x6eb*/
/*6c7 shl al, 1*/
/*6c9 shl al, 1*/
/*6cb mov ah, al*/
/*6cd lodsb al, byte ptr [si]*/
/*6ce shl al, 1*/
/*6d0 mov bl, al*/
/*6d2 mov bh, 0*/
/*6d4 mov al, 0*/
/*6d6 or ax, word ptr [bx + 0xcd7]*/
/*6da mov cx, ax*/
/*6dc lodsb al, byte ptr [si]*/
/*6dd neg al*/
/*6df add al, 0x3f*/
/*6e1 shl al, 1*/
/*6e3 mov bl, al*/
/*6e5 or word ptr [bx - 0x6dd7], cx*/
/*6e9 jmp 0x6c2*/
/*6eb mov al, byte ptr [0x9501]*/
/*6ee mov bl, al*/
/*6f0 shl bl, 1*/
/*6f2 add bl, al*/
/*6f4 add bl, byte ptr [0]*/
/*6f8 mov bh, 0*/
/*6fa shl bx, 1*/
/*6fc mov si, word ptr [bx + 0x214]*/
/*700 mov di, 0x8f29*/
/*703 mov cx, 0x300*/
/*706 mov bl, 0*/
/*708 dec bl*/
/*70a jns 0x72c*/
/*70c lodsb al, byte ptr [si]*/
/*70d mov dl, al*/
/*70f and dl, 0x3f*/
/*712 and al, 0xc0*/
/*714 jne 0x71a*/
/*716 mov bl, 0*/
/*718 jmp 0x72c*/
/*71a cmp al, 0x40*/
/*71c jne 0x722*/
/*71e mov bl, 1*/
/*720 jmp 0x72c*/
/*722 cmp al, 0x80*/
/*724 jne 0x72a*/
/*726 mov bl, 2*/
/*728 jmp 0x72c*/
/*72a mov bl, 3*/
/*72c mov byte ptr [di], dl*/
/*72e inc di*/
/*72f loop 0x708*/
/*731 mov di, 0*/
/*734 mov ax, 0xa800*/
/*737 mov es, ax*/
/*739 mov dx, 0x3ce*/
/*73c mov ah, 0*/
/*73e mov al, 0*/
/*740 out dx, ax*/
/*741 mov ax, 0xf01*/
/*744 out dx, ax*/
/*745 mov cx, 0x4000*/
/*748 rep stosw word ptr es:[di], ax*/
/*74a mov ax, 0x8f29*/
/*74d mov word ptr [0x8f25], ax*/
/*750 mov word ptr [0], 0x3f0*/
/*756 mov cx, 0x40*/
/*759 push cx*/
/*75a mov byte ptr [0], 0*/
/*75f call 0x7af*/
/*762 mov word ptr [0x279], 0*/
/*768 mov byte ptr [0x27d], 8*/
/*76d add word ptr [0x283], 8*/
/*772 mov si, 0x274*/
/*775 call 0xbc5*/
/*778 mov word ptr [0x279], 8*/
/*77e mov byte ptr [0x27d], 0x18*/
/*783 mov cx, 0xa*/
/*786 push cx*/
/*787 call 0x7af*/
/*78a mov si, 0x274*/
/*78d call 0xbc5*/
/*790 add word ptr [0x279], 0x18*/
/*795 pop cx*/
/*796 loop 0x786*/
/*798 mov byte ptr [0x27d], 8*/
/*79d call 0x7af*/
/*7a0 mov si, 0x274*/
/*7a3 call 0xbc5*/
/*7a6 sub word ptr [0], 0x10*/
/*7ab pop cx*/
/*7ac loop 0x759*/
/*7ae ret */
void sub_1069a()
{
  al = memoryAGet(ds, 0x9501);
  bl = al;
  bl <<= 0x01;
  bl += al;
  bl += memoryAGet(ds, 0x9502);
  bh = 0x00;
  bx <<= 0x0001;
  si = memoryAGet16(ds, bx + 580);
  di = 0x9229;
  cx = 0x0040;
  ax = ds;
  es = ax;
  ax = 0x0000;
  flags.direction = 0;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  di = 0x9229;
loc_106c2:
  al = lodsb<DS_SI>();
  
  if (al == 0xff) goto loc_106eb;
  al <<= 0x01;
  al <<= 0x01;
  ah = al;
  al = lodsb<DS_SI>();
  al <<= 0x01;
  bl = al;
  bh = 0x00;
  al = 0x00;
  ax |= memoryAGet16(ds, bx + 3287);
  cx = ax;
  al = lodsb<DS_SI>();
  al = -al;
  al += 0x3f;
  al <<= 0x01;
  bl = al;
  memoryASet16(ds, bx + 37417, memoryAGet16(ds, bx + 37417) | cx);
  goto loc_106c2;
loc_106eb:
  al = memoryAGet(ds, 0x9501);
  bl = al;
  bl <<= 0x01;
  bl += al;
  bl += memoryAGet(ds, 0x9502);
  bh = 0x00;
  bx <<= 0x0001;
  si = memoryAGet16(ds, bx + 532);
  di = 0x8f29;
  cx = 0x0300;
  bl = 0x00;
loc_10708:
  bl--;
  if ((char)bl >= 0) goto loc_1072c;
  al = lodsb<DS_SI>();
  dl = al;
  dl &= 0x3f;
  al &= 0xc0;
  if (al) goto loc_1071a;
  bl = 0x00;
  goto loc_1072c;
loc_1071a:
  
  if (al != 0x40) goto loc_10722;
  bl = 0x01;
  goto loc_1072c;
loc_10722:
  
  if (al != 0x80) goto loc_1072a;
  bl = 0x02;
  goto loc_1072c;
loc_1072a:
  bl = 0x03;
loc_1072c:
  memoryASet(ds, di, dl);
  di++;
  if (--cx) goto loc_10708;
  di = 0x0000;
  ax = 0xa800;
  es = ax;
  dx = 0x03ce;
  ah = 0x00;
  al = 0x00;
  out16(dx, ax);
  ax = 0x0f01;
  out16(dx, ax);
  cx = 0x4000;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  ax = 0x8f29;
  memoryASet16(ds, 0x8f25, ax);
  memoryASet16(ds, 0x8f23, 0x03f0);
  cx = 0x0040;
loc_10759:
  push(cx);
  memoryASet(ds, 0x8f22, 0x00);
  sub_107af();
  memoryASet16(ds, 0x0279, 0x0000);
  memoryASet(ds, 0x027d, 0x08);
  memoryASet16(ds, 0x0283, memoryAGet16(ds, 0x0283) + 0x0008);
  si = 0x0274;
  sub_10bc5();
  memoryASet16(ds, 0x0279, 0x0008);
  memoryASet(ds, 0x027d, 0x18);
  cx = 0x000a;
loc_10786:
  push(cx);
  sub_107af();
  si = 0x0274;
  sub_10bc5();
  memoryASet16(ds, 0x0279, memoryAGet16(ds, 0x0279) + 0x0018);
  cx = pop();
  if (--cx) goto loc_10786;
  memoryASet(ds, 0x027d, 0x08);
  sub_107af();
  si = 0x0274;
  sub_10bc5();
  memoryASet16(ds, 0x8f23, memoryAGet16(ds, 0x8f23) - 0x0010);
  cx = pop();
  if (--cx) goto loc_10759;
  return;
}

/*7af mov al, byte ptr [0x8f22]*/
/*7b2 mov byte ptr [0x277], al*/
/*7b5 mov bx, word ptr [0]*/
/*7b9 mov al, byte ptr [bx]*/
/*7bb inc bx*/
/*7bc mov word ptr [0], bx*/
/*7c0 mov bh, 0*/
/*7c2 mov bl, al*/
/*7c4 mov al, byte ptr [bx + 0x51d]*/
/*7c8 mov byte ptr [0x27e], al*/
/*7cb mov al, byte ptr [bx + 0x571]*/
/*7cf add byte ptr [0], al*/
/*7d3 mov al, byte ptr [bx + 0x547]*/
/*7d7 cwde */
/*7d8 add ax, word ptr [0]*/
/*7dc mov word ptr [0x27b], ax*/
/*7df cmp bx, 0x26*/
/*7e2 jb 0x7ec*/
/*7e4 mov word ptr [0x281], 2*/
/*7ea jmp 0x7f2*/
/*7ec mov word ptr [0x281], 4*/
/*7f2 shl bx, 1*/
/*7f4 mov bx, word ptr [bx + 0x5ef]*/
/*7f8 mov word ptr [0x283], bx*/
/*7fc ret */
void sub_107af()
{
  al = memoryAGet(ds, 0x8f22);
  memoryASet(ds, 0x0277, al);
  bx = memoryAGet16(ds, 0x8f25);
  al = memoryAGet(ds, bx);
  bx++;
  memoryASet16(ds, 0x8f25, bx);
  bh = 0x00;
  bl = al;
  al = memoryAGet(ds, bx + 1309);
  memoryASet(ds, 0x027e, al);
  al = memoryAGet(ds, bx + 1393);
  memoryASet(ds, 0x8f22, memoryAGet(ds, 0x8f22) + al);
  al = memoryAGet(ds, bx + 1351);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, 0x8f23);
  memoryASet16(ds, 0x027b, ax);
  
  if (bx < 0x0026) goto loc_107ec;
  memoryASet16(ds, 0x0281, 0x0002);
  goto loc_107f2;
loc_107ec:
  memoryASet16(ds, 0x0281, 0x0004);
loc_107f2:
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 1519);
  memoryASet16(ds, 0x0283, bx);
  return;
}

/*9a4 mov di, 0x92a9*/
/*9a7 mov cx, 0xc0*/
/*9aa mov ax, ds*/
/*9ac mov es, ax*/
/*9ae mov ax, 0xffff*/
/*9b1 cld */
/*9b2 rep stosw word ptr es:[di], ax*/
/*9b4 ret */
void sub_109a4()
{
  di = 0x92a9;
  cx = 0x00c0;
  ax = ds;
  es = ax;
  ax = 0xffff;
  flags.direction = 0;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  return;
}

/*bc5 mov ax, 0xa800*/
/*bc8 mov word ptr [0x942e], ax*/
/*bcb mov word ptr cs:[0xd93], 0x20*/
/*bd2 mov word ptr [0], 0*/
/*bd8 call 0xbdc*/
/*bdb ret */
void sub_10bc5()
{
  ax = 0xa800;
  memoryASet16(ds, 0x942e, ax);
  memoryASet16(cs, 0x0d93, 0x0020);
  memoryASet16(ds, 0x9430, 0x0000);
  sub_10bdc();
  return;
}

/*e3d mov bl, byte ptr [0]*/
/*e41 mov bh, 0*/
/*e43 shl bx, 1*/
/*e45 mov ax, word ptr [bx + 0x14f5]*/
/*e49 and ax, 0x3ff*/
/*e4c mov word ptr [0x9528], ax*/
/*e4f mov ax, word ptr [0x94fc]*/
/*e52 mov word ptr [0x952a], ax*/
/*e55 mov word ptr [0], 0x80*/
/*e5b mov byte ptr [0], 0*/
/*e60 mov word ptr [0], 0*/
/*e66 mov word ptr [0], 0*/
/*e6c mov byte ptr [0], 0*/
/*e71 mov byte ptr [0], 0*/
/*e76 mov byte ptr [0], 0*/
/*e7b mov byte ptr [0], 0*/
/*e80 call 0xe84*/
/*e83 ret */
void sub_10e3d()
{
  bl = memoryAGet(ds, 0x9501);
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5365);
  ax &= 0x03ff;
  memoryASet16(ds, 0x9528, ax);
  ax = memoryAGet16(ds, 0x94fc);
  memoryASet16(ds, 0x952a, ax);
  memoryASet16(ds, 0x950a, 0x0080);
  memoryASet(ds, 0x950e, 0x00);
  memoryASet16(ds, 0x950f, 0x0000);
  memoryASet16(ds, 0x9511, 0x0000);
  memoryASet(ds, 0x9513, 0x00);
  memoryASet(ds, 0x9515, 0x00);
  memoryASet(ds, 0x9517, 0x00);
  memoryASet(ds, 0x9432, 0x00);
  sub_10e84();
  return;
}

/*e84 mov al, byte ptr [0x950e]*/
/*e87 cmp al, 0*/
/*e89 je 0xe93*/
/*e8b mov byte ptr [0], 0*/
/*e90 call 0x69a*/
/*e93 mov word ptr [0], 0*/
/*e99 call 0xb7c*/
/*e9c mov si, 0xd32*/
/*e9f call 0xb58*/
/*ea2 mov ax, word ptr [0x950a]*/
/*ea5 mov word ptr [0x1b8f], ax*/
/*ea8 call 0x1b57*/
/*eab mov ax, word ptr [0x9528]*/
/*eae shr ax, 1*/
/*eb0 shr ax, 1*/
/*eb2 shr ax, 1*/
/*eb4 shr ax, 1*/
/*eb6 sub ax, 3*/
/*eb9 and ax, 0x3f*/
/*ebc mov word ptr [0x9507], ax*/
/*ebf mov cx, 0xf*/
/*ec2 push cx*/
/*ec3 push ax*/
/*ec4 push ax*/
/*ec5 call 0x8ba*/
/*ec8 pop ax*/
/*ec9 pop cx*/
/*eca inc ax*/
/*ecb and ax, 0x3f*/
/*ece loop 0xec2*/
/*ed0 mov al, byte ptr [0x9432]*/
/*ed3 cmp al, 0*/
/*ed5 je 0xeea*/
/*ed7 mov si, 0x1b8a*/
/*eda mov bx, 0xd49*/
/*edd mov byte ptr [si + 4], 0xa*/
/*ee1 call 0x2121*/
/*ee4 mov byte ptr [0x1b9c], 0x23*/
/*ee9 ret */
/*eea mov al, byte ptr [0x9519]*/
/*eed cmp al, 0*/
/*eef je 0xf08*/
/*ef1 mov byte ptr [0], 0*/
/*ef6 mov si, 0xda2*/
/*ef9 mov ax, word ptr [0x1b91]*/
/*efc mov word ptr [si + 7], ax*/
/*eff mov al, byte ptr [0x1b8d]*/
/*f02 mov byte ptr [si + 3], al*/
/*f05 call 0xb58*/
/*f08 call 0xf9d*/
/*f0b mov al, byte ptr [0x951a]*/
/*f0e cmp al, 0*/
/*f10 je 0xf23*/
/*f12 mov byte ptr [0], 1*/
/*f17 mov si, 0xdc3*/
/*f1a and byte ptr [si], 0xdf*/
/*f1d call 0x1cd9*/
/*f20 call 0xb58*/
/*f23 mov al, byte ptr [0x951b]*/
/*f26 cmp al, 0*/
/*f28 je 0xf3b*/
/*f2a mov byte ptr [0], 1*/
/*f2f mov si, 0xdc3*/
/*f32 or byte ptr [si], 0x20*/
/*f35 call 0x1cd9*/
/*f38 call 0xb58*/
/*f3b ret */
void sub_10e84()
{
  al = memoryAGet(ds, 0x950e);
  
  if (al == 0x00) goto loc_10e93;
  memoryASet(ds, 0x950e, 0x00);
  sub_1069a();
loc_10e93:
  memoryASet16(ds, 0x952c, 0x0000);
  sub_10b7c();
  si = 0x0d32;
  sub_10b58();
  ax = memoryAGet16(ds, 0x950a);
  memoryASet16(ds, 0x1b8f, ax);
  sub_11b57();
  ax = memoryAGet16(ds, 0x9528);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax -= 0x0003;
  ax &= 0x003f;
  memoryASet16(ds, 0x9507, ax);
  cx = 0x000f;
loc_10ec2:
  push(cx);
  push(ax);
  push(ax);
  sub_108ba();
  ax = pop();
  cx = pop();
  ax++;
  ax &= 0x003f;
  if (--cx) goto loc_10ec2;
  al = memoryAGet(ds, 0x9432);
  
  if (al == 0x00) goto loc_10eea;
  si = 0x1b8a;
  bx = 0x0d49;
  memoryASet(ds, si + 4, 0x0a);
  sub_12121();
  memoryASet(ds, 0x1b9c, 0x23);
  return;
loc_10eea:
  al = memoryAGet(ds, 0x9519);
  
  if (al == 0x00) goto loc_10f08;
  memoryASet(ds, 0x9519, 0x00);
  si = 0x0da2;
  ax = memoryAGet16(ds, 0x1b91);
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x1b8d);
  memoryASet(ds, si + 3, al);
  sub_10b58();
loc_10f08:
  sub_10f9d();
  al = memoryAGet(ds, 0x951a);
  
  if (al == 0x00) goto loc_10f23;
  memoryASet(ds, 0x951a, 0x01);
  si = 0x0dc3;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
  sub_11cd9();
  sub_10b58();
loc_10f23:
  al = memoryAGet(ds, 0x951b);
  
  if (al == 0x00) goto loc_10f3b;
  memoryASet(ds, 0x951b, 0x01);
  si = 0x0dc3;
  memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
  sub_11cd9();
  sub_10b58();
loc_10f3b:
  return;
}

/*8ba push bp*/
/*8bb mov bp, sp*/
/*8bd mov bx, word ptr [bp + 4]*/
/*8c0 shl bx, 1*/
/*8c2 mov ax, word ptr [bx - 0x6dd7]*/
/*8c6 cmp ax, 0*/
/*8c9 je 0x946*/
/*8cb push ax*/
/*8cc shr ah, 1*/
/*8ce shr ah, 1*/
/*8d0 mov bl, ah*/
/*8d2 mov bh, 0*/
/*8d4 shl bx, 1*/
/*8d6 mov si, word ptr [bx + 0x28b]*/
/*8da cmp ah, 0xf*/
/*8dd jb 0x902*/
/*8df cmp ah, 0x14*/
/*8e2 ja 0x902*/
/*8e4 sub ah, 0xf*/
/*8e7 mov byte ptr [si + 1], ah*/
/*8ea mov bl, ah*/
/*8ec mov bh, 0*/
/*8ee mov al, byte ptr [bx - 0x6ad2]*/
/*8f2 cmp al, 0*/
/*8f4 je 0x8f9*/
/*8f6 pop ax*/
/*8f7 jmp 0x946*/
/*8f9 shl bx, 1*/
/*8fb mov ax, word ptr [bx + 0x32e]*/
/*8ff mov word ptr [si + 0xf], ax*/
/*902 mov byte ptr [si + 0x13], 0xa*/
/*906 mov ax, word ptr [bp + 4]*/
/*909 mov byte ptr [si + 0x14], al*/
/*90c pop ax*/
/*90d mov cx, 0xa*/
/*910 shr ax, 1*/
/*912 jae 0x941*/
/*914 push ax*/
/*915 push cx*/
/*916 call 0x94a*/
/*919 mov al, byte ptr [si + 0x13]*/
/*91c mov ah, 0*/
/*91e push ax*/
/*91f mov ax, word ptr [bp + 4]*/
/*922 push ax*/
/*923 call 0x9e9*/
/*926 cmp ax, 0*/
/*929 je 0x932*/
/*92b push si*/
/*92c call 0xb58*/
/*92f pop si*/
/*930 jmp 0x93f*/
/*932 push si*/
/*933 call 0xb58*/
/*936 cmp si, 0*/
/*939 je 0x93e*/
/*93b call 0xa1b*/
/*93e pop si*/
/*93f pop cx*/
/*940 pop ax*/
/*941 dec byte ptr [si + 0x13]*/
/*944 loop 0x910*/
/*946 pop bp*/
/*947 ret 2*/
void sub_108ba()
{
  bool temp_cf;

  push(bp);
  bp = sp;
  bx = memoryAGet16(ss, bp + 4 - 2);
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 37417);
  
  if (ax == 0x0000) goto loc_10946;
  push(ax);
  ah >>= 0x01;
  ah >>= 0x01;
  bl = ah;
  bh = 0x00;
  bx <<= 0x0001;
  si = memoryAGet16(ds, bx + 651);
  
  if (ah < 0x0f) goto loc_10902;
  
  if (ah > 0x14) goto loc_10902;
  ah -= 0x0f;
  memoryASet(ds, si + 1, ah);
  bl = ah;
  bh = 0x00;
  al = memoryAGet(ds, bx + 38190);
  
  if (al == 0x00) goto loc_108f9;
  ax = pop();
  goto loc_10946;
loc_108f9:
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 814);
  memoryASet16(ds, si + 15, ax);
loc_10902:
  memoryASet(ds, si + 19, 0x0a);
  ax = memoryAGet16(ss, bp + 4 - 2);
  memoryASet(ds, si + 20, al);
  ax = pop();
  cx = 0x000a;
loc_10910:
  temp_cf = ax & 1;
  ax >>= 0x0001;
  if (!temp_cf) goto loc_10941;
  push(ax);
  push(cx);
  sub_1094a();
  al = memoryAGet(ds, si + 19);
  ah = 0x00;
  push(ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  sub_109e9();
  
  if (ax == 0x0000) goto loc_10932;
  push(si);
  sub_10b58();
  si = pop();
  goto loc_1093f;
loc_10932:
  push(si);
  sub_10b58();
  
  if (si == 0x0000) goto loc_1093e;
  sub_10a1b();
loc_1093e:
  si = pop();
loc_1093f:
  cx = pop();
  ax = pop();
loc_10941:
  memoryASet(ds, si + 19, memoryAGet(ds, si + 19) - 1);
  if (--cx) goto loc_10910;
loc_10946:
  bp = pop();
  return;
}

/*94a mov dl, byte ptr [si + 0x13]*/
/*94d push si*/
/*94e mov al, 0x3f*/
/*950 sub al, byte ptr [si + 0x14]*/
/*953 shl al, 1*/
/*955 shl al, 1*/
/*957 mov ah, 0*/
/*959 mov si, ax*/
/*95b shl ax, 1*/
/*95d add si, ax*/
/*95f add si, 0x8f29*/
/*963 mov cl, 0*/
/*965 cld */
/*966 cmp dl, 0*/
/*969 je 0x978*/
/*96b lodsb al, byte ptr [si]*/
/*96c mov bh, 0*/
/*96e mov bl, al*/
/*970 add cl, byte ptr [bx + 0x571]*/
/*974 dec dl*/
/*976 jmp 0x966*/
/*978 pop si*/
/*979 mov byte ptr [si + 3], cl*/
/*97c mov al, byte ptr [si + 0x14]*/
/*97f mov ah, 0*/
/*981 shl ax, 1*/
/*983 shl ax, 1*/
/*985 shl ax, 1*/
/*987 shl ax, 1*/
/*989 mov word ptr [si + 7], ax*/
/*98c mov al, byte ptr [si + 0x13]*/
/*98f mov ah, 0*/
/*991 shl ax, 1*/
/*993 mov cx, ax*/
/*995 shl ax, 1*/
/*997 add ax, cx*/
/*999 shl ax, 1*/
/*99b shl ax, 1*/
/*99d sub ax, 4*/
/*9a0 mov word ptr [si + 5], ax*/
/*9a3 ret */
void sub_1094a()
{
  dl = memoryAGet(ds, si + 19);
  push(si);
  al = 0x3f;
  al -= memoryAGet(ds, si + 20);
  al <<= 0x01;
  al <<= 0x01;
  ah = 0x00;
  si = ax;
  ax <<= 0x0001;
  si += ax;
  si += 0x8f29;
  cl = 0x00;
  flags.direction = 0;
loc_10966:
  
  if (dl == 0x00) goto loc_10978;
  al = lodsb<DS_SI>();
  bh = 0x00;
  bl = al;
  cl += memoryAGet(ds, bx + 1393);
  dl--;
  goto loc_10966;
loc_10978:
  si = pop();
  memoryASet(ds, si + 3, cl);
  al = memoryAGet(ds, si + 20);
  ah = 0x00;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, si + 19);
  ah = 0x00;
  ax <<= 0x0001;
  cx = ax;
  ax <<= 0x0001;
  ax += cx;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax -= 0x0004;
  memoryASet16(ds, si + 5, ax);
  return;
}

/*9e9 push bp*/
/*9ea mov bp, sp*/
/*9ec mov bx, word ptr [bp + 6]*/
/*9ef shl bx, 1*/
/*9f1 mov cx, word ptr [bx + 0xceb]*/
/*9f5 mov bx, word ptr [bp + 4]*/
/*9f8 shl bx, 1*/
/*9fa mov al, byte ptr [0x9502]*/
/*9fd cmp al, 1*/
/*9ff jne 0xa07*/
/*a01 add bx, 0x80*/
/*a05 jmp 0xa0f*/
/*a07 cmp al, 2*/
/*a09 jne 0xa0f*/
/*a0b add bx, 0x100*/
/*a0f not cx*/
/*a11 mov ax, word ptr [bx - 0x6d57]*/
/*a15 and ax, cx*/
/*a17 pop bp*/
/*a18 ret 4*/
void sub_109e9()
{
  push(bp);
  bp = sp;
  bx = memoryAGet16(ss, bp + 6 - 2);
  bx <<= 0x0001;
  cx = memoryAGet16(ds, bx + 3307);
  bx = memoryAGet16(ss, bp + 4 - 2);
  bx <<= 0x0001;
  al = memoryAGet(ds, 0x9502);
  
  if (al != 0x01) goto loc_10a07;
  bx += 0x0080;
  goto loc_10a0f;
loc_10a07:
  
  if (al != 0x02) goto loc_10a0f;
  bx += 0x0100;
loc_10a0f:
  cx = ~cx;
  ax = memoryAGet16(ds, bx + 37545);
  ax &= cx;
  bp = pop();
  return;
}

/*a1b mov al, byte ptr [si + 0x12]*/
/*a1e shl al, 1*/
/*a20 mov bl, al*/
/*a22 mov bh, 0*/
/*a24 mov di, word ptr [bx + 0x31e]*/
/*a28 mov al, byte ptr [di]*/
/*a2a mov byte ptr [si], al*/
/*a2c mov al, byte ptr [di + 9]*/
/*a2f mov byte ptr [si + 9], al*/
/*a32 mov al, byte ptr [di + 0xa]*/
/*a35 mov byte ptr [si + 0xa], al*/
/*a38 mov al, byte ptr [di + 0xb]*/
/*a3b mov byte ptr [si + 0xb], al*/
/*a3e mov al, byte ptr [di + 0xc]*/
/*a41 mov byte ptr [si + 0xc], al*/
/*a44 mov ax, word ptr [di + 0xf]*/
/*a47 mov word ptr [si + 0xf], ax*/
/*a4a mov al, byte ptr [di + 0x12]*/
/*a4d mov byte ptr [si + 0x12], al*/
/*a50 ret */
void sub_10a1b()
{
  al = memoryAGet(ds, si + 18);
  al <<= 0x01;
  bl = al;
  bh = 0x00;
  di = memoryAGet16(ds, bx + 798);
  al = memoryAGet(ds, di);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, di + 9);
  memoryASet(ds, si + 9, al);
  al = memoryAGet(ds, di + 10);
  memoryASet(ds, si + 10, al);
  al = memoryAGet(ds, di + 11);
  memoryASet(ds, si + 11, al);
  al = memoryAGet(ds, di + 12);
  memoryASet(ds, si + 12, al);
  ax = memoryAGet16(ds, di + 15);
  memoryASet16(ds, si + 15, ax);
  al = memoryAGet(ds, di + 18);
  memoryASet(ds, si + 18, al);
  return;
}

/*f9d mov ax, word ptr [0x1b8f]*/
/*fa0 mov word ptr [0x9433], ax*/
/*fa3 mov word ptr [0x9435], ax*/
/*fa6 mov word ptr [0x9437], ax*/
/*fa9 mov word ptr [0x9439], ax*/
/*fac mov ax, word ptr [0x1b91]*/
/*faf mov word ptr [0x943b], ax*/
/*fb2 mov word ptr [0x943d], ax*/
/*fb5 mov word ptr [0x943f], ax*/
/*fb8 mov word ptr [0x9441], ax*/
/*fbb mov al, byte ptr [0x1b8e]*/
/*fbe mov byte ptr [0x9443], al*/
/*fc1 mov byte ptr [0x9444], al*/
/*fc4 mov byte ptr [0x9445], al*/
/*fc7 mov byte ptr [0x9446], al*/
/*fca mov al, byte ptr [0x1b8d]*/
/*fcd mov byte ptr [0x9447], al*/
/*fd0 mov byte ptr [0x9448], al*/
/*fd3 mov byte ptr [0x9449], al*/
/*fd6 mov byte ptr [0x944a], al*/
/*fd9 ret */
void sub_10f9d()
{
  ax = memoryAGet16(ds, 0x1b8f);
  memoryASet16(ds, 0x9433, ax);
  memoryASet16(ds, 0x9435, ax);
  memoryASet16(ds, 0x9437, ax);
  memoryASet16(ds, 0x9439, ax);
  ax = memoryAGet16(ds, 0x1b91);
  memoryASet16(ds, 0x943b, ax);
  memoryASet16(ds, 0x943d, ax);
  memoryASet16(ds, 0x943f, ax);
  memoryASet16(ds, 0x9441, ax);
  al = memoryAGet(ds, 0x1b8e);
  memoryASet(ds, 0x9443, al);
  memoryASet(ds, 0x9444, al);
  memoryASet(ds, 0x9445, al);
  memoryASet(ds, 0x9446, al);
  al = memoryAGet(ds, 0x1b8d);
  memoryASet(ds, 0x9447, al);
  memoryASet(ds, 0x9448, al);
  memoryASet(ds, 0x9449, al);
  memoryASet(ds, 0x944a, al);
  return;
}

/*fda mov al, byte ptr [0x94ff]*/
/*fdd mov byte ptr [0x9509], al*/
/*fe0 mov si, 0x1b8a*/
/*fe3 mov al, byte ptr [0x9513]*/
/*fe6 cmp al, 0*/
/*fe8 je 0xff5*/
/*fea call 0xe07*/
/*fed mov al, byte ptr [0x9500]*/
/*ff0 cmp al, 0*/
/*ff2 je 0xfda*/
/*ff4 ret */
/*ff5 mov al, byte ptr [0x94ff]*/
/*ff8 cmp al, byte ptr [0]*/
/*ffc je 0x1036*/
/*ffe cmp al, 1*/
/*1000 jne 0x100e*/
/*1002 mov al, 0xb*/
/*1004 call 0x3840*/
/*1007 call 0xf3c*/
/*100a jmp 0xfda*/
/*100e mov al, 0xb*/
/*1010 call 0x3840*/
/*1013 mov al, byte ptr [0x951d]*/
/*1016 cmp al, 0xf0*/
/*1018 jne 0x101f*/
/*101a call 0xdc0*/
/*101d jmp 0x1034*/
/*101f mov al, byte ptr [0x1ba0]*/
/*1022 and al, 0x7f*/
/*1024 cmp al, 0x28*/
/*1026 jbe 0x1031*/
/*1028 cmp al, 0x58*/
/*102a jae 0x1031*/
/*102c mov byte ptr [0], 1*/
/*1031 call 0xe84*/
/*1034 jmp 0xfda*/
/*1036 mov al, byte ptr [si]*/
/*1038 test al, 0x80*/
/*103a jne 0x1059*/
/*103c test al, 2*/
/*103e je 0x1054*/
/*1040 push si*/
/*1041 mov bl, byte ptr [si + 0x12]*/
/*1044 cmp bl, 0*/
/*1047 je 0x1053*/
/*1049 mov bh, 0*/
/*104b dec bx*/
/*104c shl bx, 1*/
/*104e call word ptr cs:[bx + 0x105a]*/
/*1053 pop si*/
/*1054 add si, 0x17*/
/*1057 jmp 0xfe3*/
/*1059 ret */
void sub_10fda()
{
loc_10fda:
  al = memoryAGet(ds, 0x94ff);
  memoryASet(ds, 0x9509, al);
  si = 0x1b8a;
loc_10fe3:
  al = memoryAGet(ds, 0x9513);
  
  if (al == 0x00) goto loc_10ff5;
  sub_10e07();
  al = memoryAGet(ds, 0x9500);
  
  if (al == 0x00) goto loc_10fda;
  return;
loc_10ff5:
  al = memoryAGet(ds, 0x94ff);
  
  if (al == memoryAGet(ds, 0x9509)) goto loc_11036;
  
  if (al != 0x01) goto loc_1100e;
  al = 0x0b;
  sub_13840();
  sub_10f3c();
  goto loc_10fda;
  // gap 2 bytes
loc_1100e:
  al = 0x0b;
  sub_13840();
  al = memoryAGet(ds, 0x951d);
  
  if (al != 0xf0) goto loc_1101f;
  sub_10dc0();
  goto loc_11034;
loc_1101f:
  al = memoryAGet(ds, 0x1ba0);
  al &= 0x7f;
  
  if (al <= 0x28) goto loc_11031;
  
  if (al >= 0x58) goto loc_11031;
  memoryASet(ds, 0x9432, 0x01);
loc_11031:
  sub_10e84();
loc_11034:
  goto loc_10fda;
loc_11036:
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_11059;
  
  if (al & 0x02) goto loc_11054;
  push(si);
  bl = memoryAGet(ds, si + 18);
  
  if (bl == 0x00) goto loc_11053;
  bh = 0x00;
  bx--;
  bx <<= 0x0001;
  switch (bx)
  {
    case 0: sub_11108(); break;
    case 2: sub_1176c(); break;
    case 4: sub_11783(); break;
    case 6: sub_110c6(); break;
    case 8: sub_117ac(); break;
    case 10: sub_117d6(); break;
    case 12: sub_118a9(); break;
    case 14: sub_11a9e(); break;
    case 16: sub_110c6(); break;
    case 18: sub_11993(); break;
    case 20: sub_119c2(); break;
    case 22: sub_12e02(); break;
    case 24: sub_110c6(); break;
    case 26: sub_12fe8(); break;
    case 28: sub_1300a(); break;
    case 30: sub_116fe(); break;
    case 32: sub_112cb(); break;
    case 34: sub_110c6(); break;
    case 36: sub_112eb(); break;
    case 38: sub_115fc(); break;
    case 40: sub_116df(); break;
    case 42: sub_116d6(); break;
    case 44: sub_11740(); break;
    case 46: sub_11384(); break;
    case 48: sub_113a8(); break;
    case 50: sub_114f0(); break;
    case 52: sub_110f3(); break;
    case 54: sub_118c7(); break;
    case 56: sub_11429(); break;
    case 58: sub_117f4(); break;
    case 60: sub_1171f(); break;
    case 62: sub_11b09(); break;
    case 64: sub_11b4a(); break;
    case 66: sub_12f50(); break;
    case 68: sub_112a7(); break;
    default:
      stop();
  }
loc_11053:
  si = pop();
loc_11054:
  si += 0x0017;
  goto loc_10fe3;
loc_11059:
  return;
}

/*dc0 inc byte ptr [0]*/
/*dc4 mov al, byte ptr [0x94fe]*/
/*dc7 cmp al, 6*/
/*dc9 jb 0xdd3*/
/*dcb mov word ptr [0], 0x30*/
/*dd1 jmp 0xde5*/
/*dd3 cmp al, 3*/
/*dd5 jb 0xddf*/
/*dd7 mov word ptr [0], 0x20*/
/*ddd jmp 0xde5*/
/*ddf mov word ptr [0], 0x10*/
/*de5 inc byte ptr [0]*/
/*de9 mov al, byte ptr [0x9501]*/
/*dec cmp al, 7*/
/*dee jbe 0xdf5*/
/*df0 mov byte ptr [0], 1*/
/*df5 call 0x9a4*/
/*df8 call 0x69a*/
/*dfb mov byte ptr [0], 0*/
/*e00 call 0xe3d*/
/*e03 call 0x2a7f*/
/*e06 ret */
void sub_10dc0()
{
  memoryASet(ds, 0x94fe, memoryAGet(ds, 0x94fe) + 1);
  al = memoryAGet(ds, 0x94fe);
  
  if (al < 0x06) goto loc_10dd3;
  memoryASet16(ds, 0x94fc, 0x0030);
  goto loc_10de5;
loc_10dd3:
  
  if (al < 0x03) goto loc_10ddf;
  memoryASet16(ds, 0x94fc, 0x0020);
  goto loc_10de5;
loc_10ddf:
  memoryASet16(ds, 0x94fc, 0x0010);
loc_10de5:
  memoryASet(ds, 0x9501, memoryAGet(ds, 0x9501) + 1);
  al = memoryAGet(ds, 0x9501);
  
  if (al <= 0x07) goto loc_10df5;
  memoryASet(ds, 0x9501, 0x01);
loc_10df5:
  sub_109a4();
  sub_1069a();
  memoryASet(ds, 0x9519, 0x00);
  sub_10e3d();
  sub_12a7f();
  return;
}

/*e07 mov ax, word ptr [0x9534]*/
/*e0a cmp ax, 0*/
/*e0d jne 0xe15*/
/*e0f mov byte ptr [0], 1*/
/*e14 ret */
/*e15 call 0x2329*/
/*e18 mov al, byte ptr [0x9502]*/
/*e1b cmp al, 0*/
/*e1d je 0xe27*/
/*e1f mov byte ptr [0], 0*/
/*e24 call 0x69a*/
/*e27 call 0x2200*/
/*e2a mov byte ptr [0], 1*/
/*e2f mov byte ptr [0], 0*/
/*e34 mov byte ptr [0], 0*/
/*e39 call 0xe3d*/
/*e3c ret */
void sub_10e07()
{
  ax = memoryAGet16(ds, 0x9534);
  
  if (ax != 0x0000) goto loc_10e15;
  memoryASet(ds, 0x9500, 0x01);
  return;
loc_10e15:
  sub_12329();
  al = memoryAGet(ds, 0x9502);
  
  if (al == 0x00) goto loc_10e27;
  memoryASet(ds, 0x9502, 0x00);
  sub_1069a();
loc_10e27:
  sub_12200();
  memoryASet(ds, 0x9519, 0x01);
  memoryASet(ds, 0x951a, 0x00);
  memoryASet(ds, 0x951b, 0x00);
  sub_10e3d();
  return;
}

/*f3c mov byte ptr [0], 0*/
/*f41 call 0x2ddc*/
/*f44 mov word ptr [0], 0x1a*/
/*f4a mov word ptr [0], 0*/
/*f50 mov word ptr [0], 0*/
/*f56 mov byte ptr [0], 0*/
/*f5b mov byte ptr [0], 3*/
/*f60 call 0xb7c*/
/*f63 mov si, 0xd04*/
/*f66 call 0xb58*/
/*f69 call 0x2df6*/
/*f6c mov al, byte ptr [0x951a]*/
/*f6f cmp al, 0*/
/*f71 je 0xf84*/
/*f73 mov byte ptr [0], 1*/
/*f78 mov si, 0xd1b*/
/*f7b and byte ptr [si], 0xdf*/
/*f7e call 0x2f50*/
/*f81 call 0xb58*/
/*f84 mov al, byte ptr [0x951b]*/
/*f87 cmp al, 0*/
/*f89 je 0xf9c*/
/*f8b mov byte ptr [0], 1*/
/*f90 mov si, 0xd1b*/
/*f93 or byte ptr [si], 0x20*/
/*f96 call 0x2f50*/
/*f99 call 0xb58*/
/*f9c ret */
void sub_10f3c()
{
  memoryASet(ds, 0x951c, 0x00);
  sub_12ddc();
  memoryASet16(ds, 0x9528, 0x001a);
  memoryASet16(ds, 0x9547, 0x0000);
  memoryASet16(ds, 0x951e, 0x0000);
  memoryASet(ds, 0x9524, 0x00);
  memoryASet(ds, 0x9549, 0x03);
  sub_10b7c();
  si = 0x0d04;
  sub_10b58();
  sub_12df6();
  al = memoryAGet(ds, 0x951a);
  
  if (al == 0x00) goto loc_10f84;
  memoryASet(ds, 0x951a, 0x01);
  si = 0x0d1b;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
  sub_12f50();
  sub_10b58();
loc_10f84:
  al = memoryAGet(ds, 0x951b);
  
  if (al == 0x00) goto loc_10f9c;
  memoryASet(ds, 0x951b, 0x01);
  si = 0x0d1b;
  memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
  sub_12f50();
  sub_10b58();
loc_10f9c:
  return;
}

/*10c6 mov al, byte ptr [si + 3]*/
/*10c9 add al, byte ptr [si + 0xc]*/
/*10cc cwde */
/*10cd neg ax*/
/*10cf add ax, word ptr [si + 7]*/
/*10d2 and ax, 0x3ff*/
/*10d5 mov bx, word ptr [0]*/
/*10d9 add bx, 0xa0*/
/*10dd and bx, 0x3ff*/
/*10e1 cmp ax, bx*/
/*10e3 jae 0x10e8*/
/*10e5 add ax, 0x400*/
/*10e8 sub ax, bx*/
/*10ea cmp ax, 0x200*/
/*10ed jae 0x10f2*/
/*10ef mov byte ptr [si], 0*/
/*10f2 ret */
void sub_110c6()
{
  al = memoryAGet(ds, si + 3);
  al += memoryAGet(ds, si + 12);
  true ? cbw() : cwde();
  ax = -ax;
  ax += memoryAGet16(ds, si + 7);
  ax &= 0x03ff;
  bx = memoryAGet16(ds, 0x9528);
  bx += 0x00a0;
  bx &= 0x03ff;
  
  if (ax >= bx) goto loc_110e8;
  ax += 0x0400;
loc_110e8:
  ax -= bx;
  
  if (ax >= 0x0200) goto loc_110f2;
  memoryASet(ds, si, 0x00);
loc_110f2:
  return;
}

/*10f3 inc byte ptr [si + 0x16]*/
/*10f6 mov al, byte ptr [si + 0x16]*/
/*10f9 cmp al, 8*/
/*10fb jbe 0x10ff*/
/*10fd mov al, 8*/
/*10ff mov ah, 0*/
/*1101 sub word ptr [si + 7], ax*/
/*1104 call 0x10a0*/
/*1107 ret */
void sub_110f3()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  
  if (al <= 0x08) goto loc_110ff;
  al = 0x08;
loc_110ff:
  ah = 0x00;
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - ax);
  sub_110a0();
  return;
}

/*10a0 mov al, byte ptr [si + 0xa]*/
/*10a3 sub al, byte ptr [si + 3]*/
/*10a6 sub al, byte ptr [si + 0xc]*/
/*10a9 cwde */
/*10aa add ax, word ptr [si + 7]*/
/*10ad and ax, 0x3ff*/
/*10b0 mov bx, word ptr [0]*/
/*10b4 cmp ax, bx*/
/*10b6 jae 0x10bb*/
/*10b8 add ax, 0x400*/
/*10bb sub ax, bx*/
/*10bd cmp ax, 0x200*/
/*10c0 jbe 0x10c5*/
/*10c2 mov byte ptr [si], 0*/
/*10c5 ret */
void sub_110a0()
{
  al = memoryAGet(ds, si + 10);
  al -= memoryAGet(ds, si + 3);
  al -= memoryAGet(ds, si + 12);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 7);
  ax &= 0x03ff;
  bx = memoryAGet16(ds, 0x9528);
  
  if (ax >= bx) goto loc_110bb;
  ax += 0x0400;
loc_110bb:
  ax -= bx;
  
  if (ax <= 0x0200) goto loc_110c5;
  memoryASet(ds, si, 0x00);
loc_110c5:
  return;
}

/*1108 call 0x1b80*/
/*110b call 0x1bb9*/
/*110e mov bx, word ptr [0]*/
/*1112 mov ax, word ptr [0x952c]*/
/*1115 test bl, 1*/
/*1118 je 0x1131*/
/*111a sub ax, 1*/
/*111d js 0x1127*/
/*111f cmp ax, 4*/
/*1122 jle 0x1127*/
/*1124 mov ax, 4*/
/*1127 cmp ax, 0xffe8*/
/*112a jge 0x112f*/
/*112c mov ax, 0xffe8*/
/*112f jmp 0x1158*/
/*1131 test bl, 2*/
/*1134 je 0x114d*/
/*1136 add ax, 1*/
/*1139 jns 0x1143*/
/*113b cmp ax, 0xfffc*/
/*113e jge 0x1143*/
/*1140 mov ax, 0xfffc*/
/*1143 cmp ax, 0x18*/
/*1146 jle 0x114b*/
/*1148 mov ax, 0x18*/
/*114b jmp 0x1158*/
/*114d cmp ax, 0*/
/*1150 je 0x1158*/
/*1152 jle 0x1157*/
/*1154 dec ax*/
/*1155 jmp 0x1158*/
/*1157 inc ax*/
/*1158 mov word ptr [0x952c], ax*/
/*115b add ax, 3*/
/*115e sar ax, 1*/
/*1160 sar ax, 1*/
/*1162 add ax, word ptr [0x1b8f]*/
/*1166 cmp ax, 0x14*/
/*1169 jge 0x1174*/
/*116b mov ax, 0x14*/
/*116e mov word ptr [0], 0*/
/*1174 cmp ax, 0xec*/
/*1177 jle 0x1182*/
/*1179 mov ax, 0xec*/
/*117c mov word ptr [0], 0*/
/*1182 mov word ptr [0x1b8f], ax*/
/*1185 mov al, byte ptr [0x1b8e]*/
/*1188 cmp al, 0*/
/*118a je 0x118f*/
/*118c call 0x1b57*/
/*118f call 0x1c78*/
/*1192 call 0xa51*/
/*1195 cmp ax, 0*/
/*1198 je 0x119f*/
/*119a call 0x1c56*/
/*119d jmp 0x11bc*/
/*119f inc byte ptr [0x1b9e]*/
/*11a3 and byte ptr [0x1b9e], 0x3f*/
/*11a8 call 0xa51*/
/*11ab cmp ax, 0*/
/*11ae je 0x11b3*/
/*11b0 call 0x1c56*/
/*11b3 dec byte ptr [0x1b9e]*/
/*11b7 and byte ptr [0x1b9e], 0x3f*/
/*11bc mov ax, word ptr [0x9542]*/
/*11bf cmp ax, 0*/
/*11c2 jg 0x11c8*/
/*11c4 call 0x1c33*/
/*11c7 ret */
/*11c8 mov al, byte ptr [0x1b8e]*/
/*11cb cmp al, 0*/
/*11cd jne 0x11de*/
/*11cf inc byte ptr [0]*/
/*11d3 mov al, byte ptr [0x9515]*/
/*11d6 cmp al, 4*/
/*11d8 jb 0x11dd*/
/*11da call 0x1c33*/
/*11dd ret */
/*11de mov ax, word ptr [0x953e]*/
/*11e1 cmp ax, 0*/
/*11e4 jle 0x11f0*/
/*11e6 mov ax, word ptr [0x954c]*/
/*11e9 test al, 0x80*/
/*11eb je 0x11f0*/
/*11ed call 0x1d1e*/
/*11f0 mov ax, word ptr [0x954c]*/
/*11f3 mov bl, byte ptr [0]*/
/*11f7 test al, 0x40*/
/*11f9 je 0x1235*/
/*11fb cmp bl, 0*/
/*11fe jne 0x1224*/
/*1200 mov ax, word ptr [0x9536]*/
/*1203 cmp ax, 0*/
/*1206 jbe 0x1222*/
/*1208 mov byte ptr [0], 1*/
/*120d mov si, 0xdc3*/
/*1210 and byte ptr [si], 0xdf*/
/*1213 call 0x1cd9*/
/*1216 call 0xb58*/
/*1219 dec word ptr [0]*/
/*121d mov al, 1*/
/*121f call 0x3840*/
/*1222 jmp 0x1233*/
/*1224 cmp bl, 2*/
/*1227 jne 0x1233*/
/*1229 mov byte ptr [0], 3*/
/*122e mov al, 2*/
/*1230 call 0x3840*/
/*1233 jmp 0x124b*/
/*1235 cmp bl, 1*/
/*1238 jne 0x1241*/
/*123a mov byte ptr [0], 2*/
/*123f jmp 0x124b*/
/*1241 cmp bl, 3*/
/*1244 jne 0x124b*/
/*1246 mov byte ptr [0], 0*/
/*124b mov ax, word ptr [0x954c]*/
/*124e mov bl, byte ptr [0]*/
/*1252 test al, 0x20*/
/*1254 je 0x1290*/
/*1256 cmp bl, 0*/
/*1259 jne 0x127f*/
/*125b mov ax, word ptr [0x9536]*/
/*125e cmp ax, 0*/
/*1261 jbe 0x127d*/
/*1263 mov byte ptr [0], 1*/
/*1268 mov si, 0xdc3*/
/*126b or byte ptr [si], 0x20*/
/*126e call 0x1cd9*/
/*1271 call 0xb58*/
/*1274 dec word ptr [0]*/
/*1278 mov al, 1*/
/*127a call 0x3840*/
/*127d jmp 0x128e*/
/*127f cmp bl, 2*/
/*1282 jne 0x128e*/
/*1284 mov byte ptr [0], 3*/
/*1289 mov al, 2*/
/*128b call 0x3840*/
/*128e jmp 0x12a6*/
/*1290 cmp bl, 1*/
/*1293 jne 0x129c*/
/*1295 mov byte ptr [0], 2*/
/*129a jmp 0x12a6*/
/*129c cmp bl, 3*/
/*129f jne 0x12a6*/
/*12a1 mov byte ptr [0], 0*/
/*12a6 ret */
void sub_11108()
{
  sub_11b80();
  sub_11bb9();
  bx = memoryAGet16(ds, 0x954c);
  ax = memoryAGet16(ds, 0x952c);
  
  if (bl & 0x01) goto loc_11131;
  ax -= 0x0001;
  if ((short)ax < 0) goto loc_11127;
  
  if ((short)ax <= (short)0x0004) goto loc_11127;
  ax = 0x0004;
loc_11127:
  
  if ((short)ax >= (short)0xffe8) goto loc_1112f;
  ax = 0xffe8;
loc_1112f:
  goto loc_11158;
loc_11131:
  
  if (bl & 0x02) goto loc_1114d;
  ax += 0x0001;
  if ((short)ax >= 0) goto loc_11143;
  
  if ((short)ax >= (short)0xfffc) goto loc_11143;
  ax = 0xfffc;
loc_11143:
  
  if ((short)ax <= (short)0x0018) goto loc_1114b;
  ax = 0x0018;
loc_1114b:
  goto loc_11158;
loc_1114d:
  
  if (ax == 0x0000) goto loc_11158;
  if ((short)ax <= (short)0x0000) goto loc_11157;
  ax--;
  goto loc_11158;
loc_11157:
  ax++;
loc_11158:
  memoryASet16(ds, 0x952c, ax);
  ax += 0x0003;
  ax = sar16(ax, 0x0001);
  ax = sar16(ax, 0x0001);
  ax += memoryAGet16(ds, 0x1b8f);
  
  if ((short)ax >= (short)0x0014) goto loc_11174;
  ax = 0x0014;
  memoryASet16(ds, 0x952c, 0x0000);
loc_11174:
  
  if ((short)ax <= (short)0x00ec) goto loc_11182;
  ax = 0x00ec;
  memoryASet16(ds, 0x952c, 0x0000);
loc_11182:
  memoryASet16(ds, 0x1b8f, ax);
  al = memoryAGet(ds, 0x1b8e);
  
  if (al == 0x00) goto loc_1118f;
  sub_11b57();
loc_1118f:
  sub_11c78();
  sub_10a51();
  
  if (ax == 0x0000) goto loc_1119f;
  sub_11c56();
  goto loc_111bc;
loc_1119f:
  memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) + 1);
  memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) & 0x3f);
  sub_10a51();
  
  if (ax == 0x0000) goto loc_111b3;
  sub_11c56();
loc_111b3:
  memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) - 1);
  memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) & 0x3f);
loc_111bc:
  ax = memoryAGet16(ds, 0x9542);
  
  if ((short)ax > (short)0x0000) goto loc_111c8;
  sub_11c33();
  return;
loc_111c8:
  al = memoryAGet(ds, 0x1b8e);
  
  if (al != 0x00) goto loc_111de;
  memoryASet(ds, 0x9515, memoryAGet(ds, 0x9515) + 1);
  al = memoryAGet(ds, 0x9515);
  
  if (al < 0x04) goto loc_111dd;
  sub_11c33();
loc_111dd:
  return;
loc_111de:
  ax = memoryAGet16(ds, 0x953e);
  
  if ((short)ax <= (short)0x0000) goto loc_111f0;
  ax = memoryAGet16(ds, 0x954c);
  
  if (al & 0x80) goto loc_111f0;
  sub_11d1e();
loc_111f0:
  ax = memoryAGet16(ds, 0x954c);
  bl = memoryAGet(ds, 0x951a);
  
  if (al & 0x40) goto loc_11235;
  
  if (bl != 0x00) goto loc_11224;
  ax = memoryAGet16(ds, 0x9536);
  
  if (ax <= 0x0000) goto loc_11222;
  memoryASet(ds, 0x951a, 0x01);
  si = 0x0dc3;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
  sub_11cd9();
  sub_10b58();
  memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) - 1);
  al = 0x01;
  sub_13840();
loc_11222:
  goto loc_11233;
loc_11224:
  
  if (bl != 0x02) goto loc_11233;
  memoryASet(ds, 0x951a, 0x03);
  al = 0x02;
  sub_13840();
loc_11233:
  goto loc_1124b;
loc_11235:
  
  if (bl != 0x01) goto loc_11241;
  memoryASet(ds, 0x951a, 0x02);
  goto loc_1124b;
loc_11241:
  
  if (bl != 0x03) goto loc_1124b;
  memoryASet(ds, 0x951a, 0x00);
loc_1124b:
  ax = memoryAGet16(ds, 0x954c);
  bl = memoryAGet(ds, 0x951b);
  
  if (al & 0x20) goto loc_11290;
  
  if (bl != 0x00) goto loc_1127f;
  ax = memoryAGet16(ds, 0x9536);
  
  if (ax <= 0x0000) goto loc_1127d;
  memoryASet(ds, 0x951b, 0x01);
  si = 0x0dc3;
  memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
  sub_11cd9();
  sub_10b58();
  memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) - 1);
  al = 0x01;
  sub_13840();
loc_1127d:
  goto loc_1128e;
loc_1127f:
  
  if (bl != 0x02) goto loc_1128e;
  memoryASet(ds, 0x951b, 0x03);
  al = 0x02;
  sub_13840();
loc_1128e:
  goto loc_112a6;
loc_11290:
  
  if (bl != 0x01) goto loc_1129c;
  memoryASet(ds, 0x951b, 0x02);
  goto loc_112a6;
loc_1129c:
  
  if (bl != 0x03) goto loc_112a6;
  memoryASet(ds, 0x951b, 0x00);
loc_112a6:
  return;
}

/*a51 mov bl, byte ptr [0x1b9e]*/
/*a55 mov bh, 0*/
/*a57 shl bx, 1*/
/*a59 mov si, bx*/
/*a5b mov al, byte ptr [0x9502]*/
/*a5e cmp al, 1*/
/*a60 jne 0xa68*/
/*a62 add si, 0x80*/
/*a66 jmp 0xa70*/
/*a68 cmp al, 2*/
/*a6a jne 0xa70*/
/*a6c add si, 0x100*/
/*a70 mov ax, word ptr [si - 0x6d57]*/
/*a74 and ax, word ptr [bx - 0x6dd7]*/
/*a78 cmp ax, 0*/
/*a7b je 0xad1*/
/*a7d mov bl, ah*/
/*a7f shr bl, 1*/
/*a81 shr bl, 1*/
/*a83 mov bh, 0*/
/*a85 mov cl, byte ptr [bx + 0x2b5]*/
/*a89 cmp cl, 0*/
/*a8c je 0xad1*/
/*a8e mov byte ptr [0], cl*/
/*a92 mov word ptr [0], 0xa*/
/*a98 shl bx, 1*/
/*a9a mov dx, word ptr [bx + 0x2ca]*/
/*a9e mov bx, word ptr [bx + 0x2f4]*/
/*aa2 mov cx, 0xa*/
/*aa5 shr ax, 1*/
/*aa7 jae 0xac8*/
/*aa9 push bx*/
/*aaa sub bx, dx*/
/*aac cmp bx, word ptr [0x1b8f]*/
/*ab0 jg 0xac7*/
/*ab2 add bx, dx*/
/*ab4 add bx, dx*/
/*ab6 cmp bx, word ptr [0x1b8f]*/
/*aba jl 0xac7*/
/*abc pop ax*/
/*abd mov al, byte ptr [0x9429]*/
/*ac0 mov ah, 0*/
/*ac2 mov bx, word ptr [0]*/
/*ac6 ret */
/*ac7 pop bx*/
/*ac8 sub bx, 0x18*/
/*acb dec word ptr [0]*/
/*acf loop 0xaa5*/
/*ad1 mov ax, 0*/
/*ad4 ret */
void sub_10a51()
{
  bool temp_cf;

  bl = memoryAGet(ds, 0x1b9e);
  bh = 0x00;
  bx <<= 0x0001;
  si = bx;
  al = memoryAGet(ds, 0x9502);
  
  if (al != 0x01) goto loc_10a68;
  si += 0x0080;
  goto loc_10a70;
loc_10a68:
  
  if (al != 0x02) goto loc_10a70;
  si += 0x0100;
loc_10a70:
  ax = memoryAGet16(ds, si + 37545);
  ax &= memoryAGet16(ds, bx + 37417);
  
  if (ax == 0x0000) goto loc_10ad1;
  bl = ah;
  bl >>= 0x01;
  bl >>= 0x01;
  bh = 0x00;
  cl = memoryAGet(ds, bx + 693);
  
  if (cl == 0x00) goto loc_10ad1;
  memoryASet(ds, 0x9429, cl);
  memoryASet16(ds, 0x942c, 0x000a);
  bx <<= 0x0001;
  dx = memoryAGet16(ds, bx + 714);
  bx = memoryAGet16(ds, bx + 756);
  cx = 0x000a;
loc_10aa5:
  temp_cf = ax & 1;
  ax >>= 0x0001;
  if (!temp_cf) goto loc_10ac8;
  push(bx);
  bx -= dx;
  
  if ((short)bx > (short)memoryAGet16(ds, 0x1b8f)) goto loc_10ac7;
  bx += dx;
  bx += dx;
  
  if ((short)bx < (short)memoryAGet16(ds, 0x1b8f)) goto loc_10ac7;
  ax = pop();
  al = memoryAGet(ds, 0x9429);
  ah = 0x00;
  bx = memoryAGet16(ds, 0x942c);
  return;
loc_10ac7:
  bx = pop();
loc_10ac8:
  bx -= 0x0018;
  memoryASet16(ds, 0x942c, memoryAGet16(ds, 0x942c) - 1);
  if (--cx) goto loc_10aa5;
loc_10ad1:
  ax = 0x0000;
  return;
}

/*12a7 mov ax, word ptr [0x952a]*/
/*12aa sub ax, 3*/
/*12ad js 0x12b4*/
/*12af mov word ptr [0x952a], ax*/
/*12b2 jmp 0x12b7*/
/*12b4 call 0x1c33*/
/*12b7 call 0x1bb9*/
/*12ba call 0x1b57*/
/*12bd mov si, 0x1b8a*/
/*12c0 mov bx, 0xd49*/
/*12c3 mov byte ptr [si + 4], 0xa*/
/*12c7 call 0x2121*/
/*12ca ret */
void sub_112a7()
{
  ax = memoryAGet16(ds, 0x952a);
  ax -= 0x0003;
  if ((short)ax < 0) goto loc_112b4;
  memoryASet16(ds, 0x952a, ax);
  goto loc_112b7;
loc_112b4:
  sub_11c33();
loc_112b7:
  sub_11bb9();
  sub_11b57();
  si = 0x1b8a;
  bx = 0x0d49;
  memoryASet(ds, si + 4, 0x0a);
  sub_12121();
  return;
}

/*12cb mov ax, word ptr [0x952a]*/
/*12ce dec ax*/
/*12cf js 0x12d4*/
/*12d1 mov word ptr [0x952a], ax*/
/*12d4 call 0x1bb9*/
/*12d7 call 0x1b57*/
/*12da inc byte ptr [0]*/
/*12de mov al, byte ptr [0x9514]*/
/*12e1 cmp al, 0x28*/
/*12e3 jb 0x12ea*/
/*12e5 mov byte ptr [0], 1*/
/*12ea ret */
void sub_112cb()
{
  ax = memoryAGet16(ds, 0x952a);
  ax--;
  if ((short)ax < 0) goto loc_112d4;
  memoryASet16(ds, 0x952a, ax);
loc_112d4:
  sub_11bb9();
  sub_11b57();
  memoryASet(ds, 0x9514, memoryAGet(ds, 0x9514) + 1);
  al = memoryAGet(ds, 0x9514);
  
  if (al < 0x28) goto loc_112ea;
  memoryASet(ds, 0x9513, 0x01);
loc_112ea:
  return;
}

/*12eb call 0x10a0*/
/*12ee mov al, byte ptr [si]*/
/*12f0 cmp al, 0*/
/*12f2 jne 0x12f5*/
/*12f4 ret */
/*12f5 sub word ptr [si + 7], 0x10*/
/*12f9 and word ptr [si + 7], 0x3ff*/
/*12fe mov al, byte ptr [si + 4]*/
/*1301 cmp al, 1*/
/*1303 jne 0x1312*/
/*1305 mov al, byte ptr [si + 3]*/
/*1308 cmp al, 0x9c*/
/*130a jle 0x1310*/
/*130c sub byte ptr [si + 3], 8*/
/*1310 jmp 0x1321*/
/*1312 cmp al, 2*/
/*1314 jne 0x1321*/
/*1316 mov al, byte ptr [si + 3]*/
/*1319 cmp al, 0x64*/
/*131b jge 0x1321*/
/*131d add byte ptr [si + 3], 8*/
/*1321 push si*/
/*1322 mov ax, word ptr [si + 5]*/
/*1325 push ax*/
/*1326 mov ax, word ptr [si + 7]*/
/*1329 push ax*/
/*132a call 0x7fd*/
/*132d pop si*/
/*132e cmp al, byte ptr [si + 3]*/
/*1331 jl 0x1338*/
/*1333 call 0x2092*/
/*1336 jmp 0x1383*/
/*1338 push si*/
/*1339 mov ax, word ptr [si + 5]*/
/*133c push ax*/
/*133d mov byte ptr [si + 0x14], cl*/
/*1340 push cx*/
/*1341 call 0xad5*/
/*1344 pop si*/
/*1345 cmp ax, 0*/
/*1348 je 0x1383*/
/*134a push si*/
/*134b mov al, byte ptr [si + 0x14]*/
/*134e mov ah, 0*/
/*1350 push bx*/
/*1351 push ax*/
/*1352 call 0x1c0a*/
/*1355 mov al, byte ptr [si]*/
/*1357 test al, 0x80*/
/*1359 jne 0x1382*/
/*135b pop bx*/
/*135c push bx*/
/*135d mov al, byte ptr [si + 3]*/
/*1360 sub al, byte ptr [bx + 3]*/
/*1363 jns 0x1367*/
/*1365 neg al*/
/*1367 cmp al, 0x10*/
/*1369 jae 0x1382*/
/*136b dec byte ptr [si + 0x15]*/
/*136e jns 0x137a*/
/*1370 call 0x20db*/
/*1373 mov al, 6*/
/*1375 call 0x3840*/
/*1378 jmp 0x137d*/
/*137a call 0x2662*/
/*137d pop si*/
/*137e push si*/
/*137f call 0x2047*/
/*1382 pop si*/
/*1383 ret */
void sub_112eb()
{
  sub_110a0();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_112f5;
  return;
loc_112f5:
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0010);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  al = memoryAGet(ds, si + 4);
  
  if (al != 0x01) goto loc_11312;
  al = memoryAGet(ds, si + 3);
  
  if ((char)al <= (char)0x9c) goto loc_11310;
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 0x08);
loc_11310:
  goto loc_11321;
loc_11312:
  
  if (al != 0x02) goto loc_11321;
  al = memoryAGet(ds, si + 3);
  
  if ((char)al >= (char)0x64) goto loc_11321;
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + 0x08);
loc_11321:
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  ax = memoryAGet16(ds, si + 7);
  push(ax);
  sub_107fd();
  si = pop();
  
  if ((char)al < (char)memoryAGet(ds, si + 3)) goto loc_11338;
  sub_12092();
  goto loc_11383;
loc_11338:
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  memoryASet(ds, si + 20, cl);
  push(cx);
  sub_10ad5();
  si = pop();
  
  if (ax == 0x0000) goto loc_11383;
  push(si);
  al = memoryAGet(ds, si + 20);
  ah = 0x00;
  push(bx);
  push(ax);
  sub_11c0a();
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_11382;
  bx = pop();
  push(bx);
  al = memoryAGet(ds, si + 3);
  al -= memoryAGet(ds, bx + 3);
  if ((char)al >= 0) goto loc_11367;
  al = -al;
loc_11367:
  
  if (al >= 0x10) goto loc_11382;
  memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
  if ((char)memoryAGet(ds, si + 21) >= 0) goto loc_1137a;
  sub_120db();
  al = 0x06;
  sub_13840();
  goto loc_1137d;
loc_1137a:
  sub_12662();
loc_1137d:
  si = pop();
  push(si);
  sub_12047();
loc_11382:
  si = pop();
loc_11383:
  return;
}

/*7fd push bp*/
/*7fe mov bp, sp*/
/*800 sub sp, 8*/
/*803 mov ax, word ptr [bp + 6]*/
/*806 add ax, 0x10*/
/*809 mov cl, 0x18*/
/*80b div cl*/
/*80d push ax*/
/*80e mov ah, 0*/
/*810 mov word ptr [bp - 2], ax*/
/*813 pop ax*/
/*814 mov al, ah*/
/*816 mov ah, 0*/
/*818 mov cl, 3*/
/*81a div cl*/
/*81c mov ah, 0*/
/*81e mov word ptr [bp - 4], ax*/
/*821 mov ax, word ptr [bp + 4]*/
/*824 and ax, 0x3ff*/
/*827 shr ax, 1*/
/*829 shr ax, 1*/
/*82b shr ax, 1*/
/*82d shr ax, 1*/
/*82f neg ax*/
/*831 add ax, 0x3f*/
/*834 mov word ptr [bp - 6], ax*/
/*837 mov ax, word ptr [bp + 4]*/
/*83a and ax, 0xf*/
/*83d shr ax, 1*/
/*83f mov word ptr [bp - 8], ax*/
/*842 mov ax, word ptr [bp - 6]*/
/*845 shl ax, 1*/
/*847 shl ax, 1*/
/*849 mov bx, ax*/
/*84b shl ax, 1*/
/*84d add bx, ax*/
/*84f add bx, 0x8f29*/
/*853 mov si, bx*/
/*855 add bx, word ptr [bp - 2]*/
/*858 mov al, byte ptr [bx]*/
/*85a mov ah, 0*/
/*85c push ax*/
/*85d shl ax, 1*/
/*85f mov bx, ax*/
/*861 mov bx, word ptr [bx + 0x643]*/
/*865 mov ax, word ptr [bp - 8]*/
/*868 shl ax, 1*/
/*86a shl ax, 1*/
/*86c shl ax, 1*/
/*86e add bx, ax*/
/*870 add bx, word ptr [bp - 4]*/
/*873 mov cl, byte ptr [bx]*/
/*875 push cx*/
/*876 and cl, 0x1f*/
/*879 test cl, 0x10*/
/*87c je 0x881*/
/*87e or cl, 0xe0*/
/*881 mov dx, word ptr [bp - 2]*/
/*884 cld */
/*885 cmp dx, 0*/
/*888 je 0x896*/
/*88a lodsb al, byte ptr [si]*/
/*88b mov bh, 0*/
/*88d mov bl, al*/
/*88f add cl, byte ptr [bx + 0x571]*/
/*893 dec dx*/
/*894 jmp 0x885*/
/*896 mov al, cl*/
/*898 cwde */
/*899 pop cx*/
/*89a pop bx*/
/*89b test cl, 0x80*/
/*89e jne 0x8a6*/
/*8a0 mov bl, byte ptr [bx + 0x59b]*/
/*8a4 jmp 0x8aa*/
/*8a6 mov bl, byte ptr [bx + 0x5c5]*/
/*8aa mov bh, 0*/
/*8ac mov cx, word ptr [bp - 6]*/
/*8af neg cx*/
/*8b1 add cx, 0x3f*/
/*8b4 mov sp, bp*/
/*8b6 pop bp*/
/*8b7 ret 4*/
void sub_107fd()
{
  push(bp);
  bp = sp;
  sp -= 0x0008;
  ax = memoryAGet16(ss, bp + 6 - 2);
  ax += 0x0010;
  cl = 0x18;
  div8(cl);
  push(ax);
  ah = 0x00;
  memoryASet16(ss, bp - 2 - 2, ax);
  ax = pop();
  al = ah;
  ah = 0x00;
  cl = 0x03;
  div8(cl);
  ah = 0x00;
  memoryASet16(ss, bp - 4 - 2, ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  ax &= 0x03ff;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax = -ax;
  ax += 0x003f;
  memoryASet16(ss, bp - 6 - 2, ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  ax &= 0x000f;
  ax >>= 0x0001;
  memoryASet16(ss, bp - 8 - 2, ax);
  ax = memoryAGet16(ss, bp - 6 - 2);
  ax <<= 0x0001;
  ax <<= 0x0001;
  bx = ax;
  ax <<= 0x0001;
  bx += ax;
  bx += 0x8f29;
  si = bx;
  bx += memoryAGet16(ss, bp - 2 - 2);
  al = memoryAGet(ds, bx);
  ah = 0x00;
  push(ax);
  ax <<= 0x0001;
  bx = ax;
  bx = memoryAGet16(ds, bx + 1603);
  ax = memoryAGet16(ss, bp - 8 - 2);
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  bx += ax;
  bx += memoryAGet16(ss, bp - 4 - 2);
  cl = memoryAGet(ds, bx);
  push(cx);
  cl &= 0x1f;
  
  if (cl & 0x10) goto loc_10881;
  cl |= 0xe0;
loc_10881:
  dx = memoryAGet16(ss, bp - 2 - 2);
  flags.direction = 0;
loc_10885:
  
  if (dx == 0x0000) goto loc_10896;
  al = lodsb<DS_SI>();
  bh = 0x00;
  bl = al;
  cl += memoryAGet(ds, bx + 1393);
  dx--;
  goto loc_10885;
loc_10896:
  al = cl;
  true ? cbw() : cwde();
  cx = pop();
  bx = pop();
  
  if (!(cl & 0x80)) goto loc_108a6;
  bl = memoryAGet(ds, bx + 1435);
  goto loc_108aa;
loc_108a6:
  bl = memoryAGet(ds, bx + 1477);
loc_108aa:
  bh = 0x00;
  cx = memoryAGet16(ss, bp - 6 - 2);
  cx = -cx;
  cx += 0x003f;
  sp = bp;
  bp = pop();
  return;
}

/*ad5 push bp*/
/*ad6 mov bp, sp*/
/*ad8 mov bx, word ptr [bp + 4]*/
/*adb shl bx, 1*/
/*add mov si, bx*/
/*adf mov al, byte ptr [0x9502]*/
/*ae2 cmp al, 1*/
/*ae4 jne 0xaec*/
/*ae6 add si, 0x80*/
/*aea jmp 0xaf4*/
/*aec cmp al, 2*/
/*aee jne 0xaf4*/
/*af0 add si, 0x100*/
/*af4 mov ax, word ptr [si - 0x6d57]*/
/*af8 and ax, word ptr [bx - 0x6dd7]*/
/*afc cmp ax, 0*/
/*aff je 0xb51*/
/*b01 mov bl, ah*/
/*b03 shr bl, 1*/
/*b05 shr bl, 1*/
/*b07 mov bh, 0*/
/*b09 mov cl, byte ptr [bx + 0x2b5]*/
/*b0d cmp cl, 0*/
/*b10 je 0xb51*/
/*b12 mov word ptr [0], 0xa*/
/*b18 shl bx, 1*/
/*b1a mov dx, word ptr [bx + 0x2ca]*/
/*b1e sub dx, 0xe*/
/*b21 mov bx, word ptr [bx + 0x2f4]*/
/*b25 mov cx, 0xa*/
/*b28 shr ax, 1*/
/*b2a jae 0xb48*/
/*b2c push bx*/
/*b2d sub bx, dx*/
/*b2f cmp bx, word ptr [bp + 6]*/
/*b32 jg 0xb47*/
/*b34 add bx, dx*/
/*b36 add bx, dx*/
/*b38 cmp bx, word ptr [bp + 6]*/
/*b3b jl 0xb47*/
/*b3d pop ax*/
/*b3e mov ax, 1*/
/*b41 mov bx, word ptr [0]*/
/*b45 jmp 0xb54*/
/*b47 pop bx*/
/*b48 sub bx, 0x18*/
/*b4b dec word ptr [0]*/
/*b4f loop 0xb28*/
/*b51 mov ax, 0*/
/*b54 pop bp*/
/*b55 ret 4*/
void sub_10ad5()
{
  bool temp_cf;

  push(bp);
  bp = sp;
  bx = memoryAGet16(ss, bp + 4 - 2);
  bx <<= 0x0001;
  si = bx;
  al = memoryAGet(ds, 0x9502);
  
  if (al != 0x01) goto loc_10aec;
  si += 0x0080;
  goto loc_10af4;
loc_10aec:
  
  if (al != 0x02) goto loc_10af4;
  si += 0x0100;
loc_10af4:
  ax = memoryAGet16(ds, si + 37545);
  ax &= memoryAGet16(ds, bx + 37417);
  
  if (ax == 0x0000) goto loc_10b51;
  bl = ah;
  bl >>= 0x01;
  bl >>= 0x01;
  bh = 0x00;
  cl = memoryAGet(ds, bx + 693);
  
  if (cl == 0x00) goto loc_10b51;
  memoryASet16(ds, 0x942c, 0x000a);
  bx <<= 0x0001;
  dx = memoryAGet16(ds, bx + 714);
  dx -= 0x000e;
  bx = memoryAGet16(ds, bx + 756);
  cx = 0x000a;
loc_10b28:
  temp_cf = ax & 1;
  ax >>= 0x0001;
  if (!temp_cf) goto loc_10b48;
  push(bx);
  bx -= dx;
  
  if ((short)bx > (short)memoryAGet16(ss, bp + 6 - 2)) goto loc_10b47;
  bx += dx;
  bx += dx;
  
  if ((short)bx < (short)memoryAGet16(ss, bp + 6 - 2)) goto loc_10b47;
  ax = pop();
  ax = 0x0001;
  bx = memoryAGet16(ds, 0x942c);
  goto loc_10b54;
loc_10b47:
  bx = pop();
loc_10b48:
  bx -= 0x0018;
  memoryASet16(ds, 0x942c, memoryAGet16(ds, 0x942c) - 1);
  if (--cx) goto loc_10b28;
loc_10b51:
  ax = 0x0000;
loc_10b54:
  bp = pop();
  return;
}

/*1384 mov al, byte ptr [0x1b9c]*/
/*1387 cmp al, 0x11*/
/*1389 jne 0x138e*/
/*138b mov byte ptr [si], 0*/
/*138e call 0x1cd9*/
/*1391 mov al, byte ptr [si]*/
/*1393 test al, 0x20*/
/*1395 jne 0x139c*/
/*1397 mov al, byte ptr [0x951a]*/
/*139a jmp 0x139f*/
/*139c mov al, byte ptr [0x951b]*/
/*139f cmp al, 3*/
/*13a1 jne 0x13a7*/
/*13a3 mov byte ptr [si + 0x12], 0x19*/
/*13a7 ret */
void sub_11384()
{
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_1138e;
  memoryASet(ds, si, 0x00);
loc_1138e:
  sub_11cd9();
  al = memoryAGet(ds, si);
  
  if (!(al & 0x20)) goto loc_1139c;
  al = memoryAGet(ds, 0x951a);
  goto loc_1139f;
loc_1139c:
  al = memoryAGet(ds, 0x951b);
loc_1139f:
  
  if (al != 0x03) goto loc_113a7;
  memoryASet(ds, si + 18, 0x19);
loc_113a7:
  return;
}

/*13a8 call 0x10a0*/
/*13ab mov al, byte ptr [si]*/
/*13ad cmp al, 0*/
/*13af jne 0x13b2*/
/*13b1 ret */
/*13b2 sub word ptr [si + 7], 6*/
/*13b6 and word ptr [si + 7], 0x3ff*/
/*13bb push si*/
/*13bc mov ax, word ptr [si + 5]*/
/*13bf push ax*/
/*13c0 mov ax, word ptr [si + 7]*/
/*13c3 push ax*/
/*13c4 call 0x7fd*/
/*13c7 pop si*/
/*13c8 add al, 4*/
/*13ca mov byte ptr [si + 3], al*/
/*13cd mov byte ptr [si + 0x14], cl*/
/*13d0 mov byte ptr [si + 4], bl*/
/*13d3 mov bx, 0xdda*/
/*13d6 call 0x2121*/
/*13d9 mov al, byte ptr [si + 4]*/
/*13dc cmp al, 0*/
/*13de jne 0x13f5*/
/*13e0 add word ptr [si + 7], 4*/
/*13e4 and word ptr [si + 7], 0x3ff*/
/*13e9 dec byte ptr [si + 0x15]*/
/*13ec jns 0x13f5*/
/*13ee call 0x20f0*/
/*13f1 mov byte ptr [si], 0*/
/*13f4 ret */
/*13f5 push si*/
/*13f6 mov ax, word ptr [si + 5]*/
/*13f9 push ax*/
/*13fa mov cl, byte ptr [si + 0x14]*/
/*13fd mov ch, 0*/
/*13ff push cx*/
/*1400 call 0xad5*/
/*1403 pop si*/
/*1404 cmp ax, 0*/
/*1407 je 0x1428*/
/*1409 push si*/
/*140a mov al, byte ptr [si + 0x14]*/
/*140d mov ah, 0*/
/*140f push bx*/
/*1410 push ax*/
/*1411 call 0x1c0a*/
/*1414 mov al, byte ptr [si]*/
/*1416 test al, 0x80*/
/*1418 jne 0x1427*/
/*141a call 0x20db*/
/*141d mov al, 6*/
/*141f call 0x3840*/
/*1422 pop si*/
/*1423 push si*/
/*1424 mov byte ptr [si], 0*/
/*1427 pop si*/
/*1428 ret */
void sub_113a8()
{
  sub_110a0();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_113b2;
  return;
loc_113b2:
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0006);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  ax = memoryAGet16(ds, si + 7);
  push(ax);
  sub_107fd();
  si = pop();
  al += 0x04;
  memoryASet(ds, si + 3, al);
  memoryASet(ds, si + 20, cl);
  memoryASet(ds, si + 4, bl);
  bx = 0x0dda;
  sub_12121();
  al = memoryAGet(ds, si + 4);
  
  if (al != 0x00) goto loc_113f5;
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
  if ((char)memoryAGet(ds, si + 21) >= 0) goto loc_113f5;
  sub_120f0();
  memoryASet(ds, si, 0x00);
  return;
loc_113f5:
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  cl = memoryAGet(ds, si + 20);
  ch = 0x00;
  push(cx);
  sub_10ad5();
  si = pop();
  
  if (ax == 0x0000) goto loc_11428;
  push(si);
  al = memoryAGet(ds, si + 20);
  ah = 0x00;
  push(bx);
  push(ax);
  sub_11c0a();
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_11427;
  sub_120db();
  al = 0x06;
  sub_13840();
  si = pop();
  push(si);
  memoryASet(ds, si, 0x00);
loc_11427:
  si = pop();
loc_11428:
  return;
}

/*1429 call 0x10c6*/
/*142c mov al, byte ptr [si]*/
/*142e cmp al, 0*/
/*1430 jne 0x1433*/
/*1432 ret */
/*1433 mov al, byte ptr [si + 1]*/
/*1436 cmp al, 2*/
/*1438 jne 0x1440*/
/*143a add word ptr [si + 7], 5*/
/*143e jmp 0x146a*/
/*1440 cmp al, 0*/
/*1442 jne 0x144a*/
/*1444 sub word ptr [si + 5], 5*/
/*1448 jmp 0x146a*/
/*144a cmp al, 1*/
/*144c jne 0x1458*/
/*144e sub word ptr [si + 5], 3*/
/*1452 add word ptr [si + 7], 2*/
/*1456 jmp 0x146a*/
/*1458 cmp al, 3*/
/*145a jne 0x1466*/
/*145c add word ptr [si + 5], 3*/
/*1460 add word ptr [si + 7], 2*/
/*1464 jmp 0x146a*/
/*1466 add word ptr [si + 5], 5*/
/*146a and word ptr [si + 7], 0x3ff*/
/*146f mov ax, word ptr [si + 5]*/
/*1472 cmp ax, 0xc*/
/*1475 jge 0x147b*/
/*1477 mov byte ptr [si], 0*/
/*147a ret */
/*147b cmp ax, 0xf4*/
/*147e jle 0x1484*/
/*1480 mov byte ptr [si], 0*/
/*1483 ret */
/*1484 push si*/
/*1485 mov ax, word ptr [si + 5]*/
/*1488 push ax*/
/*1489 mov ax, word ptr [si + 7]*/
/*148c push ax*/
/*148d call 0x7fd*/
/*1490 pop si*/
/*1491 add al, 8*/
/*1493 mov byte ptr [si + 3], al*/
/*1496 mov byte ptr [si + 0x14], cl*/
/*1499 mov byte ptr [si + 4], bl*/
/*149c mov bl, byte ptr [si + 1]*/
/*149f mov bh, 0*/
/*14a1 shl bx, 1*/
/*14a3 mov bx, word ptr [bx + 0x10ff]*/
/*14a7 call 0x2121*/
/*14aa mov al, byte ptr [0x1b9c]*/
/*14ad cmp al, 0x11*/
/*14af jne 0x14b2*/
/*14b1 ret */
/*14b2 mov ax, word ptr [si + 5]*/
/*14b5 sub ax, word ptr [0x1b8f]*/
/*14b9 jns 0x14bd*/
/*14bb neg ax*/
/*14bd cmp ax, 0x10*/
/*14c0 jae 0x14ef*/
/*14c2 mov ax, word ptr [si + 7]*/
/*14c5 sub ax, word ptr [0x1b91]*/
/*14c9 sub ax, 8*/
/*14cc jns 0x14d0*/
/*14ce neg ax*/
/*14d0 cmp ax, 0x10*/
/*14d3 jae 0x14ef*/
/*14d5 mov al, 5*/
/*14d7 call 0x3840*/
/*14da sub word ptr [0], 0x64*/
/*14df mov byte ptr [0x12a0], 1*/
/*14e4 call 0x20f0*/
/*14e7 mov byte ptr [0x12a0], 5*/
/*14ec mov byte ptr [si], 0*/
/*14ef ret */
void sub_11429()
{
  sub_110c6();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_11433;
  return;
loc_11433:
  al = memoryAGet(ds, si + 1);
  
  if (al != 0x02) goto loc_11440;
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0005);
  goto loc_1146a;
loc_11440:
  
  if (al != 0x00) goto loc_1144a;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0005);
  goto loc_1146a;
loc_1144a:
  
  if (al != 0x01) goto loc_11458;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0003);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0002);
  goto loc_1146a;
loc_11458:
  
  if (al != 0x03) goto loc_11466;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0003);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0002);
  goto loc_1146a;
loc_11466:
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0005);
loc_1146a:
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  ax = memoryAGet16(ds, si + 5);
  
  if ((short)ax >= (short)0x000c) goto loc_1147b;
  memoryASet(ds, si, 0x00);
  return;
loc_1147b:
  
  if ((short)ax <= (short)0x00f4) goto loc_11484;
  memoryASet(ds, si, 0x00);
  return;
loc_11484:
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  ax = memoryAGet16(ds, si + 7);
  push(ax);
  sub_107fd();
  si = pop();
  al += 0x08;
  memoryASet(ds, si + 3, al);
  memoryASet(ds, si + 20, cl);
  memoryASet(ds, si + 4, bl);
  bl = memoryAGet(ds, si + 1);
  bh = 0x00;
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 4351);
  sub_12121();
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_114b2;
  return;
loc_114b2:
  ax = memoryAGet16(ds, si + 5);
  ax -= memoryAGet16(ds, 0x1b8f);
  if ((short)ax >= 0) goto loc_114bd;
  ax = -ax;
loc_114bd:
  
  if (ax >= 0x0010) goto loc_114ef;
  ax = memoryAGet16(ds, si + 7);
  ax -= memoryAGet16(ds, 0x1b91);
  ax -= 0x0008;
  if ((short)ax >= 0) goto loc_114d0;
  ax = -ax;
loc_114d0:
  
  if (ax >= 0x0010) goto loc_114ef;
  al = 0x05;
  sub_13840();
  memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x0064);
  memoryASet(ds, 0x12a0, 0x01);
  sub_120f0();
  memoryASet(ds, 0x12a0, 0x05);
  memoryASet(ds, si, 0x00);
loc_114ef:
  return;
}

/*14f0 add word ptr [si + 7], 1*/
/*14f4 push si*/
/*14f5 mov ax, word ptr [si + 5]*/
/*14f8 push ax*/
/*14f9 mov ax, word ptr [si + 7]*/
/*14fc push ax*/
/*14fd call 0x7fd*/
/*1500 pop si*/
/*1501 mov byte ptr [si + 3], al*/
/*1504 mov byte ptr [si + 0x14], cl*/
/*1507 mov byte ptr [si + 4], bl*/
/*150a mov bl, byte ptr [si + 1]*/
/*150d mov bh, 0*/
/*150f shl bx, 1*/
/*1511 mov bx, word ptr [bx + 0xfe1]*/
/*1515 call 0x2121*/
/*1518 mov al, byte ptr [0x1b9c]*/
/*151b cmp al, 0x11*/
/*151d je 0x1548*/
/*151f mov ax, word ptr [si + 5]*/
/*1522 sub ax, word ptr [0x1b8f]*/
/*1526 jns 0x152a*/
/*1528 neg ax*/
/*152a cmp ax, 0x1a*/
/*152d jae 0x1548*/
/*152f mov ax, word ptr [si + 7]*/
/*1532 sub ax, word ptr [0x1b91]*/
/*1536 jns 0x153a*/
/*1538 neg ax*/
/*153a cmp ax, 0x12*/
/*153d jae 0x1548*/
/*153f sub word ptr [0], 0xc*/
/*1544 mov byte ptr [si + 0x15], 0xff*/
/*1548 mov di, 0x1ba1*/
/*154b mov al, byte ptr [si + 0x15]*/
/*154e cmp al, 0*/
/*1550 jge 0x1561*/
/*1552 mov al, 7*/
/*1554 call 0x3840*/
/*1557 call 0x20f0*/
/*155a mov byte ptr [si], 0*/
/*155d call 0x2676*/
/*1560 ret */
/*1561 mov al, byte ptr [di]*/
/*1563 test al, 0x80*/
/*1565 jne 0x15c0*/
/*1567 test al, 0x40*/
/*1569 je 0x15bb*/
/*156b push di*/
/*156c mov ax, word ptr [di + 5]*/
/*156f sub ax, word ptr [si + 5]*/
/*1572 jns 0x1576*/
/*1574 neg ax*/
/*1576 cmp ax, 0x14*/
/*1579 jae 0x15ba*/
/*157b mov ax, word ptr [di + 7]*/
/*157e sub ax, word ptr [si + 7]*/
/*1581 jns 0x1585*/
/*1583 neg ax*/
/*1585 cmp ax, 0x10*/
/*1588 jae 0x15ba*/
/*158a mov al, byte ptr [di + 0x12]*/
/*158d cmp al, 0x19*/
/*158f jne 0x159a*/
/*1591 mov byte ptr [si + 0x15], 0xff*/
/*1595 mov byte ptr [di], 0*/
/*1598 jmp 0x15ba*/
/*159a mov al, byte ptr [di + 3]*/
/*159d sub al, byte ptr [si + 3]*/
/*15a0 jns 0x15a4*/
/*15a2 neg al*/
/*15a4 cmp al, 0x10*/
/*15a6 jae 0x15ba*/
/*15a8 dec byte ptr [si + 0x15]*/
/*15ab push si*/
/*15ac mov si, di*/
/*15ae call 0x2092*/
/*15b1 mov al, 3*/
/*15b3 call 0x3840*/
/*15b6 call 0x2662*/
/*15b9 pop si*/
/*15ba pop di*/
/*15bb add di, 0x17*/
/*15be jmp 0x154b*/
/*15c0 mov al, byte ptr [0x1b9c]*/
/*15c3 cmp al, 0x11*/
/*15c5 je 0x15f8*/
/*15c7 mov ax, word ptr [0x1b91]*/
/*15ca cmp ax, word ptr [si + 7]*/
/*15cd jbe 0x15f8*/
/*15cf mov ax, word ptr [0x1b8f]*/
/*15d2 sub ax, word ptr [si + 5]*/
/*15d5 jns 0x15d9*/
/*15d7 neg ax*/
/*15d9 cmp ax, 0x20*/
/*15dc jae 0x15f8*/
/*15de dec byte ptr [si + 0x16]*/
/*15e1 jns 0x15ee*/
/*15e3 mov byte ptr [si + 0x16], 7*/
/*15e7 mov byte ptr [0], 1*/
/*15ec jmp 0x15f3*/
/*15ee mov byte ptr [0], 0*/
/*15f3 push si*/
/*15f4 call 0x1def*/
/*15f7 pop si*/
/*15f8 call 0x10c6*/
/*15fb ret */
void sub_114f0()
{
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0001);
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  ax = memoryAGet16(ds, si + 7);
  push(ax);
  sub_107fd();
  si = pop();
  memoryASet(ds, si + 3, al);
  memoryASet(ds, si + 20, cl);
  memoryASet(ds, si + 4, bl);
  bl = memoryAGet(ds, si + 1);
  bh = 0x00;
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 4065);
  sub_12121();
  al = memoryAGet(ds, 0x1b9c);
  
  if (al == 0x11) goto loc_11548;
  ax = memoryAGet16(ds, si + 5);
  ax -= memoryAGet16(ds, 0x1b8f);
  if ((short)ax >= 0) goto loc_1152a;
  ax = -ax;
loc_1152a:
  
  if (ax >= 0x001a) goto loc_11548;
  ax = memoryAGet16(ds, si + 7);
  ax -= memoryAGet16(ds, 0x1b91);
  if ((short)ax >= 0) goto loc_1153a;
  ax = -ax;
loc_1153a:
  
  if (ax >= 0x0012) goto loc_11548;
  memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x000c);
  memoryASet(ds, si + 21, 0xff);
loc_11548:
  di = 0x1ba1;
loc_1154b:
  al = memoryAGet(ds, si + 21);
  
  if ((char)al >= (char)0x00) goto loc_11561;
  al = 0x07;
  sub_13840();
  sub_120f0();
  memoryASet(ds, si, 0x00);
  sub_12676();
  return;
loc_11561:
  al = memoryAGet(ds, di);
  
  if (!(al & 0x80)) goto loc_115c0;
  
  if (al & 0x40) goto loc_115bb;
  push(di);
  ax = memoryAGet16(ds, di + 5);
  ax -= memoryAGet16(ds, si + 5);
  if ((short)ax >= 0) goto loc_11576;
  ax = -ax;
loc_11576:
  
  if (ax >= 0x0014) goto loc_115ba;
  ax = memoryAGet16(ds, di + 7);
  ax -= memoryAGet16(ds, si + 7);
  if ((short)ax >= 0) goto loc_11585;
  ax = -ax;
loc_11585:
  
  if (ax >= 0x0010) goto loc_115ba;
  al = memoryAGet(ds, di + 18);
  
  if (al != 0x19) goto loc_1159a;
  memoryASet(ds, si + 21, 0xff);
  memoryASet(ds, di, 0x00);
  goto loc_115ba;
loc_1159a:
  al = memoryAGet(ds, di + 3);
  al -= memoryAGet(ds, si + 3);
  if ((char)al >= 0) goto loc_115a4;
  al = -al;
loc_115a4:
  
  if (al >= 0x10) goto loc_115ba;
  memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
  push(si);
  si = di;
  sub_12092();
  al = 0x03;
  sub_13840();
  sub_12662();
  si = pop();
loc_115ba:
  di = pop();
loc_115bb:
  di += 0x0017;
  goto loc_1154b;
loc_115c0:
  al = memoryAGet(ds, 0x1b9c);
  
  if (al == 0x11) goto loc_115f8;
  ax = memoryAGet16(ds, 0x1b91);
  
  if (ax <= memoryAGet16(ds, si + 7)) goto loc_115f8;
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  if ((short)ax >= 0) goto loc_115d9;
  ax = -ax;
loc_115d9:
  
  if (ax >= 0x0020) goto loc_115f8;
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
  if ((char)memoryAGet(ds, si + 22) >= 0) goto loc_115ee;
  memoryASet(ds, si + 22, 0x07);
  memoryASet(ds, 0x9518, 0x01);
  goto loc_115f3;
loc_115ee:
  memoryASet(ds, 0x9518, 0x00);
loc_115f3:
  push(si);
  sub_11def();
  si = pop();
loc_115f8:
  sub_110c6();
  return;
}

/*15fc call 0x10c6*/
/*15ff mov al, byte ptr [si]*/
/*1601 cmp al, 0*/
/*1603 jne 0x1606*/
/*1605 ret */
/*1606 mov al, byte ptr [si + 1]*/
/*1609 cmp al, 2*/
/*160b jne 0x1613*/
/*160d add word ptr [si + 7], 8*/
/*1611 jmp 0x163d*/
/*1613 cmp al, 0*/
/*1615 jne 0x161d*/
/*1617 sub word ptr [si + 5], 8*/
/*161b jmp 0x163d*/
/*161d cmp al, 1*/
/*161f jne 0x162b*/
/*1621 sub word ptr [si + 5], 6*/
/*1625 add word ptr [si + 7], 4*/
/*1629 jmp 0x163d*/
/*162b cmp al, 3*/
/*162d jne 0x1639*/
/*162f add word ptr [si + 5], 6*/
/*1633 add word ptr [si + 7], 4*/
/*1637 jmp 0x163d*/
/*1639 add word ptr [si + 5], 8*/
/*163d and word ptr [si + 7], 0x3ff*/
/*1642 mov ax, word ptr [si + 5]*/
/*1645 cmp ax, 4*/
/*1648 jge 0x164e*/
/*164a mov byte ptr [si], 0*/
/*164d ret */
/*164e cmp ax, 0xfc*/
/*1651 jle 0x1657*/
/*1653 mov byte ptr [si], 0*/
/*1656 ret */
/*1657 mov al, byte ptr [si + 4]*/
/*165a cmp al, 1*/
/*165c jne 0x166b*/
/*165e mov al, byte ptr [si + 3]*/
/*1661 cmp al, 0x64*/
/*1663 jge 0x1669*/
/*1665 add byte ptr [si + 3], 4*/
/*1669 jmp 0x167a*/
/*166b cmp al, 2*/
/*166d jne 0x167a*/
/*166f mov al, byte ptr [si + 3]*/
/*1672 cmp al, 0x9c*/
/*1674 jle 0x167a*/
/*1676 sub byte ptr [si + 3], 4*/
/*167a push si*/
/*167b mov ax, word ptr [si + 5]*/
/*167e push ax*/
/*167f mov ax, word ptr [si + 7]*/
/*1682 push ax*/
/*1683 call 0x7fd*/
/*1686 pop si*/
/*1687 cmp al, byte ptr [si + 3]*/
/*168a jl 0x1691*/
/*168c call 0x2092*/
/*168f jmp 0x16d5*/
/*1691 mov al, byte ptr [0x1b9c]*/
/*1694 cmp al, 0x11*/
/*1696 jne 0x1699*/
/*1698 ret */
/*1699 mov ax, word ptr [si + 5]*/
/*169c sub ax, word ptr [0x1b8f]*/
/*16a0 jns 0x16a4*/
/*16a2 neg ax*/
/*16a4 cmp ax, 0xc*/
/*16a7 jae 0x16d5*/
/*16a9 mov ax, word ptr [si + 7]*/
/*16ac sub ax, word ptr [0x1b91]*/
/*16b0 jns 0x16b4*/
/*16b2 neg ax*/
/*16b4 cmp ax, 8*/
/*16b7 jae 0x16d5*/
/*16b9 mov al, byte ptr [si + 3]*/
/*16bc sub al, byte ptr [0x1b8d]*/
/*16c0 jns 0x16c4*/
/*16c2 neg al*/
/*16c4 cmp al, 0x10*/
/*16c6 jae 0x16d5*/
/*16c8 sub word ptr [0], 1*/
/*16cd call 0x2092*/
/*16d0 mov al, 4*/
/*16d2 call 0x3840*/
/*16d5 ret */
void sub_115fc()
{
  sub_110c6();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_11606;
  return;
loc_11606:
  al = memoryAGet(ds, si + 1);
  
  if (al != 0x02) goto loc_11613;
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0008);
  goto loc_1163d;
loc_11613:
  
  if (al != 0x00) goto loc_1161d;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0008);
  goto loc_1163d;
loc_1161d:
  
  if (al != 0x01) goto loc_1162b;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0006);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
  goto loc_1163d;
loc_1162b:
  
  if (al != 0x03) goto loc_11639;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0006);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
  goto loc_1163d;
loc_11639:
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0008);
loc_1163d:
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  ax = memoryAGet16(ds, si + 5);
  
  if ((short)ax >= (short)0x0004) goto loc_1164e;
  memoryASet(ds, si, 0x00);
  return;
loc_1164e:
  
  if ((short)ax <= (short)0x00fc) goto loc_11657;
  memoryASet(ds, si, 0x00);
  return;
loc_11657:
  al = memoryAGet(ds, si + 4);
  
  if (al != 0x01) goto loc_1166b;
  al = memoryAGet(ds, si + 3);
  
  if ((char)al >= (char)0x64) goto loc_11669;
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + 0x04);
loc_11669:
  goto loc_1167a;
loc_1166b:
  
  if (al != 0x02) goto loc_1167a;
  al = memoryAGet(ds, si + 3);
  
  if ((char)al <= (char)0x9c) goto loc_1167a;
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 0x04);
loc_1167a:
  push(si);
  ax = memoryAGet16(ds, si + 5);
  push(ax);
  ax = memoryAGet16(ds, si + 7);
  push(ax);
  sub_107fd();
  si = pop();
  
  if ((char)al < (char)memoryAGet(ds, si + 3)) goto loc_11691;
  sub_12092();
  goto loc_116d5;
loc_11691:
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_11699;
  return;
loc_11699:
  ax = memoryAGet16(ds, si + 5);
  ax -= memoryAGet16(ds, 0x1b8f);
  if ((short)ax >= 0) goto loc_116a4;
  ax = -ax;
loc_116a4:
  
  if (ax >= 0x000c) goto loc_116d5;
  ax = memoryAGet16(ds, si + 7);
  ax -= memoryAGet16(ds, 0x1b91);
  if ((short)ax >= 0) goto loc_116b4;
  ax = -ax;
loc_116b4:
  
  if (ax >= 0x0008) goto loc_116d5;
  al = memoryAGet(ds, si + 3);
  al -= memoryAGet(ds, 0x1b8d);
  if ((char)al >= 0) goto loc_116c4;
  al = -al;
loc_116c4:
  
  if (al >= 0x10) goto loc_116d5;
  memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x0001);
  sub_12092();
  al = 0x04;
  sub_13840();
loc_116d5:
  return;
}

/*16d6 dec byte ptr [si + 4]*/
/*16d9 jns 0x16de*/
/*16db mov byte ptr [si], 0*/
/*16de ret */
void sub_116d6()
{
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
  if ((char)memoryAGet(ds, si + 4) >= 0) goto loc_116de;
  memoryASet(ds, si, 0x00);
loc_116de:
  return;
}

/*16df mov al, byte ptr [si + 4]*/
/*16e2 inc byte ptr [si + 4]*/
/*16e5 cmp al, 4*/
/*16e7 jb 0x16ed*/
/*16e9 mov byte ptr [si], 0*/
/*16ec ret */
/*16ed shl al, 1*/
/*16ef mov bl, al*/
/*16f1 mov bh, 0*/
/*16f3 mov ax, word ptr [bx + 0x143e]*/
/*16f7 mov word ptr [si + 0xf], ax*/
/*16fa call 0x10c6*/
/*16fd ret */
void sub_116df()
{
  al = memoryAGet(ds, si + 4);
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
  
  if (al < 0x04) goto loc_116ed;
  memoryASet(ds, si, 0x00);
  return;
loc_116ed:
  al <<= 0x01;
  bl = al;
  bh = 0x00;
  ax = memoryAGet16(ds, bx + 5182);
  memoryASet16(ds, si + 15, ax);
  sub_110c6();
  return;
}

/*16fe inc byte ptr [si + 0x16]*/
/*1701 mov al, byte ptr [si + 0x16]*/
/*1704 shr al, 1*/
/*1706 shr al, 1*/
/*1708 and al, 7*/
/*170a cmp al, 5*/
/*170c jl 0x1712*/
/*170e mov byte ptr [si], 0*/
/*1711 ret */
/*1712 mov byte ptr [si + 4], al*/
/*1715 mov bx, 0x12b5*/
/*1718 call 0x2121*/
/*171b call 0x10c6*/
/*171e ret */
void sub_116fe()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  al >>= 0x01;
  al >>= 0x01;
  al &= 0x07;
  
  if ((char)al < (char)0x05) goto loc_11712;
  memoryASet(ds, si, 0x00);
  return;
loc_11712:
  memoryASet(ds, si + 4, al);
  bx = 0x12b5;
  sub_12121();
  sub_110c6();
  return;
}

/*171f inc byte ptr [si + 0x16]*/
/*1722 mov al, byte ptr [si + 0x16]*/
/*1725 shr al, 1*/
/*1727 shr al, 1*/
/*1729 and al, 7*/
/*172b cmp al, 6*/
/*172d jl 0x1733*/
/*172f mov byte ptr [si], 0*/
/*1732 ret */
/*1733 mov byte ptr [si + 4], al*/
/*1736 mov bx, 0x12f5*/
/*1739 call 0x2121*/
/*173c call 0x10c6*/
/*173f ret */
void sub_1171f()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  al >>= 0x01;
  al >>= 0x01;
  al &= 0x07;
  
  if ((char)al < (char)0x06) goto loc_11733;
  memoryASet(ds, si, 0x00);
  return;
loc_11733:
  memoryASet(ds, si + 4, al);
  bx = 0x12f5;
  sub_12121();
  sub_110c6();
  return;
}

/*1740 inc byte ptr [si + 0x16]*/
/*1743 mov al, byte ptr [si + 0x16]*/
/*1746 and al, 7*/
/*1748 cmp al, 4*/
/*174a jl 0x1762*/
/*174c mov al, byte ptr [si]*/
/*174e test al, 0x20*/
/*1750 je 0x1759*/
/*1752 and byte ptr [0], 0x7f*/
/*1757 jmp 0x175e*/
/*1759 and byte ptr [0], 0xfe*/
/*175e mov byte ptr [si], 0*/
/*1761 ret */
/*1762 mov byte ptr [si + 4], al*/
/*1765 mov bx, 0x133d*/
/*1768 call 0x2121*/
/*176b ret */
void sub_11740()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  al &= 0x07;
  
  if ((char)al < (char)0x04) goto loc_11762;
  al = memoryAGet(ds, si);
  
  if (al & 0x20) goto loc_11759;
  memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) & 0x7f);
  goto loc_1175e;
loc_11759:
  memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) & 0xfe);
loc_1175e:
  memoryASet(ds, si, 0x00);
  return;
loc_11762:
  memoryASet(ds, si + 4, al);
  bx = 0x133d;
  sub_12121();
  return;
}

/*176c inc byte ptr [si + 0x16]*/
/*176f mov al, byte ptr [si + 0x16]*/
/*1772 shr al, 1*/
/*1774 and al, 3*/
/*1776 mov byte ptr [si + 4], al*/
/*1779 mov bx, 0xe2b*/
/*177c call 0x2121*/
/*177f call 0x10c6*/
/*1782 ret */
void sub_1176c()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  al >>= 0x01;
  al &= 0x03;
  memoryASet(ds, si + 4, al);
  bx = 0x0e2b;
  sub_12121();
  sub_110c6();
  return;
}

/*1783 inc byte ptr [si + 0x16]*/
/*1786 mov al, byte ptr [si + 0x16]*/
/*1789 shr al, 1*/
/*178b and al, 7*/
/*178d cmp al, 6*/
/*178f jb 0x1797*/
/*1791 mov al, 0*/
/*1793 mov byte ptr [si + 0x16], 0*/
/*1797 mov bl, al*/
/*1799 mov bh, 0*/
/*179b mov al, byte ptr [bx + 0xe4c]*/
/*179f mov byte ptr [si + 4], al*/
/*17a2 mov bx, 0xe52*/
/*17a5 call 0x2121*/
/*17a8 call 0x10c6*/
/*17ab ret */
void sub_11783()
{
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  al = memoryAGet(ds, si + 22);
  al >>= 0x01;
  al &= 0x07;
  
  if (al < 0x06) goto loc_11797;
  al = 0x00;
  memoryASet(ds, si + 22, 0x00);
loc_11797:
  bl = al;
  bh = 0x00;
  al = memoryAGet(ds, bx + 3660);
  memoryASet(ds, si + 4, al);
  bx = 0x0e52;
  sub_12121();
  sub_110c6();
  return;
}

/*17ac call 0x215b*/
/*17af cmp cx, 0*/
/*17b2 je 0x17cc*/
/*17b4 dec byte ptr [si + 0x16]*/
/*17b7 jns 0x17c4*/
/*17b9 mov byte ptr [si + 0x16], 8*/
/*17bd mov byte ptr [0], 1*/
/*17c2 jmp 0x17c9*/
/*17c4 mov byte ptr [0], 0*/
/*17c9 call 0x1f0b*/
/*17cc mov bx, 0xe73*/
/*17cf call 0x2121*/
/*17d2 call 0x10c6*/
/*17d5 ret */
void sub_117ac()
{
  sub_1215b();
  
  if (cx == 0x0000) goto loc_117cc;
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
  if ((char)memoryAGet(ds, si + 22) >= 0) goto loc_117c4;
  memoryASet(ds, si + 22, 0x08);
  memoryASet(ds, 0x9518, 0x01);
  goto loc_117c9;
loc_117c4:
  memoryASet(ds, 0x9518, 0x00);
loc_117c9:
  sub_11f0b();
loc_117cc:
  bx = 0x0e73;
  sub_12121();
  sub_110c6();
  return;
}

/*17d6 call 0x215b*/
/*17d9 cmp cx, 0*/
/*17dc je 0x17ea*/
/*17de dec byte ptr [si + 0x16]*/
/*17e1 jns 0x17ea*/
/*17e3 mov byte ptr [si + 0x16], 0x12*/
/*17e7 call 0x2005*/
/*17ea mov bx, 0xe9c*/
/*17ed call 0x2121*/
/*17f0 call 0x10c6*/
/*17f3 ret */
void sub_117d6()
{
  sub_1215b();
  
  if (cx == 0x0000) goto loc_117ea;
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
  if ((char)memoryAGet(ds, si + 22) >= 0) goto loc_117ea;
  memoryASet(ds, si + 22, 0x12);
  sub_12005();
loc_117ea:
  bx = 0x0e9c;
  sub_12121();
  sub_110c6();
  return;
}

/*17f4 call 0x10c6*/
/*17f7 mov al, byte ptr [si]*/
/*17f9 cmp al, 0*/
/*17fb jne 0x17fe*/
/*17fd ret */
/*17fe mov al, byte ptr [si + 1]*/
/*1801 cmp al, 2*/
/*1803 jne 0x180b*/
/*1805 add word ptr [si + 7], 3*/
/*1809 jmp 0x1835*/
/*180b cmp al, 0*/
/*180d jne 0x1815*/
/*180f sub word ptr [si + 5], 4*/
/*1813 jmp 0x1835*/
/*1815 cmp al, 1*/
/*1817 jne 0x1823*/
/*1819 sub word ptr [si + 5], 4*/
/*181d add word ptr [si + 7], 3*/
/*1821 jmp 0x1835*/
/*1823 cmp al, 3*/
/*1825 jne 0x1831*/
/*1827 add word ptr [si + 5], 4*/
/*182b add word ptr [si + 7], 3*/
/*182f jmp 0x1835*/
/*1831 add word ptr [si + 5], 4*/
/*1835 and word ptr [si + 7], 0x3ff*/
/*183a mov ax, word ptr [si + 5]*/
/*183d cmp ax, 8*/
/*1840 jge 0x1846*/
/*1842 mov byte ptr [si], 0*/
/*1845 ret */
/*1846 cmp ax, 0xf8*/
/*1849 jle 0x184f*/
/*184b mov byte ptr [si], 0*/
/*184e ret */
/*184f inc byte ptr [si + 0x16]*/
/*1852 mov bl, byte ptr [si + 0x16]*/
/*1855 cmp bl, 0x10*/
/*1858 jb 0x185e*/
/*185a call 0x2099*/
/*185d ret */
/*185e mov bh, 0*/
/*1860 mov al, byte ptr [bx + 0x1467]*/
/*1864 add byte ptr [si + 3], al*/
/*1867 mov al, byte ptr [0x1b9c]*/
/*186a cmp al, 0x11*/
/*186c jne 0x186f*/
/*186e ret */
/*186f mov ax, word ptr [si + 5]*/
/*1872 sub ax, word ptr [0x1b8f]*/
/*1876 jns 0x187a*/
/*1878 neg ax*/
/*187a cmp ax, 0xe*/
/*187d jae 0x18a8*/
/*187f mov ax, word ptr [si + 7]*/
/*1882 sub ax, word ptr [0x1b91]*/
/*1886 jns 0x188a*/
/*1888 neg ax*/
/*188a cmp ax, 0xa*/
/*188d jae 0x18a8*/
/*188f mov al, byte ptr [si + 3]*/
/*1892 sub al, byte ptr [0x1b8d]*/
/*1896 jns 0x189a*/
/*1898 neg al*/
/*189a cmp al, 0x10*/
/*189c jae 0x18a8*/
/*189e sub word ptr [0], 0xa*/
/*18a3 mov al, 5*/
/*18a5 call 0x3840*/
/*18a8 ret */
void sub_117f4()
{
  sub_110c6();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_117fe;
  return;
loc_117fe:
  al = memoryAGet(ds, si + 1);
  
  if (al != 0x02) goto loc_1180b;
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
  goto loc_11835;
loc_1180b:
  
  if (al != 0x00) goto loc_11815;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0004);
  goto loc_11835;
loc_11815:
  
  if (al != 0x01) goto loc_11823;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0004);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
  goto loc_11835;
loc_11823:
  
  if (al != 0x03) goto loc_11831;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0004);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
  goto loc_11835;
loc_11831:
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0004);
loc_11835:
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  ax = memoryAGet16(ds, si + 5);
  
  if ((short)ax >= (short)0x0008) goto loc_11846;
  memoryASet(ds, si, 0x00);
  return;
loc_11846:
  
  if ((short)ax <= (short)0x00f8) goto loc_1184f;
  memoryASet(ds, si, 0x00);
  return;
loc_1184f:
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
  bl = memoryAGet(ds, si + 22);
  
  if (bl < 0x10) goto loc_1185e;
  sub_12099();
  return;
loc_1185e:
  bh = 0x00;
  al = memoryAGet(ds, bx + 5223);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + al);
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_1186f;
  return;
loc_1186f:
  ax = memoryAGet16(ds, si + 5);
  ax -= memoryAGet16(ds, 0x1b8f);
  if ((short)ax >= 0) goto loc_1187a;
  ax = -ax;
loc_1187a:
  
  if (ax >= 0x000e) goto loc_118a8;
  ax = memoryAGet16(ds, si + 7);
  ax -= memoryAGet16(ds, 0x1b91);
  if ((short)ax >= 0) goto loc_1188a;
  ax = -ax;
loc_1188a:
  
  if (ax >= 0x000a) goto loc_118a8;
  al = memoryAGet(ds, si + 3);
  al -= memoryAGet(ds, 0x1b8d);
  if ((char)al >= 0) goto loc_1189a;
  al = -al;
loc_1189a:
  
  if (al >= 0x10) goto loc_118a8;
  memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x000a);
  al = 0x05;
  sub_13840();
loc_118a8:
  return;
}

/*18a9 call 0x215b*/
/*18ac cmp cx, 0*/
/*18af je 0x18bd*/
/*18b1 dec byte ptr [si + 0x16]*/
/*18b4 jns 0x18bd*/
/*18b6 mov byte ptr [si + 0x16], 0x28*/
/*18ba call 0x1fba*/
/*18bd mov bx, 0xec5*/
/*18c0 call 0x2121*/
/*18c3 call 0x10c6*/
/*18c6 ret */
void sub_118a9()
{
  sub_1215b();
  
  if (cx == 0x0000) goto loc_118bd;
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
  if ((char)memoryAGet(ds, si + 22) >= 0) goto loc_118bd;
  memoryASet(ds, si + 22, 0x28);
  sub_11fba();
loc_118bd:
  bx = 0x0ec5;
  sub_12121();
  sub_110c6();
  return;
}

/*18c7 mov al, byte ptr [0x952e]*/
/*18ca and al, byte ptr [0]*/
/*18ce and al, byte ptr [0]*/
/*18d2 and al, byte ptr [0]*/
/*18d6 and al, byte ptr [0]*/
/*18da and al, byte ptr [0]*/
/*18de jne 0x18e4*/
/*18e0 call 0x10c6*/
/*18e3 ret */
/*18e4 mov ax, word ptr [0x1b8f]*/
/*18e7 sub ax, word ptr [si + 5]*/
/*18ea sub ax, 0xc*/
/*18ed jns 0x18f1*/
/*18ef neg ax*/
/*18f1 mov cx, word ptr [0x1b91]*/
/*18f5 sub cx, 8*/
/*18f8 sub cx, word ptr [si + 7]*/
/*18fb jns 0x18ff*/
/*18fd neg cx*/
/*18ff mov bl, byte ptr [si + 4]*/
/*1902 shr bl, 1*/
/*1904 add ax, cx*/
/*1906 cmp ax, 0x40*/
/*1909 ja 0x1915*/
/*190b cmp bl, 8*/
/*190e je 0x1913*/
/*1910 inc byte ptr [si + 4]*/
/*1913 jmp 0x191d*/
/*1915 cmp bl, 0*/
/*1918 je 0x191d*/
/*191a dec byte ptr [si + 4]*/
/*191d push bx*/
/*191e mov bh, 0*/
/*1920 shl bx, 1*/
/*1922 mov ax, word ptr [bx + 0x1483]*/
/*1926 mov word ptr [si + 0xf], ax*/
/*1929 pop bx*/
/*192a cmp bl, 2*/
/*192d jb 0x196b*/
/*192f mov ax, word ptr [0x1b8f]*/
/*1932 sub ax, word ptr [si + 5]*/
/*1935 sub ax, 0xc*/
/*1938 jns 0x1947*/
/*193a neg ax*/
/*193c cmp ax, 0x18*/
/*193f ja 0x1945*/
/*1941 inc word ptr [0x1b8f]*/
/*1945 jmp 0x1952*/
/*1947 je 0x1952*/
/*1949 cmp ax, 0x18*/
/*194c ja 0x1952*/
/*194e dec word ptr [0x1b8f]*/
/*1952 cmp bl, 8*/
/*1955 jne 0x196b*/
/*1957 cmp cx, 8*/
/*195a ja 0x196b*/
/*195c cmp ax, 8*/
/*195f ja 0x196b*/
/*1961 mov al, byte ptr [0x1b9c]*/
/*1964 cmp al, 0x11*/
/*1966 je 0x196b*/
/*1968 call 0x196f*/
/*196b call 0x10c6*/
/*196e ret */
void sub_118c7()
{
  al = memoryAGet(ds, 0x952e);
  al &= memoryAGet(ds, 0x952f);
  al &= memoryAGet(ds, 0x9530);
  al &= memoryAGet(ds, 0x9531);
  al &= memoryAGet(ds, 0x9532);
  al &= memoryAGet(ds, 0x9533);
  if (al) goto loc_118e4;
  sub_110c6();
  return;
loc_118e4:
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  ax -= 0x000c;
  if ((short)ax >= 0) goto loc_118f1;
  ax = -ax;
loc_118f1:
  cx = memoryAGet16(ds, 0x1b91);
  cx -= 0x0008;
  cx -= memoryAGet16(ds, si + 7);
  if ((short)cx >= 0) goto loc_118ff;
  cx = -cx;
loc_118ff:
  bl = memoryAGet(ds, si + 4);
  bl >>= 0x01;
  ax += cx;
  
  if (ax > 0x0040) goto loc_11915;
  
  if (bl == 0x08) goto loc_11913;
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
loc_11913:
  goto loc_1191d;
loc_11915:
  
  if (bl == 0x00) goto loc_1191d;
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
loc_1191d:
  push(bx);
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5251);
  memoryASet16(ds, si + 15, ax);
  bx = pop();
  
  if (bl < 0x02) goto loc_1196b;
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  ax -= 0x000c;
  if ((short)ax >= 0) goto loc_11947;
  ax = -ax;
  
  if (ax > 0x0018) goto loc_11945;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11945:
  goto loc_11952;
loc_11947:
  if (!ax) goto loc_11952;
  
  if (ax > 0x0018) goto loc_11952;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11952:
  
  if (bl != 0x08) goto loc_1196b;
  
  if (cx > 0x0008) goto loc_1196b;
  
  if (ax > 0x0008) goto loc_1196b;
  al = memoryAGet(ds, 0x1b9c);
  
  if (al == 0x11) goto loc_1196b;
  sub_1196f();
loc_1196b:
  sub_110c6();
  return;
}

/*196f mov al, byte ptr [0x1b8e]*/
/*1972 cmp al, 0*/
/*1974 jne 0x1982*/
/*1976 mov byte ptr [0], 0xf0*/
/*197b mov byte ptr [0], 1*/
/*1980 jmp 0x1992*/
/*1982 push si*/
/*1983 mov byte ptr [0x1b8e], 0*/
/*1988 mov si, 0x1b8a*/
/*198b mov bx, 0xd49*/
/*198e call 0x2121*/
/*1991 pop si*/
/*1992 ret */
void sub_1196f()
{
  al = memoryAGet(ds, 0x1b8e);
  
  if (al != 0x00) goto loc_11982;
  memoryASet(ds, 0x951d, 0xf0);
  memoryASet(ds, 0x94ff, 0x01);
  goto loc_11992;
loc_11982:
  push(si);
  memoryASet(ds, 0x1b8e, 0x00);
  si = 0x1b8a;
  bx = 0x0d49;
  sub_12121();
  si = pop();
loc_11992:
  return;
}

/*1993 call 0x1a04*/
/*1996 mov al, byte ptr [0x94ff]*/
/*1999 cmp al, 1*/
/*199b jne 0x19c1*/
/*199d mov al, byte ptr [0x9501]*/
/*19a0 mov bl, al*/
/*19a2 shl al, 1*/
/*19a4 add bl, al*/
/*19a6 add bl, byte ptr [0]*/
/*19aa mov bh, 0*/
/*19ac shl bx, 1*/
/*19ae mov ax, word ptr [bx + 0x1495]*/
/*19b2 mov bh, ah*/
/*19b4 and ax, 0x3ff*/
/*19b7 mov word ptr [0x950c], ax*/
/*19ba and bh, 0xc0*/
/*19bd mov byte ptr [0], bh*/
/*19c1 ret */
void sub_11993()
{
  sub_11a04();
  al = memoryAGet(ds, 0x94ff);
  
  if (al != 0x01) goto loc_119c1;
  al = memoryAGet(ds, 0x9501);
  bl = al;
  al <<= 0x01;
  bl += al;
  bl += memoryAGet(ds, 0x9502);
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5269);
  bh = ah;
  ax &= 0x03ff;
  memoryASet16(ds, 0x950c, ax);
  bh &= 0xc0;
  memoryASet(ds, 0x951d, bh);
loc_119c1:
  return;
}

/*19c2 call 0x1a04*/
/*19c5 mov al, byte ptr [0x94ff]*/
/*19c8 cmp al, 1*/
/*19ca jne 0x1a03*/
/*19cc mov al, byte ptr [0x9501]*/
/*19cf mov bl, al*/
/*19d1 shl al, 1*/
/*19d3 add bl, al*/
/*19d5 add bl, byte ptr [0]*/
/*19d9 mov bh, 0*/
/*19db shl bx, 1*/
/*19dd mov ax, word ptr [bx + 0x14c5]*/
/*19e1 mov bh, ah*/
/*19e3 and ax, 0x3ff*/
/*19e6 mov word ptr [0x950c], ax*/
/*19e9 and bh, 0xc0*/
/*19ec mov byte ptr [0], bh*/
/*19f0 mov byte ptr [0], 1*/
/*19f5 mov al, byte ptr [0x9502]*/
/*19f8 inc al*/
/*19fa cmp al, 2*/
/*19fc jbe 0x1a00*/
/*19fe mov al, 0*/
/*1a00 mov byte ptr [0x9502], al*/
/*1a03 ret */
void sub_119c2()
{
  sub_11a04();
  al = memoryAGet(ds, 0x94ff);
  
  if (al != 0x01) goto loc_11a03;
  al = memoryAGet(ds, 0x9501);
  bl = al;
  al <<= 0x01;
  bl += al;
  bl += memoryAGet(ds, 0x9502);
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5317);
  bh = ah;
  ax &= 0x03ff;
  memoryASet16(ds, 0x950c, ax);
  bh &= 0xc0;
  memoryASet(ds, 0x951d, bh);
  memoryASet(ds, 0x950e, 0x01);
  al = memoryAGet(ds, 0x9502);
  al++;
  
  if (al <= 0x02) goto loc_11a00;
  al = 0x00;
loc_11a00:
  memoryASet(ds, 0x9502, al);
loc_11a03:
  return;
}

/*1a04 mov ax, word ptr [0x1b8f]*/
/*1a07 sub ax, word ptr [si + 5]*/
/*1a0a sub ax, 0xc*/
/*1a0d jns 0x1a11*/
/*1a0f neg ax*/
/*1a11 mov cx, word ptr [0x1b91]*/
/*1a15 sub cx, word ptr [si + 7]*/
/*1a18 jns 0x1a1c*/
/*1a1a neg cx*/
/*1a1c mov bl, byte ptr [si + 4]*/
/*1a1f shr bl, 1*/
/*1a21 add ax, cx*/
/*1a23 cmp ax, 0x40*/
/*1a26 ja 0x1a32*/
/*1a28 cmp bl, 6*/
/*1a2b je 0x1a30*/
/*1a2d inc byte ptr [si + 4]*/
/*1a30 jmp 0x1a3a*/
/*1a32 cmp bl, 0*/
/*1a35 je 0x1a3a*/
/*1a37 dec byte ptr [si + 4]*/
/*1a3a cmp bl, 6*/
/*1a3d jne 0x1a45*/
/*1a3f mov byte ptr [si + 2], 0*/
/*1a43 jmp 0x1a56*/
/*1a45 push bx*/
/*1a46 mov byte ptr [si + 2], 7*/
/*1a4a mov bh, 0*/
/*1a4c shl bx, 1*/
/*1a4e mov ax, word ptr [bx + 0x1477]*/
/*1a52 mov word ptr [si + 0xf], ax*/
/*1a55 pop bx*/
/*1a56 cmp bl, 1*/
/*1a59 jb 0x1a9a*/
/*1a5b mov ax, word ptr [0x1b8f]*/
/*1a5e sub ax, word ptr [si + 5]*/
/*1a61 sub ax, 0xc*/
/*1a64 jns 0x1a73*/
/*1a66 neg ax*/
/*1a68 cmp ax, 0x18*/
/*1a6b ja 0x1a71*/
/*1a6d inc word ptr [0x1b8f]*/
/*1a71 jmp 0x1a7e*/
/*1a73 je 0x1a7e*/
/*1a75 cmp ax, 0x18*/
/*1a78 ja 0x1a7e*/
/*1a7a dec word ptr [0x1b8f]*/
/*1a7e cmp cx, 8*/
/*1a81 ja 0x1a9a*/
/*1a83 cmp ax, 8*/
/*1a86 ja 0x1a9a*/
/*1a88 mov al, byte ptr [0x1b9c]*/
/*1a8b cmp al, 0x11*/
/*1a8d je 0x1a9a*/
/*1a8f mov ax, word ptr [0x1b8f]*/
/*1a92 mov word ptr [0x950a], ax*/
/*1a95 mov byte ptr [0], 1*/
/*1a9a call 0x10c6*/
/*1a9d ret */
void sub_11a04()
{
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  ax -= 0x000c;
  if ((short)ax >= 0) goto loc_11a11;
  ax = -ax;
loc_11a11:
  cx = memoryAGet16(ds, 0x1b91);
  cx -= memoryAGet16(ds, si + 7);
  if ((short)cx >= 0) goto loc_11a1c;
  cx = -cx;
loc_11a1c:
  bl = memoryAGet(ds, si + 4);
  bl >>= 0x01;
  ax += cx;
  
  if (ax > 0x0040) goto loc_11a32;
  
  if (bl == 0x06) goto loc_11a30;
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
loc_11a30:
  goto loc_11a3a;
loc_11a32:
  
  if (bl == 0x00) goto loc_11a3a;
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
loc_11a3a:
  
  if (bl != 0x06) goto loc_11a45;
  memoryASet(ds, si + 2, 0x00);
  goto loc_11a56;
loc_11a45:
  push(bx);
  memoryASet(ds, si + 2, 0x07);
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5239);
  memoryASet16(ds, si + 15, ax);
  bx = pop();
loc_11a56:
  
  if (bl < 0x01) goto loc_11a9a;
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  ax -= 0x000c;
  if ((short)ax >= 0) goto loc_11a73;
  ax = -ax;
  
  if (ax > 0x0018) goto loc_11a71;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11a71:
  goto loc_11a7e;
loc_11a73:
  if (!ax) goto loc_11a7e;
  
  if (ax > 0x0018) goto loc_11a7e;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11a7e:
  
  if (cx > 0x0008) goto loc_11a9a;
  
  if (ax > 0x0008) goto loc_11a9a;
  al = memoryAGet(ds, 0x1b9c);
  
  if (al == 0x11) goto loc_11a9a;
  ax = memoryAGet16(ds, 0x1b8f);
  memoryASet16(ds, 0x950a, ax);
  memoryASet(ds, 0x94ff, 0x01);
loc_11a9a:
  sub_110c6();
  return;
}

/*1a9e call 0x10c6*/
/*1aa1 mov al, byte ptr [si]*/
/*1aa3 cmp al, 0*/
/*1aa5 jne 0x1aa8*/
/*1aa7 ret */
/*1aa8 mov bx, word ptr [0x1b91]*/
/*1aac sub bx, word ptr [si + 7]*/
/*1aaf jns 0x1abb*/
/*1ab1 cmp bx, -0x10*/
/*1ab4 jge 0x1aba*/
/*1ab6 mov byte ptr [si + 2], 1*/
/*1aba ret */
/*1abb cmp bx, 0x20*/
/*1abe jle 0x1ac1*/
/*1ac0 ret */
/*1ac1 mov ax, word ptr [0x1b8f]*/
/*1ac4 sub ax, word ptr [si + 5]*/
/*1ac7 sub ax, 0xc*/
/*1aca jns 0x1ad9*/
/*1acc neg ax*/
/*1ace cmp ax, 0x18*/
/*1ad1 jae 0x1ad7*/
/*1ad3 inc word ptr [0x1b8f]*/
/*1ad7 jmp 0x1ae7*/
/*1ad9 cmp ax, 0x18*/
/*1adc jae 0x1ae7*/
/*1ade cmp ax, 0*/
/*1ae1 je 0x1ae7*/
/*1ae3 dec word ptr [0x1b8f]*/
/*1ae7 cmp bx, 8*/
/*1aea jbe 0x1aed*/
/*1aec ret */
/*1aed cmp ax, 2*/
/*1af0 ja 0x1af8*/
/*1af2 inc word ptr [0]*/
/*1af6 jmp 0x1b08*/
/*1af8 cmp ax, 0x24*/
/*1afb jae 0x1b08*/
/*1afd mov word ptr [0], 0*/
/*1b03 mov al, 6*/
/*1b05 call 0x3840*/
/*1b08 ret */
void sub_11a9e()
{
  sub_110c6();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_11aa8;
  return;
loc_11aa8:
  bx = memoryAGet16(ds, 0x1b91);
  bx -= memoryAGet16(ds, si + 7);
  if ((short)bx >= 0) goto loc_11abb;
  
  if ((short)bx >= (short)0xfff0) goto loc_11aba;
  memoryASet(ds, si + 2, 0x01);
loc_11aba:
  return;
loc_11abb:
  
  if ((short)bx <= (short)0x0020) goto loc_11ac1;
  return;
loc_11ac1:
  ax = memoryAGet16(ds, 0x1b8f);
  ax -= memoryAGet16(ds, si + 5);
  ax -= 0x000c;
  if ((short)ax >= 0) goto loc_11ad9;
  ax = -ax;
  
  if (ax >= 0x0018) goto loc_11ad7;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11ad7:
  goto loc_11ae7;
loc_11ad9:
  
  if (ax >= 0x0018) goto loc_11ae7;
  
  if (ax == 0x0000) goto loc_11ae7;
  memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11ae7:
  
  if (bx <= 0x0008) goto loc_11aed;
  return;
loc_11aed:
  
  if (ax > 0x0002) goto loc_11af8;
  memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) + 1);
  goto loc_11b08;
loc_11af8:
  
  if (ax >= 0x0024) goto loc_11b08;
  memoryASet16(ds, 0x9542, 0x0000);
  al = 0x06;
  sub_13840();
loc_11b08:
  return;
}

/*1b09 call 0x10c6*/
/*1b0c mov al, byte ptr [si]*/
/*1b0e cmp al, 0*/
/*1b10 jne 0x1b13*/
/*1b12 ret */
/*1b13 mov al, byte ptr [0x1b9c]*/
/*1b16 cmp al, 0x11*/
/*1b18 jne 0x1b1b*/
/*1b1a ret */
/*1b1b mov ax, word ptr [si + 5]*/
/*1b1e sub ax, word ptr [0x1b8f]*/
/*1b22 jns 0x1b26*/
/*1b24 neg ax*/
/*1b26 cmp ax, 0x12*/
/*1b29 jae 0x1b49*/
/*1b2b mov ax, word ptr [si + 7]*/
/*1b2e sub ax, word ptr [0x1b91]*/
/*1b32 jns 0x1b36*/
/*1b34 neg ax*/
/*1b36 cmp ax, 0x10*/
/*1b39 jae 0x1b49*/
/*1b3b mov byte ptr [si], 0*/
/*1b3e mov al, byte ptr [si + 1]*/
/*1b41 call 0x2b28*/
/*1b44 mov al, 0xa*/
/*1b46 call 0x3840*/
/*1b49 ret */
void sub_11b09()
{
  sub_110c6();
  al = memoryAGet(ds, si);
  
  if (al != 0x00) goto loc_11b13;
  return;
loc_11b13:
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_11b1b;
  return;
loc_11b1b:
  ax = memoryAGet16(ds, si + 5);
  ax -= memoryAGet16(ds, 0x1b8f);
  if ((short)ax >= 0) goto loc_11b26;
  ax = -ax;
loc_11b26:
  
  if (ax >= 0x0012) goto loc_11b49;
  ax = memoryAGet16(ds, si + 7);
  ax -= memoryAGet16(ds, 0x1b91);
  if ((short)ax >= 0) goto loc_11b36;
  ax = -ax;
loc_11b36:
  
  if (ax >= 0x0010) goto loc_11b49;
  memoryASet(ds, si, 0x00);
  al = memoryAGet(ds, si + 1);
  sub_12b28();
  al = 0x0a;
  sub_13840();
loc_11b49:
  return;
}

/*1b4a sub word ptr [si + 7], 2*/
/*1b4e and word ptr [si + 7], 0x3ff*/
/*1b53 call 0x10a0*/
/*1b56 ret */
void sub_11b4a()
{
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0002);
  memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
  sub_110a0();
  return;
}

/*1b57 mov ax, word ptr [0x1b8f]*/
/*1b5a push ax*/
/*1b5b mov ax, word ptr [0x9528]*/
/*1b5e add ax, 0x70*/
/*1b61 and ax, 0x3ff*/
/*1b64 mov word ptr [0x1b91], ax*/
/*1b67 push ax*/
/*1b68 call 0x7fd*/
/*1b6b mov byte ptr [0x1b8d], al*/
/*1b6e mov byte ptr [0x1b9e], cl*/
/*1b72 mov byte ptr [0x1b8e], bl*/
/*1b76 mov si, 0x1b8a*/
/*1b79 mov bx, 0xd49*/
/*1b7c call 0x2121*/
/*1b7f ret */
void sub_11b57()
{
  ax = memoryAGet16(ds, 0x1b8f);
  push(ax);
  ax = memoryAGet16(ds, 0x9528);
  ax += 0x0070;
  ax &= 0x03ff;
  memoryASet16(ds, 0x1b91, ax);
  push(ax);
  sub_107fd();
  memoryASet(ds, 0x1b8d, al);
  memoryASet(ds, 0x1b9e, cl);
  memoryASet(ds, 0x1b8e, bl);
  si = 0x1b8a;
  bx = 0x0d49;
  sub_12121();
  return;
}

/*1b80 mov bx, word ptr [0]*/
/*1b84 mov ax, word ptr [0x953a]*/
/*1b87 cmp ax, 0*/
/*1b8a jg 0x1b91*/
/*1b8c mov ax, 8*/
/*1b8f jmp 0x1b94*/
/*1b91 mov ax, word ptr [0x954c]*/
/*1b94 test al, 4*/
/*1b96 je 0x1ba3*/
/*1b98 inc bx*/
/*1b99 cmp bx, 0x40*/
/*1b9c jle 0x1ba1*/
/*1b9e mov bx, 0x40*/
/*1ba1 jmp 0x1bb4*/
/*1ba3 test al, 8*/
/*1ba5 je 0x1bb4*/
/*1ba7 sub bx, 2*/
/*1baa cmp bx, word ptr [0]*/
/*1bae jge 0x1bb4*/
/*1bb0 mov bx, word ptr [0]*/
/*1bb4 mov word ptr [0], bx*/
/*1bb8 ret */
void sub_11b80()
{
  bx = memoryAGet16(ds, 0x952a);
  ax = memoryAGet16(ds, 0x953a);
  
  if ((short)ax > (short)0x0000) goto loc_11b91;
  ax = 0x0008;
  goto loc_11b94;
loc_11b91:
  ax = memoryAGet16(ds, 0x954c);
loc_11b94:
  
  if (al & 0x04) goto loc_11ba3;
  bx++;
  
  if ((short)bx <= (short)0x0040) goto loc_11ba1;
  bx = 0x0040;
loc_11ba1:
  goto loc_11bb4;
loc_11ba3:
  
  if (al & 0x08) goto loc_11bb4;
  bx -= 0x0002;
  
  if ((short)bx >= (short)memoryAGet16(ds, 0x94fc)) goto loc_11bb4;
  bx = memoryAGet16(ds, 0x94fc);
loc_11bb4:
  memoryASet16(ds, 0x952a, bx);
  return;
}

/*1bb9 mov bx, word ptr [0]*/
/*1bbd add bx, 0xf*/
/*1bc0 shr bx, 1*/
/*1bc2 shr bx, 1*/
/*1bc4 shr bx, 1*/
/*1bc6 mov ax, bx*/
/*1bc8 dec ax*/
/*1bc9 shr bx, 1*/
/*1bcb add ax, word ptr [0]*/
/*1bcf cmp ax, 0x8b*/
/*1bd2 jbe 0x1bdd*/
/*1bd4 mov ax, 0*/
/*1bd7 mov word ptr [0], 0xffff*/
/*1bdd mov word ptr [0x950f], ax*/
/*1be0 mov ax, word ptr [0x9528]*/
/*1be3 sub ax, bx*/
/*1be5 and ax, 0x3ff*/
/*1be8 mov word ptr [0x9528], ax*/
/*1beb mov ax, word ptr [0x9528]*/
/*1bee shr ax, 1*/
/*1bf0 shr ax, 1*/
/*1bf2 shr ax, 1*/
/*1bf4 shr ax, 1*/
/*1bf6 sub ax, 3*/
/*1bf9 and ax, 0x3f*/
/*1bfc cmp ax, word ptr [0]*/
/*1c00 je 0x1c09*/
/*1c02 mov word ptr [0x9507], ax*/
/*1c05 push ax*/
/*1c06 call 0x8ba*/
/*1c09 ret */
void sub_11bb9()
{
  bx = memoryAGet16(ds, 0x952a);
  bx += 0x000f;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  ax = bx;
  ax--;
  bx >>= 0x0001;
  ax += memoryAGet16(ds, 0x950f);
  
  if (ax <= 0x008b) goto loc_11bdd;
  ax = 0x0000;
  memoryASet16(ds, 0x953c, 0xffff);
loc_11bdd:
  memoryASet16(ds, 0x950f, ax);
  ax = memoryAGet16(ds, 0x9528);
  ax -= bx;
  ax &= 0x03ff;
  memoryASet16(ds, 0x9528, ax);
  ax = memoryAGet16(ds, 0x9528);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax -= 0x0003;
  ax &= 0x003f;
  
  if (ax == memoryAGet16(ds, 0x9507)) goto loc_11c09;
  memoryASet16(ds, 0x9507, ax);
  push(ax);
  sub_108ba();
loc_11c09:
  return;
}

/*1c0a push bp*/
/*1c0b mov bp, sp*/
/*1c0d mov bx, word ptr [bp + 6]*/
/*1c10 mov cx, word ptr [bp + 4]*/
/*1c13 mov si, 0x1b8a*/
/*1c16 mov al, byte ptr [si]*/
/*1c18 test al, 0x80*/
/*1c1a jne 0x1c2f*/
/*1c1c test al, 8*/
/*1c1e je 0x1c2a*/
/*1c20 cmp cl, byte ptr [si + 0x14]*/
/*1c23 jne 0x1c2a*/
/*1c25 cmp bl, byte ptr [si + 0x13]*/
/*1c28 je 0x1c2f*/
/*1c2a add si, 0x17*/
/*1c2d jmp 0x1c16*/
/*1c2f pop bp*/
/*1c30 ret 4*/
void sub_11c0a()
{
  push(bp);
  bp = sp;
  bx = memoryAGet16(ss, bp + 6 - 2);
  cx = memoryAGet16(ss, bp + 4 - 2);
  si = 0x1b8a;
loc_11c16:
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_11c2f;
  
  if (al & 0x08) goto loc_11c2a;
  
  if (cl != memoryAGet(ds, si + 20)) goto loc_11c2a;
  
  if (bl == memoryAGet(ds, si + 19)) goto loc_11c2f;
loc_11c2a:
  si += 0x0017;
  goto loc_11c16;
loc_11c2f:
  bp = pop();
  return;
}

/*1c33 mov al, byte ptr [0x1b9c]*/
/*1c36 cmp al, 0x11*/
/*1c38 jne 0x1c3b*/
/*1c3a ret */
/*1c3b mov al, 0xc*/
/*1c3d call 0x3840*/
/*1c40 mov si, 0x1b8a*/
/*1c43 call 0x20f0*/
/*1c46 mov byte ptr [0x1b9c], 0x11*/
/*1c4b mov byte ptr [0x1b8c], 0*/
/*1c50 mov byte ptr [0], 0*/
/*1c55 ret */
void sub_11c33()
{
  al = memoryAGet(ds, 0x1b9c);
  
  if (al != 0x11) goto loc_11c3b;
  return;
loc_11c3b:
  al = 0x0c;
  sub_13840();
  si = 0x1b8a;
  sub_120f0();
  memoryASet(ds, 0x1b9c, 0x11);
  memoryASet(ds, 0x1b8c, 0x00);
  memoryASet(ds, 0x9514, 0x00);
  return;
}

/*1c56 neg ax*/
/*1c58 mov word ptr [0x9544], ax*/
/*1c5b push ax*/
/*1c5c mov al, 6*/
/*1c5e call 0x3840*/
/*1c61 pop ax*/
/*1c62 mov ax, bx*/
/*1c64 push ax*/
/*1c65 mov al, byte ptr [0x1b9e]*/
/*1c68 mov ah, 0*/
/*1c6a push ax*/
/*1c6b call 0x1c0a*/
/*1c6e mov al, byte ptr [si]*/
/*1c70 test al, 0x80*/
/*1c72 jne 0x1c77*/
/*1c74 call 0x20db*/
/*1c77 ret */
void sub_11c56()
{
  ax = -ax;
  memoryASet16(ds, 0x9544, ax);
  push(ax);
  al = 0x06;
  sub_13840();
  ax = pop();
  ax = bx;
  push(ax);
  al = memoryAGet(ds, 0x1b9e);
  ah = 0x00;
  push(ax);
  sub_11c0a();
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_11c77;
  sub_120db();
loc_11c77:
  return;
}

/*1c78 mov ax, word ptr [0x9437]*/
/*1c7b mov word ptr [0x9439], ax*/
/*1c7e mov ax, word ptr [0x9435]*/
/*1c81 mov word ptr [0x9437], ax*/
/*1c84 mov ax, word ptr [0x9433]*/
/*1c87 mov word ptr [0x9435], ax*/
/*1c8a mov ax, word ptr [0x1b8f]*/
/*1c8d mov word ptr [0x9433], ax*/
/*1c90 mov ax, word ptr [0x943f]*/
/*1c93 mov word ptr [0x9441], ax*/
/*1c96 mov ax, word ptr [0x943d]*/
/*1c99 mov word ptr [0x943f], ax*/
/*1c9c mov ax, word ptr [0x943b]*/
/*1c9f mov word ptr [0x943d], ax*/
/*1ca2 mov ax, word ptr [0x1b91]*/
/*1ca5 mov word ptr [0x943b], ax*/
/*1ca8 mov al, byte ptr [0x9445]*/
/*1cab mov byte ptr [0x9446], al*/
/*1cae mov al, byte ptr [0x9444]*/
/*1cb1 mov byte ptr [0x9445], al*/
/*1cb4 mov al, byte ptr [0x9443]*/
/*1cb7 mov byte ptr [0x9444], al*/
/*1cba mov al, byte ptr [0x1b8e]*/
/*1cbd mov byte ptr [0x9443], al*/
/*1cc0 mov al, byte ptr [0x9449]*/
/*1cc3 mov byte ptr [0x944a], al*/
/*1cc6 mov al, byte ptr [0x9448]*/
/*1cc9 mov byte ptr [0x9449], al*/
/*1ccc mov al, byte ptr [0x9447]*/
/*1ccf mov byte ptr [0x9448], al*/
/*1cd2 mov al, byte ptr [0x1b8d]*/
/*1cd5 mov byte ptr [0x9447], al*/
/*1cd8 ret */
void sub_11c78()
{
  ax = memoryAGet16(ds, 0x9437);
  memoryASet16(ds, 0x9439, ax);
  ax = memoryAGet16(ds, 0x9435);
  memoryASet16(ds, 0x9437, ax);
  ax = memoryAGet16(ds, 0x9433);
  memoryASet16(ds, 0x9435, ax);
  ax = memoryAGet16(ds, 0x1b8f);
  memoryASet16(ds, 0x9433, ax);
  ax = memoryAGet16(ds, 0x943f);
  memoryASet16(ds, 0x9441, ax);
  ax = memoryAGet16(ds, 0x943d);
  memoryASet16(ds, 0x943f, ax);
  ax = memoryAGet16(ds, 0x943b);
  memoryASet16(ds, 0x943d, ax);
  ax = memoryAGet16(ds, 0x1b91);
  memoryASet16(ds, 0x943b, ax);
  al = memoryAGet(ds, 0x9445);
  memoryASet(ds, 0x9446, al);
  al = memoryAGet(ds, 0x9444);
  memoryASet(ds, 0x9445, al);
  al = memoryAGet(ds, 0x9443);
  memoryASet(ds, 0x9444, al);
  al = memoryAGet(ds, 0x1b8e);
  memoryASet(ds, 0x9443, al);
  al = memoryAGet(ds, 0x9449);
  memoryASet(ds, 0x944a, al);
  al = memoryAGet(ds, 0x9448);
  memoryASet(ds, 0x9449, al);
  al = memoryAGet(ds, 0x9447);
  memoryASet(ds, 0x9448, al);
  al = memoryAGet(ds, 0x1b8d);
  memoryASet(ds, 0x9447, al);
  return;
}

/*1cd9 mov ax, word ptr [0x9439]*/
/*1cdc mov word ptr [si + 5], ax*/
/*1cdf mov ax, word ptr [0x9441]*/
/*1ce2 add ax, 6*/
/*1ce5 and ax, 0x3ff*/
/*1ce8 mov word ptr [si + 7], ax*/
/*1ceb mov al, byte ptr [0x9446]*/
/*1cee mov byte ptr [si + 4], al*/
/*1cf1 mov bl, al*/
/*1cf3 mov bh, 0*/
/*1cf5 mov cl, byte ptr [bx + 0xdb9]*/
/*1cf9 mov al, byte ptr [0x944a]*/
/*1cfc add al, 6*/
/*1cfe mov byte ptr [si + 3], al*/
/*1d01 mov al, byte ptr [si]*/
/*1d03 test al, 0x20*/
/*1d05 jne 0x1d10*/
/*1d07 sub word ptr [si + 5], 8*/
/*1d0b add byte ptr [si + 3], cl*/
/*1d0e jmp 0x1d17*/
/*1d10 add word ptr [si + 5], 8*/
/*1d14 sub byte ptr [si + 3], cl*/
/*1d17 mov bx, 0xdda*/
/*1d1a call 0x2121*/
/*1d1d ret */
void sub_11cd9()
{
  ax = memoryAGet16(ds, 0x9439);
  memoryASet16(ds, si + 5, ax);
  ax = memoryAGet16(ds, 0x9441);
  ax += 0x0006;
  ax &= 0x03ff;
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x9446);
  memoryASet(ds, si + 4, al);
  bl = al;
  bh = 0x00;
  cl = memoryAGet(ds, bx + 3513);
  al = memoryAGet(ds, 0x944a);
  al += 0x06;
  memoryASet(ds, si + 3, al);
  al = memoryAGet(ds, si);
  
  if (!(al & 0x20)) goto loc_11d10;
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0008);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + cl);
  goto loc_11d17;
loc_11d10:
  memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0008);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - cl);
loc_11d17:
  bx = 0x0dda;
  sub_12121();
  return;
}

/*1d1e mov si, 0x135e*/
/*1d21 and byte ptr [si], 0xdf*/
/*1d24 mov bl, byte ptr [0x1b8e]*/
/*1d28 mov bh, 0*/
/*1d2a mov al, byte ptr [bx + 0x139d]*/
/*1d2e mov byte ptr [si + 4], al*/
/*1d31 mov al, byte ptr [bx + 0x1375]*/
/*1d35 cwde */
/*1d36 add ax, word ptr [0x1b8f]*/
/*1d3a mov word ptr [si + 5], ax*/
/*1d3d mov ax, word ptr [0x1b91]*/
/*1d40 sub ax, 4*/
/*1d43 and ax, 0x3ff*/
/*1d46 mov word ptr [si + 7], ax*/
/*1d49 mov al, byte ptr [0x1b8d]*/
/*1d4c add al, byte ptr [bx + 0x1389]*/
/*1d50 mov byte ptr [si + 3], al*/
/*1d53 mov bl, byte ptr [si + 4]*/
/*1d56 mov bh, 0*/
/*1d58 mov al, byte ptr [bx + 0x13a7]*/
/*1d5c mov byte ptr [si + 0xa], al*/
/*1d5f shl bx, 1*/
/*1d61 mov ax, word ptr [bx + 0x13aa]*/
/*1d65 mov word ptr [si + 0xf], ax*/
/*1d68 call 0xb58*/
/*1d6b mov si, 0xff7*/
/*1d6e mov ax, word ptr [0x1363]*/
/*1d71 mov word ptr [si + 5], ax*/
/*1d74 mov ax, word ptr [0x1365]*/
/*1d77 mov word ptr [si + 7], ax*/
/*1d7a mov al, byte ptr [0x1361]*/
/*1d7d mov byte ptr [si + 3], al*/
/*1d80 inc byte ptr [0]*/
/*1d84 mov bl, byte ptr [0]*/
/*1d88 and bx, 0xf*/
/*1d8b mov al, byte ptr [bx + 0xfe7]*/
/*1d8f mov byte ptr [si + 4], al*/
/*1d92 mov bx, 0x100e*/
/*1d95 call 0x2121*/
/*1d98 call 0xb58*/
/*1d9b mov si, 0x135e*/
/*1d9e or byte ptr [si], 0x20*/
/*1da1 mov bl, byte ptr [0x1b8e]*/
/*1da5 mov bh, 0*/
/*1da7 mov al, byte ptr [bx + 0x137f]*/
/*1dab cwde */
/*1dac add ax, word ptr [0x1b8f]*/
/*1db0 mov word ptr [si + 5], ax*/
/*1db3 mov al, byte ptr [0x1b8d]*/
/*1db6 add al, byte ptr [bx + 0x1393]*/
/*1dba mov byte ptr [si + 3], al*/
/*1dbd call 0xb58*/
/*1dc0 mov si, 0xff7*/
/*1dc3 mov ax, word ptr [0x1363]*/
/*1dc6 mov word ptr [si + 5], ax*/
/*1dc9 mov ax, word ptr [0x1365]*/
/*1dcc mov word ptr [si + 7], ax*/
/*1dcf mov al, byte ptr [0x1361]*/
/*1dd2 mov byte ptr [si + 3], al*/
/*1dd5 call 0xb58*/
/*1dd8 mov ax, word ptr [0x9511]*/
/*1ddb add ax, bx*/
/*1ddd cmp ax, 0x10*/
/*1de0 jbe 0x1deb*/
/*1de2 mov ax, 0*/
/*1de5 mov word ptr [0], 0xffff*/
/*1deb mov word ptr [0x9511], ax*/
/*1dee ret */
void sub_11d1e()
{
  si = 0x135e;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
  bl = memoryAGet(ds, 0x1b8e);
  bh = 0x00;
  al = memoryAGet(ds, bx + 5021);
  memoryASet(ds, si + 4, al);
  al = memoryAGet(ds, bx + 4981);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, 0x1b8f);
  memoryASet16(ds, si + 5, ax);
  ax = memoryAGet16(ds, 0x1b91);
  ax -= 0x0004;
  ax &= 0x03ff;
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x1b8d);
  al += memoryAGet(ds, bx + 5001);
  memoryASet(ds, si + 3, al);
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  al = memoryAGet(ds, bx + 5031);
  memoryASet(ds, si + 10, al);
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5034);
  memoryASet16(ds, si + 15, ax);
  sub_10b58();
  si = 0x0ff7;
  ax = memoryAGet16(ds, 0x1363);
  memoryASet16(ds, si + 5, ax);
  ax = memoryAGet16(ds, 0x1365);
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x1361);
  memoryASet(ds, si + 3, al);
  memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
  bl = memoryAGet(ds, 0x9516);
  bx &= 0x000f;
  al = memoryAGet(ds, bx + 4071);
  memoryASet(ds, si + 4, al);
  bx = 0x100e;
  sub_12121();
  sub_10b58();
  si = 0x135e;
  memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
  bl = memoryAGet(ds, 0x1b8e);
  bh = 0x00;
  al = memoryAGet(ds, bx + 4991);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, 0x1b8f);
  memoryASet16(ds, si + 5, ax);
  al = memoryAGet(ds, 0x1b8d);
  al += memoryAGet(ds, bx + 5011);
  memoryASet(ds, si + 3, al);
  sub_10b58();
  si = 0x0ff7;
  ax = memoryAGet16(ds, 0x1363);
  memoryASet16(ds, si + 5, ax);
  ax = memoryAGet16(ds, 0x1365);
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x1361);
  memoryASet(ds, si + 3, al);
  sub_10b58();
  ax = memoryAGet16(ds, 0x9511);
  ax += bx;
  
  if (ax <= 0x0010) goto loc_11deb;
  ax = 0x0000;
  memoryASet16(ds, 0x9540, 0xffff);
loc_11deb:
  memoryASet16(ds, 0x9511, ax);
  return;
}

/*1def inc byte ptr [0]*/
/*1df3 mov bl, byte ptr [0]*/
/*1df7 and bx, 0xf*/
/*1dfa mov al, byte ptr [bx + 0xfe7]*/
/*1dfe mov byte ptr [0xffb], al*/
/*1e01 mov al, byte ptr [si + 1]*/
/*1e04 cmp al, 0*/
/*1e06 jne 0x1e2e*/
/*1e08 mov bl, byte ptr [si + 4]*/
/*1e0b mov bh, 0*/
/*1e0d mov cl, byte ptr [bx + 0x13cd]*/
/*1e11 mov ax, 0xfffd*/
/*1e14 mov bx, 8*/
/*1e17 call 0x1e7d*/
/*1e1a mov bl, byte ptr [si + 4]*/
/*1e1d mov bh, 0*/
/*1e1f mov cl, byte ptr [bx + 0x13d7]*/
/*1e23 mov ax, 3*/
/*1e26 mov bx, 8*/
/*1e29 call 0x1e7d*/
/*1e2c jmp 0x1e7c*/
/*1e2e cmp al, 1*/
/*1e30 jne 0x1e46*/
/*1e32 mov bl, byte ptr [si + 4]*/
/*1e35 mov bh, 0*/
/*1e37 mov cl, byte ptr [bx + 0x13e1]*/
/*1e3b mov ax, 0*/
/*1e3e mov bx, 8*/
/*1e41 call 0x1e7d*/
/*1e44 jmp 0x1e7c*/
/*1e46 mov bl, byte ptr [si + 4]*/
/*1e49 mov bh, 0*/
/*1e4b mov cl, byte ptr [bx + 0x13eb]*/
/*1e4f mov ax, 0xfff9*/
/*1e52 mov bx, 8*/
/*1e55 call 0x1e7d*/
/*1e58 mov bl, byte ptr [si + 4]*/
/*1e5b mov bh, 0*/
/*1e5d mov cl, byte ptr [bx + 0x13f5]*/
/*1e61 mov ax, 0*/
/*1e64 mov bx, 0xb*/
/*1e67 call 0x1e7d*/
/*1e6a mov bl, byte ptr [si + 4]*/
/*1e6d mov bh, 0*/
/*1e6f mov cl, byte ptr [bx + 0x13ff]*/
/*1e73 mov ax, 7*/
/*1e76 mov bx, 8*/
/*1e79 call 0x1e7d*/
/*1e7c ret */
void sub_11def()
{
  memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
  bl = memoryAGet(ds, 0x9516);
  bx &= 0x000f;
  al = memoryAGet(ds, bx + 4071);
  memoryASet(ds, 0x0ffb, al);
  al = memoryAGet(ds, si + 1);
  
  if (al != 0x00) goto loc_11e2e;
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5069);
  ax = 0xfffd;
  bx = 0x0008;
  sub_11e7d();
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5079);
  ax = 0x0003;
  bx = 0x0008;
  sub_11e7d();
  goto loc_11e7c;
loc_11e2e:
  
  if (al != 0x01) goto loc_11e46;
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5089);
  ax = 0x0000;
  bx = 0x0008;
  sub_11e7d();
  goto loc_11e7c;
loc_11e46:
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5099);
  ax = 0xfff9;
  bx = 0x0008;
  sub_11e7d();
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5109);
  ax = 0x0000;
  bx = 0x000b;
  sub_11e7d();
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  cl = memoryAGet(ds, bx + 5119);
  ax = 0x0007;
  bx = 0x0008;
  sub_11e7d();
loc_11e7c:
  return;
}

/*1e7d push si*/
/*1e7e mov di, 0xff7*/
/*1e81 add ax, word ptr [si + 5]*/
/*1e84 mov word ptr [di + 5], ax*/
/*1e87 add bx, word ptr [si + 7]*/
/*1e8a and bx, 0x3ff*/
/*1e8e mov word ptr [di + 7], bx*/
/*1e91 add cl, byte ptr [si + 3]*/
/*1e94 mov byte ptr [di + 3], cl*/
/*1e97 mov si, di*/
/*1e99 mov bx, 0x1039*/
/*1e9c call 0x2121*/
/*1e9f call 0xb58*/
/*1ea2 cmp si, 0*/
/*1ea5 je 0x1eb0*/
/*1ea7 pop ax*/
/*1ea8 push ax*/
/*1ea9 cmp ax, si*/
/*1eab jbe 0x1eb0*/
/*1ead call 0x16d6*/
/*1eb0 pop si*/
/*1eb1 mov al, byte ptr [0x9518]*/
/*1eb4 cmp al, 0*/
/*1eb6 jne 0x1eb9*/
/*1eb8 ret */
/*1eb9 push si*/
/*1eba mov bl, byte ptr [si + 4]*/
/*1ebd mov bh, 0*/
/*1ebf mov si, 0x13b0*/
/*1ec2 mov al, byte ptr [bx + 0x139d]*/
/*1ec6 mov byte ptr [si + 4], al*/
/*1ec9 mov ax, word ptr [0xffc]*/
/*1ecc mov word ptr [si + 5], ax*/
/*1ecf mov ax, word ptr [0xffe]*/
/*1ed2 mov word ptr [si + 7], ax*/
/*1ed5 mov al, byte ptr [0xffa]*/
/*1ed8 mov byte ptr [si + 3], al*/
/*1edb mov byte ptr [si + 1], 2*/
/*1edf mov bl, byte ptr [si + 4]*/
/*1ee2 mov bh, 0*/
/*1ee4 mov al, byte ptr [bx + 0x13a7]*/
/*1ee8 mov byte ptr [si + 0xa], al*/
/*1eeb mov byte ptr [si + 9], 4*/
/*1eef shl bx, 1*/
/*1ef1 mov ax, word ptr [bx + 0x13c7]*/
/*1ef5 mov word ptr [si + 0xf], ax*/
/*1ef8 call 0xb58*/
/*1efb cmp si, 0*/
/*1efe je 0x1f09*/
/*1f00 pop ax*/
/*1f01 push ax*/
/*1f02 cmp ax, si*/
/*1f04 jbe 0x1f09*/
/*1f06 call 0x15fc*/
/*1f09 pop si*/
/*1f0a ret */
void sub_11e7d()
{
  push(si);
  di = 0x0ff7;
  ax += memoryAGet16(ds, si + 5);
  memoryASet16(ds, di + 5, ax);
  bx += memoryAGet16(ds, si + 7);
  bx &= 0x03ff;
  memoryASet16(ds, di + 7, bx);
  cl += memoryAGet(ds, si + 3);
  memoryASet(ds, di + 3, cl);
  si = di;
  bx = 0x1039;
  sub_12121();
  sub_10b58();
  
  if (si == 0x0000) goto loc_11eb0;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_11eb0;
  sub_116d6();
loc_11eb0:
  si = pop();
  al = memoryAGet(ds, 0x9518);
  
  if (al != 0x00) goto loc_11eb9;
  return;
loc_11eb9:
  push(si);
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  si = 0x13b0;
  al = memoryAGet(ds, bx + 5021);
  memoryASet(ds, si + 4, al);
  ax = memoryAGet16(ds, 0x0ffc);
  memoryASet16(ds, si + 5, ax);
  ax = memoryAGet16(ds, 0x0ffe);
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, 0x0ffa);
  memoryASet(ds, si + 3, al);
  memoryASet(ds, si + 1, 0x02);
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  al = memoryAGet(ds, bx + 5031);
  memoryASet(ds, si + 10, al);
  memoryASet(ds, si + 9, 0x04);
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5063);
  memoryASet16(ds, si + 15, ax);
  sub_10b58();
  
  if (si == 0x0000) goto loc_11f09;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_11f09;
  sub_115fc();
loc_11f09:
  si = pop();
  return;
}

/*1f0b push si*/
/*1f0c inc byte ptr [0]*/
/*1f10 mov bl, byte ptr [0]*/
/*1f14 and bx, 0xf*/
/*1f17 mov al, byte ptr [bx + 0xfe7]*/
/*1f1b mov byte ptr [0xffb], al*/
/*1f1e mov di, 0xff7*/
/*1f21 mov bl, byte ptr [si + 4]*/
/*1f24 mov bh, 0*/
/*1f26 mov al, byte ptr [bx + 0x1409]*/
/*1f2a cwde */
/*1f2b add ax, word ptr [si + 5]*/
/*1f2e mov word ptr [di + 5], ax*/
/*1f31 mov al, byte ptr [bx + 0x140e]*/
/*1f35 cwde */
/*1f36 add ax, word ptr [si + 7]*/
/*1f39 and ax, 0x3ff*/
/*1f3c mov word ptr [di + 7], ax*/
/*1f3f mov al, byte ptr [si + 3]*/
/*1f42 add al, 4*/
/*1f44 mov byte ptr [di + 3], al*/
/*1f47 shl bx, 1*/
/*1f49 mov bx, word ptr [bx + 0x102f]*/
/*1f4d mov si, di*/
/*1f4f call 0x2121*/
/*1f52 call 0xb58*/
/*1f55 cmp si, 0*/
/*1f58 je 0x1f63*/
/*1f5a pop ax*/
/*1f5b push ax*/
/*1f5c cmp ax, si*/
/*1f5e jbe 0x1f63*/
/*1f60 call 0x16d6*/
/*1f63 pop si*/
/*1f64 mov al, byte ptr [0x9518]*/
/*1f67 cmp al, 0*/
/*1f69 jne 0x1f6c*/
/*1f6b ret */
/*1f6c push si*/
/*1f6d mov di, 0x13b0*/
/*1f70 mov bl, byte ptr [si + 4]*/
/*1f73 mov bh, 0*/
/*1f75 mov byte ptr [di + 1], bl*/
/*1f78 mov ax, word ptr [0xffc]*/
/*1f7b mov word ptr [di + 5], ax*/
/*1f7e mov ax, word ptr [0xffe]*/
/*1f81 mov word ptr [di + 7], ax*/
/*1f84 mov al, byte ptr [0xffa]*/
/*1f87 mov byte ptr [di + 3], al*/
/*1f8a mov al, byte ptr [bx + 0x1413]*/
/*1f8e mov byte ptr [di + 9], al*/
/*1f91 mov al, byte ptr [bx + 0x1418]*/
/*1f95 mov byte ptr [di + 0xa], al*/
/*1f98 mov byte ptr [di + 4], 0*/
/*1f9c shl bx, 1*/
/*1f9e mov ax, word ptr [bx + 0x141d]*/
/*1fa2 mov word ptr [di + 0xf], ax*/
/*1fa5 mov si, di*/
/*1fa7 call 0xb58*/
/*1faa cmp si, 0*/
/*1fad je 0x1fb8*/
/*1faf pop ax*/
/*1fb0 push ax*/
/*1fb1 cmp ax, si*/
/*1fb3 jbe 0x1fb8*/
/*1fb5 call 0x15fc*/
/*1fb8 pop si*/
/*1fb9 ret */
void sub_11f0b()
{
  push(si);
  memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
  bl = memoryAGet(ds, 0x9516);
  bx &= 0x000f;
  al = memoryAGet(ds, bx + 4071);
  memoryASet(ds, 0x0ffb, al);
  di = 0x0ff7;
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  al = memoryAGet(ds, bx + 5129);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 5);
  memoryASet16(ds, di + 5, ax);
  al = memoryAGet(ds, bx + 5134);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 7);
  ax &= 0x03ff;
  memoryASet16(ds, di + 7, ax);
  al = memoryAGet(ds, si + 3);
  al += 0x04;
  memoryASet(ds, di + 3, al);
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 4143);
  si = di;
  sub_12121();
  sub_10b58();
  
  if (si == 0x0000) goto loc_11f63;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_11f63;
  sub_116d6();
loc_11f63:
  si = pop();
  al = memoryAGet(ds, 0x9518);
  
  if (al != 0x00) goto loc_11f6c;
  return;
loc_11f6c:
  push(si);
  di = 0x13b0;
  bl = memoryAGet(ds, si + 4);
  bh = 0x00;
  memoryASet(ds, di + 1, bl);
  ax = memoryAGet16(ds, 0x0ffc);
  memoryASet16(ds, di + 5, ax);
  ax = memoryAGet16(ds, 0x0ffe);
  memoryASet16(ds, di + 7, ax);
  al = memoryAGet(ds, 0x0ffa);
  memoryASet(ds, di + 3, al);
  al = memoryAGet(ds, bx + 5139);
  memoryASet(ds, di + 9, al);
  al = memoryAGet(ds, bx + 5144);
  memoryASet(ds, di + 10, al);
  memoryASet(ds, di + 4, 0x00);
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5149);
  memoryASet16(ds, di + 15, ax);
  si = di;
  sub_10b58();
  
  if (si == 0x0000) goto loc_11fb8;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_11fb8;
  sub_115fc();
loc_11fb8:
  si = pop();
  return;
}

/*1fba push si*/
/*1fbb mov di, 0x10e8*/
/*1fbe mov bl, byte ptr [si + 4]*/
/*1fc1 mov byte ptr [di + 1], bl*/
/*1fc4 mov bh, 0*/
/*1fc6 mov al, byte ptr [bx + 0x10de]*/
/*1fca cwde */
/*1fcb add ax, word ptr [si + 5]*/
/*1fce mov word ptr [di + 5], ax*/
/*1fd1 mov al, byte ptr [bx + 0x10e3]*/
/*1fd5 cwde */
/*1fd6 add ax, word ptr [si + 7]*/
/*1fd9 and ax, 0x3ff*/
/*1fdc mov word ptr [di + 7], ax*/
/*1fdf mov al, byte ptr [si + 3]*/
/*1fe2 add al, 8*/
/*1fe4 mov byte ptr [di + 3], al*/
/*1fe7 shl bx, 1*/
/*1fe9 mov bx, word ptr [bx + 0x10ff]*/
/*1fed mov si, di*/
/*1fef call 0x2121*/
/*1ff2 call 0xb58*/
/*1ff5 cmp si, 0*/
/*1ff8 je 0x2003*/
/*1ffa pop ax*/
/*1ffb push ax*/
/*1ffc cmp ax, si*/
/*1ffe jbe 0x2003*/
/*2000 call 0x1429*/
/*2003 pop si*/
/*2004 ret */
void sub_11fba()
{
  push(si);
  di = 0x10e8;
  bl = memoryAGet(ds, si + 4);
  memoryASet(ds, di + 1, bl);
  bh = 0x00;
  al = memoryAGet(ds, bx + 4318);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 5);
  memoryASet16(ds, di + 5, ax);
  al = memoryAGet(ds, bx + 4323);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 7);
  ax &= 0x03ff;
  memoryASet16(ds, di + 7, ax);
  al = memoryAGet(ds, si + 3);
  al += 0x08;
  memoryASet(ds, di + 3, al);
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 4351);
  si = di;
  sub_12121();
  sub_10b58();
  
  if (si == 0x0000) goto loc_12003;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_12003;
  sub_11429();
loc_12003:
  si = pop();
  return;
}

/*2005 push si*/
/*2006 mov di, 0x1446*/
/*2009 mov bl, byte ptr [si + 4]*/
/*200c mov byte ptr [di + 1], bl*/
/*200f mov bh, 0*/
/*2011 mov al, byte ptr [bx + 0x145d]*/
/*2015 cwde */
/*2016 add ax, word ptr [si + 5]*/
/*2019 mov word ptr [di + 5], ax*/
/*201c mov al, byte ptr [bx + 0x1462]*/
/*2020 cwde */
/*2021 add ax, word ptr [si + 7]*/
/*2024 and ax, 0x3ff*/
/*2027 mov word ptr [di + 7], ax*/
/*202a mov al, byte ptr [si + 3]*/
/*202d add al, 8*/
/*202f mov byte ptr [di + 3], al*/
/*2032 mov si, di*/
/*2034 call 0xb58*/
/*2037 cmp si, 0*/
/*203a je 0x2045*/
/*203c pop ax*/
/*203d push ax*/
/*203e cmp ax, si*/
/*2040 jbe 0x2045*/
/*2042 call 0x17f4*/
/*2045 pop si*/
/*2046 ret */
void sub_12005()
{
  push(si);
  di = 0x1446;
  bl = memoryAGet(ds, si + 4);
  memoryASet(ds, di + 1, bl);
  bh = 0x00;
  al = memoryAGet(ds, bx + 5213);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 5);
  memoryASet16(ds, di + 5, ax);
  al = memoryAGet(ds, bx + 5218);
  true ? cbw() : cwde();
  ax += memoryAGet16(ds, si + 7);
  ax &= 0x03ff;
  memoryASet16(ds, di + 7, ax);
  al = memoryAGet(ds, si + 3);
  al += 0x08;
  memoryASet(ds, di + 3, al);
  si = di;
  sub_10b58();
  
  if (si == 0x0000) goto loc_12045;
  ax = pop();
  push(ax);
  
  if (ax <= si) goto loc_12045;
  sub_117f4();
loc_12045:
  si = pop();
  return;
}

/*2047 mov al, byte ptr [si]*/
/*2049 mov bl, byte ptr [0]*/
/*204d test al, 0x20*/
/*204f je 0x2072*/
/*2051 test bl, 0x80*/
/*2054 jne 0x206d*/
/*2056 or byte ptr [0], 0x80*/
/*205b or byte ptr [0x1326], 0x20*/
/*2060 mov di, 0x1326*/
/*2063 call 0x20a0*/
/*2066 mov al, 3*/
/*2068 call 0x3840*/
/*206b jmp 0x2070*/
/*206d mov byte ptr [si], 0*/
/*2070 jmp 0x2091*/
/*2072 test bl, 1*/
/*2075 jne 0x208e*/
/*2077 or byte ptr [0], 1*/
/*207c and byte ptr [0x1326], 0xdf*/
/*2081 mov di, 0x1326*/
/*2084 call 0x20a0*/
/*2087 mov al, 3*/
/*2089 call 0x3840*/
/*208c jmp 0x2091*/
/*208e mov byte ptr [si], 0*/
/*2091 ret */
void sub_12047()
{
  al = memoryAGet(ds, si);
  bl = memoryAGet(ds, 0x9517);
  
  if (al & 0x20) goto loc_12072;
  
  if (!(bl & 0x80)) goto loc_1206d;
  memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) | 0x80);
  memoryASet(ds, 0x1326, memoryAGet(ds, 0x1326) | 0x20);
  di = 0x1326;
  sub_120a0();
  al = 0x03;
  sub_13840();
  goto loc_12070;
loc_1206d:
  memoryASet(ds, si, 0x00);
loc_12070:
  goto loc_12091;
loc_12072:
  
  if (!(bl & 0x01)) goto loc_1208e;
  memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) | 0x01);
  memoryASet(ds, 0x1326, memoryAGet(ds, 0x1326) & 0xdf);
  di = 0x1326;
  sub_120a0();
  al = 0x03;
  sub_13840();
  goto loc_12091;
loc_1208e:
  memoryASet(ds, si, 0x00);
loc_12091:
  return;
}

/*2092 mov di, 0x1427*/
/*2095 call 0x20a0*/
/*2098 ret */
void sub_12092()
{
  di = 0x1427;
  sub_120a0();
  return;
}

/*2099 mov di, 0x12de*/
/*209c call 0x20a0*/
/*209f ret */
void sub_12099()
{
  di = 0x12de;
  sub_120a0();
  return;
}

/*20a0 mov al, byte ptr [di]*/
/*20a2 mov byte ptr [si], al*/
/*20a4 mov al, byte ptr [di + 2]*/
/*20a7 mov byte ptr [si + 2], al*/
/*20aa mov al, byte ptr [di + 0x16]*/
/*20ad mov byte ptr [si + 0x16], al*/
/*20b0 mov al, byte ptr [di + 4]*/
/*20b3 mov byte ptr [si + 4], al*/
/*20b6 mov al, byte ptr [di + 9]*/
/*20b9 mov byte ptr [si + 9], al*/
/*20bc mov al, byte ptr [di + 0xa]*/
/*20bf mov byte ptr [si + 0xa], al*/
/*20c2 mov al, byte ptr [di + 0xb]*/
/*20c5 mov byte ptr [si + 0xb], al*/
/*20c8 mov al, byte ptr [di + 0xc]*/
/*20cb mov byte ptr [si + 0xc], al*/
/*20ce mov ax, word ptr [di + 0xf]*/
/*20d1 mov word ptr [si + 0xf], ax*/
/*20d4 mov al, byte ptr [di + 0x12]*/
/*20d7 mov byte ptr [si + 0x12], al*/
/*20da ret */
void sub_120a0()
{
  al = memoryAGet(ds, di);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, di + 2);
  memoryASet(ds, si + 2, al);
  al = memoryAGet(ds, di + 22);
  memoryASet(ds, si + 22, al);
  al = memoryAGet(ds, di + 4);
  memoryASet(ds, si + 4, al);
  al = memoryAGet(ds, di + 9);
  memoryASet(ds, si + 9, al);
  al = memoryAGet(ds, di + 10);
  memoryASet(ds, si + 10, al);
  al = memoryAGet(ds, di + 11);
  memoryASet(ds, si + 11, al);
  al = memoryAGet(ds, di + 12);
  memoryASet(ds, si + 12, al);
  ax = memoryAGet16(ds, di + 15);
  memoryASet16(ds, si + 15, ax);
  al = memoryAGet(ds, di + 18);
  memoryASet(ds, si + 18, al);
  return;
}

/*20db call 0x2676*/
/*20de call 0x20f0*/
/*20e1 push si*/
/*20e2 mov al, byte ptr [si + 0x13]*/
/*20e5 mov ah, 0*/
/*20e7 push ax*/
/*20e8 mov al, byte ptr [si + 0x14]*/
/*20eb push ax*/
/*20ec call 0x9b5*/
/*20ef ret */
void sub_120db()
{
  sub_12676();
  sub_120f0();
  push(si);
  al = memoryAGet(ds, si + 19);
  ah = 0x00;
  push(ax);
  al = memoryAGet(ds, si + 20);
  push(ax);
  sub_109b5();
  return;
}

/*9b5 push bp*/
/*9b6 mov bp, sp*/
/*9b8 mov si, word ptr [bp + 8]*/
/*9bb call 0xa1b*/
/*9be mov bx, word ptr [bp + 6]*/
/*9c1 shl bx, 1*/
/*9c3 mov cx, word ptr [bx + 0xceb]*/
/*9c7 mov bx, word ptr [bp + 4]*/
/*9ca shl bx, 1*/
/*9cc mov al, byte ptr [0x9502]*/
/*9cf cmp al, 1*/
/*9d1 jne 0x9d9*/
/*9d3 add bx, 0x80*/
/*9d7 jmp 0x9e1*/
/*9d9 cmp al, 2*/
/*9db jne 0x9e1*/
/*9dd add bx, 0x100*/
/*9e1 and word ptr [bx - 0x6d57], cx*/
/*9e5 pop bp*/
/*9e6 ret 6*/
void sub_109b5()
{
  push(bp);
  bp = sp;
  si = memoryAGet16(ss, bp + 8 - 2);
  sub_10a1b();
  bx = memoryAGet16(ss, bp + 6 - 2);
  bx <<= 0x0001;
  cx = memoryAGet16(ds, bx + 3307);
  bx = memoryAGet16(ss, bp + 4 - 2);
  bx <<= 0x0001;
  al = memoryAGet(ds, 0x9502);
  
  if (al != 0x01) goto loc_109d9;
  bx += 0x0080;
  goto loc_109e1;
loc_109d9:
  
  if (al != 0x02) goto loc_109e1;
  bx += 0x0100;
loc_109e1:
  memoryASet16(ds, bx + 37545, memoryAGet16(ds, bx + 37545) & cx);
  bp = pop();
  return;
}

/*20f0 push si*/
/*20f1 mov ax, word ptr [si + 5]*/
/*20f4 mov word ptr [0x12a3], ax*/
/*20f7 mov ax, word ptr [si + 7]*/
/*20fa mov word ptr [0x12a5], ax*/
/*20fd mov al, byte ptr [si + 3]*/
/*2100 mov byte ptr [0x12a1], al*/
/*2103 mov al, byte ptr [si]*/
/*2105 test al, 0x10*/
/*2107 je 0x2119*/
/*2109 sub word ptr [0x12a3], 0xc*/
/*210e sub word ptr [0x12a5], 8*/
/*2113 and word ptr [0x12a5], 0x3ff*/
/*2119 mov si, 0x129e*/
/*211c call 0xb58*/
/*211f pop si*/
/*2120 ret */
void sub_120f0()
{
  push(si);
  ax = memoryAGet16(ds, si + 5);
  memoryASet16(ds, 0x12a3, ax);
  ax = memoryAGet16(ds, si + 7);
  memoryASet16(ds, 0x12a5, ax);
  al = memoryAGet(ds, si + 3);
  memoryASet(ds, 0x12a1, al);
  al = memoryAGet(ds, si);
  
  if (al & 0x10) goto loc_12119;
  memoryASet16(ds, 0x12a3, memoryAGet16(ds, 0x12a3) - 0x000c);
  memoryASet16(ds, 0x12a5, memoryAGet16(ds, 0x12a5) - 0x0008);
  memoryASet16(ds, 0x12a5, memoryAGet16(ds, 0x12a5) & 0x03ff);
loc_12119:
  si = 0x129e;
  sub_10b58();
  si = pop();
  return;
}

/*2121 mov cl, byte ptr [bx]*/
/*2123 mov ch, 0*/
/*2125 inc bx*/
/*2126 mov al, byte ptr [si + 4]*/
/*2129 mov ah, 0*/
/*212b mov di, ax*/
/*212d mov al, byte ptr [bx + di]*/
/*212f mov byte ptr [si + 9], al*/
/*2132 add bx, cx*/
/*2134 mov al, byte ptr [bx + di]*/
/*2136 mov byte ptr [si + 0xa], al*/
/*2139 add bx, cx*/
/*213b mov al, byte ptr [bx + di]*/
/*213d mov byte ptr [si + 0xb], al*/
/*2140 add bx, cx*/
/*2142 mov al, byte ptr [bx + di]*/
/*2144 mov byte ptr [si + 0xc], al*/
/*2147 add bx, cx*/
/*2149 shl di, 1*/
/*214b shl di, 1*/
/*214d mov ax, word ptr [bx + di]*/
/*214f mov word ptr [si + 0xd], ax*/
/*2152 add bx, 2*/
/*2155 mov ax, word ptr [bx + di]*/
/*2157 mov word ptr [si + 0xf], ax*/
/*215a ret */
void sub_12121()
{
  cl = memoryAGet(ds, bx);
  ch = 0x00;
  bx++;
  al = memoryAGet(ds, si + 4);
  ah = 0x00;
  di = ax;
  al = memoryAGet(ds, bx + di);
  memoryASet(ds, si + 9, al);
  bx += cx;
  al = memoryAGet(ds, bx + di);
  memoryASet(ds, si + 10, al);
  bx += cx;
  al = memoryAGet(ds, bx + di);
  memoryASet(ds, si + 11, al);
  bx += cx;
  al = memoryAGet(ds, bx + di);
  memoryASet(ds, si + 12, al);
  bx += cx;
  di <<= 0x0001;
  di <<= 0x0001;
  ax = memoryAGet16(ds, bx + di);
  memoryASet16(ds, si + 13, ax);
  bx += 0x0002;
  ax = memoryAGet16(ds, bx + di);
  memoryASet16(ds, si + 15, ax);
  return;
}

/*215b mov cx, 1*/
/*215e mov ax, word ptr [0x1b91]*/
/*2161 sub ax, word ptr [si + 7]*/
/*2164 cmp ax, 0x8c*/
/*2167 jle 0x2171*/
/*2169 mov byte ptr [si + 4], 2*/
/*216d mov cx, 0*/
/*2170 ret */
/*2171 cmp ax, 0xfff0*/
/*2174 jge 0x21a0*/
/*2176 mov ah, byte ptr [si + 4]*/
/*2179 mov al, byte ptr [si]*/
/*217b test al, 0x20*/
/*217d je 0x218d*/
/*217f inc ah*/
/*2181 cmp ah, 4*/
/*2184 jle 0x218b*/
/*2186 and byte ptr [si], 0xdf*/
/*2189 mov ah, 4*/
/*218b jmp 0x2199*/
/*218d dec ah*/
/*218f cmp ah, 0*/
/*2192 jge 0x2199*/
/*2194 or byte ptr [si], 0x20*/
/*2197 mov ah, 0*/
/*2199 mov byte ptr [si + 4], ah*/
/*219c mov cx, 0*/
/*219f ret */
/*21a0 mov bx, word ptr [0x1b8f]*/
/*21a4 sub bx, word ptr [si + 5]*/
/*21a7 jns 0x21c2*/
/*21a9 cmp bx, -0x20*/
/*21ac jle 0x21b3*/
/*21ae mov byte ptr [si + 4], 2*/
/*21b2 ret */
/*21b3 cmp ax, 0x20*/
/*21b6 jle 0x21bd*/
/*21b8 mov byte ptr [si + 4], 1*/
/*21bc ret */
/*21bd mov byte ptr [si + 4], 0*/
/*21c1 ret */
/*21c2 cmp bx, 0x20*/
/*21c5 jge 0x21cc*/
/*21c7 mov byte ptr [si + 4], 2*/
/*21cb ret */
/*21cc cmp ax, 0x20*/
/*21cf jle 0x21d6*/
/*21d1 mov byte ptr [si + 4], 3*/
/*21d5 ret */
/*21d6 mov byte ptr [si + 4], 4*/
/*21da ret */
void sub_1215b()
{
  cx = 0x0001;
  ax = memoryAGet16(ds, 0x1b91);
  ax -= memoryAGet16(ds, si + 7);
  
  if ((short)ax <= (short)0x008c) goto loc_12171;
  memoryASet(ds, si + 4, 0x02);
  cx = 0x0000;
  return;
loc_12171:
  
  if ((short)ax >= (short)0xfff0) goto loc_121a0;
  ah = memoryAGet(ds, si + 4);
  al = memoryAGet(ds, si);
  
  if (al & 0x20) goto loc_1218d;
  ah++;
  
  if ((char)ah <= (char)0x04) goto loc_1218b;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
  ah = 0x04;
loc_1218b:
  goto loc_12199;
loc_1218d:
  ah--;
  
  if ((char)ah >= (char)0x00) goto loc_12199;
  memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
  ah = 0x00;
loc_12199:
  memoryASet(ds, si + 4, ah);
  cx = 0x0000;
  return;
loc_121a0:
  bx = memoryAGet16(ds, 0x1b8f);
  bx -= memoryAGet16(ds, si + 5);
  if ((short)bx >= 0) goto loc_121c2;
  
  if ((short)bx <= (short)0xffe0) goto loc_121b3;
  memoryASet(ds, si + 4, 0x02);
  return;
loc_121b3:
  
  if ((short)ax <= (short)0x0020) goto loc_121bd;
  memoryASet(ds, si + 4, 0x01);
  return;
loc_121bd:
  memoryASet(ds, si + 4, 0x00);
  return;
loc_121c2:
  
  if ((short)bx >= (short)0x0020) goto loc_121cc;
  memoryASet(ds, si + 4, 0x02);
  return;
loc_121cc:
  
  if ((short)ax <= (short)0x0020) goto loc_121d6;
  memoryASet(ds, si + 4, 0x03);
  return;
loc_121d6:
  memoryASet(ds, si + 4, 0x04);
  return;
}

/*21dc mov ax, 0x403c*/
/*21df push ax*/
/*21e0 mov ax, 0x1e11*/
/*21e3 push ax*/
/*21e4 mov ax, 0x38*/
/*21e7 push ax*/
/*21e8 mov ax, 7*/
/*21eb push ax*/
/*21ec mov ax, 2*/
/*21ef push ax*/
/*21f0 call 0x2cea*/
/*21f3 call 0x2200*/
/*21f6 call 0x264a*/
/*21f9 call 0x2a7f*/
/*21fc call 0x22b1*/
/*21ff ret */
void sub_121dc()
{
  ax = 0x403c;
  push(ax);
  ax = 0x1e11;
  push(ax);
  ax = 0x0038;
  push(ax);
  ax = 0x0007;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  sub_12200();
  sub_1264a();
  sub_12a7f();
  sub_122b1();
  return;
}

/*2200 call 0x250b*/
/*2203 call 0x2553*/
/*2206 call 0x259b*/
/*2209 call 0x237c*/
/*220c ret */
void sub_12200()
{
  sub_1250b();
  sub_12553();
  sub_1259b();
  sub_1237c();
  return;
}

/*220d inc byte ptr [0]*/
/*2211 mov al, byte ptr [0x944c]*/
/*2214 and al, 3*/
/*2216 jne 0x2228*/
/*2218 mov ax, 0*/
/*221b push ax*/
/*221c push ax*/
/*221d push ax*/
/*221e mov al, byte ptr [0x94fe]*/
/*2221 push ax*/
/*2222 call 0x269e*/
/*2225 call 0x2714*/
/*2228 mov ax, word ptr [0x953c]*/
/*222b cmp ax, 0*/
/*222e je 0x2246*/
/*2230 jns 0x2237*/
/*2232 call 0x252f*/
/*2235 jmp 0x2240*/
/*2237 mov cx, ax*/
/*2239 push cx*/
/*223a call 0x2542*/
/*223d pop cx*/
/*223e loop 0x2239*/
/*2240 mov word ptr [0], 0*/
/*2246 mov ax, word ptr [0x9540]*/
/*2249 cmp ax, 0*/
/*224c je 0x2264*/
/*224e jns 0x2255*/
/*2250 call 0x2577*/
/*2253 jmp 0x225e*/
/*2255 mov cx, ax*/
/*2257 push cx*/
/*2258 call 0x258a*/
/*225b pop cx*/
/*225c loop 0x2257*/
/*225e mov word ptr [0], 0*/
/*2264 mov ax, word ptr [0x9544]*/
/*2267 cmp ax, 0*/
/*226a je 0x228a*/
/*226c jns 0x227b*/
/*226e neg ax*/
/*2270 mov cx, ax*/
/*2272 push cx*/
/*2273 call 0x25bf*/
/*2276 pop cx*/
/*2277 loop 0x2272*/
/*2279 jmp 0x2284*/
/*227b mov cx, ax*/
/*227d push cx*/
/*227e call 0x25d2*/
/*2281 pop cx*/
/*2282 loop 0x227d*/
/*2284 mov word ptr [0], 0*/
/*228a mov ax, word ptr [0x9538]*/
/*228d cmp ax, 0*/
/*2290 je 0x22b0*/
/*2292 jns 0x22a1*/
/*2294 neg ax*/
/*2296 mov cx, ax*/
/*2298 push cx*/
/*2299 call 0x2464*/
/*229c pop cx*/
/*229d loop 0x2298*/
/*229f jmp 0x22aa*/
/*22a1 mov cx, ax*/
/*22a3 push cx*/
/*22a4 call 0x239b*/
/*22a7 pop cx*/
/*22a8 loop 0x22a3*/
/*22aa mov word ptr [0], 0*/
/*22b0 ret */
void sub_1220d()
{
  memoryASet(ds, 0x944c, memoryAGet(ds, 0x944c) + 1);
  al = memoryAGet(ds, 0x944c);
  al &= 0x03;
  if (al) goto loc_12228;
  ax = 0x0000;
  push(ax);
  push(ax);
  push(ax);
  al = memoryAGet(ds, 0x94fe);
  push(ax);
  sub_1269e();
  sub_12714();
loc_12228:
  ax = memoryAGet16(ds, 0x953c);
  
  if (ax == 0x0000) goto loc_12246;
  if ((short)ax >= 0) goto loc_12237;
  sub_1252f();
  goto loc_12240;
loc_12237:
  cx = ax;
loc_12239:
  push(cx);
  sub_12542();
  cx = pop();
  if (--cx) goto loc_12239;
loc_12240:
  memoryASet16(ds, 0x953c, 0x0000);
loc_12246:
  ax = memoryAGet16(ds, 0x9540);
  
  if (ax == 0x0000) goto loc_12264;
  if ((short)ax >= 0) goto loc_12255;
  sub_12577();
  goto loc_1225e;
loc_12255:
  cx = ax;
loc_12257:
  push(cx);
  sub_1258a();
  cx = pop();
  if (--cx) goto loc_12257;
loc_1225e:
  memoryASet16(ds, 0x9540, 0x0000);
loc_12264:
  ax = memoryAGet16(ds, 0x9544);
  
  if (ax == 0x0000) goto loc_1228a;
  if ((short)ax >= 0) goto loc_1227b;
  ax = -ax;
  cx = ax;
loc_12272:
  push(cx);
  sub_125bf();
  cx = pop();
  if (--cx) goto loc_12272;
  goto loc_12284;
loc_1227b:
  cx = ax;
loc_1227d:
  push(cx);
  sub_125d2();
  cx = pop();
  if (--cx) goto loc_1227d;
loc_12284:
  memoryASet16(ds, 0x9544, 0x0000);
loc_1228a:
  ax = memoryAGet16(ds, 0x9538);
  
  if (ax == 0x0000) goto loc_122b0;
  if ((short)ax >= 0) goto loc_122a1;
  ax = -ax;
  cx = ax;
loc_12298:
  push(cx);
  sub_12464();
  cx = pop();
  if (--cx) goto loc_12298;
  goto loc_122aa;
loc_122a1:
  cx = ax;
loc_122a3:
  push(cx);
  sub_1239b();
  cx = pop();
  if (--cx) goto loc_122a3;
loc_122aa:
  memoryASet16(ds, 0x9538, 0x0000);
loc_122b0:
  return;
}

/*22b1 mov word ptr [0], 3*/
/*22b7 call 0x22e1*/
/*22ba call 0x22f9*/
/*22bd call 0x2311*/
/*22c0 ret */
void sub_122b1()
{
  memoryASet16(ds, 0x9534, 0x0003);
  sub_122e1();
  sub_122f9();
  sub_12311();
  return;
}

/*22e1 mov ax, 0x43e6*/
/*22e4 push ax*/
/*22e5 mov ax, 0x1b90*/
/*22e8 push ax*/
/*22e9 mov ax, 0x10*/
/*22ec push ax*/
/*22ed mov ax, 0xf*/
/*22f0 push ax*/
/*22f1 mov ax, 2*/
/*22f4 push ax*/
/*22f5 call 0x2cea*/
/*22f8 ret */
void sub_122e1()
{
  ax = 0x43e6;
  push(ax);
  ax = 0x1b90;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*22f9 mov ax, 0x43e6*/
/*22fc push ax*/
/*22fd mov ax, 0x1b93*/
/*2300 push ax*/
/*2301 mov ax, 0x10*/
/*2304 push ax*/
/*2305 mov ax, 0xf*/
/*2308 push ax*/
/*2309 mov ax, 2*/
/*230c push ax*/
/*230d call 0x2cea*/
/*2310 ret */
void sub_122f9()
{
  ax = 0x43e6;
  push(ax);
  ax = 0x1b93;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2311 mov ax, 0x43e6*/
/*2314 push ax*/
/*2315 mov ax, 0x1b96*/
/*2318 push ax*/
/*2319 mov ax, 0x10*/
/*231c push ax*/
/*231d mov ax, 0xf*/
/*2320 push ax*/
/*2321 mov ax, 2*/
/*2324 push ax*/
/*2325 call 0x2cea*/
/*2328 ret */
void sub_12311()
{
  ax = 0x43e6;
  push(ax);
  ax = 0x1b96;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2329 dec word ptr [0]*/
/*232d mov ax, word ptr [0x9534]*/
/*2330 cmp ax, 2*/
/*2333 je 0x2368*/
/*2335 cmp ax, 1*/
/*2338 je 0x2354*/
/*233a cmp ax, 0*/
/*233d je 0x2340*/
/*233f ret */
/*2340 mov ax, 0x1b90*/
/*2343 push ax*/
/*2344 mov ax, 2*/
/*2347 push ax*/
/*2348 mov ax, 0xf*/
/*234b push ax*/
/*234c mov ax, 0*/
/*234f push ax*/
/*2350 call 0x2d9a*/
/*2353 ret */
/*2354 mov ax, 0x1b93*/
/*2357 push ax*/
/*2358 mov ax, 2*/
/*235b push ax*/
/*235c mov ax, 0xf*/
/*235f push ax*/
/*2360 mov ax, 0*/
/*2363 push ax*/
/*2364 call 0x2d9a*/
/*2367 ret */
/*2368 mov ax, 0x1b96*/
/*236b push ax*/
/*236c mov ax, 2*/
/*236f push ax*/
/*2370 mov ax, 0xf*/
/*2373 push ax*/
/*2374 mov ax, 0*/
/*2377 push ax*/
/*2378 call 0x2d9a*/
/*237b ret */
void sub_12329()
{
  memoryASet16(ds, 0x9534, memoryAGet16(ds, 0x9534) - 1);
  ax = memoryAGet16(ds, 0x9534);
  
  if (ax == 0x0002) goto loc_12368;
  
  if (ax == 0x0001) goto loc_12354;
  
  if (ax == 0x0000) goto loc_12340;
  return;
loc_12340:
  ax = 0x1b90;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_12354:
  ax = 0x1b93;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_12368:
  ax = 0x1b96;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
}

/*237c mov word ptr [0], 6*/
/*2382 mov word ptr [0], 0*/
/*2388 call 0x23d4*/
/*238b call 0x23ec*/
/*238e call 0x2404*/
/*2391 call 0x241c*/
/*2394 call 0x2434*/
/*2397 call 0x244c*/
/*239a ret */
void sub_1237c()
{
  memoryASet16(ds, 0x9536, 0x0006);
  memoryASet16(ds, 0x9538, 0x0000);
  sub_123d4();
  sub_123ec();
  sub_12404();
  sub_1241c();
  sub_12434();
  sub_1244c();
  return;
}

/*239b inc word ptr [0]*/
/*239f mov ax, word ptr [0x9536]*/
/*23a2 cmp ax, 6*/
/*23a5 jbe 0x23ae*/
/*23a7 mov word ptr [0], 6*/
/*23ad ret */
/*23ae push ax*/
/*23af mov al, 8*/
/*23b1 call 0x3840*/
/*23b4 pop ax*/
/*23b5 cmp ax, 1*/
/*23b8 je 0x23d4*/
/*23ba cmp ax, 2*/
/*23bd je 0x23ec*/
/*23bf cmp ax, 3*/
/*23c2 je 0x2404*/
/*23c4 cmp ax, 4*/
/*23c7 je 0x241c*/
/*23c9 cmp ax, 5*/
/*23cc je 0x2434*/
/*23ce cmp ax, 6*/
/*23d1 je 0x244c*/
/*23d3 ret */
/*23d4 mov ax, 0x43ee*/
/*23d7 push ax*/
/*23d8 mov ax, 0x1b99*/
/*23db push ax*/
/*23dc mov ax, 0x10*/
/*23df push ax*/
/*23e0 mov ax, 0xf*/
/*23e3 push ax*/
/*23e4 mov ax, 2*/
/*23e7 push ax*/
/*23e8 call 0x2cea*/
/*23eb ret */
/*23ec mov ax, 0x43ee*/
/*23ef push ax*/
/*23f0 mov ax, 0x1b9b*/
/*23f3 push ax*/
/*23f4 mov ax, 0x10*/
/*23f7 push ax*/
/*23f8 mov ax, 0xf*/
/*23fb push ax*/
/*23fc mov ax, 2*/
/*23ff push ax*/
/*2400 call 0x2cea*/
/*2403 ret */
/*2404 mov ax, 0x43ee*/
/*2407 push ax*/
/*2408 mov ax, 0x1b9d*/
/*240b push ax*/
/*240c mov ax, 0x10*/
/*240f push ax*/
/*2410 mov ax, 0xf*/
/*2413 push ax*/
/*2414 mov ax, 2*/
/*2417 push ax*/
/*2418 call 0x2cea*/
/*241b ret */
/*241c mov ax, 0x43ee*/
/*241f push ax*/
/*2420 mov ax, 0x1b9f*/
/*2423 push ax*/
/*2424 mov ax, 0x10*/
/*2427 push ax*/
/*2428 mov ax, 0xf*/
/*242b push ax*/
/*242c mov ax, 2*/
/*242f push ax*/
/*2430 call 0x2cea*/
/*2433 ret */
/*2434 mov ax, 0x43ee*/
/*2437 push ax*/
/*2438 mov ax, 0x1ba1*/
/*243b push ax*/
/*243c mov ax, 0x10*/
/*243f push ax*/
/*2440 mov ax, 0xf*/
/*2443 push ax*/
/*2444 mov ax, 2*/
/*2447 push ax*/
/*2448 call 0x2cea*/
/*244b ret */
/*244c mov ax, 0x43ee*/
/*244f push ax*/
/*2450 mov ax, 0x1ba3*/
/*2453 push ax*/
/*2454 mov ax, 0x10*/
/*2457 push ax*/
/*2458 mov ax, 0xf*/
/*245b push ax*/
/*245c mov ax, 2*/
/*245f push ax*/
/*2460 call 0x2cea*/
/*2463 ret */
void sub_1239b()
{
  memoryASet16(ds, 0x9536, memoryAGet16(ds, 0x9536) + 1);
  ax = memoryAGet16(ds, 0x9536);
  
  if (ax <= 0x0006) goto loc_123ae;
  memoryASet16(ds, 0x9536, 0x0006);
  return;
loc_123ae:
  push(ax);
  al = 0x08;
  sub_13840();
  ax = pop();
  
  if (ax == 0x0001) goto loc_123d4;
  
  if (ax == 0x0002) goto loc_123ec;
  
  if (ax == 0x0003) goto loc_12404;
  
  if (ax == 0x0004) goto loc_1241c;
  
  if (ax == 0x0005) goto loc_12434;
  
  if (ax == 0x0006) goto loc_1244c;
  return;
loc_123d4:
  ax = 0x43ee;
  push(ax);
  ax = 0x1b99;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_123ec:
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9b;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_12404:
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9d;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_1241c:
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9f;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_12434:
  ax = 0x43ee;
  push(ax);
  ax = 0x1ba1;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_1244c:
  ax = 0x43ee;
  push(ax);
  ax = 0x1ba3;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*23d4 mov ax, 0x43ee*/
/*23d7 push ax*/
/*23d8 mov ax, 0x1b99*/
/*23db push ax*/
/*23dc mov ax, 0x10*/
/*23df push ax*/
/*23e0 mov ax, 0xf*/
/*23e3 push ax*/
/*23e4 mov ax, 2*/
/*23e7 push ax*/
/*23e8 call 0x2cea*/
/*23eb ret */
void sub_123d4()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1b99;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*23ec mov ax, 0x43ee*/
/*23ef push ax*/
/*23f0 mov ax, 0x1b9b*/
/*23f3 push ax*/
/*23f4 mov ax, 0x10*/
/*23f7 push ax*/
/*23f8 mov ax, 0xf*/
/*23fb push ax*/
/*23fc mov ax, 2*/
/*23ff push ax*/
/*2400 call 0x2cea*/
/*2403 ret */
void sub_123ec()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9b;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2404 mov ax, 0x43ee*/
/*2407 push ax*/
/*2408 mov ax, 0x1b9d*/
/*240b push ax*/
/*240c mov ax, 0x10*/
/*240f push ax*/
/*2410 mov ax, 0xf*/
/*2413 push ax*/
/*2414 mov ax, 2*/
/*2417 push ax*/
/*2418 call 0x2cea*/
/*241b ret */
void sub_12404()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9d;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*241c mov ax, 0x43ee*/
/*241f push ax*/
/*2420 mov ax, 0x1b9f*/
/*2423 push ax*/
/*2424 mov ax, 0x10*/
/*2427 push ax*/
/*2428 mov ax, 0xf*/
/*242b push ax*/
/*242c mov ax, 2*/
/*242f push ax*/
/*2430 call 0x2cea*/
/*2433 ret */
void sub_1241c()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1b9f;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2434 mov ax, 0x43ee*/
/*2437 push ax*/
/*2438 mov ax, 0x1ba1*/
/*243b push ax*/
/*243c mov ax, 0x10*/
/*243f push ax*/
/*2440 mov ax, 0xf*/
/*2443 push ax*/
/*2444 mov ax, 2*/
/*2447 push ax*/
/*2448 call 0x2cea*/
/*244b ret */
void sub_12434()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1ba1;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*244c mov ax, 0x43ee*/
/*244f push ax*/
/*2450 mov ax, 0x1ba3*/
/*2453 push ax*/
/*2454 mov ax, 0x10*/
/*2457 push ax*/
/*2458 mov ax, 0xf*/
/*245b push ax*/
/*245c mov ax, 2*/
/*245f push ax*/
/*2460 call 0x2cea*/
/*2463 ret */
void sub_1244c()
{
  ax = 0x43ee;
  push(ax);
  ax = 0x1ba3;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2464 mov ax, word ptr [0x9536]*/
/*2467 dec word ptr [0]*/
/*246b jns 0x2474*/
/*246d mov word ptr [0], 0*/
/*2473 ret */
/*2474 cmp ax, 1*/
/*2477 je 0x2493*/
/*2479 cmp ax, 2*/
/*247c je 0x24a7*/
/*247e cmp ax, 3*/
/*2481 je 0x24bb*/
/*2483 cmp ax, 4*/
/*2486 je 0x24cf*/
/*2488 cmp ax, 5*/
/*248b je 0x24e3*/
/*248d cmp ax, 6*/
/*2490 je 0x24f7*/
/*2492 ret */
/*2493 mov ax, 0x1b99*/
/*2496 push ax*/
/*2497 mov ax, 2*/
/*249a push ax*/
/*249b mov ax, 0xf*/
/*249e push ax*/
/*249f mov ax, 0*/
/*24a2 push ax*/
/*24a3 call 0x2d9a*/
/*24a6 ret */
/*24a7 mov ax, 0x1b9b*/
/*24aa push ax*/
/*24ab mov ax, 2*/
/*24ae push ax*/
/*24af mov ax, 0xf*/
/*24b2 push ax*/
/*24b3 mov ax, 0*/
/*24b6 push ax*/
/*24b7 call 0x2d9a*/
/*24ba ret */
/*24bb mov ax, 0x1b9d*/
/*24be push ax*/
/*24bf mov ax, 2*/
/*24c2 push ax*/
/*24c3 mov ax, 0xf*/
/*24c6 push ax*/
/*24c7 mov ax, 0*/
/*24ca push ax*/
/*24cb call 0x2d9a*/
/*24ce ret */
/*24cf mov ax, 0x1b9f*/
/*24d2 push ax*/
/*24d3 mov ax, 2*/
/*24d6 push ax*/
/*24d7 mov ax, 0xf*/
/*24da push ax*/
/*24db mov ax, 0*/
/*24de push ax*/
/*24df call 0x2d9a*/
/*24e2 ret */
/*24e3 mov ax, 0x1ba1*/
/*24e6 push ax*/
/*24e7 mov ax, 2*/
/*24ea push ax*/
/*24eb mov ax, 0xf*/
/*24ee push ax*/
/*24ef mov ax, 0*/
/*24f2 push ax*/
/*24f3 call 0x2d9a*/
/*24f6 ret */
/*24f7 mov ax, 0x1ba3*/
/*24fa push ax*/
/*24fb mov ax, 2*/
/*24fe push ax*/
/*24ff mov ax, 0xf*/
/*2502 push ax*/
/*2503 mov ax, 0*/
/*2506 push ax*/
/*2507 call 0x2d9a*/
/*250a ret */
void sub_12464()
{
  ax = memoryAGet16(ds, 0x9536);
  memoryASet16(ds, 0x9536, memoryAGet16(ds, 0x9536) - 1);
  if ((short)memoryAGet16(ds, 0x9536) >= 0) goto loc_12474;
  memoryASet16(ds, 0x9536, 0x0000);
  return;
loc_12474:
  
  if (ax == 0x0001) goto loc_12493;
  
  if (ax == 0x0002) goto loc_124a7;
  
  if (ax == 0x0003) goto loc_124bb;
  
  if (ax == 0x0004) goto loc_124cf;
  
  if (ax == 0x0005) goto loc_124e3;
  
  if (ax == 0x0006) goto loc_124f7;
  return;
loc_12493:
  ax = 0x1b99;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_124a7:
  ax = 0x1b9b;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_124bb:
  ax = 0x1b9d;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_124cf:
  ax = 0x1b9f;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_124e3:
  ax = 0x1ba1;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
loc_124f7:
  ax = 0x1ba3;
  push(ax);
  ax = 0x0002;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_12d9a();
  return;
}

/*250b mov word ptr [0], 0x2c*/
/*2511 mov word ptr [0], 0*/
/*2517 mov ax, 0x48f6*/
/*251a push ax*/
/*251b mov ax, 0x1b88*/
/*251e push ax*/
/*251f mov ax, 0x2c*/
/*2522 push ax*/
/*2523 mov ax, 7*/
/*2526 push ax*/
/*2527 mov ax, 2*/
/*252a push ax*/
/*252b call 0x2cea*/
/*252e ret */
void sub_1250b()
{
  memoryASet16(ds, 0x953a, 0x002c);
  memoryASet16(ds, 0x953c, 0x0000);
  ax = 0x48f6;
  push(ax);
  ax = 0x1b88;
  push(ax);
  ax = 0x002c;
  push(ax);
  ax = 0x0007;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*252f mov ax, word ptr [0x953a]*/
/*2532 dec ax*/
/*2533 jns 0x2536*/
/*2535 ret */
/*2536 mov word ptr [0x953a], ax*/
/*2539 push ax*/
/*253a mov ax, 0x1b88*/
/*253d push ax*/
/*253e call 0x25e3*/
/*2541 ret */
void sub_1252f()
{
  ax = memoryAGet16(ds, 0x953a);
  ax--;
  if ((short)ax >= 0) goto loc_12536;
  return;
loc_12536:
  memoryASet16(ds, 0x953a, ax);
  push(ax);
  ax = 0x1b88;
  push(ax);
  sub_125e3();
  return;
}

/*2542 mov ax, word ptr [0x953a]*/
/*2545 cmp ax, 0x2c*/
/*2548 jb 0x254b*/
/*254a ret */
/*254b call 0x2536*/
/*254e inc word ptr [0]*/
/*2552 ret */
void sub_12542()
{
  ax = memoryAGet16(ds, 0x953a);
  
  if (ax < 0x002c) goto loc_1254b;
  return;
loc_1254b:
  sub_12536();
  memoryASet16(ds, 0x953a, memoryAGet16(ds, 0x953a) + 1);
  return;
}

/*2536 mov word ptr [0x953a], ax*/
/*2539 push ax*/
/*253a mov ax, 0x1b88*/
/*253d push ax*/
/*253e call 0x25e3*/
/*2541 ret */
void sub_12536()
{
  memoryASet16(ds, 0x953a, ax);
  push(ax);
  ax = 0x1b88;
  push(ax);
  sub_125e3();
  return;
}

/*2553 mov word ptr [0], 0x30*/
/*2559 mov word ptr [0], 0*/
/*255f mov ax, 0x2ce6*/
/*2562 push ax*/
/*2563 mov ax, 0x1cc8*/
/*2566 push ax*/
/*2567 mov ax, 0x30*/
/*256a push ax*/
/*256b mov ax, 7*/
/*256e push ax*/
/*256f mov ax, 2*/
/*2572 push ax*/
/*2573 call 0x2cea*/
/*2576 ret */
void sub_12553()
{
  memoryASet16(ds, 0x953e, 0x0030);
  memoryASet16(ds, 0x9540, 0x0000);
  ax = 0x2ce6;
  push(ax);
  ax = 0x1cc8;
  push(ax);
  ax = 0x0030;
  push(ax);
  ax = 0x0007;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2577 mov ax, word ptr [0x953e]*/
/*257a dec ax*/
/*257b jns 0x257e*/
/*257d ret */
/*257e mov word ptr [0x953e], ax*/
/*2581 push ax*/
/*2582 mov ax, 0x1cc8*/
/*2585 push ax*/
/*2586 call 0x25e3*/
/*2589 ret */
void sub_12577()
{
  ax = memoryAGet16(ds, 0x953e);
  ax--;
  if ((short)ax >= 0) goto loc_1257e;
  return;
loc_1257e:
  memoryASet16(ds, 0x953e, ax);
  push(ax);
  ax = 0x1cc8;
  push(ax);
  sub_125e3();
  return;
}

/*258a mov ax, word ptr [0x953e]*/
/*258d cmp ax, 0x30*/
/*2590 jb 0x2593*/
/*2592 ret */
/*2593 call 0x257e*/
/*2596 inc word ptr [0]*/
/*259a ret */
void sub_1258a()
{
  ax = memoryAGet16(ds, 0x953e);
  
  if (ax < 0x0030) goto loc_12593;
  return;
loc_12593:
  sub_1257e();
  memoryASet16(ds, 0x953e, memoryAGet16(ds, 0x953e) + 1);
  return;
}

/*257e mov word ptr [0x953e], ax*/
/*2581 push ax*/
/*2582 mov ax, 0x1cc8*/
/*2585 push ax*/
/*2586 call 0x25e3*/
/*2589 ret */
void sub_1257e()
{
  memoryASet16(ds, 0x953e, ax);
  push(ax);
  ax = 0x1cc8;
  push(ax);
  sub_125e3();
  return;
}

/*259b mov word ptr [0], 0x38*/
/*25a1 mov word ptr [0], 0*/
/*25a7 mov ax, 0x4496*/
/*25aa push ax*/
/*25ab mov ax, 0x1e08*/
/*25ae push ax*/
/*25af mov ax, 0x38*/
/*25b2 push ax*/
/*25b3 mov ax, 7*/
/*25b6 push ax*/
/*25b7 mov ax, 2*/
/*25ba push ax*/
/*25bb call 0x2cea*/
/*25be ret */
void sub_1259b()
{
  memoryASet16(ds, 0x9542, 0x0038);
  memoryASet16(ds, 0x9544, 0x0000);
  ax = 0x4496;
  push(ax);
  ax = 0x1e08;
  push(ax);
  ax = 0x0038;
  push(ax);
  ax = 0x0007;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*25bf mov ax, word ptr [0x9542]*/
/*25c2 dec ax*/
/*25c3 jns 0x25c6*/
/*25c5 ret */
/*25c6 mov word ptr [0x9542], ax*/
/*25c9 push ax*/
/*25ca mov ax, 0x1e08*/
/*25cd push ax*/
/*25ce call 0x25e3*/
/*25d1 ret */
void sub_125bf()
{
  ax = memoryAGet16(ds, 0x9542);
  ax--;
  if ((short)ax >= 0) goto loc_125c6;
  return;
loc_125c6:
  memoryASet16(ds, 0x9542, ax);
  push(ax);
  ax = 0x1e08;
  push(ax);
  sub_125e3();
  return;
}

/*25d2 mov ax, word ptr [0x9542]*/
/*25d5 cmp ax, 0x38*/
/*25d8 jb 0x25db*/
/*25da ret */
/*25db call 0x25c6*/
/*25de inc word ptr [0]*/
/*25e2 ret */
void sub_125d2()
{
  ax = memoryAGet16(ds, 0x9542);
  
  if (ax < 0x0038) goto loc_125db;
  return;
loc_125db:
  sub_125c6();
  memoryASet16(ds, 0x9542, memoryAGet16(ds, 0x9542) + 1);
  return;
}

/*25c6 mov word ptr [0x9542], ax*/
/*25c9 push ax*/
/*25ca mov ax, 0x1e08*/
/*25cd push ax*/
/*25ce call 0x25e3*/
/*25d1 ret */
void sub_125c6()
{
  memoryASet16(ds, 0x9542, ax);
  push(ax);
  ax = 0x1e08;
  push(ax);
  sub_125e3();
  return;
}

/*25e3 push bp*/
/*25e4 mov bp, sp*/
/*25e6 mov ax, 0xa000*/
/*25e9 mov es, ax*/
/*25eb mov ax, word ptr [bp + 6]*/
/*25ee shr ax, 1*/
/*25f0 shr ax, 1*/
/*25f2 shr ax, 1*/
/*25f4 add ax, word ptr [bp + 4]*/
/*25f7 mov di, ax*/
/*25f9 mov dx, 0x3ce*/
/*25fc mov ax, 0x805*/
/*25ff out dx, ax*/
/*2600 mov cx, word ptr [bp + 6]*/
/*2603 and cx, 7*/
/*2606 mov ah, 0x80*/
/*2608 shr ah, cl*/
/*260a mov al, 8*/
/*260c out dx, ax*/
/*260d mov bl, ah*/
/*260f mov ax, 0x1803*/
/*2612 out dx, ax*/
/*2613 mov ax, 0xf01*/
/*2616 out dx, ax*/
/*2617 mov ax, 0x700*/
/*261a out dx, ax*/
/*261b mov cx, 7*/
/*261e mov al, byte ptr es:[di]*/
/*2621 test bl, al*/
/*2623 jne 0x262d*/
/*2625 mov byte ptr es:[di], bl*/
/*2628 mov byte ptr es:[di + 0x2000], bl*/
/*262d add di, 0x28*/
/*2630 loop 0x261e*/
/*2632 mov ax, 5*/
/*2635 out dx, ax*/
/*2636 mov ax, 0xff08*/
/*2639 out dx, ax*/
/*263a mov ax, 3*/
/*263d out dx, ax*/
/*263e mov ax, 1*/
/*2641 out dx, ax*/
/*2642 mov ax, 0*/
/*2645 out dx, ax*/
/*2646 pop bp*/
/*2647 ret 4*/
void sub_125e3()
{
  push(bp);
  bp = sp;
  ax = 0xa000;
  es = ax;
  ax = memoryAGet16(ss, bp + 6 - 2);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax += memoryAGet16(ss, bp + 4 - 2);
  di = ax;
  dx = 0x03ce;
  ax = 0x0805;
  out16(dx, ax);
  cx = memoryAGet16(ss, bp + 6 - 2);
  cx &= 0x0007;
  ah = 0x80;
  ah >>= cl;
  al = 0x08;
  out16(dx, ax);
  bl = ah;
  ax = 0x1803;
  out16(dx, ax);
  ax = 0x0f01;
  out16(dx, ax);
  ax = 0x0700;
  out16(dx, ax);
  cx = 0x0007;
loc_1261e:
  al = memoryAGet(es, di);
  
  if (!(bl & al)) goto loc_1262d;
  memoryASet(es, di, bl);
  memoryASet(es, di + 8192, bl);
loc_1262d:
  di += 0x0028;
  if (--cx) goto loc_1261e;
  ax = 0x0005;
  out16(dx, ax);
  ax = 0xff08;
  out16(dx, ax);
  ax = 0x0003;
  out16(dx, ax);
  ax = 0x0001;
  out16(dx, ax);
  ax = 0x0000;
  out16(dx, ax);
  bp = pop();
  return;
}

/*264a mov al, 0*/
/*264c mov byte ptr [0x94a9], al*/
/*264f mov byte ptr [0x94aa], al*/
/*2652 mov byte ptr [0x94ab], al*/
/*2655 mov byte ptr [0x94ac], al*/
/*2658 mov byte ptr [0x94ad], al*/
/*265b mov byte ptr [0x94ae], al*/
/*265e call 0x2714*/
/*2661 ret */
void sub_1264a()
{
  al = 0x00;
  memoryASet(ds, 0x94a9, al);
  memoryASet(ds, 0x94aa, al);
  memoryASet(ds, 0x94ab, al);
  memoryASet(ds, 0x94ac, al);
  memoryASet(ds, 0x94ad, al);
  memoryASet(ds, 0x94ae, al);
  sub_12714();
  return;
}

/*2662 mov ax, 0*/
/*2665 push ax*/
/*2666 mov ax, 0*/
/*2669 push ax*/
/*266a mov ax, 1*/
/*266d push ax*/
/*266e mov ax, 0*/
/*2671 push ax*/
/*2672 call 0x269e*/
/*2675 ret */
void sub_12662()
{
  ax = 0x0000;
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x0001;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_1269e();
  return;
}

/*2676 mov ax, 0*/
/*2679 push ax*/
/*267a mov ax, 1*/
/*267d push ax*/
/*267e mov ax, 5*/
/*2681 push ax*/
/*2682 mov ax, 0*/
/*2685 push ax*/
/*2686 call 0x269e*/
/*2689 ret */
void sub_12676()
{
  ax = 0x0000;
  push(ax);
  ax = 0x0001;
  push(ax);
  ax = 0x0005;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_1269e();
  return;
}

/*269e push bp*/
/*269f mov bp, sp*/
/*26a1 mov al, byte ptr [0x94ae]*/
/*26a4 add al, byte ptr [bp + 4]*/
/*26a7 cmp al, 9*/
/*26a9 jbe 0x26b1*/
/*26ab sub al, 0xa*/
/*26ad inc byte ptr [0]*/
/*26b1 mov byte ptr [0x94ae], al*/
/*26b4 mov al, byte ptr [0x94ad]*/
/*26b7 add al, byte ptr [bp + 6]*/
/*26ba cmp al, 9*/
/*26bc jbe 0x26c4*/
/*26be sub al, 0xa*/
/*26c0 inc byte ptr [0]*/
/*26c4 mov byte ptr [0x94ad], al*/
/*26c7 mov al, byte ptr [0x94ac]*/
/*26ca add al, byte ptr [bp + 8]*/
/*26cd cmp al, 9*/
/*26cf jbe 0x26d7*/
/*26d1 sub al, 0xa*/
/*26d3 inc byte ptr [0]*/
/*26d7 mov byte ptr [0x94ac], al*/
/*26da mov al, byte ptr [0x94ab]*/
/*26dd add al, byte ptr [bp + 0xa]*/
/*26e0 cmp al, 9*/
/*26e2 jbe 0x26ea*/
/*26e4 sub al, 0xa*/
/*26e6 inc byte ptr [0]*/
/*26ea mov byte ptr [0x94ab], al*/
/*26ed mov al, byte ptr [0x94aa]*/
/*26f0 cmp al, 9*/
/*26f2 jbe 0x2701*/
/*26f4 sub al, 0xa*/
/*26f6 inc byte ptr [0]*/
/*26fa push ax*/
/*26fb push si*/
/*26fc call 0x22c1*/
/*26ff pop si*/
/*2700 pop ax*/
/*2701 mov byte ptr [0x94aa], al*/
/*2704 mov al, byte ptr [0x94a9]*/
/*2707 cmp al, 9*/
/*2709 jbe 0x270d*/
/*270b sub al, 0xa*/
/*270d mov byte ptr [0x94a9], al*/
/*2710 pop bp*/
/*2711 ret 8*/
void sub_1269e()
{
  push(bp);
  bp = sp;
  al = memoryAGet(ds, 0x94ae);
  al += memoryAGet(ss, bp + 4 - 2);
  
  if (al <= 0x09) goto loc_126b1;
  al -= 0x0a;
  memoryASet(ds, 0x94ad, memoryAGet(ds, 0x94ad) + 1);
loc_126b1:
  memoryASet(ds, 0x94ae, al);
  al = memoryAGet(ds, 0x94ad);
  al += memoryAGet(ss, bp + 6 - 2);
  
  if (al <= 0x09) goto loc_126c4;
  al -= 0x0a;
  memoryASet(ds, 0x94ac, memoryAGet(ds, 0x94ac) + 1);
loc_126c4:
  memoryASet(ds, 0x94ad, al);
  al = memoryAGet(ds, 0x94ac);
  al += memoryAGet(ss, bp + 8 - 2);
  
  if (al <= 0x09) goto loc_126d7;
  al -= 0x0a;
  memoryASet(ds, 0x94ab, memoryAGet(ds, 0x94ab) + 1);
loc_126d7:
  memoryASet(ds, 0x94ac, al);
  al = memoryAGet(ds, 0x94ab);
  al += memoryAGet(ss, bp + 10 - 2);
  
  if (al <= 0x09) goto loc_126ea;
  al -= 0x0a;
  memoryASet(ds, 0x94aa, memoryAGet(ds, 0x94aa) + 1);
loc_126ea:
  memoryASet(ds, 0x94ab, al);
  al = memoryAGet(ds, 0x94aa);
  
  if (al <= 0x09) goto loc_12701;
  al -= 0x0a;
  memoryASet(ds, 0x94a9, memoryAGet(ds, 0x94a9) + 1);
  push(ax);
  push(si);
  sub_122c1();
  si = pop();
  ax = pop();
loc_12701:
  memoryASet(ds, 0x94aa, al);
  al = memoryAGet(ds, 0x94a9);
  
  if (al <= 0x09) goto loc_1270d;
  al -= 0x0a;
loc_1270d:
  memoryASet(ds, 0x94a9, al);
  bp = pop();
  return;
}

/*22c1 inc word ptr [0]*/
/*22c5 mov ax, word ptr [0x9534]*/
/*22c8 cmp ax, 3*/
/*22cb jbe 0x22d4*/
/*22cd mov word ptr [0], 3*/
/*22d3 ret */
/*22d4 je 0x2311*/
/*22d6 cmp ax, 2*/
/*22d9 je 0x22f9*/
/*22db cmp ax, 1*/
/*22de je 0x22e1*/
/*22e0 ret */
/*22e1 mov ax, 0x43e6*/
/*22e4 push ax*/
/*22e5 mov ax, 0x1b90*/
/*22e8 push ax*/
/*22e9 mov ax, 0x10*/
/*22ec push ax*/
/*22ed mov ax, 0xf*/
/*22f0 push ax*/
/*22f1 mov ax, 2*/
/*22f4 push ax*/
/*22f5 call 0x2cea*/
/*22f8 ret */
/*22f9 mov ax, 0x43e6*/
/*22fc push ax*/
/*22fd mov ax, 0x1b93*/
/*2300 push ax*/
/*2301 mov ax, 0x10*/
/*2304 push ax*/
/*2305 mov ax, 0xf*/
/*2308 push ax*/
/*2309 mov ax, 2*/
/*230c push ax*/
/*230d call 0x2cea*/
/*2310 ret */
/*2311 mov ax, 0x43e6*/
/*2314 push ax*/
/*2315 mov ax, 0x1b96*/
/*2318 push ax*/
/*2319 mov ax, 0x10*/
/*231c push ax*/
/*231d mov ax, 0xf*/
/*2320 push ax*/
/*2321 mov ax, 2*/
/*2324 push ax*/
/*2325 call 0x2cea*/
/*2328 ret */
void sub_122c1()
{
  memoryASet16(ds, 0x9534, memoryAGet16(ds, 0x9534) + 1);
  ax = memoryAGet16(ds, 0x9534);
  
  if (ax <= 0x0003) goto loc_122d4;
  memoryASet16(ds, 0x9534, 0x0003);
  return;
loc_122d4:
  if (ax == 0x0003) goto loc_12311;
  
  if (ax == 0x0002) goto loc_122f9;
  
  if (ax == 0x0001) goto loc_122e1;
  return;
loc_122e1:
  ax = 0x43e6;
  push(ax);
  ax = 0x1b90;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_122f9:
  ax = 0x43e6;
  push(ax);
  ax = 0x1b93;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
loc_12311:
  ax = 0x43e6;
  push(ax);
  ax = 0x1b96;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  return;
}

/*2714 mov byte ptr [0], 1*/
/*2719 mov si, 0x94a9*/
/*271c mov cx, 6*/
/*271f mov dx, 0*/
/*2722 push cx*/
/*2723 lodsb al, byte ptr [si]*/
/*2724 cmp al, 0*/
/*2726 je 0x272d*/
/*2728 mov byte ptr [0], 0*/
/*272d mov cl, byte ptr [0]*/
/*2731 cmp cl, 0*/
/*2734 jne 0x275e*/
/*2736 push dx*/
/*2737 push si*/
/*2738 mov bh, 0*/
/*273a mov bl, al*/
/*273c shl bx, 1*/
/*273e mov ax, word ptr [bx + 0x155f]*/
/*2742 push ax*/
/*2743 mov bx, dx*/
/*2745 mov ax, word ptr [bx + 0x1573]*/
/*2749 push ax*/
/*274a mov ax, 0x10*/
/*274d push ax*/
/*274e mov ax, 9*/
/*2751 push ax*/
/*2752 mov ax, 2*/
/*2755 push ax*/
/*2756 call 0x2cea*/
/*2759 pop si*/
/*275a pop dx*/
/*275b add dx, 2*/
/*275e pop cx*/
/*275f loop 0x2722*/
/*2761 ret */
void sub_12714()
{
  memoryASet(ds, 0x944d, 0x01);
  si = 0x94a9;
  cx = 0x0006;
  dx = 0x0000;
loc_12722:
  push(cx);
  al = lodsb<DS_SI>();
  
  if (al == 0x00) goto loc_1272d;
  memoryASet(ds, 0x944d, 0x00);
loc_1272d:
  cl = memoryAGet(ds, 0x944d);
  
  if (cl != 0x00) goto loc_1275e;
  push(dx);
  push(si);
  bh = 0x00;
  bl = al;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5471);
  push(ax);
  bx = dx;
  ax = memoryAGet16(ds, bx + 5491);
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0009;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  si = pop();
  dx = pop();
  dx += 0x0002;
loc_1275e:
  cx = pop();
  if (--cx) goto loc_12722;
  return;
}

/*2762 mov cx, 0x12*/
/*2765 mov ax, ds*/
/*2767 mov es, ax*/
/*2769 mov di, 0x94af*/
/*276c cld */
/*276d mov ax, 0*/
/*2770 rep stosw word ptr es:[di], ax*/
/*2772 mov cx, 0x2a*/
/*2775 mov di, 0x9455*/
/*2778 mov al, 0x2e*/
/*277a mov ah, 0x2e*/
/*277c rep stosw word ptr es:[di], ax*/
/*277e mov byte ptr [0], 0x5f*/
/*2783 mov al, 0*/
/*2785 mov cx, 7*/
/*2788 mov si, 0x94da*/
/*278b mov byte ptr [si], al*/
/*278d inc al*/
/*278f inc si*/
/*2790 loop 0x278b*/
/*2792 mov di, 0x9455*/
/*2795 mov dx, 0x1506*/
/*2798 mov cx, 0x8c*/
/*279b call 0x644*/
/*279e ret */
void sub_12762()
{
  cx = 0x0012;
  ax = ds;
  es = ax;
  di = 0x94af;
  flags.direction = 0;
  ax = 0x0000;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  cx = 0x002a;
  di = 0x9455;
  al = 0x2e;
  ah = 0x2e;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  memoryASet(ds, 0x9455, 0x5f);
  al = 0x00;
  cx = 0x0007;
  si = 0x94da;
loc_1278b:
  memoryASet(ds, si, al);
  al++;
  si++;
  if (--cx) goto loc_1278b;
  di = 0x9455;
  dx = 0x1506;
  cx = 0x008c;
  sub_10644();
  return;
}

/*644 mov ax, ds*/
/*646 mov word ptr [0x8f20], ax*/
/*649 call 0x64d*/
/*64c ret */
void sub_10644()
{
  ax = ds;
  memoryASet16(ds, 0x8f20, ax);
  sub_1064d();
  return;
}

/*279f call 0x2809*/
/*27a2 mov al, byte ptr [0x94e0]*/
/*27a5 cmp al, 0*/
/*27a7 jne 0x27af*/
/*27a9 mov byte ptr [0], 0*/
/*27ae ret */
/*27af mov byte ptr [0], 1*/
/*27b4 mov bl, al*/
/*27b6 shl bl, 1*/
/*27b8 add bl, al*/
/*27ba mov bh, 0*/
/*27bc shl bx, 1*/
/*27be push bx*/
/*27bf add bx, 0x94a9*/
/*27c3 mov si, 0x94a9*/
/*27c6 mov cx, 6*/
/*27c9 lodsb al, byte ptr [si]*/
/*27ca mov byte ptr [bx], al*/
/*27cc inc bx*/
/*27cd loop 0x27c9*/
/*27cf pop bx*/
/*27d0 shl bx, 1*/
/*27d2 add bx, 0x9455*/
/*27d6 mov word ptr [0], bx*/
/*27da mov si, 0x9455*/
/*27dd mov cx, 0xc*/
/*27e0 lodsb al, byte ptr [si]*/
/*27e1 mov byte ptr [bx], al*/
/*27e3 inc bx*/
/*27e4 loop 0x27e0*/
/*27e6 mov si, 0x94da*/
/*27e9 mov al, byte ptr [si]*/
/*27eb cmp al, 0*/
/*27ed je 0x27f2*/
/*27ef inc si*/
/*27f0 jmp 0x27e9*/
/*27f2 mov al, byte ptr [0x94e0]*/
/*27f5 mov byte ptr [si], al*/
/*27f7 mov byte ptr [0], 0*/
/*27fc sub si, 0x94da*/
/*2800 mov ax, si*/
/*2802 mov byte ptr [0x9450], al*/
/*2805 call 0x28da*/
/*2808 ret */
void sub_1279f()
{
  sub_12809();
  al = memoryAGet(ds, 0x94e0);
  
  if (al != 0x00) goto loc_127af;
  memoryASet(ds, 0x9546, 0x00);
  return;
loc_127af:
  memoryASet(ds, 0x9546, 0x01);
  bl = al;
  bl <<= 0x01;
  bl += al;
  bh = 0x00;
  bx <<= 0x0001;
  push(bx);
  bx += 0x94a9;
  si = 0x94a9;
  cx = 0x0006;
loc_127c9:
  al = lodsb<DS_SI>();
  memoryASet(ds, bx, al);
  bx++;
  if (--cx) goto loc_127c9;
  bx = pop();
  bx <<= 0x0001;
  bx += 0x9455;
  memoryASet16(ds, 0x9451, bx);
  si = 0x9455;
  cx = 0x000c;
loc_127e0:
  al = lodsb<DS_SI>();
  memoryASet(ds, bx, al);
  bx++;
  if (--cx) goto loc_127e0;
  si = 0x94da;
loc_127e9:
  al = memoryAGet(ds, si);
  
  if (al == 0x00) goto loc_127f2;
  si++;
  goto loc_127e9;
loc_127f2:
  al = memoryAGet(ds, 0x94e0);
  memoryASet(ds, si, al);
  memoryASet(ds, 0x94e0, 0x00);
  si -= 0x94da;
  ax = si;
  memoryASet(ds, 0x9450, al);
  sub_128da();
  return;
}

/*2809 mov al, byte ptr [0x94da]*/
/*280c mov byte ptr [0x94d3], al*/
/*280f mov al, byte ptr [0x94db]*/
/*2812 mov byte ptr [0x94d4], al*/
/*2815 mov al, byte ptr [0x94dc]*/
/*2818 mov byte ptr [0x94d5], al*/
/*281b mov al, byte ptr [0x94dd]*/
/*281e mov byte ptr [0x94d6], al*/
/*2821 mov al, byte ptr [0x94de]*/
/*2824 mov byte ptr [0x94d7], al*/
/*2827 mov al, byte ptr [0x94df]*/
/*282a mov byte ptr [0x94d8], al*/
/*282d mov al, byte ptr [0x94e0]*/
/*2830 mov byte ptr [0x94d9], al*/
/*2833 mov si, 0x94d3*/
/*2836 mov di, 0x94da*/
/*2839 mov cx, 7*/
/*283c push cx*/
/*283d push si*/
/*283e mov al, byte ptr [si]*/
/*2840 cmp al, 0xff*/
/*2842 jne 0x2847*/
/*2844 inc si*/
/*2845 jmp 0x283e*/
/*2847 cmp si, 0x94d9*/
/*284b je 0x2865*/
/*284d mov bx, si*/
/*284f inc bx*/
/*2850 mov al, byte ptr [bx]*/
/*2852 cmp al, 0xff*/
/*2854 je 0x285f*/
/*2856 call 0x2872*/
/*2859 cmp al, 0*/
/*285b je 0x285f*/
/*285d mov si, bx*/
/*285f cmp bx, 0x94d9*/
/*2863 jne 0x284f*/
/*2865 mov al, byte ptr [si]*/
/*2867 mov byte ptr [si], 0xff*/
/*286a mov byte ptr [di], al*/
/*286c inc di*/
/*286d pop si*/
/*286e pop cx*/
/*286f loop 0x283c*/
/*2871 ret */
void sub_12809()
{
  al = memoryAGet(ds, 0x94da);
  memoryASet(ds, 0x94d3, al);
  al = memoryAGet(ds, 0x94db);
  memoryASet(ds, 0x94d4, al);
  al = memoryAGet(ds, 0x94dc);
  memoryASet(ds, 0x94d5, al);
  al = memoryAGet(ds, 0x94dd);
  memoryASet(ds, 0x94d6, al);
  al = memoryAGet(ds, 0x94de);
  memoryASet(ds, 0x94d7, al);
  al = memoryAGet(ds, 0x94df);
  memoryASet(ds, 0x94d8, al);
  al = memoryAGet(ds, 0x94e0);
  memoryASet(ds, 0x94d9, al);
  si = 0x94d3;
  di = 0x94da;
  cx = 0x0007;
loc_1283c:
  push(cx);
  push(si);
loc_1283e:
  al = memoryAGet(ds, si);
  
  if (al != 0xff) goto loc_12847;
  si++;
  goto loc_1283e;
loc_12847:
  
  if (si == 0x94d9) goto loc_12865;
  bx = si;
loc_1284f:
  bx++;
  al = memoryAGet(ds, bx);
  
  if (al == 0xff) goto loc_1285f;
  sub_12872();
  
  if (al == 0x00) goto loc_1285f;
  si = bx;
loc_1285f:
  
  if (bx != 0x94d9) goto loc_1284f;
loc_12865:
  al = memoryAGet(ds, si);
  memoryASet(ds, si, 0xff);
  memoryASet(ds, di, al);
  di++;
  si = pop();
  cx = pop();
  if (--cx) goto loc_1283c;
  return;
}

/*2872 push si*/
/*2873 push di*/
/*2874 mov al, byte ptr [si]*/
/*2876 mov ah, al*/
/*2878 shl al, 1*/
/*287a add al, ah*/
/*287c shl al, 1*/
/*287e mov ah, 0*/
/*2880 add ax, 0x94a9*/
/*2883 mov si, ax*/
/*2885 mov al, byte ptr [bx]*/
/*2887 mov ah, al*/
/*2889 shl al, 1*/
/*288b add al, ah*/
/*288d shl al, 1*/
/*288f mov ah, 0*/
/*2891 add ax, 0x94a9*/
/*2894 mov di, ax*/
/*2896 mov al, byte ptr [di]*/
/*2898 cmp al, byte ptr [si]*/
/*289a ja 0x28d5*/
/*289c jb 0x28d0*/
/*289e mov al, byte ptr [di + 1]*/
/*28a1 cmp al, byte ptr [si + 1]*/
/*28a4 ja 0x28d5*/
/*28a6 jb 0x28d0*/
/*28a8 mov al, byte ptr [di + 2]*/
/*28ab cmp al, byte ptr [si + 2]*/
/*28ae ja 0x28d5*/
/*28b0 jb 0x28d0*/
/*28b2 mov al, byte ptr [di + 3]*/
/*28b5 cmp al, byte ptr [si + 3]*/
/*28b8 ja 0x28d5*/
/*28ba jb 0x28d0*/
/*28bc mov al, byte ptr [di + 4]*/
/*28bf cmp al, byte ptr [si + 4]*/
/*28c2 ja 0x28d5*/
/*28c4 jb 0x28d0*/
/*28c6 mov al, byte ptr [di + 5]*/
/*28c9 cmp al, byte ptr [si + 5]*/
/*28cc ja 0x28d5*/
/*28ce jb 0x28d0*/
/*28d0 mov al, 0*/
/*28d2 pop di*/
/*28d3 pop si*/
/*28d4 ret */
/*28d5 mov al, 1*/
/*28d7 pop di*/
/*28d8 pop si*/
/*28d9 ret */
void sub_12872()
{
  push(si);
  push(di);
  al = memoryAGet(ds, si);
  ah = al;
  al <<= 0x01;
  al += ah;
  al <<= 0x01;
  ah = 0x00;
  ax += 0x94a9;
  si = ax;
  al = memoryAGet(ds, bx);
  ah = al;
  al <<= 0x01;
  al += ah;
  al <<= 0x01;
  ah = 0x00;
  ax += 0x94a9;
  di = ax;
  al = memoryAGet(ds, di);
  
  if (al > memoryAGet(ds, si)) goto loc_128d5;
  if (al < memoryAGet(ds, si)) goto loc_128d0;
  al = memoryAGet(ds, di + 1);
  
  if (al > memoryAGet(ds, si + 1)) goto loc_128d5;
  if (al < memoryAGet(ds, si + 1)) goto loc_128d0;
  al = memoryAGet(ds, di + 2);
  
  if (al > memoryAGet(ds, si + 2)) goto loc_128d5;
  if (al < memoryAGet(ds, si + 2)) goto loc_128d0;
  al = memoryAGet(ds, di + 3);
  
  if (al > memoryAGet(ds, si + 3)) goto loc_128d5;
  if (al < memoryAGet(ds, si + 3)) goto loc_128d0;
  al = memoryAGet(ds, di + 4);
  
  if (al > memoryAGet(ds, si + 4)) goto loc_128d5;
  if (al < memoryAGet(ds, si + 4)) goto loc_128d0;
  al = memoryAGet(ds, di + 5);
  
  if (al > memoryAGet(ds, si + 5)) goto loc_128d5;
  if (al < memoryAGet(ds, si + 5)) goto loc_128d0;
loc_128d0:
  al = 0x00;
  di = pop();
  si = pop();
  return;
loc_128d5:
  al = 0x01;
  di = pop();
  si = pop();
  return;
}

/*28da mov si, 0x94da*/
/*28dd mov di, 0x1b1*/
/*28e0 mov cx, 6*/
/*28e3 push cx*/
/*28e4 add di, 2*/
/*28e7 mov ax, word ptr [di]*/
/*28e9 add di, 2*/
/*28ec push si*/
/*28ed push di*/
/*28ee call 0x2959*/
/*28f1 pop di*/
/*28f2 pop si*/
/*28f3 add di, 2*/
/*28f6 mov ax, word ptr [di]*/
/*28f8 add di, 2*/
/*28fb push si*/
/*28fc push di*/
/*28fd call 0x2907*/
/*2900 pop di*/
/*2901 pop si*/
/*2902 inc si*/
/*2903 pop cx*/
/*2904 loop 0x28e3*/
/*2906 ret */
void sub_128da()
{
  si = 0x94da;
  di = 0x01b1;
  cx = 0x0006;
loc_128e3:
  push(cx);
  di += 0x0002;
  ax = memoryAGet16(ds, di);
  di += 0x0002;
  push(si);
  push(di);
  sub_12959();
  di = pop();
  si = pop();
  di += 0x0002;
  ax = memoryAGet16(ds, di);
  di += 0x0002;
  push(si);
  push(di);
  sub_12907();
  di = pop();
  si = pop();
  si++;
  cx = pop();
  if (--cx) goto loc_128e3;
  return;
}

/*2907 mov word ptr [0x944e], ax*/
/*290a mov al, byte ptr [si]*/
/*290c mov ah, al*/
/*290e shl al, 1*/
/*2910 add al, ah*/
/*2912 mov ah, 0*/
/*2914 shl ax, 1*/
/*2916 add ax, 0x94a9*/
/*2919 mov si, ax*/
/*291b mov byte ptr [0], 1*/
/*2920 mov cx, 6*/
/*2923 mov dx, 0*/
/*2926 push cx*/
/*2927 lodsb al, byte ptr [si]*/
/*2928 cmp al, 0*/
/*292a je 0x2931*/
/*292c mov byte ptr [0], 0*/
/*2931 mov cl, byte ptr [0]*/
/*2935 cmp cl, 0*/
/*2938 je 0x293f*/
/*293a mov ax, 0x6f6c*/
/*293d jmp 0x2949*/
/*293f mov bh, 0*/
/*2941 mov bl, al*/
/*2943 shl bx, 1*/
/*2945 mov ax, word ptr [bx + 0x157f]*/
/*2949 push dx*/
/*294a push si*/
/*294b push ax*/
/*294c push dx*/
/*294d call 0x29ae*/
/*2950 pop si*/
/*2951 pop dx*/
/*2952 add dx, 6*/
/*2955 pop cx*/
/*2956 loop 0x2926*/
/*2958 ret */
void sub_12907()
{
  memoryASet16(ds, 0x944e, ax);
  al = memoryAGet(ds, si);
  ah = al;
  al <<= 0x01;
  al += ah;
  ah = 0x00;
  ax <<= 0x0001;
  ax += 0x94a9;
  si = ax;
  memoryASet(ds, 0x944d, 0x01);
  cx = 0x0006;
  dx = 0x0000;
loc_12926:
  push(cx);
  al = lodsb<DS_SI>();
  
  if (al == 0x00) goto loc_12931;
  memoryASet(ds, 0x944d, 0x00);
loc_12931:
  cl = memoryAGet(ds, 0x944d);
  
  if (cl == 0x00) goto loc_1293f;
  ax = 0x6f6c;
  goto loc_12949;
loc_1293f:
  bh = 0x00;
  bl = al;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5503);
loc_12949:
  push(dx);
  push(si);
  push(ax);
  push(dx);
  sub_129ae();
  si = pop();
  dx = pop();
  dx += 0x0006;
  cx = pop();
  if (--cx) goto loc_12926;
  return;
}

/*2959 mov word ptr [0x944e], ax*/
/*295c mov al, byte ptr [si]*/
/*295e mov ah, al*/
/*2960 shl al, 1*/
/*2962 add al, ah*/
/*2964 mov ah, 0*/
/*2966 shl ax, 1*/
/*2968 shl ax, 1*/
/*296a add ax, 0x9455*/
/*296d mov si, ax*/
/*296f mov cx, 0xc*/
/*2972 mov dx, 0*/
/*2975 push cx*/
/*2976 lodsb al, byte ptr [si]*/
/*2977 push si*/
/*2978 push dx*/
/*2979 cmp al, 0x20*/
/*297b jne 0x2982*/
/*297d mov ax, 0x6546*/
/*2980 jmp 0x29a0*/
/*2982 cmp al, 0x2e*/
/*2984 jne 0x298b*/
/*2986 mov ax, 0x6f6c*/
/*2989 jmp 0x29a0*/
/*298b cmp al, 0x5f*/
/*298d jne 0x2994*/
/*298f mov ax, 0x764c*/
/*2992 jmp 0x29a0*/
/*2994 sub al, 0x41*/
/*2996 mov ah, al*/
/*2998 shl al, 1*/
/*299a add al, ah*/
/*299c shl al, 1*/
/*299e mov ah, 0*/
/*29a0 push ax*/
/*29a1 push dx*/
/*29a2 call 0x29ae*/
/*29a5 pop dx*/
/*29a6 add dx, 6*/
/*29a9 pop si*/
/*29aa pop cx*/
/*29ab loop 0x2975*/
/*29ad ret */
void sub_12959()
{
  memoryASet16(ds, 0x944e, ax);
  al = memoryAGet(ds, si);
  ah = al;
  al <<= 0x01;
  al += ah;
  ah = 0x00;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += 0x9455;
  si = ax;
  cx = 0x000c;
  dx = 0x0000;
loc_12975:
  push(cx);
  al = lodsb<DS_SI>();
  push(si);
  push(dx);
  
  if (al != 0x20) goto loc_12982;
  ax = 0x6546;
  goto loc_129a0;
loc_12982:
  
  if (al != 0x2e) goto loc_1298b;
  ax = 0x6f6c;
  goto loc_129a0;
loc_1298b:
  
  if (al != 0x5f) goto loc_12994;
  ax = 0x764c;
  goto loc_129a0;
loc_12994:
  al -= 0x41;
  ah = al;
  al <<= 0x01;
  al += ah;
  al <<= 0x01;
  ah = 0x00;
loc_129a0:
  push(ax);
  push(dx);
  sub_129ae();
  dx = pop();
  dx += 0x0006;
  si = pop();
  cx = pop();
  if (--cx) goto loc_12975;
  return;
}

/*29ae push bp*/
/*29af mov bp, sp*/
/*29b1 mov ax, word ptr [0x94f0]*/
/*29b4 mov es, ax*/
/*29b6 mov di, word ptr [0]*/
/*29ba add di, word ptr [bp + 4]*/
/*29bd mov ax, word ptr [0x94ea]*/
/*29c0 push ds*/
/*29c1 mov ds, ax*/
/*29c3 mov si, word ptr [bp + 6]*/
/*29c6 mov cx, 0xb*/
/*29c9 movsw word ptr es:[di], word ptr [si]*/
/*29ca movsw word ptr es:[di], word ptr [si]*/
/*29cb movsw word ptr es:[di], word ptr [si]*/
/*29cc add di, 0x9a*/
/*29d0 add si, 0x9a*/
/*29d4 loop 0x29c9*/
/*29d6 pop ds*/
/*29d7 pop bp*/
/*29d8 ret 4*/
void sub_129ae()
{
  push(bp);
  bp = sp;
  ax = memoryAGet16(ds, 0x94f0);
  es = ax;
  di = memoryAGet16(ds, 0x944e);
  di += memoryAGet16(ss, bp + 4 - 2);
  ax = memoryAGet16(ds, 0x94ea);
  push(ds);
  ds = ax;
  si = memoryAGet16(ss, bp + 6 - 2);
  cx = 0x000b;
loc_129c9:
  movsw<ES_DI, DS_SI>();
  movsw<ES_DI, DS_SI>();
  movsw<ES_DI, DS_SI>();
  di += 0x009a;
  si += 0x009a;
  if (--cx) goto loc_129c9;
  ds = pop();
  bp = pop();
  return;
}

/*29db mov word ptr [0], 0*/
/*29e1 mov ax, word ptr [0x9453]*/
/*29e4 cmp ax, 0xc*/
/*29e7 jae 0x2a39*/
/*29e9 call 0x541*/
/*29ec cmp al, 0*/
/*29ee je 0x2a39*/
/*29f0 cmp al, 8*/
/*29f2 jne 0x2a0d*/
/*29f4 mov bx, word ptr [0]*/
/*29f8 add bx, word ptr [0]*/
/*29fc mov byte ptr [bx], 0x2e*/
/*29ff dec word ptr [0]*/
/*2a03 jns 0x2a0b*/
/*2a05 mov word ptr [0], 0*/
/*2a0b jmp 0x2a1b*/
/*2a0d mov bx, word ptr [0]*/
/*2a11 add bx, word ptr [0]*/
/*2a15 mov byte ptr [bx], al*/
/*2a17 inc word ptr [0]*/
/*2a1b mov bx, word ptr [0]*/
/*2a1f cmp bx, 0xc*/
/*2a22 jae 0x2a2b*/
/*2a24 add bx, word ptr [0]*/
/*2a28 mov byte ptr [bx], 0x5f*/
/*2a2b call 0x2a64*/
/*2a2e call 0x3498*/
/*2a31 call 0xb8e*/
/*2a34 call 0x3383*/
/*2a37 jmp 0x29e1*/
/*2a39 mov bx, word ptr [0]*/
/*2a3d cmp bx, 0xc*/
/*2a40 jae 0x2a52*/
/*2a42 add bx, word ptr [0]*/
/*2a46 mov al, byte ptr [bx]*/
/*2a48 cmp al, 0x5f*/
/*2a4a jne 0x2a52*/
/*2a4c mov byte ptr [bx], 0x2e*/
/*2a4f call 0x2a64*/
/*2a52 mov di, 0x9455*/
/*2a55 mov dx, 0x1506*/
/*2a58 mov cx, 0x8c*/
/*2a5b call 0x674*/
/*2a5e mov byte ptr [0], 0*/
/*2a63 ret */
void sub_129db()
{
  memoryASet16(ds, 0x9453, 0x0000);
loc_129e1:
  ax = memoryAGet16(ds, 0x9453);
  
  if (ax >= 0x000c) goto loc_12a39;
  sub_10541();
  
  if (al == 0x00) goto loc_12a39;
  
  if (al != 0x08) goto loc_12a0d;
  bx = memoryAGet16(ds, 0x9451);
  bx += memoryAGet16(ds, 0x9453);
  memoryASet(ds, bx, 0x2e);
  memoryASet16(ds, 0x9453, memoryAGet16(ds, 0x9453) - 1);
  if ((short)memoryAGet16(ds, 0x9453) >= 0) goto loc_12a0b;
  memoryASet16(ds, 0x9453, 0x0000);
loc_12a0b:
  goto loc_12a1b;
loc_12a0d:
  bx = memoryAGet16(ds, 0x9451);
  bx += memoryAGet16(ds, 0x9453);
  memoryASet(ds, bx, al);
  memoryASet16(ds, 0x9453, memoryAGet16(ds, 0x9453) + 1);
loc_12a1b:
  bx = memoryAGet16(ds, 0x9453);
  
  if (bx >= 0x000c) goto loc_12a2b;
  bx += memoryAGet16(ds, 0x9451);
  memoryASet(ds, bx, 0x5f);
loc_12a2b:
  sub_12a64();
  sub_13498();
  sub_10b8e();
  sub_13383();
  goto loc_129e1;
loc_12a39:
  bx = memoryAGet16(ds, 0x9453);
  
  if (bx >= 0x000c) goto loc_12a52;
  bx += memoryAGet16(ds, 0x9451);
  al = memoryAGet(ds, bx);
  
  if (al != 0x5f) goto loc_12a52;
  memoryASet(ds, bx, 0x2e);
  sub_12a64();
loc_12a52:
  di = 0x9455;
  dx = 0x1506;
  cx = 0x008c;
  sub_10674();
  memoryASet(ds, 0x9546, 0x00);
  return;
}

/*541 mov cx, 0x4e20*/
/*544 mov si, 0x8e8a*/
/*547 mov ah, 0*/
/*549 cld */
/*54a lodsb al, byte ptr [si]*/
/*54b cmp al, 0*/
/*54d je 0x557*/
/*54f mov ah, 1*/
/*551 cmp si, word ptr [0]*/
/*555 jne 0x55f*/
/*557 cmp si, 0x8f0a*/
/*55b je 0x55f*/
/*55d jmp 0x54a*/
/*55f je 0x578*/
/*561 mov word ptr [0], si*/
/*565 sub si, 0x8e8b*/
/*569 mov al, byte ptr [si + 0x5a]*/
/*56d cmp al, 0*/
/*56f je 0x576*/
/*571 jns 0x575*/
/*573 mov al, 0*/
/*575 ret */
/*576 jmp 0x583*/
/*578 cmp ah, 0*/
/*57b jne 0x583*/
/*57d mov word ptr [0], 0*/
/*583 loop 0x544*/
/*585 mov al, 0*/
/*587 ret */
void sub_10541()
{
  cx = 0x4e20;
loc_10544:
  si = 0x8e8a;
  ah = 0x00;
  flags.direction = 0;
loc_1054a:
  al = lodsb<DS_SI>();
  
  if (al == 0x00) goto loc_10557;
  ah = 0x01;
  
  if (si != memoryAGet16(ds, 0x8f0b)) goto loc_1055f;
loc_10557:
  
  if (si == 0x8f0a) goto loc_1055f;
  goto loc_1054a;
loc_1055f:
  if (si == 0x8f0a) goto loc_10578;
  memoryASet16(ds, 0x8f0b, si);
  si -= 0x8e8b;
  al = memoryAGet(ds, si + 90);
  
  if (al == 0x00) goto loc_10576;
  if ((char)al >= 0) goto loc_10575;
  al = 0x00;
loc_10575:
  return;
loc_10576:
  goto loc_10583;
loc_10578:
  
  if (ah != 0x00) goto loc_10583;
  memoryASet16(ds, 0x8f0b, 0x0000);
loc_10583:
  if (--cx) goto loc_10544;
  al = 0x00;
  return;
}

/*674 push di*/
/*675 push cx*/
/*676 mov cx, 0*/
/*679 mov ax, 0x3c00*/
/*67c int 0x21*/
/*67e pop cx*/
/*67f pop dx*/
/*680 jae 0x683*/
/*682 ret */
/*683 mov word ptr [0x8f1e], ax*/
/*686 mov bx, ax*/
/*688 mov ax, 0x4000*/
/*68b int 0x21*/
/*68d jae 0x690*/
/*68f ret */
/*690 mov ax, 0x3e00*/
/*693 mov bx, word ptr [0]*/
/*697 int 0x21*/
/*699 ret */
void sub_10674()
{
  push(di);
  push(cx);
  cx = 0x0000;
  ax = 0x3c00;
  interrupt(0x21);
  cx = pop();
  dx = pop();
  if (!flags.carry) goto loc_10683;
  return;
loc_10683:
  memoryASet16(ds, 0x8f1e, ax);
  bx = ax;
  ax = 0x4000;
  interrupt(0x21);
  if (!flags.carry) goto loc_10690;
  return;
loc_10690:
  ax = 0x3e00;
  bx = memoryAGet16(ds, 0x8f1e);
  interrupt(0x21);
  return;
}

/*2a64 mov si, word ptr [0]*/
/*2a68 mov bl, byte ptr [0]*/
/*2a6c mov bh, 0*/
/*2a6e shl bx, 1*/
/*2a70 shl bx, 1*/
/*2a72 shl bx, 1*/
/*2a74 mov ax, word ptr [bx + 0x1b3]*/
/*2a78 mov word ptr [0x944e], ax*/
/*2a7b call 0x296f*/
/*2a7e ret */
void sub_12a64()
{
  si = memoryAGet16(ds, 0x9451);
  bl = memoryAGet(ds, 0x9450);
  bh = 0x00;
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 435);
  memoryASet16(ds, 0x944e, ax);
  sub_1296f();
  return;
}

/*296f mov cx, 0xc*/
/*2972 mov dx, 0*/
/*2975 push cx*/
/*2976 lodsb al, byte ptr [si]*/
/*2977 push si*/
/*2978 push dx*/
/*2979 cmp al, 0x20*/
/*297b jne 0x2982*/
/*297d mov ax, 0x6546*/
/*2980 jmp 0x29a0*/
/*2982 cmp al, 0x2e*/
/*2984 jne 0x298b*/
/*2986 mov ax, 0x6f6c*/
/*2989 jmp 0x29a0*/
/*298b cmp al, 0x5f*/
/*298d jne 0x2994*/
/*298f mov ax, 0x764c*/
/*2992 jmp 0x29a0*/
/*2994 sub al, 0x41*/
/*2996 mov ah, al*/
/*2998 shl al, 1*/
/*299a add al, ah*/
/*299c shl al, 1*/
/*299e mov ah, 0*/
/*29a0 push ax*/
/*29a1 push dx*/
/*29a2 call 0x29ae*/
/*29a5 pop dx*/
/*29a6 add dx, 6*/
/*29a9 pop si*/
/*29aa pop cx*/
/*29ab loop 0x2975*/
/*29ad ret */
void sub_1296f()
{
  cx = 0x000c;
  dx = 0x0000;
loc_12975:
  push(cx);
  al = lodsb<DS_SI>();
  push(si);
  push(dx);
  
  if (al != 0x20) goto loc_12982;
  ax = 0x6546;
  goto loc_129a0;
loc_12982:
  
  if (al != 0x2e) goto loc_1298b;
  ax = 0x6f6c;
  goto loc_129a0;
loc_1298b:
  
  if (al != 0x5f) goto loc_12994;
  ax = 0x764c;
  goto loc_129a0;
loc_12994:
  al -= 0x41;
  ah = al;
  al <<= 0x01;
  al += ah;
  al <<= 0x01;
  ah = 0x00;
loc_129a0:
  push(ax);
  push(dx);
  sub_129ae();
  dx = pop();
  dx += 0x0006;
  si = pop();
  cx = pop();
  if (--cx) goto loc_12975;
  return;
}

/*2a7f mov byte ptr [0], 0*/
/*2a84 mov byte ptr [0], 0*/
/*2a89 mov byte ptr [0], 0*/
/*2a8e mov byte ptr [0], 0*/
/*2a93 mov byte ptr [0], 0*/
/*2a98 mov byte ptr [0], 0*/
/*2a9d mov ax, 0x1178*/
/*2aa0 push ax*/
/*2aa1 mov ax, 0x1b82*/
/*2aa4 push ax*/
/*2aa5 mov ax, 0x10*/
/*2aa8 push ax*/
/*2aa9 mov ax, 8*/
/*2aac push ax*/
/*2aad mov ax, 4*/
/*2ab0 push ax*/
/*2ab1 call 0x2cea*/
/*2ab4 mov ax, 0x1678*/
/*2ab7 push ax*/
/*2ab8 mov ax, 0x1cc2*/
/*2abb push ax*/
/*2abc mov ax, 0x10*/
/*2abf push ax*/
/*2ac0 mov ax, 8*/
/*2ac3 push ax*/
/*2ac4 mov ax, 4*/
/*2ac7 push ax*/
/*2ac8 call 0x2cea*/
/*2acb mov ax, 0x1b78*/
/*2ace push ax*/
/*2acf mov ax, 0x1e02*/
/*2ad2 push ax*/
/*2ad3 mov ax, 0x10*/
/*2ad6 push ax*/
/*2ad7 mov ax, 8*/
/*2ada push ax*/
/*2adb mov ax, 4*/
/*2ade push ax*/
/*2adf call 0x2cea*/
/*2ae2 mov ax, 0x2078*/
/*2ae5 push ax*/
/*2ae6 mov ax, 0x1b85*/
/*2ae9 push ax*/
/*2aea mov ax, 0x10*/
/*2aed push ax*/
/*2aee mov ax, 8*/
/*2af1 push ax*/
/*2af2 mov ax, 4*/
/*2af5 push ax*/
/*2af6 call 0x2cea*/
/*2af9 mov ax, 0x2578*/
/*2afc push ax*/
/*2afd mov ax, 0x1cc5*/
/*2b00 push ax*/
/*2b01 mov ax, 0x10*/
/*2b04 push ax*/
/*2b05 mov ax, 8*/
/*2b08 push ax*/
/*2b09 mov ax, 4*/
/*2b0c push ax*/
/*2b0d call 0x2cea*/
/*2b10 mov ax, 0x2a78*/
/*2b13 push ax*/
/*2b14 mov ax, 0x1e05*/
/*2b17 push ax*/
/*2b18 mov ax, 0x10*/
/*2b1b push ax*/
/*2b1c mov ax, 8*/
/*2b1f push ax*/
/*2b20 mov ax, 4*/
/*2b23 push ax*/
/*2b24 call 0x2cea*/
/*2b27 ret */
void sub_12a7f()
{
  memoryASet(ds, 0x952e, 0x00);
  memoryASet(ds, 0x952f, 0x00);
  memoryASet(ds, 0x9530, 0x00);
  memoryASet(ds, 0x9531, 0x00);
  memoryASet(ds, 0x9532, 0x00);
  memoryASet(ds, 0x9533, 0x00);
  ax = 0x1178;
  push(ax);
  ax = 0x1b82;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  ax = 0x1678;
  push(ax);
  ax = 0x1cc2;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  ax = 0x1b78;
  push(ax);
  ax = 0x1e02;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  ax = 0x2078;
  push(ax);
  ax = 0x1b85;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  ax = 0x2578;
  push(ax);
  ax = 0x1cc5;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  ax = 0x2a78;
  push(ax);
  ax = 0x1e05;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
}

/*2b28 push ax*/
/*2b29 mov ax, 0*/
/*2b2c push ax*/
/*2b2d mov ax, 1*/
/*2b30 push ax*/
/*2b31 mov ax, 5*/
/*2b34 push ax*/
/*2b35 mov ax, 0*/
/*2b38 push ax*/
/*2b39 call 0x269e*/
/*2b3c pop ax*/
/*2b3d cmp al, 0*/
/*2b3f je 0x2b59*/
/*2b41 cmp al, 1*/
/*2b43 je 0x2b76*/
/*2b45 cmp al, 2*/
/*2b47 je 0x2b93*/
/*2b49 cmp al, 3*/
/*2b4b je 0x2bb0*/
/*2b4d cmp al, 4*/
/*2b4f je 0x2bcd*/
/*2b51 cmp al, 5*/
/*2b53 jne 0x2b58*/
/*2b55 jmp 0x2bea*/
/*2b58 ret */
/*2b59 mov byte ptr [0], 1*/
/*2b5e mov ax, 0x2f78*/
/*2b61 push ax*/
/*2b62 mov ax, 0x1b82*/
/*2b65 push ax*/
/*2b66 mov ax, 0x10*/
/*2b69 push ax*/
/*2b6a mov ax, 8*/
/*2b6d push ax*/
/*2b6e mov ax, 4*/
/*2b71 push ax*/
/*2b72 call 0x2cea*/
/*2b75 ret */
/*2b76 mov byte ptr [0], 1*/
/*2b7b mov ax, 0x2f78*/
/*2b7e push ax*/
/*2b7f mov ax, 0x1cc2*/
/*2b82 push ax*/
/*2b83 mov ax, 0x10*/
/*2b86 push ax*/
/*2b87 mov ax, 8*/
/*2b8a push ax*/
/*2b8b mov ax, 4*/
/*2b8e push ax*/
/*2b8f call 0x2cea*/
/*2b92 ret */
/*2b93 mov byte ptr [0], 1*/
/*2b98 mov ax, 0x2f78*/
/*2b9b push ax*/
/*2b9c mov ax, 0x1e02*/
/*2b9f push ax*/
/*2ba0 mov ax, 0x10*/
/*2ba3 push ax*/
/*2ba4 mov ax, 8*/
/*2ba7 push ax*/
/*2ba8 mov ax, 4*/
/*2bab push ax*/
/*2bac call 0x2cea*/
/*2baf ret */
/*2bb0 mov byte ptr [0], 1*/
/*2bb5 mov ax, 0x2f78*/
/*2bb8 push ax*/
/*2bb9 mov ax, 0x1b85*/
/*2bbc push ax*/
/*2bbd mov ax, 0x10*/
/*2bc0 push ax*/
/*2bc1 mov ax, 8*/
/*2bc4 push ax*/
/*2bc5 mov ax, 4*/
/*2bc8 push ax*/
/*2bc9 call 0x2cea*/
/*2bcc ret */
/*2bcd mov byte ptr [0], 1*/
/*2bd2 mov ax, 0x2f78*/
/*2bd5 push ax*/
/*2bd6 mov ax, 0x1cc5*/
/*2bd9 push ax*/
/*2bda mov ax, 0x10*/
/*2bdd push ax*/
/*2bde mov ax, 8*/
/*2be1 push ax*/
/*2be2 mov ax, 4*/
/*2be5 push ax*/
/*2be6 call 0x2cea*/
/*2be9 ret */
/*2bea mov byte ptr [0], 1*/
/*2bef mov ax, 0x2f78*/
/*2bf2 push ax*/
/*2bf3 mov ax, 0x1e05*/
/*2bf6 push ax*/
/*2bf7 mov ax, 0x10*/
/*2bfa push ax*/
/*2bfb mov ax, 8*/
/*2bfe push ax*/
/*2bff mov ax, 4*/
/*2c02 push ax*/
/*2c03 call 0x2cea*/
/*2c06 ret */
void sub_12b28()
{
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x0001;
  push(ax);
  ax = 0x0005;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_1269e();
  ax = pop();
  
  if (al == 0x00) goto loc_12b59;
  
  if (al == 0x01) goto loc_12b76;
  
  if (al == 0x02) goto loc_12b93;
  
  if (al == 0x03) goto loc_12bb0;
  
  if (al == 0x04) goto loc_12bcd;
  
  if (al != 0x05) goto loc_12b58;
  goto loc_12bea;
loc_12b58:
  return;
loc_12b59:
  memoryASet(ds, 0x952e, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1b82;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
loc_12b76:
  memoryASet(ds, 0x952f, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1cc2;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
loc_12b93:
  memoryASet(ds, 0x9530, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1e02;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
loc_12bb0:
  memoryASet(ds, 0x9531, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1b85;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
loc_12bcd:
  memoryASet(ds, 0x9532, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1cc5;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
loc_12bea:
  memoryASet(ds, 0x9533, 0x01);
  ax = 0x2f78;
  push(ax);
  ax = 0x1e05;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0008;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
}

/*2c07 mov ax, 0xa0b*/
/*2c0a push ax*/
/*2c0b mov ax, 0x13*/
/*2c0e push ax*/
/*2c0f mov ax, 0x30*/
/*2c12 push ax*/
/*2c13 mov ax, 5*/
/*2c16 push ax*/
/*2c17 call 0x2d9a*/
/*2c1a mov ax, 0xaac*/
/*2c1d push ax*/
/*2c1e mov ax, 0x11*/
/*2c21 push ax*/
/*2c22 mov ax, 0x28*/
/*2c25 push ax*/
/*2c26 mov ax, 2*/
/*2c29 push ax*/
/*2c2a call 0x2d9a*/
/*2c2d mov ax, 0x5a5c*/
/*2c30 push ax*/
/*2c31 mov ax, 0xb4d*/
/*2c34 push ax*/
/*2c35 mov ax, 0x78*/
/*2c38 push ax*/
/*2c39 mov ax, 0xf*/
/*2c3c push ax*/
/*2c3d mov ax, 4*/
/*2c40 push ax*/
/*2c41 call 0x2cea*/
/*2c44 ret */
void sub_12c07()
{
  ax = 0x0a0b;
  push(ax);
  ax = 0x0013;
  push(ax);
  ax = 0x0030;
  push(ax);
  ax = 0x0005;
  push(ax);
  sub_12d9a();
  ax = 0x0aac;
  push(ax);
  ax = 0x0011;
  push(ax);
  ax = 0x0028;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12d9a();
  ax = 0x5a5c;
  push(ax);
  ax = 0x0b4d;
  push(ax);
  ax = 0x0078;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
}

/*2c45 mov ax, 0xaac*/
/*2c48 push ax*/
/*2c49 mov ax, 0x10*/
/*2c4c push ax*/
/*2c4d mov ax, 0x28*/
/*2c50 push ax*/
/*2c51 mov ax, 5*/
/*2c54 push ax*/
/*2c55 call 0x2d9a*/
/*2c58 mov ax, 0xb4d*/
/*2c5b push ax*/
/*2c5c mov ax, 0xe*/
/*2c5f push ax*/
/*2c60 mov ax, 0x20*/
/*2c63 push ax*/
/*2c64 mov ax, 2*/
/*2c67 push ax*/
/*2c68 call 0x2d9a*/
/*2c6b mov ax, 0x7592*/
/*2c6e push ax*/
/*2c6f mov ax, 0xc8f*/
/*2c72 push ax*/
/*2c73 mov ax, 0x28*/
/*2c76 push ax*/
/*2c77 mov ax, 0xc*/
/*2c7a push ax*/
/*2c7b mov ax, 2*/
/*2c7e push ax*/
/*2c7f call 0x2cea*/
/*2c82 mov ax, 0x1ab8*/
/*2c85 push ax*/
/*2c86 mov ax, 0xce4*/
/*2c89 push ax*/
/*2c8a mov ax, 0x20*/
/*2c8d push ax*/
/*2c8e mov ax, 0xd*/
/*2c91 push ax*/
/*2c92 mov ax, 4*/
/*2c95 push ax*/
/*2c96 call 0x2cea*/
/*2c99 ret */
void sub_12c45()
{
  ax = 0x0aac;
  push(ax);
  ax = 0x0010;
  push(ax);
  ax = 0x0028;
  push(ax);
  ax = 0x0005;
  push(ax);
  sub_12d9a();
  ax = 0x0b4d;
  push(ax);
  ax = 0x000e;
  push(ax);
  ax = 0x0020;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12d9a();
  ax = 0x7592;
  push(ax);
  ax = 0x0c8f;
  push(ax);
  ax = 0x0028;
  push(ax);
  ax = 0x000c;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12cea();
  ax = 0x1ab8;
  push(ax);
  ax = 0x0ce4;
  push(ax);
  ax = 0x0020;
  push(ax);
  ax = 0x000d;
  push(ax);
  ax = 0x0004;
  push(ax);
  sub_12cea();
  return;
}

/*2c9a push ax*/
/*2c9b mov ax, 0xdcc*/
/*2c9e push ax*/
/*2c9f mov ax, 0x11*/
/*2ca2 push ax*/
/*2ca3 mov ax, 0xf*/
/*2ca6 push ax*/
/*2ca7 mov ax, 2*/
/*2caa push ax*/
/*2cab call 0x2d9a*/
/*2cae pop ax*/
/*2caf cmp al, 6*/
/*2cb1 jne 0x2cbc*/
/*2cb3 mov al, 0*/
/*2cb5 call 0x2cc7*/
/*2cb8 mov al, 6*/
/*2cba jmp 0x2cc7*/
/*2cbc cmp al, 7*/
/*2cbe jne 0x2cc7*/
/*2cc0 mov al, 1*/
/*2cc2 call 0x2cc7*/
/*2cc5 mov al, 7*/
/*2cc7 mov bl, al*/
/*2cc9 mov bh, 0*/
/*2ccb shl bx, 1*/
/*2ccd mov ax, word ptr [bx + 0x151f]*/
/*2cd1 push ax*/
/*2cd2 mov ax, word ptr [bx + 0x152f]*/
/*2cd6 push ax*/
/*2cd7 mov ax, word ptr [bx + 0x153f]*/
/*2cdb push ax*/
/*2cdc mov ax, word ptr [bx + 0x154f]*/
/*2ce0 push ax*/
/*2ce1 mov ax, word ptr [bx + 0x150f]*/
/*2ce5 push ax*/
/*2ce6 call 0x2cea*/
/*2ce9 ret */
void sub_12c9a()
{
  push(ax);
  ax = 0x0dcc;
  push(ax);
  ax = 0x0011;
  push(ax);
  ax = 0x000f;
  push(ax);
  ax = 0x0002;
  push(ax);
  sub_12d9a();
  ax = pop();
  
  if (al != 0x06) goto loc_12cbc;
  al = 0x00;
  sub_12cc7();
  al = 0x06;
  goto loc_12cc7;
loc_12cbc:
  
  if (al != 0x07) goto loc_12cc7;
  al = 0x01;
  sub_12cc7();
  al = 0x07;
loc_12cc7:
  bl = al;
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5407);
  push(ax);
  ax = memoryAGet16(ds, bx + 5423);
  push(ax);
  ax = memoryAGet16(ds, bx + 5439);
  push(ax);
  ax = memoryAGet16(ds, bx + 5455);
  push(ax);
  ax = memoryAGet16(ds, bx + 5391);
  push(ax);
  sub_12cea();
  return;
}

/*2cc7 mov bl, al*/
/*2cc9 mov bh, 0*/
/*2ccb shl bx, 1*/
/*2ccd mov ax, word ptr [bx + 0x151f]*/
/*2cd1 push ax*/
/*2cd2 mov ax, word ptr [bx + 0x152f]*/
/*2cd6 push ax*/
/*2cd7 mov ax, word ptr [bx + 0x153f]*/
/*2cdb push ax*/
/*2cdc mov ax, word ptr [bx + 0x154f]*/
/*2ce0 push ax*/
/*2ce1 mov ax, word ptr [bx + 0x150f]*/
/*2ce5 push ax*/
/*2ce6 call 0x2cea*/
/*2ce9 ret */
void sub_12cc7()
{
  bl = al;
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 5407);
  push(ax);
  ax = memoryAGet16(ds, bx + 5423);
  push(ax);
  ax = memoryAGet16(ds, bx + 5439);
  push(ax);
  ax = memoryAGet16(ds, bx + 5455);
  push(ax);
  ax = memoryAGet16(ds, bx + 5391);
  push(ax);
  sub_12cea();
  return;
}

/*2cea push bp*/
/*2ceb mov bp, sp*/
/*2ced mov ax, 0xa000*/
/*2cf0 mov es, ax*/
/*2cf2 mov di, word ptr [bp + 0xa]*/
/*2cf5 mov bx, word ptr [bp + 4]*/
/*2cf8 mov bx, word ptr [bx - 0x6b18]*/
/*2cfc mov si, word ptr [bp + 0xc]*/
/*2cff push ds*/
/*2d00 push bx*/
/*2d01 mov dx, 0x3ce*/
/*2d04 mov ax, 0xa05*/
/*2d07 out dx, ax*/
/*2d08 mov ax, 7*/
/*2d0b out dx, ax*/
/*2d0c mov cx, word ptr [bp + 8]*/
/*2d0f shr cx, 1*/
/*2d11 mov ah, 0x80*/
/*2d13 mov al, 8*/
/*2d15 pop ds*/
/*2d16 mov bx, word ptr [bp + 6]*/
/*2d19 push ax*/
/*2d1a push bx*/
/*2d1b push cx*/
/*2d1c push di*/
/*2d1d push si*/
/*2d1e mov bh, 0x22*/
/*2d20 mov bl, byte ptr [si]*/
/*2d22 inc si*/
/*2d23 cmp bh, bl*/
/*2d25 jne 0x2d3d*/
/*2d27 shr ah, 1*/
/*2d29 jne 0x2d32*/
/*2d2b mov ah, 0x40*/
/*2d2d inc di*/
/*2d2e loop 0x2d20*/
/*2d30 jmp 0x2d76*/
/*2d32 shr ah, 1*/
/*2d34 jne 0x2d39*/
/*2d36 mov ah, 0x80*/
/*2d38 inc di*/
/*2d39 loop 0x2d20*/
/*2d3b jmp 0x2d76*/
/*2d3d mov bh, bl*/
/*2d3f shr bl, 1*/
/*2d41 shr bl, 1*/
/*2d43 shr bl, 1*/
/*2d45 shr bl, 1*/
/*2d47 cmp bl, 2*/
/*2d4a je 0x2d55*/
/*2d4c out dx, ax*/
/*2d4d and byte ptr es:[di], bl*/
/*2d50 and byte ptr es:[di + 0x2000], bl*/
/*2d55 shr ah, 1*/
/*2d57 jne 0x2d5c*/
/*2d59 mov ah, 0x80*/
/*2d5b inc di*/
/*2d5c and bh, 0xf*/
/*2d5f cmp bh, 2*/
/*2d62 je 0x2d6d*/
/*2d64 out dx, ax*/
/*2d65 and byte ptr es:[di], bh*/
/*2d68 and byte ptr es:[di + 0x2000], bh*/
/*2d6d shr ah, 1*/
/*2d6f jne 0x2d74*/
/*2d71 mov ah, 0x80*/
/*2d73 inc di*/
/*2d74 loop 0x2d1e*/
/*2d76 pop si*/
/*2d77 add si, 0xa0*/
/*2d7b pop di*/
/*2d7c add di, 0x28*/
/*2d7f and di, 0x7fff*/
/*2d83 pop cx*/
/*2d84 pop bx*/
/*2d85 pop ax*/
/*2d86 dec bx*/
/*2d87 jne 0x2d19*/
/*2d89 pop ds*/
/*2d8a mov ax, 0xff08*/
/*2d8d out dx, ax*/
/*2d8e mov ax, 5*/
/*2d91 out dx, ax*/
/*2d92 mov ax, 0xf07*/
/*2d95 out dx, ax*/
/*2d96 pop bp*/
/*2d97 ret 0xa*/
void sub_12cea()
{
  push(bp);
  bp = sp;
  ax = 0xa000;
  es = ax;
  di = memoryAGet16(ss, bp + 10 - 2);
  bx = memoryAGet16(ss, bp + 4 - 2);
  bx = memoryAGet16(ds, bx + 38120);
  si = memoryAGet16(ss, bp + 12 - 2);
  push(ds);
  push(bx);
  dx = 0x03ce;
  ax = 0x0a05;
  out16(dx, ax);
  ax = 0x0007;
  out16(dx, ax);
  cx = memoryAGet16(ss, bp + 8 - 2);
  cx >>= 0x0001;
  ah = 0x80;
  al = 0x08;
  ds = pop();
  bx = memoryAGet16(ss, bp + 6 - 2);
loc_12d19:
  push(ax);
  push(bx);
  push(cx);
  push(di);
  push(si);
loc_12d1e:
  bh = 0x22;
loc_12d20:
  bl = memoryAGet(ds, si);
  si++;
  
  if (bh != bl) goto loc_12d3d;
  ah >>= 0x01;
  if (ah) goto loc_12d32;
  ah = 0x40;
  di++;
  if (--cx) goto loc_12d20;
  goto loc_12d76;
loc_12d32:
  ah >>= 0x01;
  if (ah) goto loc_12d39;
  ah = 0x80;
  di++;
loc_12d39:
  if (--cx) goto loc_12d20;
  goto loc_12d76;
loc_12d3d:
  bh = bl;
  bl >>= 0x01;
  bl >>= 0x01;
  bl >>= 0x01;
  bl >>= 0x01;
  
  if (bl == 0x02) goto loc_12d55;
  out16(dx, ax);
  memoryASet(es, di, memoryAGet(es, di) & bl);
  memoryASet(es, di + 8192, memoryAGet(es, di + 8192) & bl);
loc_12d55:
  ah >>= 0x01;
  if (ah) goto loc_12d5c;
  ah = 0x80;
  di++;
loc_12d5c:
  bh &= 0x0f;
  
  if (bh == 0x02) goto loc_12d6d;
  out16(dx, ax);
  memoryASet(es, di, memoryAGet(es, di) & bh);
  memoryASet(es, di + 8192, memoryAGet(es, di + 8192) & bh);
loc_12d6d:
  ah >>= 0x01;
  if (ah) goto loc_12d74;
  ah = 0x80;
  di++;
loc_12d74:
  if (--cx) goto loc_12d1e;
loc_12d76:
  si = pop();
  si += 0x00a0;
  di = pop();
  di += 0x0028;
  di &= 0x7fff;
  cx = pop();
  bx = pop();
  ax = pop();
  bx--;
  if (bx) goto loc_12d19;
  ds = pop();
  ax = 0xff08;
  out16(dx, ax);
  ax = 0x0005;
  out16(dx, ax);
  ax = 0x0f07;
  out16(dx, ax);
  bp = pop();
  return;
}

/*2d9a push bp*/
/*2d9b mov bp, sp*/
/*2d9d mov ax, 0xa000*/
/*2da0 mov es, ax*/
/*2da2 mov di, word ptr [bp + 0xa]*/
/*2da5 mov dx, 0x3ce*/
/*2da8 mov ax, word ptr [bp + 4]*/
/*2dab mov ah, al*/
/*2dad mov al, 0*/
/*2daf out dx, ax*/
/*2db0 mov ax, 0xf01*/
/*2db3 out dx, ax*/
/*2db4 cld */
/*2db5 mov bx, word ptr [bp + 6]*/
/*2db8 push di*/
/*2db9 mov cx, word ptr [bp + 8]*/
/*2dbc rep stosb byte ptr es:[di], al*/
/*2dbe pop di*/
/*2dbf push di*/
/*2dc0 add di, 0x2000*/
/*2dc4 mov cx, word ptr [bp + 8]*/
/*2dc7 rep stosb byte ptr es:[di], al*/
/*2dc9 pop di*/
/*2dca add di, 0x28*/
/*2dcd dec bx*/
/*2dce jne 0x2db8*/
/*2dd0 mov ax, 0*/
/*2dd3 out dx, ax*/
/*2dd4 inc al*/
/*2dd6 out dx, ax*/
/*2dd7 pop bp*/
/*2dd8 ret 8*/
void sub_12d9a()
{
  push(bp);
  bp = sp;
  ax = 0xa000;
  es = ax;
  di = memoryAGet16(ss, bp + 10 - 2);
  dx = 0x03ce;
  ax = memoryAGet16(ss, bp + 4 - 2);
  ah = al;
  al = 0x00;
  out16(dx, ax);
  ax = 0x0f01;
  out16(dx, ax);
  flags.direction = 0;
  bx = memoryAGet16(ss, bp + 6 - 2);
loc_12db8:
  push(di);
  cx = memoryAGet16(ss, bp + 8 - 2);
  for (; cx != 0; --cx) stosb<ES_DI>(al);
  di = pop();
  push(di);
  di += 0x2000;
  cx = memoryAGet16(ss, bp + 8 - 2);
  for (; cx != 0; --cx) stosb<ES_DI>(al);
  di = pop();
  di += 0x0028;
  bx--;
  if (bx) goto loc_12db8;
  ax = 0x0000;
  out16(dx, ax);
  al++;
  out16(dx, ax);
  bp = pop();
  return;
}

/*2ddc mov bl, byte ptr [0]*/
/*2de0 and bx, 3*/
/*2de3 shl bx, 1*/
/*2de5 mov ax, word ptr [bx + 0x1a2a]*/
/*2de9 mov word ptr [0x94e2], ax*/
/*2dec inc byte ptr [0]*/
/*2df0 mov byte ptr [0], 0xff*/
/*2df5 ret */
void sub_12ddc()
{
  bl = memoryAGet(ds, 0x94e4);
  bx &= 0x0003;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 6698);
  memoryASet16(ds, 0x94e2, ax);
  memoryASet(ds, 0x94e4, memoryAGet(ds, 0x94e4) + 1);
  memoryASet(ds, 0x9527, 0xff);
  return;
}

/*2df6 mov al, 0*/
/*2df8 mov byte ptr [0x94e5], al*/
/*2dfb mov byte ptr [0x94e6], al*/
/*2dfe mov byte ptr [0x94e7], al*/
/*2e01 ret */
void sub_12df6()
{
  al = 0x00;
  memoryASet(ds, 0x94e5, al);
  memoryASet(ds, 0x94e6, al);
  memoryASet(ds, 0x94e7, al);
  return;
}

/*2e02 push si*/
/*2e03 call 0x1b80*/
/*2e06 call 0x309d*/
/*2e09 pop si*/
/*2e0a mov ax, word ptr [0x952a]*/
/*2e0d shr ax, 1*/
/*2e0f shr ax, 1*/
/*2e11 shr ax, 1*/
/*2e13 mov bx, word ptr [0]*/
/*2e17 test bl, 1*/
/*2e1a je 0x2e23*/
/*2e1c neg ax*/
/*2e1e sub ax, 3*/
/*2e21 jmp 0x2e30*/
/*2e23 test bl, 2*/
/*2e26 je 0x2e2d*/
/*2e28 add ax, 3*/
/*2e2b jmp 0x2e30*/
/*2e2d mov ax, 0*/
/*2e30 mov word ptr [0x9522], ax*/
/*2e33 mov al, byte ptr [si + 0x16]*/
/*2e36 and ax, 0x7f*/
/*2e39 cmp al, 0x3f*/
/*2e3b jbe 0x2e48*/
/*2e3d neg al*/
/*2e3f add al, 0x7f*/
/*2e41 call 0x3084*/
/*2e44 neg ax*/
/*2e46 jmp 0x2e4b*/
/*2e48 call 0x3084*/
/*2e4b mov word ptr [0x9520], ax*/
/*2e4e mov ax, word ptr [0x951e]*/
/*2e51 add ax, word ptr [0]*/
/*2e55 add ax, word ptr [0]*/
/*2e59 je 0x2e6a*/
/*2e5b jns 0x2e63*/
/*2e5d inc ax*/
/*2e5e jns 0x2e61*/
/*2e60 inc ax*/
/*2e61 jmp 0x2e6a*/
/*2e63 dec ax*/
/*2e64 cmp ax, 0*/
/*2e67 jle 0x2e6a*/
/*2e69 dec ax*/
/*2e6a cmp ax, 0x40*/
/*2e6d jle 0x2e74*/
/*2e6f mov ax, 0x40*/
/*2e72 jmp 0x2e7c*/
/*2e74 cmp ax, 0xffc0*/
/*2e77 jge 0x2e7c*/
/*2e79 mov ax, 0xffc0*/
/*2e7c mov word ptr [0x951e], ax*/
/*2e7f sar ax, 1*/
/*2e81 sar ax, 1*/
/*2e83 add byte ptr [si + 0x16], al*/
/*2e86 mov al, byte ptr [si + 0x16]*/
/*2e89 and ax, 0x7f*/
/*2e8c mov bx, ax*/
/*2e8e mov al, byte ptr [bx + 0x1675]*/
/*2e92 cwde */
/*2e93 shl ax, 1*/
/*2e95 add ax, 0x80*/
/*2e98 mov word ptr [si + 5], ax*/
/*2e9b mov al, byte ptr [bx + 0x16f5]*/
/*2e9f cwde */
/*2ea0 shl ax, 1*/
/*2ea2 add ax, 0x80*/
/*2ea5 push bx*/
/*2ea6 cmp ax, 0*/
/*2ea9 je 0x2ebe*/
/*2eab mov bx, ax*/
/*2ead shl ax, 1*/
/*2eaf shl ax, 1*/
/*2eb1 add ax, bx*/
/*2eb3 shl ax, 1*/
/*2eb5 add ax, 5*/
/*2eb8 mov bl, 0xc*/
/*2eba div bl*/
/*2ebc mov ah, 0*/
/*2ebe pop bx*/
/*2ebf mov word ptr [si + 7], ax*/
/*2ec2 mov al, byte ptr [bx + 0x1775]*/
/*2ec6 mov byte ptr [si + 4], al*/
/*2ec9 mov bx, 0x1594*/
/*2ecc call 0x2121*/
/*2ecf mov al, byte ptr [0x94e6]*/
/*2ed2 mov byte ptr [0x94e7], al*/
/*2ed5 mov al, byte ptr [0x94e5]*/
/*2ed8 mov byte ptr [0x94e6], al*/
/*2edb mov al, byte ptr [0x1ba0]*/
/*2ede mov byte ptr [0x94e5], al*/
/*2ee1 mov ax, word ptr [0x954c]*/
/*2ee4 mov bl, byte ptr [0]*/
/*2ee8 test al, 0x40*/
/*2eea je 0x2f02*/
/*2eec cmp bl, 2*/
/*2eef jne 0x2f00*/
/*2ef1 mov byte ptr [0], 3*/
/*2ef6 mov al, 2*/
/*2ef8 call 0x3840*/
/*2efb mov byte ptr [0], 2*/
/*2f00 jmp 0x2f18*/
/*2f02 cmp bl, 1*/
/*2f05 jne 0x2f0e*/
/*2f07 mov byte ptr [0], 2*/
/*2f0c jmp 0x2f18*/
/*2f0e cmp bl, 3*/
/*2f11 jne 0x2f18*/
/*2f13 mov byte ptr [0], 0*/
/*2f18 mov ax, word ptr [0x954c]*/
/*2f1b mov bl, byte ptr [0]*/
/*2f1f test al, 0x20*/
/*2f21 je 0x2f39*/
/*2f23 cmp bl, 2*/
/*2f26 jne 0x2f37*/
/*2f28 mov byte ptr [0], 3*/
/*2f2d mov al, 2*/
/*2f2f call 0x3840*/
/*2f32 mov byte ptr [0], 2*/
/*2f37 jmp 0x2f4f*/
/*2f39 cmp bl, 1*/
/*2f3c jne 0x2f45*/
/*2f3e mov byte ptr [0], 2*/
/*2f43 jmp 0x2f4f*/
/*2f45 cmp bl, 3*/
/*2f48 jne 0x2f4f*/
/*2f4a mov byte ptr [0], 0*/
/*2f4f ret */
void sub_12e02()
{
  push(si);
  sub_11b80();
  sub_1309d();
  si = pop();
  ax = memoryAGet16(ds, 0x952a);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  bx = memoryAGet16(ds, 0x954c);
  
  if (bl & 0x01) goto loc_12e23;
  ax = -ax;
  ax -= 0x0003;
  goto loc_12e30;
loc_12e23:
  
  if (bl & 0x02) goto loc_12e2d;
  ax += 0x0003;
  goto loc_12e30;
loc_12e2d:
  ax = 0x0000;
loc_12e30:
  memoryASet16(ds, 0x9522, ax);
  al = memoryAGet(ds, si + 22);
  ax &= 0x007f;
  
  if (al <= 0x3f) goto loc_12e48;
  al = -al;
  al += 0x7f;
  sub_13084();
  ax = -ax;
  goto loc_12e4b;
loc_12e48:
  sub_13084();
loc_12e4b:
  memoryASet16(ds, 0x9520, ax);
  ax = memoryAGet16(ds, 0x951e);
  ax += memoryAGet16(ds, 0x9522);
  ax += memoryAGet16(ds, 0x9520);
  if (!ax) goto loc_12e6a;
  if ((short)ax >= 0) goto loc_12e63;
  ax++;
  if ((short)ax >= 0) goto loc_12e61;
  ax++;
loc_12e61:
  goto loc_12e6a;
loc_12e63:
  ax--;
  
  if ((short)ax <= (short)0x0000) goto loc_12e6a;
  ax--;
loc_12e6a:
  
  if ((short)ax <= (short)0x0040) goto loc_12e74;
  ax = 0x0040;
  goto loc_12e7c;
loc_12e74:
  
  if ((short)ax >= (short)0xffc0) goto loc_12e7c;
  ax = 0xffc0;
loc_12e7c:
  memoryASet16(ds, 0x951e, ax);
  ax = sar16(ax, 0x0001);
  ax = sar16(ax, 0x0001);
  memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + al);
  al = memoryAGet(ds, si + 22);
  ax &= 0x007f;
  bx = ax;
  al = memoryAGet(ds, bx + 5749);
  true ? cbw() : cwde();
  ax <<= 0x0001;
  ax += 0x0080;
  memoryASet16(ds, si + 5, ax);
  al = memoryAGet(ds, bx + 5877);
  true ? cbw() : cwde();
  ax <<= 0x0001;
  ax += 0x0080;
  push(bx);
  
  if (ax == 0x0000) goto loc_12ebe;
  bx = ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += bx;
  ax <<= 0x0001;
  ax += 0x0005;
  bl = 0x0c;
  div8(bl);
  ah = 0x00;
loc_12ebe:
  bx = pop();
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, bx + 6005);
  memoryASet(ds, si + 4, al);
  bx = 0x1594;
  sub_12121();
  al = memoryAGet(ds, 0x94e6);
  memoryASet(ds, 0x94e7, al);
  al = memoryAGet(ds, 0x94e5);
  memoryASet(ds, 0x94e6, al);
  al = memoryAGet(ds, 0x1ba0);
  memoryASet(ds, 0x94e5, al);
  ax = memoryAGet16(ds, 0x954c);
  bl = memoryAGet(ds, 0x951a);
  
  if (al & 0x40) goto loc_12f02;
  
  if (bl != 0x02) goto loc_12f00;
  memoryASet(ds, 0x951a, 0x03);
  al = 0x02;
  sub_13840();
  memoryASet(ds, 0x951c, 0x02);
loc_12f00:
  goto loc_12f18;
loc_12f02:
  
  if (bl != 0x01) goto loc_12f0e;
  memoryASet(ds, 0x951a, 0x02);
  goto loc_12f18;
loc_12f0e:
  
  if (bl != 0x03) goto loc_12f18;
  memoryASet(ds, 0x951a, 0x00);
loc_12f18:
  ax = memoryAGet16(ds, 0x954c);
  bl = memoryAGet(ds, 0x951b);
  
  if (al & 0x20) goto loc_12f39;
  
  if (bl != 0x02) goto loc_12f37;
  memoryASet(ds, 0x951b, 0x03);
  al = 0x02;
  sub_13840();
  memoryASet(ds, 0x951c, 0x02);
loc_12f37:
  goto loc_12f4f;
loc_12f39:
  
  if (bl != 0x01) goto loc_12f45;
  memoryASet(ds, 0x951b, 0x02);
  goto loc_12f4f;
loc_12f45:
  
  if (bl != 0x03) goto loc_12f4f;
  memoryASet(ds, 0x951b, 0x00);
loc_12f4f:
  return;
}

/*2f50 mov al, byte ptr [si]*/
/*2f52 test al, 0x20*/
/*2f54 jne 0x2f5e*/
/*2f56 mov ah, byte ptr [0]*/
/*2f5a mov al, 0xf8*/
/*2f5c jmp 0x2f64*/
/*2f5e mov ah, byte ptr [0]*/
/*2f62 mov al, 8*/
/*2f64 cmp ah, 3*/
/*2f67 je 0x2f6e*/
/*2f69 cmp ah, 0*/
/*2f6c jne 0x2f90*/
/*2f6e mov byte ptr [si], 0*/
/*2f71 mov si, 0x1ba1*/
/*2f74 mov al, byte ptr [si]*/
/*2f76 test al, 0x80*/
/*2f78 jne 0x2f8f*/
/*2f7a test al, 1*/
/*2f7c je 0x2f8a*/
/*2f7e mov al, byte ptr [si + 0x12]*/
/*2f81 cmp al, 0xf*/
/*2f83 jne 0x2f8a*/
/*2f85 push si*/
/*2f86 call 0x3059*/
/*2f89 pop si*/
/*2f8a add si, 0x17*/
/*2f8d jmp 0x2f74*/
/*2f8f ret */
/*2f90 add al, byte ptr [0]*/
/*2f94 and ax, 0x7f*/
/*2f97 mov bx, ax*/
/*2f99 mov al, byte ptr [bx + 0x1675]*/
/*2f9d cwde */
/*2f9e mov cx, ax*/
/*2fa0 sar cx, 1*/
/*2fa2 add ax, cx*/
/*2fa4 add ax, 0x80*/
/*2fa7 mov word ptr [si + 5], ax*/
/*2faa mov al, byte ptr [bx + 0x16f5]*/
/*2fae cwde */
/*2faf mov cx, ax*/
/*2fb1 sar cx, 1*/
/*2fb3 add ax, cx*/
/*2fb5 add ax, 0x80*/
/*2fb8 cmp ax, 0*/
/*2fbb je 0x2fd0*/
/*2fbd mov bx, ax*/
/*2fbf shl ax, 1*/
/*2fc1 shl ax, 1*/
/*2fc3 add ax, bx*/
/*2fc5 shl ax, 1*/
/*2fc7 add ax, 5*/
/*2fca mov bl, 0xc*/
/*2fcc div bl*/
/*2fce mov ah, 0*/
/*2fd0 mov bl, byte ptr [0x1ba0]*/
/*2fd4 and bx, 0x7f*/
/*2fd7 mov word ptr [si + 7], ax*/
/*2fda mov al, byte ptr [bx + 0x1892]*/
/*2fde mov byte ptr [si + 4], al*/
/*2fe1 mov bx, 0x1811*/
/*2fe4 call 0x2121*/
/*2fe7 ret */
void sub_12f50()
{
  al = memoryAGet(ds, si);
  
  if (!(al & 0x20)) goto loc_12f5e;
  ah = memoryAGet(ds, 0x951a);
  al = 0xf8;
  goto loc_12f64;
loc_12f5e:
  ah = memoryAGet(ds, 0x951b);
  al = 0x08;
loc_12f64:
  
  if (ah == 0x03) goto loc_12f6e;
  
  if (ah != 0x00) goto loc_12f90;
loc_12f6e:
  memoryASet(ds, si, 0x00);
  si = 0x1ba1;
loc_12f74:
  al = memoryAGet(ds, si);
  
  if (!(al & 0x80)) goto loc_12f8f;
  
  if (al & 0x01) goto loc_12f8a;
  al = memoryAGet(ds, si + 18);
  
  if (al != 0x0f) goto loc_12f8a;
  push(si);
  sub_13059();
  si = pop();
loc_12f8a:
  si += 0x0017;
  goto loc_12f74;
loc_12f8f:
  return;
loc_12f90:
  al += memoryAGet(ds, 0x94e7);
  ax &= 0x007f;
  bx = ax;
  al = memoryAGet(ds, bx + 5749);
  true ? cbw() : cwde();
  cx = ax;
  cx = sar16(cx, 0x0001);
  ax += cx;
  ax += 0x0080;
  memoryASet16(ds, si + 5, ax);
  al = memoryAGet(ds, bx + 5877);
  true ? cbw() : cwde();
  cx = ax;
  cx = sar16(cx, 0x0001);
  ax += cx;
  ax += 0x0080;
  
  if (ax == 0x0000) goto loc_12fd0;
  bx = ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += bx;
  ax <<= 0x0001;
  ax += 0x0005;
  bl = 0x0c;
  div8(bl);
  ah = 0x00;
loc_12fd0:
  bl = memoryAGet(ds, 0x1ba0);
  bx &= 0x007f;
  memoryASet16(ds, si + 7, ax);
  al = memoryAGet(ds, bx + 6290);
  memoryASet(ds, si + 4, al);
  bx = 0x1811;
  sub_12121();
  return;
}

/*2fe8 mov bx, word ptr [0]*/
/*2fec shr bx, 1*/
/*2fee shr bx, 1*/
/*2ff0 shr bx, 1*/
/*2ff2 and bx, 0x1f*/
/*2ff5 mov al, byte ptr [bx + 0x1a0a]*/
/*2ff9 mov byte ptr [0x9549], al*/
/*2ffc mov al, byte ptr [bx + 0x19ea]*/
/*3000 mov byte ptr [si + 4], al*/
/*3003 mov bx, 0x1929*/
/*3006 call 0x2121*/
/*3009 ret */
void sub_12fe8()
{
  bx = memoryAGet16(ds, 0x9525);
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx &= 0x001f;
  al = memoryAGet(ds, bx + 6666);
  memoryASet(ds, 0x9549, al);
  al = memoryAGet(ds, bx + 6634);
  memoryASet(ds, si + 4, al);
  bx = 0x1929;
  sub_12121();
  return;
}

/*300a mov ax, word ptr [0x9547]*/
/*300d sub ax, word ptr [si + 0x13]*/
/*3010 shr ax, 1*/
/*3012 shr ax, 1*/
/*3014 shr ax, 1*/
/*3016 cmp ax, 0x2d*/
/*3019 jbe 0x301f*/
/*301b mov byte ptr [si], 0*/
/*301e ret */
/*301f push ax*/
/*3020 call 0x3130*/
/*3023 pop ax*/
/*3024 shr ax, 1*/
/*3026 mov byte ptr [si + 4], al*/
/*3029 mov bx, ax*/
/*302b mov al, byte ptr [bx + 0x1a9a]*/
/*302f mov byte ptr [si + 2], al*/
/*3032 mov bx, 0x1ac9*/
/*3035 call 0x2121*/
/*3038 mov al, byte ptr [si + 2]*/
/*303b cmp al, 2*/
/*303d je 0x3040*/
/*303f ret */
/*3040 mov bl, byte ptr [0x1b8e]*/
/*3044 mov bh, 0*/
/*3046 mov al, byte ptr [bx + 0x17f5]*/
/*304a cmp al, byte ptr [si + 1]*/
/*304d je 0x3050*/
/*304f ret */
/*3050 mov al, 9*/
/*3052 call 0x3840*/
/*3055 call 0x3059*/
/*3058 ret */
void sub_1300a()
{
  ax = memoryAGet16(ds, 0x9547);
  ax -= memoryAGet16(ds, si + 19);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  
  if (ax <= 0x002d) goto loc_1301f;
  memoryASet(ds, si, 0x00);
  return;
loc_1301f:
  push(ax);
  sub_13130();
  ax = pop();
  ax >>= 0x0001;
  memoryASet(ds, si + 4, al);
  bx = ax;
  al = memoryAGet(ds, bx + 6810);
  memoryASet(ds, si + 2, al);
  bx = 0x1ac9;
  sub_12121();
  al = memoryAGet(ds, si + 2);
  
  if (al == 0x02) goto loc_13040;
  return;
loc_13040:
  bl = memoryAGet(ds, 0x1b8e);
  bh = 0x00;
  al = memoryAGet(ds, bx + 6133);
  
  if (al == memoryAGet(ds, si + 1)) goto loc_13050;
  return;
loc_13050:
  al = 0x09;
  sub_13840();
  sub_13059();
  return;
}

/*3059 mov byte ptr [si], 0*/
/*305c mov al, byte ptr [0x951d]*/
/*305f cmp al, 0x40*/
/*3061 jne 0x306a*/
/*3063 add word ptr [0], 6*/
/*3068 jmp 0x3083*/
/*306a cmp al, 0x80*/
/*306c jne 0x3075*/
/*306e add word ptr [0], 4*/
/*3073 jmp 0x3083*/
/*3075 cmp al, 0xc0*/
/*3077 jne 0x3080*/
/*3079 add word ptr [0], 8*/
/*307e jmp 0x3083*/
/*3080 call 0x268a*/
/*3083 ret */
void sub_13059()
{
  memoryASet(ds, si, 0x00);
  al = memoryAGet(ds, 0x951d);
  
  if (al != 0x40) goto loc_1306a;
  memoryASet16(ds, 0x9540, memoryAGet16(ds, 0x9540) + 0x0006);
  goto loc_13083;
loc_1306a:
  
  if (al != 0x80) goto loc_13075;
  memoryASet16(ds, 0x953c, memoryAGet16(ds, 0x953c) + 0x0004);
  goto loc_13083;
loc_13075:
  
  if (al != 0xc0) goto loc_13080;
  memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) + 0x0008);
  goto loc_13083;
loc_13080:
  sub_1268a();
loc_13083:
  return;
}

/*268a mov ax, 2*/
/*268d push ax*/
/*268e mov ax, 5*/
/*2691 push ax*/
/*2692 mov ax, 0*/
/*2695 push ax*/
/*2696 mov ax, 0*/
/*2699 push ax*/
/*269a call 0x269e*/
/*269d ret */
void sub_1268a()
{
  ax = 0x0002;
  push(ax);
  ax = 0x0005;
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_1269e();
  return;
}

/*3084 sub al, 5*/
/*3086 jns 0x308d*/
/*3088 mov ax, 0*/
/*308b jmp 0x309c*/
/*308d cmp al, 0x38*/
/*308f jbe 0x3093*/
/*3091 mov al, 0x38*/
/*3093 shr al, 1*/
/*3095 mov ah, 0*/
/*3097 neg ax*/
/*3099 sub ax, 3*/
/*309c ret */
void sub_13084()
{
  al -= 0x05;
  if ((char)al >= 0) goto loc_1308d;
  ax = 0x0000;
  goto loc_1309c;
loc_1308d:
  
  if (al <= 0x38) goto loc_13093;
  al = 0x38;
loc_13093:
  al >>= 0x01;
  ah = 0x00;
  ax = -ax;
  ax -= 0x0003;
loc_1309c:
  return;
}

/*309d mov bx, word ptr [0]*/
/*30a1 add bx, 7*/
/*30a4 shr bx, 1*/
/*30a6 shr bx, 1*/
/*30a8 shr bx, 1*/
/*30aa add bx, 2*/
/*30ad add word ptr [0], bx*/
/*30b1 mov ax, word ptr [0x950f]*/
/*30b4 add ax, bx*/
/*30b6 cmp ax, 0x2e8*/
/*30b9 jbe 0x30c4*/
/*30bb mov ax, 0*/
/*30be mov word ptr [0], 0xffff*/
/*30c4 mov word ptr [0x950f], ax*/
/*30c7 mov ax, word ptr [0x9547]*/
/*30ca sub ax, 0x380*/
/*30cd jns 0x3124*/
/*30cf neg ax*/
/*30d1 cmp ax, 0x100*/
/*30d4 jae 0x30ed*/
/*30d6 mov word ptr [0x9525], ax*/
/*30d9 mov al, byte ptr [0x9524]*/
/*30dc cmp al, 0*/
/*30de jne 0x30eb*/
/*30e0 mov si, 0x1912*/
/*30e3 call 0xb58*/
/*30e6 mov byte ptr [0], 1*/
/*30eb jmp 0x3122*/
/*30ed mov ax, word ptr [0x9547]*/
/*30f0 shr ax, 1*/
/*30f2 shr ax, 1*/
/*30f4 shr ax, 1*/
/*30f6 shr ax, 1*/
/*30f8 shr ax, 1*/
/*30fa shr ax, 1*/
/*30fc cmp al, byte ptr [0]*/
/*3100 je 0x3122*/
/*3102 mov byte ptr [0x9527], al*/
/*3105 mov bl, al*/
/*3107 mov bh, 0*/
/*3109 add bx, word ptr [0]*/
/*310d mov al, byte ptr [bx]*/
/*310f cmp al, 0*/
/*3111 je 0x3122*/
/*3113 mov si, 0x1ab2*/
/*3116 mov byte ptr [si + 1], al*/
/*3119 mov ax, word ptr [0x9547]*/
/*311c mov word ptr [si + 0x13], ax*/
/*311f call 0xb58*/
/*3122 jmp 0x312f*/
/*3124 mov byte ptr [0], 0*/
/*3129 mov ax, word ptr [0x950c]*/
/*312c mov word ptr [0x9528], ax*/
/*312f ret */
void sub_1309d()
{
  bx = memoryAGet16(ds, 0x952a);
  bx += 0x0007;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx >>= 0x0001;
  bx += 0x0002;
  memoryASet16(ds, 0x9547, memoryAGet16(ds, 0x9547) + bx);
  ax = memoryAGet16(ds, 0x950f);
  ax += bx;
  
  if (ax <= 0x02e8) goto loc_130c4;
  ax = 0x0000;
  memoryASet16(ds, 0x953c, 0xffff);
loc_130c4:
  memoryASet16(ds, 0x950f, ax);
  ax = memoryAGet16(ds, 0x9547);
  ax -= 0x0380;
  if ((short)ax >= 0) goto loc_13124;
  ax = -ax;
  
  if (ax >= 0x0100) goto loc_130ed;
  memoryASet16(ds, 0x9525, ax);
  al = memoryAGet(ds, 0x9524);
  
  if (al != 0x00) goto loc_130eb;
  si = 0x1912;
  sub_10b58();
  memoryASet(ds, 0x9524, 0x01);
loc_130eb:
  goto loc_13122;
loc_130ed:
  ax = memoryAGet16(ds, 0x9547);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  
  if (al == memoryAGet(ds, 0x9527)) goto loc_13122;
  memoryASet(ds, 0x9527, al);
  bl = al;
  bh = 0x00;
  bx += memoryAGet16(ds, 0x94e2);
  al = memoryAGet(ds, bx);
  
  if (al == 0x00) goto loc_13122;
  si = 0x1ab2;
  memoryASet(ds, si + 1, al);
  ax = memoryAGet16(ds, 0x9547);
  memoryASet16(ds, si + 19, ax);
  sub_10b58();
loc_13122:
  goto loc_1312f;
loc_13124:
  memoryASet(ds, 0x94ff, 0x00);
  ax = memoryAGet16(ds, 0x950c);
  memoryASet16(ds, 0x9528, ax);
loc_1312f:
  return;
}

/*3130 mov bl, al*/
/*3132 mov bh, 0*/
/*3134 mov cl, byte ptr [bx + 0x1a6a]*/
/*3138 mov ch, 0*/
/*313a mov al, byte ptr [si + 1]*/
/*313d cmp al, 1*/
/*313f je 0x315e*/
/*3141 cmp al, 2*/
/*3143 je 0x3167*/
/*3145 cmp al, 3*/
/*3147 je 0x3170*/
/*3149 cmp al, 4*/
/*314b je 0x3178*/
/*314d cmp al, 5*/
/*314f je 0x3181*/
/*3151 cmp al, 6*/
/*3153 je 0x3188*/
/*3155 cmp al, 7*/
/*3157 je 0x3191*/
/*3159 cmp al, 8*/
/*315b je 0x319b*/
/*315d ret */
/*315e neg cx*/
/*3160 add cx, 0x6a*/
/*3163 mov word ptr [si + 7], cx*/
/*3166 ret */
/*3167 push cx*/
/*3168 call 0x315e*/
/*316b pop cx*/
/*316c call 0x3170*/
/*316f ret */
/*3170 add cx, 0x80*/
/*3174 mov word ptr [si + 5], cx*/
/*3177 ret */
/*3178 push cx*/
/*3179 call 0x3170*/
/*317c pop cx*/
/*317d call 0x3181*/
/*3180 ret */
/*3181 add cx, 0x6a*/
/*3184 mov word ptr [si + 7], cx*/
/*3187 ret */
/*3188 push cx*/
/*3189 call 0x3181*/
/*318c pop cx*/
/*318d call 0x3191*/
/*3190 ret */
/*3191 neg cx*/
/*3193 add cx, 0x80*/
/*3197 mov word ptr [si + 5], cx*/
/*319a ret */
/*319b push cx*/
/*319c call 0x3191*/
/*319f pop cx*/
/*31a0 call 0x315e*/
/*31a3 ret */
void sub_13130()
{
  bl = al;
  bh = 0x00;
  cl = memoryAGet(ds, bx + 6762);
  ch = 0x00;
  al = memoryAGet(ds, si + 1);
  
  if (al == 0x01) goto loc_1315e;
  
  if (al == 0x02) goto loc_13167;
  
  if (al == 0x03) goto loc_13170;
  
  if (al == 0x04) goto loc_13178;
  
  if (al == 0x05) goto loc_13181;
  
  if (al == 0x06) goto loc_13188;
  
  if (al == 0x07) goto loc_13191;
  
  if (al == 0x08) goto loc_1319b;
  return;
loc_1315e:
  cx = -cx;
  cx += 0x006a;
  memoryASet16(ds, si + 7, cx);
  return;
loc_13167:
  push(cx);
  sub_1315e();
  cx = pop();
  sub_13170();
  return;
loc_13170:
  cx += 0x0080;
  memoryASet16(ds, si + 5, cx);
  return;
loc_13178:
  push(cx);
  sub_13170();
  cx = pop();
  sub_13181();
  return;
loc_13181:
  cx += 0x006a;
  memoryASet16(ds, si + 7, cx);
  return;
loc_13188:
  push(cx);
  sub_13181();
  cx = pop();
  sub_13191();
  return;
loc_13191:
  cx = -cx;
  cx += 0x0080;
  memoryASet16(ds, si + 5, cx);
  return;
loc_1319b:
  push(cx);
  sub_13191();
  cx = pop();
  sub_1315e();
  return;
}

/*315e neg cx*/
/*3160 add cx, 0x6a*/
/*3163 mov word ptr [si + 7], cx*/
/*3166 ret */
void sub_1315e()
{
  cx = -cx;
  cx += 0x006a;
  memoryASet16(ds, si + 7, cx);
  return;
}

/*3170 add cx, 0x80*/
/*3174 mov word ptr [si + 5], cx*/
/*3177 ret */
void sub_13170()
{
  cx += 0x0080;
  memoryASet16(ds, si + 5, cx);
  return;
}

/*3181 add cx, 0x6a*/
/*3184 mov word ptr [si + 7], cx*/
/*3187 ret */
void sub_13181()
{
  cx += 0x006a;
  memoryASet16(ds, si + 7, cx);
  return;
}

/*3191 neg cx*/
/*3193 add cx, 0x80*/
/*3197 mov word ptr [si + 5], cx*/
/*319a ret */
void sub_13191()
{
  cx = -cx;
  cx += 0x0080;
  memoryASet16(ds, si + 5, cx);
  return;
}

/*31a4 mov ax, word ptr [0x94f8]*/
/*31a7 mov es, ax*/
/*31a9 mov di, 0x144*/
/*31ac mov bx, word ptr [0]*/
/*31b0 mov si, 0x340*/
/*31b3 call 0x31e7*/
/*31b6 not ax*/
/*31b8 and ax, 0xf*/
/*31bb mov ah, al*/
/*31bd mov al, 1*/
/*31bf mov dx, 0x3ce*/
/*31c2 out dx, ax*/
/*31c3 call 0x3209*/
/*31c6 mov ah, al*/
/*31c8 mov al, 0*/
/*31ca out dx, ax*/
/*31cb push ds*/
/*31cc mov ds, bx*/
/*31ce cld */
/*31cf mov cx, 0xa0*/
/*31d2 push cx*/
/*31d3 mov cx, 0x20*/
/*31d6 rep movsb byte ptr es:[di], byte ptr [si]*/
/*31d8 add di, 8*/
/*31db pop cx*/
/*31dc loop 0x31d2*/
/*31de pop ds*/
/*31df mov ax, 0*/
/*31e2 out dx, ax*/
/*31e3 inc al*/
/*31e5 out dx, ax*/
/*31e6 ret */
void sub_131a4()
{
  ax = memoryAGet16(ds, 0x94f8);
  es = ax;
  di = 0x0144;
  bx = memoryAGet16(ds, 0x94f4);
  si = 0x0340;
  sub_131e7();
  ax = ~ax;
  ax &= 0x000f;
  ah = al;
  al = 0x01;
  dx = 0x03ce;
  out16(dx, ax);
  sub_13209();
  ah = al;
  al = 0x00;
  out16(dx, ax);
  push(ds);
  ds = bx;
  flags.direction = 0;
  cx = 0x00a0;
loc_131d2:
  push(cx);
  cx = 0x0020;
  for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
  di += 0x0008;
  cx = pop();
  if (--cx) goto loc_131d2;
  ds = pop();
  ax = 0x0000;
  out16(dx, ax);
  al++;
  out16(dx, ax);
  return;
}

/*31e7 mov al, byte ptr [0x951d]*/
/*31ea cmp al, 0x40*/
/*31ec jne 0x31f3*/
/*31ee mov ax, 2*/
/*31f1 jmp 0x3208*/
/*31f3 cmp al, 0x80*/
/*31f5 jne 0x31fc*/
/*31f7 mov ax, 4*/
/*31fa jmp 0x3208*/
/*31fc cmp al, 0xc0*/
/*31fe jne 0x3205*/
/*3200 mov ax, 1*/
/*3203 jmp 0x3208*/
/*3205 mov ax, 3*/
/*3208 ret */
void sub_131e7()
{
  al = memoryAGet(ds, 0x951d);
  
  if (al != 0x40) goto loc_131f3;
  ax = 0x0002;
  goto loc_13208;
loc_131f3:
  
  if (al != 0x80) goto loc_131fc;
  ax = 0x0004;
  goto loc_13208;
loc_131fc:
  
  if (al != 0xc0) goto loc_13205;
  ax = 0x0001;
  goto loc_13208;
loc_13205:
  ax = 0x0003;
loc_13208:
  return;
}

/*3209 mov al, byte ptr [0x951c]*/
/*320c cmp al, 0*/
/*320e jne 0x3215*/
/*3210 mov ax, 0*/
/*3213 jmp 0x322b*/
/*3215 cmp al, 1*/
/*3217 jne 0x3223*/
/*3219 mov ax, 7*/
/*321c mov byte ptr [0], 0*/
/*3221 jmp 0x322b*/
/*3223 mov ax, 0xf*/
/*3226 mov byte ptr [0], 1*/
/*322b ret */
void sub_13209()
{
  al = memoryAGet(ds, 0x951c);
  
  if (al != 0x00) goto loc_13215;
  ax = 0x0000;
  goto loc_1322b;
loc_13215:
  
  if (al != 0x01) goto loc_13223;
  ax = 0x0007;
  memoryASet(ds, 0x951c, 0x00);
  goto loc_1322b;
loc_13223:
  ax = 0x000f;
  memoryASet(ds, 0x951c, 0x01);
loc_1322b:
  return;
}

/*32fe mov dx, 0x3ce*/
/*3301 mov ax, 0x105*/
/*3304 out dx, ax*/
/*3305 mov ax, word ptr [0x94f8]*/
/*3308 mov es, ax*/
/*330a mov di, 0x144*/
/*330d mov ax, word ptr [0x9528]*/
/*3310 shl ax, 1*/
/*3312 shl ax, 1*/
/*3314 shl ax, 1*/
/*3316 shl ax, 1*/
/*3318 shl ax, 1*/
/*331a mov si, ax*/
/*331c push ds*/
/*331d mov ax, 0xa800*/
/*3320 mov ds, ax*/
/*3322 cld */
/*3323 mov cx, 0xa0*/
/*3326 push cx*/
/*3327 mov cx, 0x20*/
/*332a rep movsb byte ptr es:[di], byte ptr [si]*/
/*332c and si, 0x7fff*/
/*3330 add di, 8*/
/*3333 pop cx*/
/*3334 loop 0x3326*/
/*3336 pop ds*/
/*3337 mov ax, 5*/
/*333a out dx, ax*/
/*333b ret */
void sub_132fe()
{
  dx = 0x03ce;
  ax = 0x0105;
  out16(dx, ax);
  ax = memoryAGet16(ds, 0x94f8);
  es = ax;
  di = 0x0144;
  ax = memoryAGet16(ds, 0x9528);
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  si = ax;
  push(ds);
  ax = 0xa800;
  ds = ax;
  flags.direction = 0;
  cx = 0x00a0;
loc_13326:
  push(cx);
  cx = 0x0020;
  for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
  si &= 0x7fff;
  di += 0x0008;
  cx = pop();
  if (--cx) goto loc_13326;
  ds = pop();
  ax = 0x0005;
  out16(dx, ax);
  return;
}

/*333c mov ax, 0xd*/
/*333f int 0x10*/
/*3341 mov ax, 0xa000*/
/*3344 mov word ptr [0x94fa], ax*/
/*3347 add ax, 0x200*/
/*334a mov word ptr [0x94f8], ax*/
/*334d mov ax, 0*/
/*3350 call 0x33b3*/
/*3353 mov ax, word ptr [0x94f8]*/
/*3356 mov bx, word ptr [0]*/
/*335a mov word ptr [0], bx*/
/*335e mov word ptr [0x94fa], ax*/
/*3361 call 0x33d7*/
/*3364 mov bx, word ptr [0]*/
/*3368 shl bx, 1*/
/*336a shl bx, 1*/
/*336c shl bx, 1*/
/*336e shl bx, 1*/
/*3370 cli */
/*3371 mov dx, 0x3d4*/
/*3374 mov ah, bh*/
/*3376 mov al, 0xc*/
/*3378 out dx, ax*/
/*3379 mov ah, bl*/
/*337b inc al*/
/*337d out dx, ax*/
/*337e sti */
/*337f call 0x33d7*/
/*3382 ret */
void sub_1333c()
{
  ax = 0x000d;
  interrupt(0x10);
  ax = 0xa000;
  memoryASet16(ds, 0x94fa, ax);
  ax += 0x0200;
  memoryASet16(ds, 0x94f8, ax);
  ax = 0x0000;
  sub_133b3();
  ax = memoryAGet16(ds, 0x94f8);
  bx = memoryAGet16(ds, 0x94fa);
  memoryASet16(ds, 0x94f8, bx);
  memoryASet16(ds, 0x94fa, ax);
  sub_133d7();
  bx = memoryAGet16(ds, 0x94fa);
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  flags.interrupts = 0;
  dx = 0x03d4;
  ah = bh;
  al = 0x0c;
  out16(dx, ax);
  ah = bl;
  al++;
  out16(dx, ax);
  flags.interrupts = 1;
  sub_133d7();
  return;
}

/*3383 mov ax, word ptr [0x94f8]*/
/*3386 mov bx, word ptr [0]*/
/*338a mov word ptr [0], bx*/
/*338e mov word ptr [0x94fa], ax*/
/*3391 mov bx, word ptr [0]*/
/*3395 shl bx, 1*/
/*3397 shl bx, 1*/
/*3399 shl bx, 1*/
/*339b shl bx, 1*/
/*339d cli */
/*339e mov dx, 0x3d4*/
/*33a1 mov ah, bh*/
/*33a3 mov al, 0xc*/
/*33a5 out dx, ax*/
/*33a6 sti */
/*33a7 mov dx, 0x3da*/
/*33aa in al, dx*/
/*33ab and al, 8*/
/*33ad jne 0x33aa*/
/*33af call 0x33d7*/
/*33b2 ret */
void sub_13383()
{
  ax = memoryAGet16(ds, 0x94f8);
  bx = memoryAGet16(ds, 0x94fa);
  memoryASet16(ds, 0x94f8, bx);
  memoryASet16(ds, 0x94fa, ax);
  bx = memoryAGet16(ds, 0x94fa);
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  bx <<= 0x0001;
  flags.interrupts = 0;
  dx = 0x03d4;
  ah = bh;
  al = 0x0c;
  out16(dx, ax);
  flags.interrupts = 1;
  dx = 0x03da;
loc_133aa:
  al = in8(dx);
  al &= 0x08;
  if (al) goto loc_133aa;
  sub_133d7();
  return;
}

/*33b3 push ax*/
/*33b4 mov ax, word ptr [0x94f8]*/
/*33b7 mov es, ax*/
/*33b9 mov di, 0*/
/*33bc mov dx, 0x3ce*/
/*33bf pop ax*/
/*33c0 mov ah, al*/
/*33c2 mov al, 0*/
/*33c4 out dx, ax*/
/*33c5 mov ax, 0xf01*/
/*33c8 out dx, ax*/
/*33c9 cld */
/*33ca mov cx, 0xfa0*/
/*33cd rep stosw word ptr es:[di], ax*/
/*33cf mov ax, 0*/
/*33d2 out dx, ax*/
/*33d3 inc al*/
/*33d5 out dx, ax*/
/*33d6 ret */
void sub_133b3()
{
  push(ax);
  ax = memoryAGet16(ds, 0x94f8);
  es = ax;
  di = 0x0000;
  dx = 0x03ce;
  ax = pop();
  ah = al;
  al = 0x00;
  out16(dx, ax);
  ax = 0x0f01;
  out16(dx, ax);
  flags.direction = 0;
  cx = 0x0fa0;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  ax = 0x0000;
  out16(dx, ax);
  al++;
  out16(dx, ax);
  return;
}

/*33d7 mov dx, 0x3da*/
/*33da in al, dx*/
/*33db and al, 8*/
/*33dd je 0x33da*/
/*33df in al, dx*/
/*33e0 and al, 8*/
/*33e2 jne 0x33df*/
/*33e4 ret */
void sub_133d7()
{
  dx = 0x03da;
loc_133da:
  al = in8(dx);
  al &= 0x08;
  if (!al) goto loc_133da;
loc_133df:
  al = in8(dx);
  al &= 0x08;
  if (al) goto loc_133df;
  return;
}

/*3423 mov ax, 0*/
/*3426 call 0x33b3*/
/*3429 call 0x3439*/
/*342c call 0x3383*/
/*342f mov ax, 0*/
/*3432 call 0x33b3*/
/*3435 call 0x3439*/
/*3438 ret */
void sub_13423()
{
  ax = 0x0000;
  sub_133b3();
  sub_13439();
  sub_13383();
  ax = 0x0000;
  sub_133b3();
  sub_13439();
  return;
}

/*3439 mov ax, word ptr [0x94f8]*/
/*343c mov es, ax*/
/*343e mov di, 0x11c*/
/*3441 mov ax, 0xffff*/
/*3444 mov cx, 0x10*/
/*3447 rep stosw word ptr es:[di], ax*/
/*3449 mov di, 0x1a44*/
/*344c mov cx, 0x10*/
/*344f rep stosw word ptr es:[di], ax*/
/*3451 mov di, 0x11b*/
/*3454 mov al, 1*/
/*3456 mov cx, 0xa2*/
/*3459 mov byte ptr es:[di], al*/
/*345c add di, 0x28*/
/*345f loop 0x3459*/
/*3461 mov di, 0x13c*/
/*3464 mov al, 0x80*/
/*3466 mov cx, 0xa2*/
/*3469 mov byte ptr es:[di], al*/
/*346c add di, 0x28*/
/*346f loop 0x3469*/
/*3471 ret */
void sub_13439()
{
  ax = memoryAGet16(ds, 0x94f8);
  es = ax;
  di = 0x011c;
  ax = 0xffff;
  cx = 0x0010;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  di = 0x1a44;
  cx = 0x0010;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  di = 0x011b;
  al = 0x01;
  cx = 0x00a2;
loc_13459:
  memoryASet(es, di, al);
  di += 0x0028;
  if (--cx) goto loc_13459;
  di = 0x013c;
  al = 0x80;
  cx = 0x00a2;
loc_13469:
  memoryASet(es, di, al);
  di += 0x0028;
  if (--cx) goto loc_13469;
  return;
}

/*3472 mov si, 0*/
/*3475 mov bx, word ptr [0]*/
/*3479 call 0x33e5*/
/*347c call 0x3383*/
/*347f mov si, 0*/
/*3482 mov bx, word ptr [0]*/
/*3486 call 0x33e5*/
/*3489 mov ax, word ptr [0x94f8]*/
/*348c push ax*/
/*348d mov ax, 0xa000*/
/*3490 add ax, 0x400*/
/*3493 push ax*/
/*3494 call 0x3291*/
/*3497 ret */
void sub_13472()
{
  si = 0x0000;
  bx = memoryAGet16(ds, 0x94f2);
  sub_133e5();
  sub_13383();
  si = 0x0000;
  bx = memoryAGet16(ds, 0x94f2);
  sub_133e5();
  ax = memoryAGet16(ds, 0x94f8);
  push(ax);
  ax = 0xa000;
  ax += 0x0400;
  push(ax);
  sub_13291();
  return;
}

/*3291 push bp*/
/*3292 mov bp, sp*/
/*3294 mov ax, word ptr [bp + 4]*/
/*3297 mov es, ax*/
/*3299 mov di, 0x144*/
/*329c mov bx, word ptr [bp + 6]*/
/*329f mov si, 0x144*/
/*32a2 mov dx, 0x3ce*/
/*32a5 mov ax, 0x105*/
/*32a8 out dx, ax*/
/*32a9 push ds*/
/*32aa mov ds, bx*/
/*32ac cld */
/*32ad mov cx, 0xa0*/
/*32b0 push cx*/
/*32b1 mov cx, 0x20*/
/*32b4 rep movsb byte ptr es:[di], byte ptr [si]*/
/*32b6 add si, 8*/
/*32b9 add di, 8*/
/*32bc pop cx*/
/*32bd loop 0x32b0*/
/*32bf pop ds*/
/*32c0 mov ax, 5*/
/*32c3 out dx, ax*/
/*32c4 pop bp*/
/*32c5 ret 4*/
void sub_13291()
{
  push(bp);
  bp = sp;
  ax = memoryAGet16(ss, bp + 4 - 2);
  es = ax;
  di = 0x0144;
  bx = memoryAGet16(ss, bp + 6 - 2);
  si = 0x0144;
  dx = 0x03ce;
  ax = 0x0105;
  out16(dx, ax);
  push(ds);
  ds = bx;
  flags.direction = 0;
  cx = 0x00a0;
loc_132b0:
  push(cx);
  cx = 0x0020;
  for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
  si += 0x0008;
  di += 0x0008;
  cx = pop();
  if (--cx) goto loc_132b0;
  ds = pop();
  ax = 0x0005;
  out16(dx, ax);
  bp = pop();
  return;
}

/*33e5 mov ax, word ptr [0x94f8]*/
/*33e8 mov es, ax*/
/*33ea mov di, 0*/
/*33ed mov dx, 0x3ce*/
/*33f0 mov ax, 0x805*/
/*33f3 out dx, ax*/
/*33f4 mov ax, 7*/
/*33f7 out dx, ax*/
/*33f8 mov dl, 0xc4*/
/*33fa mov ax, 0x802*/
/*33fd push ds*/
/*33fe mov ds, bx*/
/*3400 out dx, ax*/
/*3401 push ax*/
/*3402 push di*/
/*3403 mov cx, 0x1f40*/
/*3406 lodsb al, byte ptr [si]*/
/*3407 and byte ptr es:[di], al*/
/*340a inc di*/
/*340b loop 0x3406*/
/*340d pop di*/
/*340e pop ax*/
/*340f shr ah, 1*/
/*3411 jne 0x3400*/
/*3413 pop ds*/
/*3414 mov ax, 0xf02*/
/*3417 out dx, ax*/
/*3418 mov dl, 0xce*/
/*341a mov ax, 5*/
/*341d out dx, ax*/
/*341e mov ax, 0xf07*/
/*3421 out dx, ax*/
/*3422 ret */
void sub_133e5()
{
  ax = memoryAGet16(ds, 0x94f8);
  es = ax;
  di = 0x0000;
  dx = 0x03ce;
  ax = 0x0805;
  out16(dx, ax);
  ax = 0x0007;
  out16(dx, ax);
  dl = 0xc4;
  ax = 0x0802;
  push(ds);
  ds = bx;
loc_13400:
  out16(dx, ax);
  push(ax);
  push(di);
  cx = 0x1f40;
loc_13406:
  al = lodsb<DS_SI>();
  memoryASet(es, di, memoryAGet(es, di) & al);
  di++;
  if (--cx) goto loc_13406;
  di = pop();
  ax = pop();
  ah >>= 0x01;
  if (ah) goto loc_13400;
  ds = pop();
  ax = 0x0f02;
  out16(dx, ax);
  dl = 0xce;
  ax = 0x0005;
  out16(dx, ax);
  ax = 0x0f07;
  out16(dx, ax);
  return;
}

/*3498 mov ax, 0xa000*/
/*349b add ax, 0x400*/
/*349e push ax*/
/*349f mov ax, word ptr [0x94f8]*/
/*34a2 push ax*/
/*34a3 call 0x3291*/
/*34a6 ret */
void sub_13498()
{
  ax = 0xa000;
  ax += 0x0400;
  push(ax);
  ax = memoryAGet16(ds, 0x94f8);
  push(ax);
  sub_13291();
  return;
}

/*34a8 mov di, 0*/
/*34ab mov ax, word ptr [0x94f4]*/
/*34ae mov es, ax*/
/*34b0 mov ax, 0*/
/*34b3 mov cx, 0x1000*/
/*34b6 cld */
/*34b7 rep stosw word ptr es:[di], ax*/
/*34b9 mov ax, 0x4f*/
/*34bc push ax*/
/*34bd mov ax, 0xff*/
/*34c0 push ax*/
/*34c1 mov ax, 0xb0*/
/*34c4 push ax*/
/*34c5 mov ax, 0*/
/*34c8 push ax*/
/*34c9 call 0x36d4*/
/*34cc mov ax, 0x4f*/
/*34cf push ax*/
/*34d0 mov ax, 0*/
/*34d3 push ax*/
/*34d4 mov ax, 0xb0*/
/*34d7 push ax*/
/*34d8 mov ax, 0xff*/
/*34db push ax*/
/*34dc call 0x36d4*/
/*34df mov ax, 0*/
/*34e2 push ax*/
/*34e3 mov ax, 0x4f*/
/*34e6 push ax*/
/*34e7 mov ax, 0xff*/
/*34ea push ax*/
/*34eb mov ax, 0xb0*/
/*34ee push ax*/
/*34ef call 0x36d4*/
/*34f2 mov ax, 0*/
/*34f5 push ax*/
/*34f6 mov ax, 0xb0*/
/*34f9 push ax*/
/*34fa mov ax, 0xff*/
/*34fd push ax*/
/*34fe mov ax, 0x4f*/
/*3501 push ax*/
/*3502 call 0x36d4*/
/*3505 mov ax, word ptr [0x9547]*/
/*3508 and ax, 0x3f*/
/*350b mov word ptr [0x954e], ax*/
/*350e mov bx, ax*/
/*3510 add ax, 0x40*/
/*3513 push ax*/
/*3514 mov al, byte ptr [bx + 0x1fdc]*/
/*3518 mov ah, 0*/
/*351a push ax*/
/*351b call 0x35bc*/
/*351e mov ax, word ptr [0x954e]*/
/*3521 cmp ax, 0xc*/
/*3524 jbe 0x3527*/
/*3526 ret */
/*3527 mov bx, word ptr [0]*/
/*352b mov al, byte ptr [bx + 0x201c]*/
/*352f mov ah, 0*/
/*3531 add ax, 0x80*/
/*3534 push ax*/
/*3535 mov ax, 0*/
/*3538 push ax*/
/*3539 mov ax, 0xff*/
/*353c push ax*/
/*353d mov al, byte ptr [bx + 0x2029]*/
/*3541 mov ah, 0*/
/*3543 neg ax*/
/*3545 add ax, 0x7f*/
/*3548 push ax*/
/*3549 call 0x36d4*/
/*354c mov bx, word ptr [0]*/
/*3550 mov al, byte ptr [bx + 0x201c]*/
/*3554 mov ah, 0*/
/*3556 neg ax*/
/*3558 add ax, 0x7f*/
/*355b push ax*/
/*355c mov ax, 0*/
/*355f push ax*/
/*3560 mov ax, 0*/
/*3563 push ax*/
/*3564 mov al, byte ptr [bx + 0x2029]*/
/*3568 mov ah, 0*/
/*356a neg ax*/
/*356c add ax, 0x7f*/
/*356f push ax*/
/*3570 call 0x36d4*/
/*3573 mov bx, word ptr [0]*/
/*3577 mov al, byte ptr [bx + 0x201c]*/
/*357b mov ah, 0*/
/*357d add ax, 0x80*/
/*3580 push ax*/
/*3581 mov ax, 0xff*/
/*3584 push ax*/
/*3585 mov ax, 0xff*/
/*3588 push ax*/
/*3589 mov al, byte ptr [bx + 0x2029]*/
/*358d mov ah, 0*/
/*358f add ax, 0x80*/
/*3592 push ax*/
/*3593 call 0x36d4*/
/*3596 mov bx, word ptr [0]*/
/*359a mov al, byte ptr [bx + 0x201c]*/
/*359e mov ah, 0*/
/*35a0 neg ax*/
/*35a2 add ax, 0x7f*/
/*35a5 push ax*/
/*35a6 mov ax, 0xff*/
/*35a9 push ax*/
/*35aa mov ax, 0*/
/*35ad push ax*/
/*35ae mov al, byte ptr [bx + 0x2029]*/
/*35b2 mov ah, 0*/
/*35b4 add ax, 0x80*/
/*35b7 push ax*/
/*35b8 call 0x36d4*/
/*35bb ret */
void sub_134a8()
{
  di = 0x0000;
  ax = memoryAGet16(ds, 0x94f4);
  es = ax;
  ax = 0x0000;
  cx = 0x1000;
  flags.direction = 0;
  for (; cx != 0; --cx) stosw<ES_DI>(ax);
  ax = 0x004f;
  push(ax);
  ax = 0x00ff;
  push(ax);
  ax = 0x00b0;
  push(ax);
  ax = 0x0000;
  push(ax);
  sub_136d4();
  ax = 0x004f;
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x00b0;
  push(ax);
  ax = 0x00ff;
  push(ax);
  sub_136d4();
  ax = 0x0000;
  push(ax);
  ax = 0x004f;
  push(ax);
  ax = 0x00ff;
  push(ax);
  ax = 0x00b0;
  push(ax);
  sub_136d4();
  ax = 0x0000;
  push(ax);
  ax = 0x00b0;
  push(ax);
  ax = 0x00ff;
  push(ax);
  ax = 0x004f;
  push(ax);
  sub_136d4();
  ax = memoryAGet16(ds, 0x9547);
  ax &= 0x003f;
  memoryASet16(ds, 0x954e, ax);
  bx = ax;
  ax += 0x0040;
  push(ax);
  al = memoryAGet(ds, bx + 8156);
  ah = 0x00;
  push(ax);
  sub_135bc();
  ax = memoryAGet16(ds, 0x954e);
  
  if (ax <= 0x000c) goto loc_13527;
  return;
loc_13527:
  bx = memoryAGet16(ds, 0x954e);
  al = memoryAGet(ds, bx + 8220);
  ah = 0x00;
  ax += 0x0080;
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x00ff;
  push(ax);
  al = memoryAGet(ds, bx + 8233);
  ah = 0x00;
  ax = -ax;
  ax += 0x007f;
  push(ax);
  sub_136d4();
  bx = memoryAGet16(ds, 0x954e);
  al = memoryAGet(ds, bx + 8220);
  ah = 0x00;
  ax = -ax;
  ax += 0x007f;
  push(ax);
  ax = 0x0000;
  push(ax);
  ax = 0x0000;
  push(ax);
  al = memoryAGet(ds, bx + 8233);
  ah = 0x00;
  ax = -ax;
  ax += 0x007f;
  push(ax);
  sub_136d4();
  bx = memoryAGet16(ds, 0x954e);
  al = memoryAGet(ds, bx + 8220);
  ah = 0x00;
  ax += 0x0080;
  push(ax);
  ax = 0x00ff;
  push(ax);
  ax = 0x00ff;
  push(ax);
  al = memoryAGet(ds, bx + 8233);
  ah = 0x00;
  ax += 0x0080;
  push(ax);
  sub_136d4();
  bx = memoryAGet16(ds, 0x954e);
  al = memoryAGet(ds, bx + 8220);
  ah = 0x00;
  ax = -ax;
  ax += 0x007f;
  push(ax);
  ax = 0x00ff;
  push(ax);
  ax = 0x0000;
  push(ax);
  al = memoryAGet(ds, bx + 8233);
  ah = 0x00;
  ax += 0x0080;
  push(ax);
  sub_136d4();
  return;
}

/*35bc push bp*/
/*35bd mov bp, sp*/
/*35bf mov ax, 0x7f*/
/*35c2 sub ax, word ptr [bp + 4]*/
/*35c5 push ax*/
/*35c6 mov ax, 0x7f*/
/*35c9 sub ax, word ptr [bp + 6]*/
/*35cc push ax*/
/*35cd mov ax, 0x80*/
/*35d0 add ax, word ptr [bp + 4]*/
/*35d3 push ax*/
/*35d4 mov ax, 0x7f*/
/*35d7 sub ax, word ptr [bp + 6]*/
/*35da push ax*/
/*35db call 0x36d4*/
/*35de mov ax, 0x80*/
/*35e1 add ax, word ptr [bp + 4]*/
/*35e4 push ax*/
/*35e5 mov ax, 0x7f*/
/*35e8 sub ax, word ptr [bp + 6]*/
/*35eb push ax*/
/*35ec mov ax, 0x80*/
/*35ef add ax, word ptr [bp + 6]*/
/*35f2 push ax*/
/*35f3 mov ax, 0x7f*/
/*35f6 sub ax, word ptr [bp + 4]*/
/*35f9 push ax*/
/*35fa call 0x36d4*/
/*35fd mov ax, 0x80*/
/*3600 add ax, word ptr [bp + 6]*/
/*3603 push ax*/
/*3604 mov ax, 0x7f*/
/*3607 sub ax, word ptr [bp + 4]*/
/*360a push ax*/
/*360b mov ax, 0x80*/
/*360e add ax, word ptr [bp + 6]*/
/*3611 push ax*/
/*3612 mov ax, 0x80*/
/*3615 add ax, word ptr [bp + 4]*/
/*3618 push ax*/
/*3619 call 0x36d4*/
/*361c mov ax, 0x80*/
/*361f add ax, word ptr [bp + 4]*/
/*3622 push ax*/
/*3623 mov ax, 0x80*/
/*3626 add ax, word ptr [bp + 6]*/
/*3629 push ax*/
/*362a mov ax, 0x80*/
/*362d add ax, word ptr [bp + 6]*/
/*3630 push ax*/
/*3631 mov ax, 0x80*/
/*3634 add ax, word ptr [bp + 4]*/
/*3637 push ax*/
/*3638 call 0x36d4*/
/*363b mov ax, 0x7f*/
/*363e sub ax, word ptr [bp + 4]*/
/*3641 push ax*/
/*3642 mov ax, 0x80*/
/*3645 add ax, word ptr [bp + 6]*/
/*3648 push ax*/
/*3649 mov ax, 0x80*/
/*364c add ax, word ptr [bp + 4]*/
/*364f push ax*/
/*3650 mov ax, 0x80*/
/*3653 add ax, word ptr [bp + 6]*/
/*3656 push ax*/
/*3657 call 0x36d4*/
/*365a mov ax, 0x7f*/
/*365d sub ax, word ptr [bp + 6]*/
/*3660 push ax*/
/*3661 mov ax, 0x80*/
/*3664 add ax, word ptr [bp + 4]*/
/*3667 push ax*/
/*3668 mov ax, 0x7f*/
/*366b sub ax, word ptr [bp + 4]*/
/*366e push ax*/
/*366f mov ax, 0x80*/
/*3672 add ax, word ptr [bp + 6]*/
/*3675 push ax*/
/*3676 call 0x36d4*/
/*3679 mov ax, 0x7f*/
/*367c sub ax, word ptr [bp + 6]*/
/*367f push ax*/
/*3680 mov ax, 0x7f*/
/*3683 sub ax, word ptr [bp + 4]*/
/*3686 push ax*/
/*3687 mov ax, 0x7f*/
/*368a sub ax, word ptr [bp + 6]*/
/*368d push ax*/
/*368e mov ax, 0x80*/
/*3691 add ax, word ptr [bp + 4]*/
/*3694 push ax*/
/*3695 call 0x36d4*/
/*3698 mov ax, 0x7f*/
/*369b sub ax, word ptr [bp + 6]*/
/*369e push ax*/
/*369f mov ax, 0x7f*/
/*36a2 sub ax, word ptr [bp + 4]*/
/*36a5 push ax*/
/*36a6 mov ax, 0x7f*/
/*36a9 sub ax, word ptr [bp + 4]*/
/*36ac push ax*/
/*36ad mov ax, 0x7f*/
/*36b0 sub ax, word ptr [bp + 6]*/
/*36b3 push ax*/
/*36b4 call 0x36d4*/
/*36b7 mov ax, word ptr [bp + 6]*/
/*36ba shr ax, 1*/
/*36bc cmp al, byte ptr [0]*/
/*36c0 jbe 0x36d0*/
/*36c2 mov word ptr [bp + 6], ax*/
/*36c5 mov ax, word ptr [bp + 4]*/
/*36c8 shr ax, 1*/
/*36ca mov word ptr [bp + 4], ax*/
/*36cd jmp 0x35bf*/
/*36d0 pop bp*/
/*36d1 ret 4*/
void sub_135bc()
{
  push(bp);
  bp = sp;
loc_135bf:
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  sub_136d4();
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  sub_136d4();
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  sub_136d4();
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  sub_136d4();
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  sub_136d4();
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  sub_136d4();
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x0080;
  ax += memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  sub_136d4();
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 4 - 2);
  push(ax);
  ax = 0x007f;
  ax -= memoryAGet16(ss, bp + 6 - 2);
  push(ax);
  sub_136d4();
  ax = memoryAGet16(ss, bp + 6 - 2);
  ax >>= 0x0001;
  
  if (al <= memoryAGet(ds, 0x9549)) goto loc_136d0;
  memoryASet16(ss, bp + 6 - 2, ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  ax >>= 0x0001;
  memoryASet16(ss, bp + 4 - 2, ax);
  goto loc_135bf;
loc_136d0:
  bp = pop();
  return;
}

/*36d4 push bp*/
/*36d5 mov bp, sp*/
/*36d7 sub sp, 0xa*/
/*36da mov ax, word ptr [0x94f4]*/
/*36dd mov es, ax*/
/*36df mov ax, word ptr [bp + 8]*/
/*36e2 cmp ax, 0*/
/*36e5 je 0x36fa*/
/*36e7 mov bx, ax*/
/*36e9 shl ax, 1*/
/*36eb shl ax, 1*/
/*36ed add ax, bx*/
/*36ef shl ax, 1*/
/*36f1 add ax, 5*/
/*36f4 mov bl, 0xc*/
/*36f6 div bl*/
/*36f8 mov ah, 0*/
/*36fa mov word ptr [bp + 8], ax*/
/*36fd mov ax, word ptr [bp + 4]*/
/*3700 cmp ax, 0*/
/*3703 je 0x3718*/
/*3705 mov bx, ax*/
/*3707 shl ax, 1*/
/*3709 shl ax, 1*/
/*370b add ax, bx*/
/*370d shl ax, 1*/
/*370f add ax, 5*/
/*3712 mov bl, 0xc*/
/*3714 div bl*/
/*3716 mov ah, 0*/
/*3718 mov word ptr [bp + 4], ax*/
/*371b mov ax, word ptr [bp + 0xa]*/
/*371e mov bx, word ptr [bp + 6]*/
/*3721 cmp bx, ax*/
/*3723 jae 0x3737*/
/*3725 mov word ptr [bp + 0xa], bx*/
/*3728 mov word ptr [bp + 6], ax*/
/*372b mov ax, word ptr [bp + 8]*/
/*372e mov bx, word ptr [bp + 4]*/
/*3731 mov word ptr [bp + 8], bx*/
/*3734 mov word ptr [bp + 4], ax*/
/*3737 mov ax, word ptr [bp + 6]*/
/*373a sub ax, word ptr [bp + 0xa]*/
/*373d mov word ptr [bp - 2], ax*/
/*3740 mov ax, word ptr [bp + 4]*/
/*3743 sub ax, word ptr [bp + 8]*/
/*3746 jns 0x3751*/
/*3748 neg ax*/
/*374a mov word ptr [bp - 0xa], 0xffe0*/
/*374f jmp 0x3756*/
/*3751 mov word ptr [bp - 0xa], 0x20*/
/*3756 mov word ptr [bp - 4], ax*/
/*3759 mov cx, word ptr [bp - 2]*/
/*375c cmp cx, 0*/
/*375f je 0x37db*/
/*3761 cmp ax, 0*/
/*3764 jne 0x3769*/
/*3766 jmp 0x37ed*/
/*3769 cmp ax, word ptr [bp - 2]*/
/*376c jae 0x37a4*/
/*376e mov ax, word ptr [bp - 2]*/
/*3771 shr ax, 1*/
/*3773 mov word ptr [bp - 6], ax*/
/*3776 call 0x3801*/
/*3779 mov cx, word ptr [bp - 2]*/
/*377c shr al, 1*/
/*377e jne 0x3783*/
/*3780 mov al, 0x80*/
/*3782 inc di*/
/*3783 mov bx, word ptr [bp - 6]*/
/*3786 add bx, word ptr [bp - 4]*/
/*3789 mov word ptr [bp - 6], bx*/
/*378c cmp bx, word ptr [bp - 2]*/
/*378f jbe 0x379d*/
/*3791 sub bx, word ptr [bp - 2]*/
/*3794 mov word ptr [bp - 6], bx*/
/*3797 mov bx, word ptr [bp - 0xa]*/
/*379a add di, word ptr [bp - 0xa]*/
/*379d or byte ptr es:[di], al*/
/*37a0 loop 0x377c*/
/*37a2 jmp 0x37d5*/
/*37a4 mov ax, word ptr [bp - 4]*/
/*37a7 shr ax, 1*/
/*37a9 mov word ptr [bp - 6], ax*/
/*37ac call 0x3801*/
/*37af mov cx, word ptr [bp - 4]*/
/*37b2 add di, word ptr [bp - 0xa]*/
/*37b5 mov bx, word ptr [bp - 6]*/
/*37b8 add bx, word ptr [bp - 2]*/
/*37bb mov word ptr [bp - 6], bx*/
/*37be cmp bx, word ptr [bp - 4]*/
/*37c1 jbe 0x37d0*/
/*37c3 sub bx, word ptr [bp - 4]*/
/*37c6 mov word ptr [bp - 6], bx*/
/*37c9 shr al, 1*/
/*37cb jne 0x37d0*/
/*37cd mov al, 0x80*/
/*37cf inc di*/
/*37d0 or byte ptr es:[di], al*/
/*37d3 loop 0x37b2*/
/*37d5 mov sp, bp*/
/*37d7 pop bp*/
/*37d8 ret 8*/
/*37db call 0x3801*/
/*37de mov cx, word ptr [bp - 4]*/
/*37e1 jcxz 0x37d5*/
/*37e3 add di, word ptr [bp - 0xa]*/
/*37e6 or byte ptr es:[di], al*/
/*37e9 loop 0x37e3*/
/*37eb jmp 0x37d5*/
/*37ed call 0x3801*/
/*37f0 mov cx, word ptr [bp - 2]*/
/*37f3 shr al, 1*/
/*37f5 jne 0x37fa*/
/*37f7 mov al, 0x80*/
/*37f9 inc di*/
/*37fa or byte ptr es:[di], al*/
/*37fd loop 0x37f3*/
/*37ff jmp 0x37d5*/
void sub_136d4()
{
  push(bp);
  bp = sp;
  sp -= 0x000a;
  ax = memoryAGet16(ds, 0x94f4);
  es = ax;
  ax = memoryAGet16(ss, bp + 8 - 2);
  
  if (ax == 0x0000) goto loc_136fa;
  bx = ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += bx;
  ax <<= 0x0001;
  ax += 0x0005;
  bl = 0x0c;
  div8(bl);
  ah = 0x00;
loc_136fa:
  memoryASet16(ss, bp + 8 - 2, ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  
  if (ax == 0x0000) goto loc_13718;
  bx = ax;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += bx;
  ax <<= 0x0001;
  ax += 0x0005;
  bl = 0x0c;
  div8(bl);
  ah = 0x00;
loc_13718:
  memoryASet16(ss, bp + 4 - 2, ax);
  ax = memoryAGet16(ss, bp + 10 - 2);
  bx = memoryAGet16(ss, bp + 6 - 2);
  
  if (bx >= ax) goto loc_13737;
  memoryASet16(ss, bp + 10 - 2, bx);
  memoryASet16(ss, bp + 6 - 2, ax);
  ax = memoryAGet16(ss, bp + 8 - 2);
  bx = memoryAGet16(ss, bp + 4 - 2);
  memoryASet16(ss, bp + 8 - 2, bx);
  memoryASet16(ss, bp + 4 - 2, ax);
loc_13737:
  ax = memoryAGet16(ss, bp + 6 - 2);
  ax -= memoryAGet16(ss, bp + 10 - 2);
  memoryASet16(ss, bp - 2 - 2, ax);
  ax = memoryAGet16(ss, bp + 4 - 2);
  ax -= memoryAGet16(ss, bp + 8 - 2);
  if ((short)ax >= 0) goto loc_13751;
  ax = -ax;
  memoryASet16(ss, bp - 10 - 2, 0xffe0);
  goto loc_13756;
loc_13751:
  memoryASet16(ss, bp - 10 - 2, 0x0020);
loc_13756:
  memoryASet16(ss, bp - 4 - 2, ax);
  cx = memoryAGet16(ss, bp - 2 - 2);
  
  if (cx == 0x0000) goto loc_137db;
  
  if (ax != 0x0000) goto loc_13769;
  goto loc_137ed;
loc_13769:
  
  if (ax >= memoryAGet16(ss, bp - 2 - 2)) goto loc_137a4;
  ax = memoryAGet16(ss, bp - 2 - 2);
  ax >>= 0x0001;
  memoryASet16(ss, bp - 6 - 2, ax);
  sub_13801();
  cx = memoryAGet16(ss, bp - 2 - 2);
loc_1377c:
  al >>= 0x01;
  if (al) goto loc_13783;
  al = 0x80;
  di++;
loc_13783:
  bx = memoryAGet16(ss, bp - 6 - 2);
  bx += memoryAGet16(ss, bp - 4 - 2);
  memoryASet16(ss, bp - 6 - 2, bx);
  
  if (bx <= memoryAGet16(ss, bp - 2 - 2)) goto loc_1379d;
  bx -= memoryAGet16(ss, bp - 2 - 2);
  memoryASet16(ss, bp - 6 - 2, bx);
  bx = memoryAGet16(ss, bp - 10 - 2);
  di += memoryAGet16(ss, bp - 10 - 2);
loc_1379d:
  memoryASet(es, di, memoryAGet(es, di) | al);
  if (--cx) goto loc_1377c;
  goto loc_137d5;
loc_137a4:
  ax = memoryAGet16(ss, bp - 4 - 2);
  ax >>= 0x0001;
  memoryASet16(ss, bp - 6 - 2, ax);
  sub_13801();
  cx = memoryAGet16(ss, bp - 4 - 2);
loc_137b2:
  di += memoryAGet16(ss, bp - 10 - 2);
  bx = memoryAGet16(ss, bp - 6 - 2);
  bx += memoryAGet16(ss, bp - 2 - 2);
  memoryASet16(ss, bp - 6 - 2, bx);
  
  if (bx <= memoryAGet16(ss, bp - 4 - 2)) goto loc_137d0;
  bx -= memoryAGet16(ss, bp - 4 - 2);
  memoryASet16(ss, bp - 6 - 2, bx);
  al >>= 0x01;
  if (al) goto loc_137d0;
  al = 0x80;
  di++;
loc_137d0:
  memoryASet(es, di, memoryAGet(es, di) | al);
  if (--cx) goto loc_137b2;
loc_137d5:
  sp = bp;
  bp = pop();
  return;
loc_137db:
  sub_13801();
  cx = memoryAGet16(ss, bp - 4 - 2);
  if (cx==0) goto loc_137d5;
loc_137e3:
  di += memoryAGet16(ss, bp - 10 - 2);
  memoryASet(es, di, memoryAGet(es, di) | al);
  if (--cx) goto loc_137e3;
  goto loc_137d5;
loc_137ed:
  sub_13801();
  cx = memoryAGet16(ss, bp - 2 - 2);
loc_137f3:
  al >>= 0x01;
  if (al) goto loc_137fa;
  al = 0x80;
  di++;
loc_137fa:
  memoryASet(es, di, memoryAGet(es, di) | al);
  if (--cx) goto loc_137f3;
  goto loc_137d5;
}

/*3801 mov ax, word ptr [bp + 8]*/
/*3804 shl ax, 1*/
/*3806 shl ax, 1*/
/*3808 shl ax, 1*/
/*380a shl ax, 1*/
/*380c shl ax, 1*/
/*380e mov di, ax*/
/*3810 mov ax, word ptr [bp + 0xa]*/
/*3813 shr ax, 1*/
/*3815 shr ax, 1*/
/*3817 shr ax, 1*/
/*3819 add di, ax*/
/*381b mov cx, word ptr [bp + 0xa]*/
/*381e and cx, 7*/
/*3821 mov al, 0x80*/
/*3823 shr al, cl*/
/*3825 or byte ptr es:[di], al*/
/*3828 ret */
void sub_13801()
{
  ax = memoryAGet16(ss, bp + 8 - 2);
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax <<= 0x0001;
  di = ax;
  ax = memoryAGet16(ss, bp + 10 - 2);
  ax >>= 0x0001;
  ax >>= 0x0001;
  ax >>= 0x0001;
  di += ax;
  cx = memoryAGet16(ss, bp + 10 - 2);
  cx &= 0x0007;
  al = 0x80;
  al >>= cl;
  memoryASet(es, di, memoryAGet(es, di) | al);
  return;
}

/*382a mov al, 0*/
/*382c mov byte ptr [0x9550], al*/
/*382f mov byte ptr [0x9551], al*/
/*3832 mov byte ptr [0x9552], al*/
/*3835 mov byte ptr [0], 1*/
/*383a mov byte ptr [0], 0*/
/*383f ret */
void sub_1382a()
{
  al = 0x00;
  memoryASet(ds, 0x9550, al);
  memoryASet(ds, 0x9551, al);
  memoryASet(ds, 0x9552, al);
  memoryASet(ds, 0x9506, 0x01);
  memoryASet(ds, 0x9505, 0x00);
  return;
}

/*3840 mov ah, byte ptr [0]*/
/*3844 cmp ah, 0*/
/*3847 je 0x384a*/
/*3849 ret */
/*384a mov ah, byte ptr [0]*/
/*384e cmp ah, 0*/
/*3851 jne 0x3854*/
/*3853 ret */
/*3854 mov ah, byte ptr [0]*/
/*3858 cmp ah, 0*/
/*385b jne 0x3866*/
/*385d push bx*/
/*385e mov byte ptr [0x9550], al*/
/*3861 call 0x3914*/
/*3864 pop bx*/
/*3865 ret */
/*3866 mov ah, byte ptr [0]*/
/*386a cmp ah, 0*/
/*386d jne 0x3873*/
/*386f mov byte ptr [0x9551], al*/
/*3872 ret */
/*3873 cmp al, byte ptr [0]*/
/*3877 jbe 0x387c*/
/*3879 mov byte ptr [0x9552], al*/
/*387c ret */
void sub_13840()
{
  ah = memoryAGet(ds, 0x955e);
  
  if (ah == 0x00) goto loc_1384a;
  return;
loc_1384a:
  ah = memoryAGet(ds, 0x9506);
  
  if (ah != 0x00) goto loc_13854;
  return;
loc_13854:
  ah = memoryAGet(ds, 0x9550);
  
  if (ah != 0x00) goto loc_13866;
  push(bx);
  memoryASet(ds, 0x9550, al);
  sub_13914();
  bx = pop();
  return;
loc_13866:
  ah = memoryAGet(ds, 0x9551);
  
  if (ah != 0x00) goto loc_13873;
  memoryASet(ds, 0x9551, al);
  return;
loc_13873:
  
  if (al <= memoryAGet(ds, 0x9552)) goto loc_1387c;
  memoryASet(ds, 0x9552, al);
loc_1387c:
  return;
}

/*3914 dec al*/
/*3916 mov bl, al*/
/*3918 mov bh, 0*/
/*391a shl bx, 1*/
/*391c mov bx, word ptr [bx - 0x741c]*/
/*3920 mov al, byte ptr [bx + 1]*/
/*3923 mov byte ptr [0x9557], al*/
/*3926 cmp bx, 0x8c2c*/
/*392a jne 0x3941*/
/*392c mov ax, word ptr [0x9536]*/
/*392f mov ah, al*/
/*3931 mov al, 0*/
/*3933 shl ax, 1*/
/*3935 shl ax, 1*/
/*3937 neg ax*/
/*3939 add ax, 0x1f40*/
/*393c mov word ptr [0x8c2e], ax*/
/*393f jmp 0x3966*/
/*3941 cmp bx, 0x8c32*/
/*3945 jne 0x3966*/
/*3947 mov al, byte ptr [0x1ba0]*/
/*394a and ax, 0x7f*/
/*394d cmp ax, 0x3f*/
/*3950 jbe 0x3957*/
/*3952 sub ax, 0x40*/
/*3955 jmp 0x395c*/
/*3957 neg ax*/
/*3959 add ax, 0x3f*/
/*395c shl ax, 1*/
/*395e shl ax, 1*/
/*3960 add ax, 0x190*/
/*3963 mov word ptr [0x8c34], ax*/
/*3966 mov ax, word ptr [bx + 2]*/
/*3969 mov word ptr [0x9558], ax*/
/*396c mov ax, word ptr [bx + 4]*/
/*396f mov word ptr [0x955a], ax*/
/*3972 mov bl, byte ptr [bx]*/
/*3974 mov byte ptr [0], bl*/
/*3978 cmp bl, 0*/
/*397b jle 0x398f*/
/*397d dec bl*/
/*397f mov bh, 0*/
/*3981 shl bx, 1*/
/*3983 mov ax, word ptr [bx - 0x73a4]*/
/*3987 mov word ptr [0x9555], ax*/
/*398a mov byte ptr [0], 0*/
/*398f mov al, 0xb6*/
/*3991 out 0x43, al*/
/*3993 mov ax, word ptr [0x9558]*/
/*3996 out 0x42, al*/
/*3998 mov al, ah*/
/*399a out 0x42, al*/
/*399c in al, 0x61*/
/*399e or al, 3*/
/*39a0 out 0x61, al*/
/*39a2 ret */
void sub_13914()
{
  al--;
  bl = al;
  bh = 0x00;
  bx <<= 0x0001;
  bx = memoryAGet16(ds, bx + 35812);
  al = memoryAGet(ds, bx + 1);
  memoryASet(ds, 0x9557, al);
  
  if (bx != 0x8c2c) goto loc_13941;
  ax = memoryAGet16(ds, 0x9536);
  ah = al;
  al = 0x00;
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax = -ax;
  ax += 0x1f40;
  memoryASet16(ds, 0x8c2e, ax);
  goto loc_13966;
loc_13941:
  
  if (bx != 0x8c32) goto loc_13966;
  al = memoryAGet(ds, 0x1ba0);
  ax &= 0x007f;
  
  if (ax <= 0x003f) goto loc_13957;
  ax -= 0x0040;
  goto loc_1395c;
loc_13957:
  ax = -ax;
  ax += 0x003f;
loc_1395c:
  ax <<= 0x0001;
  ax <<= 0x0001;
  ax += 0x0190;
  memoryASet16(ds, 0x8c34, ax);
loc_13966:
  ax = memoryAGet16(ds, bx + 2);
  memoryASet16(ds, 0x9558, ax);
  ax = memoryAGet16(ds, bx + 4);
  memoryASet16(ds, 0x955a, ax);
  bl = memoryAGet(ds, bx);
  memoryASet(ds, 0x9553, bl);
  
  if ((char)bl <= (char)0x00) goto loc_1398f;
  bl--;
  bh = 0x00;
  bx <<= 0x0001;
  ax = memoryAGet16(ds, bx + 35932);
  memoryASet16(ds, 0x9555, ax);
  memoryASet(ds, 0x9554, 0x00);
loc_1398f:
  al = 0xb6;
  out8(0x43, al);
  ax = memoryAGet16(ds, 0x9558);
  out8(0x42, al);
  al = ah;
  out8(0x42, al);
  al = in8(0x61);
  al |= 0x03;
  out8(0x61, al);
  return;
}

/*39a3 mov al, 0*/
/*39a5 mov byte ptr [0x9550], al*/
/*39a8 mov byte ptr [0x9551], al*/
/*39ab mov byte ptr [0x9552], al*/
/*39ae mov byte ptr [0x9557], al*/
/*39b1 in al, 0x61*/
/*39b3 and al, 0xfc*/
/*39b5 out 0x61, al*/
/*39b7 ret */
void sub_139a3()
{
  al = 0x00;
  memoryASet(ds, 0x9550, al);
  memoryASet(ds, 0x9551, al);
  memoryASet(ds, 0x9552, al);
  memoryASet(ds, 0x9557, al);
  al = in8(0x61);
  al &= 0xfc;
  out8(0x61, al);
  return;
}

/*39b8 mov byte ptr [0], 0*/
/*39bd mov word ptr [0], 0*/
/*39c3 mov byte ptr [0], 1*/
/*39c8 mov al, byte ptr [0x9546]*/
/*39cb cmp al, 0*/
/*39cd jne 0x39d4*/
/*39cf mov ax, 0x8dec*/
/*39d2 jmp 0x39d7*/
/*39d4 mov ax, 0x8d4c*/
/*39d7 mov word ptr [0x9562], ax*/
/*39da ret */
void sub_139b8()
{
  memoryASet(ds, 0x9561, 0x00);
  memoryASet16(ds, 0x955f, 0x0000);
  memoryASet(ds, 0x955e, 0x01);
  al = memoryAGet(ds, 0x9546);
  
  if (al != 0x00) goto loc_139d4;
  ax = 0x8dec;
  goto loc_139d7;
loc_139d4:
  ax = 0x8d4c;
loc_139d7:
  memoryASet16(ds, 0x9562, ax);
  return;
}
