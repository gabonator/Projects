  const fpstack = new Array(8).fill(0);
  let fptop = 0;
  let fppos = 0;
  let compareResult = 0;

  function fppush(value) {
    if (!(fppos < 8)) {
      console.error("FPU stack overflow! fppos=" + fppos + " fptop=" + fptop + " stack=" + JSON.stringify(fpstack));
      debugger;
    }
    assert(fppos < 8, "FPU stack overflow");

    // Guard against NaN/Infinity entering the FPU stack
    if (!Number.isFinite(value)) {
      if (!fppush.hasWarned) {
        console.warn(`fppush: Non-finite values detected - clamping to 0.0 (first: ${value})`);
        fppush.hasWarned = true;
      }
      value = 0.0;
    }

    fptop = (fptop - 1) & 7;
    fpstack[fptop] = value;

    fppos++;
  }

  function fppop() {
    assert(fppos > 0, "FPU stack underflow");

    const value = fpstack[fptop];
    fpstack[fptop] = 0;
    fptop = (fptop + 1) & 7;
    fppos--;

    return value;
  }

  function st(i) {
    const idx = (fptop + i) & 7;
    return fpstack[idx];
  }

  function setst(i, v) {
    const idx = (fptop + i) & 7;
    // Guard against NaN/Infinity propagating through FPU stack
    if (!Number.isFinite(v)) {
      // Only log once per session to avoid spam
      if (!setst.hasWarned) {
        console.warn(`setst: Non-finite values detected in FPU operations - clamping to 0.0`);
        console.warn(`  First occurrence: value=${v} at ST(${i})`);
        console.warn(`  FPU Stack: ST(0)=${st(0)}, ST(1)=${st(1)}, ST(2)=${st(2)}, ST(3)=${st(3)}`);
        setst.hasWarned = true;
      }
      v = 0.0;
    }
    fpstack[idx] = v;
  }

  function fild32(v) {
    fppush((v << 0)); // force int32
  }

  function FromFp64(v) {
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setBigUint64(0, v, true);
    const result = dv.getFloat64(0, true);
    // Replace NaN and Infinity with 0 to prevent audio glitches
    if (!Number.isFinite(result)) {
      if (!FromFp64.hasWarned) {
        console.warn(`FromFp64: Non-finite values in memory detected - clamping to 0.0`);
        console.warn(`  First occurrence: ${result} from BigInt ${v}`);
        FromFp64.hasWarned = true;
      }
      return 0.0;
    }
    return result;
  }

  function toFp64(d) {
    // Replace NaN and Infinity with 0 before storing to prevent propagation
    if (!Number.isFinite(d)) {
      if (!toFp64.hasWarned) {
        console.warn(`toFp64: Non-finite values being stored - clamping to 0.0 (first: ${d})`);
        toFp64.hasWarned = true;
      }
      d = 0.0;
    }
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setFloat64(0, d, true);
    return dv.getBigUint64(0, true);
  }

  function FromFp32(v) {
    const buf = new ArrayBuffer(4);
    const dv = new DataView(buf);
    dv.setUint32(0, v, true);
    const result = dv.getFloat32(0, true);
    // Replace NaN and Infinity with 0 to prevent audio glitches
    if (!Number.isFinite(result)) {
      if (!FromFp32.hasWarned) {
        console.warn(`FromFp32: Non-finite values in memory detected - clamping to 0.0 (first: ${result})`);
        FromFp32.hasWarned = true;
      }
      return 0.0;
    }
    return result;
  }

  function toFp32(d) {
    // Replace NaN and Infinity with 0 before storing to prevent propagation
    if (!Number.isFinite(d)) {
      if (!toFp32.hasWarned) {
        console.warn(`toFp32: Non-finite values being stored - clamping to 0.0 (first: ${d})`);
        toFp32.hasWarned = true;
      }
      d = 0.0;
    }
    const buf = new ArrayBuffer(4);
    const dv = new DataView(buf);
    dv.setFloat32(0, d, true);
    return dv.getUint32(0, true);
  }

  function fld32(v) {
    fppush(FromFp32(v));
  }
  function fld64(v) {
    fppush(FromFp64(v));
  }

  function fmul64(v) {
    //console.log(`  fmul64: ST(0)=${st(0)} * mem=${FromFp64(v)} = ${st(0) * FromFp64(v)}`);
    setst(0, st(0) * FromFp64(v));
  }

  function fadd32(v) {
    setst(0, st(0) + FromFp32(v));
  }

  function fiadd32(v) {
    setst(0, st(0) + v);
  }

  function fadd64(v) {
    //console.log(`  fadd64: ST(0)=${st(0)} + mem=${FromFp64(v)} = ${st(0) + FromFp64(v)}`);
    setst(0, st(0) + FromFp64(v));
  }

  function fsub32(v) { setst(0, st(0) - FromFp32(v)); }
  function fsubr32(v) { setst(0, FromFp32(v) - st(0)); }

  function fsub64(v) {
    //console.log(`  fsub64: ST(0)=${st(0)} - mem=${FromFp64(v)} = ${st(0) - FromFp64(v)}`);
    setst(0, st(0) - FromFp64(v));
  }

  function fsubr64(v) {
    setst(0, FromFp64(v) - st(0));
  }

  function fst64() {
    //console.log(`  fst64: storing ST(0)=${st(0)} to memory as BigInt=${toFp64(st(0))}`);
    return toFp64(st(0));
  }

  function fstp64() {
    return toFp64(fppop());
  }

  function fstp32() {
    return toFp32(fppop());
  }

  function fst32() {
    return toFp32(st(0));
  }

  function fistp64() {
    return BigInt(Math.trunc(fppop()));
  }

  function fstp80() {
    return fppop();
  }

  function fstpst(n) {
    setst(n, st(0));
    fppop();
  }

  function fmul80(d) {
    setst(0, st(0) * d);
  }

  function fmul32(v) {
    setst(0, st(0) * FromFp32(v));
  }

  function fadd80(d) {
    setst(0, st(0) + d);
  }

  function fsub80(d) {
    setst(0, st(0) - d);
  }

  function faddpst(i) {
    // FADD ST(i), ST(0) then pop ST(0)
    setst(i, st(i) + st(0));
    fppop();
  }

  function faddp80(v) {
    // FADDP - Add ST(0) to ST(1) and pop
    // Note: In x87, FADDP typically operates on ST(1), ST(0)
    // The parameter v is st(1) which we ignore, we always use index 1
    setst(1, st(1) + st(0));
    fppop();
  }

  function fsubpst(i) {
    setst(i, st(i) - st(0));
    fppop();
  }

  function fmulpst(i) {
    setst(i, st(i) * st(0));
    fppop();
  }

  function fsubrpst(i) {
    // "reverse": st(i) = st(0) - st(i)
    setst(i, st(0) - st(i));
    fppop();
  }

  function fdivrpst(i) {
    // FDIVRP ST(i), ST(0): ST(i) = ST(0)/ST(i), pop ST(0)
    setst(i, st(0) / st(i));
    fppop();
  }

  function fdivr32(v) { setst(0, FromFp32(v) / st(0)); }
  function fdivr64(v) { setst(0, FromFp64(v) / st(0)); }
  function fdivr80(v) { setst(0, v / st(0)); }
  function fdiv32(v)  { setst(0, st(0) / FromFp32(v)); }
  function fdiv64(v)  { setst(0, st(0) / FromFp64(v)); }
  function fdiv80(v)  { setst(0, st(0) / v); }  // v is a JS number from 80-bit reg
  // FDIVP ST(i), ST(0): ST(i) = ST(i)/ST(0), then pop ST(0)
  // fdivp80 called as fdivp80(st(i)) — v is the captured value of ST(i)
  function fdivp32(v) { setst(1, FromFp32(v) / st(0)); fppop(); }
  function fdivp64(v) { setst(1, FromFp64(v) / st(0)); fppop(); }
  function fdivp80(v) { setst(1, v / st(0)); fppop(); }
  function fsubrp32(v){ setst(0, FromFp32(v) - st(0)); fppop(); }
  function fsubrp64(v){ setst(0, FromFp64(v) - st(0)); fppop(); }

  function fchs() {
    setst(0, -st(0));
  }

  function emulate_fnstsw_compare(a, b) {
    let ax = 0;
    const unordered = Number.isNaN(a) || Number.isNaN(b);

    if (unordered) {
      ax |= (1 << 14); // C3
      ax |= (1 << 10); // C2
      ax |= (1 << 8);  // C0
    } else if (a < b) {
      ax |= (1 << 8);  // C0
    } else if (a === b) {
      ax |= (1 << 14); // C3
    }

    return ax;
  }

  function fcom80(v) {
    compareResult = emulate_fnstsw_compare(st(0), v);
  }

  function fcom32(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp32(v));
  }

  function fcom64(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp64(v));
  }

  function fcomp32(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp32(v));
    fppop();
  }

  function fcompst(n) {
    compareResult = emulate_fnstsw_compare(st(0), st(n));
    fppop();
  }

  function fcomst(n) {
    compareResult = emulate_fnstsw_compare(st(0), st(n));
  }

  function fcomp64(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp64(v));
    fppop();
  }

  function fcomp80(v) {
    assert(fppos >= 1);
    compareResult = emulate_fnstsw_compare(st(0), v);
    fppop();
  }

  function fnstsw() {
    // Compute parity flag from the status word as if TEST AH, mask was run.
    // PF reflects even parity of the low 8 bits of the last TEST/AND result.
    // The emitted code does: r16[ax] = fnstsw(); TEST AH, x; JP/JNP
    // We precompute parity for the full AH byte so JP/JNP checks work.
    const ah = (compareResult >> 8) & 0xff;
    let p = ah;
    p ^= p >> 4;
    p ^= p >> 2;
    p ^= p >> 1;
    flags.parity = (~p) & 1; // 1 = even parity (PF set)
    return compareResult;
  }

  function fldst(n) { fppush(st(n)); }  // FLD ST(n) — push copy of ST(n)
  function fxchst2(i, j) { const tmp = st(i); setst(i, st(j)); setst(j, tmp); }  // FXCH ST(i), ST(j)

  function fld80(d) {
    fppush(d);
  }

