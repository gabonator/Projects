seg001 segment	byte public 'CODE' use16
entry proc near
  sti
  cld
  mov dx, 0xffff
  mov si, 0x80
  lodsb
  cbw
  mov cx, ax
  jcxz loc_004f
loc_0013:
  lodsb
  cmp al, 0x2f
  jz loc_001c
  loop loc_0013
  jmp loc_004f
loc_001c:
  lodsb
  and al, 0xdf
  cmp al, 0x56
  jnz loc_0025
  mov dl, 0x5
loc_0025:
  cmp al, 0x45
  jnz loc_002b
  mov dl, 0x3
loc_002b:
  cmp al, 0x54
  jnz loc_0031
  mov dl, 0x2
loc_0031:
  cmp al, 0x43
  jnz loc_0037
  mov dl, 0x1
loc_0037:
  cmp al, 0x48
  jnz loc_003d
  mov dl, 0x0
loc_003d:
  cmp al, 0x42
  jnz loc_0043
  mov dh, 0x0
loc_0043:
  cmp al, 0x46
  jnz loc_004d
  mov byte ptr cs:[0x3], 0x0
loc_004d:
  loop loc_0013
loc_004f:
  mov ax, 0x168f
  mov ds, ax
  mov byte ptr cs:[0x1], dl
  mov byte ptr cs:[0x2], dh
  mov ax, 0x8f01
  mov cl, 0x4
  shr ax, cl
  add ax, 0x1690
  mov [0x4c1], ax
  push ds
  xor ax, ax
  mov ds, ax
  mov word ptr [0x90], 0x8d0
  mov word ptr [0x92], cs
  pop ds
  call sub_17fe
  mov ax, 0x168f
  mov ds, ax
  mov ax, 0x168f
  mov ds, ax
  call sub_107d
  call sub_0ceb
  call sub_0701
  call sub_307d
  call sub_3160
  nop
  nop
  nop
  mov dx, 0x0
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0xe], ax
  call sub_183f
  call sub_1198
  mov ax, 0x4000
  out 0x40, al
  mov al, ah
  out 0x40, al
  call sub_53a2
  call sub_52ec
  call sub_24c9
  mov ax, [0x4c1]
  mov [0xc], ax
loc_00c5:
  mov dx, word ptr [0xc]
  mov word ptr [0x4c1], dx
  or ax, ax
  jz loc_00e9
  call sub_51c6
  call sub_3160
  mov byte ptr [0x41b], 0x2
  mov byte ptr [0x419], 0x10
  mov byte ptr [0x41a], 0x0
  call sub_0173
loc_00e9:
  call sub_3160
  mov al, [0x5250]
  call sub_2eb7
  call sub_378d
  call sub_56cc
  mov ax, 0x168f
  mov ds, ax
  mov bl, byte ptr [0x5250]
  xor bh, bh
  mov al, byte ptr [bx+0x508c]
  cbw
  call sub_10ff
  call sub_3ee8
  call sub_2d62
  call sub_2c87
  call sub_3271
loc_0117:
  mov ax, 0x168f
  mov ds, ax
  inc word ptr [0x64fe]
  call sub_3e28
  call sub_39c7
  call sub_414b
  call sub_5945
  call sub_58c8
  call sub_5737
  call sub_38b5
  call sub_37f5
  call sub_3f46
  call sub_2ba2
  call sub_2c87
  call sub_1c61
  call sub_3627
  jnc loc_014c
  jmp loc_00c5
loc_014c:
  call sub_05b7
  call sub_0158
  call sub_3271
  jmp loc_0117
  db 00h
entry endp ; sp-analysis failed

sub_0158 proc near
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr cs:[0x16e4], 0x3
  jnz loc_0172
  cmp byte ptr [0x9b2], 0x0
  jnz loc_0172
  mov ax, [0x913]
  call sub_10ff
loc_0172:
  ret
sub_0158 endp

sub_0173 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov ax, 0x0
  call sub_10ff
  call sub_2811
  call sub_01f8
  cmp byte ptr [0x41a], 0xa
  jc loc_01c6
  call sub_03f2
loc_0197:
  cmp byte ptr [0x41a], 0xa
  jc loc_01c6
  mov dx, 0xa
loc_01a1:
  dec byte ptr [0x41a]
  push dx
  call sub_0244
  pop dx
  mov cx, 0xf
loc_01ad:
  call sub_3243
  loop loc_01ad
  dec dx
  jnz loc_01a1
  inc byte ptr [0x41b]
  call sub_0244
  mov cx, 0xa
loc_01bf:
  call sub_3243
  loop loc_01bf
  jmp loc_0197
loc_01c6:
  call sub_0244
  call sub_03f2
  call sub_03ae
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_0173 endp

sub_01d9 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  call sub_2811
  call sub_01f8
  call sub_03f2
  call sub_03ae
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_01d9 endp

sub_01f8 proc near
  mov ax, 0x168f
  mov ds, ax
  call sub_038a
  mov word ptr [0x1f5], 0xd
  mov word ptr [0x1f7], 0x960
  call sub_03dc
  mov cl, byte ptr [0x5250]
  xor ch, ch
  mov si, 0x5104
  jcxz loc_0223
loc_021a:
  lodsb
  or al, al
  jnz loc_021a
  inc si
  loop loc_021a
  dec si
loc_0223:
  xor bx, bx
loc_0225:
  inc bx
  cmp byte ptr [bx+si], 0x0
  jnz loc_0225
  dec bx
  shr bx, 1
  adc bl, 0x1
  mov word ptr [0x1f5], 0x14
  mov word ptr [0x1f7], 0xbe0
  sub word ptr [0x1f5], bx
  call sub_0488
sub_01f8 endp ; sp-analysis failed

sub_0244 proc near
  mov word ptr [0x1f5], 0xa
  mov word ptr [0x1f7], 0x12c0
  mov si, 0x10
  call sub_0488
  mov dl, byte ptr [0x41a]
  xor dh, dh
  call sub_0423
  mov word ptr [0x1f5], 0xa
  mov word ptr [0x1f7], 0x14a0
  mov si, 0x1e
  call sub_0488
  mov dl, byte ptr [0x41b]
  xor dh, dh
  call sub_0423
  ret
sub_0244 endp

sub_027b proc near
  push bx
  push cx
  push dx
  push di
  push si
  push bp
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  call sub_3160
  call sub_038a
  mov word ptr [0x1f5], 0xe
  mov word ptr [0x1f7], 0xc80
  mov si, 0x2c
  call sub_0488
  sub word ptr [0x1f5], 0x4
  xor dx, dx
  mov cx, 0x4
loc_02aa:
  mov byte ptr [0x4c0], 0x0
loc_02af:
  mov bl, byte ptr [0x4c0]
  test bl, 0x80
  jnz loc_02aa
  xor bh, bh
  mov al, byte ptr [bx+0x175]
  cmp al, 0x2d
  jz loc_02af
  mov ah, al
  sub ah, 0x30
  cmp ah, 0x9
  jbe loc_02cf
  sub ah, 0x7
loc_02cf:
  shl dx, 1
  shl dx, 1
  shl dx, 1
  shl dx, 1
  or dl, ah
  call sub_050e
  loop loc_02aa
  mov word ptr [0x1f5], 0xb
  mov word ptr [0x1f7], 0x1040
  xor cx, cx
loc_02ec:
  mov ax, cx
  call sub_6582
  cmp ax, dx
  jz loc_0307
  inc cx
  cmp cx, 0x14
  jbe loc_02ec
loc_02fb:
  mov si, 0x37
  call sub_0488
  call sub_03f2
  stc
  jmp loc_032a
loc_0307:
  mov si, 0x48
  call sub_0488
  mov bx, cx
  mov dl, byte ptr [bx+0x523c]
  xor dh, dh
  cmp dl, 0xff
  jnz loc_0321
  sub word ptr [0x1f5], 0x9
  jmp loc_02fb
loc_0321:
  push bx
  call sub_0423
  call sub_03f2
  pop ax
  clc
loc_032a:
  pop es
  pop ds
  pop bp
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  ret
sub_027b endp

sub_0333 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  call sub_2811
  call sub_038a
  mov word ptr [0x1f5], 0xd
  mov word ptr [0x1f7], 0x1040
  call sub_03dc
  mov word ptr [0x1f5], 0xe
  mov word ptr [0x1f7], 0xc80
  mov si, 0x52
  call sub_0488
  mov al, [0x5250]
  cbw
  call sub_6582
  mov dx, ax
  call sub_0465
  call sub_03f2
  call sub_3243
  call sub_03ae
  call sub_276f
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_0333 endp

sub_038a proc near
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_039e
  cmp al, 0x3
  jnc loc_03a5
  ret
loc_039e:
  mov dx, 0x4c4
  call sub_0410
  ret
loc_03a5:
  mov dx, 0x4f4
  mov ax, 0x1002
  int 0x10
  ret
sub_038a endp

sub_03ae proc near
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  call sub_27df
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_03c5
  cmp al, 0x3
  jnc loc_03d3
  ret
loc_03c5:
  mov ax, 0x1012
  xor bx, bx
  mov cx, 0x10
  mov dx, 0x5057
  int 0x10
  ret
loc_03d3:
  mov dx, 0x5035
  mov ax, 0x1002
  int 0x10
  ret
sub_03ae endp

sub_03dc proc near
  mov si, 0x59
  call sub_0488
  mov bl, byte ptr [0x5250]
  xor bh, bh
  mov dl, byte ptr [bx+0x523c]
  xor dh, dh
  call sub_0423
  ret
sub_03dc endp

sub_03f2 proc near
  mov ax, 0x168f
  mov ds, ax
loc_03f7:
  call sub_0805
  mov al, [0x47e]
  or al, byte ptr [0x42b]
  jz loc_03f7
loc_0403:
  call sub_0805
  mov al, [0x42b]
  or al, byte ptr [0x47e]
  jnz loc_0403
  ret
sub_03f2 endp

sub_0410 proc near
  mov al, cs:[0x1]
  cmp al, 0x5
  jnz loc_0422
  mov ax, 0x1012
  xor bx, bx
  mov cx, 0x10
  int 0x10
loc_0422:
  ret
sub_0410 endp

sub_0423 proc near
  mov byte ptr [0x418], 0x0
  mov bx, 0x2710
loc_042b:
  mov al, 0x30
loc_042d:
  cmp dx, bx
  jc loc_0437
  sub dx, bx
  inc al
  jmp loc_042d
loc_0437:
  cmp al, 0x30
  jnz loc_044b
  cmp bx, 0x1
  jz loc_044b
  cmp byte ptr [0x418], 0x0
  jnz loc_044b
  mov al, 0x20
  jmp loc_0450
loc_044b:
  mov byte ptr [0x418], 0x1
loc_0450:
  call sub_050e
  mov ax, bx
  push dx
  xor dx, dx
  mov bx, 0xa
  div bx
  pop dx
  mov bx, ax
  or bx, bx
  jnz loc_042b
  ret
sub_0423 endp

sub_0465 proc near
  mov cx, 0x4
loc_0468:
  xor ax, ax
  shl dx, 1
  rcl ax, 1
  shl dx, 1
  rcl ax, 1
  shl dx, 1
  rcl ax, 1
  shl dx, 1
  rcl ax, 1
  cmp al, 0x9
  jbe loc_0480
  add al, 0x7
loc_0480:
  add al, 0x30
  call sub_050e
  loop loc_0468
  ret
sub_0465 endp

sub_0488 proc near
  push ax
loc_0489:
  lodsb
  or al, al
  jz loc_0493
  call sub_050e
  jmp loc_0489
loc_0493:
  pop ax
  ret
loc_0495:
  mov dl, al
  cmp byte ptr [0x43b], 0x0
  jnz loc_04bd
  inc byte ptr [0x43b]
  mov word ptr cs:[0x6676], 0x597
  mov ds, word ptr [0xe]
  xor si, si
  mov cx, 0x29
loc_04b2:
  mov ax, 0x10c
  call sub_65be
  add si, 0x30
  loop loc_04b2
loc_04bd:
  mov ax, 0x168f
  mov ds, ax
  mov di, word ptr [0x1f5]
  shl di, 1
  add di, word ptr [0x1f7]
  inc word ptr [0x1f5]
  mov ax, 0xb800
  mov es, ax
  mov cx, 0x6
  mov al, dl
  cmp al, 0x20
  jnz loc_04ee
  xor ax, ax
loc_04e0:
  stosw
  add di, 0x1ffe
  stosw
  sub di, 0x1fb2
  loop loc_04e0
  jmp loc_050c
loc_04ee:
  sub al, 0x30
  cmp al, 0x9
  jbe loc_04f6
  sub al, 0x2
loc_04f6:
  mov ds, word ptr [0xe]
  mov ah, 0x30
  mul ah
  mov si, ax
loc_0500:
  movsw
  add di, 0x1ffe
  movsw
  sub di, 0x1fb2
  loop loc_0500
loc_050c:
  jmp loc_058d
sub_0488 endp

sub_050e proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_0522
  jmp loc_0495
loc_0522:
  mov di, word ptr [0x1f7]
  add di, word ptr [0x1f5]
  add di, word ptr [0x5268]
  inc word ptr [0x1f5]
  cmp al, 0x20
  jnz loc_0556
  mov ax, 0xa000
  mov es, ax
  call sub_32dc
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  xor al, al
  mov cx, 0xc
loc_054a:
  stosb
  add di, 0x27
  loop loc_054a
  sub di, 0x1e0
  jmp loc_058d
loc_0556:
  sub al, 0x30
  cmp al, 0x9
  jbe loc_055e
  sub al, 0x2
loc_055e:
  mov ds, word ptr [0xe]
  mov ah, 0x30
  mul ah
  mov si, ax
  mov ax, 0xa000
  mov es, ax
  call sub_32dc
  mov dx, 0x3c4
  mov al, 0x2
  out dx, al
  inc dx
  mov al, 0x1
loc_0579:
  out dx, al
  mov cx, 0xc
loc_057d:
  movsb
  add di, 0x27
  loop loc_057d
  sub di, 0x1e0
  shl al, 1
  cmp al, 0x8
  jbe loc_0579
loc_058d:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
  db 00h
  db 00h
  db 00h
  db 00h
  db aah
  db 55h
  db 55h
  db 55h
  db ffh
  db ffh
  db ffh
  db ffh
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
sub_050e endp ; sp-analysis failed

sub_05b7 proc near
  sub byte ptr [0x6506], 0x1
  adc byte ptr [0x6506], 0x0
  jz loc_05c6
  call sub_05c7
loc_05c6:
  ret
sub_05b7 endp

sub_05c7 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr cs:[0x1], 0x3
  jc loc_0636
  mov si, word ptr [0x526a]
  add si, 0x174
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov dl, 0xce
  mov ax, 0x5
  out dx, ax
  mov ax, 0x3
  out dx, ax
  mov ax, 0x100
  out dx, ax
  mov ax, 0xf01
  out dx, ax
  mov ax, 0xf008
  out dx, ax
  mov cl, byte ptr [0x419]
  mov bl, cl
  xor ch, ch
  mov ax, 0xa000
  mov ds, ax
  mov bp, 0x28
  jcxz loc_0619
loc_0614:
  call sub_0691
  loop loc_0614
loc_0619:
  mov cl, 0x10
  sub cl, bl
  jz loc_0624
loc_061f:
  call sub_06ea
  loop loc_061f
loc_0624:
  mov ax, 0x1
  out dx, ax
  mov ax, 0xff08
  out dx, ax
loc_062c:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
loc_0636:
  mov bp, 0x4f
  mov di, 0x2e8
  mov es, word ptr [0x5262]
  mov al, 0xff
  mov cl, byte ptr [0x419]
  xor ch, ch
  jcxz loc_064f
loc_064a:
  call sub_065e
  loop loc_064a
loc_064f:
  mov cl, 0x10
  sub cl, byte ptr [0x419]
  jcxz loc_062c
loc_0657:
  call sub_06d4
  loop loc_0657
  jmp loc_062c
sub_05c7 endp

sub_065e proc near
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  sub di, 0x4af
  ret
sub_065e endp

sub_0691 proc near
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  sub si, 0x257
  ret
sub_0691 endp

sub_06d4 proc near
  add di, 0x1e0
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  add di, bp
  stosb
  sub di, 0x31f
  ret
sub_06d4 endp

sub_06ea proc near
  add si, 0xf0
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  add si, bp
  add byte ptr [si], al
  sub si, 0x167
  ret
sub_06ea endp

sub_0701 proc near
  mov ax, 0x168f
  mov ds, ax
  mov byte ptr [0x428], 0x3
loc_070b:
  mov byte ptr [0x41c], 0x0
  mov word ptr [0x41d], 0x320
  mov dx, 0x201
  mov cx, 0xc80
  mov ah, 0x3
  cli
loc_071f:
  in al, dx
  test al, 0x3
  jz loc_0727
  and ah, 0x2
loc_0727:
  test al, 0xc
  jz loc_072e
  and ah, 0x1
loc_072e:
  loop loc_071f
  mov al, 0xff
  test ah, 0x2
  jz loc_073a
  mov al, [0x42a]
loc_073a:
  test ah, 0x1
  jz loc_0742
  mov al, [0x429]
loc_0742:
  mov [0x427], al
  call sub_07b0
  jc loc_0796
  cmp ax, 0x320
  jnc loc_0796
  cmp bx, 0x320
  jnc loc_0796
  or ax, ax
  jz loc_0796
  or bx, bx
  jz loc_0796
  mov cl, 0x2
  mov bp, ax
  shr ax, cl
  sub ax, bp
  neg ax
  mov [0x41f], ax
  mov ax, bp
  shr ax, cl
  add ax, bp
  mov [0x425], ax
  mov bp, bx
  shr bx, cl
  sub bx, bp
  neg bx
  mov word ptr [0x421], bx
  mov bx, bp
  shr bx, cl
  add bx, bp
  mov word ptr [0x423], bx
  cmp ax, bx
  jnc loc_078f
  mov ax, bx
loc_078f:
  shl ax, 1
  mov [0x41d], ax
  jmp loc_07ae
loc_0796:
  dec byte ptr [0x428]
  jz loc_07a9
  mov al, [0x429]
  xchg byte ptr [0x42a], al
  mov [0x429], al
  jmp loc_070b
loc_07a9:
  mov byte ptr [0x427], 0xff
loc_07ae:
  sti
  ret
sub_0701 endp

sub_07b0 proc near
  mov cl, byte ptr [0x427]
  or cl, cl
  js loc_0802
  cmp byte ptr [0x41c], 0x0
  jnz loc_0802
  mov dx, 0x201
  in al, dx
  shr al, cl
  test al, 0x3
  jnz loc_0802
  xor al, 0x30
  shr al, 1
  shr al, 1
  shr al, 1
  shr al, 1
  xor bp, bp
  xor di, di
  xor bx, bx
  shr al, 1
  sbb byte ptr [0x42b], bh
  shr al, 1
  sbb byte ptr [0x42b], bh
  mov si, word ptr [0x41d]
  cli
  out dx, al
loc_07eb:
  in al, dx
  shr al, cl
  test al, 0x3
  jz loc_07fd
  shr al, 1
  adc di, bp
  shr al, 1
  adc bx, bp
  dec si
  jnz loc_07eb
loc_07fd:
  mov ax, di
  sti
  clc
  ret
loc_0802:
  sti
  stc
  ret
sub_07b0 endp

sub_0805 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  xor ax, ax
  mov [0x42d], al
  mov [0x42e], al
  mov [0x42f], al
  mov [0x430], al
  mov [0x42b], al
  mov [0x42c], al
  call sub_07b0
  jc loc_085c
  cmp ax, word ptr [0x41f]
  ja loc_0839
  mov byte ptr [0x430], 0xff
  jmp loc_0844
loc_0839:
  cmp ax, word ptr [0x425]
  jc loc_0844
  mov byte ptr [0x42f], 0xff
loc_0844:
  cmp bx, word ptr [0x421]
  ja loc_0851
  mov byte ptr [0x42d], 0xff
  jmp loc_085c
loc_0851:
  cmp bx, word ptr [0x423]
  jc loc_085c
  mov byte ptr [0x42e], 0xff
loc_085c:
  mov al, [0x488]
  or al, byte ptr [0x4bc]
  or al, byte ptr [0x469]
  or al, byte ptr [0x450]
  or byte ptr [0x42d], al
  mov al, [0x490]
  or al, byte ptr [0x4bb]
  or al, byte ptr [0x48a]
  or al, byte ptr [0x45e]
  or byte ptr [0x42e], al
  mov al, [0x48d]
  or al, byte ptr [0x4b9]
  or al, byte ptr [0x48e]
  or al, byte ptr [0x467]
  or byte ptr [0x42f], al
  mov al, [0x48b]
  or al, byte ptr [0x4ba]
  or al, byte ptr [0x46b]
  or al, byte ptr [0x466]
  or byte ptr [0x430], al
  mov al, [0x45c]
  or al, byte ptr [0x479]
  or al, byte ptr [0x4b4]
  or al, byte ptr [0x497]
  or byte ptr [0x42b], al
  mov al, [0x459]
  or al, byte ptr [0x484]
  or byte ptr [0x42c], al
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_0805 endp

sub_08d0 proc near
  mov ax, 0x3
  int 0x10
  mov ax, 0x168f
  mov ds, ax
  mov byte ptr cs:[0x6bb3], 0x0
  mov ah, 0x9
  mov dx, 0x61
  int 0x21
  jmp loc_096c
loc_08ea:
  mov ax, 0x168f
  mov ds, ax
  mov ax, 0x3
  int 0x10
  mov ah, 0x9
  mov dx, 0x77
  int 0x21
  jmp loc_096c
loc_08fd:
  mov ax, 0x3
  int 0x10
  mov ax, 0x168f
  mov ds, ax
  mov ah, 0x9
  mov dx, 0x8a
  int 0x21
  jmp loc_096c
loc_0910:
  push ax
  push bx
  push cx
  push dx
  push di
  mov ax, 0x3
  int 0x10
  mov di, dx
  push dx
  cmp byte ptr [0x417], 0x0
  jz loc_092d
  mov ah, 0x9
  mov dx, 0x9e
  int 0x21
  jmp loc_0934
loc_092d:
  mov ah, 0x9
  mov dx, 0xb1
  int 0x21
loc_0934:
  mov cx, 0x5a
  xor ax, ax
  repne scasb
  mov byte ptr [di], 0x24
  pop dx
  mov ah, 0x9
  int 0x21
  cmp byte ptr [0x417], 0x1
  jz loc_096c
  mov byte ptr [0x4c3], 0x0
  mov ah, 0x9
  mov dx, 0xd5
  int 0x21
  mov byte ptr [0x4c0], 0x0
loc_095b:
  mov al, [0x4c0]
  cmp al, 0x1c
  jnz loc_095b
  call sub_3160
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  jmp sub_097b
loc_096c:
  mov ah, 0x9
  mov dx, 0x109
  int 0x21
  mov byte ptr [0x4c3], 0x0
  sti
loc_0979:
  jmp loc_0979
sub_08d0 endp

sub_097b proc near
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov byte ptr cs:[0x6bb3], 0x1
  mov ax, 0x3d00
  int 0x21
  mov byte ptr cs:[0x6bb3], 0x0
  jnc loc_0998
  jmp loc_0910
loc_0998:
  mov cs:[0xaf2], ax
  mov ax, [0x4c1]
  mov cs:[0xaf4], ax
  mov ds, ax
  mov byte ptr cs:[0x6bb3], 0x1
  mov bx, word ptr cs:[0xaf2]
  mov cx, 0x6
  mov dx, 0x41a
  mov ah, 0x3f
  int 0x21
  jnc loc_09bf
  jmp loc_08fd
loc_09bf:
  dec byte ptr cs:[0x6bb3]
  mov si, dx
  lodsw
  cmp ah, 0x10
  jnz loc_09cf
  jmp loc_0af6
loc_09cf:
  mov bx, ax
  lodsw
  mov cx, 0x4
loc_09d5:
  shr bx, 1
  rcr ax, 1
  loop loc_09d5
  inc ax
  mov cx, word ptr [si]
  add ax, word ptr es:[0x4c1]
  mov es:[0x4c1], ax
  mov ds, ax
  mov ax, cs:[0xaf4]
  mov es, ax
  mov byte ptr cs:[0x6bb3], 0x1
  mov bx, word ptr cs:[0xaf2]
  mov cx, cx
  mov dx, 0x6
  mov ah, 0x3f
  int 0x21
  jnc loc_0a08
  jmp loc_08fd
loc_0a08:
  dec byte ptr cs:[0x6bb3]
  mov dl, 0x1
  mov word ptr [0x0], 0x2
  xor di, di
loc_0a17:
  xor bx, bx
  call sub_0abe
  or bh, bh
  jz loc_0a66
  cmp bl, 0x2
  jc loc_0a35
  mov cl, bl
  xor ch, ch
  mov bp, ax
  mov al, byte ptr es:[di-0x1]
  rep stosb
  mov ax, bp
  jmp loc_0a6a
loc_0a35:
  or bl, bl
  jnz loc_0a4c
  xor bx, bx
  call sub_0abe
  mov bp, ax
  mov cx, bx
  mov al, byte ptr es:[di-0x1]
  rep stosb
  mov ax, bp
  jmp loc_0a6a
loc_0a4c:
  xor bx, bx
  call sub_0abe
  mov ch, bl
  xor bx, bx
  call sub_0abe
  mov cl, bl
  mov bp, ax
  mov al, byte ptr es:[di-0x1]
  rep stosb
  mov ax, bp
  jmp loc_0a6a
loc_0a66:
  mov byte ptr es:[di], bl
  inc di
loc_0a6a:
  cmp di, 0x4000
  jc loc_0a17
  mov bx, es
  add bx, 0x3ff
  mov es, bx
  sub di, 0x3ff0
  jmp loc_0a6a
loc_0a7e:
  sub word ptr [0x0], 0x2
  jnz loc_0ab9
  push bx
  push di
  mov byte ptr cs:[0x6bb3], 0x1
  mov bx, word ptr cs:[0xaf2]
  mov cx, 0x1000
  mov dx, 0x41a
  mov ah, 0x3f
  int 0x21
  jnc loc_0aa1
  jmp loc_08fd
loc_0aa1:
  dec byte ptr cs:[0x6bb3]
  mov [0x0], ax
  or ax, ax
  pop di
  pop bx
  jz loc_0ad3
  shr ax, 1
  adc word ptr [0x0], 0x0
  mov si, 0x41a
loc_0ab9:
  lodsw
  xchg ah, al
  mov dl, 0x11
sub_097b endp ; sp-analysis failed

sub_0abe proc near
  dec dl
  jz loc_0a7e
  rol ax, 1
  jnc loc_0ac8
  inc bx
  inc bx
loc_0ac8:
  mov bx, word ptr [bx+0x6]
  or bh, bh
  jns sub_0abe
  and bh, 0x7f
  ret
loc_0ad3:
  pop ax
  mov byte ptr cs:[0x6bb3], 0x1
  mov bx, word ptr cs:[0xaf2]
  mov ah, 0x3e
  int 0x21
  dec byte ptr cs:[0x6bb3]
  mov ax, 0x168f
  mov ds, ax
  mov ax, cs:[0xaf4]
  ret
  db 00h
  db 00h
  db 00h
  db 00h
loc_0af6:
  xor dx, dx
  xor cx, cx
  mov ax, 0x4200
  mov byte ptr cs:[0x6bb3], 0x1
  int 0x21
  mov byte ptr cs:[0x6bb3], 0x0
  mov ax, 0x168f
  mov es, ax
  mov ax, cs:[0xaf4]
  mov ds, ax
  mov cx, 0x4
  mov dx, 0xe
  mov bx, word ptr cs:[0xaf2]
  mov ah, 0x3f
  mov byte ptr cs:[0x6bb3], 0x1
  int 0x21
  jnc loc_0b30
  jmp loc_08fd
loc_0b30:
  mov byte ptr cs:[0x6bb3], 0x0
  mov al, [0xf]
  and al, 0xf0
  cmp al, 0x10
  jz loc_0b42
  jmp loc_08ea
loc_0b42:
  xor di, di
  mov bx, word ptr [0xe]
  mov ax, [0x10]
  mov cx, 0x4
loc_0b4e:
  shr bx, 1
  rcr ax, 1
  loop loc_0b4e
  inc ax
  add ax, word ptr es:[0x4c1]
  mov es:[0x4c1], ax
  mov ds, ax
  mov ax, cs:[0xaf4]
  mov es, ax
  mov word ptr [0x0], di
  mov word ptr [0x2], di
loc_0b6e:
  call sub_0c1e
  call sub_0c30
  cmp ax, 0x101
  jz loc_0b8b
  mov [0x5], ax
  mov [0x4], al
  stosb
loc_0b80:
  call sub_0c30
  cmp ax, 0x100
  jz loc_0b6e
  cmp ax, 0x101
loc_0b8b:
  jz loc_0c02
  mov [0x7], ax
  mov si, 0x4010
  cmp word ptr [0xc], ax
  ja loc_0ba3
  mov dl, byte ptr [0x4]
  mov byte ptr [si], dl
  inc si
  mov ax, [0x5]
loc_0ba3:
  or ah, ah
  jz loc_0bb8
  mov bx, ax
  mov dl, byte ptr [bx+0x1010]
  mov byte ptr [si], dl
  inc si
  shl bx, 1
  mov ax, word ptr [bx+0x2010]
  jmp loc_0ba3
loc_0bb8:
  mov byte ptr [si], al
  inc si
  mov [0x4], al
loc_0bbe:
  dec si
  mov al, byte ptr [si]
  stosb
  cmp di, 0x8000
  jc loc_0bd3
  mov ax, es
  add ax, 0x800
  mov es, ax
  sub di, 0x8000
loc_0bd3:
  cmp si, 0x4010
  jnz loc_0bbe
  mov bx, word ptr [0xc]
  cmp bx, 0x1000
  jnc loc_0bf9
  mov dl, byte ptr [0x4]
  mov byte ptr [bx+0x1010], dl
  mov dx, word ptr [0x5]
  shl bx, 1
  mov word ptr [bx+0x2010], dx
  inc word ptr [0xc]
loc_0bf9:
  mov ax, [0x7]
  mov [0x5], ax
  jmp loc_0b80
loc_0c02:
  mov byte ptr [0x4c3], 0x1
  mov bx, word ptr cs:[0xaf2]
  mov ah, 0x3e
  int 0x21
  dec byte ptr [0x4c3]
  mov ax, 0x168f
  mov ds, ax
  mov ax, cs:[0xaf4]
  ret
sub_0abe endp

sub_0c1e proc near
  mov word ptr [0xa], 0x200
  mov byte ptr [0x9], 0x9
  mov word ptr [0xc], 0x102
  ret
sub_0c1e endp

sub_0c30 proc near
  mov ax, [0xc]
  cmp word ptr [0xa], ax
  jnz loc_0c48
  cmp byte ptr [0x9], 0xc
  jz loc_0c48
  inc byte ptr [0x9]
  shl word ptr [0xa], 1
loc_0c48:
  mov bx, word ptr [0x2]
  mov si, bx
  add bl, byte ptr [0x9]
  adc bh, 0x0
  cmp word ptr [0x0], bx
  jnc loc_0caf
  mov cx, 0x1000
  mov dx, 0x10
  mov bx, 0x10
  sub bx, word ptr [0x0]
  add bx, word ptr [0x2]
  mov word ptr [0x2], bx
  mov si, bx
  mov ax, [0x100e]
  mov [0xe], ax
  mov bx, word ptr cs:[0xaf2]
  mov ah, 0x3f
  mov byte ptr cs:[0x6bb3], 0x1
  int 0x21
  jnc loc_0c8c
  jmp loc_08fd
loc_0c8c:
  dec byte ptr cs:[0x6bb3]
  inc ax
  inc ax
  shl ax, 1
  shl ax, 1
  shl ax, 1
  mov [0x0], ax
  push di
  shr di, 1
  shr di, 1
  shr di, 1
  shr di, 1
  mov ax, es
  add ax, di
  mov es, ax
  pop di
  and di, 0xf
loc_0caf:
  mov cx, si
  shr si, 1
  shr si, 1
  shr si, 1
  and cl, 0x7
  mov ax, word ptr [si+0xe]
  xchg ah, al
  xor dh, dh
  shl ax, cl
  mov ch, 0x10
  sub ch, cl
  sub ch, byte ptr [0x9]
  jnc loc_0cd8
  neg ch
  mov cl, 0x8
  sub cl, ch
  mov dh, byte ptr [si+0x10]
  shr dh, cl
loc_0cd8:
  mov bl, byte ptr [0x9]
  xor bh, bh
  add word ptr [0x2], bx
  mov cl, 0x10
  sub cl, bl
  shr ax, cl
  or al, dh
  ret
sub_0c30 endp

sub_0ceb proc near
  push ax
  push cx
  push di
  push si
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  xor ax, ax
  mov es, ax
  mov si, 0x433
  mov di, 0x20
  mov cx, 0x4
  cli
  cld
loc_0d05:
  mov ax, word ptr es:[di]
  xchg word ptr [si], ax
  stosw
  inc si
  inc si
  loop loc_0d05
  push ds
  pop es
  mov di, 0x440
  xor ax, ax
  mov cx, 0x40
  rep stosw
  sti
  pop es
  pop ds
  pop si
  pop di
  pop cx
  pop ax
  ret
  db 00h
  db 00h
  db 00h
  db 00h
sub_0ceb endp ; sp-analysis failed

sub_0d27 proc near
  mov cs:[0xd23], ax
  mov word ptr cs:[0xd25], ds
  mov ax, 0x168f
  mov ds, ax
  add word ptr [0x43c], 0x1
  adc word ptr [0x43e], 0x0
  push word ptr [0x435]
  push word ptr [0x433]
  mov ds, word ptr cs:[0xd25]
  mov ax, cs:[0xd23]
  retf
sub_0d27 endp

sub_0d51 proc near
  push ds
  push bx
  push ax
  cld
  mov ax, 0x168f
  mov ds, ax
  in al, 0x60
  mov bl, al
  in al, 0x61
  mov ah, al
  or al, 0x80
  out 0x61, al
  mov al, ah
  out 0x61, al
  mov byte ptr [0x4c0], bl
  cmp bl, 0x1
  jnz loc_0d79
  cmp byte ptr cs:[0x6bb3], 0x0
loc_0d79:
  jnz loc_0df9
  mov ax, 0x3
  int 0x10
  mov si, 0x127
  mov cx, 0x1
  mov ah, 0xe
  mov bx, 0x3
loc_0d8b:
  lodsb
  or al, al
  jz loc_0d94
  int 0x10
  jmp loc_0d8b
loc_0d94:
  xor al, al
  out 0x40, al
  out 0x40, al
  mov dx, 0x40
loc_0d9d:
  in al, dx
  mov ah, al
  in al, dx
  xchg ah, al
  cmp ax, 0xf000
  jc loc_0d9d
loc_0da8:
  in al, dx
  mov ah, al
  in al, dx
  xchg ah, al
  cmp ax, 0x4000
  ja loc_0da8
  mov ax, 0x3
  int 0x10
  call sub_0ceb
  mov al, 0xa
  out 0x42, al
  xor al, al
  out 0x42, al
  in al, 0x61
  and al, 0xfc
  out 0x61, al
  mov ax, cs
  mov es, ax
  mov cx, 0xdc9
  xor di, di
  rep stosb
  mov di, 0xdf9
  mov dx, 0x15e
loc_0dda:
  mov cx, 0x400
  rep stosb
  sub di, 0x400
  add ax, 0x40
  mov es, ax
  dec dx
  jnz loc_0dda
  mov al, 0x20
  out 0x20, al
  mov ax, 0x4c00
  int 0x21
  jmpf lab_f000_fff0
