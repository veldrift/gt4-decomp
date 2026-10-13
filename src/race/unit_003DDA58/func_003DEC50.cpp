typedef int s32;

struct func_0044CF10_arg0 { s32 v; };

extern "C" char D_00845690[];
extern "C" char D_00845698[];
extern "C" char D_008456A0[];
extern "C" char D_008456A8[];

extern "C" char D_00621CA0[];
extern "C" char D_00621CA8[];
extern "C" char D_00621CC0[];
extern "C" char D_00621CC8[];
extern "C" char D_00621CD8[];
extern "C" char D_00621CE0[];
extern "C" char D_00621CF0[];
extern "C" char D_00621CF8[];

extern "C" char D_006A3640[];
extern "C" char D_006A3650[];
extern "C" char D_006A3660[];
extern "C" char D_006A3670[];

extern "C" void func_003DE520(void **arg0);
extern "C" void func_003DE550(void *arg0, int arg1) throw();
extern "C" void func_003DE768(void **arg0);
extern "C" void func_003DE798(void *arg0, int arg1) throw();
extern "C" void func_003DEA30(void **arg0);
extern "C" void func_003DEA60(void *arg0, int arg1) throw();
extern "C" void func_003DEBA0(void **arg0);
extern "C" void func_003DEBD0(void *arg0, int arg1) throw();
extern "C" void func_0044CF10(struct func_0044CF10_arg0 *arg0, void *arg1, void *arg2);
extern "C" void func_0044CF30(int arg0, int arg1);

extern "C" void func_003DEC50(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_003DE520((void **)D_00845690);
    if (prio == 0xFFFF && init == 1)
        func_0044CF10((struct func_0044CF10_arg0 *)D_00621CA8, D_006A3640, D_00621CA0);
    if (prio == 0xFFFF && init == 1) func_003DE768((void **)D_00845698);
    if (prio == 0xFFFF && init == 1)
        func_0044CF10((struct func_0044CF10_arg0 *)D_00621CC8, D_006A3650, D_00621CC0);
    if (prio == 0xFFFF && init == 1) func_003DEA30((void **)D_008456A0);
    if (prio == 0xFFFF && init == 1)
        func_0044CF10((struct func_0044CF10_arg0 *)D_00621CE0, D_006A3660, D_00621CD8);
    if (prio == 0xFFFF && init == 1) func_003DEBA0((void **)D_008456A8);
    if (prio == 0xFFFF && init == 1)
        func_0044CF10((struct func_0044CF10_arg0 *)D_00621CF8, D_006A3670, D_00621CF0);
    if (prio == 0xFFFF && init == 0) func_0044CF30((int)D_00621CF8, 2);
    if (prio == 0xFFFF && init == 0) func_003DEBD0(D_008456A8, 2);
    if (prio == 0xFFFF && init == 0) func_0044CF30((int)D_00621CE0, 2);
    if (prio == 0xFFFF && init == 0) func_003DEA60(D_008456A0, 2);
    if (prio == 0xFFFF && init == 0) func_0044CF30((int)D_00621CC8, 2);
    if (prio == 0xFFFF && init == 0) func_003DE798(D_00845698, 2);
    if (prio == 0xFFFF && init == 0) func_0044CF30((int)D_00621CA8, 2);
    if (prio == 0xFFFF && init == 0) func_003DE550(D_00845690, 2);
}
