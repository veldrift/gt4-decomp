// The status member has independently observed discarded reads after native writes.
// The float quality member is ordinary storage; the comparison is an inline integer getter.
struct mPhotoRenderFace {
    char unknown_00[0xB4];
    char unknown_b4[4];
    int field_b8;
    char unknown_bc[8];
    char field_c4[0x28];
    void *field_ec;
    int field_f0;
    float field_f4;
    float field_f8;
    float field_fc;
};
struct RacePhotoMode_00197798 { char unknown_00[0x1E634]; volatile int field_1e634; char unknown_1e638[0x10]; float field_1e648;
    int format_from_field_1e648() const { return field_1e648 < 1.0f ? 1 : 0; }
};
struct PhotoData_00197788 { char unknown_00[0x11C]; int field_11c; };
struct Config_00622F4C { char unknown_00[0x39DBC]; int field_39dbc; };
extern "C" void mTextFace__virtual_67(void *, void *);
extern "C" RacePhotoMode_00197798 *func_00197798(void *);
extern "C" PhotoData_00197788 *func_00197788(void *);
extern "C" int func_00197808(int);
extern "C" Config_00622F4C *D_00622F4C;
extern "C" void mPhotoRenderFace__virtual_67(mPhotoRenderFace *self, void *photo) {
    mTextFace__virtual_67(self, photo);
    self->field_b8 = 0;
    RacePhotoMode_00197798 *stream = func_00197798(photo);
    if (stream != 0) { stream->field_1e634 = 1; (void)stream->field_1e634; }
    PhotoData_00197788 *image = func_00197788(photo);
    void *fallback = (char *)self + 0xC4;
    if (image != 0) {
        self->field_ec = (char *)func_00197788(photo) + 0x1C;
        int format;
        if (stream != 0) format = stream->format_from_field_1e648();
        else format = *(int *)((char *)func_00197788(photo) + 0x18);
        self->field_f0 = format;
        image->field_11c = func_00197808(D_00622F4C->field_39dbc);
    } else {
        self->field_ec = fallback;
    }
    self->field_f8 = 0.0f;
    self->field_fc = 1.0f;
    self->field_f4 = 0.0f;
}