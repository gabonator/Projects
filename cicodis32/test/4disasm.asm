sub_15e390 begin
15e390 jmp 0x15e3a4
sub_15e390 ends

sub_15e3a4 begin
15e3a4 sti 
15e3a5 and esp, 0xfffffffc
15e3a8 mov ebx, esp
15e3aa mov dword ptr [0x17c238], ebx
15e3b0 mov dword ptr [0x17c224], ebx
15e3b6 mov ax, 0x24
15e3ba mov word ptr [0x17c230], ax
15e3c0 mov ebx, 0x50484152
15e3c5 sub eax, eax
15e3c7 mov ah, 0x30
15e3c9 int 0x21
15e3cb mov byte ptr [0x17c25a], al
15e3d0 mov byte ptr [0x17c25b], ah
15e3d6 mov ecx, eax
15e3d8 sub esi, esi
15e3da mov edi, 0x81
15e3df shr eax, 0x10
15e3e2 cmp ax, 0x4458
15e3e6 jne 0x15e42e
15e3e8 mov ah, 0
15e3ea cmp ebx, 0x4a613231
15e3f0 jne 0x15e3f4
15e3f2 mov ah, 1
15e3f4 sub bl, 0x2f
15e3f7 mov al, bl
15e3f9 push eax
15e3fa mov es, word ptr [0x17c230]
15e401 mov ebx, dword ptr es:[0x5c]
15e408 add ebx, 0xfff
15e40e and ebx, 0xfffff000
15e414 mov dword ptr [0x17c224], ebx
15e41a shr ebx, 0xc
15e41d mov eax, ds
15e41f mov es, eax
15e421 mov ah, 0x4a
15e423 int 0x21
15e425 pop eax
15e426 mov ebx, ds
15e428 mov cx, 0x2c
15e42c jmp 0x15e46f
15e42e mov dx, 0x78
15e432 mov ax, 0xff00
15e436 int 0x21
15e438 test al, al
15e43a je 0x15e46d
15e43c mov eax, gs
15e43e test ax, ax
15e441 je 0x15e449
15e443 mov word ptr [0x17c214], ax
15e449 mov ax, 6
15e44d mov ebx, ds
15e44f int 0x31
15e451 mov al, 1
15e453 mov ah, 0
15e455 or dx, cx
15e458 je 0x15e45c
15e45a mov ah, 1
15e45c mov word ptr [0x17c230], es
15e463 mov cx, word ptr es:[0x2c]
15e46b jmp 0x15e46f
15e46d xor eax, eax
15e46f mov byte ptr [0x17c251], al
15e474 mov byte ptr [0x17c252], ah
15e47a mov es, ebx
15e47c mov word ptr es:[0x15e65d], ds
15e484 mov dword ptr [0x17c254], esi
15e48a mov word ptr [0x17c258], cx
15e491 push esi
15e492 mov es, word ptr [0x17c230]
15e499 mov edx, 0x17c75c
15e49e add edx, 0xf
15e4a1 and dl, 0xf0
15e4a4 sub ecx, ecx
15e4a6 mov cl, byte ptr es:[edi - 1]
15e4aa cld 
15e4ab mov al, 0x20
15e4ad repe scasb al, byte ptr es:[edi]
15e4af lea esi, [edi - 1]
15e4b2 mov edi, edx
15e4b4 mov ebx, es
15e4b6 mov edx, ds
15e4b8 mov ds, ebx
15e4ba mov es, edx
15e4bc je 0x15e4c1
15e4be inc ecx
15e4bf rep movsb byte ptr es:[edi], byte ptr [esi]
15e4c1 sub al, al
15e4c3 stosb byte ptr es:[edi], al
15e4c4 stosb byte ptr es:[edi], al
15e4c5 pop esi
15e4c6 dec edi
15e4c7 push edi
15e4c8 push edx
15e4c9 mov ds, word ptr es:[0x17c258]
15e4d1 mov bx, 0x100
15e4d5 mov eax, dword ptr [esi]
15e4d7 or eax, 0x20202020
15e4dc cmp eax, 0x37386f6e
15e4e1 jne 0x15e4ee
15e4e3 cmp byte ptr [esi + 4], 0x3d
15e4e7 jne 0x15e501
15e4e9 or bl, 1
15e4ec jmp 0x15e501
15e4ee cmp eax, 0x3d6e666c
15e4f3 jne 0x15e501
15e4f5 mov al, byte ptr [esi + 4]
15e4f8 or al, 0x20
15e4fa cmp al, 0x6e
15e4fc jne 0x15e501
15e4fe and bh, 0xfe
15e501 cmp byte ptr [esi], 0
15e504 lodsb al, byte ptr [esi]
15e505 jne 0x15e501
15e507 cmp byte ptr [esi], 0
15e50a jne 0x15e4d5
15e50c lodsb al, byte ptr [esi]
15e50d inc esi
15e50e inc esi
15e50f cmp byte ptr [esi], 0
15e512 movsb byte ptr es:[edi], byte ptr [esi]
15e513 jne 0x15e50f
15e515 pop ds
15e516 pop esi
15e517 mov byte ptr [0x17c250], bl
15e51d and byte ptr [0x17c264], bh
15e523 mov dword ptr [0x17c234], edi
15e529 mov ebx, esp
15e52b mov dword ptr [0x17c220], ebx
15e531 mov ecx, 0x17c75c
15e536 mov edi, 0x17c6a8
15e53b sub ecx, edi
15e53d cmp byte ptr [0x17c251], 1
15e544 jne 0x15e553
15e546 cmp ecx, 0x1000
15e54c jbe 0x15e553
15e54e mov ecx, 0x1000
15e553 mov dl, cl
15e555 shr ecx, 2
15e558 sub eax, eax
15e55a rep stosd dword ptr es:[edi], eax
15e55c mov cl, dl
15e55e and cl, 3
15e561 rep stosb byte ptr es:[edi], al
15e563 mov eax, 0x17c75c
15e568 add eax, 0xf
15e56b and al, 0xf0
15e56d mov dword ptr [0x17c228], eax
15e572 mov dword ptr [0x17c22c], esi
15e578 sub ebp, ebp
15e57a mov eax, 0xff
15e57f call 0x15e830
15e584 call 0x15e7e0
15e589 push eax
15e58a jmp 0x15e5bc
gap 48 bytes
15e5bc xor eax, eax
15e5be mov edx, 0xf
15e5c3 call 0x15e880
15e5c8 pop eax
15e5c9 mov ah, 0x4c
15e5cb int 0x21
sub_15e3a4 ends

