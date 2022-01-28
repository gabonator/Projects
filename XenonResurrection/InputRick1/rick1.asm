seg001 segment	byte public 'CODE' use16
entry proc near
  call sub_0570
  call sub_0314
  mov ax, 0x1040
  mov ds, ax
loc_000b:
  call sub_0433
  jz loc_000b
  call sub_1b33
loc_0013:
  call sub_0433
  jz loc_0013
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov bx, 0x88f0
  mov cx, 0x20b
loc_0025:
  and byte ptr [bx], 0x7f
  add bx, 0x5
  loop loc_0025
  mov byte ptr [0x7d90], 0x0
  mov byte ptr [0x7d91], 0x0
  mov byte ptr [0x7e46], 0x6
  mov byte ptr [0x7e45], 0x6
  mov byte ptr [0x7e47], 0x6
  push ds
  mov ax, 0x1fc1
  mov ds, ax
  mov word ptr [0x490e], 0x3030
  mov word ptr [0x4910], 0x3030
  mov word ptr [0x4912], 0x3030
  pop ds
  call sub_1ac6
  call sub_0797
  mov al, [0x80ef]
  mov [0x7e80], al
  mov ax, [0x80f1]
  mov [0x7e82], ax
  mov byte ptr [0x7e8c], 0x18
  mov byte ptr [0x7e8e], 0x15
  mov di, word ptr [0x80f3]
  mov bx, word ptr [0x80f5]
  call sub_0e37
  mov al, [0x7e46]
  and al, al
  jnz loc_00c7
  nop
  nop
  nop
loc_0090:
  call sub_07d6
loc_0093:
  call sub_2b4d
  mov ax, 0x1fc1
  mov ds, ax
  mov ax, 0xb800
  mov es, ax
  mov bx, 0x4864
  mov word ptr [0x48ca], 0xaaaa
  mov di, 0xc8f
  call sub_1f7b
  mov ax, 0x1040
  mov ds, ax
loc_00b4:
  call sub_0433
  jnz loc_00b4
loc_00b9:
  call sub_0433
  jz loc_00b9
  call sub_265a
  call sub_2038
  jmp loc_000b
loc_00c7:
  mov byte ptr [0x7d92], 0x0
  mov byte ptr [0x7d75], 0x0
  mov byte ptr [0x7e7e], 0x1
  mov byte ptr [0x7e45], 0x6
  mov byte ptr [0x7e47], 0x6
  call sub_0d50
  call sub_0309
loc_00e6:
  call sub_044d
  jz loc_0090
  cmp byte ptr [0x7e43], 0x1
  jnz loc_00f5
  jmp loc_0198
loc_00f5:
  mov ah, 0x1
  int 0x16
  jnz loc_00fe
  nop
  nop
  nop
loc_00fe:
  mov ah, 0x2
  int 0x16
  jnz loc_0107
  nop
  nop
  nop
loc_0107:
  call sub_2241
  call sub_0270
  call sub_01a6
  call sub_0445
  jnz loc_012a
  nop
  nop
  nop
  call sub_2b4d
loc_011b:
  call sub_0445
  jz loc_011b
loc_0120:
  call sub_0445
  jnz loc_0120
loc_0125:
  call sub_0445
  jz loc_0125
loc_012a:
  mov al, [0x7d92]
  and al, al
  jz loc_0143
  nop
  nop
  nop
  mov al, [0x7e46]
  dec al
  mov [0x7e46], al
  jnz loc_0141
  jmp loc_0090
loc_0141:
  jmp loc_00c7
loc_0143:
  mov al, [0x7d76]
  and al, al
  jz loc_015c
  nop
  nop
  nop
  call sub_0d7c
  mov al, [0x7d91]
  and al, al
  jz loc_015a
  jmp loc_0093
loc_015a:
  jmp loc_00e6
loc_015c:
  call sub_07d6
  call sub_0200
  call sub_2b32
  call sub_07bb
  call sub_2b32
  call sub_07bb
  call sub_0c18
  mov al, [0x7d75]
  and al, al
  jnz loc_0195
  nop
  nop
  nop
  mov al, [0x7e82]
  cmp al, 0xcc
  jc loc_018b
  nop
  nop
  nop
  call sub_0f81
  jmp loc_0195
  db 90h
loc_018b:
  cmp al, 0x60
  jnc loc_0195
  nop
  nop
  nop
  call sub_0fef
loc_0195:
  jmp loc_00e6
loc_0198:
  call sub_0652
  call sub_0337
  call sub_2b4d
  mov ax, 0x4c00
  int 0x21
entry endp ; sp-analysis failed

sub_01a6 proc near
  cmp byte ptr [0x7d8f], 0x0
  jnz loc_01b1
  nop
  nop
  nop
  ret
loc_01b1:
  dec byte ptr [0x7d95]
  cmp byte ptr [0x7d95], 0x0
  jz loc_01c0
  nop
  nop
  nop
  ret
loc_01c0:
  mov byte ptr [0x7d95], 0x1e
  push ds
  mov ax, 0x1fc1
  mov ds, ax
  cmp word ptr [0x491c], 0x0
  jnz loc_01eb
  nop
  nop
  nop
  cmp word ptr [0x491e], 0x0
  jnz loc_01eb
  nop
  nop
  nop
  cmp byte ptr [0x4920], 0x0
  jnz loc_01eb
  nop
  nop
  nop
  pop ds
  ret
loc_01eb:
  mov bx, 0x491f
loc_01ee:
  dec byte ptr [bx]
  test byte ptr [bx], 0x80
  jz loc_01fe
  nop
  nop
  nop
  mov byte ptr [bx], 0x9
  dec bx
  jmp loc_01ee
loc_01fe:
  pop ds
  ret
sub_01a6 endp

sub_0200 proc near
  mov al, [0x7e45]
  cmp al, byte ptr [0x7d93]
  jz loc_0224
  nop
  nop
  nop
  mov [0x7d93], al
  mov word ptr [0x7337], 0x101
  mov word ptr [0x7339], 0x101
  mov word ptr [0x733b], 0x101
  call sub_02c0
loc_0224:
  mov al, [0x7e47]
  cmp al, byte ptr [0x7d94]
  jnz loc_0231
  nop
  nop
  nop
  ret
loc_0231:
  mov [0x7d94], al
  mov word ptr [0x733f], 0x101
  mov word ptr [0x7341], 0x101
  mov word ptr [0x7343], 0x101
  call sub_02cf
  ret
sub_0200 endp

sub_024a proc near
  push bx
  push cx
  mov bx, word ptr [0x7e48]
  add bx, word ptr [0x7e4a]
  add bx, 0xd
  mov cx, word ptr [0x7e4c]
  add bx, cx
  sub al, al
  xor al, bl
  xor al, ch
  xor al, cl
  xor al, bh
  mov bl, al
  mov word ptr [0x7e48], bx
  pop cx
  pop bx
  ret
sub_024a endp

sub_0270 proc near
  add word ptr [0x7e4a], 0x1
  adc word ptr [0x7e4c], 0x0
  ret
sub_0270 endp

sub_027b proc near
  push ds
  mov di, 0x145
  nop
  mov ax, 0x1fc1
  mov ds, ax
  mov ax, 0xb800
  mov es, ax
  mov bx, 0x490e
  call sub_1f89
  pop ds
  ret
sub_027b endp

sub_0292 proc near
  push ds
  mov ax, 0x1fc1
  mov ds, ax
  add si, 0x4
  mov di, 0x4913
  mov cx, 0x5
  clc
loc_02a2:
  mov al, byte ptr [di]
  adc al, byte ptr [si]
  cmp al, 0x3a
  jc loc_02b0
  nop
  nop
  nop
  sub al, 0xa
  clc
loc_02b0:
  cmc
  mov byte ptr [di], al
  dec di
  dec si
  loop loc_02a2
  mov al, byte ptr [di]
  adc al, 0x0
  mov byte ptr [di], al
  pop ds
  jmp sub_027b
sub_0292 endp

sub_02c0 proc near
  mov cl, byte ptr [0x7e45]
  sub ch, ch
  mov al, 0x1
  mov di, 0x14d
  nop
  jmp loc_02ea
  db 90h
sub_02c0 endp ; sp-analysis failed

sub_02cf proc near
  mov cl, byte ptr [0x7e47]
  sub ch, ch
  mov al, 0x2
  mov di, 0x155
  nop
  jmp loc_02ea
  db 90h
loc_02de:
  mov cl, byte ptr [0x7e46]
  sub ch, ch
  mov al, 0x3
  mov di, 0x15d
  nop
loc_02ea:
  cmp cx, 0x0
  jnz loc_02f3
  nop
  nop
  nop
  ret
loc_02f3:
  push ds
  mov bx, 0x1fc1
  mov ds, bx
  mov bx, 0xb800
  mov es, bx
loc_02fe:
  push cx
  push ax
  call sub_1fa0
  pop ax
  pop cx
  loop loc_02fe
  pop ds
  ret
sub_02cf endp

sub_0309 proc near
  call sub_027b
  call sub_02c0
  call sub_02cf
  jmp loc_02de
sub_0309 endp

sub_0314 proc near
  push ds
  mov ah, 0x35
  mov al, 0x9
  int 0x21
  mov ax, 0x1040
  mov ds, ax
  mov word ptr [0x7e3e], es
  mov word ptr [0x7e40], bx
  mov ah, 0x25
  mov al, 0x9
  mov dx, cs
  mov ds, dx
  mov dx, 0x348
  int 0x21
  pop ds
  ret
sub_0314 endp

sub_0337 proc near
  push ds
  mov dx, word ptr [0x7e40]
  mov ds, word ptr [0x7e3e]
  mov ah, 0x25
  mov al, 0x9
  int 0x21
  pop ds
  ret
sub_0337 endp

sub_0348 proc near
  sti
  push ax
  push ds
  mov ax, 0x1040
  mov ds, ax
  in al, 0x60
  mov [0x7e43], al
  in al, 0x61
  or al, 0x80
  out 0x61, al
  and al, 0x7f
  out 0x61, al
  push bx
  mov al, [0x7e43]
  mov ah, al
  and ah, 0x80
  jz loc_03ce
  nop
  nop
  nop
  mov bl, byte ptr [0x7e44]
  and al, 0x7f
  cmp al, 0x18
  jnz loc_0380
  nop
  nop
  nop
  and bl, 0xf7
  jmp loc_041d
loc_0380:
  cmp al, 0x25
  jnz loc_038d
  nop
  nop
  nop
  and bl, 0xfb
  jmp loc_041d
loc_038d:
  cmp al, 0x2c
  jnz loc_039a
  nop
  nop
  nop
  and bl, 0xfd
  jmp loc_041d
loc_039a:
  cmp al, 0x2d
  jnz loc_03a7
  nop
  nop
  nop
  and bl, 0xfe
  jmp loc_041d
  db 90h
loc_03a7:
  cmp al, 0x39
  jnz loc_03b4
  nop
  nop
  nop
  and bl, 0xef
  jmp loc_041d
  db 90h
loc_03b4:
  cmp al, 0x19
  jnz loc_03c1
  nop
  nop
  nop
  and bl, 0x7f
  jmp loc_0427
  db 90h
loc_03c1:
  cmp al, 0x12
  jnz loc_0427
  nop
  nop
  nop
  and bl, 0xbf
  jmp loc_0427
  db 90h
loc_03ce:
  mov bl, byte ptr [0x7e44]
  cmp al, 0x18
  jnz loc_03df
  nop
  nop
  nop
  or bl, 0x8
  jmp loc_041d
  db 90h
loc_03df:
  cmp al, 0x25
  jnz loc_03ec
  nop
  nop
  nop
  or bl, 0x4
  jmp loc_041d
  db 90h
loc_03ec:
  cmp al, 0x2c
  jnz loc_03f9
  nop
  nop
  nop
  or bl, 0x2
  jmp loc_041d
  db 90h
loc_03f9:
  cmp al, 0x2d
  jnz loc_0406
  nop
  nop
  nop
  or bl, 0x1
  jmp loc_041d
  db 90h
loc_0406:
  cmp al, 0x39
  jnz loc_0413
  nop
  nop
  nop
  or bl, 0x10
  jmp loc_041d
  db 90h
loc_0413:
  cmp al, 0x19
  jnz loc_041d
  nop
  nop
  nop
  or bl, 0x80
loc_041d:
  cmp al, 0x12
  jnz loc_0427
  nop
  nop
  nop
  or bl, 0x40
loc_0427:
  mov byte ptr [0x7e44], bl
  pop bx
  pop ds
  mov al, 0x61
  out 0x20, al
  pop ax
  iret
sub_0348 endp ; sp-analysis failed

sub_0433 proc near
  mov al, [0x7e44]
  and al, 0x10
  jz loc_0440
  nop
  nop
  nop
  sub al, al
  ret
loc_0440:
  sub al, al
  dec al
  ret
sub_0433 endp

sub_0445 proc near
  mov al, [0x7e44]
  and al, 0x80
  cmp al, 0x80
  ret
sub_0445 endp

sub_044d proc near
  mov al, [0x7e44]
  and al, 0x40
  cmp al, 0x40
  ret
sub_044d endp

sub_0455 proc near
  mov al, [0x7e44]
  and al, 0x80
  cmp al, 0x80
  ret
sub_0455 endp

sub_045d proc near
  push bp
  mov bp, sp
  mov ah, 0x1
  int 0x16
loc_0464:
  jnz loc_0476
  nop
  nop
  nop
  call sub_265a
  sub ah, ah
  int 0x16
  mov ah, 0x1
  int 0x16
  jz loc_0464
loc_0476:
  pop bp
  ret
sub_045d endp

sub_0478 proc near
  mov byte ptr [0x957e], 0x0
  mov ah, 0x3d
  mov al, 0x0
  int 0x21
  jc loc_048c
  nop
  nop
  nop
  mov [0x957f], ax
  ret
loc_048c:
  mov byte ptr [0x957e], 0x1
  mov dx, 0x1fc1
  push ds
  mov ds, dx
  add al, 0x30
  mov [0x490e], al
  pop ds
  call sub_027b
  ret
sub_0478 endp

sub_04a1 proc near
  mov byte ptr [0x957e], 0x0
  mov bx, word ptr [0x957f]
  mov ah, 0x3f
  int 0x21
  jc loc_04b4
  nop
  nop
  nop
  ret
loc_04b4:
  mov byte ptr [0x957e], 0x2
  ret
sub_04a1 endp

sub_04ba proc near
  mov byte ptr [0x957e], 0x0
  mov bx, word ptr [0x957f]
  push cx
  mov ax, 0x1040
  mov ds, ax
  mov ah, 0x40
  int 0x21
  pop cx
  jc loc_04e1
  nop
  nop
  nop
  cmp ax, cx
  jnz loc_04db
  nop
  nop
  nop
  ret
loc_04db:
  mov byte ptr [0x957e], 0x5
  ret
loc_04e1:
  mov byte ptr [0x957e], 0x4
  ret
sub_04ba endp

sub_04e7 proc near
  mov ah, 0x3f
  mov bx, word ptr [0x957f]
  int 0x21
  jc loc_04f5
  nop
  nop
  nop
  ret
loc_04f5:
  mov byte ptr [0x957e], 0x3
  ret
sub_04e7 endp

sub_04fb proc near
  mov dx, 0x1040
  mov ds, dx
  mov bh, 0x0
  add bx, bx
  push bx
  add bx, 0x9647
  mov dx, word ptr [bx]
  mov word ptr [0x9669], dx
  pop bx
  push bx
  add bx, 0x962f
  mov dx, word ptr [bx]
  mov word ptr [0x966b], dx
  pop bx
  add bx, 0x9615
  mov dx, word ptr [bx]
  call sub_0478
  mov al, [0x957e]
  cmp al, 0x0
  jnz loc_0557
  nop
  nop
  nop
  mov dx, 0x1040
  mov ds, dx
  mov dx, word ptr [0x966b]
  mov cx, word ptr [0x9669]
  call sub_04a1
  mov al, [0x957e]
  cmp al, 0x0
  jnz loc_0557
  nop
  nop
  nop
  call sub_04e7
  mov al, [0x957e]
  cmp al, 0x0
  jnz loc_0557
  nop
  nop
  nop
  ret
