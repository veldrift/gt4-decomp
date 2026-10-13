/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" void mScrollable__deepCopy(void *arg0, void *arg1);
extern "C" int GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *);

extern char mListBox__tf[];
extern char hObject__tf[];

extern "C" void mListBox__deepCopy(void *arg0, void *arg1) {
    char *var_a0;
    char *temp_v0;

    mScrollable__deepCopy(arg0, arg1);
    var_a0 = 0;
    if (arg1 != 0) {
        temp_v0 = *(char **)((char *)arg1 + 4);
        var_a0 = (char *)GT4MC__FileGT4GameData__loadInstance(*(s32 *)(temp_v0 + 4), (s32)mListBox__tf, 0,
                                       (char *)arg1 + *(s16 *)temp_v0, (s32)hObject__tf, arg1);
    }
    if (var_a0 != 0) {
        *(s32 *)((char *)arg0 + 0xEC) = *(s32 *)(var_a0 + 0xEC);
        *(s32 *)((char *)arg0 + 0xF0) = *(s32 *)(var_a0 + 0xF0);
        *(f32 *)((char *)arg0 + 0xF4) = *(f32 *)(var_a0 + 0xF4);
        *(f32 *)((char *)arg0 + 0xF8) = *(f32 *)(var_a0 + 0xF8);
        *(f32 *)((char *)arg0 + 0xFC) = *(f32 *)(var_a0 + 0xFC);
        *(f32 *)((char *)arg0 + 0x100) = *(f32 *)(var_a0 + 0x100);
        *(f32 *)((char *)arg0 + 0x104) = *(f32 *)(var_a0 + 0x104);
        *(s32 *)((char *)arg0 + 0x108) = *(s32 *)(var_a0 + 0x108);
        *(s32 *)((char *)arg0 + 0x10C) = *(s32 *)(var_a0 + 0x10C);
    }
}