sub_15e7e0 begin
15e589 push eax
15e58a jmp 0x15e5bc
gap 48 bytes
15e5bc xor eax, eax
15e5be mov edx, 0xf
15e5c3 call 0x15e880
15e5c8 pop eax
15e5c9 mov ah, 0x4c
15e5cb int 0x21
gap 531 bytes
15e7e0 push edx
15e7e1 push ebp
15e7e2 mov ebp, esp
15e7e4 mov eax, dword ptr [0x17c23c]
15e7e9 add eax, 3
15e7ec and al, 0xfc
15e7ee mov edx, dword ptr [0x17c23c]
15e7f4 sub esp, eax
15e7f6 mov eax, esp
15e7f8 add eax, edx
15e7fa mov dword ptr [0x17c240], eax
15e7ff call 0x15fee0
15e804 mov edx, dword ptr [0x17c6d0]
15e80a mov eax, dword ptr [0x17c6d4]
15e80f call 0x15e010
15e814 jmp 0x15ff31
gap 5912 bytes
15ff31 mov ecx, eax
15ff33 call dword ptr [0x17c390]
15ff39 mov edx, 0xff
15ff3e mov eax, 0x10
15ff43 call 0x15e880
15ff48 call dword ptr [0x17c390]
15ff4e call dword ptr [0x17c394]
15ff54 mov eax, ecx
15ff56 jmp 0x15e589
sub_15e7e0 ends

