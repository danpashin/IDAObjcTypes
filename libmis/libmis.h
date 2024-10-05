#import "../BaseTypes.h"
#import "Types.h"
#import "../Foundation/Foundation.h"

CFStringRef MISCopyErrorStringForErrorCode(MISError error);

CFTypeID MISProfileGetTypeID(void);

CFDataRef MISProfileCreateDataRepresentation(MISProfileRef profile);
CFDictionaryRef MISProfileCopyPayload(MISProfileRef profile);
CFTypeRef MISProfileGetValue(MISProfileRef profile, CFStringRef key);
MISError MISProfileCopySignerSubjectSummary(MISProfileRef profile, CFStringRef *summary);
MISError MISProfileRemoveValue(MISMutableProfileRef profile, CFStringRef key);
MISError MISProfileSetPayload(MISMutableProfileRef profile, CFDictionaryRef payload);
MISError MISProfileSetValue(MISMutableProfileRef profile, CFStringRef key, CFTypeRef value);
MISError MISProfileSignWithKeyAndCertificates(MISMutableProfileRef profile, CFTypeRef key, CFArrayRef certs);
MISError MISProfileSignWithRSACallBack(MISMutableProfileRef profile, int (*rsaCallback)(CFDataRef, CFDataRef *), CFArrayRef certs);
MISError MISProfileValidateSignature(MISProfileRef profile);
MISError MISProfileValidateSignatureWithAnchors(MISProfileRef profile, CFArrayRef anchors);
MISError MISProfileValidateSignatureWithAnchorsAndPolicy(MISProfileRef profile, CFArrayRef anchors, int policyType);
MISError MISProfileWriteToFile(MISProfileRef profile, CFStringRef file);
MISMutableProfileRef MISProfileCreate(CFAllocatorRef allocator);
MISMutableProfileRef MISProfileCreateMutableCopy(CFAllocatorRef allocator, MISProfileRef profile);
MISProfileRef MISProfileCreateWithData(CFAllocatorRef allocator, CFDataRef data);
MISProfileRef MISProfileCreateWithFile(CFAllocatorRef allocator, CFStringRef file);
bool MISProfileIsMutable(MISProfileRef profile);

bool MISExistsIndeterminateApps(void);

CFArrayRef MISProvisioningProfileCopyApplicationIdentifierPrefixes(MISProfileRef profile);
CFStringRef MISProvisioningProfileGetName(MISProfileRef profile);
CFStringRef MISProvisioningProfileGetTeamIdentifier(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetCreationDate(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetDeveloperCertificates(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetDeveloperCertificatesHashes(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetExpirationDate(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetProvisionedDevices(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetRawEntitlements(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetUUID(MISProfileRef profile);
NSInteger MISProvisioningProfileGetVersion(MISProfileRef profile);
bool MISProvisioningProfileGrantsEntitlement(MISProfileRef profile, CFStringRef entitlement);
bool MISProvisioningProfileHasPPQRequirement(MISProfileRef profile);
bool MISProvisioningProfileIncludesPlatform(MISProfileRef profile, CFStringRef platformName);
bool MISProvisioningProfileIsAppleInternalProfile(MISProfileRef profile);
bool MISProvisioningProfileIsForLocalProvisioning(MISProfileRef profile);
bool MISProvisioningProfileProvisionsAllDevices(MISProfileRef profile);

MISError MISQueryBlacklistForBundle(CFStringRef path, bool flag, bool overridenFlag, void **result, MISBlacklistDataRef *blacklist, NSUInteger *haty);
MISError MISQueryBlacklistForCdHash(CFDataRef, bool flag, bool overridenFlag, void **result);

MISError MISBlacklistSetOverride(MISBlacklistDataRef blacklist, NSUInteger haty, bool override);

