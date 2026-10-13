typedef int s32;
typedef unsigned char u8;
typedef float f32;

struct func_00345A50_temp {
    char pad0[0x1];
    u8 unk1;
};

struct func_00345A50_elem {
    char pad0[0x28];
    f32 unk28;
    f32 unk2C;
    char pad30[0x10];
    f32 unk40;
    char pad44[0xA8];
};

extern "C" void *func_00359538(void *);

extern "C" void func_00345A50(void *arg0) {
    s32 var_a1;
    struct func_00345A50_temp *temp_v0;
    struct func_00345A50_elem *var_a0;
    f32 temp_f0;
    f32 temp_f1;
    f32 sum;
    f32 len;
    f32 var_f0;

    temp_v0 = (struct func_00345A50_temp *)func_00359538(arg0);
    var_a1 = 0;
    if (temp_v0->unk1 != 0) {
        var_a0 = (struct func_00345A50_elem *)((char *)arg0 + 0x164);
        do {
            temp_f0 = var_a0->unk28;
            temp_f1 = var_a0->unk2C;
            sum = temp_f0 * temp_f0 + temp_f1 * temp_f1;
            __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(sum));
            var_f0 = len * 0x1.47AE16p-6f;
            if (var_f0 > 1.0f) {
                var_f0 = 1.0f;
            }
            var_a0->unk40 = var_f0;
            var_a1 += 1;
            var_a0++;
        } while (var_a1 < (s32)temp_v0->unk1);
    }
}
