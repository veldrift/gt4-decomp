struct V {
    short delta;
    short index;
    int (*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    V *vt;
    char pad68[0x1C];
    char v[0xE444 - 0x84];
    int id;
};

struct Info {
    char pad[0x1C];
    int a;
    int b;
};

extern "C" int func_00336C70(int id, Info *info);
extern "C" void CameraSys__CameraManager__initReplayDisplayEnable(int a, int b);
extern "C" void CameraSys__CameraManager__initReplayMode(int a, int b);

extern "C" void RaceLanBattle__virtual_45(Obj *o)
{
    Info info;
    int r;
    int v;
    V *e;

    r = func_00336C70(o->id, &info);
    if (r == 0)
        return;
    e = (V *)((char *)o->vt + 0xD0);
    v = e->fn((char *)o + e->delta, 0);
    CameraSys__CameraManager__initReplayDisplayEnable(v, info.a);
    CameraSys__CameraManager__initReplayMode(v, info.b);
}
