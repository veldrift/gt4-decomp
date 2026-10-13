// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mLicenseRecord:hObject {void* const data;mLicenseRecord(void*) __asm__("func_00172968");virtual ~mLicenseRecord();};
mLicenseRecord::mLicenseRecord(void* value):data(value){}
