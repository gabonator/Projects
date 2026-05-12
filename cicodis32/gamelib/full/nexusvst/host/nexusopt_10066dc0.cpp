#error doesn't work

static inline float f32(uint32_t addr)
{
    return memoryFGet32(ds, addr);
}
static inline void sf32(uint32_t addr, float value)
{
    memoryFSet32(ds, addr, value);
}
static void update_pair_linear(
    uint32_t state_base,
    uint32_t& io_ptr,
    uint32_t copy_src,
    uint32_t side_feedback_addr,
    float feedback_gain,
    int& count,
    float step_add,
    float bias)
{
    while (count) {
        count--;
        const float t = f32(state_base + 0x1c);
        const float input_sample = f32(io_ptr);
        io_ptr += 4;
        const float a = f32(state_base);
        const float b = f32(state_base + 0x4);
        const float err_a = b - (a * t + bias);
        sf32(state_base + 0x4, err_a);
        sf32(state_base - 0x4, f32(state_base - 0x4) - (err_a * t + bias));
        const float next_a = input_sample + err_a * feedback_gain - err_a + bias;
        sf32(state_base, next_a);
        const float c = f32(state_base + 0x10);
        const float d = f32(state_base + 0x14);
        const float err_b = d - (c * t + bias);
        sf32(state_base + 0x14, err_b);
        sf32(state_base + 0x0c, f32(state_base + 0x0c) - (err_b * t + bias));
        const float next_c = f32(side_feedback_addr)
                           + err_b * f32(0x100e74bc)
                           - err_b;
        sf32(state_base + 0x10, next_c);
        sf32(state_base + 0x18, input_sample - err_b);
        sf32(io_ptr - 4, f32(copy_src));
        sf32(state_base + 0x1c, step_add + t);
    }
}
static void update_pair_nonlinear(
    uint32_t state_base,
    uint32_t& io_ptr,
    uint32_t copy_src,
    uint32_t side_feedback_addr,
    float feedback_gain,
    float shape,
    float nonlinear_bias,
    int& count,
    float step_add,
    float bias)
{
    while (count) {
        count--;
        const float t = f32(state_base + 0x1c);
        const float input_sample = f32(io_ptr);
        io_ptr += 4;
        const float a = f32(state_base);
        const float b = f32(state_base + 0x4);
        const float err_a = b - (a * t + bias);
        sf32(state_base + 0x4, err_a);
        const float curved_a = fabsf(err_a) * shape + nonlinear_bias;
        const float correction_a = (curved_a * err_a + bias) * t + bias;
        sf32(state_base - 0x4, f32(state_base - 0x4) - correction_a);
        const float next_a = input_sample + err_a * feedback_gain - err_a + bias;
        sf32(state_base, next_a);
        const float c = f32(state_base + 0x10);
        const float d = f32(state_base + 0x14);
        const float err_b = d - (c * t + bias);
        sf32(state_base + 0x14, err_b);
        /*
            Matches the original FPU sequence:
            the non-linear scale for the second channel uses fabs(state_base + 0x4),
            which is err_a after the store above, not fabs(err_b).
        */
        const float curved_b = fabsf(f32(state_base + 0x4)) * shape + nonlinear_bias;
        const float correction_b = (curved_b * err_b + bias) * t + bias;
        sf32(state_base + 0x0c, f32(state_base + 0x0c) - correction_b);
        const float next_c = f32(side_feedback_addr)
                           + err_b * f32(0x100e74bc)
                           - err_b;
        sf32(state_base + 0x10, next_c);
        sf32(state_base + 0x18, input_sample - err_b);
        sf32(io_ptr - 4, f32(copy_src));
        sf32(state_base + 0x1c, step_add + t);
    }
}
static void update_from_input_linear(
    uint32_t state_base,
    uint32_t& io_ptr,
    uint32_t copy_src,
    int& count,
    float step_add,
    float bias)
{
    while (count) {
        count--;
        const float t = f32(state_base + 0x1c);
        const float input_sample = f32(io_ptr);
        const float base_a = f32(state_base - 0x4);
        const float delta_a = input_sample - base_a;
        io_ptr += 4;
        sf32(state_base - 0x4, base_a + delta_a * t + bias);
        const float base_b = f32(state_base + 0x0c);
        const float delta_b = delta_a - base_b;
        sf32(state_base + 0x0c, base_b + delta_b * t + bias);
        sf32(state_base, f32(io_ptr - 4) - delta_a);
        const float doubled_b = f32(state_base + 0x0c) * 2.0f;
        sf32(state_base + 0x4, doubled_b);
        sf32(state_base + 0x8, f32(io_ptr - 4) - doubled_b);
        sf32(io_ptr - 4, f32(copy_src));
        sf32(state_base + 0x1c, step_add + t);
    }
}
static void update_from_input_nonlinear(
    uint32_t state_base,
    uint32_t& io_ptr,
    uint32_t copy_src,
    float shape,
    float nonlinear_bias,
    int& count,
    float step_add,
    float bias)
{
    while (count) {
        count--;
        const float t = f32(state_base + 0x1c);
        const float input_sample = f32(io_ptr);
        const float base_a = f32(state_base - 0x4);
        const float delta_a = input_sample - base_a;
        io_ptr += 4;
        const float curved_a = fabsf(delta_a) * shape + nonlinear_bias;
        const float correction_a = (curved_a * delta_a + bias) * t + bias;
        sf32(state_base - 0x4, base_a + correction_a);
        const float base_b = f32(state_base + 0x0c);
        const float delta_b = delta_a - base_b;
        const float curved_b = fabsf(delta_b) * shape + nonlinear_bias;
        const float correction_b = (curved_b * delta_b + bias) * t + bias;
        sf32(state_base + 0x0c, base_b + correction_b);
        sf32(state_base, f32(io_ptr - 4) - delta_a);
        const float doubled_b = f32(state_base + 0x0c) * 2.0f;
        sf32(state_base + 0x4, doubled_b);
        sf32(state_base + 0x8, f32(io_ptr - 4) - doubled_b);
        sf32(io_ptr - 4, f32(copy_src));
        sf32(state_base + 0x1c, step_add + t);
    }
}
void sub_10066dc0()
{
    StackGuard _sg(16, __FUNCTION__);
    const float one = 1.0f;
    const float k_halfish      = memoryFGet32(ds, 0x100e6490);
    const float k_feedback2    = memoryFGet32(ds, 0x100e74bc);
    const float k_input_scale  = memoryFGet32(ds, 0x100e77e8);
    const float k_gain_mul     = memoryFGet32(ds, 0x103cd1c4);
    const float k_gain_add     = memoryFGet32(ds, 0x103d3918);
    const float k_initial_bias = memoryFGet32(ds, 0x103d33f0);
    const float k_shape_bias   = memoryFGet32(ds, 0x103d4538);
    esp -= 4;
    esp -= 0x1c;
    eax = memoryAGet32(ds, esp + 0x2c);
    edx = eax;
    edx = (int32_t)edx * (int32_t)0x4c;
    push32(ebx);
    push32(ebp);
    push32(esi);
    esi = (edx + ecx) + 172;
    edx = memoryAGet32(ds, ecx + 0x64);
    eax = memoryAGet32(ds, edx + eax * 4);
    edx = memoryAGet32(ds, ecx + 0x58);
    memoryASet32(ds, esp + 0x18, esi);
    push32(edi);
    memoryASet32(ds, esp + 0x14, ecx);
    memoryASet32(ds, esp + 0x10, 0);
    const float input0 = memoryFGet32(ds, edx + 0x0)
                       + memoryFGet32(ds, eax + 0x0);
    const float input1 = memoryFGet32(ds, edx + 0x4)
                       + memoryFGet32(ds, eax + 0x4);
    const float input2 = memoryFGet32(ds, edx + 0x8)
                       + memoryFGet32(ds, eax + 0x8);
    esi += 4;
    const float shaped0 = (fabsf(input0) + one - fabsf(input0 - one)) * k_halfish;
    const float shaped1 = (fabsf(input1) + one - fabsf(input1 - one)) * k_halfish;
    const float shaped2 = (fabsf(input2) + one - fabsf(input2 - one)) * k_halfish;
    memoryFSet32(ds, esp + 0x3c, shaped2);
    memoryFSet32(ds, esp + 0x18, shaped0 * shaped0);
    float feedback_gain = shaped1 * k_gain_mul;
    feedback_gain += k_gain_add;
    feedback_gain = k_feedback2 - shaped0 * feedback_gain;
    const float inv_count = (float)(int32_t)memoryAGet32(ds, esp + 0x38);
    memoryFSet32(ds, esp + 0x20, inv_count);
    float step_add = 0.0f;
    float bias = k_initial_bias;
loc_10066e79:
    eax = memoryAGet32(ds, esp + 0x30);
    const uint32_t output_index = memoryAGet32(ds, esp + 0x10);
    edi = memoryAGet32(ds, eax + output_index * 4);
    ecx = memoryAGet32(ds, esp + 0x14);
    eax = memoryAGet32(ds, ecx + 0x4cac);
    edx = (int32_t)eax < 0 ? -1 : 0;
    ecx = 3;
    idiv32(ecx);
    ebp = eax;
    const int phase = (int)edx;
    ebx = memoryAGet32(ds, esp + 0x38);
    const float scaled_input =
        (k_input_scale / memoryFGet32(ds, memoryAGet32(ds, esp + 0x14) + 0x70))
        * memoryFGet32(ds, esp + 0x18);
    const float shape_value =
        (fabsf(scaled_input) + one - fabsf(scaled_input - one)) * k_halfish
        + k_shape_bias;
    memoryFSet32(ds, esp + 0x28, shape_value);
    const float shape_delta = shape_value - k_halfish;
    const float folded = (shape_delta + fabsf(shape_delta)) * k_halfish;
    const float nonlinear_shape =
        (one - ((shape_value - folded) * 2.0f)) * shaped2;
    eax = memoryAGet32(ds, esp + 0x1c);
    if (!memoryAGet(ds, eax + 0x48)) {
        memoryASet(ds, eax + 0x48, 1);
        memoryFSet32(ds, eax + 0x44, shape_value);
        memoryFSet32(ds, eax + 0x20, shape_value);
    }
    edx = memoryAGet32(ds, esp + 0x14);
    edx = memoryAGet32(ds, edx + 0x4cac);
    eax = 0x55555556;
    imul32(edx);
    eax = edx;
    eax >>= 31;
    eax += edx;
    uint32_t side_feedback_addr = (esi + eax * 4) - 4;
    if (eax == 3)
        side_feedback_addr = esi + 4;
    const float normalized_step =
        (shape_value - memoryFGet32(ds, esi + 0x1c))
        / memoryFGet32(ds, esp + 0x20);
    const uint32_t copy_src = esi + ebp * 4 - 4;
    const uint32_t pair_copy_src = esi + ebp * 4 + 12;
    const float nonlinear_limit = memoryFGet32(ds, esp + 0x3c);
    if (phase == 0) {
        if (step_add < nonlinear_limit) {
            if (ebx) {
                const float nonlinear_bias = one - nonlinear_shape;
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_from_input_nonlinear(
                    esi,
                    io_ptr,
                    copy_src,
                    nonlinear_shape,
                    nonlinear_bias,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
        else {
            if (ebx) {
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_from_input_linear(
                    esi,
                    io_ptr,
                    copy_src,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
    }
    else if (phase == 1) {
        if (step_add < nonlinear_limit) {
            if (ebx) {
                const float nonlinear_bias = one - nonlinear_shape;
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_pair_nonlinear(
                    esi,
                    io_ptr,
                    copy_src,
                    side_feedback_addr,
                    feedback_gain,
                    nonlinear_shape,
                    nonlinear_bias,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
        else {
            if (ebx) {
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_pair_linear(
                    esi,
                    io_ptr,
                    copy_src,
                    side_feedback_addr,
                    feedback_gain,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
    }
    else if (phase == 2) {
        if (step_add < nonlinear_limit) {
            if (ebx) {
                const float nonlinear_bias = one - nonlinear_shape;
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_pair_nonlinear(
                    esi,
                    io_ptr,
                    pair_copy_src,
                    side_feedback_addr,
                    feedback_gain,
                    nonlinear_shape,
                    nonlinear_bias,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
        else {
            if (ebx) {
                uint32_t io_ptr = (uint32_t)edi;
                int count = (int)ebx;
                update_pair_linear(
                    esi,
                    io_ptr,
                    pair_copy_src,
                    side_feedback_addr,
                    feedback_gain,
                    count,
                    step_add,
                    bias);
                edi = io_ptr;
                ebx = count;
            }
        }
    }
    else {
        step_add = normalized_step;
    }
    eax = memoryAGet32(ds, esp + 0x10);
    bias = memoryFGet32(ds, esp + 0x28);
    eax++;
    memoryFSet32(ds, esi + 0x1c, bias);
    esi += 0x24;
    memoryASet32(ds, esp + 0x10, eax);
    if ((int32_t)eax < 2) {
        bias = 0.0f;
        ecx = memoryAGet32(ds, esp + 0x14);
        goto loc_10066e79;
    }
    edi = pop32();
    esi = pop32();
    ebp = pop32();
    ebx = pop32();
    esp += 0x1c;
    esp += 20;
}