loc_0df9:
  cmp bl, 0x3d
  jnz loc_0e1c
  xor byte ptr cs:[0x16e4], 0x2
  cmp byte ptr cs:[0x16e3], 0x1
  jz loc_0e1c
  in al, 0x61
  and al, 0xfc
  test byte ptr cs:[0x16e4], 0x2
  jz loc_0e1a
  or al, 0x3
loc_0e1a:
  out 0x61, al
loc_0e1c:
  and bl, 0x7f
  xor bh, bh
  mov al, [0x4c0]
  cbw
  not ah
  mov byte ptr [bx+0x440], ah
  mov al, 0x20
  out 0x20, al
  pop ax
  pop bx
  pop ds
  iret
sub_0d51 endp ; sp-analysis failed

sub_0e33 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cli
  xor ax, ax
  mov ds, ax
  mov al, 0xcf
  les di, [0xc]
  stosb
  mov word ptr [0x4], 0x1028
  mov word ptr [0x6], cs
  pushf
  pop ax
  or ah, 0x1
  push ax
  popf
  sti
  mov ax, 0x168f
  mov es, ax
  xor ax, ax
  mov ds, ax
  mov bx, 0x211
  mov ch, 0x0
loc_0e68:
  mov cl, 0x1
loc_0e6a:
  mov ax, 0x201
  xor dx, dx
  pushf
  callf [0x4c]
  cli
  mov ax, cs:[0xffc]
  or ax, word ptr cs:[0xffe]
  jnz loc_0e92
  inc cl
  cmp cl, 0xa
  jnz loc_0e6a
  inc ch
  cmp ch, 0x27
  jbe loc_0e68
  mov ah, 0x4c
  int 0x21
loc_0e92:
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov ah, 0x19
  int 0x21
  and al, 0x1
  mov [0x210], al
  call sub_0efe
  jnc loc_0ede
  call sub_0efe
  jnc loc_0ede
  xor byte ptr [0x210], 0x1
  call sub_0efe
  jnc loc_0ede
  call sub_0efe
  jnc loc_0ede
  mov ax, 0x3
  int 0x10
  mov dx, 0x1f9
  mov ah, 0x9
  int 0x21
  mov ah, 0xe
  mov al, [0x414]
  add al, 0x30
  int 0x10
  mov al, 0x2d
  int 0x10
  mov dx, word ptr [0x415]
  call sub_1004
  jmp loc_096c
loc_0ede:
  pushf
  cmp byte ptr [0x417], 0x1
  jz loc_0ef3
  mov ah, 0x19
  int 0x21
  cmp al, 0x3
  jc loc_0ef3
  mov byte ptr [0x417], 0x1
loc_0ef3:
  popf
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_0e33 endp

sub_0efe proc near
  mov dl, byte ptr [0x210]
  xor ah, ah
  int 0x13
  mov ax, 0x201
  mov bx, 0x211
  mov cx, 0x2
  mov dl, byte ptr [0x210]
  mov dh, 0x0
  mov byte ptr [0x411], 0x1
  call sub_0ffa
  jc loc_0f7c
  mov byte ptr [0x417], 0x0
  mov ax, 0x2701
  cmp byte ptr [bx], 0xf9
  jnz loc_0f34
  mov byte ptr [0x417], 0x1
  mov ax, 0x4f00
loc_0f34:
  mov byte ptr [0x20f], ah
  mov [0x20e], al
  mov byte ptr [0x411], 0x2
  mov cl, 0x1
loc_0f42:
  mov ax, 0x201
  mov bx, 0x211
  mov ch, byte ptr [0x20f]
  mov dh, byte ptr [0x20e]
  call sub_0ffa
  jc loc_0f7c
  inc cl
  cmp cl, 0xa
  jbe loc_0f42
  mov ax, 0x201
  mov cl, 0xf7
  mov dl, byte ptr [0x210]
  call sub_0ffa
  mov byte ptr [0x411], 0x3
  jnc loc_0f7c
  mov byte ptr [0x411], 0x4
  mov [0x412], ax
  cmp ah, 0x10
  jz loc_0f90
loc_0f7c:
  mov al, [0x411]
  cmp byte ptr [0x414], al
  jnc loc_0f8e
  mov [0x414], al
  mov ax, [0x412]
  mov [0x415], ax
loc_0f8e:
  stc
  ret
loc_0f90:
  mov byte ptr [0x411], 0x5
  cmp word ptr [0x211], 0x4f4d
  jnz loc_0f7c
  mov byte ptr [0x411], 0x6
  cmp word ptr [0x213], 0x544b
  jnz loc_0f7c
  mov byte ptr [0x411], 0x7
  mov di, 0x250
  xor bx, bx
loc_0fb4:
  inc bx
  cmp byte ptr [bx+di], 0x4e
  jz loc_0fb4
  mov word ptr [0x412], bx
  lea di, [bx+di+0xa]
  cmp bx, 0xa
  mov byte ptr [0x411], 0x8
  mov ah, byte ptr [di]
  xor bx, bx
loc_0fcd:
  inc bx
  cmp byte ptr [bx+di], ah
  jz loc_0fcd
  mov word ptr [0x412], bx
  add di, bx
  cmp bx, 0xf
  mov byte ptr [0x411], 0x9
  mov di, 0x410
  mov al, byte ptr [di]
  xor bx, bx
loc_0fe7:
  dec bx
  cmp byte ptr [bx+di], al
  jz loc_0fe7
  not bx
  mov word ptr [0x412], bx
  cmp bx, 0xa8
  jc loc_0f7c
  clc
  ret
sub_0efe endp

sub_0ffa proc near
  pushf
  callf sub_0000_0000
  mov [0x412], ax
  ret
sub_0ffa endp

sub_1004 proc near
  mov cx, 0x4
loc_1007:
  xor al, al
  shl dx, 1
  rcl al, 1
  shl dx, 1
  rcl al, 1
  shl dx, 1
  rcl al, 1
  shl dx, 1
  rcl al, 1
  cmp al, 0x9
  jbe loc_101f
  add al, 0x7
loc_101f:
  add al, 0x30
  mov ah, 0xe
  int 0x10
  loop loc_1007
  ret
sub_1004 endp

sub_1028 proc near
  efined2 4
  efined2 0
  push bp
  push ax
  mov bp, sp
  cmp word ptr cs:[0xffe], 0x0
  jnz loc_1075
  db 00h; mov ax, word ptr [bp+param_1+0x4]
  cmp ax, 0xc000
  jc loc_107a
  mov ax, word ptr [bp+local_res0+0x4]
  shr ax, 1
  shr ax, 1
  shr ax, 1
  shr ax, 1
  db 00h; add ax, word ptr [bp+param_1+0x4]
  cmp ax, 0xc000
  jc loc_107a
loc_104f:
  mov bp, sp
  db 00h; mov ds, word ptr [bp+param_1+0x4]
  mov bp, word ptr [bp+local_res0+0x4]
  cmp byte ptr ds:[bp+0x0], 0xfa
  jnz loc_1065
  mov bp, sp
  inc word ptr [bp+local_res0+0x4]
  jmp loc_104f
loc_1065:
  mov bp, sp
  db 00h; mov ax, word ptr [bp+param_1+0x4]
  mov cs:[0xffe], ax
  mov ax, word ptr [bp+local_res0+0x4]
  mov cs:[0xffc], ax
loc_1075:
  db 00h; and word ptr [bp+param_2+0x4], 0xfeff
loc_107a:
  pop ax
  pop bp
  iret
sub_1028 endp ; sp-analysis failed

sub_107d proc near
  cli
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  xor ax, ax
  mov es, ax
  push word ptr es:[0x18]
  push word ptr es:[0x1a]
  mov word ptr es:[0x18], 0x10bc
  mov word ptr es:[0x1a], cs
  mov al, 0x1
  mov cl, 0x20
  shl al, cl
  cmp al, 0x1
  jz loc_10b1
  mov byte ptr cs:[0x4], 0x0
  jmp loc_10c5
loc_10b1:
  xor ax, ax
  mov byte ptr cs:[0x4], 0x3
  jmp loc_10c5
  db 2eh
  db c6h
  db 06h
  db 04h
  db 00h
  db 02h
  db 83h
  db c4h
  db 06h
loc_10c5:
  pop word ptr es:[0x1a]
  pop word ptr es:[0x18]
  sti
  pop es
  pop ds
  ret
sub_107d endp

sub_10d3 proc near
  mov ax, 0x168f
  mov ds, ax
  mov byte ptr [0x651a], 0x0
loc_10dd:
  mov ax, [0x431]
  sub ax, word ptr cs:[0x16e0]
  jns loc_10e9
  neg ax
loc_10e9:
  cmp ax, 0x2
  jc loc_10dd
  ja loc_10f7
  call sub_3243
  inc byte ptr [0x651a]
loc_10f7:
  mov ax, cs:[0x16e0]
  mov [0x431], ax
  ret
sub_10d3 endp

sub_10ff proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov dx, 0x168f
  mov ds, dx
  mov es, dx
  mov bx, ax
  cmp byte ptr [bx+0x505], 0x1
  jz loc_111d
  mov [0x913], ax
  jmp loc_111d
loc_111d:
  or byte ptr cs:[0x16e4], 0x1
  cli
  cmp byte ptr cs:[0x16e3], 0x1
  jz loc_1157
  mov bx, ax
  mov al, byte ptr [bx+0x9a2]
  mov [0x980], al
  mov [0x981], al
  shl bx, 1
  mov ax, word ptr [bx+0x982]
  mov byte ptr cs:[0x70a2], 0x1
  mov [0xb07], ax
  test byte ptr cs:[0x16e4], 0x2
  jz loc_118d
  in al, 0x61
  or al, 0x3
  out 0x61, al
  jmp loc_118d
loc_1157:
  call sub_164f
  mov bx, 0x515
  mov cx, ax
  jcxz loc_116b
loc_1161:
  inc bx
  inc bx
  cmp word ptr [bx-0x2], -0x1
  jnz loc_1161
  loop loc_1161
loc_116b:
  mov cx, ax
  mov ax, bx
  mov bx, 0x675
  jcxz loc_117e
loc_1174:
  inc bx
  inc bx
  cmp word ptr [bx-0x2], -0x1
  jnz loc_1174
  loop loc_1174
loc_117e:
  mov si, bx
loc_1180:
  inc si
  inc si
  cmp word ptr [si], -0x1
  jnz loc_1180
  mov cx, word ptr [si-0x2]
  call sub_1269
loc_118d:
  sti
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_10ff endp

sub_1198 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr cs:[0x2], 0x0
  jz loc_11d2
  mov ax, 0x2001
  call sub_15a7
  call sub_1610
  jc loc_11d2
  cli
  mov ax, 0x8
  call sub_15a7
  mov ax, 0xbd
  call sub_15a7
  call sub_164f
  mov byte ptr cs:[0x16e3], 0x1
  sti
  jmp loc_11dc
loc_11d2:
  mov al, 0xb6
  out 0x43, al
  in al, 0x61
  or al, 0x3
  out 0x61, al
loc_11dc:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_1198 endp

sub_11e6 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov bx, 0x168f
  mov ds, bx
  mov word ptr [0x172], 0xf
  mov bl, al
  xor bh, bh
  shl bx, 1
  mov bx, word ptr [bx+0x156]
  mov byte ptr [0x174], 0x1
  cli
  mov dl, 0x13
  call sub_15de
  sub dl, 0x3
  add bx, 0x5
  call sub_15de
  mov ah, byte ptr [bx+0x5]
  mov al, 0xc6
  call sub_15a7
  sti
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_11e6 endp

sub_122b proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov ax, 0x20b6
  call sub_15a7
  cli
  mov bx, 0xb9a
  mov dl, 0x13
  call sub_15de
  sub dl, 0x3
  add bx, 0x5
  call sub_15de
  mov ah, byte ptr [bx+0x5]
  mov al, 0xc6
  call sub_15a7
  mov byte ptr [0x174], 0x0
  sti
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_122b endp

sub_1269 proc near
  push ax
  push cx
  push si
  push di
  mov byte ptr cs:[0x16e2], 0x0
  mov byte ptr [0x981], cl
  mov byte ptr [0x980], cl
  mov word ptr [0x917], bx
  mov di, 0x9b3
  mov si, ax
  xor ax, ax
  xor dx, dx
  mov byte ptr [0x9b2], 0xff
loc_128d:
  mov cx, 0x11
  rep stosb
  mov cx, word ptr [si]
  inc si
  inc si
  inc byte ptr [0x9b2]
  mov word ptr [di-0x4], cx
  mov byte ptr [di-0xc], dl
  inc dx
  cmp cx, -0x1
  jnz loc_128d
  pop di
  pop si
  pop cx
  pop ax
  ret
sub_1269 endp

sub_12ab proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cld
  mov ax, 0x168f
  mov ds, ax
  dec byte ptr [0x980]
  jnz loc_12c8
  mov al, [0x981]
  mov [0x980], al
  jmp loc_1331
loc_12c8:
  mov word ptr [0x915], 0x9b3
loc_12ce:
  mov di, word ptr [0x915]
  mov si, word ptr [di+0xd]
  cmp si, -0x1
  jz loc_1331
  cmp si, -0x2
  jz loc_1327
  sub byte ptr [di+0x7], 0x1
  ja loc_1327
loc_12e5:
  xor bh, bh
  lodsb
  test al, 0x80
  jz loc_12ef
  jmp loc_1454
loc_12ef:
  mov ah, al
  and ah, 0xf
  mov cl, ah
  xchg byte ptr [di+0x8], cl
  mov byte ptr [di+0xf], cl
  mov cl, 0x4
  shr al, cl
  mov byte ptr [di+0x9], al
  mov bl, byte ptr [di+0x8]
  xor bh, bh
  shl bx, 1
  mov ax, word ptr [bx+0x966]
  mov cl, byte ptr [di+0x9]
  call sub_13c2
  mov al, 0x60
  mov cl, byte ptr [di]
  cmp cl, 0x7
  jnz loc_1322
  mov al, 0x40
  mov cl, byte ptr [di+0x3]
loc_1322:
  shr al, cl
  mov byte ptr [di+0x7], al
loc_1327:
  mov word ptr [di+0xd], si
  add word ptr [0x915], 0x11
  jmp loc_12ce
loc_1331:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_12ab endp

sub_133b proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr [0x174], 0x0
  jz loc_1381
  mov al, 0xbd
  mov ah, 0xef
  and ah, byte ptr [0x919]
  call sub_15a7
  mov ax, 0x57a6
  call sub_15a7
  mov ax, 0x1b6
  call sub_15a7
  mov ax, 0x5b6
  call sub_15a7
  mov al, 0xbd
  mov ah, 0x10
  or ah, byte ptr [0x919]
  call sub_15a7
  dec word ptr [0x172]
  jnz loc_1381
  call sub_122b
loc_1381:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_133b endp

sub_138b proc near
  cmp byte ptr cs:[0x16e4], 0x3
  jnz loc_13a6
  cmp byte ptr cs:[0x16e3], 0x0
  jz loc_13a3
  call sub_133b
  call sub_12ab
  jmp loc_13a6
loc_13a3:
  call sub_16e5
loc_13a6:
  inc word ptr cs:[0x16e0]
  inc byte ptr cs:[0x16e2]
  and byte ptr cs:[0x16e2], 0x3
  jz loc_13bf
  push ax
  mov al, 0x20
  out 0x20, al
  pop ax
  iret
loc_13bf:
  jmp sub_0d27
sub_138b endp

sub_13c2 proc near
  or ax, ax
  jnz loc_13c9
  jmp loc_144d
loc_13c9:
  cmp byte ptr [di+0x6], 0xf
  jc loc_1417
  add cl, 0xf
  cmp byte ptr [di+0x6], cl
  jz loc_13e0
  call sub_14e9
  mov al, byte ptr [di+0x1]
  call sub_147d
loc_13e0:
  mov cl, byte ptr [di+0x5]
  sub cl, 0x6
  mov ah, 0x10
  shr ah, cl
  not ah
  and ah, byte ptr [0x919]
  mov al, 0xbd
  call sub_15a7
  cmp byte ptr [di+0x5], 0x6
  jnz loc_140d
  mov ax, 0x57a6
  call sub_15a7
  mov ax, 0xb6
  call sub_15a7
  mov ax, 0x5b6
  call sub_15a7
loc_140d:
  mov ah, byte ptr [0x919]
  mov al, 0xbd
  call sub_15a7
  ret
loc_1417:
  add cl, 0x2
  mov dx, ax
  mov ah, dl
  mov al, byte ptr [di+0x5]
  add al, 0xa0
  call sub_15a7
  cmp byte ptr [di+0x10], 0x1
  jz loc_143a
  mov al, byte ptr [di+0x5]
  add al, 0xb0
  mov ah, 0x0
  call sub_15a7
  or dx, dx
  jz loc_144d
loc_143a:
  mov ah, dh
  shl cl, 1
  shl cl, 1
  or ah, cl
  or ah, 0x20
  mov al, byte ptr [di+0x5]
  add al, 0xb0
  call sub_15a7
loc_144d:
  mov al, byte ptr [di+0x4]
  mov byte ptr [di+0x10], al
  ret
loc_1454:
  mov ah, al
  and al, 0xf
  mov cl, 0x4
  and ah, 0x70
  shr ah, cl
  cmp ah, 0x7
  jz loc_146f
  mov bl, ah
  shl bx, 1
  call word ptr [bx+0x91a]
  jmp loc_12e5
loc_146f:
  mov bl, al
  shl bx, 1
  call word ptr [bx+0x928]
  jmp loc_12e5
sub_13c2 endp

sub_147a proc near
  mov byte ptr [di], al
  ret
sub_147a endp

sub_147d proc near
  mov byte ptr [di+0x1], al
  inc al
  mov bl, byte ptr [di+0x6]
  mov cl, bl
  mov bh, 0x0
  shl bx, 1
  add bx, word ptr [0x917]
  mov bx, word ptr [bx]
  cmp cl, 0xf
  jc loc_1497
  inc bx
loc_1497:
  mov cl, al
  xor ch, ch
  mov ah, byte ptr [bx+0x2]
  and ah, 0x3f
  sub ah, 0x3f
  neg ah
  xor al, al
  shr ax, 1
  shr ax, 1
  shr ax, 1
  shr ax, 1
  mul cx
  mov al, 0x3f
  sub al, ah
  mov bl, byte ptr [di+0x5]
  mov bh, 0x0
  mov bl, byte ptr [bx+0x95b]
  cmp bl, 0xd
  ja loc_14c7
  add bl, 0x3
loc_14c7:
  mov bl, byte ptr [bx+0x948]
  mov ah, al
  mov al, bl
  add al, 0x40
  call sub_15a7
  ret
sub_147d endp

sub_14d5 proc near
  mov byte ptr [di+0x2], al
  ret
sub_14d5 endp

sub_14d9 proc near
  mov byte ptr [di+0x3], al
  ret
sub_14d9 endp

sub_14dd proc near
  mov byte ptr [di+0x4], al
  ret
sub_14dd endp

sub_14e1 proc near
  mov byte ptr [di+0x5], al
  ret
sub_14e1 endp

sub_14e5 proc near
  cmp al, 0x1
  jnz loc_1512
sub_14e5 endp ; sp-analysis failed

sub_14e9 proc near
  mov bl, byte ptr [di+0x9]
  xor bh, bh
  add bl, 0xf
  mov byte ptr [di+0x6], bl
  shl bx, 1
  add bx, word ptr [0x917]
  mov bx, word ptr [bx]
  mov cl, byte ptr [bx]
  mov byte ptr [di+0x5], cl
  mov ah, 0x10
  sub cl, 0x6
  shr ah, cl
  or ah, byte ptr [0x919]
  mov byte ptr [0x919], ah
  jmp loc_1534
loc_1512:
  jc loc_1516
  dec al
loc_1516:
  mov byte ptr [di+0x6], al
  mov cl, byte ptr [di+0x5]
  sub cl, 0x6
  jc loc_1534
  mov ah, 0x10
  shr ah, cl
  not ah
  and ah, byte ptr [0x919]
  mov byte ptr [0x919], ah
  mov al, 0xbd
  call sub_15a7
loc_1534:
  mov bl, byte ptr [di+0x5]
  xor bh, bh
  mov bl, byte ptr [bx+0x95b]
  cmp byte ptr [di+0x5], 0x6
  ja loc_1546
  add bl, 0x3
loc_1546:
  mov dl, byte ptr [bx+0x948]
  mov bl, byte ptr [di+0x6]
  xor bh, bh
  shl bx, 1
  add bx, word ptr [0x917]
  mov bx, word ptr [bx]
  cmp byte ptr [di+0x6], 0xf
  jc loc_155e
  inc bx
loc_155e:
  call sub_15de
  sub dl, 0x3
  add bx, 0x5
  cmp byte ptr [di+0x5], 0x7
  jnc loc_157b
  call sub_15de
  mov ah, byte ptr [bx+0x5]
  mov al, byte ptr [di+0x5]
  add al, 0xc0
  call sub_15a7
loc_157b:
  ret
sub_14e9 endp

sub_157c proc near
  lea ax, [si+0x2]
  mov word ptr [di+0xa], ax
  mov si, word ptr [si]
  ret
sub_157c endp

sub_1585 proc near
  mov si, word ptr [di+0xa]
  ret
sub_1585 endp

sub_1589 proc near
  mov si, word ptr [si]
  ret
sub_1589 endp

sub_158c proc near
  lodsb
  mov byte ptr [di+0xc], al
  ret
sub_158c endp

sub_1591 proc near
  dec byte ptr [di+0xc]
  jz loc_1599
  mov si, word ptr [si]
  ret
loc_1599:
  inc si
  inc si
  ret
sub_1591 endp

sub_159c proc near
  pop ax
  mov si, 0xfffe
  dec byte ptr [0x9b2]
  jmp loc_1327
sub_159c endp

sub_15a7 proc near
  push dx
  push ax
  push cx
  cmp byte ptr cs:[0x4], 0x3
  jnc loc_15c8
  mov dx, 0x388
  out dx, al
  mov cx, 0x5
loc_15b9:
  loop loc_15b9
  inc dx
  mov al, ah
  out dx, al
  mov cx, 0x23
loc_15c2:
  loop loc_15c2
  pop cx
  pop ax
  pop dx
  ret
loc_15c8:
  mov dx, 0x388
  out dx, al
  mov cx, 0x14
loc_15cf:
  loop loc_15cf
  inc dx
  mov al, ah
  out dx, al
  mov cx, 0x8c
loc_15d8:
  loop loc_15d8
  pop cx
  pop ax
  pop dx
  ret
sub_15a7 endp

sub_15de proc near
  mov ah, byte ptr [bx]
  mov al, dl
  add al, 0x60
  call sub_15a7
  mov ah, byte ptr [bx+0x1]
  mov al, dl
  add al, 0x80
  call sub_15a7
  mov ah, byte ptr [bx+0x2]
  mov al, dl
  add al, 0x40
  call sub_15a7
  mov ah, byte ptr [bx+0x3]
  mov al, dl
  add al, 0x20
  call sub_15a7
  mov ah, byte ptr [bx+0x4]
  mov al, dl
  add al, 0xe0
  call sub_15a7
  ret
sub_15de endp

sub_1610 proc near
  mov ax, 0x6304
  call sub_15a7
  mov dx, 0x388
  mov cx, 0x2000
loc_161c:
  in al, dx
  and al, 0x60
  jnz loc_164d
  loop loc_161c
  mov ax, 0x2304
  call sub_15a7
  mov cx, 0x9fff
loc_162c:
  in al, dx
  and al, 0x60
  cmp al, 0x40
  jz loc_1637
  loop loc_162c
  jmp loc_164d
loc_1637:
  mov ax, 0x4304
  call sub_15a7
  mov cx, 0x9fff
loc_1640:
  in al, dx
  and al, 0x60
  cmp al, 0x20
  jz loc_164b
  loop loc_1640
  jmp loc_164d
loc_164b:
  clc
  ret
loc_164d:
  stc
  ret
sub_1610 endp

sub_164f proc near
  push ax
  mov ax, 0xb0
loc_1653:
  call sub_15a7
  inc ax
  cmp al, 0xb9
  jc loc_1653
  mov ax, 0xa0
loc_165e:
  call sub_15a7
  inc ax
  cmp al, 0xb9
  jc loc_165e
  mov ax, 0x8
  call sub_15a7
  mov ax, 0xbd
  call sub_15a7
  mov ax, 0x3f40
  call sub_15a7
  mov ax, 0x3f41
  call sub_15a7
  mov ax, 0x3f42
  call sub_15a7
  mov ax, 0x3f43
  call sub_15a7
  mov ax, 0x3f44
  call sub_15a7
  mov ax, 0x3f45
  call sub_15a7
  mov ax, 0x3f48
  call sub_15a7
  mov ax, 0x3f49
  call sub_15a7
  mov ax, 0x3f4a
  call sub_15a7
  mov ax, 0x3f4b
  call sub_15a7
  mov ax, 0x3f4c
  call sub_15a7
  mov ax, 0x3f4d
  call sub_15a7
  mov ax, 0x3f50
  call sub_15a7
  mov ax, 0x3f51
  call sub_15a7
  mov ax, 0x3f52
  call sub_15a7
  mov ax, 0x3f53
  call sub_15a7
  mov ax, 0x3f54
  call sub_15a7
  mov ax, 0x3f55
  call sub_15a7
  pop ax
  ret
  db 00h
  db 00h
  db 00h
  db 00h
  db 02h
sub_164f endp ; sp-analysis failed

sub_16e5 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cld
  mov ax, 0x168f
  mov ds, ax
  mov si, word ptr [0xb07]
  cmp si, -0x2
  jc loc_1700
  jmp loc_1783
loc_1700:
  test byte ptr cs:[0x16e4], 0x2
  jz loc_1783
  dec byte ptr [0x980]
  jnz loc_1716
  mov al, [0x981]
  mov [0x980], al
  jmp loc_1783
loc_1716:
  cmp byte ptr [0xb09], 0x2
  jnz loc_172f
  cmp byte ptr [0xb13], 0x1
  jz loc_172f
  mov ax, 0x3a98
  out 0x42, al
  mov al, ah
  out 0x42, al
  jmp loc_172f
loc_172f:
  sub byte ptr [0xb09], 0x1
  ja loc_1783
loc_1736:
  xor bh, bh
  lodsb
  test al, 0x80
  jnz loc_1791
  mov ah, al
  and ah, 0xf
  mov byte ptr [0xb0e], ah
  mov cl, 0x4
  shr al, cl
  mov [0xb0d], al
  mov al, 0x10
  mov cl, byte ptr [0xb0f]
  shr al, cl
  mov bl, byte ptr [0xb0e]
  xor bh, bh
  shl bx, 1
  mov ax, word ptr [bx+0xb20]
  mov cl, byte ptr [0xb0d]
  shr ax, cl
  out 0x42, al
  mov al, ah
  out 0x42, al
  mov al, 0x60
  mov cl, byte ptr [0xb0f]
  cmp cl, 0x7
  jnz loc_177e
  mov al, 0x40
  mov cl, byte ptr [0xb12]
loc_177e:
  shr al, cl
  mov [0xb09], al
loc_1783:
  mov word ptr [0xb07], si
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
loc_1791:
  mov ah, al
  and al, 0xf
  mov cl, 0x4
  and ah, 0x70
  shr ah, cl
  cmp ah, 0x7
  jz loc_17a9
  mov bl, ah
  mov byte ptr [bx+0xb0f], al
  jmp loc_1736
loc_17a9:
  cmp al, 0xf
  jz loc_17b8
  mov bl, al
  shl bx, 1
  call word ptr [bx+0xb16]
  jmp loc_1736
loc_17b8:
  in al, 0x61
  and al, 0xfc
  out 0x61, al
  mov si, 0xfffe
  dec byte ptr [0x9b2]
  jmp loc_1783
sub_16e5 endp

sub_17c7 proc near
  lea ax, [si+0x2]
  mov [0xb0a], ax
  mov si, word ptr [si]
  ret
sub_17c7 endp

sub_17d0 proc near
  mov si, word ptr [0xb0a]
  ret
sub_17d0 endp

sub_17d5 proc near
  mov si, word ptr [si]
  ret
sub_17d5 endp

sub_17d8 proc near
  mov al, byte ptr [si]
  mov [0xb0c], al
  inc si
  ret
sub_17d8 endp

sub_17df proc near
  dec byte ptr [0xb0c]
  jz loc_17e8
  mov si, word ptr [si]
  ret
loc_17e8:
  inc si
  inc si
  ret
sub_17df endp

sub_17eb proc near
  mov al, cs:[0x16e4]
  and al, 0x3
  cmp al, 0x3
  jnz loc_17fc
  cmp byte ptr [0x9b2], 0x0
  jnz sub_17eb
loc_17fc:
  ret
  db 00h
sub_17eb endp ; sp-analysis failed

sub_17fe proc near
  mov ax, 0x168f
  mov ds, ax
  mov ah, 0x4
  int 0x1a
  jc loc_183d
  push dx
  xor ax, ax
  mov bl, 0x4
  mov bp, 0xa
loc_1811:
  mul bp
  shl cx, 1
  rcl dh, 1
  shl cx, 1
  rcl dh, 1
  shl cx, 1
  rcl dh, 1
  shl cx, 1
  rcl dh, 1
  add al, dh
  dec bl
  jnz loc_1811
  pop dx
  cmp ax, 0x813
  jnc loc_183d
  cmp ax, 0x7c8
  jnz loc_183a
  cmp dh, 0x6
  jnc loc_183a
  dec ax
loc_183a:
  mov [0xa], ax
loc_183d:
  ret
loc_183e:
  ret
sub_17fe endp

sub_183f proc near
  mov ax, 0x168f
  mov ds, ax
  cmp word ptr [0xa], 0x7cc
  jc loc_183e
  call sub_27df
  call sub_038a
  mov word ptr [0x1f5], 0x5
  mov word ptr [0x1f7], 0x960
  mov si, 0x4e6e
  call sub_0488
  mov word ptr [0x1f5], 0x0
  add word ptr [0x1f7], 0x1e0
  mov si, 0x4e7a
  call sub_0488
  mov dx, word ptr [0xa]
  call sub_0423
  mov si, 0x4e9a
  call sub_0488
  mov word ptr [0x1f5], 0x1
  mov word ptr [0x1f7], 0x1680
  mov si, 0x4e9e
  call sub_0488
  mov word ptr [0x1f5], 0x3
  add word ptr [0x1f7], 0x1e0
  mov si, 0x4ec3
  call sub_0488
  call sub_03f2
  call sub_27df
  ret
loc_18ae:
  ret
sub_183f endp

sub_18af proc near
  mov al, [0x45d]
  and al, byte ptr [0x478]
  mov ah, al
  and ah, byte ptr [0x451]
  jnz loc_18c4
  and al, byte ptr [0x450]
  jz loc_18ae
loc_18c4:
  mov bx, 0x1
  xor al, al
loc_18c9:
  cmp bl, 0x10
  jz loc_18e3
  cmp bl, 0x11
  jz loc_18e3
  cmp bl, 0x1d
  jz loc_18e3
  cmp bl, 0x38
  jz loc_18e3
  or al, byte ptr [bx+0x440]
  jnz loc_18ae
loc_18e3:
  inc bx
  cmp bl, 0x7f
  jc loc_18c9
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cmp byte ptr [0x450], 0x0
  jz loc_1909
  cmp byte ptr [0x41a], 0xa
  jc loc_1909
  inc byte ptr [0x41b]
  sub byte ptr [0x41a], 0xa
loc_1909:
  call sub_1958
  call sub_03f2
  call sub_03ae
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_18af endp

sub_191c proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  call sub_3160
  call sub_1958
  mov word ptr [0x43c], 0x0
loc_1936:
  call sub_0805
  cmp byte ptr [0x42b], 0x0
  jnz loc_1948
  cmp word ptr [0x43c], 0x168
  jc loc_1936
loc_1948:
  mov word ptr [0x43c], 0x870
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_191c endp

sub_1958 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov ax, 0x9
  call sub_10ff
  call sub_2811
  call sub_038a
  mov word ptr [0x1f5], 0x5
  mov word ptr [0x1f7], 0x3c0
  mov si, 0x4ee3
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f02
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f21
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f40
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f5f
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f7e
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4f9d
  call sub_0488
  add word ptr [0x1f7], 0x1e0
  sub word ptr [0x1f5], 0x1e
  mov si, 0x4fbc
  call sub_0488
  mov word ptr [0x1f5], 0xf
  mov word ptr [0x1f7], 0x1770
  mov si, 0x4fdb
  call sub_0488
  mov word ptr [0x1f5], 0x0
  mov word ptr [0x1f7], 0x1a40
  mov si, 0x4fe5
  call sub_0488
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
loc_1a29:
  ret
sub_1958 endp

sub_1a2a proc near
  mov al, [0x45d]
  and al, byte ptr [0x478]
  and al, byte ptr [0x452]
  jz loc_1a29
  mov bx, 0x1
  xor al, al
loc_1a3c:
  cmp bl, 0x12
  jz loc_1a51
  cmp bl, 0x1d
  jz loc_1a51
  cmp bl, 0x38
  jz loc_1a51
  or al, byte ptr [bx+0x440]
  jnz loc_1a29
loc_1a51:
  inc bx
  cmp bl, 0x7f
  jc loc_1a3c
  jmp loc_1a61
sub_1a2a endp

sub_1a59 proc near
  cmp word ptr [0xa], 0x7c8
  jc loc_1a29
loc_1a61:
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov dx, 0x500e
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x4e52], ax
  call sub_1a8d
  mov ax, 0x9
  call sub_10ff
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_1a59 endp

sub_1a8d proc near
  call sub_3160
  cmp byte ptr cs:[0x1], 0x5
  jnz loc_1ae4
  mov ax, 0xd
  int 0x10
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov dx, 0x4e54
  mov ax, 0x1002
  int 0x10
  mov dx, 0x3c8
  xor al, al
  out dx, al
  inc dx
  mov cx, 0x10
  xor al, al
loc_1ab8:
  out dx, al
  jmp loc_1abb
loc_1abb:
  out dx, al
  jmp loc_1abe
loc_1abe:
  out dx, al
  add al, 0x4
  loop loc_1ab8
  mov ax, 0xa000
  mov es, ax
  mov ds, word ptr [0x4e52]
  xor si, si
  mov dx, 0x3c4
  mov ax, 0x102
loc_1ad4:
  out dx, ax
  mov cx, 0xfa0
  xor di, di
  rep movsw
  shl ah, 1
  cmp ah, 0x8
  jbe loc_1ad4
  ret
loc_1ae4:
  cmp byte ptr cs:[0x1], 0x0
  jz loc_1af1
  mov ax, 0x6
  int 0x10
loc_1af1:
  mov ax, 0xb800
  mov es, ax
  xor ax, ax
  xor di, di
  mov cx, 0x3e80
  rep stosw
  mov byte ptr [0x4e6a], 0x0
  mov word ptr [0x4e68], 0x0
  mov byte ptr [0x4e6d], 0x0
  mov word ptr [0x4e6b], 0x0
  xor bx, bx
loc_1b17:
  call sub_1bb6
  push ax
  add bx, ax
  cmp bx, 0x10
  jl loc_1b30
  call sub_1b83
  call sub_1c09
  and ax, 0x1
  sub bx, 0x10
  add bx, ax
