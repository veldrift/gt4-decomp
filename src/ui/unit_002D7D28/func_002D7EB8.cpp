/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0025C300(int);
extern "C" int func_002D7D28(int, int, int) throw();
extern "C" int func_002D7EB8(int a, int b, int first, int last, int count) {
start:
        if (first == last) return first;
        int middle = first;
        int half = count / 2;
        int n = half;
        while (n > 0) {
            --n;
            middle = func_0025C300(middle);
        }
        if (func_002D7D28(a, b, middle)) {
            last = middle;
            count = half;
            goto start;
        } else {
            if (middle == first) return last;
            first = middle;
            count -= half;
            goto start;
        }
}