sub_15e830 begin
15e830 push ebx
15e831 push ecx
15e832 push edx
15e833 push esi
15e834 push es
15e835 mov dh, al
15e837 mov esi, 0x17c68a
15e83c mov eax, 0x17c660
15e841 mov ecx, esi
15e843 mov dl, dh
15e845 cmp esi, eax
15e847 jbe 0x15e863
15e849 cmp byte ptr [eax], 2
15e84c je 0x15e859
15e84e mov bh, byte ptr [eax + 1]
15e851 cmp dl, bh
15e853 jb 0x15e859
15e855 mov ecx, eax
15e857 mov dl, bh
15e859 add eax, 6
15e85c cmp eax, 0x17c68a
15e861 jb 0x15e849
15e863 cmp ecx, 0x17c68a
15e869 je 0x15e878
15e86b lea eax, [ecx + 2]
15e86e call 0x15e820
15e873 mov byte ptr [ecx], 2
15e876 jmp 0x15e83c
15e878 pop es
15e879 pop esi
15e87a pop edx
15e87b pop ecx
15e87c pop ebx
15e87d ret 
sub_15e830 ends

sub_15e880 begin
15e880 push ebx
15e881 push ecx
15e882 push esi
15e883 push es
15e884 mov bl, al
15e886 mov dh, dl
15e888 mov esi, 0x17c690
15e88d mov eax, 0x17c68a
15e892 mov ecx, esi
15e894 mov dl, bl
15e896 cmp esi, eax
15e898 jbe 0x15e8b4
15e89a cmp byte ptr [eax], 2
15e89d je 0x15e8aa
15e89f mov bh, byte ptr [eax + 1]
15e8a2 cmp dl, bh
15e8a4 ja 0x15e8aa
15e8a6 mov ecx, eax
15e8a8 mov dl, bh
15e8aa add eax, 6
15e8ad cmp eax, 0x17c690
15e8b2 jb 0x15e89a
15e8b4 cmp ecx, 0x17c690
15e8ba je 0x15e8d0
15e8bc cmp dh, byte ptr [ecx + 1]
15e8bf jae 0x15e8c6
15e8c1 mov byte ptr [ecx], 2
15e8c4 jmp 0x15e88d
15e8c6 lea eax, [ecx + 2]
15e8c9 call 0x15e820
15e8ce jmp 0x15e8c1
15e8d0 pop es
15e8d1 pop esi
15e8d2 pop ecx
15e8d3 pop ebx
15e8d4 ret 
sub_15e880 ends

