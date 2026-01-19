  const fpstack = new Array(8).fill(0);
  let fptop = 0;
  let fppos = 0;
  let compareResult = 0;

  function fppush(value) {
    console.assert(fppos < 8, "FPU stack overflow");

    fptop = (fptop - 1) & 7;
    console.assert(fptop !== 0);
    fpstack[fptop] = value;

    fppos++;
  }

  function fppop() {
    console.assert(fppos > 0, "FPU stack underflow");

    const value = fpstack[fptop];
    fpstack[fptop] = 0;
    fptop = (fptop + 1) & 7;
    fppos--;

    return value;
  }

  function st(i) {
    const idx = (fptop + i) & 7;
    console.assert(idx !== 0);
    return fpstack[idx];
  }

  function setst(i, v) {
    const idx = (fptop + i) & 7;
    console.assert(idx !== 0);
    fpstack[idx] = v;
  }

  function fild32(v) {
    fppush((v << 0)); // force int32
  }

  function FromFp64(v) {
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setBigUint64(0, v, true);
    return dv.getFloat64(0, true);
  }

  function toFp64(d) {
    const buf = new ArrayBuffer(8);
    const dv = new DataView(buf);
    dv.setFloat64(0, d, true);
    return dv.getBigUint64(0, true);
  }

  function fld64(v) {
    fppush(FromFp64(v));
  }

  function fmul64(v) {
    setst(0, st(0) * FromFp64(v));
  }

  function fadd64(v) {
    setst(0, st(0) + FromFp64(v));
  }

  function fsub64(v) {
    setst(0, st(0) - FromFp64(v));
  }

  function fsubr64(v) {
    setst(0, FromFp64(v) - st(0));
  }

  function fst64() {
    return toFp64(st(0));
  }

  function fstp64() {
    return toFp64(fppop());
  }

  function fistp64() {
    return BigInt(Math.trunc(fppop()));
  }

  function fstp80() {
    return fppop();
  }

  function fmul80(d) {
    setst(0, st(0) * d);
  }

  function fadd80(d) {
    setst(0, st(0) + d);
  }

  function faddp80(ref) {
    ref.value += st(0);
    fppop();
  }

  function fsubp80(ref) {
    ref.value -= st(0);
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

  function fcom64(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp64(v));
  }

  function fcomp64(v) {
    compareResult = emulate_fnstsw_compare(st(0), FromFp64(v));
    fppop();
  }

  function fcomp80(v) {
    console.assert(fppos >= 2);
    compareResult = emulate_fnstsw_compare(st(0), v);
    fppop();
  }

  function fnstsw() {
    return compareResult;
  }

  function fld80(d) {
    fppush(d);
  }

  function fxch80(ref) {
    const tmp = ref.value;
    ref.value = st(0);
    setst(0, tmp);
  }

  function fnstcw()
  {
    return 0;
  }
  function fldcw()
  {
  }