loc_1b30:
  inc word ptr [0x4e68]
  pop ax
  add bx, ax
  cmp bx, 0x10
  jl loc_1b4a
  call sub_1b83
  call sub_1c09
  and ax, 0x1
  sub bx, 0x10
  add bx, ax
loc_1b4a:
  inc word ptr [0x4e68]
  cmp word ptr [0x4e68], 0x280
  jc loc_1b67
  mov word ptr [0x4e68], 0x0
  inc byte ptr [0x4e6a]
  cmp byte ptr [0x4e6a], 0xc8
  jnc loc_1b82
loc_1b67:
  cmp word ptr [0x4e6b], 0x140
  jc loc_1b80
  mov word ptr [0x4e6b], 0x0
  inc byte ptr [0x4e6d]
  cmp byte ptr [0x4e6d], 0xc8
  jnc loc_1b82
loc_1b80:
  jmp loc_1b17
loc_1b82:
  ret
sub_1a8d endp

sub_1b83 proc near
  push ax
  push cx
  push di
  mov al, [0x4e6a]
  shr al, 1
  mov ah, 0x50
  mul ah
  test byte ptr [0x4e6a], 0x1
  jz loc_1b99
  add ax, 0x2000
loc_1b99:
  mov di, ax
  mov ax, [0x4e68]
  mov cl, 0x3
  shr ax, cl
  add di, ax
  mov cl, byte ptr [0x4e68]
  and cl, 0x7
  mov ah, 0x80
  shr ah, cl
  or byte ptr es:[di], ah
  pop di
  pop cx
  pop ax
  ret
sub_1b83 endp

sub_1bb6 proc near
  push cx
  push di
  mov al, [0x4e6d]
  mov ah, 0x28
  mul ah
  xor di, di
  and di, 0xfff0
  add di, ax
  mov ax, [0x4e6b]
  mov cl, 0x3
  shr ax, cl
  add di, ax
  mov cl, byte ptr [0x4e6b]
  and cl, 0x7
  mov ah, 0x80
  shr ah, cl
  xor al, al
  push ds
  mov ds, word ptr [0x4e52]
  test byte ptr [di], ah
  jz loc_1be7
  inc al
loc_1be7:
  test byte ptr [di+0x1f40], ah
  jz loc_1bef
  add al, 0x2
loc_1bef:
  test byte ptr [di+0x3e80], ah
  jz loc_1bf7
  add al, 0x4
loc_1bf7:
  test byte ptr [di+0x5dc0], ah
  jz loc_1bff
  add al, 0x8
loc_1bff:
  pop ds
  xor ah, ah
  inc word ptr [0x4e6b]
  pop di
  pop cx
  ret
sub_1bb6 endp

sub_1c09 proc near
  mov ax, [0x4e65]
  add ax, 0x9248
  ror ax, 1
  ror ax, 1
  ror ax, 1
  mov [0x4e65], ax
  ret
  db 00h
sub_1c09 endp ; sp-analysis failed

sub_1c1a proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_1c2f
  push dx
  push ax
  mov dx, 0x3da
  in al, dx
  mov dl, 0xc0
  mov al, 0x20
  out dx, al
  pop ax
  pop dx
loc_1c2f:
  ret
sub_1c1a endp

sub_1c30 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_1c45
  push dx
  push ax
  mov dx, 0x3da
  in al, dx
  mov dl, 0xc0
  xor al, al
  out dx, al
  pop ax
  pop dx
loc_1c45:
  ret
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
sub_1c30 endp ; sp-analysis failed

sub_1c61 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov si, 0x567e
loc_1c72:
  mov word ptr [0x527a], si
  cmp word ptr [si+0x4], -0x1
  jnz loc_1c7f
  jmp loc_24a9
loc_1c7f:
  xor ax, ax
  mov cs:[0x1c49], al
  mov cs:[0x1c53], al
  mov cs:[0x1c56], al
  mov cs:[0x1c57], al
  mov cs:[0x1c46], ax
  and byte ptr [si+0x5], 0xdf
  mov bx, word ptr [si+0x4]
  shl bx, 1
  rcl byte ptr cs:[0x1c48], 1
  mov al, 0x1
  test bh, 0x80
  jz loc_1caf
  mov al, 0x41
  and bh, 0x7f
loc_1caf:
  mov cs:[0x1c5e], al
  mov dx, word ptr [bx+0x6665]
  mov al, byte ptr [bx+0x692f]
  test byte ptr cs:[0x1c48], 0x1
  jz loc_1cc9
  sub al, byte ptr [bx+0x6665]
  neg al
loc_1cc9:
  cbw
  neg ax
  add ax, word ptr [si]
  mov cx, word ptr [0x5270]
  shl cx, 1
  shl cx, 1
  shl cx, 1
  shl cx, 1
  sub ax, cx
  mov cx, ax
  mov cs:[0x1c50], ax
  cmp ax, 0x140
  jl loc_1cea
  jmp loc_24a9
loc_1cea:
  add cl, dl
  adc ch, 0x0
  jns loc_1cf4
  jmp loc_24a9
loc_1cf4:
  mov al, byte ptr [bx+0x6930]
  cbw
  add ax, word ptr [si+0x2]
  inc ax
  mov cx, word ptr [0x5272]
  shl cx, 1
  shl cx, 1
  shl cx, 1
  shl cx, 1
  sub ax, cx
  jg loc_1d10
  jmp loc_24a9
loc_1d10:
  mov [0x5278], ax
  mov byte ptr cs:[0x1c52], dh
  mov byte ptr cs:[0x1c4c], dh
  sub al, dh
  sbb ah, 0x0
  cmp ax, 0xc0
  jl loc_1d2a
  jmp loc_24a9
loc_1d2a:
  mov cs:[0x1c4e], ax
  mov cl, byte ptr cs:[0x0]
  shr dl, cl
  mov byte ptr cs:[0x1c4a], dl
  mov byte ptr cs:[0x1c4b], dl
  xor dh, dh
  xor cx, cx
  or ax, ax
  jns loc_1d5a
  neg ax
  sub byte ptr cs:[0x1c52], al
  mul dl
  mov cx, ax
  mov cs:[0x1c46], ax
  xor di, di
  jmp loc_1d60
loc_1d5a:
  mul byte ptr [0x525c]
  mov di, ax
loc_1d60:
  add di, word ptr [0x526a]
  mov word ptr cs:[0x1c58], di
  mov ax, word ptr [bx+0x5dc4]
  mov cs:[0x1c5c], ax
  mov ax, word ptr [bx+0x5aa4]
  add ax, cx
  mov cs:[0x1c5a], ax
  mov ax, [0x5278]
  sub ax, 0xc0
  jle loc_1d8f
  sub byte ptr cs:[0x1c52], al
  mul dl
  add word ptr cs:[0x1c46], ax
loc_1d8f:
  mov ax, cs:[0x1c50]
  or ax, ax
  jns loc_1db0
  mov cl, byte ptr cs:[0x0]
  sar ax, cl
  add byte ptr cs:[0x1c4a], al
  neg al
  mov cs:[0x1c53], al
  inc byte ptr cs:[0x1c49]
  jmp loc_1de8
loc_1db0:
  mov cl, byte ptr cs:[0x0]
  sar ax, cl
  add word ptr cs:[0x1c58], ax
  mov ax, cs:[0x1c50]
  mov cl, byte ptr cs:[0x0]
  shr ax, cl
  add al, byte ptr cs:[0x1c4a]
  adc ah, 0x0
  sub ax, word ptr [0x525c]
  jc loc_1de8
  sub byte ptr cs:[0x1c4a], al
  inc byte ptr cs:[0x1c49]
  mov cs:[0x1c56], al
  not byte ptr cs:[0x1c57]
loc_1de8:
  or byte ptr [si+0x5], 0x20
  cmp byte ptr cs:[0x1], 0x3
  jc loc_1df7
  jmp loc_203a
loc_1df7:
  cmp byte ptr cs:[0x1c5e], 0x1
  jz loc_1e02
  jmp loc_24a9
loc_1e02:
  mov al, cs:[0x1c4b]
  mul byte ptr cs:[0x1c4c]
  mov cs:[0x1c5f], ax
  mov es, word ptr [0x5262]
  mov di, word ptr cs:[0x1c58]
  mov ds, word ptr cs:[0x1c5c]
  mov bx, word ptr cs:[0x1c5f]
  mov si, word ptr cs:[0x1c5a]
  mov dl, byte ptr cs:[0x1c52]
  cmp byte ptr cs:[0x1c49], 0x0
  jnz loc_1ea3
  test word ptr cs:[0x1c50], 0x3
  jnz loc_1ea3
  mov dh, byte ptr cs:[0x1c4a]
  xor ch, ch
  mov cl, dh
  test byte ptr cs:[0x1c48], 0x1
  jnz loc_1e6c
  mov bp, 0x50
  sub bp, cx
loc_1e53:
  shr cx, 1
loc_1e55:
  mov ax, word ptr es:[di]
  and ax, word ptr [bx+si]
  or ax, word ptr [si]
  stosw
  inc si
  inc si
  loop loc_1e55
  mov cl, dh
  add di, bp
  dec dl
  jnz loc_1e53
  jmp loc_24a9
loc_1e6c:
  mov bp, bx
  mov bx, 0x330e
  add di, cx
  dec di
loc_1e74:
  shr cx, 1
loc_1e76:
  mov ax, word ptr ds:[bp+si]
  xlat cs
  and byte ptr es:[di], al
  lodsb
  xlat cs
  or byte ptr es:[di], al
  dec di
  mov al, ah
  xlat cs
  and byte ptr es:[di], al
  lodsb
  xlat cs
  or byte ptr es:[di], al
  dec di
  loop loc_1e76
  mov cl, dh
  add di, cx
  add di, 0x50
  dec dl
  jnz loc_1e74
loc_1ea0:
  jmp loc_24a9
loc_1ea3:
  cmp byte ptr cs:[0x1c4a], 0x0
  jz loc_1ea0
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x3
  shl cl, 1
  mov ch, 0xff
  shl ch, cl
  test byte ptr cs:[0x1c48], 0x1
  jnz loc_1f3e
loc_1ec1:
  mov al, cs:[0x1c4a]
  cbw
  mov bp, ax
  mov al, cs:[0x1c53]
  cbw
  add si, ax
  not ch
  mov dx, 0xff00
  and dh, ch
  or ax, ax
  jz loc_1ee4
  mov dh, byte ptr [bx+si-0x1]
  and dh, ch
  mov dl, byte ptr [si-0x1]
  and dl, ch
loc_1ee4:
  not ch
loc_1ee6:
  mov al, byte ptr [bx+si]
  mov ah, al
  and al, ch
  or al, dh
  ror al, cl
  and byte ptr es:[di], al
  lodsb
  mov dh, al
  and al, ch
  or al, dl
  ror al, cl
  or byte ptr es:[di], al
  not ch
  mov dl, dh
  mov dh, ah
  and dl, ch
  and dh, ch
  not ch
  inc di
  dec bp
  jnz loc_1ee6
  cmp byte ptr cs:[0x1c57], 0x0
  jnz loc_1f23
  or dh, ch
  ror dh, cl
  ror dl, cl
  and byte ptr es:[di], dh
  or byte ptr es:[di], dl
loc_1f23:
  mov al, cs:[0x1c4a]
  cbw
  sub di, ax
  add di, 0x50
  mov al, cs:[0x1c56]
  cbw
  add si, ax
  dec byte ptr cs:[0x1c52]
  jnz loc_1ec1
  jmp loc_24a9
loc_1f3e:
  mov al, cs:[0x1c53]
  mov cs:[0x1c54], al
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x3
  sub cl, 0x4
  neg cl
  and cl, 0x3
  shl cl, 1
  mov ch, 0xff
  shr ch, cl
  mov bp, bx
  mov bx, 0x330e
  cmp byte ptr cs:[0x1c53], 0x0
  jz loc_1f7d
  dec di
  test word ptr cs:[0x1c50], 0x3
  jz loc_1f7d
  dec byte ptr cs:[0x1c53]
  inc byte ptr cs:[0x1c4a]
loc_1f7d:
  cmp byte ptr cs:[0x1c57], 0x0
  jz loc_1f9a
  dec di
  test word ptr cs:[0x1c50], 0x3
  jz loc_1f9a
  inc di
  dec byte ptr cs:[0x1c4a]
  inc byte ptr cs:[0x1c56]
loc_1f9a:
  mov al, cs:[0x1c4a]
  cbw
  add di, ax
loc_1fa1:
  mov al, cs:[0x1c4a]
  mov cs:[0x1c4d], al
  not ch
  mov dx, 0xff00
  and dh, ch
  not ch
  cmp byte ptr cs:[0x1c57], 0x0
  jz loc_1fd7
  mov al, cs:[0x1c56]
  cbw
  add si, ax
  mov al, byte ptr ds:[bp+si-0x1]
  xlat cs
  mov dh, al
  mov al, byte ptr [si-0x1]
  xlat cs
  mov dl, al
  inc byte ptr cs:[0x1c4d]
  jmp loc_1ffa
loc_1fd7:
  mov al, byte ptr ds:[bp+si]
  xlat cs
  mov ah, al
  and al, ch
  or al, dh
  rol al, cl
  and byte ptr es:[di], al
  lodsb
  xlat cs
  mov dh, al
  and al, ch
  or al, dl
  rol al, cl
  or byte ptr es:[di], al
  dec di
  mov dl, dh
  mov dh, ah
loc_1ffa:
  not ch
  and dl, ch
  and dh, ch
  not ch
  dec byte ptr cs:[0x1c4d]
  jnz loc_1fd7
  cmp byte ptr cs:[0x1c54], 0x0
  jnz loc_201d
  or dh, ch
  rol dh, cl
  rol dl, cl
  and byte ptr es:[di], dh
  or byte ptr es:[di], dl
loc_201d:
  mov al, cs:[0x1c4a]
  cbw
  add di, ax
  add di, 0x50
  mov al, cs:[0x1c53]
  add si, ax
  dec byte ptr cs:[0x1c52]
  jz loc_2037
  jmp loc_1fa1
loc_2037:
  jmp loc_24a9
loc_203a:
  call sub_32dc
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x7
  mov ch, 0xff
  shl ch, cl
  mov di, word ptr cs:[0x1c58]
  mov si, word ptr cs:[0x1c5a]
  mov dl, 0xce
  mov al, 0x3
  mov ah, cl
  or ah, 0x8
  out dx, ax
  mov bh, ch
  not bh
  mov dh, byte ptr cs:[0x1c4a]
  mov cl, dh
  mov al, cl
  cbw
  sub ax, 0x28
  mov bp, ax
  mov dl, byte ptr cs:[0x1c52]
  mov ds, word ptr cs:[0x1c5c]
  mov ax, 0xa000
  mov es, ax
  test byte ptr cs:[0x1c48], 0x1
  jnz loc_2091
  jmp loc_22e9
loc_2091:
  mov byte ptr cs:[0x1c4c], dl
  mov dx, bx
  mov bx, 0x340e
  std
  dec si
  cmp byte ptr cs:[0x1c49], 0x0
  jz loc_20a8
  jmp loc_21ef
loc_20a8:
  mov al, cl
  cbw
  add si, ax
  cmp ch, 0xff
  jz loc_20b5
  jmp loc_213c
loc_20b5:
  xor ch, ch
loc_20b7:
  lodsb
  xlat cs
  not al
  xchg byte ptr es:[di], al
  inc di
  loop loc_20b7
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cl
  cbw
  add si, ax
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_20b7
  push dx
  mov dx, 0x3ce
  mov ax, 0x1003
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
  not byte ptr cs:[0x1c57]
  pop dx
loc_20ee:
  push dx
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov cl, byte ptr cs:[0x1c4a]
  mov dl, byte ptr cs:[0x1c52]
  mov byte ptr cs:[0x1c4c], dl
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
  pop dx
loc_2111:
  lodsb
  xlat cs
  xchg byte ptr es:[di], al
  inc di
  loop loc_2111
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cl
  cbw
  add si, ax
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_2111
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jc loc_20ee
  jmp loc_24a9
loc_213c:
  lodsb
  xlat cs
  mov dl, al
  and al, ch
  or al, ah
  not al
  xchg byte ptr es:[di], al
  inc di
  and dl, dh
  mov ah, dl
  dec cl
  jnz loc_213c
  not ah
  xchg byte ptr es:[di], ah
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cl
  cbw
  add si, ax
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_213c
  push dx
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x7
  mov dx, 0x3ce
  mov al, 0x3
  mov ah, cl
  or ah, 0x10
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
  not byte ptr cs:[0x1c57]
  pop dx
loc_2190:
  push dx
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov cl, byte ptr cs:[0x1c4a]
  mov dl, byte ptr cs:[0x1c52]
  mov byte ptr cs:[0x1c4c], dl
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
  pop dx
  xor ax, ax
loc_21b5:
  lodsb
  xlat cs
  mov dl, al
  and al, ch
  or al, ah
  xchg byte ptr es:[di], al
  inc di
  and dl, dh
  mov ah, dl
  dec cl
  jnz loc_21b5
  xchg byte ptr es:[di], ah
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cl
  cbw
  add si, ax
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_21b5
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jc loc_2190
  jmp loc_24a9
loc_21ef:
  mov al, cs:[0x1c4b]
  cbw
  add si, ax
loc_21f6:
  mov al, cs:[0x1c53]
  cbw
  or ax, ax
  jz loc_220a
  dec ax
  sub si, ax
  lodsb
  xlat cs
  mov dl, al
  inc cx
  jmp loc_2219
loc_220a:
  lodsb
  xlat cs
  mov dl, al
  and al, ch
  or al, ah
  not al
  xchg byte ptr es:[di], al
  inc di
loc_2219:
  and dl, dh
  mov ah, dl
  dec cl
  jnz loc_220a
  not ah
  or ah, byte ptr cs:[0x1c57]
  xchg byte ptr es:[di], ah
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cs:[0x1c4b]
  cbw
  add si, ax
  sub al, byte ptr cs:[0x1c56]
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_21f6
  push dx
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x7
  mov dx, 0x3ce
  mov al, 0x3
  mov ah, cl
  or ah, 0x10
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
  not byte ptr cs:[0x1c57]
  pop dx
loc_226a:
  push dx
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov cl, byte ptr cs:[0x1c4a]
  mov dl, byte ptr cs:[0x1c52]
  mov byte ptr cs:[0x1c4c], dl
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
  pop dx
loc_228d:
  mov al, cs:[0x1c53]
  cbw
  or ax, ax
  jz loc_22a1
  dec ax
  sub si, ax
  lodsb
  xlat cs
  mov dl, al
  inc cx
  jmp loc_22ae
loc_22a1:
  lodsb
  xlat cs
  mov dl, al
  and al, ch
  or al, ah
  xchg byte ptr es:[di], al
  inc di
loc_22ae:
  and dl, dh
  mov ah, dl
  dec cl
  jnz loc_22a1
  and ah, byte ptr cs:[0x1c57]
  xchg byte ptr es:[di], ah
  mov cl, byte ptr cs:[0x1c4a]
  mov al, cs:[0x1c4b]
  cbw
  add si, ax
  sub al, byte ptr cs:[0x1c56]
  add si, ax
  sub di, bp
  dec byte ptr cs:[0x1c4c]
  jnz loc_228d
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jnc loc_22e6
  jmp loc_226a
loc_22e6:
  jmp loc_24a9
loc_22e9:
  cmp byte ptr cs:[0x1c49], 0x0
  jz loc_22f4
  jmp loc_23e2
loc_22f4:
  cmp ch, 0xff
  jnz loc_2354
  xor ch, ch
loc_22fb:
  lodsb
  not al
  scasb
  dec di
  stosb
  loop loc_22fb
  mov cl, dh
  sub di, bp
  dec dl
  jnz loc_22fb
  mov dx, 0x3ce
  mov ax, 0x1003
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
loc_231b:
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov dh, byte ptr cs:[0x1c4a]
  mov cl, dh
  mov dl, byte ptr cs:[0x1c52]
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
loc_2339:
  lodsb
  scasb
  dec di
  stosb
  loop loc_2339
  sub di, bp
  mov cl, dh
  dec dl
  jnz loc_2339
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jc loc_231b
  jmp loc_24a9
loc_2354:
  xor ax, ax
loc_2356:
  lodsb
  mov bl, al
  and al, ch
  or al, ah
  not al
  scasb
  dec di
  stosb
  and bl, bh
  mov ah, bl
  dec cl
  jnz loc_2356
  not ah
  xchg byte ptr es:[di], ah
  mov cl, dh
  sub di, bp
  dec dl
  jnz loc_2354
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x7
  mov dx, 0x3ce
  mov al, 0x3
  mov ah, cl
  or ah, 0x10
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
  not byte ptr cs:[0x1c57]
loc_2398:
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov dh, byte ptr cs:[0x1c4a]
  mov cl, dh
  mov dl, byte ptr cs:[0x1c52]
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
loc_23b6:
  xor ax, ax
loc_23b8:
  lodsb
  mov bl, al
  and al, ch
  or al, ah
  scasb
  dec di
  stosb
  and bl, bh
  mov ah, bl
  dec cl
  jnz loc_23b8
  xchg byte ptr es:[di], ah
  mov cl, dh
  sub di, bp
  dec dl
  jnz loc_23b6
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jc loc_2398
  jmp loc_24a9
loc_23e2:
  mov al, cs:[0x1c53]
  cbw
  or ax, ax
  jz loc_23f4
  dec ax
  inc cx
  add si, ax
  lodsb
  mov bl, al
  jmp loc_2400
loc_23f4:
  lodsb
  mov bl, al
  and al, ch
  or al, ah
  not al
  scasb
  dec di
  stosb
loc_2400:
  and bl, bh
  mov ah, bl
  dec cl
  jnz loc_23f4
  not ah
  or ah, byte ptr cs:[0x1c57]
  xchg byte ptr es:[di], ah
  mov al, cs:[0x1c56]
  cbw
  add si, ax
  mov cl, byte ptr cs:[0x1c4a]
  sub di, bp
  dec dl
  jnz loc_23e2
  mov cl, byte ptr cs:[0x1c50]
  and cl, 0x7
  mov dx, 0x3ce
  mov al, 0x3
  mov ah, cl
  or ah, 0x10
  out dx, ax
  mov dl, 0xc4
  mov al, 0x2
  out dx, al
  mov al, cs:[0x1c5e]
  not byte ptr cs:[0x1c57]
loc_2445:
  mov cs:[0x1c4d], al
  mov dx, 0x3c5
  out dx, al
  mov cl, byte ptr cs:[0x1c4a]
  mov dl, byte ptr cs:[0x1c52]
  mov di, word ptr cs:[0x1c58]
  add si, word ptr cs:[0x1c46]
loc_2461:
  mov al, cs:[0x1c53]
  cbw
  or ax, ax
  jz loc_2473
  dec ax
  inc cx
  add si, ax
  lodsb
  mov bl, al
  jmp loc_247d
loc_2473:
  lodsb
  mov bl, al
  and al, ch
  or al, ah
  scasb
  dec di
  stosb
loc_247d:
  and bl, bh
  mov ah, bl
  dec cl
  jnz loc_2473
  and ah, byte ptr cs:[0x1c57]
  xchg byte ptr es:[di], ah
  mov al, cs:[0x1c56]
  cbw
  add si, ax
  mov cl, byte ptr cs:[0x1c4a]
  sub di, bp
  dec dl
  jnz loc_2461
  mov al, cs:[0x1c4d]
  shl al, 1
  cmp al, 0x10
  jc loc_2445
loc_24a9:
  cld
  mov ax, 0x168f
  mov ds, ax
  mov si, word ptr [0x527a]
  sub si, 0x12
  cmp si, 0x527c
  jc loc_24bf
  jmp loc_1c72
loc_24bf:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_1c61 endp

sub_24c9 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_24f1
  mov ax, [0x4c1]
  mov [0x5262], ax
  add ax, 0x400
  mov [0x5264], ax
  add word ptr [0x4c1], 0x800
loc_24f1:
  mov si, 0x7255
  xor bx, bx
loc_24f6:
  lodsw
  cmp ax, 0xffff
  jz loc_251a
loc_24fc:
  cmp ax, bx
  jz loc_2508
  mov byte ptr [bx+0x70c5], 0x0
  inc bx
  jmp loc_24fc
loc_2508:
  lodsw
loc_2509:
  mov byte ptr [bx+0x70c5], 0x1
  inc bx
  dec ax
  jnz loc_2509
  jmp loc_24f6
loc_2514:
  mov byte ptr [bx+0x70c5], 0x0
  inc bx
loc_251a:
  cmp bx, 0x190
  jz loc_2514
  mov dx, 0x501a
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x5260], ax
  xor bx, bx
loc_252f:
  mov al, byte ptr [bx+0x6666]
  or al, al
  jz loc_2543
  sub byte ptr [bx+0x6930], al
  neg byte ptr [bx+0x6930]
  inc bx
  inc bx
  jmp loc_252f
loc_2543:
  cmp byte ptr cs:[0x1], 0x3
  jc loc_254e
  jmp loc_263e
loc_254e:
  xor si, si
  mov word ptr cs:[0x6676], 0x274f
  mov ax, [0x5260]
  mov [0x5268], ax
  mov word ptr [0x525e], 0x0
  mov es, word ptr [0x4c1]
loc_2567:
  push es
  mov ax, 0xb800
  mov es, ax
  mov di, 0x1ef0
  mov ax, 0x168f
  mov ds, ax
  mov cx, word ptr [0x525e]
  mov dx, cx
  shr dx, 1
  shr dx, 1
  add di, dx
  mov al, 0xc0
  and cl, 0x3
  shl cl, 1
  shr al, cl
  or byte ptr es:[di], al
  pop es
  mov ax, si
  shr ax, 1
  shr ax, 1
  shr ax, 1
  shr ax, 1
  add word ptr [0x5268], ax
  and si, 0xf
  xor di, di
  mov bx, word ptr [0x525e]
  inc word ptr [0x525e]
  shl bx, 1
  mov ax, word ptr [bx+0x6665]
  mov dx, ax
  mul ah
  shr ax, 1
  shr ax, 1
  jz loc_2608
  mov cx, ax
  push si
  mov ds, word ptr [0x5268]
  rep movsw
  pop si
  mov bx, ax
  mov al, dh
  mov ah, dl
  shr ah, 1
  shr ah, 1
  shr ah, 1
  call sub_65be
  add si, bx
  shr bx, 1
  mov bp, bx
  xor di, di
loc_25da:
  mov al, byte ptr es:[di]
  add di, bx
  or al, byte ptr es:[di]
  add di, bx
  or al, byte ptr es:[di]
  or al, byte ptr es:[bx+di]
  sub di, bx
  sub di, bx
  mov cx, 0x8
loc_25f1:
  shr al, 1
  rcr dx, 1
  sar dx, 1
  loop loc_25f1
  xchg dh, dl
  not dx
  mov word ptr [si], dx
  inc si
  inc si
  inc di
  dec bp
  jnz loc_25da
  jmp loc_2567
loc_2608:
  mov ax, 0x168f
  mov ds, ax
  xor di, di
  mov bx, word ptr [0x5260]
  xor cx, cx
loc_2615:
  mov word ptr [di+0x5dc4], bx
  mov word ptr [di+0x5aa4], cx
  mov ax, word ptr [di+0x6665]
  inc di
  inc di
  mul ah
  shr ax, 1
  jz loc_263b
  add cx, ax
  cmp cx, 0x1000
  jc loc_2615
  sub cx, 0x1000
  add bx, 0x100
  jmp loc_2615
loc_263b:
  jmp loc_273d
loc_263e:
  std
  mov ax, [0x4c1]
  mov bx, word ptr [0x5260]
  sub ax, bx
  mov bp, ax
  mov dx, ax
  shr dx, 1
  shr dx, 1
  inc dx
  add ax, dx
  add ax, bx
  mov [0x4c1], ax
  dec ax
  mov bx, ax
  sub ax, dx
loc_265d:
  mov ds, ax
  mov es, bx
  mov si, 0xf
  mov di, si
  mov cx, 0x10
  rep movsb
  dec ax
  dec bx
  dec bp
  jnz loc_265d
  cld
  mov dx, 0x168f
  mov ds, dx
  inc ax
  inc bx
  mov [0x5087], ax
  mov word ptr [0x5089], bx
  mov bx, 0x6665
  xor si, si
  xor di, di
loc_2686:
  mov ax, si
  shr ax, 1
  shr ax, 1
  shr ax, 1
  shr ax, 1
  add word ptr [0x5089], ax
  and si, 0xf
  mov ax, di
  shr ax, 1
  shr ax, 1
  shr ax, 1
  shr ax, 1
  add word ptr [0x5087], ax
  and di, 0xf
  mov ax, word ptr [bx]
  or al, al
  jz loc_26f2
  ror al, 1
  ror al, 1
  ror al, 1
  test al, 0xe0
  jz loc_26bc
  and al, 0x1f
  inc al
loc_26bc:
  inc bx
  inc bx
  mul ah
  mov bp, ax
  mov es, word ptr [0x5087]
  mov ds, word ptr [0x5089]
  mov cx, bp
  push si
loc_26cd:
  mov al, byte ptr [si]
  or al, byte ptr ds:[bp+si]
  add si, bp
  or al, byte ptr ds:[bp+si]
  add si, bp
  or al, byte ptr ds:[bp+si]
  sub si, bp
  sub si, bp
  stosb
  inc si
  loop loc_26cd
  pop si
  mov cx, bp
  shl cx, 1
  rep movsw
  mov ax, 0x168f
  mov ds, ax
  jmp loc_2686
loc_26f2:
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov bx, word ptr [0x5260]
  mov si, 0x6665
  xor di, di
  xor dx, dx
loc_2704:
  lodsw
  or al, al
  jz loc_273d
  ror al, 1
  ror al, 1
  ror al, 1
  test al, 0xe0
  jz loc_2717
  and al, 0x1f
  inc al
loc_2717:
  mul ah
  mov bp, ax
  shl ax, 1
  shl ax, 1
  add ax, bp
  mov word ptr [di+0x5aa4], dx
  mov word ptr [di+0x5dc4], bx
  cmp dx, 0x1000
  jc loc_2737
  sub dx, 0x1000
  add bx, 0x100
loc_2737:
  inc di
  inc di
  add dx, ax
  jmp loc_2704
loc_273d:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db ffh
  db ffh
  db 00h
  db 00h
  db aah
  db aah
  db aah
  db aah
  db aah
  db aah
  db aah
  db aah
  db 00h
  db aah
  db 00h
  db 00h
  db 00h
  db 55h
  db 55h
  db 55h
  db 55h
  db 55h
  db 00h
  db 00h
  db 55h
  db 55h
  db aah
  db aah
  db ffh
  db ffh
sub_24c9 endp ; sp-analysis failed

sub_276f proc near
  push ax
  push cx
  push dx
  push di
  push ds
  push es
  call sub_2c87
  mov ax, 0x168f
  mov ds, ax
  call sub_27df
  call sub_32f4
  mov bp, 0x2
  mov di, 0xc92
loc_2789:
  call sub_3243
  mov cx, bp
loc_278e:
  call sub_28cd
  inc di
  inc di
  loop loc_278e
  dec di
  dec di
  mov cx, bp
  dec cx
loc_279a:
  add di, 0x190
  call sub_28cd
  loop loc_279a
  mov cx, bp
  dec cx
loc_27a6:
  dec di
  dec di
  call sub_28cd
  loop loc_27a6
  mov cx, bp
  dec cx
loc_27b0:
  sub di, 0x190
  call sub_28cd
  loop loc_27b0
  inc bp
  inc bp
  sub di, 0x192
  cmp bp, 0x14
  jc loc_2789
  mov di, word ptr [0x526a]
  mov si, word ptr [0x5268]
  mov ax, 0xa000
  mov es, ax
  mov ds, ax
  mov cx, 0x1e00
  rep movsb
  pop es
  pop ds
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_276f endp

sub_27df proc near
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_27ec
  call sub_3160
  jmp loc_2810
loc_27ec:
  push ax
  push cx
  push dx
  push di
  push es
  call sub_32dc
  mov ax, 0xa000
  mov es, ax
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov di, word ptr [0x5268]
  mov cx, 0xf00
  xor ax, ax
  rep stosw
  pop es
  pop di
  pop dx
  pop cx
  pop ax
loc_2810:
  ret
sub_27df endp

sub_2811 proc near
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_281d
  call sub_3160
  ret
loc_281d:
  push ax
  push cx
  push dx
  push di
  push ds
  push es
  call sub_32dc
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov ax, 0x168f
  mov ds, ax
  mov di, word ptr [0x5268]
  mov cx, 0x14
  mov word ptr cs:[0x274d], 0x26
  mov word ptr cs:[0x274b], 0x1c70
loc_2847:
  call sub_3243
  push cx
  push di
  mov word ptr cs:[0x2747], 0x0
  mov word ptr cs:[0x2749], 0x0
loc_285a:
  add di, word ptr cs:[0x2749]
  call sub_28f8
  add di, word ptr cs:[0x274b]
  call sub_28f8
  sub di, word ptr cs:[0x274b]
  sub di, word ptr cs:[0x2749]
  cmp word ptr cs:[0x2747], 0x1c70
  jbe loc_2883
  add di, 0x1c70
  jmp loc_2888
loc_2883:
  add di, word ptr cs:[0x2747]
loc_2888:
  call sub_28f8
  add di, word ptr cs:[0x274d]
  call sub_28f8
  sub di, word ptr cs:[0x274d]
  sub di, word ptr cs:[0x2747]
  add word ptr cs:[0x2747], 0x190
  add word ptr cs:[0x2749], 0x2
  loop loc_285a
  pop di
  add di, 0x192
  sub word ptr cs:[0x274d], 0x4
  sub word ptr cs:[0x274b], 0x320
  pop cx
  dec cx
  dec cx
  jnz loc_2847
  call sub_32dc
  pop es
  pop ds
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_2811 endp

sub_28cd proc near
  push ax
  push cx
  push di
  push si
  push ds
  push es
  mov si, di
  add si, word ptr [0x526a]
  add di, word ptr [0x5268]
  mov ax, 0xa000
  mov ds, ax
  mov es, ax
  mov cx, 0xa
loc_28e7:
  movsb
  movsb
  add di, 0x26
  add si, 0x26
  loop loc_28e7
  pop es
  pop ds
  pop si
  pop di
  pop cx
  pop ax
  ret
sub_28cd endp

sub_28f8 proc near
  push ax
  push cx
  push di
  push es
  mov ax, 0xa000
  mov es, ax
  mov cx, 0xa
  xor ax, ax
loc_2906:
  stosw
  add di, 0x26
  loop loc_2906
  pop es
  pop di
  pop cx
  pop ax
  ret
sub_28f8 endp

sub_2911 proc near
  push ax
  push cx
  push dx
  push di
  mov ax, 0x168f
  mov ds, ax
  cmp word ptr [0x5272], 0x0
  jz loc_2946
  dec word ptr [0x5272]
  mov ax, [0x5276]
  dec ax
  jns loc_292e
  mov ax, 0xb
loc_292e:
  xor di, di
  mov [0x5276], ax
  mov ax, [0x5274]
  call sub_2b67
  mov ah, byte ptr [0x5272]
  mov al, [0x5270]
  call sub_2a0d
  clc
  jmp loc_2947
loc_2946:
  stc
loc_2947:
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_2911 endp

sub_294c proc near
  push ax
  push cx
  push dx
  push di
  mov ax, 0x168f
  mov ds, ax
  mov al, [0x508b]
  xor ah, ah
  sub ax, 0xc
  cmp word ptr [0x5272], ax
  jnc loc_298e
  inc word ptr [0x5272]
  mov ax, [0x5276]
  inc ax
  cmp ax, 0xc
  jc loc_2972
  xor ax, ax
