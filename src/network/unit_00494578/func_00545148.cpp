extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" int func_00544A18(int *, int) throw();
extern "C" int func_00544870(int *) throw();
extern "C" int func_005448B8(const int *) throw();
extern "C" int func_00545C58(int *, int);
extern "C" int func_00545558(int *, const int *, int *, const int *);
extern "C" int func_00546668(int *, int *, int *, const int *);
extern "C" int func_00545148(const int *a, const int *b) {
    int result[32];
    int temp[32];
    func_005A4724(temp, a, 128);
    func_00544A18(temp, 1);
    if (func_00544870(temp) == 0) goto fail;
    func_00545C58(temp, 1);
    func_00545558(result, b, temp, a);
    if (func_005448B8(result) != 0) goto fail;
    func_00546668(result, result, result, a);
    if (func_005448B8(result) != 0) return 1;
fail:
    return 0;
}