loc_0557:
  mov bh, 0x0
  mov bl, byte ptr [0x957e]
  dec bl
  add bl, bl
  add bx, 0x96fc
  mov dx, word ptr [bx]
  mov ah, 0x9
  int 0x21
  mov ah, 0x8
  int 0x21
  ret
sub_04fb endp

sub_0570 proc near
  mov ah, 0x4a
  mov bx, 0x3000
  int 0x21
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov ax, 0x2455
  mov [0x9661], ax
  mov ah, 0x48
  mov bx, 0xfff
  int 0x21
  jc sub_0570
  mov [0x9663], ax
  mov ah, 0x48
  mov bx, 0xfff
  int 0x21
  jc sub_0570
  mov [0x9665], ax
  mov ah, 0x48
  mov bx, 0xfff
  int 0x21
  jc sub_0570
  mov [0x9667], ax
  mov ah, 0xf
  int 0x10
  mov [0x7e42], al
  mov ax, 0xd
  int 0x10
  mov ax, 0x1040
  mov ds, ax
  call sub_06f8
  mov ax, 0x1fc1
  mov ds, ax
  mov ax, 0x1040
  mov es, ax
  mov si, 0x0
  mov di, 0x223a
  mov cx, 0x2000
  cld
  rep movsb
  mov dx, 0x2000
  call sub_0661
  mov ax, 0x1fc1
  mov ds, ax
  mov ax, 0x1040
  mov es, ax
  mov si, 0x2000
  mov di, 0x223a
  mov cx, 0x2000
  cld
  rep movsb
  mov dx, 0x2800
  call sub_0661
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov si, 0x9810
  mov di, 0x223a
  mov cx, 0x2000
  cld
  rep movsb
  mov dx, 0x3000
  call sub_0661
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov si, 0xd810
  mov di, 0x223a
  mov cx, 0x2000
  cld
  rep movsb
  mov dx, 0x3800
  call sub_0661
  mov ax, 0x1fc1
  mov es, ax
  mov byte ptr [0x7d90], 0x0
  call sub_0786
  mov ax, 0x9810
  mov [0x7d5e], ax
  mov ax, 0x3000
  mov [0x971a], ax
  mov dx, 0x3ce
  mov ax, 0x105
  out dx, ax
  mov ax, 0x1
  out dx, ax
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  ret
sub_0570 endp

sub_0652 proc near
  push ds
  mov ax, 0x1040
  mov ds, ax
  mov al, [0x7e42]
  mov ah, 0x0
  int 0x10
  pop ds
  ret
sub_0652 endp

sub_0661 proc near
  push ds
  push bp
  push dx
  mov bp, sp
  mov dx, 0x3ce
  mov ax, 0x1
  out dx, ax
  mov al, 0x3
  out dx, ax
  mov al, 0x5
  out dx, ax
  mov ax, 0xff08
  out dx, ax
  mov ax, 0xa000
  mov es, ax
  mov ax, 0x1040
  mov ds, ax
  mov dx, 0x3c4
  mov ax, 0x102
  out dx, ax
  mov di, word ptr [bp+0x0]
  mov cx, 0x800
  mov si, 0x223a
  rep movsb
  mov cx, 0x800
  mov si, 0x423a
  rep movsb
  mov ax, 0x202
  out dx, ax
  mov di, word ptr [bp+0x0]
  mov cx, 0x800
  mov si, 0x2a3a
  rep movsb
  mov cx, 0x800
  mov si, 0x4a3a
  rep movsb
  mov ax, 0x402
  out dx, ax
  mov di, word ptr [bp+0x0]
  mov si, 0x323a
  mov cx, 0x800
  rep movsb
  mov si, 0x523a
  mov cx, 0x800
  rep movsb
  mov ax, 0x802
  out dx, ax
  pop di
  mov cx, 0x800
  mov si, 0x3a3a
  rep movsb
  mov cx, 0x800
  mov si, 0x5a3a
  rep movsb
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  pop bp
  pop ds
  ret
sub_0661 endp

sub_06e8 proc near
  ret
sub_06e8 endp

sub_06e9 proc near
  push ds
  push es
  mov ax, 0x2455
  mov es, ax
  mov si, 0x9810
  rep movsw
  pop es
  pop ds
  ret
sub_06e9 endp

sub_06f8 proc near
  push ds
  push es
  sub dx, dx
  mov ax, 0x1040
  mov ds, ax
  mov dx, word ptr [0x9663]
  mov ax, 0x2455
  mov ds, ax
  mov es, dx
  call sub_0736
  mov ax, 0x1040
  mov ds, ax
  mov dx, word ptr [0x9665]
  push es
  pop ds
  mov ax, dx
  mov es, ax
  call sub_0736
  mov ax, 0x1040
  mov ds, ax
  mov dx, word ptr [0x9667]
  push es
  pop ds
  mov ax, dx
  mov es, ax
  call sub_0736
  pop es
  pop ds
  ret
sub_06f8 endp

sub_0736 proc near
  mov di, 0x0
  mov cx, 0x9a
loc_073c:
  push cx
  push di
  mov cx, 0x15
loc_0741:
  push cx
  mov ax, word ptr [di]
  mov bx, word ptr [di+0xa]
  stc
  rcr ax, 1
  rcr bx, 1
  stc
  rcr ax, 1
  rcr bx, 1
  mov word ptr es:[di], ax
  mov word ptr es:[di+0xa], bx
  add di, 0x2
  mov cx, 0x4
loc_075e:
  mov ax, word ptr [di]
  mov bx, word ptr [di+0xa]
  shr ax, 1
  rcr bx, 1
  shr ax, 1
  rcr bx, 1
  mov word ptr es:[di], ax
  mov word ptr es:[di+0xa], bx
  add di, 0x2
  loop loc_075e
  add di, 0xa
  pop cx
  loop loc_0741
  pop di
  add di, 0x1a4
  pop cx
  loop loc_073c
  ret
sub_0736 endp

sub_0786 proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov dx, 0x9709
  mov ax, 0x1002
  int 0x10
  ret
  db c3h
sub_0786 endp ; sp-analysis failed

sub_0797 proc near
  push es
  mov ax, 0xa000
  mov es, ax
  mov dx, 0x3ce
  mov ax, 0x5
  out dx, ax
  mov al, 0x1
  out dx, ax
  mov al, 0x5
  out dx, ax
  sub ax, ax
  mov di, ax
  mov ax, di
  mov cx, 0xfa0
  rep stosw
  mov ax, 0x105
  out dx, ax
  pop es
  ret
sub_0797 endp

sub_07bb proc near
  mov dx, 0x3da
loc_07be:
  in al, dx
  and al, 0x8
  jnz loc_07be
loc_07c3:
  in al, dx
  and al, 0x8
  jz loc_07c3
  ret
sub_07bb endp

sub_07c9 proc near
  cmp byte ptr [0x7e43], 0x39
  jnz sub_07c9
  mov byte ptr [0x7e43], 0x0
  ret
sub_07c9 endp

sub_07d6 proc near
  mov dx, 0x3ce
  mov ax, 0x1
  out dx, ax
  mov al, 0x3
  out dx, ax
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov ax, 0x23a
  mov [0x7d96], ax
  mov ax, 0x2
  mov [0x7e3c], ax
  mov si, 0x7e4e
loc_07f6:
  mov al, byte ptr [si]
  or al, al
  jz loc_0809
  nop
  nop
  nop
  cmp al, 0xff
  jz loc_080e
  nop
  nop
  nop
  call sub_087e
loc_0809:
  add si, 0x30
  jmp loc_07f6
loc_080e:
  mov dx, 0x3ce
  mov ax, 0x1
  out dx, ax
  mov al, 0x3
  out dx, ax
  mov al, 0x5
  out dx, ax
  mov ax, 0xff08
  out dx, ax
  mov ax, 0xa000
  mov es, ax
  mov bx, word ptr [0x7e3c]
  sub bx, 0x2
  mov dx, 0x3c4
  mov ax, 0x102
  out dx, ax
  mov si, 0x23a
  mov di, 0x4000
  mov cx, bx
loc_083a:
  movsw
  movsw
  movsw
  movsw
  loop loc_083a
  mov ah, 0x2
  out dx, ax
  mov si, 0xa3a
  mov di, 0x4000
  mov cx, bx
loc_084b:
  movsw
  movsw
  movsw
  movsw
  loop loc_084b
  mov ah, 0x4
  out dx, ax
  mov si, 0x123a
  mov di, 0x4000
  mov cx, bx
loc_085c:
  movsw
  movsw
  movsw
  movsw
  loop loc_085c
  mov ah, 0x8
  out dx, ax
  mov si, 0x1a3a
  mov di, 0x4000
  mov cx, bx
loc_086d:
  movsw
  movsw
  movsw
  movsw
  loop loc_086d
  mov ah, 0xf
  out dx, ax
  mov dx, 0x3ce
  mov ax, 0x105
  out dx, ax
  ret
sub_07d6 endp

sub_087e proc near
  push si
  mov bl, byte ptr [si+0x8]
  sub bh, bh
  add bx, bx
  add bx, 0x100
  mov ax, word ptr [bx]
  push ax
  mov ax, word ptr [si+0x4]
  mov dl, al
  and ax, 0x1f8
  add ax, ax
  add ax, ax
  mov bx, word ptr [si+0x2]
  mov dh, bl
  mov cl, 0x3
  shr bx, cl
  add ax, bx
  add ax, 0x778e
  mov si, ax
  and dl, 0x7
  test dl, 0x4
  jz loc_08b7
  nop
  nop
  nop
  jmp loc_09fb
loc_08b7:
  mov di, word ptr [0x7d96]
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x3f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x3f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x3f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  mov word ptr [0x7d96], di
  sub di, 0x60
  mov al, dl
  mov ah, 0x0
  add di, ax
  pop si
  mov bl, dh
  mov bh, 0x0
  and bl, 0x6
  mov ax, 0x9661
  add bx, ax
  push ds
  push es
  push ds
  pop es
  mov ax, word ptr [bx]
  mov ds, ax
  mov cx, 0x15
loc_0925:
  lodsw
  mov bh, byte ptr es:[di]
  mov bl, byte ptr es:[di+0x18]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di], bh
  mov byte ptr es:[di+0x18], bl
  mov bh, byte ptr es:[di+0x800]
  mov bl, byte ptr es:[di+0x818]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x800], bh
  mov byte ptr es:[di+0x818], bl
  mov bh, byte ptr es:[di+0x1000]
  mov bl, byte ptr es:[di+0x1018]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1000], bh
  mov byte ptr es:[di+0x1018], bl
  mov bh, byte ptr es:[di+0x1800]
  mov bl, byte ptr es:[di+0x1818]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1800], bh
  mov byte ptr es:[di+0x1818], bl
  lodsw
  mov bh, byte ptr es:[di+0x30]
  mov bl, byte ptr es:[di+0x48]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x30], bh
  mov byte ptr es:[di+0x48], bl
  mov bh, byte ptr es:[di+0x830]
  mov bl, byte ptr es:[di+0x848]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x830], bh
  mov byte ptr es:[di+0x848], bl
  mov bh, byte ptr es:[di+0x1030]
  mov bl, byte ptr es:[di+0x1048]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1030], bh
  mov byte ptr es:[di+0x1048], bl
  mov bh, byte ptr es:[di+0x1830]
  mov bl, byte ptr es:[di+0x1848]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1830], bh
  mov byte ptr es:[di+0x1848], bl
  inc di
  dec cx
  jz loc_09f7
  nop
  nop
  nop
  jmp loc_0925
loc_09f7:
  pop es
  pop ds
  pop si
  ret
loc_09fb:
  mov di, word ptr [0x7d96]
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x5f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x5f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, -0x5f
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  add si, 0x20
  call sub_0b58
  mov word ptr [0x7d96], di
  sub di, 0x80
  mov al, dl
  mov ah, 0x0
  add di, ax
  pop si
  mov bl, dh
  mov bh, 0x0
  and bl, 0x6
  mov ax, 0x9661
  add bx, ax
  push ds
  push es
  push ds
  pop es
  mov ax, word ptr [bx]
  mov ds, ax
  mov cx, 0x15
loc_0a82:
  lodsw
  mov bh, byte ptr es:[di]
  mov bl, byte ptr es:[di+0x20]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di], bh
  mov byte ptr es:[di+0x20], bl
  mov bh, byte ptr es:[di+0x800]
  mov bl, byte ptr es:[di+0x820]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x800], bh
  mov byte ptr es:[di+0x820], bl
  mov bh, byte ptr es:[di+0x1000]
  mov bl, byte ptr es:[di+0x1020]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1000], bh
  mov byte ptr es:[di+0x1020], bl
  mov bh, byte ptr es:[di+0x1800]
  mov bl, byte ptr es:[di+0x1820]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1800], bh
  mov byte ptr es:[di+0x1820], bl
  lodsw
  mov bh, byte ptr es:[di+0x40]
  mov bl, byte ptr es:[di+0x60]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x40], bh
  mov byte ptr es:[di+0x60], bl
  mov bh, byte ptr es:[di+0x840]
  mov bl, byte ptr es:[di+0x860]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x840], bh
  mov byte ptr es:[di+0x860], bl
  mov bh, byte ptr es:[di+0x1040]
  mov bl, byte ptr es:[di+0x1060]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1040], bh
  mov byte ptr es:[di+0x1060], bl
  mov bh, byte ptr es:[di+0x1840]
  mov bl, byte ptr es:[di+0x1860]
  and bx, ax
  or bx, word ptr [si]
  inc si
  inc si
  mov byte ptr es:[di+0x1840], bh
  mov byte ptr es:[di+0x1860], bl
  inc di
  dec cx
  jz loc_0b54
  nop
  nop
  nop
  jmp loc_0a82
loc_0b54:
  pop es
  pop ds
  pop si
  ret
sub_087e endp

sub_0b58 proc near
  mov bx, 0x0
  mov bl, byte ptr [si]
  sub ah, ah
  mov al, byte ptr [bx]
  test al, 0x8
  mov al, bl
  jz loc_0b75
  nop
  nop
  nop
  mov ax, [0x7e3c]
  inc ax
  mov [0x7e3c], ax
  add di, 0x8
  ret
loc_0b75:
  push si
  sub si, 0x778e
  add si, 0x720e
  mov cx, word ptr [0x7d5e]
  mov bl, byte ptr [si]
  cmp bl, 0x2
  jc loc_0b91
  nop
  nop
  nop
  mov al, bl
  mov cx, 0x22a
loc_0b91:
  mov bx, word ptr [0x7e3c]
  mov byte ptr [si], bl
  inc bx
  mov word ptr [0x7e3c], bx
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, cx
  mov si, ax
  mov ax, word ptr [si+0x1800]
  mov word ptr es:[di+0x1800], ax
  mov ax, word ptr [si+0x1000]
  mov word ptr es:[di+0x1000], ax
  mov ax, word ptr [si+0x800]
  mov word ptr es:[di+0x800], ax
  movsw
  mov ax, word ptr [si+0x1800]
  mov word ptr es:[di+0x1800], ax
  mov ax, word ptr [si+0x1000]
  mov word ptr es:[di+0x1000], ax
  mov ax, word ptr [si+0x800]
  mov word ptr es:[di+0x800], ax
  movsw
  mov ax, word ptr [si+0x1800]
  mov word ptr es:[di+0x1800], ax
  mov ax, word ptr [si+0x1000]
  mov word ptr es:[di+0x1000], ax
  mov ax, word ptr [si+0x800]
  mov word ptr es:[di+0x800], ax
  movsw
  mov ax, word ptr [si+0x1800]
  mov word ptr es:[di+0x1800], ax
  mov ax, word ptr [si+0x1000]
  mov word ptr es:[di+0x1000], ax
  mov ax, word ptr [si+0x800]
  mov word ptr es:[di+0x800], ax
  movsw
  pop si
  ret
