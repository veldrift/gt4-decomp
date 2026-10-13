struct Ret {
    char pad[0x16C];
    unsigned char b;
};

struct CamBase {
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual Ret *v026(void *);
};

struct DevCam : CamBase {
    char pad[0x9B8];
    void *m9BC;
};

extern "C" unsigned char DevelopCamera__virtual_40(DevCam *arg0) {
    Ret *r = arg0->v026(arg0->m9BC);
    if (r != 0) {
        return r->b;
    }
    return (unsigned char)(unsigned long)r;
}
