struct Rec { int w[11]; };
extern "C" void func_00431DF0(Rec *, int);
extern "C" void func_00431F88(Rec *arr, unsigned idx) {
    if (idx < 10) {
        int i = idx;
        if (i < 9) {
            do {
                arr[i] = arr[i + 1];
                i++;
            } while (i < 9);
        }
        func_00431DF0(arr + 9, i);
    }
}