sub_0b58 endp

sub_0c18 proc near
  mov ax, 0x1040
  mov es, ax
  mov ds, ax
  call sub_0ead
  mov ax, 0xa000
  mov es, ax
  mov si, 0x730e
  mov di, 0x4
  mov bx, 0x18
loc_0c30:
  mov cx, 0x20
  sub ax, ax
loc_0c35:
  or al, byte ptr [si]
  jnz loc_0c48
  nop
  nop
  nop
loc_0c3c:
  inc di
  inc si
  loop loc_0c35
  add di, 0x120
  dec bx
  jnz loc_0c30
  ret
loc_0c48:
  push bx
  push di
  push si
  push ds
  cmp ax, 0x1
  jnz loc_0c94
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  sub si, 0x730e
  add si, 0x788e
  mov ah, 0x0
  mov al, byte ptr [si]
  mov bx, word ptr [0x971a]
loc_0c67:
  push es
  pop ds
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, bx
  mov si, ax
  mov bx, 0x27
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  pop ds
  pop si
  pop di
  pop bx
  sub ax, ax
  jmp loc_0c3c
loc_0c94:
  mov byte ptr [si], 0x1
  mov bx, 0x3ff0
  jmp loc_0c67
sub_0c18 endp

sub_0c9c proc near
  mov ax, 0x1040
  mov es, ax
  mov ds, ax
  call sub_0ead
  mov ax, 0xa000
  mov es, ax
  mov si, 0x730e
  mov di, 0x4
  mov bx, 0x18
loc_0cb4:
  mov cx, 0x20
  sub ax, ax
loc_0cb9:
  or al, byte ptr [si]
  jnz loc_0ccc
  nop
  nop
  nop
loc_0cc0:
  inc di
  inc si
  loop loc_0cb9
  add di, 0x120
  dec bx
  jnz loc_0cb4
  ret
loc_0ccc:
  push bx
  push di
  push si
  push ds
  cmp ax, 0x1
  jnz loc_0d18
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  sub si, 0x730e
  add si, 0x788e
  mov ah, 0x0
  mov al, byte ptr [si]
  mov bx, word ptr [0x971a]
loc_0ceb:
  push es
  pop ds
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, bx
  mov si, ax
  mov bx, 0x27
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  add di, bx
  movsb
  pop ds
  pop si
  pop di
  pop bx
  sub ax, ax
  jmp loc_0cc0
loc_0d18:
  mov bx, 0x3ff0
  jmp loc_0ceb
sub_0c9c endp

sub_0d1d proc near
  mov ax, 0x1040
  mov ds, ax
  mov si, 0x730e
  mov cx, 0x300
loc_0d28:
  mov byte ptr [si], 0x1
  inc si
  loop loc_0d28
  ret
sub_0d1d endp

sub_0d2f proc near
  mov al, [0x7d68]
  mov [0x7d88], al
  mov ax, [0x7e82]
  mov [0x7d8a], ax
  mov al, [0x7e80]
  mov [0x7d89], al
  mov al, [0x7e8a]
  mov [0x7d8c], al
  mov al, [0x7e38]
  sub ah, ah
  mov [0x7d8d], al
  ret
sub_0d2f endp

sub_0d50 proc near
  mov al, [0x7d88]
  mov [0x7d68], al
  mov al, [0x7d89]
  mov [0x7e80], al
  mov ax, [0x7d8a]
  mov [0x7e82], ax
  mov al, [0x7d8c]
  mov [0x7e8a], al
  mov bl, byte ptr [0x7d8d]
  mov byte ptr [0x7e38], bl
  mov byte ptr [0x7d85], 0x0
  mov di, word ptr [0x7d60]
  jmp sub_0e37
sub_0d50 endp

sub_0d7c proc near
  mov byte ptr [0x7d76], 0x0
  mov byte ptr [0x7d8f], 0x0
  mov si, word ptr [0x7d62]
  mov ax, [0x7e82]
  shr ax, 1
  shr ax, 1
  shr ax, 1
  add al, byte ptr [0x7e38]
  mov cl, al
  mov bl, byte ptr [0x7d77]
loc_0d9d:
  cmp bl, byte ptr [si]
  jz loc_0da4
  jmp loc_0e31
loc_0da4:
  mov al, cl
  sub al, byte ptr [si+0x1]
  cmp al, 0x3
  jc loc_0db0
  jmp loc_0e31
loc_0db0:
  mov al, byte ptr [si+0x1]
  sub al, byte ptr [si+0x4]
  mov bl, byte ptr [0x7e38]
  sub bl, al
  sub bh, bh
  mov di, word ptr [si+0x2]
  cmp di, 0xff
  jnz sub_0e37
  nop
  nop
  nop
  mov byte ptr [0x7e45], 0x6
  mov byte ptr [0x7e47], 0x6
  mov al, [0x7d90]
  inc al
  mov [0x7d90], al
  cmp al, 0x4
  jnz loc_0df1
  nop
  nop
  nop
  mov al, [0x7e46]
  inc al
  mov [0x4916], al
  mov si, 0x4916
  call sub_0292
loc_0df1:
  push ds
  call sub_1ac6
  pop ds
  mov al, [0x7d90]
  cmp al, 0x4
  jc loc_0e06
  nop
  nop
  nop
  mov byte ptr [0x7d91], 0xff
  ret
loc_0e06:
  mov bl, byte ptr [0x7d90]
  sub bh, bh
  add bx, bx
  add bx, bx
  add bx, bx
  add bx, 0x80ef
  mov al, byte ptr [bx]
  mov [0x7e80], al
  inc bx
  inc bx
  mov ax, word ptr [bx]
  mov [0x7e82], ax
  inc bx
  inc bx
  mov di, word ptr [bx]
  inc bx
  inc bx
  mov bx, word ptr [bx]
  call sub_0e37
  call sub_0309
  ret
loc_0e31:
  add si, 0x6
  jmp loc_0d9d
sub_0d7c endp

sub_0e37 proc near
  mov word ptr [0x7d60], di
  mov byte ptr [0x7d76], 0x0
  mov si, 0x7d0e
  mov cx, 0x9810
  mov dx, 0x3000
  mov ax, word ptr [di]
  and ax, ax
  jz loc_0e5b
  nop
  nop
  nop
  mov si, 0x7d1e
  mov cx, 0xd810
  mov dx, 0x3800
loc_0e5b:
  mov word ptr [0x7d5e], cx
  mov word ptr [0x971a], dx
  mov ax, word ptr [di+0x2]
  mov [0x7e3a], ax
  mov byte ptr [0x7e38], bl
  mov ax, word ptr [di+0x4]
  mov [0x7d62], ax
  mov ax, word ptr [di+0x6]
  mov [0x7d64], ax
  call sub_1295
  call sub_0edb
  call sub_2669
  mov dh, byte ptr [0x7e38]
  add dh, 0x8
  mov dl, 0x18
  call sub_2089
  mov dh, byte ptr [0x7e38]
  mov dl, 0x8
  call sub_2089
  mov dh, byte ptr [0x7e38]
  add dh, 0x20
  mov dl, 0x8
  call sub_2089
  call sub_0d1d
  call sub_0c9c
  call sub_0d2f
  ret
sub_0e37 endp

sub_0ead proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov ax, 0x0
  mov di, 0x732f
  stosw
  stosw
  stosw
  mov cl, byte ptr [0x7e45]
  sub ch, ch
  mov di, 0x7337
  rep stosb
  mov cl, byte ptr [0x7e47]
  mov di, 0x733f
  rep stosb
  mov cl, byte ptr [0x7e46]
  mov di, 0x7347
  rep stosb
  ret
sub_0ead endp

sub_0edb proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov di, 0x778e
  mov al, [0x7e38]
  sub ah, ah
  add ax, ax
  and ax, 0xfff8
  add ax, word ptr [0x7e3a]
  mov bx, ax
  mov dh, 0xb
loc_0ef7:
  mov cx, 0x8
loc_0efa:
  mov al, byte ptr [bx]
  inc bx
  mov ah, 0x0
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, 0x423a
  mov si, ax
  movsw
  movsw
  add di, 0x1c
  movsw
  movsw
  add di, 0x1c
  movsw
  movsw
  add di, 0x1c
  movsw
  movsw
  add di, -0x60
  loop loc_0efa
  add di, 0x60
  dec dh
  jnz loc_0ef7
  ret
sub_0edb endp

sub_0f2a proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  cld
  mov di, 0x788e
  mov si, 0x78ae
  mov bx, 0x730e
  mov dl, 0x1
  mov cx, 0x3e0
loc_0f40:
  inc bx
  cmpsb
  jnz loc_0f4b
  nop
  nop
  nop
loc_0f47:
  dec cx
  jnz loc_0f40
  ret
loc_0f4b:
  dec si
  dec di
  movsb
  dec bx
  mov al, byte ptr [bx]
  cmp al, 0x2
  jnc loc_0f5b
  nop
  nop
  nop
  mov byte ptr [bx], 0x1
loc_0f5b:
  inc bx
  jmp loc_0f47
sub_0f2a endp

sub_0f5e proc near
  mov si, 0x730e
  mov cx, 0x400
  mov al, 0x1
loc_0f66:
  cmp al, byte ptr [si]
  jc loc_0f71
  nop
  nop
  nop
loc_0f6d:
  inc si
  loop loc_0f66
  ret
loc_0f71:
  mov al, byte ptr [si]
  sub si, 0x20
  mov byte ptr [si], al
  add si, 0x20
  mov al, 0x1
  mov byte ptr [si], al
  jmp loc_0f6d
sub_0f5e endp

sub_0f81 proc near
  call sub_10fa
  call sub_07d6
  mov cx, 0x8
loc_0f8a:
  push cx
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  call sub_0f2a
  call sub_0f5e
  mov bx, 0xfff8
  call sub_10b2
  mov cx, 0x1
loc_0fa1:
  push cx
  call sub_07bb
  pop cx
  loop loc_0fa1
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  cld
  mov si, 0x732e
  mov di, 0x7d2e
  mov cx, 0x10
  rep movsw
  call sub_0c9c
  call sub_2b32
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  cld
  mov si, 0x7d2e
  mov di, 0x732e
  mov cx, 0x10
  rep movsw
  mov ax, [0x7e38]
  inc ax
  mov [0x7e38], ax
  pop cx
  loop loc_0f8a
  mov dh, al
  add dh, 0x20
  mov dl, 0x8
  call sub_2089
  call sub_0edb
  call sub_0c18
  ret
sub_0f81 endp

sub_0fef proc near
  call sub_10fa
  call sub_07d6
  mov cx, 0x8
loc_0ff8:
  push cx
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  call sub_108f
  call sub_105a
  mov bx, 0x8
  call sub_10b2
  mov cx, 0x1
loc_100f:
  push cx
  call sub_07bb
  pop cx
  loop loc_100f
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  cld
  mov si, 0x732e
  mov di, 0x7d2e
  mov cx, 0x10
  rep movsw
  call sub_0c9c
  call sub_2b32
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  cld
  mov si, 0x7d2e
  mov di, 0x732e
  mov cx, 0x10
  rep movsw
  mov ax, [0x7e38]
  dec ax
  mov [0x7e38], ax
  pop cx
  loop loc_0ff8
  mov dh, al
  mov dl, 0x8
  call sub_2089
  call sub_0edb
  call sub_0c18
  ret
sub_0fef endp

sub_105a proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  std
  mov di, 0x7b8e
  mov si, 0x7b6e
  mov bx, 0x760e
  mov dl, 0x1
  mov cx, 0x400
loc_1070:
  dec bx
  cmpsb
  jnz loc_107c
  nop
  nop
  nop
loc_1077:
  dec cx
  jnz loc_1070
  cld
  ret
loc_107c:
  inc si
  inc di
  movsb
  inc bx
  mov al, byte ptr [bx]
  cmp al, 0x2
  jnc loc_108c
  nop
  nop
  nop
  mov byte ptr [bx], 0x1
loc_108c:
  dec bx
  jmp loc_1077
sub_105a endp

sub_108f proc near
  mov si, 0x760e
  mov cx, 0x420
  mov al, 0x1
loc_1097:
  cmp al, byte ptr [si]
  jc loc_10a2
  nop
  nop
  nop
loc_109e:
  dec si
  loop loc_1097
  ret
loc_10a2:
  mov al, byte ptr [si]
  add si, 0x20
  mov byte ptr [si], al
  sub si, 0x20
  mov al, 0x1
  mov byte ptr [si], al
  jmp loc_109e
sub_108f endp

sub_10b2 proc near
  mov ax, 0x1040
  mov ds, ax
  mov si, 0x7e4e
loc_10ba:
  cmp byte ptr [si], 0x0
  jz loc_10f4
  nop
  nop
  nop
  cmp byte ptr [si], 0xff
  jz loc_10f9
  nop
  nop
  nop
  add word ptr [si+0x1e], bx
  add word ptr [si+0x18], bx
  mov ax, word ptr [si+0x4]
  add ax, bx
  test ah, 0x80
  jz loc_10e3
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  jmp loc_10f4
  db 90h
loc_10e3:
  cmp ax, 0x140
  jc loc_10f1
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  jmp loc_10f4
  db 90h
loc_10f1:
  mov word ptr [si+0x4], ax
loc_10f4:
  add si, 0x30
  jmp loc_10ba
loc_10f9:
  ret
sub_10b2 endp

sub_10fa proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov ax, 0x0
  mov di, 0x720e
  mov cx, 0x80
  rep stosw
  mov di, 0x760e
  mov cx, 0x80
  rep stosw
  ret
sub_10fa endp

sub_1115 proc near
  and dx, 0xf8
  add dx, dx
  add dx, dx
  mov al, bl
  shr bl, 1
  shr bl, 1
  shr bl, 1
  sub bh, bh
  add dx, bx
  mov bx, 0x778e
  add bx, dx
  mov al, byte ptr [bx]
  mov bx, 0x0
  mov bl, al
  mov al, byte ptr [bx]
  and al, 0x40
  ret
sub_1115 endp

sub_113a proc near
  push ax
  push cx
  push bx
  push dx
  mov byte ptr [0x7d74], 0x0
  add bl, 0x4
  mov cx, 0x1
  test dl, 0x4
  jz loc_1152
  nop
  nop
  nop
  inc cx
loc_1152:
  and dx, 0x1f8
  add dx, dx
  add dx, dx
  mov al, bl
  shr bl, 1
  shr bl, 1
  shr bl, 1
  sub bh, bh
  add dx, bx
  mov bx, 0x778e
  add dx, bx
  mov di, dx
  mov bx, 0x0
  sub dl, dl
  and al, 0x7
  jz loc_119f
  nop
  nop
  nop
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0xf0
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0xf0
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0xf0
  or dl, al
  add di, 0x1e
  mov byte ptr [0x7d74], dl
  sub dl, dl
  jmp loc_11fc
  db 90h
loc_119f:
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0xf0
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0xf0
  or dl, al
  add di, 0x1f
  mov byte ptr [0x7d74], dl
  sub dl, dl
  jmp loc_1238
  db 90h
sub_113a endp ; sp-analysis failed