loc_2972:
  mov di, 0x1b80
  mov [0x5276], ax
  mov ax, [0x5274]
  call sub_2b67
  mov ah, byte ptr [0x5272]
  mov al, [0x5270]
  add ax, 0xb00
  call sub_2a0d
  clc
  jmp loc_298f
loc_298e:
  stc
loc_298f:
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_294c endp

sub_2994 proc near
  push ax
  push cx
  push dx
  push di
  mov ax, 0x168f
  mov ds, ax
  xor di, di
  cmp word ptr [0x5270], 0x0
  jz loc_2a07
  dec word ptr [0x5270]
  mov ax, [0x5274]
  dec ax
  jns loc_29f2
  mov ax, 0x13
  jmp loc_29f2
sub_2994 endp

sub_29b5 proc near
  push ax
  push cx
  push dx
  push di
  mov ax, 0x168f
  mov ds, ax
  mov ax, [0x527c]
  sar ax, 1
  sar ax, 1
  sar ax, 1
  sar ax, 1
  sub ax, 0x14
  cmp word ptr [0x7d3d], ax
  jge loc_29d7
  mov ax, 0xec
  jmp loc_29da
loc_29d7:
  mov ax, [0x7d3d]
loc_29da:
  cmp word ptr [0x5270], ax
  jnc loc_2a07
  mov di, 0x13
  inc word ptr [0x5270]
  mov ax, [0x5274]
  inc ax
  cmp ax, 0x14
  jc loc_29f2
  xor ax, ax
loc_29f2:
  mov [0x5274], ax
  call sub_2b67
  mov ah, byte ptr [0x5272]
  mov al, [0x5270]
  add ax, di
  call sub_2ab1
  clc
  jmp loc_2a08
loc_2a07:
  stc
loc_2a08:
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_29b5 endp

sub_2a0d proc near
  push ax
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  push ds
  pop es
  cmp byte ptr cs:[0x1], 0x3
  jc loc_2a6c
  call sub_32f4
  mov si, ax
  add di, word ptr [0x5266]
  mov dx, word ptr [0x5274]
  mov bx, 0x63e4
  mov ds, word ptr [0x526c]
  mov cx, 0x14
loc_2a36:
  cmp di, 0x5c80
  jc loc_2a40
  sub di, 0x1e00
loc_2a40:
  lodsb
  mov ah, al
  xlat es
  or byte ptr es:[0x64f5], al
  mov al, ah
  push es
  mov bp, 0xa000
  mov es, bp
  call sub_2df5
  pop es
  inc dx
  cmp dx, 0x14
  jc loc_2a61
  sub di, 0x28
  xor dx, dx
loc_2a61:
  loop loc_2a36
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop ax
  ret
loc_2a6c:
  mov si, ax
  shl di, 1
  add di, word ptr [0x5266]
  mov dx, word ptr [0x5274]
  mov bx, 0x63e4
  mov ds, word ptr [0x526c]
  mov cx, 0x14
loc_2a82:
  cmp di, 0x3c00
  jc loc_2a8c
  sub di, 0x3c00
loc_2a8c:
  lodsb
  mov ah, al
  xlat es
  or byte ptr es:[0x64f5], al
  mov al, ah
  call sub_2e53
  inc dx
  cmp dx, 0x14
  jc loc_2aa6
  sub di, 0x50
  xor dx, dx
loc_2aa6:
  loop loc_2a82
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop ax
  ret
sub_2a0d endp

sub_2ab1 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_2b0d
  push ds
  push es
  push ds
  pop es
  call sub_32f4
  mov si, ax
  mov ax, di
  shl di, 1
  add di, word ptr [0x5266]
  add ax, word ptr [0x5274]
  cmp ax, 0x14
  jc loc_2ad6
  sub di, 0x28
loc_2ad6:
  mov ds, word ptr [0x526c]
  mov cx, 0xc
  mov bx, 0x63e4
loc_2ae0:
  cmp di, 0x5c80
  jc loc_2aea
  sub di, 0x1e00
loc_2aea:
  lodsb
  mov ah, al
  xlat es
  or byte ptr es:[0x64f5], al
  mov al, ah
  push es
  mov dx, 0xa000
  mov es, dx
  call sub_2df5
  pop es
  add si, 0xff
  add di, 0x27e
  loop loc_2ae0
  pop es
  pop ds
  ret
loc_2b0d:
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  push ds
  pop es
  mov si, ax
  mov ax, di
  shl di, 1
  shl di, 1
  add di, word ptr [0x5266]
  add ax, word ptr [0x5274]
  cmp ax, 0x14
  jc loc_2b30
  sub di, 0x50
loc_2b30:
  mov ds, word ptr [0x526c]
  mov cx, 0xc
  mov bx, 0x63e4
loc_2b3a:
  cmp di, 0x3c00
  jc loc_2b44
  sub di, 0x3c00
loc_2b44:
  lodsb
  mov ah, al
  xlat es
  or byte ptr es:[0x64f5], al
  mov al, ah
  call sub_2e53
  add si, 0xff
  add di, 0x4fc
  loop loc_2b3a
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_2ab1 endp

sub_2b67 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_2b88
  shl ax, 1
  mov dh, byte ptr [0x5276]
  xor dl, dl
  mov bx, dx
  shl bx, 1
  shr dx, 1
  add ax, dx
  add ax, bx
  add ax, 0x3e80
  mov [0x5266], ax
  ret
loc_2b88:
  shl ax, 1
  shl ax, 1
  push ax
  mov ax, 0x500
  mov dl, byte ptr [0x5276]
  xor dh, dh
  mul dx
  pop dx
  add ax, dx
  mov [0x5266], ax
  ret
loc_2b9f:
  jmp loc_2c7d
sub_2b67 endp

sub_2ba2 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov es, word ptr [0x526c]
  call sub_32f4
  cmp byte ptr [0x64f5], 0x0
  jz loc_2b9f
  test byte ptr [0x64fc], 0x3
  jnz loc_2b9f
  mov byte ptr [0x64f5], 0x0
  mov ah, byte ptr [0x5272]
  mov al, [0x5270]
  mov si, ax
  mov ch, 0xc
  xor bh, bh
  mov di, word ptr [0x5266]
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_2c32
loc_2be3:
  mov dx, word ptr [0x5274]
  mov cl, 0x14
loc_2be9:
  mov bl, byte ptr es:[si]
  cmp byte ptr [bx+0x63e4], 0x0
  jz loc_2c11
  mov byte ptr [0x64f5], 0x1
  mov al, bl
  mov bx, word ptr [0x64f6]
  xlat ds
  xor bh, bh
  cmp di, 0x3c00
  jc loc_2c0b
  sub di, 0x3c00
loc_2c0b:
  call sub_2e53
  sub di, 0x4
loc_2c11:
  inc dx
  cmp dx, 0x14
  jc loc_2c1c
  sub di, 0x50
  xor dx, dx
loc_2c1c:
  add di, 0x4
  inc si
  dec cl
  jnz loc_2be9
  add di, 0x500
  add si, 0xec
  dec ch
  jnz loc_2be3
  jmp loc_2c7d
loc_2c32:
  mov dx, word ptr [0x5274]
  mov cl, 0x14
loc_2c38:
  mov bl, byte ptr es:[si]
  cmp byte ptr [bx+0x63e4], 0x0
  jz loc_2c5f
  mov byte ptr [0x64f5], 0x1
  mov al, bl
  mov bx, word ptr [0x64f6]
  xlat ds
  xor bh, bh
  cmp di, 0x5c80
  jc loc_2c5a
  sub di, 0x1e00
loc_2c5a:
  call sub_2de8
  dec di
  dec di
loc_2c5f:
  inc dx
  cmp dx, 0x14
  jc loc_2c6a
  sub di, 0x28
  xor dx, dx
loc_2c6a:
  inc di
  inc di
  inc si
  dec cl
  jnz loc_2c38
  add di, 0x280
  add si, 0xec
  dec ch
  jnz loc_2c32
loc_2c7d:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_2ba2 endp

sub_2c87 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_2cfb
  push bx
  push di
  push si
  push ds
  push es
  call sub_32f4
  mov ax, 0x168f
  mov ds, ax
  mov si, word ptr [0x5266]
  mov di, word ptr [0x526a]
  mov dl, 0x14
  mov dh, byte ptr [0x5274]
  sub dl, dh
  shl dl, 1
  shl dh, 1
  mov bp, 0xc
  sub bp, word ptr [0x5276]
  mov cl, 0x4
  shl bp, cl
  mov ax, 0xa000
  mov es, ax
  mov ds, ax
  xor ch, ch
  mov ax, 0x28
  mov bx, 0xc0
  sub bx, bp
loc_2ccc:
  mov cl, dl
  rep movsb
  sub si, ax
  mov cl, dh
  rep movsb
  add si, ax
  dec bp
  jnz loc_2ccc
  or bx, bx
  jz loc_2cf5
  mov si, 0x3e80
  mov cl, dh
  add si, cx
loc_2ce6:
  mov cl, dl
  rep movsb
  sub si, ax
  mov cl, dh
  rep movsb
  add si, ax
  dec bx
  jnz loc_2ce6
loc_2cf5:
  pop es
  pop ds
  pop si
  pop di
  pop bx
  ret
loc_2cfb:
  push bx
  push di
  push si
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  mov si, word ptr [0x5266]
  xor di, di
  mov dl, 0x14
  mov dh, byte ptr [0x5274]
  sub dl, dh
  shl dl, 1
  shl dh, 1
  mov bp, 0xc
  sub bp, word ptr [0x5276]
  mov cl, 0x4
  shl bp, cl
  mov es, word ptr [0x5262]
  mov ds, word ptr [0x5264]
  xor ch, ch
  mov ax, 0x50
  mov bx, 0xc0
  sub bx, bp
loc_2d34:
  mov cl, dl
  rep movsw
  sub si, ax
  mov cl, dh
  rep movsw
  add si, ax
  dec bp
  jnz loc_2d34
  or bx, bx
  jz loc_2d5c
  mov cl, dh
  mov si, cx
  add si, cx
loc_2d4d:
  mov cl, dl
  rep movsw
  sub si, ax
  mov cl, dh
  rep movsw
  add si, ax
  dec bx
  jnz loc_2d4d
loc_2d5c:
  pop es
  pop ds
  pop si
  pop di
  pop bx
  ret
sub_2c87 endp

sub_2d62 proc near
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  xor ax, ax
  call sub_2811
  mov [0x5270], ax
  mov [0x5272], ax
  mov [0x5274], ax
  mov [0x5276], ax
  call sub_2b67
  mov di, word ptr [0x5266]
  mov es, word ptr [0x526c]
  xor si, si
  cmp byte ptr cs:[0x1], 0x3
  jc loc_2daf
  call sub_32f4
  mov ch, 0xc
loc_2d94:
  mov cl, 0x14
loc_2d96:
  mov al, byte ptr es:[si]
  call sub_2de8
  inc si
  dec cl
  jnz loc_2d96
  add si, 0xec
  add di, 0x258
  dec ch
  jnz loc_2d94
  jmp loc_2dca
loc_2daf:
  mov ch, 0xc
loc_2db1:
  mov cl, 0x14
loc_2db3:
  mov al, byte ptr es:[si]
  call sub_2e53
  inc si
  dec cl
  jnz loc_2db3
  add si, 0xec
  add di, 0x4b0
  dec ch
  jnz loc_2db1
loc_2dca:
  call sub_3f46
  mov al, [0x6521]
  or al, byte ptr [0x6520]
  jnz loc_2dca
  call sub_276f
  pop es
  pop ds
  ret
sub_2d62 endp

sub_2ddc proc near
  cmp byte ptr cs:[0x1], 0x3
  jc sub_2e53
  add di, 0x3e80
sub_2ddc endp ; sp-analysis failed

sub_2de8 proc near
  push dx
  push es
  mov dx, 0xa000
  mov es, dx
  call sub_2df5
  pop es
  pop dx
  ret
sub_2de8 endp

sub_2df5 proc near
  push si
  push ds
  xor ah, ah
  shl ax, 1
  shl ax, 1
  shl ax, 1
  shl ax, 1
  shl ax, 1
  mov si, ax
  add si, 0x5dc0
  push es
  pop ds
  mov bp, 0x26
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  add di, bp
  movsb
  movsb
  sub di, 0x258
  pop ds
  pop si
  ret
sub_2df5 endp

sub_2e53 proc near
  push si
  push ds
  push bp
  push es
  mov ah, al
  xor al, al
  shr ax, 1
  mov si, ax
  mov ax, 0x168f
  mov ds, ax
  mov es, word ptr [0x5264]
  mov ds, word ptr cs:[0xb95e]
  mov bp, 0x4c
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  add di, bp
  movsw
  movsw
  sub di, 0x4b0
  pop es
  pop bp
  pop ds
  pop si
  ret
sub_2e53 endp

sub_2eb7 proc near
  push ds
  mov dx, 0x168f
  mov ds, dx
  mov es, dx
  mov [0x5250], al
  add al, 0x30
  cmp al, 0x39
  jbe loc_2eca
  add al, 0x7
loc_2eca:
  mov [0x5256], al
  mov di, 0x72a3
  mov cx, 0xbf4
  mov al, 0xff
  rep stosb
  mov di, 0x527c
  mov cx, 0x20a
  rep stosw
  call sub_32dc
  mov dx, 0x5251
  call sub_097b
  mov [0x526c], ax
  push ax
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov al, [0x5250]
  mov ah, 0x3
  mul ah
  mov si, ax
  add si, 0x50c8
  mov di, 0x5081
  mov cx, 0x3
  rep movsb
  mov dx, 0x5057
  call sub_0410
  pop ax
  call sub_3009
  mov ax, 0x168f
  mov es, ax
  mov di, 0x72a3
  mov cx, 0x180
  rep movsw
  mov cx, 0xf0
  rep movsb
  mov cl, 0x3
  rep movsw
  mov cx, 0x514
  rep movsb
  mov cx, 0x190
  rep movsb
  movsw
  mov cx, 0x8c
  rep movsb
  mov cx, 0xc8
  rep movsb
  movsw
  movsw
  call sub_2f76
  call sub_2fdd
  mov ax, [0x7695]
  mov [0x64e4], ax
  mov ax, [0x7697]
  mov [0x64e6], ax
  mov si, 0x7dcb
  mov cx, 0xa
loc_2f57:
  cmp byte ptr es:[si+0x7], 0x8
  jc loc_2f64
  mov word ptr es:[si+0x4], 0xffff
loc_2f64:
  add si, 0x14
  loop loc_2f57
  mov si, 0x75a3
  mov di, 0x7e97
  mov cx, 0x8f4
  rep movsb
  pop ds
  ret
sub_2eb7 endp

sub_2f76 proc near
  mov ax, 0x168f
  mov ds, ax
  xor bx, bx
  mov cx, 0x100
  xor dl, dl
loc_2f82:
  test byte ptr [bx+0x74a3], 0x80
  jnz loc_2f9c
  mov byte ptr [bx+0x60e4], bl
  mov byte ptr [bx+0x61e4], bl
  mov byte ptr [bx+0x62e4], bl
  mov byte ptr [bx+0x63e4], 0x0
  jmp loc_2fd3
loc_2f9c:
  mov dl, 0x1
  mov al, bl
  mov byte ptr [bx+0x60e4], al
  mov byte ptr [bx+0x61e6], al
  mov byte ptr [bx+0x62e5], al
  inc ax
  mov byte ptr [bx+0x60e5], al
  mov byte ptr [bx+0x61e4], al
  mov byte ptr [bx+0x62e6], al
  inc ax
  mov byte ptr [bx+0x60e6], al
  mov byte ptr [bx+0x61e5], al
  mov byte ptr [bx+0x62e4], al
  mov byte ptr [bx+0x63e4], 0x1
  mov word ptr [bx+0x63e5], 0x101
  inc bx
  inc bx
loc_2fd3:
  inc bx
  or bh, bh
  jz loc_2f82
  mov byte ptr [0x64f5], dl
  ret
sub_2f76 endp

sub_2fdd proc near
  push ax
  push cx
  push di
  push si
  push ds
  push es
  mov ax, 0x168f
  mov ds, ax
  mov es, word ptr [0x526c]
  mov si, 0x7bad
  mov cx, 0x64
loc_2ff2:
  mov di, word ptr [si+0x2]
  cmp di, -0x1
  jz loc_2ffd
  mov al, byte ptr [si]
  stosb
loc_2ffd:
  add si, 0x4
  loop loc_2ff2
  pop es
  pop ds
  pop si
  pop di
  pop cx
  pop ax
  ret
sub_2fdd endp

sub_3009 proc near
  mov bl, byte ptr [0x5250]
  mov bh, byte ptr [bx+0x50a0]
  mov byte ptr [0x508b], bh
  cmp byte ptr cs:[0x1], 0x3
  jnc loc_3044
  xor bl, bl
  mov cl, 0x4
  shr bx, cl
  add ax, bx
  mov ds, ax
  xor si, si
  mov cs:[0xb95e], ax
  mov word ptr cs:[0x6676], 0x66b8
  mov cx, 0x100
loc_3037:
  mov ax, 0x210
  call sub_65be
  add si, 0x80
  loop loc_3037
  ret
loc_3044:
  xor bl, bl
  mov cl, 0x4
  shr bx, cl
  add ax, bx
  mov [0x4c1], ax
  mov ds, ax
  xor si, si
  mov ax, 0xa000
  mov es, ax
  mov di, 0x5dc0
  mov dx, 0x3c4
  mov al, 0x2
  out dx, al
  inc dx
  mov bx, 0x100
loc_3065:
  mov al, 0x1
loc_3067:
  out dx, al
  mov cx, 0x10
  rep movsw
  sub di, 0x20
  shl al, 1
  cmp al, 0x10
  jc loc_3067
  add di, 0x20
  dec bx
  jnz loc_3065
  ret
sub_3009 endp

sub_307d proc near
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr cs:[0x1], 0xff
  jz loc_308d
  jmp sub_3160
loc_308d:
  mov ax, 0xd
  int 0x10
  mov dx, 0x3c8
  mov al, 0x40
  out dx, al
  inc dx
  mov cx, 0x1e
  mov si, 0x5057
loc_309f:
  lodsb
  and al, 0x3f
  out dx, al
  loop loc_309f
  mov cx, 0x1e
  sub si, cx
  mov al, 0x40
  mov dl, 0xc7
  out dx, al
  mov dl, 0xc9
loc_30b1:
  mov ah, byte ptr [si]
  inc si
  and ah, 0x3f
  in al, dx
  cmp al, ah
  jnz loc_30ca
  loop loc_30b1
  call sub_3126
  jc loc_30e6
  mov byte ptr cs:[0x1], 0x5
  ret
loc_30ca:
  call sub_3126
  jc loc_30e6
  mov byte ptr cs:[0x1], 0x4
  mov ah, 0x12
  mov bl, 0x10
  int 0x10
  or bl, bl
  jnz loc_3125
  mov byte ptr cs:[0x1], 0x3
  ret
loc_30e6:
  mov ax, 0x3
  int 0x10
  mov ah, 0xf
  int 0x10
  cmp ax, 0x5003
  jz loc_30fb
  mov byte ptr cs:[0x1], 0x0
  ret
loc_30fb:
  mov byte ptr cs:[0x1], 0x2
  mov ax, 0x9
  int 0x10
  mov ax, 0xb800
  mov es, ax
  mov byte ptr es:[0x4000], 0xff
  mov al, es:[0x4000]
  mov ah, byte ptr es:[0x0]
  cmp ax, 0xff
  jz loc_3125
  mov byte ptr cs:[0x1], 0x1
loc_3125:
  ret
sub_307d endp

sub_3126 proc near
  mov ax, 0xd
  int 0x10
  mov ax, 0xa000
  mov es, ax
  mov dx, 0x3c4
  mov ax, 0x102
  out dx, ax
  mov dl, 0xce
  mov ax, 0x5
  out dx, ax
  mov ax, 0x4
  out dx, ax
  mov al, 0x51
  mov es:[0x2000], al
  cmp byte ptr es:[0x2000], al
  jnz loc_315e
  mov ax, 0x103
  out dx, ax
  mov byte ptr es:[si], 0xaa
  cmp byte ptr es:[si], 0x55
  jnz loc_315e
  clc
  ret
loc_315e:
  stc
  ret
sub_3126 endp

sub_3160 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov al, cs:[0x1]
  cmp al, 0x1
  jz loc_31c5
  cmp al, 0x2
  jz loc_31c5
  cmp al, 0x0
  jz loc_31e9
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov ax, 0xd
  int 0x10
  mov dx, 0x3d4
  mov ax, 0x2411
  out dx, ax
  mov word ptr [0x5268], 0x0
  mov word ptr [0x526a], 0x1f40
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_31a4
  cmp al, 0x3
  jnc loc_31bb
loc_31a4:
  mov dx, 0x5046
  mov ax, 0x1002
  int 0x10
  mov ax, 0x1012
  xor bx, bx
  mov cx, 0x10
  mov dx, 0x5057
  int 0x10
  jmp loc_31e7
loc_31bb:
  mov dx, 0x5035
  mov ax, 0x1002
  int 0x10
  jmp loc_31e7
loc_31c5:
  mov ax, 0x168f
  mov ds, ax
  mov word ptr [0x526a], 0x0
  mov word ptr [0x5268], 0x0
  mov word ptr [0x525c], 0x50
  mov byte ptr cs:[0x0], 0x2
  mov ax, 0x4
  int 0x10
loc_31e7:
  jmp loc_3239
loc_31e9:
  mov ax, 0x168f
  mov ds, ax
  mov word ptr [0x526a], 0x0
  mov word ptr [0x5268], 0x0
  mov word ptr [0x525c], 0x50
  mov byte ptr cs:[0x0], 0x2
  mov si, 0x5025
  mov dx, 0x3bf
  mov al, 0x3
  out dx, al
  mov dl, 0xb8
  mov al, 0x82
  out dx, al
  mov dl, 0xb4
  mov cx, 0xe
  xor ax, ax
loc_321b:
  mov al, ah
  out dx, al
  inc dx
  lodsb
  out dx, al
  dec dx
  inc ah
  loop loc_321b
  mov cx, 0x2000
  mov ax, 0xb800
  mov es, ax
  xor ax, ax
  xor di, di
  rep stosw
  mov dl, 0xb8
  mov al, 0x8a
  out dx, al
loc_3239:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_3160 endp

sub_3243 proc near
  push ax
  push dx
  cmp byte ptr cs:[0x1], 0x0
  jz loc_325f
  mov dx, 0x3da
  mov ah, 0x8
loc_3252:
  in al, dx
  test ah, al
  jnz loc_3252
loc_3257:
  in al, dx
  test ah, al
  jz loc_3257
  pop dx
  pop ax
  ret
loc_325f:
  mov dx, 0x3ba
  mov ah, 0x1
loc_3264:
  in al, dx
  test ah, al
  jnz loc_3264
loc_3269:
  in al, dx
  test ah, al
  jz loc_3269
  pop dx
  pop ax
  ret
sub_3243 endp

sub_3271 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_32a4
  call sub_10d3
  mov dx, 0x3d4
  mov ax, 0x168f
  mov ds, ax
  mov bx, word ptr [0x526a]
  mov al, 0xd
  mov ah, bl
  out dx, ax
  dec ax
  mov ah, bh
  out dx, ax
  xchg word ptr [0x5268], bx
  mov word ptr [0x526a], bx
  cmp byte ptr [0x651a], 0x0
  jz loc_32a3
  call sub_3243
loc_32a3:
  ret
loc_32a4:
  push ds
  push es
  push si
  push di
  push dx
  push ax
  push cx
  mov ds, word ptr [0x5262]
  xor si, si
  mov ax, 0xb800
  mov es, ax
  xor di, di
  mov dx, 0x60
  mov ax, 0x28
loc_32be:
  mov cx, ax
  rep movsw
  add di, 0x1fb0
  mov cx, ax
  rep movsw
  sub di, 0x2000
  dec dx
  jnz loc_32be
  call sub_10d3
  pop cx
  pop ax
  pop dx
  pop di
  pop si
  pop es
  pop ds
  ret
sub_3271 endp

sub_32dc proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_32f3
  push ax
  push dx
  mov dx, 0x3ce
  mov ax, 0x5
  out dx, ax
  mov ax, 0x3
  out dx, ax
  pop dx
  pop ax
loc_32f3:
  ret
sub_32dc endp

sub_32f4 proc near
  cmp byte ptr cs:[0x1], 0x3
  jc loc_330d
  push ax
  push dx
  mov dx, 0x3ce
  mov ax, 0x105
  out dx, ax
  mov dl, 0xc4
  mov ax, 0xf02
  out dx, ax
  pop dx
  pop ax
loc_330d:
  ret
  db 00h
  db 40h
  db 80h
  db c0h
  db 10h
  db 50h
  db 90h
  db d0h
  db 20h
  db 60h
  db a0h
  db e0h
  db 30h
  db 70h
  db b0h
  db f0h
  db 04h
  db 44h
  db 84h
  db c4h
  db 14h
  db 54h
  db 94h
  db d4h
  db 24h
  db 64h
  db a4h
  db e4h
  db 34h
  db 74h
  db b4h
  db f4h
  db 08h
  db 48h
  db 88h
  db c8h
  db 18h
  db 58h
  db 98h
  db d8h
  db 28h
  db 68h
  db a8h
  db e8h
  db 38h
  db 78h
  db b8h
  db f8h
  db 0ch
  db 4ch
  db 8ch
  db cch
  db 1ch
  db 5ch
  db 9ch
  db dch
  db 2ch
  db 6ch
  db ach
  db ech
  db 3ch
  db 7ch
  db bch
  db fch
  db 01h
  db 41h
  db 81h
  db c1h
  db 11h
  db 51h
  db 91h
  db d1h
  db 21h
  db 61h
  db a1h
  db e1h
  db 31h
  db 71h
  db b1h
  db f1h
  db 05h
  db 45h
  db 85h
  db c5h
  db 15h
  db 55h
  db 95h
  db d5h
  db 25h
  db 65h
  db a5h
  db e5h
  db 35h
  db 75h
  db b5h
  db f5h
  db 09h
  db 49h
  db 89h
  db c9h
  db 19h
  db 59h
  db 99h
  db d9h
  db 29h
  db 69h
  db a9h
  db e9h
  db 39h
  db 79h
  db b9h
  db f9h
  db 0dh
  db 4dh
  db 8dh
  db cdh
  db 1dh
  db 5dh
  db 9dh
  db ddh
  db 2dh
  db 6dh
  db adh
  db edh
  db 3dh
  db 7dh
  db bdh
  db fdh
  db 02h
  db 42h
  db 82h
  db c2h
  db 12h
  db 52h
  db 92h
  db d2h
  db 22h
  db 62h
  db a2h
  db e2h
  db 32h
  db 72h
  db b2h
  db f2h
  db 06h
  db 46h
  db 86h
  db c6h
  db 16h
  db 56h
  db 96h
  db d6h
  db 26h
  db 66h
  db a6h
  db e6h
  db 36h
  db 76h
  db b6h
  db f6h
  db 0ah
  db 4ah
  db 8ah
  db cah
  db 1ah
  db 5ah
  db 9ah
  db dah
  db 2ah
  db 6ah
  db aah
  db eah
  db 3ah
  db 7ah
  db bah
  db fah
  db 0eh
  db 4eh
  db 8eh
  db ceh
  db 1eh
  db 5eh
  db 9eh
  db deh
  db 2eh
  db 6eh
  db aeh
  db eeh
  db 3eh
  db 7eh
  db beh
  db feh
  db 03h
  db 43h
  db 83h
  db c3h
  db 13h
  db 53h
  db 93h
  db d3h
  db 23h
  db 63h
  db a3h
  db e3h
  db 33h
  db 73h
  db b3h
  db f3h
  db 07h
  db 47h
  db 87h
  db c7h
  db 17h
  db 57h
  db 97h
  db d7h
  db 27h
  db 67h
  db a7h
  db e7h
  db 37h
  db 77h
  db b7h
  db f7h
  db 0bh
  db 4bh
  db 8bh
  db cbh
  db 1bh
  db 5bh
  db 9bh
  db dbh
  db 2bh
  db 6bh
  db abh
  db ebh
  db 3bh
  db 7bh
  db bbh
  db fbh
  db 0fh
  db 4fh
  db 8fh
  db cfh
  db 1fh
  db 5fh
  db 9fh
  db dfh
  db 2fh
  db 6fh
  db afh
  db efh
  db 3fh
  db 7fh
  db bfh
  db ffh
  db 00h
  db 80h
  db 40h
  db c0h
  db 20h
  db a0h
  db 60h
  db e0h
  db 10h
  db 90h
  db 50h
  db d0h
  db 30h
  db b0h
  db 70h
  db f0h
  db 08h
  db 88h
  db 48h
  db c8h
  db 28h
  db a8h
  db 68h
  db e8h
  db 18h
  db 98h
  db 58h
  db d8h
  db 38h
  db b8h
  db 78h
  db f8h
  db 04h
  db 84h
  db 44h
  db c4h
  db 24h
  db a4h
  db 64h
  db e4h
  db 14h
  db 94h
  db 54h
  db d4h
  db 34h
  db b4h
  db 74h
  db f4h
  db 0ch
  db 8ch
  db 4ch
  db cch
  db 2ch
  db ach
  db 6ch
  db ech
  db 1ch
  db 9ch
  db 5ch
  db dch
  db 3ch
  db bch
  db 7ch
  db fch
  db 02h
  db 82h
  db 42h
  db c2h
  db 22h
  db a2h
  db 62h
  db e2h
  db 12h
  db 92h
  db 52h
  db d2h
  db 32h
  db b2h
  db 72h
  db f2h
  db 0ah
  db 8ah
  db 4ah
  db cah
  db 2ah
  db aah
  db 6ah
  db eah
  db 1ah
  db 9ah
  db 5ah
  db dah
  db 3ah
  db bah
  db 7ah
  db fah
  db 06h
  db 86h
  db 46h
  db c6h
  db 26h
  db a6h
  db 66h
  db e6h
  db 16h
  db 96h
  db 56h
  db d6h
  db 36h
  db b6h
  db 76h
  db f6h
  db 0eh
  db 8eh
  db 4eh
  db ceh
  db 2eh
  db aeh
  db 6eh
  db eeh
  db 1eh
  db 9eh
  db 5eh
  db deh
  db 3eh
  db beh
  db 7eh
  db feh
  db 01h
  db 81h
  db 41h
  db c1h
  db 21h
  db a1h
  db 61h
  db e1h
  db 11h
  db 91h
  db 51h
  db d1h
  db 31h
  db b1h
  db 71h
  db f1h
  db 09h
  db 89h
  db 49h
  db c9h
  db 29h
  db a9h
  db 69h
  db e9h
  db 19h
  db 99h
  db 59h
  db d9h
  db 39h
  db b9h
  db 79h
  db f9h
  db 05h
  db 85h
  db 45h
  db c5h
  db 25h
  db a5h
  db 65h
  db e5h
  db 15h
  db 95h
  db 55h
  db d5h
  db 35h
  db b5h
  db 75h
  db f5h
  db 0dh
  db 8dh
  db 4dh
  db cdh
  db 2dh
  db adh
  db 6dh
  db edh
  db 1dh
  db 9dh
  db 5dh
  db ddh
  db 3dh
  db bdh
  db 7dh
  db fdh
  db 03h
  db 83h
  db 43h
  db c3h
  db 23h
  db a3h
  db 63h
  db e3h
  db 13h
  db 93h
  db 53h
  db d3h
  db 33h
  db b3h
  db 73h
  db f3h
  db 0bh
  db 8bh
  db 4bh
  db cbh
  db 2bh
  db abh
  db 6bh
  db ebh
  db 1bh
  db 9bh
  db 5bh
  db dbh
  db 3bh
  db bbh
  db 7bh
  db fbh
  db 07h
  db 87h
  db 47h
  db c7h
  db 27h
  db a7h
  db 67h
  db e7h
  db 17h
  db 97h
  db 57h
  db d7h
  db 37h
  db b7h
  db 77h
  db f7h
  db 0fh
  db 8fh
  db 4fh
  db cfh
  db 2fh
  db afh
  db 6fh
  db efh
  db 1fh
  db 9fh
  db 5fh
  db dfh
  db 3fh
  db bfh
  db 7fh
  db ffh
loc_350e:
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov byte ptr [0x5250], 0x0
  mov byte ptr [0x6518], 0x0
  mov di, 0x527c
  mov cx, 0x3a
loc_3525:
  mov word ptr [di+0x4], 0xffff
  add di, 0x12
  loop loc_3525
  mov word ptr [0x5280], 0x157
  mov word ptr [0x527c], 0xff9c
  mov word ptr [0x527e], 0xb4
  mov word ptr [0x5288], 0x6609
  mov word ptr [0x52b6], 0x151
  mov word ptr [0x52b2], 0x1a4
  mov word ptr [0x52b4], 0xb4
  mov word ptr [0x52be], 0x65e3
loc_355f:
  call sub_3f46
  call sub_2ba2
  mov si, 0x527c
  add word ptr [si], 0x3
  call sub_3611
  mov si, 0x52b2
  sub word ptr [si], 0x3
  call sub_3611
  call sub_2c87
  call sub_1c61
  call sub_3271
  mov ax, [0x527c]
  add ax, 0x1c
  cmp word ptr [0x52b2], ax
  jg loc_355f
  mov word ptr [0x52b6], 0x815a
  sub word ptr [0x52b2], 0x18
  mov si, 0x527c
  mov word ptr [0x5288], 0x661d
  sub word ptr [0x527e], 0x10
  mov cx, 0x10
loc_35a8:
  push cx
  call sub_3611
  call sub_3f46
  call sub_2ba2
  call sub_2c87
  call sub_1c61
  call sub_3271
  inc word ptr [0x527e]
  pop cx
  loop loc_35a8
  mov word ptr [0x5280], 0x163
  mov si, 0x663f
loc_35cb:
  lodsb
  xor ah, ah
  mov [0x527c], ax
  lodsb
  xor ah, ah
  mov [0x527e], ax
  push si
  call sub_3f46
  call sub_2ba2
  call sub_2c87
  call sub_1c61
  call sub_3271
  call sub_0805
  pop si
  cmp byte ptr [0x42b], 0x0
  jnz loc_35fd
  mov ax, word ptr [si]
  cmp ax, 0xffdc
  jnz loc_35cb
  add si, ax
  jmp loc_35cb
loc_35fd:
  mov ax, 0x14f
  mov dx, 0x150
  mov si, 0x527c
  call sub_372f
  call sub_1a59
  mov ax, 0x1
  stc
  ret
sub_32f4 endp

sub_3611 proc near
  mov bx, word ptr [si+0xc]
  inc bx
  inc bx
loc_3616:
  mov ax, word ptr [bx]
  or ax, ax
  jns loc_3620
  add bx, ax
  jmp loc_3616
loc_3620:
  mov word ptr [si+0x4], ax
  mov word ptr [si+0xc], bx
  ret
sub_3611 endp

sub_3627 proc near
  xor ax, ax
  cmp byte ptr [0x6519], 0x1
  jz loc_364e
  inc ax
  cmp byte ptr [0x6517], 0x1
  jnz loc_363b
  jmp loc_3710
loc_363b:
  cmp byte ptr [0x6516], 0x1
  jz loc_3660
  cmp byte ptr [0x6518], 0x1
  jnz loc_364c
  jmp loc_350e
loc_364c:
  clc
  ret
