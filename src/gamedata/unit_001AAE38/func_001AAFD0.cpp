typedef int s32;

extern "C" s32 func_001C72B8(void *);
extern "C" s32 func_001C70A8(void *);
extern "C" void *func_001C71B8(void *);
extern "C" float func_00579398(float);
extern "C" void func_001C7358(void *, void *, s32, s32, float, float);
extern "C" s32 func_001C7110(void *);
extern "C" void func_001C73C8(void *);
extern "C" void func_001C7438(void *);
extern "C" s32 func_001C7328(void *);
extern "C" void func_001C7178(void *);
extern s32 D_00622F4C;

extern "C" void func_001AAFD0(void *arg0) {
    char *face = (char *)arg0 + 0x1E9C;
    char *resource = (char *)arg0 + 0xBC;
    if (func_001C72B8(face)) {
        if (func_001C70A8(resource)) {
            void *entry = func_001C71B8(resource);
            if (entry != 0) {
                s32 flip = 0;
                if (func_00579398(1.0f) < 0.5f) flip = 1;
                char *data = (char *)D_00622F4C + 0x38CB0;
                s32 extra = *(s32 *)(data + 0x1170);
                float low = (float)*(s32 *)(data + 0x1174);
                float high = (float)*(s32 *)(data + 0x1180);
                if (low < 3.0f) low = 3.0f;
                if (low > 60.0f) low = 60.0f;
                func_001C7358(face, (char *)entry + 4, flip, extra, low, high);
            }
        } else if (*(s32 *)(resource + 8) != 0 && func_001C7110(resource)) {
            func_001C73C8(face);
        }
    }
    func_001C7438(face);
    if (func_001C7328(face)) func_001C7178(resource);
}