sub_11bc proc near
  push ax
  push cx
  push bx
  push dx
  mov byte ptr [0x7d67], 0x0
  add bl, 0x4
  mov cx, 0x2
  test dx, 0x4
  jz loc_11d5
  nop
  nop
  nop
  inc cx
loc_11d5:
  and dx, 0x1f8
  add dx, dx
  add dx, dx
  mov al, bl
  shr bl, 1
  shr bl, 1
  shr bl, 1
  sub bh, bh
  add dx, bx
  mov bx, 0x778e
  add dx, bx
  mov di, dx
  mov bx, 0x0
  sub dl, dl
  and al, 0x7
  jz loc_1238
  nop
  nop
  nop
loc_11fc:
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x6d
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x6f
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x6d
  or dl, al
  add di, 0x1e
  loop loc_11fc
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x7d
  or dl, al
  inc di
  mov bl, byte ptr [di]
  or dl, byte ptr [bx]
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x7d
  or dl, al
  mov byte ptr [0x7d67], dl
  jmp loc_125b
  db 90h
loc_1238:
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x6f
  or dl, al
  inc di
  mov bl, byte ptr [di]
  mov al, byte ptr [bx]
  and al, 0x6f
  or dl, al
  add di, 0x1f
  loop loc_1238
  mov bl, byte ptr [di]
  or dl, byte ptr [bx]
  inc di
  mov bl, byte ptr [di]
  or dl, byte ptr [bx]
  mov byte ptr [0x7d67], dl
loc_125b:
  test byte ptr [0x7d67], 0x40
  jnz loc_1290
  nop
  nop
  nop
  cmp byte ptr [0x7e4e], 0x0
  jz loc_1290
  nop
  nop
  nop
  pop dx
  pop bx
  push bx
  push dx
  push si
  push di
  mov di, 0x808f
  mov byte ptr [di+0x2], bl
  mov word ptr [di+0x4], dx
  mov si, 0x7e4e
  call sub_12bc
  pop di
  pop si
  jnz loc_1290
  nop
  nop
  nop
  or byte ptr [0x7d67], 0x40
loc_1290:
  pop dx
  pop bx
  pop cx
  pop ax
  ret
sub_11bc endp

sub_1295 proc near
  mov di, 0x0
  mov ax, 0x1040
  mov ds, ax
  mov cx, 0x8
loc_12a0:
  mov ax, word ptr [si]
loc_12a2:
  mov byte ptr [di], ah
  inc di
  dec al
  jnz loc_12a2
  inc si
  inc si
  loop loc_12a0
  ret
sub_1295 endp

sub_12ae proc near
  cmp byte ptr [0x7d75], 0x0
  jz loc_12b9
  nop
  nop
  nop
  ret
loc_12b9:
  mov di, 0x7e7e
sub_12ae endp ; sp-analysis failed

sub_12bc proc near
  mov al, byte ptr [di+0x2]
  add al, 0x11
  mov ah, byte ptr [si+0x2]
  cmp al, ah
  jc loc_1312
  nop
  nop
  nop
  sub al, 0xc
  add ah, byte ptr [si+0xe]
  cmp ah, al
  jc loc_1312
  nop
  nop
  nop
  mov ax, word ptr [di+0x4]
  add ax, 0x14
  mov bx, word ptr [si+0x4]
  cmp ax, bx
  jc loc_1312
  nop
  nop
  nop
  mov ax, word ptr [di+0x4]
  cmp byte ptr [di], 0x1
  jnz loc_12ff
  nop
  nop
  nop
  cmp byte ptr [0x7d68], 0x0
  jz loc_12ff
  nop
  nop
  nop
  add ax, 0x8
loc_12ff:
  mov cl, byte ptr [si+0x10]
  dec cl
  sub ch, ch
  add bx, cx
  cmp bx, ax
  jc loc_1312
  nop
  nop
  nop
  sub al, al
  ret
loc_1312:
  sub al, al
  dec al
  ret
sub_12bc endp

sub_1317 proc near
  mov al, byte ptr [si+0x2]
  cmp al, bl
  jnc loc_1346
  nop
  nop
  nop
  add al, byte ptr [si+0xe]
  cmp al, bl
  jc loc_1346
  nop
  nop
  nop
  mov ax, word ptr [si+0x4]
  cmp dx, ax
  jc loc_1346
  nop
  nop
  nop
  mov cl, byte ptr [si+0x10]
  sub ch, ch
  add ax, cx
  cmp ax, dx
  jc loc_1346
  nop
  nop
  nop
  sub al, al
  ret
loc_1346:
  sub al, al
  dec al
  ret
sub_1317 endp

sub_134b proc near
  mov al, [0x7ee0]
  mov ah, al
  sub al, 0x4
  jnc loc_1359
  nop
  nop
  nop
  sub al, al
loc_1359:
  add ah, 0x20
  jnc loc_1363
  nop
  nop
  nop
  mov ah, 0xff
loc_1363:
  mov bl, byte ptr [si+0x2]
  cmp ah, bl
  jc loc_13a7
  nop
  nop
  nop
  add bl, byte ptr [si+0xe]
  cmp bl, al
  jc loc_13a7
  nop
  nop
  nop
  mov ax, [0x7ee2]
  mov bx, ax
  sub ax, 0x4
  test ah, 0x80
  jz loc_1389
  nop
  nop
  nop
  sub ax, ax
loc_1389:
  add bx, 0x1d
  mov cx, word ptr [si+0x4]
  cmp bx, cx
  jc loc_13a7
  nop
  nop
  nop
  mov dl, byte ptr [si+0x10]
  sub dh, dh
  add cx, dx
  cmp cx, ax
  jc loc_13a7
  nop
  nop
  nop
  sub al, al
  ret
loc_13a7:
  sub al, al
  dec al
  ret
sub_134b endp

sub_13ac proc near
  push si
  pop di
  test byte ptr [0x7e4e], 0x80
  jz loc_13c3
  nop
  nop
  nop
  mov si, 0x7e4e
  call sub_12bc
  jz loc_13db
  nop
  nop
  nop
loc_13c3:
  mov cx, 0x5
  mov si, 0x7f0e
loc_13c9:
  push cx
  test byte ptr [si], 0x80
  jz loc_13e0
  nop
  nop
  nop
  call sub_12bc
  jnz loc_13e0
  nop
  nop
  nop
  pop cx
loc_13db:
  push di
  pop si
  sub al, al
  ret
loc_13e0:
  add si, 0x30
  pop cx
  loop loc_13c9
  push di
  pop si
  sub al, al
  dec al
  ret
sub_13ac endp

sub_13ed proc near
  mov al, byte ptr [si+0x16]
  cmp al, bl
  jnc loc_1443
  nop
  nop
  nop
  mov ch, bl
  mov bl, byte ptr [si]
  and bl, 0x7f
  sub bh, bh
  add bx, bx
  add bx, bx
  add bx, bx
  add bx, 0x932c
  mov ah, byte ptr [bx]
  inc bx
  mov cl, byte ptr [bx]
  add ah, ah
  add ah, ah
  add ah, ah
  add ah, al
  jnc loc_141e
  nop
  nop
  nop
  mov ah, 0xff
loc_141e:
  cmp ah, ch
  jc loc_1443
  nop
  nop
  nop
  mov ax, word ptr [si+0x18]
  cmp ax, dx
  jnc loc_1443
  nop
  nop
  nop
  sub ch, ch
  add cx, cx
  add cx, cx
  add cx, cx
  add ax, cx
  cmp ax, dx
  jc loc_1443
  nop
  nop
  nop
  sub al, al
  ret
loc_1443:
  sub al, al
  dec al
  ret
sub_13ed endp

sub_1448 proc near
  call sub_153c
  mov al, [0x7d68]
  mov [0x7d69], al
  cmp byte ptr [0x7d75], 0x0
  jz loc_145c
  nop
  nop
  nop
  ret
loc_145c:
  cmp byte ptr [0x7d6a], 0x0
  jz loc_1479
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0xb
  cmp byte ptr [0x7d79], 0x0
  jz loc_1478
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0x17
loc_1478:
  ret
loc_1479:
  cmp byte ptr [0x7d6b], 0x0
  jz loc_1493
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0xa
  cmp byte ptr [0x7d79], 0x0
  jz loc_1478
  mov byte ptr [si+0x8], 0x16
  ret
loc_1493:
  cmp byte ptr [0x7d6d], 0x0
  jz loc_14b0
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0xc
  mov al, byte ptr [si+0x2]
  xor al, byte ptr [si+0x4]
  and al, 0x4
  jz loc_1478
  mov byte ptr [si+0x8], 0x18
  ret
loc_14b0:
  cmp byte ptr [0x7d68], 0x0
  jz loc_14e9
  nop
  nop
  nop
  mov al, [0x7d78]
  inc al
  and al, 0x3
  mov [0x7d78], al
  jnz loc_14cc
  nop
  nop
  nop
  call sub_2b68
loc_14cc:
  mov ah, 0x7
  cmp byte ptr [0x7d79], 0x0
  jz loc_14da
  nop
  nop
  nop
  mov ah, 0x13
loc_14da:
  test byte ptr [si+0x2], 0x4
  jz loc_14e5
  nop
  nop
  nop
  inc ah
loc_14e5:
  mov byte ptr [si+0x8], ah
  ret
loc_14e9:
  cmp word ptr [0x7d6e], 0x0
  jz loc_1506
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0x6
  cmp byte ptr [0x7d79], 0x0
  jz loc_153b
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0x15
  ret
loc_1506:
  mov al, [0x7d78]
  inc al
  cmp al, 0x14
  jc loc_1517
  nop
  nop
  nop
  call sub_2b68
  mov al, 0x4
loc_1517:
  cmp al, 0xc
  jnz loc_1523
  nop
  nop
  nop
  call sub_2b68
  mov al, 0xc
loc_1523:
  mov [0x7d78], al
  shr al, 1
  shr al, 1
  add al, 0x1
  cmp byte ptr [0x7d79], 0x0
  jz loc_1538
  nop
  nop
  nop
  add al, 0xc
loc_1538:
  mov byte ptr [si+0x8], al
loc_153b:
  ret
sub_1448 endp

sub_153c proc near
  mov byte ptr [0x7d6a], 0x0
  mov byte ptr [0x7d6b], 0x0
  mov al, [0x7d75]
  or al, al
  jz loc_1550
  jmp loc_195a
loc_1550:
  mov al, [0x7e44]
  mov [0x7d6c], al
  mov al, [0x7d6d]
  or al, al
  jz loc_1560
  jmp loc_1873
loc_1560:
  mov byte ptr [0x7d6e], 0x0
  mov dl, byte ptr [0x7d72]
  mov dh, byte ptr [si+0x4]
  mov al, byte ptr [si+0x5]
  mov bx, word ptr [0x7d70]
  sub ah, ah
  test bh, 0x80
  jz loc_157f
  nop
  nop
  nop
  dec ah
loc_157f:
  add dx, bx
  adc al, ah
  mov ah, dl
  mov dl, dh
  mov dh, al
  mov bl, byte ptr [si+0x2]
  mov al, [0x7d68]
  cmp al, 0x0
  jz loc_15ab
  nop
  nop
  nop
  call sub_113a
  mov al, [0x7d74]
  cmp al, 0x0
  jnz loc_15ae
  nop
  nop
  nop
  mov byte ptr [0x7d68], 0x0
  jmp loc_15ae
  db 90h
loc_15ab:
  call sub_11bc
loc_15ae:
  mov bh, 0xf0
  mov al, [0x7d71]
  or al, al
  jns loc_15bc
  nop
  nop
  nop
  mov bh, 0xe0
loc_15bc:
  mov al, [0x7d67]
  mov cl, al
  and al, bh
  jz loc_15cb
  nop
  nop
  nop
  jmp loc_168f
loc_15cb:
  mov byte ptr [0x7d6e], 0xff
  test cl, 0x4
  jz loc_15d8
  jmp sub_19cf
loc_15d8:
  mov word ptr [si+0x4], dx
  mov byte ptr [0x7d72], ah
  test cl, 0x2
  jz loc_15fd
  nop
  nop
  nop
  mov al, [0x7d6c]
  and al, 0xc
  jz loc_15fd
  nop
  nop
  nop
  mov word ptr [0x7d70], 0x100
  mov byte ptr [0x7d6d], 0xff
  ret
loc_15fd:
  mov dx, word ptr [0x7d70]
  add dx, 0x80
  js loc_161a
  nop
  nop
  nop
  cmp dh, 0x8
  jc loc_161a
  nop
  nop
  nop
  mov byte ptr [0x7d72], 0x0
  mov dx, 0x800
loc_161a:
  mov word ptr [0x7d70], dx
loc_161e:
  mov al, [0x7d6c]
  and al, 0x3
  or al, al
  jnz loc_1630
  nop
  nop
  nop
  mov byte ptr [0x7d78], 0x2
  ret
loc_1630:
  cmp al, 0x2
  jnz loc_1649
  nop
  nop
  nop
  mov byte ptr [0x7d79], 0x1
  mov ax, word ptr [si+0x2]
  add al, 0xfe
  jc loc_165e
  nop
  nop
  nop
  jmp loc_19af
loc_1649:
  mov byte ptr [0x7d79], 0x0
  mov ax, word ptr [si+0x2]
  add ax, 0x2
  cmp al, 0xe8
  jc loc_165e
  nop
  nop
  nop
  jmp loc_19bf
loc_165e:
  mov dx, word ptr [si+0x4]
  mov bl, al
  mov al, [0x7d68]
  and al, al
  jz loc_1673
  nop
  nop
  nop
  call sub_113a
  jmp loc_1676
  db 90h
loc_1673:
  call sub_11bc
loc_1676:
  mov al, [0x7d67]
  mov cl, al
  and al, 0x70
  jz loc_1683
  nop
  nop
  nop
  ret
loc_1683:
  mov byte ptr [si+0x2], bl
  test cl, 0x4
  jz loc_168e
  jmp sub_19cf
loc_168e:
  ret
loc_168f:
  mov ax, [0x7d70]
  and ax, ax
  jns loc_16b5
  nop
  nop
  nop
  mov word ptr [0x7d6e], 0xff
  mov ax, word ptr [si+0x4]
  and al, 0xf8
  mov word ptr [si+0x4], ax
  mov byte ptr [0x7d72], 0x0
  mov word ptr [0x7d70], 0x0
  jmp loc_161e
loc_16b5:
  mov ax, word ptr [si+0x4]
  and al, 0xf8
  or al, 0x3
  mov word ptr [si+0x4], ax
  mov byte ptr [0x7d72], 0x0
  test cl, 0x20
  jz loc_16fc
  nop
  nop
  nop
  mov bx, word ptr [0x7d70]
  mov al, bh
  and al, al
  js loc_16fc
  nop
  nop
  nop
  cmp al, 0x2
  jc loc_16fc
  nop
  nop
  nop
  test byte ptr [0x7d6c], 0x8
  jz loc_16f0
  nop
  nop
  nop
  mov cx, 0xf800
  jmp loc_16f5
  db 90h
loc_16f0:
  mov cx, 0xfe
  sub cx, bx
loc_16f5:
  mov word ptr [0x7d70], cx
  jmp loc_161e
loc_16fc:
  mov word ptr [0x7d70], 0x100
  mov al, [0x7d6c]
  mov dh, al
  mov al, [0x7d69]
  and al, al
  mov al, dh
  jz loc_1713
  jmp loc_1808
loc_1713:
  test dh, 0x10
  jnz loc_171b
  jmp loc_1808
loc_171b:
  and al, 0x3
  jz loc_174b
  nop
  nop
  nop
  mov ax, word ptr [si+0x4]
  add ax, 0xe
  mov [0x7d7c], ax
  mov byte ptr [0x7d79], 0x1
  mov al, byte ptr [si+0x2]
  test dh, 0x1
  jz loc_1742
  nop
  nop
  nop
  mov byte ptr [0x7d79], 0x0
  add al, 0x17