loc_364e:
  call sub_0173
  mov byte ptr [0x419], 0x10
  call sub_378d
  xor ax, ax
  mov [0x64fa], ax
  stc
  ret
loc_3660:
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x1
  call sub_10ff
  call sub_4ae9
  mov word ptr [0x5280], 0xd
  mov word ptr [0x528a], 0xf
  mov cx, 0x3c
loc_3681:
  push cx
  call sub_2c87
  call sub_39c7
  call sub_1c61
  call sub_3271
  call sub_3243
  mov ax, [0x528a]
  dec ax
  cmp ax, 0xfff0
  jge loc_369d
  mov ax, 0xfff0
loc_369d:
  mov [0x528a], ax
  sub word ptr [0x527e], ax
  pop cx
  loop loc_3681
  call sub_378d
  mov ax, [0x64e4]
  mov [0x527c], ax
  mov ax, [0x64e6]
  mov [0x527e], ax
  cmp word ptr [0x64fa], 0x0
  jz loc_36e3
  mov si, 0x52a0
  mov cx, 0x28
loc_36c3:
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  sub bx, 0x38
  cmp bx, 0x1
  ja loc_36de
  mov ax, [0x64f8]
  mov word ptr [si], ax
  mov ax, [0x64fa]
  mov word ptr [si+0x2], ax
  jmp loc_36e3
loc_36de:
  add si, 0x12
  loop loc_36c3
loc_36e3:
  mov byte ptr [0x419], 0x10
  call sub_17eb
  mov ax, 0x0
  call sub_10ff
  call sub_01d9
  mov bl, byte ptr [0x5250]
  xor bh, bh
  mov al, byte ptr [bx+0x508c]
  cbw
  call sub_10ff
  call sub_2d62
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  clc
  ret
loc_3710:
  mov ax, 0x2
  call sub_10ff
  mov byte ptr [0x419], 0x10
  mov byte ptr [0x41a], 0x0
  mov word ptr [0x5280], 0xd
  mov si, 0x528e
  mov ax, 0x14d
  mov dx, 0x14e
sub_3627 endp ; sp-analysis failed

sub_372f proc near
  lea di, [si+0x12]
  mov cl, 0x4
  mov word ptr [si+0x4], ax
  mov ax, [0x5270]
  shl ax, cl
  sub ax, 0x76
  mov word ptr [si], ax
  mov ax, [0x5272]
  shl ax, cl
  add ax, 0x64
  mov word ptr [si+0x2], ax
  mov word ptr [di+0x4], dx
  mov ax, [0x5270]
  shl ax, cl
  add ax, 0x1b6
  mov word ptr [di], ax
  mov ax, [0x5272]
  shl ax, cl
  add ax, 0x64
  mov word ptr [di+0x2], ax
  mov cx, 0x1f
loc_3767:
  push cx
  call sub_2c87
  call sub_1c61
  call sub_3271
  pop cx
  add word ptr [si], 0x8
  sub word ptr [di], 0x8
  loop loc_3767
  call sub_1a2a
  mov byte ptr [0x5250], 0x0
  mov word ptr [0x64fa], 0x0
  mov ax, 0x1
  stc
  ret
sub_372f endp

sub_378d proc near
  push ax
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov di, 0x64fc
  mov cx, 0x2b
  mov al, 0x0
  rep stosb
  mov si, 0x7e97
  mov di, 0x75a3
  mov cx, 0x8f4
  rep movsb
  mov [0x6504], al
  mov [0x6510], al
  mov byte ptr [0x6511], 0x4
  mov [0x650d], al
  mov [0x6512], al
  mov [0x6514], al
  mov [0x6513], al
  mov [0x6505], al
  mov [0x650a], al
  mov [0x6509], al
  mov [0x6502], al
  mov [0x6517], al
  mov [0x6519], al
  mov [0x6516], al
  mov [0x651b], al
  mov [0x6500], al
  mov ax, 0xffff
  mov si, 0x5600
  mov cx, 0x4
loc_37e5:
  mov word ptr [si+0x4], ax
  add si, 0x12
  loop loc_37e5
  call sub_56cc
  call sub_3ee8
  pop ax
  ret
sub_378d endp

sub_37f5 proc near
  cmp byte ptr [0x5287], 0x0
  jnz loc_3820
  cmp byte ptr [0x651c], 0x1
  jnz loc_3820
  cmp word ptr [0x651e], 0x8c
  jc loc_3820
  mov al, 0x1d
  cmp word ptr [0x651e], 0xaf
  jc loc_381d
  xor al, al
  mov word ptr [0x651e], 0x0
loc_381d:
  mov [0x5280], al
loc_3820:
  mov si, 0x528e
  mov cx, 0x29
  mov bx, word ptr [0x64fe]
loc_382a:
  mov ax, word ptr [si+0x4]
  test ah, 0x20
  jz loc_38ab
  cmp ax, 0xffff
  jz loc_38ab
  test bl, 0x7
  jnz loc_386f
  mov dl, al
  sub dl, 0x38
  jz loc_384f
  cmp dl, 0x1
  ja loc_385a
  test byte ptr [0x64fe], 0x3f
  jnz loc_38ab
loc_384f:
  xor dl, 0x1
  add dl, 0x38
  mov byte ptr [si+0x4], dl
  jmp loc_38ab
loc_385a:
  mov dl, al
  sub dl, 0x33
  cmp dl, 0x1
  ja loc_386f
  xor dl, 0x1
  add dl, 0x33
  mov byte ptr [si+0x4], dl
  jmp loc_38ab
loc_386f:
  test bl, 0x1
  jnz loc_38ab
  mov dl, al
  sub dl, 0x36
  cmp dl, 0x1
  ja loc_38ab
  mov dl, 0x37
  cmp byte ptr [si+0x8], 0x0
  jz loc_38a6
  mov dh, 0x1
  cmp byte ptr [0x6511], 0x1
  jbe loc_3891
  xor dh, dh
loc_3891:
  and byte ptr [si+0x8], dh
  dec dl
  cmp al, 0x36
  jz loc_38a6
  mov di, word ptr [si+0x9]
  add word ptr [di+0x2], 0x5
  mov byte ptr [0x6511], 0x3
loc_38a6:
  mov byte ptr [si+0x4], dl
  jmp loc_38ab
loc_38ab:
  add si, 0x12
  dec cx
  jz loc_38b4
  jmp loc_382a
loc_38b4:
  ret
sub_37f5 endp

sub_38b5 proc near
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr [0x64fd], 0x0
  jnz loc_3937
  cmp byte ptr [0x5250], 0x9
  jnz loc_38d6
  mov ax, [0x5292]
  and ah, 0x1f
  sub ax, 0x38
  cmp ax, 0x1
  ja loc_3937
loc_38d6:
  cmp byte ptr [0x5250], 0x10
  jnz loc_38e2
  mov byte ptr [0x6518], 0x1
loc_38e2:
  mov ax, [0x527c]
  and al, 0xf0
  cmp word ptr [0x7e93], ax
  jz loc_38f6
  sub ax, 0x10
  cmp word ptr [0x7e93], ax
  jnz loc_3937
loc_38f6:
  mov ax, [0x527e]
  and al, 0xf0
  cmp word ptr [0x7e95], ax
  jz loc_390a
  sub ax, 0x10
  cmp word ptr [0x7e95], ax
  jnz loc_3937
loc_390a:
  mov ax, 0x4
  call sub_10ff
  call sub_17eb
  call sub_2811
  mov bl, byte ptr [0x5250]
  xor bh, bh
  mov si, 0x523c
  mov al, byte ptr [bx+si]
  inc ax
loc_3922:
  cmp byte ptr [si], al
  jz loc_3929
  inc si
  jmp loc_3922
loc_3929:
  mov ax, si
  sub ax, 0x523c
  mov [0x5250], al
  mov byte ptr [0x6519], 0x1
  ret
loc_3937:
  cmp byte ptr [0x6510], 0x0
  jz loc_395d
  mov cl, 0x4
  mov ax, [0x527e]
  sar ax, cl
  mov dh, al
  mov ax, [0x527c]
  sar ax, cl
  mov dl, al
  mov si, 0x7d3f
  mov cx, 0x14
loc_3954:
  cmp word ptr [si], dx
  jz loc_395e
  add si, 0x7
  loop loc_3954
loc_395d:
  ret
loc_395e:
  mov word ptr [0x5282], 0x0
  mov word ptr [0x528a], 0x0
  call sub_2811
  push word ptr [0x7d3d]
  push si
  mov word ptr [0x7d3d], 0xec
  mov ax, word ptr [si+0x4]
  mov cl, 0x4
  mov dl, al
  xor dh, dh
  shl dx, cl
  mov word ptr [0x527c], dx
  mov dl, ah
  xor dh, dh
  shl dx, cl
  mov word ptr [0x527e], dx
  mov ax, word ptr [si+0x2]
loc_3994:
  cmp byte ptr [0x5272], ah
  jz loc_39a6
  jc loc_39a1
  call sub_2911
  jmp loc_3994
loc_39a1:
  call sub_294c
  jmp loc_3994
loc_39a6:
  cmp byte ptr [0x5270], al
  jz loc_39b8
  jc loc_39b3
  call sub_2994
  jmp loc_39a6
loc_39b3:
  call sub_29b5
  jmp loc_39a6
loc_39b8:
  pop si
  pop word ptr [0x7d3d]
  mov al, byte ptr [si+0x6]
  mov [0x6502], al
  call sub_276f
  ret
sub_38b5 endp

sub_39c7 proc near
  cmp byte ptr [0x6511], 0x0
  jnz loc_39d1
  jmp loc_3d96
loc_39d1:
  mov es, word ptr [0x526c]
  mov word ptr [0x64eb], 0x28
  mov si, 0x52a0
  mov cl, 0x4
loc_39e0:
  cmp word ptr [si+0x4], -0x1
  jnz loc_39e9
  jmp loc_3d8a
loc_39e9:
  mov ax, word ptr [si]
  cmp ax, 0x8
  jg loc_39fa
  mov word ptr [si+0x6], 0x20
  mov word ptr [si+0xe], 0x0
loc_39fa:
  cmp ax, 0xff8
  jl loc_3a09
  mov word ptr [si+0x6], 0xffe0
  mov word ptr [si+0xe], 0x0
loc_3a09:
  mov ah, byte ptr [si+0x4]
  mov al, ah
  test word ptr [0x64fe], 0x3
  jnz loc_3a42
  cmp word ptr [si+0xe], 0x0
  jle loc_3a42
  cmp byte ptr [0x6503], 0x2
  jz loc_3a42
  sub al, 0x31
  jz loc_3a30
  dec al
  jnz loc_3a42
  mov word ptr [si+0x6], 0x0
loc_3a30:
  sar word ptr [si+0x6], 1
  inc word ptr [si+0x4]
  mov byte ptr [0x6503], 0x1
  mov byte ptr [0x6504], 0xc8
  jmp loc_3a85
loc_3a42:
  sub ah, 0x33
  cmp ah, 0x1
  ja loc_3a85
  mov byte ptr [0x6511], 0x4
  cmp byte ptr [0x6503], 0x0
  jz loc_3a6f
  xor dx, dx
  mov word ptr [si+0xc], dx
  mov ax, [0x527e]
  sub ax, 0x8
  cmp word ptr [si+0x2], ax
  jz loc_3a6c
  mov dl, 0x10
  jl loc_3a6c
  neg dx
loc_3a6c:
  mov word ptr [si+0xe], dx
loc_3a6f:
  cmp byte ptr [0x6504], 0x0
  jnz loc_3a85
  mov word ptr [si+0x4], 0x31
  mov word ptr [si+0x6], 0x0
  mov byte ptr [0x6503], 0x2
loc_3a85:
  cmp word ptr [si+0x6], 0x0
  jnz loc_3a8e
  jmp loc_3b25
loc_3a8e:
  mov ax, word ptr [si+0x2]
  sar ax, cl
  test byte ptr [si+0x2], 0xf
  jnz loc_3a9a
  dec ax
loc_3a9a:
  xchg al, ah
  mov di, word ptr [si]
  sar di, cl
  add di, ax
  mov bx, 0x72a3
  mov al, byte ptr es:[di]
  xlat ds
  and al, 0x1
  jnz loc_3ade
  mov ax, word ptr [si]
  mov dx, word ptr [si+0x6]
  sar dx, cl
  add dx, ax
  sar dx, cl
  sar ax, cl
  cmp ax, dx
  jz loc_3ae8
  mov ax, 0x1
  test byte ptr [si+0x7], 0x80
  jz loc_3ac9
  neg ax
loc_3ac9:
  add di, ax
  mov dx, word ptr [si]
  sar dx, cl
  add ax, dx
  cmp ax, 0x100
  jnc loc_3ade
  mov al, byte ptr es:[di]
  xlat ds
  and al, 0x1
  jz loc_3ae8
loc_3ade:
  neg word ptr [si+0x6]
  mov ax, word ptr [si+0x6]
  sar ax, cl
  add word ptr [si], ax
loc_3ae8:
  mov byte ptr [0x6511], 0x4
  mov ax, word ptr [si+0xe]
  or ax, ax
  jns loc_3af6
  neg ax
loc_3af6:
  mov dx, 0x3
  cmp ax, 0x10
  jc loc_3b00
  mov dl, 0x1
loc_3b00:
  mov ax, word ptr [si+0x6]
  or ax, ax
  jns loc_3b09
  neg dx
loc_3b09:
  mov bp, ax
  sar ax, cl
  add word ptr [si], ax
  mov ax, bp
  sub ax, dx
  mov dx, ax
  or ax, ax
  jns loc_3b1b
  neg ax
loc_3b1b:
  cmp ax, 0x10
  jnc loc_3b22
  xor dx, dx
loc_3b22:
  mov word ptr [si+0x6], dx
loc_3b25:
  mov ax, word ptr [si+0x2]
  sar ax, cl
  mov [0x64ed], ax
  xchg al, ah
  mov di, word ptr [si]
  sar di, cl
  add di, ax
  cmp word ptr [si+0xe], 0x0
  jge loc_3b8a
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov al, byte ptr [bx+0x6bf8]
  shr al, cl
  cbw
  inc ax
  xchg al, ah
  sub di, ax
  mov bx, 0x74a3
  mov al, byte ptr es:[di]
  xlat ds
  and al, 0x7f
  jnz loc_3b78
  mov ax, word ptr [si+0xe]
  sar ax, cl
  add ax, word ptr [si+0x2]
  sub ax, word ptr [0x64ed]
  jnz loc_3b6b
  jmp loc_3d5a
loc_3b6b:
  mov al, byte ptr es:[di+0xff00]
  xlat ds
  and al, 0x7f
  jnz loc_3b78
  jmp loc_3d5a
loc_3b78:
  mov word ptr [si+0xe], 0x0
  push si
  call sub_5133
  jnz loc_3b87
  and byte ptr [si+0x2], 0xf0
loc_3b87:
  jmp loc_3d8a
loc_3b8a:
  mov ax, word ptr [si+0x4]
  mov dx, ax
  and dh, 0x1f
  test byte ptr [si+0xb], 0x1
  jnz loc_3ba8
  mov bx, dx
  test byte ptr [bx+0x6f19], 0x8
  jz loc_3bb8
  cmp word ptr [si+0xe], 0xa0
  jl loc_3bb8
loc_3ba8:
  test ah, 0x20
  jz loc_3bb0
  jmp loc_3d5a
loc_3bb0:
  mov word ptr [si+0x4], 0xffff
  jmp loc_3d8a
loc_3bb8:
  mov bx, 0x72a3
  mov al, byte ptr es:[di]
  mov ah, al
  xlat ds
  xchg ah, al
  mov bx, 0x73a3
  xlat ds
  cmp word ptr [si+0x2], 0x6
  jg loc_3bd1
  xor al, al
  jmp loc_3be8
loc_3bd1:
  mov dl, byte ptr [0x508b]
  xor dh, dh
  shl dx, cl
  cmp word ptr [si+0x2], dx
  jl loc_3be8
  xor al, al
  add dx, 0x40
  cmp word ptr [si+0x2], dx
  jge loc_3bfe
loc_3be8:
  cmp al, 0x9
  jz loc_3bfe
  cmp al, 0x8
  jnz loc_3c03
  mov dx, word ptr [si+0x4]
  and dh, 0x1f
  cmp dx, 0x27
  jnz loc_3bfe
  jmp loc_3b78
loc_3bfe:
  mov word ptr [si+0x4], 0xffff
loc_3c03:
  cmp al, 0x6
  jz loc_3c13
  and ah, 0x1
  or al, ah
  and al, 0x7
  jz loc_3c13
  jmp loc_3b78
loc_3c13:
  mov dx, word ptr [si+0xe]
  sar dx, cl
  add dx, word ptr [si+0x2]
  sar dx, cl
  sub dx, word ptr [0x64ed]
  jz loc_3c70
  mov word ptr [0x64ed], dx
  push bx
  mov bx, word ptr [si+0x4]
  call sub_5045
  pop bx
  jc loc_3c7b
  mov dx, word ptr [0x64ed]
loc_3c35:
  add di, 0x100
  mov al, byte ptr es:[di]
  push bx
  mov bx, 0x72a3
  mov ah, al
  xlat ds
  xchg ah, al
  pop bx
  xlat ds
  cmp al, 0x9
  jz loc_3bfe
  cmp al, 0x8
  jnz loc_3c5d
  mov dx, word ptr [si+0x4]
  and dh, 0x1f
  cmp dx, 0x27
  jnz loc_3c5d
  jmp loc_3ced
loc_3c5d:
  cmp al, 0x6
  jz loc_3c6d
  and ah, 0x1
  or al, ah
  and al, 0x7
  jz loc_3c6d
  jmp loc_3ced
loc_3c6d:
  dec dx
  jnz loc_3c35
loc_3c70:
  mov bx, word ptr [si+0x4]
  call sub_5045
  jc loc_3c7b
  jmp loc_3d5a
loc_3c7b:
  mov word ptr [si+0xc], 0x0
  mov di, ax
  push si
  call sub_5133
  jnz loc_3cd4
  push di
  call sub_5133
  jnz loc_3c9e
  mov word ptr [si+0x2], dx
  mov word ptr [si+0xe], 0x0
  mov word ptr [si+0xc], 0x0
  jmp loc_3d8a
loc_3c9e:
  or byte ptr [di+0x8], 0x1
  mov word ptr [di+0x9], si
  mov ax, word ptr [si+0xe]
  neg ax
  sar ax, 1
  mov bx, ax
  add ax, 0x10
  jns loc_3cb8
  add bx, 0x20
  js loc_3cc3
loc_3cb8:
  mov word ptr [si+0xe], 0x0
  mov word ptr [si+0x2], dx
  jmp loc_3d8a
loc_3cc3:
  mov word ptr [di+0xe], bx
  mov word ptr [si+0xe], ax
  mov ax, word ptr [si+0x6]
  sar ax, 1
  mov word ptr [di+0x6], ax
  jmp loc_3d5a
loc_3cd4:
  push di
  call sub_5133
  jnz loc_3ceb
  mov word ptr [si+0x2], dx
  cmp word ptr [si+0xe], 0x10
  jnc loc_3d3f
  mov word ptr [si+0xe], 0x0
  jmp loc_3d8a
loc_3ceb:
  jmp loc_3c9e
loc_3ced:
  push si
  call sub_5133
  jnz loc_3d37
  mov word ptr [si+0xe], 0x0
  and byte ptr [si+0x2], 0xf0
  add word ptr [si+0x2], 0x10
  mov al, byte ptr [si+0x4]
  sub al, 0x31
  cmp al, 0x3
  ja loc_3d12
  mov byte ptr [si+0x4], 0x31
  mov byte ptr [0x6503], 0x0
loc_3d12:
  test byte ptr [si+0x5], 0x20
  jz loc_3d8a
  cmp word ptr [0x5292], -0x1
  jnz loc_3d8a
  mov byte ptr [0x6505], 0x20
  mov ax, word ptr [si+0x2]
  mov [0x5290], ax
  mov ax, word ptr [si]
  mov [0x528e], ax
  mov word ptr [0x5292], 0x2e
  jmp loc_3d8a
loc_3d37:
  and byte ptr [si+0x2], 0xf0
  add word ptr [si+0x2], 0x10
loc_3d3f:
  mov byte ptr [0x6511], 0x4
  mov word ptr [si+0xc], 0x0
  mov ax, word ptr [si+0xe]
  neg ax
  add ax, 0x30
  jl loc_3d55
  xor ax, ax
loc_3d55:
  mov word ptr [si+0xe], ax
  jmp loc_3d8a
loc_3d5a:
  mov dl, 0xf
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  cmp bl, 0x65
  jnc loc_3d6b
  mov dl, byte ptr [bx+0x6f60]
loc_3d6b:
  mov ax, word ptr [si+0xe]
  sar ax, cl
  jz loc_3d77
  mov byte ptr [0x6511], 0x4
loc_3d77:
  add word ptr [si+0x2], ax
  cmp al, dl
  jge loc_3d87
  add word ptr [si+0xe], 0x10
  jle loc_3d87
  inc word ptr [si+0xc]
loc_3d87:
  call sub_3d97
loc_3d8a:
  add si, 0x12
  dec word ptr [0x64eb]
  jz loc_3d96
  jmp loc_39e0
loc_3d96:
  ret
sub_39c7 endp

sub_3d97 proc near
  push ax
  push bx
  push dx
  cmp word ptr [si+0xc], 0xa
  jnc loc_3da3
  jmp loc_3e24
loc_3da3:
  cmp word ptr [0x528a], 0xc0
  jge loc_3e24
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_3db5
  neg ax
loc_3db5:
  cmp ax, 0x20
  jnc loc_3e24
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_3dc3
  neg ax
loc_3dc3:
  cmp ax, 0x20
  jnc loc_3e24
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf7]
  mov ax, word ptr [si]
  mov dx, word ptr [0x527c]
  cmp ax, dx
  jle loc_3de1
  xchg ax, dx
  mov bl, 0x18
loc_3de1:
  xor bh, bh
  add ax, bx
  cmp ax, dx
  jl loc_3e24
  mov ax, word ptr [si+0x2]
  mov dx, word ptr [0x527e]
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf8]
  dec bl
  cmp ax, dx
  jge loc_3e05
  xchg ax, dx
  mov bl, 0x20
loc_3e05:
  xor bh, bh
  sub ax, bx
  cmp ax, dx
  jge loc_3e24
  mov al, 0x5
  call sub_11e6
  mov byte ptr [0x6513], 0x18
  test byte ptr [si+0xb], 0x2
  jz loc_3e24
  call sub_59cc
  and byte ptr [si+0xb], 0xfd
loc_3e24:
  pop dx
  pop bx
  pop ax
  ret
sub_3d97 endp

sub_3e28 proc near
  mov ax, 0x168f
  mov ds, ax
  mov bp, 0xffff
  mov word ptr [0x564c], bp
  mov word ptr [0x565e], bp
  mov word ptr [0x5670], bp
  mov word ptr [0x5682], bp
  mov si, 0x7dcb
  mov di, 0x5648
  mov ax, [0x5270]
  mov dx, word ptr [0x5272]
  mov cl, 0x4
  shl ax, cl
  shl dx, cl
  mov cx, 0xa
loc_3e56:
  cmp word ptr [si+0x4], bp
  jz loc_3ec7
  push ax
  push dx
  mov al, byte ptr [si+0x7]
  cbw
  mov dl, byte ptr [si+0x6]
  cmp dl, 0x0
  jnz loc_3e6e
  sub word ptr [si+0x2], ax
  jmp loc_3ed0
loc_3e6e:
  cmp dl, 0x2
  jnz loc_3e78
  add word ptr [si+0x2], ax
  jmp loc_3ed0
loc_3e78:
  cmp dl, 0x1
  jnz loc_3e81
  add word ptr [si], ax
  jmp loc_3ed0
loc_3e81:
  cmp dl, 0x3
  jnz loc_3e8a
  sub word ptr [si], ax
  jmp loc_3ed0
loc_3e8a:
  pop dx
  pop ax
  mov bx, word ptr [si]
  add bx, 0x10
  sub bx, ax
  jc loc_3ec7
  sub bx, 0x20
  cmp bx, 0x140
  jg loc_3ec7
  mov bx, word ptr [si+0x2]
  sub bx, dx
  jc loc_3ec7
  sub bx, 0x10
  cmp bx, 0xc0
  jg loc_3ec7
  mov bx, word ptr [si+0x4]
  add bx, 0x1e
  mov word ptr [di+0x4], bx
  mov bx, word ptr [si]
  mov word ptr [di], bx
  mov bx, word ptr [si+0x2]
  mov word ptr [di+0x2], bx
  mov word ptr [di+0x9], si
  add di, 0x12
loc_3ec7:
  add si, 0x14
  dec cx
  jz loc_3ecf
  jmp loc_3e56
loc_3ecf:
  ret
loc_3ed0:
  inc word ptr [si+0x11]
  mov ax, word ptr [si+0x11]
  cmp word ptr [si+0xa], ax
  jnz loc_3e8a
  xor dl, 0x2
  mov word ptr [si+0x11], 0x0
  mov byte ptr [si+0x6], dl
  jmp loc_3e8a
sub_3e28 endp

sub_3ee8 proc near
  push bx
  push di
  push si
  mov ax, 0x168f
  mov ds, ax
  mov es, ax
  mov di, 0x527c
  mov cx, 0x20a
  xor ax, ax
  rep stosw
  mov di, 0x527c
  mov cx, 0x3a
loc_3f02:
  mov word ptr [di+0x4], 0xffff
  add di, 0x12
  loop loc_3f02
  mov si, 0x52a0
  mov di, 0x75a3
  mov cx, 0x28
loc_3f15:
  mov ax, word ptr [di]
  mov word ptr [si+0x4], ax
  mov ax, word ptr [di+0x2]
  mov word ptr [si], ax
  mov ax, word ptr [di+0x4]
  mov word ptr [si+0x2], ax
  mov byte ptr [si+0xb], 0x0
  add si, 0x12
  add di, 0x6
  loop loc_3f15
  mov byte ptr [0x6511], 0x4
  mov ax, [0x7695]
  mov [0x527c], ax
  mov ax, [0x7697]
  mov [0x527e], ax
  pop si
  pop di
  pop bx
  ret
sub_3ee8 endp

sub_3f46 proc near
  mov ax, 0x168f
  mov ds, ax
  inc byte ptr [0x64fc]
  test byte ptr [0x64fc], 0x3
  jnz loc_3f66
  mov ax, [0x64f6]
  inc ah
  cmp ax, 0x63e4
  jnz loc_3f63
  sub ah, 0x3
loc_3f63:
  mov [0x64f6], ax
loc_3f66:
  cmp byte ptr [0x6502], 0x0
  jnz loc_3f73
  call sub_403c
  call sub_3f74
loc_3f73:
  ret
sub_3f46 endp

sub_3f74 proc near
  mov ax, 0x168f
  mov ds, ax
  cmp word ptr [0x528a], 0x0
  jnz loc_3f85
  mov byte ptr [0x6521], 0x0
loc_3f85:
  mov dx, word ptr [0x527e]
  mov cl, 0x4
  sar dx, cl
  sub dx, word ptr [0x5272]
  cmp byte ptr [0x6521], 0x0
  jnz loc_3fcf
  cmp word ptr [0x528a], 0x0
  jnz loc_3fa6
  cmp byte ptr [0x650d], 0x0
  jz loc_3fb8
loc_3fa6:
  mov ax, 0x3
  cmp dx, 0xa
  jge loc_3fc8
  mov ax, 0x9
  cmp dx, 0x2
  jg loc_3fcf
  jmp loc_3fc8
loc_3fb8:
  mov ax, 0xa
  cmp dx, 0xb
  jge loc_3fc8
  mov ax, 0x9
  cmp dx, 0x2
  jg loc_3fcf
loc_3fc8:
  mov [0x6524], ax
  inc byte ptr [0x6521]
loc_3fcf:
  mov ax, [0x7693]
  add ax, 0xc
  shl ax, cl
  cmp word ptr [0x527e], ax
  ja loc_3fe8
  mov bx, word ptr [0x5272]
  dec bx
  cmp word ptr [0x7693], bx
  jl loc_4031
loc_3fe8:
  mov ax, [0x7693]
  sub ax, word ptr [0x5272]
  cmp ax, 0x5
  jnc loc_4005
  mov ax, [0x7693]
  add ax, 0xc
  shl ax, cl
  sub ax, word ptr [0x527e]
  cmp ax, 0x70
  jc loc_402a
loc_4005:
  cmp byte ptr [0x6521], 0x0
  jz loc_403b
  cmp word ptr [0x6524], dx
  jz loc_4036
  jg loc_4031
  mov ax, [0x7693]
  mov dx, ax
  add dx, 0xc
  shl dx, cl
  cmp word ptr [0x527e], dx
  ja loc_402a
  cmp word ptr [0x5272], ax
  ja loc_4036
loc_402a:
  call sub_294c
  jc loc_4036
  jmp loc_403b
loc_4031:
  call sub_2911
  jnc loc_403b
loc_4036:
  mov byte ptr [0x6521], 0x0
loc_403b:
  ret
sub_3f74 endp

sub_403c proc near
  mov ax, 0x168f
  mov ds, ax
  mov dx, word ptr [0x527c]
  mov cl, 0x4
  sar dx, cl
  sub dx, word ptr [0x5270]
  cmp byte ptr [0x6520], 0x0
  jz loc_4057
  jmp loc_40d7
loc_4057:
  cmp word ptr [0x651e], 0x16
  jc loc_40c6
  mov al, [0x5287]
  and al, 0xf
  cmp al, 0x1
  jnz loc_40a1
  mov ax, [0x5282]
  or ax, ax
  jns loc_4070
  neg ax
loc_4070:
  cmp ax, 0x40
  jz loc_407e
  cmp word ptr [0x5280], 0x0
  jl loc_409c
  jmp loc_408a
loc_407e:
  cmp word ptr [0x5282], 0x0
  js loc_4097
  cmp dx, 0xd
  jl loc_40d7
loc_408a:
  mov ax, 0x2
loc_408d:
  mov [0x6522], ax
  mov byte ptr [0x6520], 0x1
  jmp loc_40d7
loc_4097:
  cmp dx, 0x7
  jg loc_40d7
loc_409c:
  mov ax, 0x12
  jmp loc_408d
loc_40a1:
  mov ax, [0x5282]
  or ax, word ptr [0x528a]
  jnz loc_40c6
  cmp word ptr [0x651e], 0x21
  jnz loc_40c6
  call sub_40fa
  mov [0x6522], ax
  jmp loc_40bf
loc_40b9:
  mov word ptr [0x6522], 0xa
loc_40bf:
  mov byte ptr [0x6520], 0x1
  jmp loc_40d7
loc_40c6:
  cmp byte ptr [0x6520], 0x0
  jnz loc_40d7
  cmp dx, 0x12
  jg loc_40b9
  cmp dx, 0x2
  jl loc_40b9
loc_40d7:
  cmp byte ptr [0x6520], 0x0
  jz loc_40f9
  cmp word ptr [0x6522], dx
  jz loc_40f4
  jg loc_40ed
  call sub_29b5
  jc loc_40f4
  jmp loc_40f9
loc_40ed:
  call sub_2994
  jc loc_40f4
  jmp loc_40f9
loc_40f4:
  mov byte ptr [0x6520], 0x0
loc_40f9:
  ret
sub_403c endp

sub_40fa proc near
  push bx
  push cx
  push dx
  push si
  mov dx, word ptr [0x527c]
  mov si, 0x5570
  mov cx, 0x8
  mov ax, 0xa
loc_410b:
  cmp word ptr [si+0x4], -0x1
  jz loc_4133
  xor bx, bx
  cmp word ptr [si], dx
  adc bl, 0x0
  mov bh, byte ptr [0x5281]
  rol bh, 1
  and bh, 0x1
  xor bl, bh
  jz loc_4133
  mov bx, word ptr [si]
  sub bx, dx
  jns loc_412d
  neg bx
loc_412d:
  cmp bx, 0xc8
  jc loc_4146
loc_4133:
  add si, 0x12
  loop loc_410b
  mov ax, 0x3
  test word ptr [0x5281], 0x80
  jz loc_4146
  mov ax, 0x11
loc_4146:
  pop si
  pop dx
  pop cx
  pop bx
  ret
sub_40fa endp

sub_414b proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  cmp byte ptr [0x6516], 0x0
  jnz loc_4171
  cmp byte ptr [0x47b], 0x0
  jz loc_4171
  call sub_4dc0
  dec byte ptr [0x6516]
  jmp loc_447a
loc_4171:
  cmp byte ptr [0x47c], 0x0
  jz loc_4187
  mov byte ptr [0x6517], 0x1
loc_417d:
  cmp byte ptr [0x47c], 0x0
  jz loc_417d
  jmp loc_447a
loc_4187:
  cmp byte ptr [0x452], 0x0
  jz loc_4193
  mov byte ptr [0x6506], 0x32
loc_4193:
  cmp byte ptr [0x47e], 0x0
  jz loc_41ad
loc_419a:
  cmp byte ptr [0x47e], 0x0
  jnz loc_419a
  call sub_27df
  call sub_01f8
  call sub_03f2
  call sub_03ae
loc_41ad:
  call sub_18af
  mov es, word ptr [0x526c]
  mov si, 0x527c
  call sub_4b49
  call sub_0805
  mov ax, 0x550b
  cmp byte ptr [0x6513], 0x0
  jz loc_41ca
  jmp loc_428a
loc_41ca:
  mov al, 0xc
  add al, byte ptr [0x6501]
  cmp byte ptr [0x6514], 0x0
  jz loc_41da
  jmp loc_428a
loc_41da:
  mov byte ptr [0x6501], 0x0
  mov al, 0xaa
  cmp byte ptr [0x42f], 0x0
  jz loc_41eb
  mov ax, 0x101
loc_41eb:
  cmp byte ptr [0x430], 0x0
  jz loc_41f5
  mov ax, 0xff01
loc_41f5:
  cmp byte ptr [0x650d], 0x0
  jz loc_4200
  mov al, 0x6
  jmp loc_4242
loc_4200:
  cmp byte ptr [0x650e], 0x0
  jnz loc_4215
  cmp byte ptr [0x650f], 0x6
  jz loc_4220
  cmp byte ptr [0x42e], 0x0
  jz loc_4220
loc_4215:
  cmp ah, 0x55
  jz loc_421e
  mov al, 0x3
  jmp loc_4220
loc_421e:
  mov al, 0x5
loc_4220:
  cmp byte ptr [0x650e], 0x0
  jnz loc_4242
  cmp byte ptr [0x42d], 0x0
  jz loc_4242
  cmp byte ptr [0x650f], 0x0
  jnz loc_4242
  mov al, 0x2
  cmp byte ptr [si+0xb], 0x5
  jnz loc_4242
  mov byte ptr [0x6512], 0x64
loc_4242:
  cmp al, 0xaa
  jnz loc_4248
  xor al, al
loc_4248:
  cmp byte ptr [0x42b], 0x0
  jz loc_4280
  cmp byte ptr [0x650e], 0x0
  jnz loc_4280
  cmp byte ptr [0x650a], 0x0
  jnz loc_428a
  cmp al, 0x3
  jz loc_4265
  cmp al, 0x5
  jnz loc_426e
loc_4265:
  mov byte ptr [0x650b], 0x0
  mov al, 0x7
  jmp loc_428a
loc_426e:
  cmp byte ptr [0x6509], 0x0
  jz loc_428a
  cmp byte ptr [0x650b], 0x0
  jz loc_428a
  mov al, 0x8
  jmp loc_428a
loc_4280:
  mov byte ptr [0x650b], 0x1
  mov byte ptr [0x650c], 0x0
