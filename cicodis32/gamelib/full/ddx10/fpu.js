  const fpstack = new Array(8).fill(0);
  let fptop = 0;
  let fppos = 0;
  let compareResult = 0;
  function fpdump()
  {
    let aux = [];
    for (var i=0; i<fppos; i++)
      aux.push(Math.floor(st(i)*100)/100);
    return aux.join(",");
  }
  function fppush(value) {
    if (!(fppos < 8)) {
      console.error("FPU stack overflow! fppos=" + fppos + " fptop=" + fptop + " stack=" + JSON.stringify(fpstack));
      debugger;
    }
    //assert(fppos < 8, "FPU stack overflow");
/*
    // Guard against NaN/Infinity entering the FPU stack
    if (!Number.isFinite(value)) {
      if (!fppush.hasWarned) {
        console.warn(`fppush: Non-finite values detected - clamping to 0.0 (first: ${value})`);
        fppush.hasWarned = true;
      }
      value = 0.0;
    }
*/
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
/*
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
*/
    fpstack[idx] = v;
  }

  function fild32(v) {
    fppush((v << 0)); // force int32
  }

  const _fp64Buf = new ArrayBuffer(8);
  const _fp64View = new DataView(_fp64Buf);

  function FromFp64(v) {
    _fp64View.setBigUint64(0, v, true);   // little-endian
    return _fp64View.getFloat64(0, true); // little-endian
/*
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setBigUint64(0, v, true);
    const result = dv.getFloat64(0, true);
    return result;
*/
  }
/*
    // Replace NaN and Infinity with 0 to prevent audio glitches
    if (!Number.isFinite(result)) {
      if (!FromFp64.hasWarned) {
        console.warn(`FromFp64: Non-finite values in memory detected - clamping to 0.0`);
        console.warn(`  First occurrence: ${result} from BigInt ${v}`);
        FromFp64.hasWarned = true;
      }
      return 0.0;
    }
*/

  function toFp64(d) {
    _fp64View.setFloat64(0, d, true);   // little-endian
    return _fp64View.getBigUint64(0, true);
  }
/*
  function toFp64(d) {
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setFloat64(0, d, true);
    return dv.getBigUint64(0, true);
  }
*/
/*
    // Replace NaN and Infinity with 0 before storing to prevent propagation
    if (!Number.isFinite(d)) {
      if (!toFp64.hasWarned) {
        console.warn(`toFp64: Non-finite values being stored - clamping to 0.0 (first: ${d})`);
        toFp64.hasWarned = true;
      }
      d = 0.0;
    }
*/

  function FromFp32(v) {
    const buf = new ArrayBuffer(4);
    const dv = new DataView(buf);
    dv.setUint32(0, v, true);
    const result = dv.getFloat32(0, true);
/*
    // Replace NaN and Infinity with 0 to prevent audio glitches
    if (!Number.isFinite(result)) {
      if (!FromFp32.hasWarned) {
        console.warn(`FromFp32: Non-finite values in memory detected - clamping to 0.0 (first: ${result})`);
        FromFp32.hasWarned = true;
      }
      return 0.0;
    }
*/
    return result;
  }

  function toFp32(d) {
/*
    // Replace NaN and Infinity with 0 before storing to prevent propagation
    if (!Number.isFinite(d)) {
      if (!toFp32.hasWarned) {
        console.warn(`toFp32: Non-finite values being stored - clamping to 0.0 (first: ${d})`);
        toFp32.hasWarned = true;
      }
      d = 0.0;
    }
*/
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

  function fmulst2(a, b) {
    setst(a, st(a) * st(b));
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

  function fsub64(v) {
    //console.log(`  fsub64: ST(0)=${st(0)} - mem=${FromFp64(v)} = ${st(0) - FromFp64(v)}`);
    setst(0, st(0) - FromFp64(v));
  }

  function fsubr64(v) {
    setst(0, FromFp64(v) - st(0));
  }

  function fst64() {
    //console.log(`  fst64: storing ST(0)=${st(0)} to memory as BigInt=${toFp64(st(0))}`);
    if (Math.abs(st(0)) > 1000000)
      console.log( "badA", st(0))
    return toFp64(st(0));
  }

  function fstp64() {
    if (Math.abs(st(0)) > 1000000)
      console.log( "badB", st(0))
    return toFp64(fppop());
  }

  function fstp32() {
    return toFp32(fppop());
  }

  function fst32() {
    return toFp32(st(0));
  }

  function fistp64() {
    if (Math.abs(st(0)) > 1000000)
      throw "badC"
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

//  function fadd80(d) {
//    setst(0, st(0) + d);
//  }
  function faddst2(i, j) {
    setst(i, st(i) + st(j));
  }


  function fsubst(i) {
    setst(0, st(0) - st(i));
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
    // "reverse divide": st(i) = st(0) / st(i)
    const divisor = st(i);
    const dividend = st(0);
    
    if (divisor === 0) {
      // For audio DSP, if dividing by zero, use 1.0 as safe default (common for reciprocal calculations)
      // Silent handling - division by zero in DSP often happens during initialization
      setst(i, 1.0);
    } else {
      const result = dividend / divisor;
      setst(i, result);  // setst will clamp if result is Infinity
    }
    fppop();
  }

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

  function fcomst(i) {
    compareResult = emulate_fnstsw_compare(st(0), st(i));
  }

  function fcom64(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp64(v));
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

  function fldst(i) {
    fppush(st(i));
  }

/*  function fxch80(ref) {
    const tmp = ref.value;
    ref.value = st(0);
    setst(0, tmp);
  }*/

  function fxchst2(a, b) {
/*
    const tmp = st(a);
    setst(a, st(b));
    setst(b, tmp);
*/
    a = (fptop + a) & 7;
    b = (fptop + b) & 7;
    const tmp = fpstack[a];
    fpstack[a] = fpstack[b];
    fpstack[b] = tmp;
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

  function fsubst2(i, j) {
    // FSUB ST(i), ST(j) - subtract ST(j) from ST(i) and store in ST(i)
    setst(i, st(i) - st(j));
  }

  function faddst(i) {
    // FADD ST(0), ST(i) - add ST(i) to ST(0), store in ST(0)
    setst(0, st(0) + st(i));
  }

  function fmulst(i) {
    // FMUL ST(0), ST(i) - multiply ST(0) by ST(i), store in ST(0)
    setst(0, st(0) * st(i));
  }
