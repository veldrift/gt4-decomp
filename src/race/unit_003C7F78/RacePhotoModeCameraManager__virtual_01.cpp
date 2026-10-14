struct Obj { char pad[0xF84]; float value; };
extern "C" void func_00378100(void *, float);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(void *);
extern "C" void func_004A7890(float, float, float);
extern "C" void RacePhotoModeCameraManager__virtual_01(Obj *self, float value) {
    float matrix[16];
    if (self->value != 0.0f) {
        func_004A53F8();
        func_004A7454();
        func_00378100(self, value);
        func_004A7550(matrix);
        func_004A5400();
        float scale = matrix[5] / matrix[0];
        func_004A7890(scale, 1.0f / scale, 1.0f);
    }
    func_00378100(self, value);
}