loc_428a:
  add al, byte ptr [0x6509]
  cmp ah, 0x55
  jnz loc_4296
  mov ah, byte ptr [si+0xa]
loc_4296:
  mov dl, byte ptr [0x430]
  or dl, byte ptr [0x42f]
  mov byte ptr [0x6507], dl
  mov dl, byte ptr [0x42d]
  or dl, byte ptr [0x42e]
  mov byte ptr [0x6508], dl
  cwd
  or dl, ah
  cmp word ptr [si+0x9], dx
  jz loc_42c1
  mov word ptr [si+0x9], dx
loc_42b9:
  mov word ptr [0x651e], 0x1
  jmp loc_42e1
loc_42c1:
  cmp al, 0x1
  jz loc_42c9
  cmp al, 0x0
  jnz loc_42d2
loc_42c9:
  cmp byte ptr [0x6512], 0x0
  jz loc_42d2
  add al, 0x9
loc_42d2:
  cmp byte ptr [si+0xb], al
  jnz loc_42b9
  add word ptr [0x651e], 0x1
  sbb word ptr [0x651e], 0x0
loc_42e1:
  cbw
  mov bx, ax
  shl bx, 1
  call word ptr [bx+0x6efb]
  mov ax, word ptr [si+0x6]
  mov cl, 0x4
  sar ax, cl
  add word ptr [si], ax
  cmp word ptr [si], 0x8
  jl loc_42fe
  cmp word ptr [si], 0xff8
  jc loc_4300
loc_42fe:
  sub word ptr [si], ax
loc_4300:
  mov ax, word ptr [si+0xe]
  mov cl, 0x4
  sar ax, cl
  add word ptr [si+0x2], ax
  call sub_4484
  mov al, [0x650a]
  or al, al
  jz loc_4378
  mov cl, 0x4
  mov ax, [0x5294]
  sar ax, cl
  add ax, word ptr [0x528e]
  cmp ax, 0x1000
  jnc loc_436b
  mov bx, word ptr [0x5270]
  shl bx, cl
  sub bx, 0x28
  cmp bx, ax
  jg loc_436b
  add bx, 0x190
  cmp bx, ax
  jl loc_436b
  mov [0x528e], ax
  mov ax, [0x529c]
  sar ax, cl
  add ax, word ptr [0x5290]
  mov bl, byte ptr [0x508b]
  xor bh, bh
  shl bx, cl
  cmp ax, bx
  jnc loc_436b
  mov bx, word ptr [0x5272]
  shl bx, cl
  sub bx, 0x14
  cmp bx, ax
  jg loc_436b
  add bx, 0xe8
  cmp bx, ax
  jl loc_436b
  mov [0x5290], ax
  jmp loc_4376
loc_436b:
  mov word ptr [0x5292], 0xffff
  mov byte ptr [0x650a], 0x0
loc_4376:
  jmp loc_43ea
loc_4378:
  cmp byte ptr [0x6509], 0x0
  jz loc_43ea
  mov bx, word ptr [0x5280]
  mov dx, bx
  and dh, 0x1f
  mov al, [0x5287]
  cmp byte ptr [0x650d], 0x0
  jnz loc_43ab
  cmp al, 0x15
  jz loc_439a
  cmp al, 0x17
  jnz loc_43ab
loc_439a:
  mov ax, word ptr [si+0x2]
  sub ax, 0x4
  mov [0x5290], ax
  call sub_5122
  mov [0x528e], ax
  jmp loc_43ea
loc_43ab:
  and al, 0xf
  cmp dx, 0xe
  jz loc_43ba
  cmp al, 0x7
  jz loc_43ea
  cmp al, 0x8
  jz loc_43ea
loc_43ba:
  mov ax, [0x527c]
  inc ax
  inc ax
  sub dx, 0x17
  jc loc_43d4
  cmp dx, 0x1
  ja loc_43d4
  sub ax, 0xa
  test bh, 0x80
  jz loc_43d4
  add ax, 0x12
loc_43d4:
  and bh, 0x1f
  mov [0x528e], ax
  mov ax, [0x527e]
  shl bx, 1
  sub al, byte ptr [bx+0x6bf8]
  sbb ah, 0x0
  inc ax
  mov [0x5290], ax
loc_43ea:
  cmp byte ptr [0x6515], 0x0
  jz loc_43fd
  dec byte ptr [0x6515]
  jnz loc_43fd
  mov word ptr [0x5292], 0xffff
loc_43fd:
  mov dx, 0x1
  sub byte ptr [0x651b], dl
  adc byte ptr [0x651b], dh
  sub byte ptr [0x6516], dl
  adc byte ptr [0x6516], dh
  sub byte ptr [0x6504], dl
  adc byte ptr [0x6504], dh
  sub byte ptr [0x6510], dl
  adc byte ptr [0x6510], dh
  sub byte ptr [0x6511], dl
  adc byte ptr [0x6511], dh
  sub byte ptr [0x6512], dl
  adc byte ptr [0x6512], dh
  sub byte ptr [0x6514], dl
  adc byte ptr [0x6514], dh
  cmp word ptr [0x528a], 0x0
  jnz loc_4447
  sub byte ptr [0x6513], dl
  adc byte ptr [0x6513], dh
loc_4447:
  mov ax, [0x5282]
  or ax, word ptr [0x528a]
  jnz loc_4454
  mov byte ptr [0x6514], dh
loc_4454:
  sub byte ptr [0x6505], dl
  adc byte ptr [0x6505], dh
  jz loc_447a
  test byte ptr [0x6505], 0x3
  jnz loc_447a
  inc word ptr [0x5292]
  cmp byte ptr [0x5292], 0x31
  jnz loc_447a
  mov word ptr [0x5292], 0xffff
  mov byte ptr [0x6505], dh
loc_447a:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_414b endp

sub_4484 proc near
  push ax
  push cx
  push dx
  mov si, 0x527c
  mov ax, [0x527e]
  mov cl, 0x4
  sar ax, cl
  dec ax
  xchg al, ah
  mov bx, word ptr [0x5280]
  and bh, 0x1f
  shl bx, 1
  mov dh, byte ptr [bx+0x6bf8]
  mov bx, 0x8
  cmp word ptr [0x5282], 0x0
  jg loc_44b1
  jl loc_44af
  xor bx, bx
loc_44af:
  neg bx
loc_44b1:
  push ax
  push bx
  mov bx, word ptr [0x527c]
  sar bx, cl
  add bx, ax
  cmp word ptr [0x527e], 0x0
  jle loc_44d9
  mov al, [0x508b]
  xor ah, ah
  inc ax
  shl ax, 1
  shl ax, 1
  shl ax, 1
  shl ax, 1
  cmp word ptr [0x527e], ax
  jle loc_44d9
  call sub_4dc0
loc_44d9:
  mov byte ptr [0x6526], 0x0
  mov al, [0x527c]
  and al, 0xf
  sub al, 0x4
  sbb bx, 0x0
  mov bp, bx
  call sub_4561
  cmp byte ptr [0x6526], 0x1
  jnz loc_4539
  add al, 0x8
  adc bx, 0x0
  cmp al, 0xf
  cmc
  adc bx, 0x0
  cmp bx, bp
  jz loc_4506
  call sub_4561
loc_4506:
  cmp byte ptr [0x6526], 0x1
  jnz loc_4539
  cmp byte ptr [0x6510], 0x0
  jnz loc_4536
  cmp byte ptr [0x6513], 0x0
  jnz loc_4536
  call sub_4657
  cmp byte ptr [0x6526], 0x1
  jnz loc_4539
  call sub_4f1f
  cmp byte ptr [0x6526], 0x1
  jz loc_4536
  mov byte ptr [0x5284], 0x0
  jmp loc_4539
loc_4536:
  call sub_4c65
loc_4539:
  pop bx
  pop ax
  cmp word ptr [0x527e], 0x0
  jle loc_455d
  add bx, word ptr [0x527c]
  sar bx, cl
  add bx, ax
  call sub_4617
  jmp loc_4552
loc_454f:
  call sub_4631
loc_4552:
  sub bx, 0x100
  jc loc_455d
  sub dh, 0x10
  ja loc_454f
loc_455d:
  pop dx
  pop cx
  pop ax
  ret
sub_4484 endp

sub_4561 proc near
  push ax
  push bx
  push bp
  mov byte ptr [0x651c], 0x0
  mov byte ptr [0x650e], 0x0
  mov byte ptr [0x650d], 0x0
  cmp word ptr [0x527e], -0x1
  jg loc_4585
  call sub_4c65
  mov byte ptr [0x6526], 0xff
  jmp loc_4613
loc_4585:
  mov al, [0x5287]
  and al, 0xf
  cmp al, 0x2
  jz loc_45a5
  push bx
  lea di, [bx+0x100]
  mov al, byte ptr es:[di]
  mov bx, 0x73a3
  xlat ds
  xor ah, ah
  mov bx, ax
  shl bx, 1
  call word ptr [bx+0x727d]
  pop bx
loc_45a5:
  sub bx, 0x100
  jc loc_4613
  cmp word ptr [0x528a], 0x0
  jg loc_4613
  mov di, bx
  mov ah, byte ptr es:[bx]
  mov al, byte ptr es:[bx+0x100]
  mov bx, 0x72a3
  xlat ds
  xchg al, ah
  mov bx, 0x74a3
  xlat ds
  and al, 0x7f
  mov bl, al
  xor bh, bh
  shl bx, 1
  push ax
  call word ptr [bx+0x7299]
  pop ax
  and ah, 0x1
  jz loc_4613
  cmp word ptr [0x527e], 0x0
  jle loc_4613
  mov dx, 0xffff
  mov bx, 0x72a3
  cmp word ptr [0x5282], 0x0
  jg loc_45ef
  neg dx
loc_45ef:
  push di
  add di, dx
  mov al, byte ptr es:[di+0x100]
  xlat ds
  or al, al
  jz loc_460c
  neg dx
  add di, dx
  add di, dx
  mov al, byte ptr es:[di+0x100]
  xlat ds
  or al, al
  jnz loc_4612
loc_460c:
  shl dx, 1
  add word ptr [0x527c], dx
loc_4612:
  pop di
loc_4613:
  pop bp
  pop bx
  pop ax
  ret
sub_4561 endp

sub_4617 proc near
  push bx
  push dx
  push di
  mov di, bx
  mov al, byte ptr es:[bx]
  mov bx, 0x72a3
  xlat ds
  xor ah, ah
  mov bx, ax
  shl bx, 1
  call word ptr [bx+0x726f]
  pop di
  pop dx
  pop bx
  ret
sub_4617 endp

sub_4631 proc near
  push bx
  push dx
  push di
  mov di, bx
  mov al, byte ptr es:[bx]
  mov bx, 0x72a3
  xlat ds
  cmp al, 0x4
  jz loc_4645
  cmp al, 0x2
  jnz loc_464f
loc_4645:
  xor ah, ah
  mov bx, ax
  shl bx, 1
  call word ptr [bx+0x726f]
loc_464f:
  pop di
  pop dx
  pop bx
  ret
loc_4653:
  ret
loc_4654:
  jmp loc_4735
sub_4631 endp

sub_4657 proc near
  cmp word ptr [0x528a], 0x0
  jl loc_4653
  cmp byte ptr [0x6510], 0x0
  jnz loc_4653
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov si, 0x5648
  mov cx, 0x4
loc_4674:
  cmp word ptr [si+0x4], -0x1
  jz loc_4654
  test byte ptr [si+0x5], 0x20
  jz loc_4654
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_468a
  neg ax
loc_468a:
  cmp ax, 0x40
  jnc loc_4654
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [0x527e]
  jns loc_469a
  neg ax
loc_469a:
  cmp ax, 0x10
  jnc loc_4654
  mov ax, word ptr [si]
  mov dx, word ptr [0x527c]
  sub dl, byte ptr [0x692f]
  sbb dh, 0x0
  mov bl, byte ptr [0x6bf7]
  cmp dx, ax
  jl loc_46c1
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf7]
  xchg ax, dx
loc_46c1:
  xor bh, bh
  add dx, bx
  cmp dx, ax
  jle loc_4735
  mov ax, word ptr [si+0x2]
  mov dx, word ptr [0x527e]
  sub dl, 0x6
  sbb dh, 0x0
  mov bl, 0x8
  cmp dx, ax
  jl loc_46e9
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf8]
  xchg ax, dx
loc_46e9:
  xor bh, bh
  add dx, bx
  cmp dx, ax
  jle loc_4735
  cmp word ptr [0x651e], 0xe
  jnz loc_46fe
  mov word ptr [0x651e], 0x10
loc_46fe:
  mov byte ptr [0x6526], 0x0
  mov ax, word ptr [si+0x2]
  mov [0x527e], ax
  call sub_4cf0
  mov bx, word ptr [si+0x9]
  mov al, byte ptr [bx+0x7]
  cbw
  mov dl, byte ptr [bx+0x6]
  cmp dl, 0x1
  jz loc_472f
  cmp dl, 0x2
  jz loc_4729
  neg ax
  cmp dl, 0x3
  jz loc_472f
  jmp loc_473e
loc_4729:
  add word ptr [0x527e], ax
  jmp loc_473e
loc_472f:
  add word ptr [0x527c], ax
  jmp loc_473e
loc_4735:
  add si, 0x12
  dec cx
  jz loc_473e
  jmp loc_4674
loc_473e:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_4657 endp

sub_4748 proc near
  cmp byte ptr [0x651d], 0x3
  jc loc_4755
  mov byte ptr [0x650f], 0x6
  ret
loc_4755:
  inc byte ptr [0x651d]
  mov bp, 0x30
  call sub_4bb6
  mov bp, 0x40
  call sub_4b7d
  call sub_4c12
  call sub_4c2a
  ret
sub_4748 endp

sub_476c proc near
  push ax
  push bx
  push dx
  mov [0x5287], al
  call sub_4be8
  or ax, ax
  jns loc_477b
  neg ax
loc_477b:
  cmp ax, 0x10
  jc loc_479d
  mov al, [0x5281]
  mov ah, byte ptr [0x5283]
  rol al, 1
  rol ah, 1
  and ax, 0x101
  cmp al, ah
  jnz loc_479d
  mov bl, byte ptr [0x6509]
  xor bh, bh
  add bx, 0x4
  shl bx, 1
loc_479d:
  mov bx, word ptr [bx+0x6ebf]
  mov word ptr [0x5288], bx
  mov ax, word ptr [bx]
  mov dh, byte ptr [0x5285]
  and dh, 0x80
  or ah, dh
  mov [0x5280], ax
  pop dx
  pop bx
  pop ax
  ret
sub_476c endp

sub_47b7 proc near
  call sub_4c12
  call sub_4c2a
  call sub_4be8
  cmp word ptr [0x651e], 0xf
  jnz loc_47d2
  mov byte ptr [0x6510], 0x6
  mov word ptr [0x528a], 0x0
loc_47d2:
  ret
sub_47b7 endp

sub_47d3 proc near
  call sub_4c12
  call sub_4c2a
  mov bp, 0x20
  call sub_4b7d
  mov ax, [0x5282]
  or ax, ax
  jns loc_47e8
  neg ax
loc_47e8:
  cmp ax, 0x20
  jnc loc_47f9
  mov al, 0x6
  mov ah, byte ptr [0x5285]
  and ah, 0x80
  mov [0x5280], ax
loc_47f9:
  ret
sub_47d3 endp

sub_47fa proc near
  mov bp, 0x40
  call sub_4b7d
  call sub_4c12
  call sub_4c2a
  ret
sub_47fa endp

sub_4807 proc near
  mov bp, 0x30
  call sub_4b7d
  call sub_4c12
  call sub_4c2a
  ret
sub_4807 endp

sub_4814 proc near
  mov word ptr [0x5282], 0x0
  call sub_4c12
  call sub_4c2a
  ret
sub_4814 endp

sub_4821 proc near
  call sub_4ae9
  jmp sub_4814
sub_4821 endp

sub_4826 proc near
  mov bp, 0xc0
  call sub_4bd0
  call sub_4c12
  call sub_4c2a
  ret
sub_4826 endp

sub_4833 proc near
  cmp byte ptr [0x6507], 0x0
  jz loc_4842
  mov bp, 0x40
  call sub_4b7d
  jmp loc_4845
loc_4842:
  call sub_4be8
loc_4845:
  cmp word ptr [0x651e], 0x1
  ja loc_485c
  mov ax, 0xc
  cmp byte ptr [0x6509], 0x0
  jz loc_4859
  mov ax, 0x17
loc_4859:
  mov [0x5280], ax
loc_485c:
  xor ax, ax
  cmp byte ptr [0x6508], al
  jz loc_48c8
  mov al, 0x6
  add al, byte ptr [0x6509]
  cbw
  mov bx, ax
  shl bx, 1
  call sub_4c12
  call sub_4c2a
  and byte ptr [0x527c], 0xf0
  add byte ptr [0x527c], 0x8
  mov bx, 0x73a3
  mov cl, 0x4
  mov ax, [0x527e]
  and al, 0xf0
  shl ax, cl
  mov di, word ptr [0x527c]
  sar di, cl
  add di, ax
  mov es, word ptr [0x526c]
  mov al, byte ptr es:[di]
  xlat ds
  cmp al, 0x6
  jz loc_48bc
  mov dx, 0xfff0
  mov al, byte ptr es:[di-0x1]
  xlat ds
  cmp al, 0x6
  jz loc_48b8
  neg dx
  mov al, byte ptr es:[di+0x1]
  xlat ds
  cmp al, 0x6
  jz loc_48b8
  xor dx, dx
loc_48b8:
  add word ptr [0x527c], dx
loc_48bc:
  mov ax, 0x40
  cmp byte ptr [0x42d], 0x0
  jz loc_48c8
  neg ax
loc_48c8:
  mov [0x528a], ax
  ret
sub_4833 endp

sub_48cc proc near
  call sub_4c12
  call sub_4c2a
  call sub_4be8
  ret
sub_48cc endp

sub_48d6 proc near
  call sub_4c12
  call sub_4c2a
  call sub_4be8
  cmp byte ptr [0x6509], 0x0
  jz loc_495a
  xor ax, ax
  mov dx, 0xff60
  cmp byte ptr [0x42d], 0x0
  jnz loc_490a
  mov dx, 0xff20
  xchg ax, dx
  test byte ptr [0x5281], 0x80
  jnz loc_48ff
  neg ax
loc_48ff:
  mov bx, word ptr [0x527e]
  sub bx, 0x10
  mov word ptr [0x5290], bx
loc_490a:
  or dx, dx
  jnz loc_4921
  mov bx, word ptr [0x5292]
  and bh, 0x1f
  cmp bx, 0x65
  jnc loc_4938
  test byte ptr [bx+0x6f19], 0x4
  jz loc_4938
loc_4921:
  call sub_4ae9
  mov bx, word ptr [0x64e9]
  mov word ptr [bx+0xe], dx
  mov dx, ax
  sar dx, 1
  sar dx, 1
  sub ax, dx
  mov word ptr [bx+0x6], ax
  jmp loc_4949
loc_4938:
  mov byte ptr [0x650a], 0x1
  mov [0x5294], ax
  mov word ptr [0x529c], dx
  mov al, 0x3
  call sub_11e6
loc_4949:
  mov al, 0xa
  mov ah, byte ptr [0x5285]
  and ah, 0x80
  mov [0x5280], ax
  mov byte ptr [0x6509], 0x0
loc_495a:
  ret
sub_48d6 endp

sub_495b proc near
  call sub_4c12
  call sub_4c2a
  call sub_4be8
  cmp byte ptr [0x650c], 0x0
  jnz loc_49af
  cmp word ptr [0x651e], 0x1
  jnz loc_49b2
  cmp byte ptr [0x6509], 0x0
  jz loc_49b2
  call sub_4ae9
  mov bx, word ptr [0x64e9]
  mov ax, word ptr [bx+0x2]
  mov cl, 0x4
  sar ax, cl
  xchg al, ah
  mov di, ax
  mov ax, word ptr [bx]
  sar ax, cl
  add di, ax
  mov ax, word ptr es:[di]
  mov bx, 0x73a3
  xlat ds
  and al, 0x7
  jz loc_49af
  mov dx, 0xffd0
  mov al, ah
  xlat ds
  and al, 0x7
  jz loc_49a8
  neg dx
loc_49a8:
  mov bx, word ptr [0x64e9]
  mov word ptr [bx+0x6], dx
loc_49af:
  jmp loc_4ae3
loc_49b2:
  cmp byte ptr [0x6509], 0x0
  jz loc_49bc
  jmp loc_4ac1
loc_49bc:
  mov di, 0x52a0
  mov cx, 0x30
  mov bx, word ptr [0x527e]
  mov dx, word ptr [0x527c]
loc_49ca:
  cmp word ptr [di+0x4], -0x1
  jnz loc_49d3
  jmp loc_4ada
loc_49d3:
  mov ax, bx
  sub ax, word ptr [di+0x2]
  jns loc_49dc
  neg ax
loc_49dc:
  cmp ax, 0x14
  jc loc_49e4
  jmp loc_4ada
loc_49e4:
  mov ax, dx
  sub ax, word ptr [di]
  test byte ptr [0x5281], 0x80
  jnz loc_49f1
  neg ax
loc_49f1:
  cmp ax, 0x14
  jc loc_49f9
  jmp loc_4ada
loc_49f9:
  cmp cx, 0x8
  ja loc_4a11
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  mov al, byte ptr [bx+0x6f7a]
  and al, 0xf
  cmp al, 0xf
  jnz loc_4a11
  jmp loc_4ad2
loc_4a11:
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf7]
  mov ax, [0x527c]
  cmp ax, dx
  jle loc_4a27
  xchg ax, dx
  mov bl, 0x20
loc_4a27:
  xor bh, bh
  add ax, bx
  cmp ax, dx
  jge loc_4a32
  jmp loc_4ad2
loc_4a32:
  mov ax, word ptr [di+0x2]
  mov dx, word ptr [0x527e]
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf8]
  dec bl
  cmp ax, dx
  jge loc_4a4e
  xchg ax, dx
  mov bl, 0xa
loc_4a4e:
  xor bh, bh
  sub ax, bx
  cmp ax, dx
  jge loc_4ad2
  cmp byte ptr [di+0x4], 0x65
  jc loc_4a90
  mov ax, [0x527c]
  sub ax, word ptr [di]
  test byte ptr [di+0x5], 0x80
  jz loc_4a69
  neg ax
loc_4a69:
  or ax, ax
  js loc_4ad2
  mov bx, word ptr [di+0x9]
  mov word ptr [bx+0x4], 0xffff
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  mov bl, byte ptr [bx+0x6f7a]
  and bl, 0xf
  xor bh, bh
  shl bx, 1
  mov bx, word ptr [bx+0x6fc5]
  add bx, 0x65
  mov word ptr [di+0x4], bx
loc_4a90:
  mov al, 0x9
  call sub_11e6
  xor ax, ax
  mov [0x6505], al
  mov word ptr [di+0xe], ax
  mov word ptr [di+0x6], ax
  mov byte ptr [0x6511], 0x4
  mov ax, 0xffff
  xchg word ptr [di+0x4], ax
  mov [0x5292], ax
  mov byte ptr [0x6509], 0x10
  mov byte ptr [0x6515], 0x0
  cmp al, 0x31
  jnz loc_4ac1
  mov byte ptr [0x6503], 0x0
loc_4ac1:
  mov ax, [0x527e]
  sub ax, 0x4
  mov [0x5290], ax
  call sub_5122
  mov [0x528e], ax
  jmp loc_4ae3
loc_4ad2:
  mov bx, word ptr [0x527e]
  mov dx, word ptr [0x527c]
loc_4ada:
  add di, 0x12
  dec cx
  jz loc_4ae3
  jmp loc_49ca
loc_4ae3:
  mov byte ptr [0x650c], 0x1
  ret
sub_495b endp

sub_4ae9 proc near
  cmp word ptr [0x5292], -0x1
  jz loc_4b48
  cmp byte ptr [0x6509], 0x0
  jz loc_4b48
  push ax
  push di
  mov di, 0x528e
  mov ax, 0xffff
loc_4aff:
  add di, 0x12
  cmp word ptr [di+0x4], ax
  jnz loc_4aff
  xchg word ptr [0x5292], ax
  mov word ptr [di+0x4], ax
  and ah, 0x1f
  cmp ax, 0x65
  mov al, 0x0
  jc loc_4b1a
  inc al
loc_4b1a:
  mov byte ptr [di+0xb], al
  mov ax, [0x528e]
  mov word ptr [di], ax
  mov ax, [0x5290]
  mov word ptr [di+0x2], ax
  xor ax, ax
  mov [0x6509], al
  mov word ptr [di+0xc], ax
  mov word ptr [di+0xe], ax
  mov word ptr [di+0x6], ax
  mov byte ptr [di+0x8], al
  inc ax
  mov [0x650c], al
  mov byte ptr [0x6511], 0x4
  mov word ptr [0x64e9], di
  pop di
  pop ax
loc_4b48:
  ret
sub_4ae9 endp

sub_4b49 proc near
  cmp byte ptr [0x459], 0x0
  jz loc_4b7c
loc_4b50:
  cmp byte ptr [0x459], 0x0
  jnz loc_4b50
  call sub_2c87
  push word ptr [0x5280]
  mov word ptr [0x5280], 0x1d
  call sub_1c61
  call sub_3271
  pop word ptr [0x5280]
loc_4b6e:
  cmp byte ptr [0x459], 0x0
  jz loc_4b6e
loc_4b75:
  cmp byte ptr [0x459], 0x0
  jnz loc_4b75
loc_4b7c:
  ret
sub_4b49 endp

sub_4b7d proc near
  push ax
  push cx
  push dx
  push bp
  xor ax, ax
  cmp byte ptr [0x6507], 0x0
  jz loc_4b95
  mov ax, [0x5285]
  shl ax, 1
  shl ax, 1
  shl ax, 1
  shl ax, 1
loc_4b95:
  mov cl, byte ptr [0x5284]
  sar ax, cl
  mov dx, word ptr [0x5282]
  add dx, ax
  cmp dx, bp
  jge loc_4bad
  neg bp
  cmp dx, bp
  jle loc_4bad
  mov bp, dx
loc_4bad:
  mov word ptr [0x5282], bp
  pop bp
  pop dx
  pop cx
  pop ax
  ret
sub_4b7d endp

sub_4bb6 proc near
  push ax
  push cx
  push dx
  mov dx, word ptr [0x528a]
  add dx, -0x20
  neg bp
  cmp dx, bp
  jge loc_4bc8
  mov bp, dx
loc_4bc8:
  mov word ptr [0x528a], bp
  pop dx
  pop cx
  pop ax
  ret
sub_4bb6 endp

sub_4bd0 proc near
  push ax
  push cx
  push dx
  mov dx, word ptr [0x528a]
  add dx, 0x10
  cmp dx, bp
  jge loc_4be0
  mov bp, dx
loc_4be0:
  mov word ptr [0x528a], bp
  pop dx
  pop cx
  pop ax
  ret
sub_4bd0 endp

sub_4be8 proc near
  push cx
  push dx
  xor ch, ch
  mov ax, [0x5282]
  or ax, ax
  jns loc_4bf7
  neg ax
  inc ch
loc_4bf7:
  mov cl, byte ptr [0x5284]
  mov dx, 0xc
  shr dx, cl
  sub ax, dx
  jnc loc_4c06
  xor ax, ax
loc_4c06:
  or ch, ch
  jz loc_4c0c
  neg ax
loc_4c0c:
  mov [0x5282], ax
  pop dx
  pop cx
  ret
sub_4be8 endp

sub_4c12 proc near
  cmp byte ptr [0x5287], al
  jz loc_4c25
  mov [0x5287], al
  mov bx, word ptr [bx+0x6ebf]
  mov word ptr [0x5288], bx
  jmp loc_4c29
loc_4c25:
  mov bx, word ptr [0x5288]
loc_4c29:
  ret
sub_4c12 endp

sub_4c2a proc near
  push ax
  push bx
  push dx
  mov ax, word ptr [bx]
  or ax, ax
  jns loc_4c37
  add bx, ax
  mov ax, word ptr [bx]
loc_4c37:
  mov dh, byte ptr [0x5285]
  and dh, 0x80
  or ah, dh
  mov [0x5280], ax
  inc bx
  inc bx
  mov word ptr [0x5288], bx
  pop dx
  pop bx
  pop ax
  ret
sub_4c2a endp

sub_4c4d proc near
  mov bp, 0xc0
  call sub_4bd0
  mov al, 0xe
  mov ah, byte ptr [0x5285]
  and ah, 0x80
  mov [0x5280], ax
  mov byte ptr [0x650f], 0x6
  ret
sub_4c4d endp

sub_4c65 proc near
  mov byte ptr [0x650f], 0x6
  cmp byte ptr [0x6514], 0x0
  jnz loc_4ca1
  push ax
  push bp
  mov bp, 0x40
  call sub_4b7d
  mov bp, 0xc0
  call sub_4bd0
  cmp byte ptr [0x6513], 0x0
  jz loc_4c8a
  mov al, 0xf
  jmp loc_4c95
loc_4c8a:
  mov al, 0xa
  cmp byte ptr [0x6509], 0x0
  jz loc_4c95
  mov al, 0x15
loc_4c95:
  mov ah, byte ptr [0x5285]
  and ah, 0x80
  mov [0x5280], ax
  pop bp
  pop ax
loc_4ca1:
  ret
sub_4c65 endp

sub_4ca2 proc near
  or byte ptr [0x6526], 0x1
  ret
sub_4ca2 endp

sub_4ca8 proc near
  push ax
  mov ax, [0x5282]
  sar ax, 1
  sar ax, 1
  sar ax, 1
  sar ax, 1
  sub word ptr [0x527c], ax
  mov word ptr [0x5282], 0x0
  cmp byte ptr [0x6514], 0x0
  jz loc_4cd6
  cmp byte ptr [0x650f], 0x6
  jz loc_4cd6
  mov byte ptr [0x6513], 0x14
  mov byte ptr [0x6514], 0x0
loc_4cd6:
  pop ax
  ret
sub_4ca8 endp

sub_4cd8 proc near
  mov byte ptr [0x651c], 0x1
  mov byte ptr [0x5284], 0x0
  cmp word ptr [0x528a], 0x0
  jge loc_4ceb
  jmp sub_4ca2
loc_4ceb:
  and byte ptr [0x527e], 0xf0
sub_4cd8 endp ; sp-analysis failed

sub_4cf0 proc near
  mov word ptr [0x528a], 0x0
sub_4cf0 endp ; sp-analysis failed

sub_4cf6 proc near
  sub byte ptr [0x650f], 0x1
  adc byte ptr [0x650f], 0x0
  mov byte ptr [0x651d], 0x0
  mov byte ptr [0x6526], 0x2
  ret
  ret
sub_4cf6 endp

sub_4d0c proc near
  call sub_4ca8
  ret
sub_4d0c endp

sub_4d10 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov si, 0x7bad
  mov cx, 0x64
loc_4d1f:
  cmp word ptr [si+0x2], di
  jz loc_4d2b
  add si, 0x4
  loop loc_4d1f
  jmp loc_4d8f
loc_4d2b:
  cmp byte ptr [si], 0xfd
  jc loc_4d39
  mov ax, 0x6
  call sub_10ff
  call sub_59a1
loc_4d39:
  mov al, byte ptr [si+0x1]
  mov byte ptr es:[di], al
  mov bl, 0x50
  mov bh, 0x2
  cmp byte ptr cs:[0x1], 0x3
  jc loc_4d52
  call sub_32f4
  mov bl, 0x28
  mov bh, 0x1
loc_4d52:
  mov ax, di
  mov al, ah
  xor ah, ah
  mov dl, 0xc
  div dl
  mov al, bl
  mul ah
  shl ax, 1
  shl ax, 1
  shl ax, 1
  shl ax, 1
  push ax
  mov ax, di
  xor ah, ah
  mov dl, 0x14
  div dl
  mov al, ah
  xor ah, ah
  mov cl, bh
  shl ax, cl
  pop di
  add di, ax
  mov al, byte ptr [si+0x1]
  call sub_2ddc
  mov byte ptr [0x6511], 0x4
  mov byte ptr [0x64f5], 0x1
  clc
  jmp loc_4d90
loc_4d8f:
  stc
loc_4d90:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_4d10 endp

sub_4d9a proc near
  mov ax, 0x7
  call sub_10ff
  mov al, [0x5250]
  mov byte ptr [0x5250], 0xe
  push ax
  call sub_4db1
  pop ax
  mov [0x5250], al
  ret
sub_4d9a endp

sub_4db1 proc near
  mov ax, 0x7
  call sub_10ff
  call sub_4d10
  jc loc_4dbf
  call sub_0333
loc_4dbf:
  ret
sub_4db1 endp

sub_4dc0 proc near
  call sub_59e7
  mov byte ptr [0x6516], 0x2
  ret
sub_4dc0 endp

sub_4dc9 proc near
  mov ax, 0x5
  call sub_10ff
  call sub_4d10
  jc loc_4df8
  mov ax, [0x527c]
  mov [0x64e4], ax
  mov dx, word ptr [0x527e]
  mov word ptr [0x64e6], dx
  mov bx, word ptr [0x5292]
  and bh, 0x1f
  sub bx, 0x38
  cmp bx, 0x1
  ja loc_4df8
  mov [0x64f8], ax
  mov word ptr [0x64fa], dx
loc_4df8:
  ret
sub_4dc9 endp

sub_4df9 proc near
  call sub_4ca2
  ret
sub_4df9 endp

sub_4dfd proc near
  call sub_4cd8
  ret
sub_4dfd endp

sub_4e01 proc near
  mov byte ptr [0x5284], 0x0
  cmp byte ptr [0x6510], 0x0
  jnz loc_4e10
  jmp sub_4cd8
loc_4e10:
  jmp sub_4ca2
sub_4e01 endp

sub_4e13 proc near
  call sub_4cd8
  mov byte ptr [0x5284], 0x1
  ret
sub_4e13 endp

sub_4e1c proc near
  call sub_4cd8
  mov byte ptr [0x5284], 0x2
  ret
sub_4e1c endp

sub_4e25 proc near
  call sub_4cd8
  mov byte ptr [0x5284], 0x3
  ret
sub_4e25 endp

sub_4e2e proc near
  cmp byte ptr [0x6513], 0x0
  jnz sub_4df9
  mov al, [0x5287]
  and al, 0xf
  cmp al, 0x1
  jz sub_4dfd
  cmp al, 0x3
loc_4e40:
  jz sub_4dfd
  cmp al, 0x7
  jz sub_4dfd
  cmp al, 0x8
  jz loc_4e40
  cmp al, 0x5
  jnz loc_4e5c
  call sub_4df9
  mov word ptr [0x5280], 0xe
  add word ptr [0x527e], 0x8
loc_4e5c:
  push ds
  mov ds, word ptr [0x526c]
  mov bl, byte ptr [di+0xff00]
  pop ds
  xor bh, bh
  mov ah, byte ptr [bx+0x73a3]
  cmp ah, 0x6
  jz loc_4e7e
  cmp al, 0x0
  jz loc_4e40
  mov ah, byte ptr [0x42d]
  cmp ax, 0xff06
  jz loc_4e40
loc_4e7e:
  call sub_4cf6
  mov byte ptr [0x650d], 0x1
  ret
sub_4e2e endp

sub_4e87 proc near
  ret
sub_4e87 endp

sub_4e88 proc near
  cmp word ptr [0x528a], 0x0
  jz loc_4ea5
  mov word ptr [0x528a], 0x0
  and word ptr [0x527e], 0xfff0
  add word ptr [0x527e], 0x10
  mov byte ptr [0x651d], 0xff
  ret
