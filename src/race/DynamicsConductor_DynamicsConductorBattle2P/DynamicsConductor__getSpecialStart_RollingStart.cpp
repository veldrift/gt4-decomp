/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
int DynamicsConductor__getSpecialStart_Rolling_ByBalance(void *, int, int *, int *, int *) throw();
int DynamicsConductor__getSpecialStart_Rolling_ByCourse(void *, int, int *, int *, int *) throw();
int DynamicsConductor__getCourseType(void *) throw();
float func_0046AB80(void *, float, float);
void DynamicsConductor__getSpecialStart_RollingStart(void *obj, int id, int *kind, int *x, int *y) {
    if (DynamicsConductor__getSpecialStart_Rolling_ByBalance(obj, id, kind, x, y) == 0 &&
        DynamicsConductor__getSpecialStart_Rolling_ByCourse(obj, id, kind, x, y) == 0) {
        float distance = 400.0f;
        *kind = 4;
        int type = DynamicsConductor__getCourseType(obj);
        float limit = 350.0f;
        switch (type) {
        case 0: case 1: break;
        case 2: case 3:
            distance = 300.0f;
            limit = 200.0f;
            break;
        default: break;
        }
        *x = (int)func_0046AB80((void *)(0xDA50 + (int)obj), -distance, limit) - 5;
    }
}
}