loc_1742:
  mov [0x7d7b], al
  mov byte ptr [0x7d6a], 0xff
  ret
loc_174b:
  mov al, dh
  and al, 0xc
  cmp al, 0x8
  jnz loc_17c3
  nop
  nop
  nop
  mov byte ptr [0x7d6b], 0xff
  mov al, [0x7d86]
  and al, al
  jz loc_1766
  nop
  nop
  nop
  ret
loc_1766:
  mov byte ptr [0x7d86], 0xff
  mov al, [0x7eae]
  and al, al
  jz loc_1776
  nop
  nop
  nop
  ret
loc_1776:
  mov al, [0x7e45]
  and al, al
  jnz loc_1781
  nop
  nop
  nop
  ret
loc_1781:
  dec al
  mov [0x7e45], al
  mov word ptr [0x7eae], 0x2
  mov ax, word ptr [si+0x4]
  add ax, 0x6
  mov [0x7eb2], ax
  mov al, byte ptr [si+0x2]
  mov [0x7eb0], al
  mov word ptr [0x7d87], 0x8
  mov byte ptr [0x7eb6], 0x20
  mov ax, 0x7d9c
  mov [0x7d9a], ax
  mov al, [0x7d79]
  and al, al
  jnz loc_17b7
  nop
  nop
  nop
  ret
loc_17b7:
  mov word ptr [0x7d87], 0xfff8
  mov byte ptr [0x7eb6], 0x21
  ret
loc_17c3:
  mov byte ptr [0x7d86], 0x0
  mov byte ptr [0x7d78], 0x0
  test dh, 0x4
  jnz loc_17d6
  nop
  nop
  nop
  ret
loc_17d6:
  test byte ptr [0x7ede], 0xff
  jz loc_17e1
  nop
  nop
  nop
  ret
loc_17e1:
  mov al, [0x7e47]
  and al, al
  jnz loc_17ec
  nop
  nop
  nop
  ret
loc_17ec:
  dec al
  mov [0x7e47], al
  mov byte ptr [0x7ede], 0x3
  mov byte ptr [0x7d81], 0x2d
  mov al, byte ptr [si+0x2]
  mov [0x7ee0], al
  mov ax, word ptr [si+0x4]
  mov [0x7ee2], ax
  ret
loc_1808:
  test dh, 0x8
  jz loc_1832
  nop
  nop
  nop
  test cl, 0x2
  jz loc_181e
  nop
  nop
  nop
  mov byte ptr [0x7d6d], 0xff
  ret
loc_181e:
  mov word ptr [0x7d70], 0xfa80
  mov byte ptr [0x7d72], 0x0
  mov ax, 0x7de9
  mov [0x7d9a], ax
  jmp loc_161e
loc_1832:
  test dh, 0x4
  jnz loc_183d
  nop
  nop
  nop
  jmp loc_161e
loc_183d:
  test cl, 0x80
  jz loc_186b
  nop
  nop
  nop
  mov al, [0x7d6c]
  and al, 0x3
  jnz loc_186b
  nop
  nop
  nop
  mov al, byte ptr [si+0x2]
  and al, 0x1f
  cmp al, 0xa
  jnc loc_186b
  nop
  nop
  nop
  mov al, byte ptr [si+0x2]
  and al, 0xf0
  or al, 0x4
  mov byte ptr [si+0x2], al
  mov byte ptr [0x7d6d], 0xff
  ret
loc_186b:
  mov byte ptr [0x7d68], 0xff
  jmp loc_161e
loc_1873:
  mov al, [0x7d6c]
  and al, 0xf
  jnz loc_1883
  nop
  nop
  nop
  mov byte ptr [0x7d78], 0x0
  ret
loc_1883:
  and al, 0xc
  jz loc_18f1
  nop
  nop
  nop
  mov dx, word ptr [si+0x4]
  cmp al, 0x8
  jnz loc_189a
  nop
  nop
  nop
  mov cx, 0xfffe
  jmp loc_189d
  db 90h
loc_189a:
  mov cx, 0x2
loc_189d:
  add dx, cx
  mov bl, byte ptr [si+0x2]
  call sub_11bc
  mov al, [0x7d67]
  mov cl, al
  and al, 0x70
  jz loc_18c7
  nop
  nop
  nop
  test ch, 0x80
  jnz loc_18bf
  nop
  nop
  nop
  mov byte ptr [0x7d6d], 0x0
  ret
loc_18bf:
  test cl, 0x10
  jz loc_18f1
  nop
  nop
  nop
loc_18c7:
  mov word ptr [si+0x4], dx
  test cl, 0x4
  jz loc_18d2
  jmp sub_19cf
loc_18d2:
  test cl, 0x82
  jnz loc_18f1
  nop
  nop
  nop
  mov dx, 0x100
  or cx, cx
  jns loc_18e7
  nop
  nop
  nop
  mov dx, 0xfd00
loc_18e7:
  mov word ptr [0x7d70], dx
  mov byte ptr [0x7d6d], 0x0
  ret
loc_18f1:
  mov al, [0x7d6c]
  and al, 0x3
  jnz loc_18fc
  nop
  nop
  nop
  ret
loc_18fc:
  cmp al, 0x1
  mov al, byte ptr [si+0x2]
  jz loc_1910
  nop
  nop
  nop
  add al, 0xfe
  jc loc_190d
  jmp loc_19af
loc_190d:
  jmp loc_1919
  db 90h
loc_1910:
  add al, 0x2
  cmp al, 0xe8
  jc loc_1919
  jmp loc_19bf
loc_1919:
  mov bl, al
  mov dx, word ptr [si+0x4]
  call sub_11bc
  mov al, [0x7d67]
  mov cl, al
  and al, 0x60
  jz loc_192e
  nop
  nop
  nop
  ret
loc_192e:
  mov byte ptr [si+0x2], bl
  test cl, 0x4
  jz loc_1939
  jmp sub_19cf
loc_1939:
  mov al, cl
  and al, 0x82
  jz loc_1943
  nop
  nop
  nop
  ret
loc_1943:
  mov byte ptr [0x7d6d], 0x0
  mov al, [0x7d6c]
  test al, 0x8
  jnz loc_1953
  nop
  nop
  nop
  ret
loc_1953:
  mov word ptr [0x7d70], 0xfd00
  ret
loc_195a:
  mov byte ptr [si+0x8], 0x19
  test byte ptr [si+0x2], 0x4
  jz loc_196b
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0x1a
loc_196b:
  mov al, [0x7d7a]
  add al, byte ptr [si+0x2]
  mov byte ptr [si+0x2], al
  mov al, [0x7d72]
  mov ah, byte ptr [si+0x4]
  mov bl, byte ptr [si+0x5]
  mov cx, word ptr [0x7d70]
  mov bh, 0x0
  or cx, cx
  jns loc_198c
  nop
  nop
  nop
  dec bh
loc_198c:
  add ax, cx
  adc bl, bh
  mov [0x7d72], al
  mov byte ptr [si+0x4], ah
  mov byte ptr [si+0x5], bl
  add cx, 0x80
  mov word ptr [0x7d70], cx
  cmp bl, 0x1
  jnz loc_19ae
  nop
  nop
  nop
  mov byte ptr [0x7d92], 0xff
loc_19ae:
  ret
loc_19af:
  mov byte ptr [0x7d76], 0xff
  mov byte ptr [0x7d77], 0x0
  mov word ptr [si+0x2], 0xe2
  ret
loc_19bf:
  mov byte ptr [0x7d76], 0xff
  mov byte ptr [0x7d77], 0x1
  mov word ptr [si+0x2], 0x4
  ret
sub_153c endp

sub_19cf proc near
  mov al, [0x7d75]
  or al, al
  jz loc_19da
  nop
  nop
  nop
  ret
loc_19da:
  mov ax, 0x7da9
  mov [0x7d9a], ax
  mov byte ptr [0x7d75], 0xff
  mov word ptr [0x7d70], 0xfc00
  mov al, [0x7e80]
  cmp al, 0x80
  jnc loc_19fb
  nop
  nop
  nop
  mov byte ptr [0x7d7a], 0x3
  ret
loc_19fb:
  mov byte ptr [0x7d7a], 0xfd
  ret
sub_19cf endp

sub_1a01 proc near
  mov al, [0x7d87]
  and al, al
  jns loc_1a30
  nop
  nop
  nop
  add al, byte ptr [si+0x2]
  jnc loc_1a44
  nop
  nop
  nop
  mov byte ptr [si+0x2], al
loc_1a16:
  add al, 0xc
  mov [0x7d7e], al
  mov dx, word ptr [si+0x4]
  add dx, 0x5
  mov word ptr [0x7d7f], dx
  mov bl, al
  call sub_1115
  jnz loc_1a44
  nop
  nop
  nop
  ret
loc_1a30:
  add al, byte ptr [si+0x2]
  jc loc_1a44
  nop
  nop
  nop
  cmp al, 0xe8
  jnc loc_1a44
  nop
  nop
  nop
  mov byte ptr [si+0x2], al
  jmp loc_1a16
loc_1a44:
  mov byte ptr [si], 0x0
  ret
sub_1a01 endp

sub_1a48 proc near
  mov al, [0x7d81]
  dec al
  jnz loc_1a5b
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  mov byte ptr [0x7d85], 0x0
  ret
loc_1a5b:
  mov [0x7d81], al
  cmp al, 0xa
  jc loc_1a87
  nop
  nop
  nop
  cmp al, 0xb
  jnz loc_1a72
  nop
  nop
  nop
  mov ax, 0x7e1b
  mov [0x7d9a], ax
loc_1a72:
  mov byte ptr [si+0x8], 0x22
  test al, 0x1
  jz loc_1a81
  nop
  nop
  nop
  mov byte ptr [si+0x8], 0x23
loc_1a81:
  mov byte ptr [0x7d85], 0x0
  ret
loc_1a87:
  sub ah, ah
  shr al, 1
  mov di, 0x8138
  add di, ax
  mov al, byte ptr [di]
  mov byte ptr [si+0x8], al
  cmp al, 0x4
  jc loc_1a81
  mov al, byte ptr [si+0x2]
  add al, 0xc
  mov [0x7d82], al
  mov ax, word ptr [si+0x4]
  add ax, 0xa
  mov [0x7d83], ax
  mov byte ptr [0x7d85], 0xff
  push si
  mov si, 0x7e7e
  call sub_134b
  pop si
  jnz loc_1abf
  nop
  nop
  nop
  jmp sub_19cf
loc_1abf:
  ret
  db b8h
  db e9h
  db 7dh
  db a3h
  db 9ah
  db 7dh
sub_1a48 endp ; sp-analysis failed

sub_1ac6 proc near
  push ds
  mov al, [0x7d90]
  mov ah, 0x0
  push ax
  mov [0x971e], ax
  mov dx, 0x1fc1
  mov ds, dx
  mov dx, 0xa000
  mov es, dx
  mov ax, 0x2800
  mov [0x4907], ax
  call sub_0797
  pop bx
  add bl, bl
  add bx, 0x48cc
  mov bx, word ptr [bx]
  mov di, 0x5
  call sub_1f89
  mov di, 0xf04
  call sub_1f7b
  pop ds
  call sub_1c82
  call sub_1d30
  call sub_1dac
  call sub_1d5e
  call sub_1bae
  mov byte ptr [0x7e43], 0x0
loc_1b0d:
  call sub_07bb
  call sub_1d5e
  call sub_07bb
  call sub_1ce7
  call sub_1bae
  call sub_07bb
  call sub_1d5e
  call sub_1dac
  call sub_07bb
  call sub_1bae
  cmp byte ptr [0x7e43], 0x39
  jnz loc_1b0d
  ret
sub_1ac6 endp

sub_1b33 proc near
  push ds
loc_1b34:
  mov dx, 0x1fc1
  mov ds, dx
  mov dx, 0xb800
  mov es, dx
  mov ax, 0x2000
  mov [0x4907], ax
  call sub_0797
  mov bx, 0x4642
  mov di, 0x4
  call sub_1f7b
  mov di, 0x647
  call sub_1f7b
  mov ax, 0x1040
  mov ds, ax
  mov cx, 0x1f4
loc_1b5e:
  call sub_07bb
  call sub_0433
  jz loc_1baa
  nop
  nop
  nop
  loop loc_1b5e
  call sub_0797
  mov dx, 0x1fc1
  mov ds, dx
  mov dx, 0xb800
  mov es, dx
  mov ax, 0x0
  mov [0x4905], ax
  call sub_0797
  mov bx, 0x47a1
  mov di, 0x284
  call sub_1f7b
  mov bx, 0x4888
  mov di, 0xc89
  call sub_1f7b
  mov ax, 0x1040
  mov ds, ax
  mov cx, 0x1f4
loc_1b9b:
  call sub_07bb
  call sub_0433
  jz loc_1baa
  nop
  nop
  nop
  loop loc_1b9b
  jmp loc_1b34
loc_1baa:
  push ds
  pop es
  pop ds
  ret
sub_1b33 endp

sub_1bae proc near
  mov ax, [0x9720]
  mov bx, ax
  and bx, 0x3
  add bx, bx
  add bx, 0x9661
  mov cx, word ptr [bx]
  rcr ax, 1
  rcr ax, 1
  and ax, 0x3
  mov di, 0x3d0
  add di, ax
  mov ax, [0x9724]
  mov dx, 0x50
  mul dx
  add di, ax
  mov bl, byte ptr [0x9728]
  sub bh, bh
  add bx, bx
  add bx, 0x100
  mov si, word ptr [bx]
  push ds
  mov dx, 0x3ce
  mov ax, 0x1
  out dx, ax
  mov al, 0x3
  out dx, ax
  mov al, 0x5
  out dx, ax
  mov ds, cx
  mov cx, 0x15
loc_1bf5:
  call sub_1c15
  call sub_1c15
  add di, 0x24
  loop loc_1bf5
  mov ax, 0xf02
  out dx, ax
  mov dx, 0x3ce
  mov ax, 0x105
  out dx, ax
  mov ax, 0x1
  out dx, ax
  mov ax, 0xff08
  out dx, ax
  pop ds
  ret
sub_1bae endp

sub_1c15 proc near
  inc di
  mov dx, 0x3ce
  lodsw
  not al
  mov ah, al
  mov al, 0x8
  out dx, ax
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov ah, byte ptr es:[di]
  mov ah, 0x1
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x202
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x402
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x802
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  dec di
  sub si, 0x9
  mov dx, 0x3ce
  lodsw
  not al
  mov ah, al
  mov al, 0x8
  out dx, ax
  mov dx, 0x3c4
  mov ax, 0xf02
  out dx, ax
  mov ah, byte ptr es:[di]
  mov ah, 0x1
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x202
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x402
  out dx, ax
  lodsw
  mov byte ptr es:[di], al
  mov ax, 0x802
  out dx, ax
  lodsb
  stosb
  inc di
  ret
sub_1c15 endp

sub_1c82 proc near
  mov bx, word ptr [0x971e]
  add bx, bx
  add bx, 0x974c
  mov ax, word ptr [bx]
  mov [0x972a], ax
  mov word ptr [0x9730], 0x0
  mov bx, ax
  mov ax, word ptr [bx]
  mov [0x9720], ax
  mov ax, word ptr [bx+0x2]
  mov [0x9724], ax
  add bx, 0x4
  mov word ptr [0x972e], bx
  call sub_1cb3
  dec byte ptr [0x9730]
  ret
sub_1c82 endp