loc_4ea5:
  mov al, [0x5280]
  cmp al, 0xa
  jz loc_4f02
  cmp al, 0x15
  jz loc_4f02
  cmp byte ptr [0x650f], 0x6
  jz loc_4f02
  mov byte ptr [0x650e], 0x1
  cmp byte ptr [0x6509], 0x0
  jz loc_4f02
  call sub_4ae9
  push bx
  push di
  mov di, word ptr [0x64e9]
  mov cl, 0x4
  mov ax, word ptr [di+0x2]
  sar ax, cl
  mov bh, al
  mov ax, word ptr [di]
  sar ax, cl
  mov bl, al
  mov di, bx
  mov es, word ptr [0x526c]
  mov bx, 0x72a3
  mov al, byte ptr es:[di]
  xlat ds
  and al, 0x1
  jz loc_4f00
  mov dx, 0x10
  mov al, byte ptr es:[di-0x1]
  xlat ds
  and al, 0x1
  jnz loc_4efa
  neg dx
loc_4efa:
  mov di, word ptr [0x64e9]
  add word ptr [di], dx
loc_4f00:
  pop di
  pop bx
loc_4f02:
  ret
sub_4e88 endp

sub_4f03 proc near
  cmp word ptr [0x528a], 0x0
  jge loc_4f1b
  cmp word ptr [0x5282], 0x0
  jnz loc_4f1b
  mov byte ptr [0x651d], 0xa
  mov byte ptr [0x650d], 0x1
loc_4f1b:
  ret
loc_4f1c:
  jmp loc_503b
sub_4f03 endp

sub_4f1f proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cmp word ptr [si+0xe], 0x0
  jl loc_4f1c
  mov si, 0x527c
  xor bx, bx
  call sub_5045
  jnc loc_4f1c
  mov word ptr [0x527e], dx
  mov di, ax
  mov al, byte ptr [di+0x4]
  sub al, 0x36
  cmp al, 0x1
  ja loc_4f4e
  or byte ptr [di+0x8], 0x2
  mov word ptr [di+0x9], si
loc_4f4e:
  mov al, byte ptr [di+0x4]
  sub al, 0x33
  cmp al, 0x1
  ja loc_4f7b
  mov ax, 0x60
  mov dl, byte ptr [0x5281]
  and dl, 0x80
  jz loc_4f65
  neg ax
loc_4f65:
  and byte ptr [di+0x5], 0x7f
  or byte ptr [di+0x5], dl
  mov word ptr [di+0x6], ax
  mov byte ptr [0x6511], 0x4
  mov byte ptr [0x6503], 0x0
  jmp loc_4fb9
loc_4f7b:
  cmp word ptr [0x651e], 0xa
  jle loc_4fb9
  test byte ptr [0x5287], 0xf
  jnz loc_4fb9
  cmp word ptr [0x528a], 0x0
  jnz loc_4fb9
  mov al, byte ptr [di+0x4]
  cmp al, 0x53
  jz loc_4f9b
  cmp al, 0x5e
  jnz loc_4fb9
loc_4f9b:
  mov ax, 0x30
  test byte ptr [0x5281], 0x80
  jz loc_4fa7
  neg ax
loc_4fa7:
  mov word ptr [di+0x6], ax
  and ah, 0x80
  and byte ptr [di+0x5], 0x7f
  or byte ptr [di+0x5], ah
  mov byte ptr [0x6511], 0x4
loc_4fb9:
  mov dx, 0x10
  mov ax, word ptr [di+0x6]
  or ax, ax
  jz loc_4fcc
  jns loc_4fc7
  xor dx, dx
loc_4fc7:
  add ax, dx
  mov [0x5282], ax
loc_4fcc:
  cmp byte ptr [0x6510], 0x0
  jnz loc_5029
  cmp word ptr [0x528a], 0x30
  jle loc_5029
  push di
  call sub_5133
  jz loc_5029
  mov ax, [0x528a]
  mov dx, 0xfff0
  cmp byte ptr [0x42d], 0x0
  jz loc_4ff0
  mov dx, 0x30
loc_4ff0:
  cmp byte ptr [0x42e], 0x0
  jnz loc_4ffb
  add ax, dx
  jns loc_4ffd
loc_4ffb:
  xor ax, ax
loc_4ffd:
  neg ax
  mov [0x528a], ax
  mov word ptr [0x651e], 0x0
  cmp word ptr [di+0xe], 0x0
  jnz loc_503b
  mov al, 0xc
  call sub_11e6
  mov ax, [0x528a]
  neg ax
  mov word ptr [di+0xe], ax
  mov cl, 0x4
  sar ax, cl
  sub word ptr [di+0x2], ax
  mov byte ptr [0x6511], 0x4
  jmp loc_503b
loc_5029:
  mov ax, word ptr [di+0xe]
  or ax, ax
  jz loc_5038
  mov [0x528a], ax
  call sub_4cf6
  jmp loc_503b
loc_5038:
  call sub_4cf0
loc_503b:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_4f1f endp

sub_5045 proc near
  push cx
  push di
  and bh, 0x1f
  shl bx, 1
  mov al, byte ptr [bx+0x6bf7]
  xor ah, ah
  mov [0x64ef], ax
  mov bl, byte ptr [bx+0x6665]
  xor bh, bh
  mov ax, word ptr [si]
  mov dx, word ptr [si+0x2]
  shr bx, 1
  sub ax, bx
  mov [0x64f1], ax
  mov word ptr [0x64f3], dx
  mov cx, 0x28
  mov di, 0x52a0
loc_5071:
  cmp si, di
  jz loc_508c
  mov bx, word ptr [di+0x4]
  cmp bx, -0x1
  jz loc_508c
  and bh, 0x1f
  test byte ptr [bx+0x6f19], 0x1
  jz loc_508c
  call sub_5153
  jc loc_5092
loc_508c:
  add di, 0x12
  loop loc_5071
  clc
loc_5092:
  pop di
  pop cx
  ret
sub_5045 endp

sub_5095 proc near
  push ax
  push bx
  push dx
  mov ax, word ptr [si]
  sub ax, word ptr [di]
  jns loc_50a0
  neg ax
loc_50a0:
  cmp ax, 0x40
  jnc loc_511d
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [di+0x2]
  jns loc_50af
  neg ax
loc_50af:
  cmp ax, 0x46
  jnc loc_511d
  mov ax, word ptr [si+0x2]
  mov dx, word ptr [di+0x2]
  mov bx, word ptr [si+0x4]
  cmp ax, dx
  jge loc_50c5
  xchg ax, dx
  mov bx, word ptr [di+0x4]
loc_50c5:
  and bh, 0x1f
  shl bx, 1
  mov bl, byte ptr [bx+0x6bf8]
  xor bh, bh
  sub bx, 0x3
  sub ax, bx
  cmp ax, dx
  jge loc_511d
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bp, bx
  mov al, byte ptr [bx+0x692f]
  xor ah, ah
  mov dx, word ptr [si]
  sub dx, ax
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  shl bx, 1
  mov ax, word ptr [di]
  sub al, byte ptr [bx+0x692f]
  sbb ah, 0x0
  mov bl, byte ptr [bx+0x6bf7]
  shr bl, 1
  cmp ax, dx
  jl loc_5110
  xchg ax, dx
  mov bl, byte ptr ds:[bp+0x6bf7]
  shr bl, 1
loc_5110:
  xor bh, bh
  add ax, bx
  cmp ax, dx
  jle loc_511d
  pop dx
  pop bx
  pop ax
  stc
  ret
loc_511d:
  pop dx
  pop bx
  pop ax
  clc
  ret
sub_5095 endp

sub_5122 proc near
  mov ax, word ptr [si]
  mov dx, 0xc
  test byte ptr [si+0x5], 0x80
  jz loc_5130
  mov dx, 0xfff6
loc_5130:
  add ax, dx
  ret
sub_5122 endp

sub_5133 proc near
  push bx
  push bp
  mov bp, sp
  db 00h; mov bx, word ptr [bp+param_1+0x4]
  mov bx, word ptr [bx+0x4]
  and bh, 0x1f
  cmp bl, 0x65
  jc loc_5149
  xor bx, bx
  jmp loc_514e
loc_5149:
  test byte ptr [bx+0x6f19], 0x2
loc_514e:
  pop bp
  pop bx
  ret 0x2
sub_5133 endp

sub_5153 proc near
  mov bx, word ptr [di]
  sub bx, ax
  jns loc_515b
  neg bx
loc_515b:
  cmp bx, 0x40
  ja loc_51c3
  mov bx, word ptr [di+0x2]
  sub bx, dx
  jns loc_5169
  neg bx
loc_5169:
  cmp bx, 0x46
  ja loc_51c3
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  shl bx, 1
  mov bp, bx
  mov bl, byte ptr [bx+0x6bf7]
  xor bh, bh
  push bx
  shr bx, 1
  mov dx, word ptr [di]
  sub dx, bx
  pop bx
  cmp dx, ax
  jle loc_518f
  xchg ax, dx
  mov bx, word ptr [0x64ef]
loc_518f:
  add dx, bx
  cmp dx, ax
  jle loc_51bc
  mov bl, byte ptr ds:[bp+0x6bf8]
  xor bh, bh
  mov bp, bx
  shr bx, 1
  shr bx, 1
  shr bx, 1
  mov dx, word ptr [di+0x2]
  mov ax, [0x64f3]
  sub dx, bx
  cmp dx, ax
  jl loc_51bc
  add dx, bx
  sub dx, bp
  cmp dx, ax
  jg loc_51bc
  mov ax, di
  stc
  ret
loc_51bc:
  mov ax, [0x64f1]
  mov dx, word ptr [0x64f3]
loc_51c3:
  clc
  ret
  db 00h
sub_5153 endp ; sp-analysis failed

sub_51c6 proc near
  mov ax, 0x168f
  mov ds, ax
  call sub_5338
  mov word ptr [0x43c], 0x0
loc_51d4:
  mov byte ptr [0x87d4], 0x0
loc_51d9:
  cmp word ptr [0xa], 0x7c8
  jc loc_51f1
  cmp word ptr [0x43c], 0xca8
  jc loc_51f1
  call sub_191c
  call sub_53c8
  jmp loc_51d4
loc_51f1:
  call sub_0805
  cmp byte ptr [0x42d], 0x0
  jz loc_520b
  cmp byte ptr [0x87d4], 0x0
  jz loc_520b
  call sub_5252
  dec byte ptr [0x87d4]
  jmp loc_51d9
loc_520b:
  cmp byte ptr [0x42e], 0x0
  jz loc_5222
  cmp byte ptr [0x87d4], 0x0
  jnz loc_5222
  call sub_5252
  inc byte ptr [0x87d4]
  jmp loc_51d9
loc_5222:
  cmp byte ptr [0x42b], 0x0
  jnz loc_522b
  jmp loc_51d9
loc_522b:
  cmp byte ptr [0x87d4], 0x0
  jz loc_5244
  call sub_027b
  jc loc_523a
  mov [0x5250], al
loc_523a:
  call sub_53c8
  mov byte ptr [0x87d4], 0x0
  jmp loc_51d9
loc_5244:
  call sub_0805
  cmp byte ptr [0x42b], 0x0
  jnz loc_5244
  call sub_5645
  ret
sub_51c6 endp

sub_5252 proc near
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_5260
  cmp al, 0x3
  jnc loc_528b
  jmp loc_52bb
loc_5260:
  push ds
  mov ax, 0xa000
  mov ds, ax
  mov si, 0xc878
  mov di, 0xd8b8
  mov dx, 0x8
loc_526f:
  mov cx, 0x4
loc_5272:
  mov ax, word ptr [di]
  xchg word ptr [si], ax
  mov word ptr [di], ax
  inc si
  inc si
  inc di
  inc di
  loop loc_5272
  add si, 0x138
  add di, 0x138
  dec dx
  jnz loc_526f
  pop ds
  ret
loc_528b:
  push ds
  mov ax, 0xa000
  mov ds, ax
  call sub_32f4
  mov cx, 0x8
  mov si, 0x190f
  mov di, 0x1b17
loc_529d:
  mov al, byte ptr [si]
  mov [0x0], al
  mov al, byte ptr [di]
  mov byte ptr [si], al
  mov al, [0x0]
  mov byte ptr [di], al
  mov al, [0x1]
  mov [0x0], al
  add si, 0x28
  add di, 0x28
  loop loc_529d
  pop ds
  ret
loc_52bb:
  push ds
  push es
  mov ax, 0xb800
  mov ds, ax
  mov es, ax
  mov cx, 0x5
  mov si, 0x191e
  mov di, 0x1afe
loc_52cd:
  mov ax, word ptr [si]
  xchg word ptr es:[di], ax
  mov word ptr [si], ax
  mov ax, word ptr [si+0x2000]
  xchg word ptr es:[di+0x2000], ax
  mov word ptr [si+0x2000], ax
  add si, 0x50
  add di, 0x50
  loop loc_52cd
  pop es
  pop ds
  ret
sub_5252 endp

sub_52ec proc near
  mov ax, 0x168f
  mov ds, ax
  mov al, cs:[0x1]
  cmp al, 0x5
  jnz loc_5315
  push ds
  mov dx, 0x878c
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x526c], ax
  mov ax, 0xf
  call sub_10ff
  call sub_5557
  pop ds
  ret
loc_5315:
  push ds
  mov dx, 0x8796
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x526c], ax
  mov ax, 0xf
  call sub_10ff
  mov word ptr cs:[0x6676], 0x6678
  call sub_5477
  pop ds
  ret
sub_52ec endp

sub_5338 proc near
  mov ax, 0x168f
  mov ds, ax
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_534b
  cmp al, 0x3
  jnc loc_5373
  jmp loc_5373
loc_534b:
  push ds
  mov dx, 0x87a3
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x526c], ax
  cmp byte ptr [0x87d3], 0x0
  jz loc_5366
  call sub_03f2
loc_5366:
  mov byte ptr [0x87d3], 0x1
  call sub_5645
  call sub_5557
  pop ds
  ret
loc_5373:
  push ds
  mov dx, 0x87ac
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x526c], ax
  cmp byte ptr [0x87d3], 0x0
  jz loc_538e
  call sub_03f2
loc_538e:
  mov byte ptr [0x87d3], 0x1
  call sub_1c30
  mov word ptr cs:[0x6676], 0x6698
  call sub_5477
  pop ds
  ret
sub_5338 endp

sub_53a2 proc near
  mov ax, 0x168f
  mov ds, ax
  push ds
  mov dx, 0x87b8
  push ds
  push es
  call sub_097b
  pop es
  pop ds
  mov [0x4c1], ax
  mov [0x526c], ax
  call sub_5557
  mov cx, 0x46
loc_53be:
  call sub_3243
  loop loc_53be
  call sub_5645
  pop ds
  ret
sub_53a2 endp

sub_53c8 proc near
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_53d9
  cmp al, 0x3
  jc loc_53d7
  jmp sub_5477
loc_53d7:
  jmp loc_5425
loc_53d9:
  push ds
  mov ax, 0x13
  int 0x10
  call sub_1c30
  call sub_3243
  mov ax, 0x168f
  mov ds, ax
  mov ds, word ptr [0x526c]
  xor si, si
  mov ax, 0xa000
  mov es, ax
  mov dx, 0x3c8
  mov al, 0x0
  out dx, al
  inc dx
  mov cx, 0x100
loc_53ff:
  lodsb
  jmp loc_5402
loc_5402:
  out dx, al
  lodsb
  jmp loc_5406
loc_5406:
  out dx, al
  lodsb
  jmp loc_540a
loc_540a:
  out dx, al
  loop loc_53ff
  mov si, ds
  add si, 0x30
  mov ds, si
  xor si, si
  mov cx, 0x7d00
  xor di, di
  rep movsw
  call sub_3243
  call sub_1c1a
  pop ds
  ret
loc_5425:
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov ax, 0x168f
  mov ds, ax
  mov ds, word ptr [0x526c]
  jmp loc_544d
loc_5439:
  call sub_3160
  mov ax, 0x168f
  mov ds, ax
  mov ds, word ptr [0x526c]
  xor si, si
  mov ax, 0x28c8
  call sub_65be
loc_544d:
  xor si, si
  xor di, di
  mov ax, 0xb800
  mov es, ax
  mov dx, 0x64
loc_5459:
  mov cx, 0x28
  rep movsw
  add di, 0x1fb0
  mov cl, 0x28
  rep movsw
  sub di, 0x2000
  dec dx
  jnz loc_5459
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
sub_53c8 endp

sub_5477 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  cmp byte ptr cs:[0x1], 0x3
  jc loc_5439
  mov ax, 0xd
  int 0x10
  call sub_1c30
  mov ax, 0x168f
  mov ds, ax
  mov ds, word ptr [0x526c]
  xor si, si
  xor di, di
  mov ax, 0xa000
  mov es, ax
  mov dx, 0x3c4
  mov ax, 0x102
loc_54a8:
  out dx, ax
  mov cx, 0xfa0
  rep movsw
  xor di, di
  shl ah, 1
  cmp ah, 0x10
  jc loc_54a8
  call sub_1c1a
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
loc_54c4:
  call sub_3160
  call sub_562d
  mov bx, 0x66e0
  mov ax, 0xb800
  mov es, ax
  xor di, di
  mov dl, 0xc8
loc_54d6:
  mov ch, 0x50
loc_54d8:
  xor ah, ah
  mov cl, 0x4
loc_54dc:
  lodsb
  xlat cs
  shl al, 1
  rcl ah, 1
  shl al, 1
  rcl ah, 1
  dec cl
  jnz loc_54dc
  mov byte ptr es:[di], ah
  inc di
  dec ch
  jnz loc_54d8
  cmp di, 0x2000
  jl loc_54ff
  sub di, 0x2000
  jmp loc_5503
loc_54ff:
  add di, 0x1fb0
loc_5503:
  dec dl
  jnz loc_54d6
  ret
loc_5508:
  mov ax, 0xd
  int 0x10
  call sub_1c30
  call sub_562d
  mov dx, 0x3c4
  mov al, 0x2
  out dx, al
  inc dx
  mov bl, 0x1
loc_551c:
  mov al, bl
  out dx, al
loc_551f:
  xor ah, ah
  mov cl, 0x8
loc_5523:
  lodsb
  test bl, al
  jz loc_5529
  stc
loc_5529:
  rcl ah, 1
  dec cl
  jnz loc_5523
  mov al, ah
  stosb
  cmp si, 0xfa00
  jc loc_551f
  xor di, di
  sub si, 0xfa00
  shl bl, 1
  cmp bl, 0x10
  jc loc_551c
  mov ax, 0x168f
  mov es, ax
  mov dx, 0x87c2
  mov ax, 0x1002
  int 0x10
  call sub_1c1a
  ret
  db 00h
sub_5477 endp ; sp-analysis failed

sub_5557 proc near
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_5566
  cmp al, 0x3
  jnc loc_5508
  jmp loc_54c4
loc_5566:
  push ds
  mov ax, 0x13
  int 0x10
  call sub_1c30
  call sub_3243
  mov dx, 0x3c8
  mov al, 0x0
  out dx, al
  inc dx
  mov cx, 0x300
loc_557c:
  out dx, al
  loop loc_557c
  call sub_562d
  mov cx, 0x7d00
  rep movsw
  call sub_3243
  call sub_1c1a
  mov si, ds
  sub si, 0x30
  mov ds, si
loc_5594:
  mov byte ptr cs:[0x5556], 0x0
  xor si, si
  xor bp, bp
loc_559e:
  test byte ptr cs:[0x5556], 0xf
  jnz loc_55a9
  call sub_3243
loc_55a9:
  cmp byte ptr cs:[0x3], 0x0
  jz loc_561d
  mov dx, 0x3c7
  mov al, cs:[0x5556]
  out dx, al
  mov dl, 0xc9
  jmp loc_55bd
loc_55bd:
  in al, dx
  and al, 0x3f
  mov ah, al
  jmp loc_55c4
loc_55c4:
  in al, dx
  and al, 0x3f
  mov bl, al
  jmp loc_55cb
loc_55cb:
  in al, dx
  and al, 0x3f
  mov bh, al
  mov dl, 0xc8
  mov al, cs:[0x5556]
  out dx, al
  inc dx
  mov al, ah
  cmp byte ptr [si], al
  jbe loc_55e5
  cmp al, 0x3d
  ja loc_55e5
  add al, 0x2
  inc bp
loc_55e5:
  out dx, al
  mov al, bl
  cmp byte ptr [si+0x1], al
  jbe loc_55f4
  cmp al, 0x3d
  ja loc_55f4
  add al, 0x2
  inc bp
loc_55f4:
  out dx, al
  mov al, bh
  cmp byte ptr [si+0x2], al
  jbe loc_5603
  cmp al, 0x3d
  ja loc_5603
  add al, 0x2
  inc bp
loc_5603:
  out dx, al
  add si, 0x3
  inc byte ptr cs:[0x5556]
  cmp byte ptr cs:[0x5556], 0x40
  jc loc_559e
  or bp, bp
  jz loc_561b
  jmp loc_5594
loc_561b:
  jmp loc_562b
loc_561d:
  mov dx, 0x3c8
  mov al, 0x0
  out dx, al
  inc dx
  mov cx, 0xc0
loc_5627:
  lodsb
  out dx, al
  loop loc_5627
loc_562b:
  pop ds
  ret
sub_5557 endp

sub_562d proc near
  mov ax, 0x168f
  mov ds, ax
  mov si, word ptr [0x526c]
  add si, 0x30
  mov ds, si
  xor si, si
  mov ax, 0xa000
  mov es, ax
  xor di, di
  ret
sub_562d endp

sub_5645 proc near
  cmp byte ptr cs:[0x3], 0x0
  jz loc_56cb
  mov al, cs:[0x1]
  cmp al, 0x5
  jz loc_5656
  ret
loc_5656:
  mov byte ptr cs:[0x5556], 0x0
  xor bp, bp
loc_565e:
  test byte ptr cs:[0x5556], 0xf
  jnz loc_5669
  call sub_3243
loc_5669:
  mov dx, 0x3c7
  mov al, cs:[0x5556]
  out dx, al
  mov dl, 0xc9
  jmp loc_5675
loc_5675:
  in al, dx
  and al, 0x3f
  mov ah, al
  jmp loc_567c
loc_567c:
  in al, dx
  and al, 0x3f
  mov bl, al
  jmp loc_5683
loc_5683:
  in al, dx
  and al, 0x3f
  mov bh, al
  mov dl, 0xc8
  mov al, cs:[0x5556]
  out dx, al
  inc dx
  mov al, ah
  sub al, 0x1
  adc al, 0x0
  sub al, 0x1
  adc al, 0x0
  or bp, ax
  out dx, al
  mov al, bl
  sub al, 0x1
  adc al, 0x0
  sub al, 0x1
  adc al, 0x0
  or bp, ax
  out dx, al
  mov al, bh
  sub al, 0x1
  adc al, 0x0
  sub al, 0x1
  adc al, 0x0
  or bp, ax
  out dx, al
  inc byte ptr cs:[0x5556]
  cmp byte ptr cs:[0x5556], 0x40
  jc loc_565e
  or bp, bp
  jz loc_56cb
  jmp sub_5645
loc_56cb:
  ret
sub_5645 endp

sub_56cc proc near
  push si
  push cx
  push bx
  mov ax, 0x168f
  mov ds, ax
  mov si, 0x7699
  mov cx, 0x32
  mov byte ptr [0x64fd], 0x0
loc_56df:
  mov di, 0x87d3
  mov ax, word ptr [si+0x4]
  cmp ax, 0xffff
  jz loc_5700
  and ah, 0x1f
loc_56ed:
  inc di
  inc di
  cmp word ptr [di], ax
  jnz loc_56ed
  mov word ptr [si+0xa], di
  mov di, ax
  mov al, byte ptr [di+0x70c5]
  add byte ptr [0x64fd], al
loc_5700:
  add si, 0x1a
  loop loc_56df
  mov si, 0x7dcb
  mov cx, 0xa
loc_570b:
  mov ax, word ptr [si+0xc]
  mov word ptr [si], ax
  mov ax, word ptr [si+0xe]
  mov word ptr [si+0x2], ax
  mov al, byte ptr [si+0x10]
  mov byte ptr [si+0x6], al
  mov word ptr [si+0x11], 0x0
  add si, 0x14
  loop loc_570b
  mov bl, byte ptr [0x5250]
  xor bh, bh
  mov al, byte ptr [bx+0x50b4]
  mov [0x64e8], al
  pop bx
  pop cx
  pop si
  ret
sub_56cc endp

sub_5737 proc near
  mov si, 0x7699
  mov di, 0x5570
  mov bp, 0xffff
  mov word ptr [0x5574], bp
  mov word ptr [0x5586], bp
  mov word ptr [0x5598], bp
  mov word ptr [0x55aa], bp
  mov word ptr [0x55bc], bp
  mov word ptr [0x55ce], bp
  mov word ptr [0x55e0], bp
  mov word ptr [0x55f2], bp
  mov ax, [0x5270]
  mov dx, word ptr [0x5272]
  mov cl, 0x4
  shl ax, cl
  shl dx, cl
  mov cx, 0x32
loc_5770:
  cmp word ptr [si+0x4], bp
  jnz loc_5778
  jmp loc_58a6
loc_5778:
  and byte ptr [si+0x5], 0xdf
  mov bx, word ptr [si]
  add bx, 0x20
  sub bx, ax
  jnc loc_5788
  jmp loc_589d
loc_5788:
  sub bx, 0x40
  cmp bx, 0x140
  jle loc_5794
  jmp loc_589d
loc_5794:
  mov bx, word ptr [si+0x2]
  sub bx, dx
  jnc loc_579e
  jmp loc_589d
loc_579e:
  sub bx, 0x20
  cmp bx, 0xc0
  jle loc_57aa
  jmp loc_589d
loc_57aa:
  or byte ptr [si+0x5], 0x20
  push ax
  push dx
  call sub_64ff
  mov word ptr [di+0x9], si
  mov bx, word ptr [si]
  mov word ptr [di], bx
  mov bx, word ptr [si+0x2]
  mov word ptr [di+0x2], bx
  push cx
  push si
  test byte ptr [si+0x7], 0xc0
  jz loc_57cb
  jmp loc_5891
loc_57cb:
  cmp byte ptr [0x6514], 0x0
  jnz loc_57e8
  cmp word ptr [si+0x4], 0x5aa
  jnz loc_57dc
  jmp loc_5891
loc_57dc:
  mov bx, word ptr [si+0x6]
  and bh, 0x1f
  shl bx, 1
  call word ptr [bx+0x8edb]
loc_57e8:
  cmp byte ptr [0x6511], 0x0
  jz loc_5825
  mov si, 0x52a0
  mov cx, 0x28
loc_57f5:
  cmp word ptr [si+0x6], 0x0
  jnz loc_580a
  mov ax, word ptr [si+0xe]
  or ax, ax
  jz loc_5820
  mov ax, word ptr [si+0xc]
  cmp ax, 0xa
  jc loc_5820
loc_580a:
  mov ax, bx
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  test byte ptr [bx+0x6f19], 0x10
  mov bx, ax
  jnz loc_5820
  call sub_5095
  jc loc_584e
loc_5820:
  add si, 0x12
  loop loc_57f5
loc_5825:
  cmp byte ptr [0x650a], 0x0
  jz loc_5891
  cmp byte ptr [0x6509], 0x0
  jnz loc_5891
  mov si, 0x528e
  cmp word ptr [si+0x4], -0x1
  jz loc_5891
  call sub_5095
  jnc loc_5891
  mov byte ptr [0x651b], 0x0
  mov word ptr [si+0x4], 0xffff
  call sub_58b0
loc_584e:
  cmp byte ptr [si+0x4], 0x49
  jz loc_5857
  neg word ptr [si+0x6]
loc_5857:
  mov al, 0x1
  call sub_11e6
  mov byte ptr [0x650a], 0x0
  mov bx, word ptr [di+0x4]
  and bh, 0x1f
  cmp byte ptr [bx+0x7060], 0x0
  jz loc_5888
  cmp byte ptr [0x651b], 0x0
  jnz loc_5891
  mov byte ptr [0x651b], 0xa
  or byte ptr [di+0x5], 0x40
  dec byte ptr [0x64e8]
  jnz loc_5891
  dec byte ptr [0x64fd]
loc_5888:
  mov bp, sp
  mov si, word ptr [bp+0x0]
  or byte ptr [si+0x7], 0x80
loc_5891:
  pop si
  pop cx
  mov bp, 0xffff
  add di, 0x12
  pop dx
  pop ax
  jmp loc_58a6
loc_589d:
  test byte ptr [si+0x7], 0xc0
  jz loc_58a6
  mov word ptr [si+0x4], bp
loc_58a6:
  add si, 0x1a
  dec cx
  jz loc_58af
  jmp loc_5770
loc_58af:
  ret
sub_5737 endp

sub_58b0 proc near
  mov word ptr [0x5292], 0x2d
  mov word ptr [0x5294], 0x0
  mov word ptr [0x529c], 0x0
  mov byte ptr [0x6515], 0x5
  ret
sub_58b0 endp

sub_58c8 proc near
  mov si, 0x5600
  mov dx, 0x4
  mov cl, 0x4
loc_58d0:
  cmp word ptr [si+0x4], -0x1
  jz loc_5926
  mov ax, word ptr [si+0x6]
  or ax, ax
  jz loc_58f0
  sar ax, cl
  add word ptr [si], ax
  mov ax, word ptr [si]
  shr ax, cl
  sub ax, word ptr [0x5270]
  jc loc_590a
  cmp ax, 0x14
  jg loc_590a
loc_58f0:
  mov ax, word ptr [si+0xe]
  jz loc_5911
  sar ax, cl
  add word ptr [si+0x2], ax
  mov ax, word ptr [si+0x2]
  shr ax, cl
  sub ax, word ptr [0x5272]
  jc loc_590a
  cmp ax, 0xc0
  jle loc_5911
loc_590a:
  mov word ptr [si+0x4], 0xffff
  jmp loc_5926
loc_5911:
  mov di, 0x527c
  call sub_5095
  jnc loc_5926
  mov bp, 0x46
  mov ax, word ptr [si]
  sub ax, word ptr [si+0x6]
  call sub_596f
  jmp loc_590a
loc_5926:
  add si, 0x12
  dec dx
  jnz loc_58d0
  ret
sub_58c8 endp

sub_592d proc near
  mov di, 0x5600
  push cx
  mov cx, 0x4
loc_5934:
  cmp word ptr [di+0x4], -0x1
  jnz loc_593d
  pop cx
  clc
  ret
loc_593d:
  add di, 0x12
  loop loc_5934
  pop cx
  stc
  ret
sub_592d endp

sub_5945 proc near
  mov ax, 0x168f
  mov ds, ax
  mov word ptr [0x8eb3], 0x32
  mov si, 0x7699
loc_5953:
  cmp word ptr [si+0x4], -0x1
  jz loc_5965
  mov bx, word ptr [si+0x6]
  and bh, 0x1f
  shl bx, 1
  call word ptr [bx+0x8eb5]
loc_5965:
  add si, 0x1a
  dec word ptr [0x8eb3]
  jnz loc_5953
  ret
sub_5945 endp

sub_596f proc near
  push ax
  mov al, 0x4
  call sub_11e6
  pop ax
  call sub_59cc
  call sub_59cc
  mov byte ptr [0x6514], 0x18
  mov byte ptr [0x6513], 0x0
  mov byte ptr [0x5287], 0x0
  cmp word ptr [0x527c], ax
  jg loc_5993
  neg bp
loc_5993:
  mov word ptr [0x5282], bp
  mov word ptr [0x528a], 0xff80
  call sub_4ae9
  ret
sub_596f endp

sub_59a1 proc near
  mov byte ptr [0x6506], 0x32
  inc byte ptr [0x419]
  cmp byte ptr [0x419], 0x10
  jbe loc_59ba
  mov byte ptr [0x419], 0x10
  inc byte ptr [0x41a]
loc_59ba:
  ret
sub_59a1 endp

sub_59bb proc near
  cmp byte ptr [0x41b], 0x9
  jz loc_59c6
  inc byte ptr [0x41b]
loc_59c6:
  mov byte ptr [0x6506], 0x0
  ret
sub_59bb endp

sub_59cc proc near
  mov byte ptr [0x6506], 0x32
  cmp byte ptr [0x6516], 0x0
  jnz loc_59e6
  dec byte ptr [0x419]
  jns loc_59e6
  mov byte ptr [0x419], 0x0
  call sub_59e7
loc_59e6:
  ret
sub_59cc endp

sub_59e7 proc near
  mov byte ptr [0x6516], 0xa
  cmp byte ptr [0x41b], 0x0
  jz loc_59fd
  dec byte ptr [0x41b]
  mov byte ptr [0x6506], 0x0
  ret
loc_59fd:
  mov byte ptr [0x6517], 0x1
  ret
sub_59e7 endp

sub_5a03 proc near
  ret
sub_5a03 endp

sub_5a04 proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  mov si, 0x527c
  call sub_5095
  jnc loc_5a40
  mov bx, word ptr [di+0x9]
  cmp byte ptr [bx+0x6], 0xb
  jz loc_5a2c
  mov ax, word ptr [bx+0x4]
  and ah, 0x1f
  cmp ax, 0xb2
  jz loc_5a2c
  neg word ptr [bx+0x8]
loc_5a2c:
  mov ax, word ptr [di+0x4]
  and ah, 0x1f
  sub ax, 0x9a
  cmp ax, 0x2
  ja loc_5a3f
  mov byte ptr [0x6501], 0x1
loc_5a3f:
  stc
loc_5a40:
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  jnc loc_5a57
  mov bp, word ptr [si+0xc]
  or bp, bp
  jz loc_5a57
  mov ax, word ptr [si]
  call sub_596f
loc_5a57:
  ret
loc_5a58:
  test al, 0x40
  jnz loc_5a98
  or byte ptr [si+0x7], 0x40
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  mov bl, byte ptr [bx+0x6fdf]
  and bl, 0xf0
  cmp bl, 0xf0
  jz loc_5a8f
  mov cl, 0x3
  xor bh, bh
  shr bx, cl
  mov ah, byte ptr [si+0x5]
  and ax, 0x8000
  or ax, word ptr [bx+0x6fd3]
  mov word ptr [si+0x4], ax
  mov word ptr [si+0x8], 0x0
  mov byte ptr [si+0xe], 0xff
  ret
loc_5a8f:
  mov word ptr [si+0x8], 0xfff6
  mov byte ptr [si+0xe], 0x0
loc_5a98:
  cmp byte ptr [si+0xe], 0xff
  jz loc_5ab7
  mov ax, word ptr [si+0x8]
  add word ptr [si+0x2], ax
  cmp byte ptr [0x6515], 0x0
  jz loc_5aaf
  add word ptr [0x5290], ax
loc_5aaf:
  cmp ax, 0x14
  jge loc_5ab7
  inc word ptr [si+0x8]
loc_5ab7:
  ret
sub_5a04 endp

sub_5ab8 proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_5ac1
  jmp loc_5a58
loc_5ac1:
  mov ax, word ptr [si+0x14]
  mov dx, word ptr [si+0xf]
  sub ax, dx
  cmp word ptr [0x527c], ax
  jl loc_5b21
  add ax, dx
  add ax, dx
  cmp word ptr [0x527c], ax
  jg loc_5b21
  mov ax, word ptr [si+0x16]
  mov dx, word ptr [si+0x11]
  sub ax, dx
  cmp word ptr [0x527e], ax
  jl loc_5b21
  add ax, dx
  add ax, dx
  cmp word ptr [0x527e], ax
  jg loc_5b21
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_5afa
  neg ax
