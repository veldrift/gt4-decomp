#include "spr.h"
extern "C" void func_004A4910(float);
extern "C" void func_0049FE28() throw();
extern "C" void func_004A3308(char *) throw();
extern "C" void func_004A3910(char *) throw();
extern "C" void func_004A3498(char *, int, float) throw();
extern "C" void func_004A3620(char *, char *, char *, int, int, int, float) throw();
extern "C" void func_004A3998(unsigned int arg0, float fparg0) {
    char *p = (char *)spr_base();
    char *temp_s0;
    char *temp_s0_2;
    char *temp_s0_3;
    char *temp_s0_4;
    char *temp_s0_5;
    char *temp_s1;
    char *temp_s1_2;
    char *temp_s1_3;
    char *temp_s1_4;
    char *temp_s1_5;

    func_004A4910(fparg0);
    func_0049FE28();
    switch (arg0) {                                 /* irregular */
    case 0:
        func_004A3308(p);
        if (!(fparg0 > 0.0f)) {
            func_004A3620(p, p + 0x24C, p + 0x260, 0x62, 0, 0, -fparg0);
            return;
        }
        func_004A3620(p, p + 0x24C, p + 0x260, 0x68, 0, 0, fparg0);
        return;
    case 1:
        func_004A3308(p);
        func_004A3620(p, p + 0x24C, p + 0x260, 0xA8, 0, 0, fparg0);
        return;
    case 2:
        func_004A3308(p);
        if (!(fparg0 > 0.0f)) {
            func_004A3498(p, 0x62, -fparg0);
            return;
        }
        func_004A3498(p, 0x68, fparg0);
        return;
    case 3:
        func_004A3308(p);
        func_004A3498(p, 0xA9, fparg0);
        return;
    case 4:
        func_004A3910(p);
        func_004A3620(p, p + 0x260, p + 0x24C, 0xA8, 0, 0, fparg0);
        return;
    case 5:
        func_004A3910(p);
        func_004A3620(p, p + 0x260, p + 0x24C, 0x64, 0, 0, fparg0);
        return;
    case 6:
        func_004A3308(p);
        func_004A3620(p, p + 0x24C, p + 0x260, 0x64, 0, 0, fparg0);
        return;
    case 7:
        func_004A3308(p);
        func_004A3620(p, p + 0x24C, p + 0x260, 0x44, 0, 0, fparg0);
        return;
    case 8:
        func_004A3308(p);
        if (*(signed char *)(p+0x2c0) == 0) {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 16, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 16, 16, 0.5f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 0, 0, fparg0);
            return;
        }
        else if (*(unsigned char *)(p+0x2c1) != 0) {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 0, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 0, 16, 0.5f);
            return;
        }
        else {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 0, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, -16, 0, 0.5f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 0, 16, fparg0);
            return;
        }
    case 9:
        func_004A3308(p);
        if (*(signed char *)(p+0x2c0) == 0) {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 0, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, -16, 0, 0.5f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 0, 16, fparg0);
            return;
        }
        else if (*(unsigned char *)(p+0x2c1) != 0) {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 0, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 16, 16, 0.5f);
            return;
        }
        else {
            func_004A3620(p, p+0x24c, p+0x260, 168, 0, 16, 1.0f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 16, 16, 0.5f);
            func_004A3620(p, p+0x24c, p+0x260, 100, 0, 0, fparg0);
            return;
        }
    }
}