sub_1cb3 proc near
  mov bx, word ptr [0x972e]
  mov ax, word ptr [bx]
  or ax, ax
  jz loc_1ce3
  nop
  nop
  nop
  mov [0x972c], ax
  mov ax, word ptr [bx+0x2]
  mov [0x9722], ax
  mov ax, word ptr [bx+0x4]
  mov [0x9726], ax
  mov ax, word ptr [bx+0x6]
  mov [0x9732], ax
  add bx, 0x8
  mov word ptr [0x972e], bx
  mov word ptr [0x9734], 0x0
  ret
loc_1ce3:
  mov [0x9730], ax
  ret
sub_1cb3 endp

sub_1ce7 proc near
  cmp word ptr [0x9730], 0x0
  jz sub_1d30
  nop
  nop
  nop
  sub ah, ah
  mov bx, word ptr [0x9734]
  mov si, word ptr [0x9732]
  mov al, byte ptr [bx+si]
  or ax, ax
  jnz loc_1d09
  nop
  nop
  nop
  mov [0x9734], ax
  mov ax, word ptr [si]
loc_1d09:
  mov [0x9728], ax
  inc word ptr [0x9734]
  mov ax, [0x9720]
  add ax, word ptr [0x9722]
  mov [0x9720], ax
  mov ax, [0x9724]
  add ax, word ptr [0x9726]
  mov [0x9724], ax
  dec word ptr [0x972c]
  jnz sub_1d30
  nop
  nop
  nop
  call sub_1cb3
sub_1ce7 endp ; sp-analysis failed

sub_1d30 proc near
  mov bx, word ptr [0x971e]
  push ds
  mov cx, 0x1fc1
  mov ds, cx
  mov di, 0x3d0
  mov cx, 0x6
  add bx, 0x4909
  mov dl, byte ptr [bx]
loc_1d46:
  push cx
  push di
  mov cx, 0x6
loc_1d4b:
  mov al, dl
  call sub_1fb1
  inc dl
  loop loc_1d4b
  pop di
  add di, 0x140
  pop cx
  loop loc_1d46
  pop ds
  ret
sub_1d30 endp

sub_1d5e proc near
  mov al, [0x971c]
  inc al
  mov [0x971c], al
  push ds
  push es
  pop ds
  and al, 0x1
  jz loc_1d87
  nop
  nop
  nop
  mov dx, 0x22
  mov si, 0x2828
  mov di, 0x290
  call sub_1d9e
  mov si, 0x2a00
  mov di, 0xb50
  call sub_1d9e
  pop ds
  ret
loc_1d87:
  mov dx, 0x22
  mov si, 0x2a00
  mov di, 0x290
  call sub_1d9e
  mov si, 0x2830
  mov di, 0xb50
  call sub_1d9e
  pop ds
  ret
sub_1d5e endp

sub_1d9e proc near
  mov cx, 0x8
loc_1da1:
  movsb
  stosb
  stosb
  stosb
  stosb
  stosb
  add di, dx
  loop loc_1da1
  ret
sub_1d9e endp

sub_1dac proc near
  mov al, [0x971c]
  push ds
  push es
  pop ds
  and al, 0x2
  jz loc_1dd0
  nop
  nop
  nop
  mov dx, 0x28
  mov si, 0x2820
  mov di, 0x28f
  call sub_1de7
  mov si, 0x2820
  mov di, 0x296
  call sub_1de7
  pop ds
  ret
loc_1dd0:
  mov dx, 0x28
  mov si, 0x2958
  mov di, 0x28f
  call sub_1de7
  mov si, 0x2958
  mov di, 0x296
  call sub_1de7
  pop ds
  ret
sub_1dac endp

sub_1de7 proc near
  mov cx, 0x8
loc_1dea:
  lodsb
  mov byte ptr [di], al
  mov byte ptr [di+0x140], al
  mov byte ptr [di+0x280], al
  mov byte ptr [di+0x3c0], al
  mov byte ptr [di+0x500], al
  mov byte ptr [di+0x640], al
  mov byte ptr [di+0x780], al
  mov byte ptr [di+0x8c0], al
  add di, dx
  loop loc_1dea
  ret
sub_1de7 endp

sub_1e0e proc near
  push ds
  mov al, 0x0
  mov [0x48f4], al
  mov [0x48f5], al
  mov [0x48f6], al
  mov dx, 0x1fc1
  mov ds, dx
  mov es, dx
  mov cx, 0xa
  mov di, 0x48fb
  mov al, 0x3b
  rep stosb
  mov dx, 0xa000
  mov es, dx
  mov ax, 0x2000
  mov [0x4907], ax
  call sub_0797
  mov bx, 0x457d
  mov di, 0x4
  call sub_1f7b
  mov di, 0x649
  call sub_1f89
  mov di, 0xa0e
  call sub_1f7b
  mov di, 0x17cf
  call sub_1f89
  mov ax, 0x1040
  mov es, ax
loc_1e59:
  call sub_07bb
  call sub_07bb
  call sub_07bb
  call sub_07bb
  cmp byte ptr [0x48f6], 0xa
  jz loc_1e74
  nop
  nop
  nop
  call sub_1e76
  jmp loc_1e59
loc_1e74:
  pop ds
  ret
sub_1e0e endp

sub_1e76 proc near
  mov al, es:[0x7e44]
  mov bx, word ptr [0x48f4]
  test al, 0x10
  jz loc_1e88
  nop
  nop
  nop
  jmp loc_1f17
loc_1e88:
  test al, 0x1
  jz loc_1e9b
  nop
  nop
  nop
  inc bl
  cmp bl, 0x6
  jnz loc_1e9b
  nop
  nop
  nop
  mov bl, 0x5
loc_1e9b:
  test al, 0x2
  jz loc_1eab
  nop
  nop
  nop
  dec bl
  jns loc_1eab
  nop
  nop
  nop
  mov bl, 0x0
loc_1eab:
  test al, 0x4
  jz loc_1ebe
  nop
  nop
  nop
  inc bh
  cmp bh, 0x5
  jnz loc_1ebe
  nop
  nop
  nop
  mov bh, 0x4
loc_1ebe:
  test al, 0x8
  jz loc_1ece
  nop
  nop
  nop
  dec bh
  jns loc_1ece
  nop
  nop
  nop
  mov bh, 0x0
loc_1ece:
  mov word ptr [0x48f4], bx
  mov bx, word ptr [0x48f4]
  add bh, bh
  mov al, bh
  add al, al
  add al, bh
  add al, bl
  mov ah, 0x0
  mov bx, 0x48d6
  add bx, ax
  mov al, byte ptr [bx]
  mov [0x48f7], al
  mov di, word ptr [0x48f8]
  mov al, 0x40
  call sub_1fa0
  mov bx, word ptr [0x48f4]
  mov al, bh
  mov ah, 0x0
  mov dx, 0x280
  mul dx
  add bl, bl
  mov bh, 0x0
  mov di, 0xb4e
  add di, ax
  add di, bx
  mov word ptr [0x48f8], di
  mov al, 0x3e
  call sub_1fa0
  ret
loc_1f17:
  push es
  mov ax, 0xa000
  mov es, ax
  mov al, [0x48f7]
  cmp al, 0x3d
  jnz loc_1f2f
  nop
  nop
  nop
  mov byte ptr [0x48f6], 0xa
  jmp loc_1f71
  db 90h
loc_1f2f:
  cmp al, 0x3c
  jnz loc_1f51
  nop
  nop
  nop
  cmp byte ptr [0x48f6], 0x0
  jz loc_1f71
  nop
  nop
  nop
  dec byte ptr [0x48f6]
  mov bl, byte ptr [0x48f6]
  mov al, 0x3b
  dec byte ptr [0x48f6]
  jmp loc_1f55
  db 90h
loc_1f51:
  mov bl, byte ptr [0x48f6]
loc_1f55:
  mov bh, al
  push bx
  sub bh, bh
  mov di, 0x17cf
  add di, bx
  call sub_1fb1
  pop bx
  mov al, bh
  sub bh, bh
  add bx, 0x48fb
  mov byte ptr [bx], al
  inc byte ptr [0x48f6]
loc_1f71:
  pop es
loc_1f72:
  test byte ptr es:[0x7e44], 0x10
  jnz loc_1f72
  ret
sub_1e76 endp

sub_1f7b proc near
  push di
  call sub_1f89
  pop di
  add di, 0x140
  cmp al, 0xfe
  jnz sub_1f7b
  ret
sub_1f7b endp

sub_1f89 proc near
  mov al, byte ptr [bx]
  inc bx
  cmp al, 0xff
  jz loc_1f9f
  nop
  nop
  nop
  cmp al, 0xfe
  jz loc_1f9f
  nop
  nop
  nop
  call sub_1fa0
  jmp sub_1f89
loc_1f9f:
  ret
sub_1f89 endp

sub_1fa0 proc near
  push ds
  push es
  push dx
  mov dx, 0xa000
  mov es, dx
  mov ds, dx
  pop dx
  call sub_1fb1
  pop es
  pop ds
  ret
sub_1fa0 endp

sub_1fb1 proc near
  push es
  push ds
  push di
  push cx
  mov cx, 0x1fc1
  mov ds, cx
  mov cx, word ptr [0x4907]
  push es
  pop ds
  mov ah, 0x0
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, cx
  mov si, ax
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  add di, 0x27
  movsb
  pop cx
  pop di
  inc di
  pop ds
  pop es
  ret
sub_1fb1 endp

sub_1fef proc near
  push ds
  mov ax, 0x1fc1
  mov ds, ax
  mov es, ax
  mov di, 0x4785
  mov si, 0x4769
loc_1ffd:
  cmp si, bx
  jz loc_2011
  nop
  nop
  nop
  mov cx, 0xd
  rep movsw
  sub di, 0x36
  sub si, 0x36
  jmp loc_1ffd
loc_2011:
  mov cx, 0xd
  rep movsw
  mov ax, [0x490e]
  mov word ptr [bx], ax
  inc bx
  inc bx
  mov ax, [0x4910]
  mov word ptr [bx], ax
  inc bx
  inc bx
  mov ax, [0x4912]
  mov word ptr [bx], ax
  add bx, 0xc
  mov di, bx
  mov si, 0x48fb
  mov cx, 0xa
  rep movsb
  pop ds
  ret
sub_1fef endp

sub_2038 proc near
  mov ax, 0x1fc1
  mov ds, ax
  mov si, 0x46a5
  mov cx, 0x8
loc_2043:
  mov di, 0x490e
  mov al, byte ptr [si]
  cmp al, byte ptr [di]
  jc loc_207b
  nop
  nop
  nop
  jnz loc_206f
  nop
  nop
  nop
  push si
  mov bx, 0x5
loc_2058:
  inc si
  inc di
  mov al, byte ptr [si]
  cmp al, byte ptr [di]
  jc loc_207a
  nop
  nop
  nop
  jnz loc_206e
  nop
  nop
  nop
  dec bx
  jnz loc_2058
  jmp loc_207a
  db 90h
loc_206e:
  pop si
loc_206f:
  add si, 0x1c
  loop loc_2043
  mov ax, 0x1040
  mov ds, ax
  ret
loc_207a:
  pop si
loc_207b:
  push si
  call sub_1e0e
  pop bx
  call sub_1fef
  mov ax, 0x1040
  mov ds, ax
  ret
sub_2038 endp

sub_2089 proc near
  mov ax, 0x1040
  mov ds, ax
  mov es, ax
  mov di, word ptr [0x7d64]
loc_2094:
  mov al, byte ptr [di]
  cmp al, 0xff
  jnz loc_209e
  nop
  nop
  nop
  ret
loc_209e:
  cmp al, dh
  jnc loc_20aa
  nop
  nop
  nop
  add di, 0x5
  jmp loc_2094
loc_20aa:
  add dh, dl
loc_20ac:
  mov al, byte ptr [di]
  cmp al, 0xff
  jnz loc_20b6
  nop
  nop
  nop
  ret
loc_20b6:
  cmp al, dh
  jc loc_20be
  nop
  nop
  nop
  ret
loc_20be:
  push dx
  and al, 0xf8
  mov dl, al
  mov al, byte ptr [di+0x1]
  and al, al
  jns loc_20d0
  nop
  nop
  nop
  jmp loc_21de
loc_20d0:
  test byte ptr [di+0x2], 0x2
  jz loc_20f0
  nop
  nop
  nop
  cmp byte ptr [0x7e4e], 0x0
  jz loc_20e6
  nop
  nop
  nop
  jmp loc_21de
loc_20e6:
  mov si, 0x7e4e
  mov byte ptr [si+0x26], 0x0
  jmp loc_210d
  db 90h
loc_20f0:
  cmp al, 0x10
  jnc loc_2102
  nop
  nop
  nop
  call sub_2205
  jz loc_210d
  nop
  nop
  nop
  jmp loc_21de
loc_2102:
  call sub_21e5
  jz loc_210d
  nop
  nop
  nop
  jmp loc_21de
loc_210d:
  mov byte ptr [si], al
  mov al, byte ptr [di+0x3]
  mov dh, al
  and al, 0xf8
  mov byte ptr [si+0x2], al
  mov byte ptr [si+0x1c], al
  and dh, 0x7
  sub dl, byte ptr [0x7e38]
  add dl, dh
  sub dh, dh
  add dx, dx
  add dx, dx
  add dx, dx
  test byte ptr [di+0x2], 0x2
  jnz loc_2139
  nop
  nop
  nop
  add dx, 0x3
loc_2139:
  mov word ptr [si+0x4], dx
  mov word ptr [si+0x1e], dx
  mov word ptr [si+0xc], 0x0
  mov bl, byte ptr [di+0x1]
  sub bh, bh
  add bx, bx
  add bx, bx
  add bx, bx
  add bx, 0x9326
  mov al, byte ptr [bx]
  mov byte ptr [si+0xe], al
  inc bx
  mov al, byte ptr [bx]
  mov byte ptr [si+0x10], al
  inc bx
  mov ax, word ptr [bx]
  mov word ptr [si+0x20], ax
  mov byte ptr [si+0x8], al
  inc bx
  inc bx
  mov ax, word ptr [bx]
  mov word ptr [si+0x22], ax
  mov word ptr [si+0x12], di
  mov al, byte ptr [di+0x2]
  mov byte ptr [si+0x14], al
  test al, 0x4
  jz loc_2181
  nop
  nop
  nop
  or byte ptr [si], 0x80
loc_2181:
  mov al, byte ptr [di+0x2]
  and al, 0xf0
  cmp al, 0xf0
  jnz loc_219b
  nop
  nop
  nop
  cmp si, 0x7ffe
  jc loc_219b
  nop
  nop
  nop
  mov cl, byte ptr [bx]
  mov byte ptr [si+0x20], cl
loc_219b:
  mov al, byte ptr [di+0x4]
  mov dl, al
  and al, 0xf8
  mov byte ptr [si+0x16], al
  and dl, 0x7
  mov al, dl
  add al, al
  add al, al
  add al, al
  add al, al
  add al, al
  mov byte ptr [si+0x2e], al
  mov bl, byte ptr [0x7e38]
  mov al, byte ptr [di]
  and al, 0xf8
  sub al, bl
  add al, dl
  sub ah, ah
  add ax, ax
  add ax, ax
  add ax, ax
  add ax, 0x3
  mov word ptr [si+0x18], ax
  mov byte ptr [si+0x28], 0x0
  mov byte ptr [si+0x2a], 0x0
  mov word ptr [si+0x2c], 0x0
loc_21de:
  pop dx
  add di, 0x5
  jmp loc_20ac
sub_2089 endp

sub_21e5 proc near
  push ax
  mov si, 0x7f0e
  mov cx, 0x5
  sub ax, ax
loc_21ee:
  cmp ax, word ptr [si]
  jnz loc_21fb
  nop
  nop
  nop
  pop ax
  mov byte ptr [si+0x26], 0x0
  ret