loc_5afa:
  mov dx, word ptr [si]
  cmp word ptr [0x527c], dx
  jz loc_5b0b
  jl loc_5b06
  neg ax
loc_5b06:
  mov word ptr [si+0x8], ax
  sub word ptr [si], ax
loc_5b0b:
  mov al, byte ptr [si+0x13]
  mov dx, word ptr [si+0x2]
  cmp word ptr [0x527e], dx
  jz loc_5b1f
  jl loc_5b1b
  neg al
loc_5b1b:
  cbw
  sub word ptr [si+0x2], ax
loc_5b1f:
  jmp loc_5b4d
loc_5b21:
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_5b2a
  neg ax
loc_5b2a:
  mov dx, word ptr [si]
  cmp word ptr [si+0x14], dx
  jz loc_5b3a
  jl loc_5b35
  neg ax
loc_5b35:
  mov word ptr [si+0x8], ax
  sub word ptr [si], ax
loc_5b3a:
  mov al, byte ptr [si+0x13]
  mov dx, word ptr [si+0x2]
  cmp word ptr [si+0x16], dx
  jz loc_5b4d
  jl loc_5b49
  neg al
loc_5b49:
  cbw
  sub word ptr [si+0x2], ax
loc_5b4d:
  ret
sub_5ab8 endp

sub_5b4e proc near
  and byte ptr [si+0x7], 0x3f
  mov ax, word ptr [si+0x13]
  inc ax
  cmp word ptr [si+0x11], ax
  ja loc_5bb7
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_5b65
  neg ax
loc_5b65:
  cmp word ptr [si+0xf], ax
  jc loc_5bb5
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  cmp word ptr [si+0x15], ax
  jl loc_5bba
  mov di, 0x528e
  mov ax, 0xffff
loc_5b7b:
  add di, 0x12
  cmp word ptr [di+0x4], ax
  jnz loc_5b7b
  cmp di, 0x5570
  jnc loc_5bb5
  call sub_64df
  mov bx, word ptr [si+0xa]
  mov ax, word ptr [bx]
  and ah, 0x1f
  or ah, 0x80
  mov word ptr [di+0x4], ax
  mov ax, word ptr [si]
  mov word ptr [di], ax
  mov ax, word ptr [si+0x2]
  mov word ptr [di+0x2], ax
  mov byte ptr [di+0xb], 0x3
  mov word ptr [di+0xe], 0x0
  mov byte ptr [0x6511], 0x4
  call sub_64ef
loc_5bb5:
  xor ax, ax
loc_5bb7:
  mov word ptr [si+0x13], ax
loc_5bba:
  ret
sub_5b4e endp

sub_5bbb proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_5bc5
  jmp loc_5a58
loc_5bc5:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_5c07
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_5bd5
  neg ax
loc_5bd5:
  mov dx, word ptr [0x527c]
  sub dx, word ptr [si]
  jns loc_5be1
  neg ax
  neg dx
loc_5be1:
  neg ax
  mov word ptr [si+0x8], ax
  cmp word ptr [si+0x17], dx
  jc loc_5c5f
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5bf5
  neg ax
loc_5bf5:
  cmp ax, 0x28
  ja loc_5c5f
  call sub_64df
  inc byte ptr [si+0xe]
  mov word ptr [si+0x15], 0xa
  jmp loc_5c5f
loc_5c07:
  cmp al, 0x1
  jnz loc_5c23
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  mov ax, word ptr [si+0x15]
  sub word ptr [si+0x2], ax
  dec word ptr [si+0x15]
  jnz loc_5c5f
  call sub_64df
  inc byte ptr [si+0xe]
  jmp loc_5c5f
loc_5c23:
  cmp al, 0x2
  jnz loc_5c49
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  mov ax, word ptr [si+0x15]
  add word ptr [si+0x2], ax
  inc word ptr [si+0x15]
  cmp word ptr [si+0x15], 0xa
  jbe loc_5c5f
  inc byte ptr [si+0xe]
  call sub_64df
  mov al, byte ptr [si+0x14]
  mov byte ptr [si+0x15], al
  jmp loc_5c5f
loc_5c49:
  cmp al, 0x3
  jnz loc_5c5f
  dec byte ptr [si+0x15]
  jnz loc_5c5f
  call sub_64ef
  call sub_64ef
  call sub_64ef
  mov byte ptr [si+0xe], 0x0
loc_5c5f:
  ret
sub_5bbb endp

sub_5c60 proc near
  and byte ptr [si+0x7], 0x3f
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_5c80
  call sub_64df
  mov ax, word ptr [si+0xf]
  mov word ptr [si+0x11], ax
  mov ax, word ptr [si+0x2]
  mov word ptr [si+0x14], ax
  mov byte ptr [si+0xe], 0x1
  jmp loc_5cc9
loc_5c80:
  cmp al, 0x1
  jnz loc_5c95
  mov ax, word ptr [si+0x11]
  sub word ptr [si+0x2], ax
  dec word ptr [si+0x11]
  jnz loc_5cc9
  mov byte ptr [si+0xe], 0x2
  jmp loc_5cc9
loc_5c95:
  cmp al, 0x2
  jnz loc_5cbc
  mov ax, word ptr [si+0x11]
  add word ptr [si+0x2], ax
  inc word ptr [si+0x11]
  mov ax, word ptr [si+0x14]
  cmp word ptr [si+0x2], ax
  jl loc_5cc9
  mov word ptr [si+0x2], ax
  mov al, byte ptr [si+0x13]
  mov byte ptr [si+0x11], al
  mov byte ptr [si+0xe], 0x3
  call sub_64ef
  jmp loc_5cc9
loc_5cbc:
  cmp al, 0x3
  jnz loc_5cc9
  dec byte ptr [si+0x11]
  jnz loc_5cc9
  mov byte ptr [si+0xe], 0x0
loc_5cc9:
  ret
sub_5c60 endp

sub_5cca proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_5cd4
  jmp loc_5a58
loc_5cd4:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_5d09
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5ce4
  neg ax
loc_5ce4:
  cmp word ptr [si+0x17], ax
  jc loc_5d01
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5cf3
  neg ax
loc_5cf3:
  cmp ax, 0x1a
  ja loc_5d01
  inc byte ptr [si+0xe]
  call sub_64df
  call sub_621c
loc_5d01:
  ret
  db e8h
  db eah
  db 07h
  db feh
  db 4ch
  db 0eh
  db c3h
loc_5d09:
  cmp al, 0x1
  jnz loc_5d7a
  call sub_6567
  or al, al
  jnz loc_5d17
  call sub_5eca
loc_5d17:
  and byte ptr [si+0x2], 0xf0
  mov al, byte ptr es:[di+0xff00]
  mov bx, 0x72a3
  xlat ds
  and al, 0x1
  jz loc_5d2b
  neg word ptr [si+0x8]
loc_5d2b:
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  jns loc_5d39
  neg ax
  sub word ptr [si], ax
  mov word ptr [si+0x8], ax
loc_5d39:
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5d42
  neg ax
loc_5d42:
  cmp ax, 0x280
  jc loc_5d4c
  inc byte ptr [si+0xe]
  jmp loc_5d01
loc_5d4c:
  sub byte ptr [si+0x14], 0x1
  adc byte ptr [si+0x14], 0x0
  jnz loc_5dcd
  cmp ax, 0x40
  ja loc_5dcd
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5d65
  neg ax
loc_5d65:
  cmp ax, 0x14
  ja loc_5dcd
  call sub_621c
  mov byte ptr [si+0xe], 0x3
  call sub_64df
  mov byte ptr [si+0x14], 0x14
  jmp loc_5dcd
loc_5d7a:
  cmp al, 0x2
  jnz loc_5db0
  mov cl, 0x4
  mov ax, word ptr [si+0xf]
  sar ax, cl
  sub ax, word ptr [0x5270]
  cmp ax, 0x15
  jnc loc_5d9c
  mov ax, word ptr [si+0x11]
  sar ax, cl
  sub ax, word ptr [0x5272]
  cmp ax, 0xd
  jbe loc_5dcd
loc_5d9c:
  mov ax, word ptr [si+0xf]
  mov word ptr [si], ax
  mov ax, word ptr [si+0x11]
  mov word ptr [si+0x2], ax
  call sub_64ef
  mov byte ptr [si+0xe], 0x0
  jmp loc_5dcd
loc_5db0:
  cmp al, 0x3
  jnz loc_5dcd
  test byte ptr [si+0x7], 0x20
  jz loc_5dcd
  call sub_592d
  jc loc_5dc6
  add word ptr [si+0xa], 0x4
  call sub_6496
loc_5dc6:
  call sub_64ef
  mov byte ptr [si+0xe], 0x1
loc_5dcd:
  ret
sub_5cca endp

sub_5dce proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_5dd8
  jmp loc_5a58
loc_5dd8:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_5e0e
  cmp byte ptr [0x6512], 0x0
  jnz loc_5e44
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5def
  neg ax
loc_5def:
  cmp word ptr [si+0x17], ax
  jc loc_5e44
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5dfe
  neg ax
loc_5dfe:
  cmp ax, 0x1a
  ja loc_5e44
  inc byte ptr [si+0xe]
  call sub_64df
  call sub_621c
  jmp loc_5e44
loc_5e0e:
  cmp al, 0x1
  jnz loc_5e4c
  cmp byte ptr [0x6512], 0x0
  jnz loc_5e44
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5e22
  neg ax
loc_5e22:
  cmp word ptr [si+0x17], ax
  jc loc_5e45
  add ax, 0x32
  cmp word ptr [si+0x17], ax
  jc loc_5e44
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5e39
  neg ax
loc_5e39:
  cmp ax, 0x3c
  ja loc_5e44
  inc byte ptr [si+0xe]
  call sub_64df
loc_5e44:
  ret
loc_5e45:
  call sub_64ef
  dec byte ptr [si+0xe]
  ret
loc_5e4c:
  cmp al, 0x2
  jnz loc_5e92
  call sub_6567
  or al, al
  jnz loc_5e5a
  call sub_5eca
loc_5e5a:
  and byte ptr [si+0x2], 0xf0
  call sub_5ee4
  mov al, byte ptr es:[di+0xff00]
  mov bx, 0x72a3
  xlat ds
  and al, 0x1
  jz loc_5e71
  call sub_5eca
loc_5e71:
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  jns loc_5e7f
  neg ax
  sub word ptr [si], ax
  mov word ptr [si+0x8], ax
loc_5e7f:
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5e88
  neg ax
loc_5e88:
  cmp ax, 0x280
  jc loc_5ec9
  inc byte ptr [si+0xe]
  jmp loc_5ec9
loc_5e92:
  cmp al, 0x3
  jnz loc_5ec9
  mov cl, 0x4
  mov ax, word ptr [si+0xf]
  sar ax, cl
  sub ax, word ptr [0x5270]
  cmp ax, 0x15
  jnc loc_5eb4
  mov ax, word ptr [si+0x11]
  sar ax, cl
  sub ax, word ptr [0x5272]
  cmp ax, 0xd
  jbe loc_5ec9
loc_5eb4:
  mov ax, word ptr [si+0xf]
  mov word ptr [si], ax
  mov ax, word ptr [si+0x11]
  mov word ptr [si+0x2], ax
  call sub_64ef
  call sub_64ef
  mov byte ptr [si+0xe], 0x0
loc_5ec9:
  ret
sub_5dce endp

sub_5eca proc near
  push ax
  push dx
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_5ed5
  neg ax
loc_5ed5:
  mov dx, word ptr [si]
  cmp word ptr [si+0xf], dx
  jle loc_5ede
  neg ax
loc_5ede:
  mov word ptr [si+0x8], ax
  pop dx
  pop ax
  ret
sub_5eca endp

sub_5ee4 proc near
  mov ax, 0x1
  cmp word ptr [si+0x8], 0x0
  jg loc_5eef
  neg ax
loc_5eef:
  sub di, ax
  ret
sub_5ee4 endp

sub_5ef2 proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_5efc
  jmp loc_5a58
loc_5efc:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_5f2a
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5f0c
  neg ax
loc_5f0c:
  cmp word ptr [si+0x17], ax
  jc loc_5f29
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_5f1b
  neg ax
loc_5f1b:
  cmp ax, 0x3c
  ja loc_5f29
  inc byte ptr [si+0xe]
  call sub_64df
  call sub_621c
loc_5f29:
  ret
loc_5f2a:
  cmp al, 0x1
  jnz loc_5f98
  inc byte ptr [0x6500]
  test byte ptr [0x6500], 0x4
  jnz loc_5f44
  test word ptr [0x64fe], 0x1ff
  jnz loc_5f44
  call sub_64df
loc_5f44:
  test byte ptr [0x64fe], 0x7f
  jnz loc_5f55
  mov al, 0x3
  mov byte ptr [si+0xe], al
  call sub_64df
  jmp loc_5f98
loc_5f55:
  call sub_6567
  or al, al
  jnz loc_5f5f
  call sub_5eca
loc_5f5f:
  and byte ptr [si+0x2], 0xf0
  call sub_5ee4
  mov al, byte ptr es:[di+0xff00]
  mov bx, 0x72a3
  xlat ds
  and al, 0x1
  jz loc_5f76
  neg word ptr [si+0x8]
loc_5f76:
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  jns loc_5f84
  neg ax
  sub word ptr [si], ax
  mov word ptr [si+0x8], ax
loc_5f84:
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_5f8d
  neg ax
loc_5f8d:
  cmp ax, 0x500
  jc loc_5f29
  mov byte ptr [si+0xe], 0x2
  jmp loc_5ff8
loc_5f98:
  cmp al, 0x2
  jnz loc_5fce
  mov cl, 0x4
  mov ax, word ptr [si+0x11]
  shr ax, cl
  sub ax, word ptr [0x5272]
  cmp ax, 0xc
  ja loc_5fba
  mov ax, word ptr [si+0xf]
  shr ax, cl
  sub ax, word ptr [0x5270]
  cmp ax, 0x19
  jc loc_5ff8
loc_5fba:
  mov ax, word ptr [si+0x11]
  mov word ptr [si+0x2], ax
  mov ax, word ptr [si+0xf]
  mov word ptr [si], ax
  mov byte ptr [si+0xe], 0x0
  call sub_64ef
  jmp loc_5ff8
loc_5fce:
  cmp al, 0x3
  jnz loc_5ff8
  test byte ptr [si+0x5], 0x20
  jnz loc_5feb
  call sub_64df
  sub word ptr [si+0xa], 0x2
  call sub_64ff
  call sub_621c
  mov byte ptr [si+0xe], 0x1
  jmp loc_5ff8
loc_5feb:
  test byte ptr [si+0x7], 0x20
  jz loc_5ff8
  call sub_621c
  mov byte ptr [si+0xe], 0x1
loc_5ff8:
  ret
  and byte ptr [si+0x7], 0x3f
  ret
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_6008
  jmp loc_5a58
loc_6008:
  ret
  and byte ptr [si+0x7], 0x3f
  jmp loc_6019
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_6019
  jmp loc_5a58
loc_6019:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_604a
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_602a
  neg ax
loc_602a:
  cmp ax, 0x154
  ja loc_603f
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [0x527e]
  jns loc_603a
  neg ax
loc_603a:
  cmp ax, 0xe6
  jc loc_6064
loc_603f:
  inc byte ptr [si+0xe]
  call sub_64df
  call sub_621c
  jmp loc_6064
loc_604a:
  cmp al, 0x1
  jnz loc_60ab
  call sub_6567
  or al, al
  jnz loc_6065
  cmp word ptr [si+0x15], 0x10
  jnc loc_605e
  inc word ptr [si+0x15]
loc_605e:
  mov ax, word ptr [si+0x15]
  add word ptr [si+0x2], ax
loc_6064:
  ret
loc_6065:
  cmp word ptr [si+0x15], 0x0
  jz loc_606e
  call sub_621c
loc_606e:
  mov word ptr [si+0x15], 0x0
  and byte ptr [si+0x2], 0xf0
  call sub_5ee4
  mov al, byte ptr es:[di+0xff00]
  mov bx, 0x72a3
  xlat ds
  and al, 0x1
  jz loc_608a
  neg word ptr [si+0x8]
loc_608a:
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  jns loc_6098
  neg ax
  sub word ptr [si], ax
  mov word ptr [si+0x8], ax
loc_6098:
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_60a1
  neg ax
loc_60a1:
  cmp ax, 0x280
  jc loc_60df
  inc byte ptr [si+0xe]
  jmp loc_60df
loc_60ab:
  cmp al, 0x2
  jnz loc_60df
  mov cl, 0x4
  mov ax, word ptr [si+0x11]
  shr ax, cl
  sub ax, word ptr [0x5272]
  cmp ax, 0xc
  ja loc_60cd
  mov ax, word ptr [si+0xf]
  shr ax, cl
  sub ax, word ptr [0x5270]
  cmp ax, 0x13
  jc loc_60df
loc_60cd:
  mov ax, word ptr [si+0x11]
  mov word ptr [si+0x2], ax
  mov ax, word ptr [si+0xf]
  mov word ptr [si], ax
  mov byte ptr [si+0xe], 0x0
  call sub_64ef
loc_60df:
  ret
sub_5ef2 endp

sub_60e0 proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_60ea
  jmp loc_5a58
loc_60ea:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_6123
  mov ax, [0x527e]
  cmp word ptr [si+0x2], ax
  jg loc_6140
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_6103
  neg ax
loc_6103:
  cmp word ptr [si+0x17], ax
  jc loc_6140
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [0x527e]
  jns loc_6113
  neg ax
loc_6113:
  cmp ax, 0xc8
  ja loc_6140
  inc byte ptr [si+0xe]
  call sub_64df
  call sub_621c
  jmp loc_6140
loc_6123:
  cmp al, 0x1
  jz loc_612a
  jmp loc_61d4
loc_612a:
  call sub_6567
  or al, al
  jnz loc_6141
  cmp word ptr [si+0x15], 0x10
  jnc loc_613a
  inc word ptr [si+0x15]
loc_613a:
  mov ax, word ptr [si+0x15]
  add word ptr [si+0x2], ax
loc_6140:
  ret
loc_6141:
  cmp word ptr [si+0x15], 0x0
  jz loc_614a
  call sub_621c
loc_614a:
  mov word ptr [si+0x15], 0x0
  and byte ptr [si+0x2], 0xf0
  call sub_5ee4
  mov al, byte ptr es:[di+0xff00]
  mov bx, 0x72a3
  xlat ds
  and al, 0x1
  jz loc_6166
  neg word ptr [si+0x8]
loc_6166:
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  jns loc_6174
  neg ax
  sub word ptr [si], ax
  mov word ptr [si+0x8], ax
loc_6174:
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_617d
  neg ax
loc_617d:
  cmp ax, 0x280
  ja loc_6191
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_618c
  neg ax
loc_618c:
  cmp ax, 0x190
  jc loc_6198
loc_6191:
  mov byte ptr [si+0xe], 0x2
  jmp loc_621b
loc_6198:
  cmp byte ptr [si+0xe], 0x1
  jnz loc_621b
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_61a7
  neg ax
loc_61a7:
  mov bx, word ptr [si+0x4]
  and bh, 0x1f
  shl bx, 1
  mov dl, byte ptr [bx+0x6665]
  xor dh, dh
  add dx, 0x6
  cmp ax, dx
  ja loc_621b
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_61c6
  neg ax
loc_61c6:
  cmp ax, 0x8
  ja loc_621b
  mov byte ptr [si+0xe], 0x3
  call sub_64df
  jmp loc_621b
loc_61d4:
  cmp al, 0x2
  jnz loc_620a
  mov cl, 0x4
  mov ax, word ptr [si+0x11]
  shr ax, cl
  sub ax, word ptr [0x5272]
  cmp ax, 0xd
  ja loc_61f6
  mov ax, word ptr [si+0xf]
  shr ax, cl
  sub ax, word ptr [0x5270]
  cmp ax, 0x15
  jc loc_621b
loc_61f6:
  mov ax, word ptr [si+0x11]
  mov word ptr [si+0x2], ax
  mov ax, word ptr [si+0xf]
  mov word ptr [si], ax
  mov byte ptr [si+0xe], 0x0
  call sub_64ef
  jmp loc_621b
loc_620a:
  cmp al, 0x3
  jnz loc_621b
  test byte ptr [si+0x7], 0x20
  jnz loc_6217
  jmp loc_612a
loc_6217:
  mov byte ptr [si+0xe], 0x1
loc_621b:
  ret
sub_60e0 endp

sub_621c proc near
  mov dl, byte ptr [si+0x13]
  xor dh, dh
  mov ax, [0x527c]
  cmp word ptr [si], ax
  jg loc_622a
  neg dx
loc_622a:
  mov word ptr [si+0x8], dx
  ret
sub_621c endp

sub_622e proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_6238
  jmp loc_5a58
loc_6238:
  call sub_63c9
  test byte ptr [si+0x5], 0x20
  jnz loc_6244
  jmp loc_62c8
loc_6244:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_6284
  mov dx, 0xfffe
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [0x527e]
  jns loc_625b
  neg ax
  neg dx
loc_625b:
  mov cl, byte ptr [si+0x13]
  xor ch, ch
  cmp ax, cx
  ja loc_62c8
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_626e
  neg ax
loc_626e:
  cmp ax, 0x28
  ja loc_62c8
  mov ax, word ptr [si+0x2]
  mov word ptr [si+0x16], ax
  mov word ptr [si+0x14], dx
  inc byte ptr [si+0xe]
  call sub_64df
  jmp loc_62c8
loc_6284:
  cmp al, 0x1
  jnz loc_62ac
  mov ax, word ptr [si+0x14]
  add word ptr [si+0x2], ax
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [si+0x16]
  jns loc_6298
  neg ax
loc_6298:
  mov cl, byte ptr [si+0x13]
  xor ch, ch
  cmp ax, cx
  jc loc_62c8
  neg word ptr [si+0x14]
  call sub_64df
  inc byte ptr [si+0xe]
  jmp loc_62c8
loc_62ac:
  cmp al, 0x2
  jnz loc_62c8
  mov ax, word ptr [si+0x14]
  add word ptr [si+0x2], ax
  mov ax, word ptr [si+0x16]
  cmp word ptr [si+0x2], ax
  jnz loc_62c8
  call sub_64ef
  call sub_64ef
  mov byte ptr [si+0xe], 0x0
loc_62c8:
  ret
sub_622e endp

sub_62c9 proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_62d3
  jmp loc_5a58
loc_62d3:
  mov al, byte ptr [si+0xe]
  cmp al, 0x0
  jnz loc_6342
  call sub_63c9
  test byte ptr [si+0x5], 0x20
  jz loc_6341
  mov ax, word ptr [si+0x2]
  sub ax, word ptr [0x527e]
  or ah, ah
  jnz loc_6341
  cmp byte ptr [si+0x13], al
  jc loc_6341
  mov cl, al
  xor dh, dh
  mov ax, word ptr [si]
  sub ax, word ptr [0x527c]
  jns loc_6303
  neg ax
  mov dh, 0x80
loc_6303:
  mov dl, byte ptr [si+0x5]
  and dl, 0x80
  cmp dl, dh
  jnz loc_6341
  cmp ax, 0x30
  jge loc_6341
  mov ax, [0x527c]
  sub ax, word ptr [si+0xf]
  jns loc_631c
  neg ax
loc_631c:
  cmp word ptr [si+0x11], ax
  jc loc_6341
  inc byte ptr [si+0xe]
  xor dx, dx
loc_6326:
  inc dl
  add dh, dl
  cmp cl, dh
  ja loc_6326
  mov al, dl
  cbw
  neg ax
  mov word ptr [si+0x14], ax
  mov ax, word ptr [si+0x2]
  mov word ptr [si+0x16], ax
  call sub_64df
  jmp loc_63be
loc_6341:
  ret
loc_6342:
  test byte ptr [si+0x5], 0x20
  jz loc_6341
  cmp al, 0x1
  jnz loc_6391
  mov ax, word ptr [si+0x8]
  shl ax, 1
  shl ax, 1
  sub word ptr [si], ax
  mov ax, word ptr [si+0x14]
  add word ptr [si+0x2], ax
  inc ax
  jz loc_636f
  mov word ptr [si+0x14], ax
  mov ax, word ptr [si+0x16]
  sub al, byte ptr [si+0x13]
  sbb ah, 0x0
  cmp word ptr [si+0x2], ax
  jg loc_63be
loc_636f:
  call sub_64df
  inc byte ptr [si+0xe]
  mov word ptr [si+0x14], 0x0
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_6383
  neg ax
loc_6383:
  mov dx, word ptr [si+0xf]
  cmp word ptr [si], dx
  jle loc_638c
  neg ax
loc_638c:
  mov word ptr [si+0x8], ax
  jmp loc_63be
loc_6391:
  cmp al, 0x2
  jnz loc_63be
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  mov ax, word ptr [si+0x14]
  add word ptr [si+0x2], ax
  inc ax
  mov word ptr [si+0x14], ax
  mov ax, word ptr [si+0x16]
  cmp word ptr [si+0x2], ax
  jl loc_63be
  mov word ptr [si+0x2], ax
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  mov byte ptr [si+0xe], 0x0
  call sub_64ef
  call sub_64ef
loc_63be:
  ret
sub_62c9 endp

sub_63bf proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz sub_63c9
  jmp loc_5a58
sub_63bf endp

sub_63c9 proc near
  mov ax, word ptr [si+0x8]
  sub word ptr [si], ax
  mov ax, word ptr [si]
  sub ax, word ptr [si+0xf]
  mov dx, ax
  jns loc_63d9
  neg ax
loc_63d9:
  cmp ax, word ptr [si+0x11]
  jbe loc_63f0
  mov ax, word ptr [si+0x8]
  or ax, ax
  jns loc_63e7
  neg ax
loc_63e7:
  or dx, dx
  jns loc_63ed
  neg ax
loc_63ed:
  mov word ptr [si+0x8], ax
loc_63f0:
  ret
sub_63c9 endp

sub_63f1 proc near
  mov al, byte ptr [si+0x7]
  test al, 0xc0
  jz loc_63fb
  jmp loc_5a58
loc_63fb:
  test byte ptr [si+0x5], 0x20
  jnz loc_6404
  jmp loc_6495
loc_6404:
  mov al, byte ptr [si+0x12]
  test al, 0xc0
  jz loc_6414
  xor dx, dx
  test al, 0x40
  jnz loc_641e
  dec dx
  jmp loc_641e
loc_6414:
  xor dx, dx
  mov ax, [0x527c]
  cmp word ptr [si], ax
  jge loc_641e
  dec dx
loc_641e:
  mov word ptr [si+0x8], dx
  mov al, byte ptr [si+0xe]
  or al, al
  jnz loc_6476
  sub byte ptr [si+0xf], 0x1
  adc byte ptr [si+0xf], 0x0
  jnz loc_6495
  mov ax, [0x527e]
  sub ax, word ptr [si+0x2]
  jns loc_643c
  neg ax
loc_643c:
  cmp ax, 0x18
  ja loc_6495
  mov ax, [0x527c]
  sub ax, word ptr [si]
  jns loc_644a
  neg ax
loc_644a:
  mov dx, word ptr [si+0x11]
  and dh, 0x3f
  cmp dx, ax
  jc loc_6495
  mov al, byte ptr [si+0x12]
  rol al, 1
  rol al, 1
  and al, 0x3
  jz loc_646d
  cmp al, 0x1
  mov ax, [0x527c]
  mov dx, word ptr [si]
  jz loc_6469
  xchg ax, dx
loc_6469:
  cmp ax, dx
  jg loc_6495
loc_646d:
  mov byte ptr [si+0xe], 0x1e
  call sub_64df
  jmp loc_6495
loc_6476:
  dec byte ptr [si+0xe]
  test byte ptr [si+0x7], 0x20
  jz loc_6495
  add word ptr [si+0xa], 0x4
  call sub_592d
  jc loc_6491
  call sub_6496
  mov al, byte ptr [si+0x10]
  mov byte ptr [si+0xf], al
loc_6491:
  mov byte ptr [si+0xe], 0x0
loc_6495:
  ret
sub_63f1 endp

sub_6496 proc near
  mov ax, word ptr [si]
  mov word ptr [di], ax
  mov ax, word ptr [si+0x2]
  mov bx, word ptr [si+0xa]
  mov bp, bx
  mov bx, word ptr [bx-0x2]
  xor bh, bh
  xchg ax, bx
  cbw
  xchg ax, bx
  sub ax, bx
  mov word ptr [di+0x2], ax
  mov bx, word ptr ds:[bp-0x4]
  and bh, 0x1f
  add bx, 0x801e
  mov dx, 0xb0
  mov ax, [0x527c]
  cmp word ptr [si], ax
  jl loc_64c9
  neg dx
  xor bh, 0x80
loc_64c9:
  mov word ptr [di+0x4], bx
  mov word ptr [di+0x6], dx
  mov word ptr [di+0xe], 0x0
  sar dx, 1
  sar dx, 1
  sar dx, 1
  sar dx, 1
  add word ptr [di], dx
  ret
sub_6496 endp

sub_64df proc near
  mov bx, word ptr [si+0xa]
loc_64e2:
  inc bx
  inc bx
  cmp word ptr [bx], 0x0
  jge loc_64e2
  inc bx
  inc bx
  mov word ptr [si+0xa], bx
  ret
sub_64df endp

sub_64ef proc near
  mov bx, word ptr [si+0xa]
loc_64f2:
  dec bx
  dec bx
  cmp word ptr [bx], 0x0
  jge loc_64f2
  dec bx
  dec bx
  mov word ptr [si+0xa], bx
  ret
sub_64ef endp

sub_64ff proc near
  test byte ptr [si+0x7], 0xc0
  jnz loc_654b
  and byte ptr [si+0x7], 0xdf
  mov bx, word ptr [si+0xa]
loc_650c:
  mov ax, word ptr [bx]
  or ax, ax
  jns loc_6516
  add bx, ax
  jmp loc_650c
loc_6516:
  cmp ax, 0x55aa
  jnz loc_6527
  mov word ptr [di+0x4], 0xffff
  mov word ptr [si+0x4], 0x5aa
  jmp sub_655c
loc_6527:
  mov dh, ah
  and dh, 0x20
  and ah, 0xdf
  or byte ptr [si+0x7], dh
  mov dh, byte ptr [si+0x9]
  and dh, 0x80
  or ah, dh
  mov word ptr [si+0x4], ax
  add ax, 0x65
  mov word ptr [di+0x4], ax
  call sub_655c
  mov word ptr [si+0xa], bx
  jmp loc_6557
loc_654b:
  mov ax, word ptr [si+0x4]
  and ah, 0xdf
  add ax, 0x65
  mov word ptr [di+0x4], ax
loc_6557:
  or byte ptr [si+0x5], 0x20
  ret
sub_64ff endp

sub_655c proc near
  inc bx
  inc bx
  mov ax, word ptr [bx]
  or ax, ax
  jns loc_6566
  add bx, ax
loc_6566:
  ret
sub_655c endp

sub_6567 proc near
  mov cl, 0x4
  mov ax, word ptr [si+0x2]
  and al, 0xf0
  shl ax, cl
  mov di, word ptr [si]
  shr di, cl
  add di, ax
  mov es, word ptr [0x526c]
  mov al, byte ptr es:[di]
  mov bx, 0x73a3
  xlat ds
  ret
sub_6567 endp

sub_6582 proc near
  push bx
  push cx
  push si
  push es
  push ds
  mov bx, ax
  mov ax, 0xf000
  mov es, ax
  mov ax, 0x168f
  mov ds, ax
  mov si, 0xfff0
  mov ax, word ptr es:[bx]
  mov cl, byte ptr cs:[0x4]
  add al, byte ptr es:[bx+0xf000]
  sub ah, byte ptr es:[bx+0xf002]
  ror ax, cl
  mov cx, 0x8
loc_65ad:
  adc ax, word ptr es:[si]
  inc si
  inc si
  loop loc_65ad
  mov cl, bl
  rol ax, cl
  pop ds
  pop es
  pop si
  pop cx
  pop bx
  ret
sub_6582 endp

sub_65be proc near
  push ax
  push bx
  push cx
  push dx
  push di
  push si
  push ds
  push es
  push bp
  push si
  mov cs:[0x66d9], al
  mov byte ptr cs:[0x66da], ah
  mul ah
  mov cs:[0x66dd], ax
  mov ax, 0x168f
  mov es, ax
  mov ax, es:[0x4c1]
  add ax, 0x7d1
  mov es, ax
  xor di, di
  xor bp, bp
loc_65e9:
  mov al, cs:[0x66da]
  mov cs:[0x66d8], al
loc_65f1:
  mov bx, word ptr cs:[0x66dd]
  mov ah, byte ptr [bx+si]
  xor dx, dx
  mov word ptr cs:[0x66db], dx
  cmp byte ptr cs:[0x66df], dl
  jnz loc_6611
  shl bx, 1
  mov dl, byte ptr [bx+si]
  add bx, word ptr cs:[0x66dd]
  mov dh, byte ptr [bx+si]
loc_6611:
  lodsb
  mov cx, 0x8
loc_6615:
  xor bx, bx
  shl dh, 1
  rcl bx, 1
  shl dl, 1
  rcl bx, 1
  shl ah, 1
  rcl bx, 1
  shl al, 1
  rcl bx, 1
  shl bx, 1
  add bx, bp
  add bx, word ptr cs:[0x6676]
  mov bl, byte ptr cs:[bx]
  xor bp, 0x1
  shl bl, 1
  rcl word ptr cs:[0x66db], 1
  shl bl, 1
  rcl word ptr cs:[0x66db], 1
  loop loc_6615
  mov ax, cs:[0x66db]
  xchg ah, al
  stosw
  dec byte ptr cs:[0x66d8]
  jnz loc_65f1
  xor bp, 0x1
  dec byte ptr cs:[0x66d9]
  jnz loc_65e9
  pop di
  xor si, si
  push ds
  push es
  pop ds
  pop es
  mov cx, word ptr cs:[0x66dd]
  rep movsw
  pop bp
  pop es
  pop ds
  pop si
  pop di
  pop dx
  pop cx
  pop bx
  pop ax
  ret
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db aah
  db 55h
  db 55h
  db 55h
  db 00h
  db aah
  db 00h
  db 00h
  db aah
  db aah
  db ffh
  db 00h
  db 00h
  db 00h
  db 00h
  db 55h
  db aah
  db 55h
  db 55h
  db ffh
  db aah
  db ffh
  db aah
  db aah
  db ffh
  db ffh
  db ffh
  db ffh
  db 00h
  db 00h
  db aah
  db aah
  db ffh
  db ffh
  db 55h
  db 55h
  db 55h
  db 55h
  db ffh
  db ffh
  db aah
  db aah
  db 55h
  db 55h
  db 00h
  db 00h
  db 55h
  db 55h
  db aah
  db 55h
  db 55h
  db 55h
  db aah
  db aah
  db aah
  db aah
  db ffh
  db ffh
  db ffh
  db ffh
  db 00h
  db 00h
  db ffh
  db ffh
  db 00h
  db 00h
  db aah
  db aah
  db aah
  db aah
  db 00h
  db aah
  db aah
  db aah
  db ffh
  db 00h
  db 00h
  db 00h
  db 00h
  db 55h
  db aah
  db 55h
  db 55h
  db 55h
  db aah
  db ffh
  db 55h
  db 55h
  db 00h
  db 55h
  db 00h
  db 55h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db 00h
  db c0h
  db 00h
  db 00h
  db c0h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
  db 80h
sub_65be endp
seg001 ends