/*  function fxch80(ref) {
    const tmp = ref.value;
    ref.value = st(0);
    setst(0, tmp);
  }*/

  function fxchst(a, b) {
    const tmp = st(a);
    setst(a, st(b));
    setst(b, tmp);
  }

  function fnstcw()
  {
    return 0;
  }
  function fldcw()
  {
  }
  function fld1() {
    fppush(1.0);
  }
  function fldz() {
    fppush(0.0);
  }

  function fsubst(i) {
    // FSUB ST(0), ST(i) — D8 form: result always in ST(0)
    setst(0, st(0) - st(i));
  }

  function faddst(i) {
    // FADD ST(0), ST(i) — D8 form: result always in ST(0)
    setst(0, st(0) + st(i));
  }

  function faddst2(i, j) {
    // FADD ST(i), ST(j) — DC form: result in ST(i)
    setst(i, st(i) + st(j));
  }

  function fmulst(i) {
    // FMUL ST(0), ST(i) — D8 form: result always in ST(0)
    setst(0, st(0) * st(i));
  }

  function fidiv32(v) { setst(0, st(0) / (v | 0)); }
  function fidiv64(v) { setst(0, st(0) / Number(BigInt.asIntN(64, BigInt(v)))); }
  function fidivr32(v) { setst(0, (v | 0) / st(0)); }
  function fidivr64(v) { setst(0, Number(BigInt.asIntN(64, BigInt(v))) / st(0)); }
  function fsin()   { setst(0, Math.sin(st(0))); }
  function fcos()   { setst(0, Math.cos(st(0))); }
  function fptan()  { fppush(1); setst(1, Math.tan(st(1))); }  // pushes 1, then tan(x) in ST(0)
  function fpatan() { const y = fppop(); setst(0, Math.atan2(y, st(0))); }
  function fist32() { const v = (DataView.prototype.getInt32.call(new DataView(new ArrayBuffer(4)), 0) || 0); return Math.round(st(0)) & 0xffffffff; }
  function fisub32(v) { setst(0, st(0) - (v | 0)); }
  function fisub64(v) { setst(0, st(0) - Number(BigInt.asIntN(64, BigInt(v)))); }
  function fimul32(v) { setst(0, st(0) * (v | 0)); }
  function fimul64(v) { setst(0, st(0) * Number(BigInt.asIntN(64, BigInt(v)))); }
  function fabs()   { setst(0, Math.abs(st(0))); }
  function f2xm1()  { setst(0, Math.pow(2, st(0)) - 1); }
  function fscale() { setst(0, st(0) * Math.pow(2, Math.trunc(st(1)))); }
  function fyl2x()  { const x = fppop(); setst(0, st(0) * Math.log2(x)); }
  function fldpi()  { fppush(Math.PI); }
  function fldln2() { fppush(Math.LN2); }
  function fldl2t() { fppush(Math.LOG2E * Math.LN10); }  // log2(10)
  function fldl2e() { fppush(Math.LOG2E); }
  function fldlg2() { fppush(Math.LOG10E * Math.LN2); }  // log10(2)