loc_21fb:
  add si, 0x30
  loop loc_21ee
  sub ax, ax
  inc ax
  pop ax
  ret
sub_21e5 endp

sub_2205 proc near
  push ax
  mov si, 0x7ffe
  mov cx, 0x3
  sub ax, ax
loc_220e:
  cmp al, byte ptr [si]
  jz loc_221d
  nop
  nop
  nop
  cmp di, word ptr [si+0x12]
  jz loc_223c
  nop
  nop
  nop
loc_221d:
  add si, 0x30
  loop loc_220e
  mov si, 0x7ffe
  mov cx, 0x3
  sub ax, ax
loc_222a:
  cmp ax, word ptr [si]
  jnz loc_2237
  nop
  nop
  nop
  pop ax
  mov byte ptr [si+0x26], 0x2
  ret
loc_2237:
  add si, 0x30
  loop loc_222a
loc_223c:
  sub ax, ax
  inc ax
  pop ax
  ret
sub_2205 endp

sub_2241 proc near
  mov ax, 0x1040
  mov ds, ax
  mov si, 0x7e4e
loc_2249:
  mov ax, word ptr [si]
  and ax, ax
  jz loc_225d
  nop
  nop
  nop
  cmp ax, 0xff
  jz loc_2262
  nop
  nop
  nop
  call sub_2263
loc_225d:
  add si, 0x30
  jmp loc_2249
loc_2262:
  ret
sub_2241 endp

sub_2263 proc near
  mov bx, 0x1040
  mov ds, bx
  mov es, bx
  and al, 0x7f
  cmp al, 0x47
  jnz loc_2276
  nop
  nop
  nop
  jmp loc_2501
loc_2276:
  cmp al, 0x18
  jc loc_2281
  nop
  nop
  nop
  jmp loc_268f
  db c3h
loc_2281:
  sub ah, ah
  add ax, ax
  add ax, 0x80bf
  mov di, ax
  db 00h
;switchd:
;  jmp word ptr [di]
sub_2263 endp

sub_228c proc near
  mov byte ptr [si+0x8], 0x0
  cmp byte ptr [0x7d8f], 0x0
  jnz loc_229b
  nop
  nop
  nop
  ret
loc_229b:
  mov bl, byte ptr [0x7e80]
  add bl, 0xc
  mov dx, word ptr [0x7e82]
  add dx, 0xa
  call sub_13ed
  jz loc_22b2
  nop
  nop
  nop
  ret
loc_22b2:
  mov byte ptr [0x7d8f], 0x0
  push si
  mov si, 0x491c
  call sub_0292
  pop si
  mov byte ptr [si], 0x0
  mov ax, 0x7df2
  mov [0x7d9a], ax
  jmp sub_2592
sub_228c endp

sub_22cb proc near
  mov byte ptr [si+0x8], 0x0
  mov bl, byte ptr [0x7e80]
  add bl, 0xc
  mov dx, word ptr [0x7e82]
  add dx, 0xa
  call sub_13ed
  jz loc_22e6
  nop
  nop
  nop
  ret
loc_22e6:
  mov byte ptr [si], 0x0
  mov byte ptr [0x7d8f], 0xff
  mov byte ptr [0x7d95], 0x1e
  mov ax, 0x7df2
  mov [0x7d9a], ax
  push ds
  mov ax, 0x1fc1
  mov ds, ax
  mov word ptr [0x491c], 0x200
  mov word ptr [0x491e], 0x0
  mov word ptr [0x491f], 0x0
  pop ds
  ret
sub_22cb endp

sub_2313 proc near
  mov byte ptr [0x7d8e], 0xff
loc_2318:
  call sub_238b
  call sub_13ac
  jnz loc_2323
  jmp loc_24c4
loc_2323:
  cmp byte ptr [0x7eae], 0x0
  jz loc_2352
  nop
  nop
  nop
  mov bl, byte ptr [0x7eb0]
  test byte ptr [0x7d87], 0x80
  jnz loc_233e
  nop
  nop
  nop
  add bl, 0x18
loc_233e:
  mov dx, word ptr [0x7eb2]
  call sub_1317
  jnz loc_2352
  nop
  nop
  nop
  mov byte ptr [0x7eae], 0x0
  jmp loc_24c4
loc_2352:
  cmp byte ptr [0x7d85], 0x0
  jz loc_2364
  nop
  nop
  nop
  call sub_134b
  jnz loc_2364
  jmp loc_24c4
loc_2364:
  cmp byte ptr [0x7d6a], 0x0
  jz loc_2382
  nop
  nop
  nop
  mov bl, byte ptr [0x7d7b]
  mov dx, word ptr [0x7d7c]
  call sub_1317
  jnz loc_2382
  nop
  nop
  nop
  mov byte ptr [si+0x2e], 0x14
loc_2382:
  call sub_12ae
  jnz loc_238a
  jmp sub_19cf
loc_238a:
  ret
sub_2313 endp

sub_238b proc near
  mov dl, byte ptr [si+0x2a]
  mov dh, byte ptr [si+0x4]
  mov al, byte ptr [si+0x5]
  mov cx, word ptr [si+0x2c]
  sub ah, ah
  test ch, 0x80
  jz loc_23a3
  nop
  nop
  nop
  dec ah
loc_23a3:
  add dx, cx
  adc al, ah
  mov ah, dl
  mov dl, dh
  mov dh, al
  cmp dx, 0x140
  jc loc_23bc
  nop
  nop
  nop
  call sub_265a
  jmp loc_24fd
loc_23bc:
  mov bl, byte ptr [si+0x2]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0xf0
  jnz loc_23f1
  nop
  nop
  nop
  mov al, [0x7d67]
  and al, 0x4
  jz loc_23d6
  jmp loc_24c4
loc_23d6:
  mov word ptr [si+0x4], dx
  mov byte ptr [si+0x2a], ah
  mov ax, word ptr [si+0x2c]
  add ax, 0x80
  cmp ah, 0x8
  jc loc_23ed
  nop
  nop
  nop
  mov ax, 0x800
loc_23ed:
  mov word ptr [si+0x2c], ax
  ret
loc_23f1:
  mov bl, byte ptr [si+0x2]
  and bl, 0x1c
  shr bl, 1
  shr bl, 1
  shr bl, 1
  sub bh, bh
  add bx, 0x8143
  mov al, byte ptr [bx]
  test byte ptr [si+0x26], 0x80
  jz loc_2410
  nop
  nop
  nop
  add al, 0x3
loc_2410:
  add al, byte ptr [si+0x20]
  mov byte ptr [si+0x8], al
  mov word ptr [si+0x2c], 0x80
  mov ax, word ptr [si+0x4]
  and al, 0xf8
  or al, 0x3
  mov word ptr [si+0x4], ax
  mov al, byte ptr [si+0x2e]
  and al, al
  jz loc_2435
  nop
  nop
  nop
  dec al
  mov byte ptr [si+0x2e], al
  ret
loc_2435:
  mov al, byte ptr [si+0x26]
  and al, al
  jnz loc_2447
  nop
  nop
  nop
  ret
sub_238b endp

sub_2440 proc near
  mov al, 0x2
  mov byte ptr [si+0x26], al
  and al, al
loc_2447:
  jns loc_2457
  nop
  nop
  nop
  add al, byte ptr [si+0x2]
  jc loc_2461
  nop
  nop
  nop
  jmp loc_24bc
  db 90h
loc_2457:
  add al, byte ptr [si+0x2]
  cmp al, 0xe8
  jnc loc_24bc
  nop
  nop
  nop
loc_2461:
  mov bl, al
  mov dx, word ptr [si+0x4]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0xf0
  jnz loc_24bc
  nop
  nop
  nop
  mov al, [0x7d67]
  test al, 0x4
  jnz loc_24c4
  nop
  nop
  nop
  mov byte ptr [si+0x2], bl
  mov al, [0x7d8e]
  and al, al
  jz loc_24a9
  nop
  nop
  nop
  mov al, byte ptr [si+0x2]
  mov cl, al
  and al, 0x1e
  cmp al, 0x10
  jz loc_2499
  nop
  nop
  nop
loc_2498:
  ret
loc_2499:
  mov al, [0x7e80]
  cmp al, cl
  mov byte ptr [si+0x26], 0xfe
  jc loc_2498
  mov byte ptr [si+0x26], 0x2
  ret
loc_24a9:
  mov al, byte ptr [si+0x16]
  shr al, 1
  mov cl, al
  mov al, byte ptr [si+0x28]
  inc al
  mov byte ptr [si+0x28], al
  cmp al, cl
  jc loc_2498
loc_24bc:
  mov byte ptr [si+0x28], 0x0
  neg byte ptr [si+0x26]
  ret
loc_24c4:
  mov byte ptr [si], 0x47
  mov word ptr [si+0x2c], 0xfc00
  mov ax, 0x7da9
  mov [0x7d9a], ax
  push si
  mov si, 0x4928
  call sub_0292
  pop si
  test byte ptr [si+0x14], 0x1
  jz loc_24ea
  nop
  nop
  nop
  mov bx, word ptr [si+0x12]
  inc bx
  or byte ptr [bx], 0x80
loc_24ea:
  mov byte ptr [si+0x26], 0x2
  cmp byte ptr [si+0x2], 0x80
  jnc loc_24f8
  nop
  nop
  nop
  ret
loc_24f8:
  mov byte ptr [si+0x26], 0xfe
  ret
loc_24fd:
  mov byte ptr [si], 0x0
  ret
loc_2501:
  mov ah, byte ptr [si+0x20]
  add ah, 0x6
  test byte ptr [si+0x2], 0x4
  jz loc_2512
  nop
  nop
  nop
  inc ah
loc_2512:
  mov byte ptr [si+0x8], ah
  mov dl, byte ptr [si+0x2a]
  mov dh, byte ptr [si+0x4]
  mov al, byte ptr [si+0x5]
  mov cx, word ptr [si+0x2c]
  sub ah, ah
  and ch, ch
  jns loc_252c
  nop
  nop
  nop
  dec ah
loc_252c:
  add dx, cx
  adc al, ah
  and al, al
  jz loc_253b
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  ret
loc_253b:
  mov byte ptr [si+0x2a], dl
  mov byte ptr [si+0x4], dh
  mov byte ptr [si+0x5], al
  mov ax, word ptr [si+0x2c]
  add ax, 0x80
  mov word ptr [si+0x2c], ax
  mov al, byte ptr [si+0x26]
  and al, al
  jns loc_2568
  nop
  nop
  nop
  add al, byte ptr [si+0x2]
  mov byte ptr [si+0x2], al
  jnc loc_2563
  nop
  nop
  nop
loc_2562:
  ret
loc_2563:
  mov byte ptr [si+0x2], 0x0
  ret
loc_2568:
  add al, byte ptr [si+0x2]
  mov byte ptr [si+0x2], al
  jnc loc_2562
  mov byte ptr [si+0x2], 0xe8
  ret
sub_2440 endp

sub_2575 proc near
  call sub_12ae
  jz loc_257e
  nop
  nop
  nop
  ret
loc_257e:
  mov byte ptr [si], 0x0
  push si
  mov si, 0x492e
  call sub_0292
  pop si
  mov ax, 0x7df2
  mov [0x7d9a], ax
  jmp sub_2592
  db 90h
sub_2575 endp ; sp-analysis failed

sub_2592 proc near
  mov bx, word ptr [si+0x12]
  inc bx
  or byte ptr [bx], 0x80
  ret
sub_2592 endp

sub_259a proc near
  ret
sub_259a endp

sub_259b proc near
  mov byte ptr [0x7d8e], 0x0
  jmp loc_2318
sub_259b endp

sub_25a3 proc near
  test byte ptr [si], 0x80
  jz loc_25ca
  nop
  nop
  nop
  mov bl, byte ptr [si+0x26]
  shr bl, 1
  sub bh, bh
  add bx, 0x8138
  mov al, byte ptr [bx]
  mov byte ptr [si+0x8], al
  dec byte ptr [si+0x26]
  jnz loc_25c9
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  call sub_2592
loc_25c9:
  ret
loc_25ca:
  push si
  push di
  call sub_12ae
  pop di
  pop si
  jz loc_2629
  nop
  nop
  nop
  mov al, [0x7d6a]
  and al, al
  jz loc_25f8
  nop
  nop
  nop
  mov bl, byte ptr [0x7d7b]
  mov dx, word ptr [0x7d7c]
  call sub_1317
  jnz loc_25f8
  nop
  nop
  nop
loc_25f0:
  mov byte ptr [si+0x26], 0xa
  or byte ptr [si], 0x80
  ret
loc_25f8:
  mov al, [0x7eae]
  and al, al
  jz loc_2619
  nop
  nop
  nop
  mov bl, byte ptr [0x7d7e]
  mov dx, word ptr [0x7d7f]
  call sub_1317
  jnz loc_2619
  nop
  nop
  nop
  mov byte ptr [0x7eae], 0x0
  jmp loc_25f0
loc_2619:
  mov al, [0x7d85]
  and al, al
  jz loc_2628
  nop
  nop
  nop
  call sub_134b
  jz loc_25f0
loc_2628:
  ret
loc_2629:
  mov ax, 0x7df2
  mov [0x7d9a], ax
  mov al, byte ptr [si]
  cmp al, 0x10
  mov byte ptr [si], 0x0
  jnz loc_2643
  nop
  nop
  nop
  mov byte ptr [0x7e47], 0x6
  jmp sub_2592
loc_2643:
  mov byte ptr [0x7e45], 0x6
  jmp sub_2592
sub_25a3 endp

sub_264b proc near
  push ds
  push bx
  mov bx, 0xb800
  mov ds, bx
  mov bx, 0x44
  mov word ptr [bx], ax
  pop bx
  pop ds
  ret
sub_264b endp

sub_265a proc near
  push ds
  push bx
  mov bx, 0xb800
  mov ds, bx
  mov bx, 0x4e
  inc word ptr [bx]
  pop bx
  pop ds
  ret
sub_265a endp

sub_2669 proc near
  mov byte ptr [0x7d85], 0x0
  mov byte ptr [0x7d6a], 0x0
  mov si, 0x7e4e
loc_2676:
  mov al, byte ptr [si]
  cmp al, 0xff
  jnz loc_2680
  nop
  nop
  nop
  ret
loc_2680:
  cmp al, 0x1
  jz loc_268a
  nop
  nop
  nop
  mov byte ptr [si], 0x0
loc_268a:
  add si, 0x30
  jmp loc_2676
loc_268f:
  call sub_26a3
  test byte ptr [si], 0x80
  jz loc_26a2
  nop
  nop
  nop
  call sub_12ae
  jnz loc_26a2
  jmp sub_19cf
loc_26a2:
  ret
sub_2669 endp

sub_26a3 proc near
  mov al, byte ptr [si+0x26]
  sub ah, ah
  mov bx, word ptr [si+0x20]
  mov cx, bx
  add bx, ax
  mov al, byte ptr [bx]
  cmp al, 0xff
  jnz loc_26bc
  nop
  nop
  nop
  mov bx, cx
  mov al, byte ptr [bx]
loc_26bc:
  mov byte ptr [si+0x8], al
  mov al, byte ptr [si+0x26]
  and al, al
  jnz loc_26c9
  jmp loc_27a7
loc_26c9:
  sub ah, ah
  mov bx, cx
  add bx, ax
  cmp byte ptr [bx], 0xff
  jnz loc_26de
  nop
  nop
  nop
  mov byte ptr [si+0x26], 0x1
  jmp loc_26f5
  db 90h
loc_26de:
  inc al
  mov byte ptr [si+0x26], al
  sub ah, ah
  mov bx, cx
  add bx, ax
  cmp byte ptr [bx], 0xff
  jnz loc_26f5
  nop
  nop
  nop
  mov byte ptr [si+0x26], 0x1