sub_15e010 begin
15e010 push 0x9c
15e015 call 0x15e27b
15e01a push ebx
15e01b push ecx
15e01c push edx
15e01d push esi
15e01e push edi
15e01f push ebp
15e020 sub esp, 0x80
15e026 xor eax, eax
15e028 mov dword ptr [esp + 0x6c], eax
15e02c mov dword ptr [esp + 0x70], 0xbff80000
15e034 mov dword ptr [esp + 0x74], eax
15e038 mov dword ptr [esp + 0x78], 0xbff00000
15e040 mov dword ptr [esp + 0x34], eax
15e044 mov edi, 0x40000000
15e049 mov dword ptr [esp + 0x38], edi
15e04d mov dword ptr [esp + 0x4c], eax
15e051 mov dword ptr [esp + 0x50], edi
15e055 mov ebp, 0xa0000
15e05a mov word ptr [esp], 0x13
15e060 mov ebx, esp
15e062 mov edx, esp
15e064 mov eax, 0x10
15e069 call 0x15e2b0
15e06e xor eax, eax
15e070 xor ecx, ecx
15e072 mov edx, ecx
15e074 mov eax, 0x3c8
15e079 call 0x15e2d0
15e07e mov dword ptr [esp + 0x7c], ecx
15e082 fild dword ptr [esp + 0x7c]
15e086 fmul qword ptr [0x17c004]
15e08c fstp qword ptr [esp + 0x24]
15e090 fld1 
15e092 fmul qword ptr [esp + 0x24]
15e096 call 0x15e2dc
15e09b fmul qword ptr [0x17c00c]
15e0a1 fsubr qword ptr [0x17c014]
15e0a7 call 0x15e358
15e0ac fistp qword ptr [esp + 0x54]
15e0b0 mov edx, dword ptr [esp + 0x54]
15e0b4 mov eax, 0x3c9
15e0b9 call 0x15e2d0
15e0be fld qword ptr [esp + 0x24]
15e0c2 fmul qword ptr [0x17c01c]
15e0c8 call 0x15e2dc
15e0cd fmul qword ptr [0x17c00c]
15e0d3 fsubr qword ptr [0x17c014]
15e0d9 call 0x15e358
15e0de fistp qword ptr [esp + 0x54]
15e0e2 mov edx, dword ptr [esp + 0x54]
15e0e6 mov eax, 0x3c9
15e0eb call 0x15e2d0
15e0f0 fld qword ptr [esp + 0x24]
15e0f4 fmul qword ptr [0x17c024]
15e0fa call 0x15e2dc
15e0ff fmul qword ptr [0x17c00c]
15e105 fsubr qword ptr [0x17c014]
15e10b call 0x15e358
15e110 fistp qword ptr [esp + 0x54]
15e114 mov edx, dword ptr [esp + 0x54]
15e118 mov eax, 0x3c9
15e11d call 0x15e2d0
15e122 inc ecx
15e123 cmp ecx, 0x100
15e129 jl 0x15e072
15e12f xor ebx, ebx
15e131 jmp 0x15e140
15e133 inc ebx
15e134 cmp ebx, 0xc8
15e13a jge 0x15e241
15e140 mov dword ptr [esp + 0x7c], ebx
15e144 fild dword ptr [esp + 0x7c]
15e148 fmul qword ptr [esp + 0x4c]
15e14c fdiv qword ptr [0x17c02c]
15e152 fadd qword ptr [esp + 0x74]
15e156 fstp qword ptr [esp + 0x44]
15e15a xor ecx, ecx
15e15c jmp 0x15e210
15e161 inc edx
15e162 cmp edx, 0x100
15e168 ja 0x15e1cf
15e16a fld qword ptr [esp + 0x5c]
15e16e fmul st(0)
15e170 fld qword ptr [esp + 0x64]
15e174 fmul st(0)
15e176 fsubp st(1)
15e178 fadd qword ptr [esp + 0x2c]
15e17c fstp qword ptr [esp + 0x1c]
15e180 fld qword ptr [esp + 0x5c]
15e184 fmul qword ptr [0x17c03c]
15e18a fmul qword ptr [esp + 0x64]
15e18e fadd qword ptr [esp + 0x44]
15e192 fstp qword ptr [esp + 0x3c]
15e196 mov eax, dword ptr [esp + 0x1c]
15e19a mov dword ptr [esp + 0x5c], eax
15e19e mov eax, dword ptr [esp + 0x20]
15e1a2 mov dword ptr [esp + 0x60], eax
15e1a6 mov eax, dword ptr [esp + 0x3c]
15e1aa mov dword ptr [esp + 0x64], eax
15e1ae mov eax, dword ptr [esp + 0x40]
15e1b2 mov dword ptr [esp + 0x68], eax
15e1b6 fld qword ptr [esp + 0x1c]
15e1ba fmul st(0)
15e1bc fld qword ptr [esp + 0x3c]
15e1c0 fmul st(0)
15e1c2 faddp st(1)
15e1c4 fcomp qword ptr [0x17c044]
15e1ca fnstsw ax
15e1cc sahf 
15e1cd jb 0x15e161
15e1cf cmp edx, 0x100
15e1d5 jae 0x15e203
15e1d7 mov dword ptr [esp + 0x7c], edx
15e1db fild dword ptr [esp + 0x7c]
15e1df fmul qword ptr [0x17c04c]
15e1e5 fmul qword ptr [0x17c054]
15e1eb call 0x15e358
15e1f0 fistp dword ptr [esp + 0x7c]
15e1f4 mov al, byte ptr [esp + 0x7c]
15e1f8 imul edx, ebx, 0x140
15e1fe add edx, ebp
15e200 mov byte ptr [ecx + edx], al
15e203 inc ecx
15e204 cmp ecx, 0x140
15e20a jge 0x15e133
15e210 mov dword ptr [esp + 0x7c], ecx
15e214 fild dword ptr [esp + 0x7c]
15e218 fmul qword ptr [esp + 0x34]
15e21c fdiv qword ptr [0x17c034]
15e222 fadd qword ptr [esp + 0x6c]
15e226 fstp qword ptr [esp + 0x2c]
15e22a xor edx, edx
15e22c mov dword ptr [esp + 0x5c], edx
15e230 mov dword ptr [esp + 0x60], edx
15e234 mov dword ptr [esp + 0x64], edx
15e238 mov dword ptr [esp + 0x68], edx
15e23c jmp 0x15e16a
15e241 call 0x15e370
15e246 mov word ptr [esp], 3
15e24c mov ebx, esp
15e24e mov edx, esp
15e250 mov eax, 0x10
15e255 call 0x15e2b0
15e25a mov eax, 1
15e25f add esp, 0x80
15e265 pop ebp
15e266 pop edi
15e267 pop esi
15e268 pop edx
15e269 pop ecx
15e26a pop ebx
15e26b ret 
sub_15e010 ends

