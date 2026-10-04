./cicodis arkanoid.txt > arkanoid.cpp

# Convert cico16.h syntax to cicoemu.h syntax
sed -i '' '1s|#include "cico16.h"|#include <stdio.h>\n#include "cicoemu.h"\nusing namespace CicoContext;|' arkanoid.cpp
sed -i '' 's/out8(/out(/g; s/out16(/out(/g' arkanoid.cpp
sed -i '' 's/indirectCall(/callIndirect(/g' arkanoid.cpp
sed -i '' 's/indirectJump(/jumpIndirect(/g' arkanoid.cpp
sed -i '' 's/al = in8(\(.*\));/in(al, \1);/g' arkanoid.cpp
sed -i '' 's/mul8(/mul(/g; s/mul16(/mul(/g' arkanoid.cpp
sed -i '' 's/ror8(/ror(/g; s/rcr16(/rcr(/g; s/ror16(/ror(/g' arkanoid.cpp
sed -i '' 's/div16(/div(/g; s/rol8(/rol(/g' arkanoid.cpp
sed -i '' 's/<ES_DI, DS_SI>/<MemAuto, MemAuto, DirAuto>/g' arkanoid.cpp
sed -i '' 's/<DS_SI>/<MemAuto, DirAuto>/g' arkanoid.cpp
sed -i '' 's/<ES_DI>/<MemAuto, DirAuto>/g' arkanoid.cpp
sed -i '' 's/flags\.interrupts = 0;/flags.interrupts = false;/g' arkanoid.cpp
sed -i '' 's/flags\.interrupts = 1;/flags.interrupts = true;/g' arkanoid.cpp
sed -i '' 's/flags\.carry = 0;/flags.carry = false;/g; s/flags\.carry = 1;/flags.carry = true;/g' arkanoid.cpp
sed -i '' 's/push(flagAsReg());/tx = flags.carry | (flags.zero << 1);\n    push(tx);/g' arkanoid.cpp
sed -i '' 's/flagsFromReg(pop());/tx = pop();\n    flags.carry = tx \& 1;\n    flags.zero = (tx << 1) \& 1;/g' arkanoid.cpp
sed -i '' 's/for (; cx != 0; --cx) movsb<\(.*\)>();/rep_movsb<\1>();/g' arkanoid.cpp
sed -i '' 's/for (; cx != 0; --cx) movsw<\(.*\)>();/rep_movsw<\1>();/g' arkanoid.cpp
sed -i '' 's/for (; cx != 0; --cx) stosb<\(.*\)>();/rep_stosb<\1>();/g' arkanoid.cpp
sed -i '' 's/for (; cx != 0; --cx) stosw<\(.*\)>();/rep_stosw<\1>();/g' arkanoid.cpp
sed -i '' 's/al = lodsb<\(.*\)>();/lodsb<\1>();/g' arkanoid.cpp
sed -i '' 's/ax = lodsw<\(.*\)>();/lodsw<\1>();/g' arkanoid.cpp
sed -i '' 's/stosb<\(.*\)>(al);/stosb<\1>();/g' arkanoid.cpp
sed -i '' 's/stosw<\(.*\)>(ax);/stosw<\1>();/g' arkanoid.cpp
sed -i '' 's/    stop("stack_below");/    \/\/ stop("stack_below");/g' arkanoid.cpp
sed -i '' 's/    stop("stack_unbalanced");/    \/\/ stop("stack_unbalanced");/g' arkanoid.cpp

patch ./arkanoid.cpp ./arkanoid.patch
mv arkanoid.cpp run