loc_26f5:
  mov bx, word ptr [si+0x24]
  mov al, byte ptr [si+0x28]
loc_26fb:
  cmp al, byte ptr [bx]
  jc loc_2757
  nop
  nop
  nop
  inc bx
  inc bx
  inc bx
  cmp byte ptr [bx], 0xff
  jnz loc_274d
  nop
  nop
  nop
loc_270d:
  mov al, [0x7d75]
  and al, al
  jnz loc_2724
  nop
  nop
  nop
  test byte ptr [si+0x14], 0x1
  jz loc_2724
  nop
  nop
  nop
loc_2720:
  mov byte ptr [si], 0x0
  ret
loc_2724:
  mov al, byte ptr [si]
  and al, 0x7f
  test byte ptr [si+0x14], 0x4
  jz loc_2733
  nop
  nop
  nop
  or al, 0x80
loc_2733:
  mov byte ptr [si], al
  mov byte ptr [si+0x26], 0x0
  mov al, byte ptr [si+0x1c]
  mov byte ptr [si+0x2], al
  mov ax, word ptr [si+0x1e]
  cmp ax, 0x140
  jnc loc_2720
  mov word ptr [si+0x4], ax
  jmp sub_26a3
loc_274d:
  mov word ptr [si+0x24], bx
  mov al, 0x0
  mov byte ptr [si+0x28], al
  jmp loc_26fb
loc_2757:
  inc al
  mov byte ptr [si+0x28], al
  inc bx
  mov al, byte ptr [bx]
  and al, al
  jns loc_276e
  nop
  nop
  nop
  add al, byte ptr [si+0x2]
  jnc loc_270d
  jmp loc_2777
  db 90h
loc_276e:
  add al, byte ptr [si+0x2]
  jc loc_270d
  cmp al, 0xe8
  jnc loc_270d
loc_2777:
  mov byte ptr [si+0x2], al
  inc bx
  mov cl, byte ptr [bx]
  sub ch, ch
  mov ax, word ptr [si+0x4]
  and cl, cl
  jns loc_278b
  nop
  nop
  nop
  dec ch
loc_278b:
  add ax, cx
  and ah, ah
  jz loc_27a3
  nop
  nop
  nop
  cmp ah, 0x1
  jz loc_279c
  jmp loc_270d
loc_279c:
  cmp al, 0x40
  jc loc_27a3
  jmp loc_270d
loc_27a3:
  mov word ptr [si+0x4], ax
  ret
loc_27a7:
  mov al, byte ptr [si+0x14]
  test al, 0x80
  jz loc_27ca
  nop
  nop
  nop
  mov bl, byte ptr [0x7e80]
  add bl, 0xc
  mov dx, word ptr [0x7e82]
  add dx, 0xa
  call sub_13ed
  jz loc_2836
  nop
  nop
  nop
  mov al, byte ptr [si+0x14]
loc_27ca:
  test al, 0x40
  jz loc_27ee
  nop
  nop
  nop
  mov al, [0x7d6a]
  and al, al
  jz loc_27eb
  nop
  nop
  nop
  mov bl, byte ptr [0x7d7b]
  mov dx, word ptr [0x7d7c]
  call sub_13ed
  jz loc_2836
  nop
  nop
  nop
loc_27eb:
  mov al, byte ptr [si+0x14]
loc_27ee:
  test al, 0x20
  jz loc_281a
  nop
  nop
  nop
  mov al, [0x7eae]
  and al, al
  jz loc_2817
  nop
  nop
  nop
  mov bl, byte ptr [0x7d7e]
  mov dx, word ptr [0x7d7f]
  call sub_13ed
  jnz loc_2817
  nop
  nop
  nop
  mov byte ptr [0x7eae], 0x0
  jmp loc_2836
  db 90h
loc_2817:
  mov al, byte ptr [si+0x14]
loc_281a:
  test al, 0x10
  jnz loc_2822
  nop
  nop
  nop
loc_2821:
  ret
loc_2822:
  mov al, [0x7d85]
  and al, al
  jz loc_2821
  mov bl, byte ptr [0x7d82]
  mov dx, word ptr [0x7d83]
  call sub_13ed
  jnz loc_2821
loc_2836:
  cmp byte ptr [0x7d75], 0x0
  jz loc_2841
  nop
  nop
  nop
  ret
loc_2841:
  mov al, byte ptr [si]
  and al, 0x7f
  test byte ptr [si+0x14], 0x8
  jz loc_2850
  nop
  nop
  nop
  or al, 0x80
loc_2850:
  mov byte ptr [si], al
  mov byte ptr [si+0x26], 0x1
  mov byte ptr [si+0x28], 0x0
  mov ax, word ptr [si+0x22]
  mov word ptr [si+0x24], ax
  ret
sub_26a3 endp

sub_2861 proc near
  call sub_28db
  call sub_12ae
  jnz loc_286f
  nop
  nop
  nop
  call sub_19cf
loc_286f:
  call sub_13ac
  jnz loc_2877
  jmp loc_24c4
loc_2877:
  mov al, [0x7eae]
  and al, al
  jnz loc_2884
  nop
  nop
  nop
  jmp loc_28ac
  db 90h
loc_2884:
  mov bl, byte ptr [0x7eb0]
  mov dx, word ptr [0x7eb2]
  add dx, 0x6
  test byte ptr [0x7d87], 0x80
  jnz loc_289c
  nop
  nop
  nop
  add bl, 0x18
loc_289c:
  call sub_1317
  jnz loc_28ac
  nop
  nop
  nop
  mov byte ptr [0x7eae], 0x0
  jmp loc_24c4
loc_28ac:
  mov al, [0x7d85]
  and al, al
  jz loc_28be
  nop
  nop
  nop
  call sub_134b
  jnz loc_28be
  jmp loc_24c4
loc_28be:
  mov al, [0x7d6a]
  and al, al
  jnz loc_28c9
  nop
  nop
  nop
loc_28c8:
  ret
loc_28c9:
  mov bl, byte ptr [0x7d7b]
  mov dx, word ptr [0x7d7c]
  call sub_1317
  jnz loc_28c8
  mov byte ptr [si+0x2e], 0x14
  ret
sub_2861 endp

sub_28db proc near
  mov al, byte ptr [si+0x2e]
  and al, al
  jz loc_28e8
  nop
  nop
  nop
  dec byte ptr [si+0x2e]
loc_28e8:
  cmp byte ptr [si+0x26], 0xff
  jz loc_28f1
  jmp loc_29ca
loc_28f1:
  cmp byte ptr [si+0x2e], 0x0
  jz loc_28fb
  nop
  nop
  nop
  ret
loc_28fb:
  mov al, byte ptr [si+0x20]
  add al, 0x8
  mov ah, byte ptr [si+0x4]
  xor ah, byte ptr [si+0x2]
  and ah, 0x4
  jz loc_2910
  nop
  nop
  nop
  inc al
loc_2910:
  mov byte ptr [si+0x8], al
  mov ax, [0x7e82]
  and al, 0xfe
  mov bx, word ptr [si+0x4]
  and bl, 0xfe
  cmp ax, bx
  jnz loc_2968
  nop
  nop
  nop
loc_2925:
  mov al, byte ptr [si+0x2]
  cmp al, byte ptr [0x7e80]
  mov ah, 0x2
  jc loc_2935
  nop
  nop
  nop
  mov ah, 0xfe
loc_2935:
  mov byte ptr [si+0x28], ah
  add al, ah
  mov bl, al
  mov dx, word ptr [si+0x4]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0x70
  jz loc_294d
  nop
  nop
  nop
  ret
loc_294d:
  mov al, [0x7d67]
  and al, 0x4
  jz loc_2957
  jmp loc_24c4
loc_2957:
  mov byte ptr [si+0x2], bl
  mov al, [0x7d67]
  and al, 0x82
  jz loc_2965
  nop
  nop
  nop
  ret
loc_2965:
  jmp loc_29c6
  db 90h
loc_2968:
  mov ax, 0xfffe
  jc loc_2973
  nop
  nop
  nop
  mov ax, 0x2
loc_2973:
  add bx, ax
  push ax
  cmp bh, 0x0
  jz loc_2990
  nop
  nop
  nop
  cmp bh, 0x1
  jz loc_298b
  nop
  nop
  nop
loc_2986:
  mov byte ptr [si], 0x0
  pop ax
  ret
loc_298b:
  cmp bl, 0x40
  jnc loc_2986
loc_2990:
  mov dx, bx
  mov bl, byte ptr [si+0x2]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0x70
  pop ax
  jz loc_29b8
  nop
  nop
  nop
  test ah, 0x80
  jnz loc_29b2
  nop
  nop
  nop
  mov byte ptr [si+0x26], 0x0
  jmp loc_29ca
  db 90h
loc_29b2:
  mov dx, word ptr [si+0x4]
  jmp loc_2925
loc_29b8:
  mov al, [0x7d67]
  mov word ptr [si+0x4], dx
  and al, 0x82
  jz loc_29c6
  nop
  nop
  nop
  ret
loc_29c6:
  mov byte ptr [si+0x26], 0x0
loc_29ca:
  mov dl, byte ptr [si+0x2a]
  mov dh, byte ptr [si+0x4]
  mov al, byte ptr [si+0x5]
  mov bx, word ptr [si+0x2c]
  sub ah, ah
  test bh, 0x80
  jz loc_29e2
  nop
  nop
  nop
  dec ah
loc_29e2:
  add dx, bx
  adc al, ah
  mov ah, dl
  mov dl, dh
  mov dh, al
  mov bl, byte ptr [si+0x2]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0x70
  jnz loc_2a5b
  nop
  nop
  nop
  mov al, [0x7d67]
  and al, 0x4
  jz loc_2a06
  jmp loc_24c4
loc_2a06:
  cmp dh, 0x0
  jz loc_2a1a
  nop
  nop
  nop
  cmp dl, 0x40
  jc loc_2a1a
  nop
  nop
  nop
  mov byte ptr [si], 0x0
  ret
loc_2a1a:
  mov al, [0x7d67]
  and al, 0x80
  jz loc_2a40
  nop
  nop
  nop
  mov al, byte ptr [si+0x2]
  and al, 0x7
  cmp al, 0x4
  jnz loc_2a5b
  nop
  nop
  nop
  mov cx, word ptr [0x7e82]
  cmp dx, cx
  jnc loc_2a5b
  nop
  nop
  nop
  mov byte ptr [si+0x26], 0xff
  ret
loc_2a40:
  mov word ptr [si+0x4], dx
  mov byte ptr [si+0x2a], bl
  mov ax, word ptr [si+0x2c]
  add ax, 0x80
  cmp ah, 0x8
  jc loc_2a57
  nop
  nop
  nop
  mov ax, 0x800
loc_2a57:
  mov word ptr [si+0x2c], ax
  ret
loc_2a5b:
  mov al, byte ptr [si+0x4]
  and al, 0xf8
  or al, 0x3
  mov byte ptr [si+0x4], al
  mov word ptr [si+0x2c], 0x100
  cmp byte ptr [si+0x2e], 0x0
  jz loc_2a74
  nop
  nop
  nop
  ret
loc_2a74:
  mov al, [0x7d67]
  and al, 0x2
  jz loc_2a9d
  nop
  nop
  nop
  mov al, byte ptr [si+0x2]
  and al, 0xe
  cmp al, 0x4
  jnz loc_2a9d
  nop
  nop
  nop
  mov dx, word ptr [0x7e82]
  mov ax, word ptr [si+0x4]
  cmp dx, ax
  jnc loc_2a9d
  nop
  nop
  nop
  mov byte ptr [si+0x26], 0xff
  ret
loc_2a9d:
  mov bx, 0x8143
  test byte ptr [si+0x28], 0x80
  jz loc_2aac
  nop
  nop
  nop
  mov bx, 0x8147
loc_2aac:
  mov al, byte ptr [si+0x2]
  and al, 0xe
  sub ah, ah
  shr al, 1
  shr al, 1
  shr al, 1
  add bx, ax
  mov al, byte ptr [bx]
  add al, byte ptr [si+0x20]
  mov byte ptr [si+0x8], al
  mov al, byte ptr [si+0x28]
  and al, al
  jnz loc_2ad5
  nop
  nop
  nop
  mov byte ptr [si+0x28], 0x2
  mov al, 0x2
  and al, al
loc_2ad5:
  jns loc_2ae5
  nop
  nop
  nop
  add al, byte ptr [si+0x2]
  jc loc_2aef
  nop
  nop
  nop
  jmp loc_2b22
  db 90h
loc_2ae5:
  add al, byte ptr [si+0x2]
  cmp al, 0xe8
  jnc loc_2b22
  nop
  nop
  nop
loc_2aef:
  mov bl, al
  mov dx, word ptr [si+0x4]
  call sub_11bc
  mov al, [0x7d67]
  and al, 0xf0
  jnz loc_2b22
  nop
  nop
  nop
  mov byte ptr [si+0x2], bl
  and bl, 0x1e
  cmp bl, 0x8
  jz loc_2b10
  nop
  nop
  nop
  ret
loc_2b10:
  call sub_024a
  and al, 0x1
  mov ah, 0x2
  jz loc_2b1e
  nop
  nop
  nop
  mov ah, 0xfe
loc_2b1e:
  mov byte ptr [si+0x28], ah
  ret
loc_2b22:
  mov al, byte ptr [si+0x28]
  neg al
  jnz loc_2b2e
  nop
  nop
  nop
  mov al, 0x2
loc_2b2e:
  mov byte ptr [si+0x28], al
  ret
sub_28db endp

sub_2b32 proc near
  mov si, word ptr [0x7d9a]
  mov ch, byte ptr [si]
  and ch, ch
  jnz loc_2b42
  nop
  nop
  nop
  jmp sub_2b4d
  db 90h
loc_2b42:
  add word ptr [0x7d9a], 0x1
  mov cl, 0x0
  call sub_2b54
  ret
sub_2b32 endp

sub_2b4d proc near
  in al, 0x61
  and al, 0xfd
  out 0x61, al
  ret
sub_2b4d endp

sub_2b54 proc near
  mov dx, 0x43
  mov al, 0xb6
  out dx, al
  dec dx
  mov al, cl
  out dx, al
  mov al, ch
  out dx, al
  in al, 0x61
  or al, 0x3
  out 0x61, al
  ret
sub_2b54 endp

sub_2b68 proc near
  mov bx, 0x3
loc_2b6b:
  in al, 0x61
  and al, 0xfc
  out 0x61, al
  mov cx, 0x320
loc_2b74:
  loop loc_2b74
  or al, 0x2
  out 0x61, al
  mov cx, 0x2bc
loc_2b7d:
  loop loc_2b7d
  dec bx
  jnz loc_2b6b
  ret
sub_2b68 endp

sub_2b83 proc near
  push ax
  push dx
  mov al, ah
  call sub_2b90
  pop dx
  inc dl
  inc dl
  pop ax
sub_2b83 endp ; sp-analysis failed

sub_2b90 proc near
  mov cx, 0x1040
  mov ds, cx
  push di
  push si
  push cx
  push es
  push dx
  mov di, 0x8132
  sub ah, ah
  push ax
  and al, 0xf0
  mov cl, 0x4
  shr al, cl
  mov si, 0x8122
  add si, ax
  mov al, byte ptr [si]
  mov byte ptr [di], al
  inc di
  pop ax
  and al, 0xf
  mov si, 0x8122
  add si, ax
  mov al, byte ptr [si]
  mov byte ptr [di], al
  dec di
  pop dx
  mov ax, 0x1301
  mov bx, 0x7
  mov cx, 0x2
  mov bp, 0x1040
  mov es, bp
  mov bp, 0x8132
  int 0x10
  pop es
  pop cx
  pop si
  pop di
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
sub_2b90 endp
seg001 ends