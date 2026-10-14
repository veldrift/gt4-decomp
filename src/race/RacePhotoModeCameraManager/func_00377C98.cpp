typedef int s32;

extern char D_0067A250[];

extern "C" s32 func_0036FA88(void *);
extern "C" void *func_003721D8(void *);
extern "C" s32 RacePhotoModeCameraManager__virtual_20(void *, s32);
extern "C" void func_00384358(void *);
extern "C" void func_00384510(void *);
extern "C" s32 exception__structor_0(s32);

static inline s32 make_camera() {
    s32 p = exception__structor_0(0x200);
    func_00384358((void *)p);
    return p;
}
static inline s32 make_other() {
    s32 p = exception__structor_0(0x1C0);
    func_00384510((void *)p);
    return p;
}
extern "C" s32 func_00377C98(void *arg0) {
    char *p2 = (char *)arg0 + 0xC40;
    s32 s0;
    func_003721D8(arg0);
    *(char **)arg0 = D_0067A250;
    func_0036FA88((char *)arg0 + 0xE28);
    s0 = make_camera();
    *(s32 *)p2 = s0;
    s0 = make_other();
    *(s32 *)((char *)arg0 + 0xC44) = s0;
    return RacePhotoModeCameraManager__virtual_20(arg0, 0);
}
