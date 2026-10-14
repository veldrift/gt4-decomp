/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result { int words[5]; };
extern "C" Result func_004AE6B0(int);
extern "C" int func_00575E60(int, int);
extern "C" int func_004AE268(Result *, int, int, int, int);
extern "C" int func_0044FFC0(int arg0, int arg1) {
    Result result = func_004AE6B0(arg1);
    int size = (result.words[2] + 63) & ~63;
    int buffer = func_00575E60(64, size);
    func_004AE268(&result, arg1, buffer, size, 1);
    return result.words[0] == 0 ? buffer : 0;
}