sub_15fee0 begin
15fee0 push ebx
15fee1 push ecx
15fee2 push esi
15fee3 push edi
15fee4 mov al, byte ptr [0x17c251]
15fee9 cmp al, 2
15feeb jl 0x15fef6
15feed cmp al, 9
15feef jg 0x15fef6
15fef1 pop edi
15fef2 pop esi
15fef3 pop ecx
15fef4 pop ebx
15fef5 ret 
15fef6 call 0x164000
15fefb cmp eax, 1
15fefe jne 0x15fef1
15ff00 mov esi, 0x15e65f
15ff05 mov ebx, 0x15e654
15ff0a sub esi, 0x15e654
15ff10 mov di, si
15ff13 shr esi, 0x10
15ff16 mov cx, bx
15ff19 shr ebx, 0x10
15ff1c mov ax, 0x600
15ff20 int 0x31
15ff22 sbb eax, eax
15ff24 pop edi
15ff25 pop esi
15ff26 pop ecx
15ff27 pop ebx
15ff28 ret 
sub_15fee0 ends

sub_15e820 begin
15e820 push es
15e821 cmp dword ptr [eax], 0
15e824 jne 0x15e828
15e826 pop es
15e827 ret 
15e828 push ds
15e829 pop es
15e82a call dword ptr [eax]
15e82c pop es
15e82d ret 
sub_15e820 ends

sub_15e27b begin
15e27b push eax
15e27c mov eax, dword ptr [esp + 8]
15e280 cmp eax, esp
15e282 jae 0x15e2a0
15e284 sub eax, esp
15e286 neg eax
15e288 cmp eax, dword ptr [0x17c234]
15e28e ja 0x15e29a
15e290 mov ax, ss
15e293 cmp ax, word ptr [0x17c1f4]
15e29a je 0x15e2a0
15e29c pop eax
15e29d ret 4
15e2a0 pop eax
15e2a1 mov eax, 0x17c1f6
15e2a6 mov edx, 1
15e2ab jmp 0x15e6c0
gap 729 bytes
15e589 push eax
15e58a jmp 0x15e5bc
15e58c push edx
15e58d push eax
15e58e mov edx, 0x15e399
15e593 mov ax, 0x3d01
15e597 int 0x21
15e599 mov bx, ax
15e59c pop edx
15e59d mov esi, edx
15e59f cld 
15e5a0 lodsb al, byte ptr [esi]
15e5a1 test al, al
15e5a3 jne 0x15e5a0
15e5a5 mov ecx, esi
15e5a7 sub ecx, edx
15e5a9 dec ecx
15e5aa mov ah, 0x40
15e5ac int 0x21
15e5ae mov edx, 0x15e39d
15e5b3 mov ecx, 2
15e5b8 mov ah, 0x40
15e5ba int 0x21
15e5bc xor eax, eax
15e5be mov edx, 0xf
15e5c3 call 0x15e880
15e5c8 pop eax
15e5c9 mov ah, 0x4c
15e5cb int 0x21
gap 243 bytes
15e6c0 mov ebx, eax
15e6c2 mov ecx, edx
15e6c4 mov edx, ds
15e6c6 call 0x15fa60
15e6cb test eax, eax
15e6cd jne 0x15e6d8
15e6cf mov edx, ecx
15e6d1 mov eax, ebx
15e6d3 jmp 0x15e58c
15e6d8 mov eax, ecx
15e6da jmp 0x15e589
sub_15e27b ends

