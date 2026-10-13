/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

extern "C" {
    extern char *PDISTD__global_font_manager;
}

extern "C" void func_0044E348(char *arg0) {
    char **g = (char **)&PDISTD__global_font_manager;

    *(f32 *)(arg0 + 0x8) = (f32)(*(f32 *)(*g + 0x54) + *(f32 *)(*g + 0x30));
    *(f32 *)(arg0 + 0xC) = (f32)(*(f32 *)(*g + 0x58) + *(f32 *)(*g + 0x34));
}
