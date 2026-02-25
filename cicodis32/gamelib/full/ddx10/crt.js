function allocate(size)
{
    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    allocatorPtr += size;
    return ptr;
}

function sub_1001ef91()
{
    const size = stack32(0);

    let ptr = allocatorPtr;
    console.log("Alloc 0x" + size.toString(16) + " @ 0x" + ptr.toString(16))
    allocatorPtr += size;
    r32[eax] = ptr;  
}


function sub_10020d33()
{
  // eh_vector_constructor_iterator
  const ptr = stack32(0);
  const elementSize = stack32(1);
  const elementCount = stack32(2);
  const ctorFunc = stack32(3);
  const dtorFunc = stack32(4);
  console.log("eh_vector_constructor_iterator", ptr.toString(16), elementSize, elementCount,
    ctorFunc.toString(16), dtorFunc.toString(16))
  for (let i=0; i<elementCount; i++)
  {
    r32[ecx] = ptr + elementSize*i;
    switch (ctorFunc)
    {
      case 0x100105f0: sub_100105f0(); break;
      case 0x1000c040: sub_1000c040(); break;
      default:
        console.assert("no indirect ctor")
    }
 }
}

function readstring(ptr)
{
    let str = "";
    for (let i=0; i<200; i++)
    {
      const c = memoryAGet(0, ptr+i);
      if (c == 0)
        break;
      str += String.fromCharCode(c);
    }
    return str;
}

function sub_10020480()
{
  // strncpy
  const dst = stack32(0);
  const src = stack32(1);
  const len = stack32(2);
  console.log(readstring(src));
  for (let i=0; i<len; i++)
  {
    const c = memoryAGet(0, src+i);
    memoryASet(0, dst+i, c);
    if (!c)
      break;
  }
}

function sub_10035bb0()
{
  // trunc
  const v = FromFp64(memoryAGet(0, r32[esp]));
  console.log("trunc", v, Math.trunc(v));
  v = Math.trunc(v);
  fppush(v);
}