sub_15e2b0 begin
15e2b0 push ecx
15e2b1 push esi
15e2b2 sub esp, 0xc
15e2b5 mov esi, eax
15e2b7 mov eax, esp
15e2b9 mov ecx, esp
15e2bb call 0x15e6e0
15e2c0 mov eax, esi
15e2c2 call 0x15e710
15e2c7 add esp, 0xc
15e2ca pop esi
15e2cb pop ecx
15e2cc ret 
sub_15e2b0 ends

sub_15e2d0 begin
15e2d0 push ecx
15e2d1 mov ecx, eax
15e2d3 mov al, dl
15e2d5 mov edx, ecx
15e2d7 out dx, al
15e2d8 pop ecx
15e2d9 ret 
sub_15e2d0 ends

sub_15e2dc begin
15e2dc fcos 
15e2de call 0x15e2f0
15e2e3 jae 0x15e2dc
15e2e5 ret 
sub_15e2dc ends

sub_15e358 begin
15e358 push 0xc3f
15e35d fnstcw word ptr [esp + 2]
15e361 fldcw word ptr [esp]
15e364 frndint 
15e366 fldcw word ptr [esp + 2]
15e36a lea esp, [esp + 4]
15e36e ret 
sub_15e358 ends

sub_15e370 begin
15e370 push edx
15e371 xor edx, edx
15e373 mov eax, dword ptr [0x17c244]
15e378 mov dword ptr [0x17c244], edx
15e37e test eax, eax
15e380 je 0x15e384
15e382 pop edx
15e383 ret 
15e384 mov ah, 8
15e386 int 0x21
15e388 and eax, 0xff
15e38d pop edx
15e38e ret 
sub_15e370 ends

sub_164000 begin
164000 push ebx
164001 push ecx
164002 push edx
164003 push esi
164004 push edi
164005 sub esp, 8
164008 mov edi, dword ptr [0x17c430]
16400e test edi, edi
164010 jne 0x164064
164012 cmp byte ptr [0x17c251], 1
164019 jne 0x164075
16401b xor ah, ah
16401d mov esi, esp
16401f mov byte ptr [esp], ah
164022 mov byte ptr [esp + 1], ah
164026 xor al, al
164028 mov edx, ds
16402a mov word ptr [esp + 2], ax
16402f mov byte ptr [esp + 4], ah
164033 push ds
164034 mov ds, edx
164036 mov ax, 0x400
16403a int 0x31
16403c mov byte ptr [esi], ah
16403e mov byte ptr [esi + 1], al
164041 mov word ptr [esi + 2], bx
164045 mov byte ptr [esi + 4], cl
164048 mov byte ptr [esi + 5], dh
16404b mov byte ptr [esi + 6], dl
16404e pop ds
16404f xor eax, eax
164051 movzx esi, byte ptr [esp + 1]
164056 mov al, byte ptr [esp]
164059 add eax, esi
16405b test eax, eax             ***
16405d jle 0x164080              >>>>>
16405f mov edi, 1
164064 mov eax, edi
164066 mov dword ptr [0x17c430], edi
16406c add esp, 8
16406f pop edi
164070 pop esi
164071 pop edx
164072 pop ecx
164073 pop ebx
164074 ret 
164075 mov ax, 0x1686
164079 int 0x2f
16407b test ax, ax               ****
16407e je 0x16401b
164080 mov edi, 0xffffffff       <<<<
164085 mov eax, edi
164087 mov dword ptr [0x17c430], edi
16408d add esp, 8
164090 pop edi
164091 pop esi
164092 pop edx
164093 pop ecx
164094 pop ebx
164095 ret 
sub_164000 ends

sub_15fa60 begin
15fa60 cmp byte ptr [0x17c38c], 0
15fa67 jne 0x15fa6c
15fa69 xor eax, eax
15fa6b ret 
15fa6c and edx, 0xffff
15fa72 push edx
15fa73 push eax
15fa74 int3 
15fa75 jmp 0x15fa7d
gap 6 bytes
15fa7d mov eax, 1
15fa82 add esp, 8
15fa85 ret 
sub_15fa60 ends

