// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mLicenseRecordUnit:hObject {void* const data;mLicenseRecordUnit(void*) __asm__("func_001713D0");virtual ~mLicenseRecordUnit();};
mLicenseRecordUnit::mLicenseRecordUnit(void* value):data(value){}