sub_15e6e0 begin
15e6e0 push edx
15e6e1 mov edx, eax
15e6e3 mov eax, cs
15e6e5 mov word ptr [edx + 2], ax
15e6e9 mov eax, ds
15e6eb mov word ptr [edx + 6], ax
15e6ef mov eax, es
15e6f1 mov word ptr [edx], ax
15e6f4 mov eax, ss
15e6f6 mov word ptr [edx + 4], ax
15e6fa mov eax, fs
15e6fc mov word ptr [edx + 8], ax
15e700 mov eax, gs
15e702 mov word ptr [edx + 0xa], ax
15e706 pop edx
15e707 ret 
sub_15e6e0 ends

sub_15e710 begin
15e710 push esi
15e711 push edi
15e712 push ebp
15e713 mov edi, edx
15e715 mov ebp, ebx
15e717 and eax, 0xff
15e71c mov ebx, ecx
15e71e mov edx, ebp
15e720 call 0x15fa88
15e725 mov eax, dword ptr [ebp]
15e728 pop ebp
15e729 pop edi
15e72a pop esi
15e72b ret 
sub_15e710 ends

sub_15e2f0 begin
15e2f0 push ebp
15e2f1 mov ebp, esp
15e2f3 push eax
15e2f4 wait 
15e2f5 fnstsw word ptr [ebp - 2]
15e2f8 wait 
15e2f9 mov ah, byte ptr [ebp - 1]
15e2fc or ah, 1
15e2ff sahf 
15e300 jnp 0x15e31a
15e302 fld xword ptr [0x17c208]
15e308 fxch st(1)
15e30a fprem 
15e30c wait 
15e30d fnstsw word ptr [ebp - 2]
15e310 wait 
15e311 mov ah, byte ptr [ebp - 1]
15e314 sahf 
15e315 jp 0x15e30a
15e317 fstp st(1)
15e319 clc 
15e31a pop eax
15e31b pop ebp
15e31c ret 
sub_15e2f0 ends

sub_15fa88 begin
15fa88 pushfd 
15fa89 push ebp
15fa8a push es
15fa8b push ds
15fa8c push edx
15fa8d push ebx
15fa8e xor edx, edx
15fa90 call 0x15fac8
15fa95 push ds
15fa96 push edx
15fa97 mov ebp, esp
15fa99 mov ds, word ptr [ebp + 0x10]
15fa9d mov edx, dword ptr [ebp + 0xc]
15faa0 mov dword ptr [edx], eax
15faa2 mov dword ptr [edx + 4], ebx
15faa5 mov dword ptr [edx + 8], ecx
15faa8 pop dword ptr [edx + 0xc]
15faab mov dword ptr [edx + 0x10], esi
15faae mov dword ptr [edx + 0x14], edi
15fab1 sbb eax, eax
15fab3 and eax, 1
15fab6 mov dword ptr [edx + 0x18], eax
15fab9 pop eax
15faba pop ebx
15fabb mov word ptr [ebx], es
15fabe mov word ptr [ebx + 6], ax
15fac2 pop edx
15fac3 pop ds
15fac4 pop es
15fac5 pop ebp
15fac6 popfd 
15fac7 ret 
sub_15fa88 ends

sub_15fac8 begin
15fac8 lea eax, [eax + eax*2]
15facb lea eax, [eax + 0x15fb73]
15fad1 push eax
15fad2 mov ah, dl
15fad4 sahf 
15fad5 mov es, word ptr [ebx]
15fad8 mov bp, word ptr [ebx + 6]
15fadc mov eax, dword ptr [edi]
15fade mov ebx, dword ptr [edi + 4]
15fae1 mov ecx, dword ptr [edi + 8]
15fae4 mov edx, dword ptr [edi + 0xc]
15fae7 mov esi, dword ptr [edi + 0x10]
15faea mov edi, dword ptr [edi + 0x14]
15faed mov ds, bp
15faf0 ret 
sub_15fac8 ends

Program ended with exit code: 0