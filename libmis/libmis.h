#import "../BaseTypes.h"
#import "Types.h"
#import "../Foundation/Foundation.h"

//
// - AMFI part
//
bool amfi_developer_mode_status(void);
bool amfi_developer_mode_resolved(void);

int amfi_interface_cdhash_in_trustcache(const uint8_t cdhash[], size_t cdhash_len, uint64_t *trustcache_result);
int amfi_interface_query_bootarg_state(void *state_result);
int amfi_interface_get_local_signing_private_key(void *private_key_result);
int amfi_interface_get_local_signing_public_key(void *public_key_result);
int amfi_interface_set_local_signing_public_key(void *public_key);
int amfi_interface_authorize_local_signing(void *public_key);
int amfi_launch_constraint_set_spawnattr( /* posix_spawnattr_t * */void *attr, void *data, size_t datalen);


//
// - Profile
//
Boolean MISProfileIsDEREncoded(MISProfileRef profile);
Boolean MISProfileIsMutable(MISProfileRef profile);
CFDataRef MISProfileCreateDataRepresentation(MISProfileRef profile);
CFDictionaryRef MISProfileCopyPayload(MISProfileRef profile);
CFTypeID MISProfileGetTypeID(void);
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


//
// - ProvisioningProfile
//
Boolean MISProvisioningProfileGrantsEntitlement(MISProfileRef profile, CFStringRef entitlement, CFTypeRef value);
Boolean MISProvisioningProfileHasPPQRequirement(MISProfileRef profile);
Boolean MISProvisioningProfileIncludesDevice(MISProfileRef profile, CFStringRef deviceID);
Boolean MISProvisioningProfileIncludesPlatform(MISProfileRef profile, CFStringRef platformName);
Boolean MISProvisioningProfileIsAppleInternalProfile(MISProfileRef profile);
Boolean MISProvisioningProfileIsForBetaDeploymen(MISProfileRef profile);
Boolean MISProvisioningProfileIsForBetaDeployment(MISProfileRef profile);
Boolean MISProvisioningProfileIsForLocalProvisioning(MISProfileRef profile);
Boolean MISProvisioningProfileProvisionsAllDevices(MISProfileRef profile);
CFArrayRef MISProvisioningProfileCopyApplicationIdentifierPrefixes(MISProfileRef profile);
CFArrayRef MISProvisioningProfileGetDeveloperCertificates(MISProfileRef profile);
CFArrayRef MISProvisioningProfileGetDeveloperCertificatesHashes(MISProfileRef profile);
CFArrayRef MISProvisioningProfileGetProvisionedDevices(MISProfileRef profile);
CFArrayRef MISProvisioningProfileGetProvisioningCDHashes(MISProfileRef profile);
CFDateRef MISProvisioningProfileGetCreationDate(MISProfileRef profile);
CFDateRef MISProvisioningProfileGetExpirationDate(MISProfileRef profile);
CFDictionaryRef MISProvisioningProfileGetEntitlements(MISProfileRef profile);
CFStringRef MISProvisioningProfileGetName(MISProfileRef profile);
CFStringRef MISProvisioningProfileGetTeamIdentifier(MISProfileRef profile);
CFStringRef MISProvisioningProfileGetUUID(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetEmbeddedDER(MISProfileRef profile);
CFTypeRef MISProvisioningProfileGetRawEntitlements(MISProfileRef profile);
MISError MISProvisioningProfileAddDeveloperCertificate(MISMutableProfileRef profile, CFDataRef cert);
MISError MISProvisioningProfileAddEntitlement(MISMutableProfileRef profile, CFStringRef entitlement, CFTypeRef value);
MISError MISProvisioningProfileAddProvisionedDevice(MISMutableProfileRef profile, CFStringRef deviceID);
MISError MISProvisioningProfileCheckValidity(MISProfileRef profile, CFStringRef deviceID, CFDateRef date);
MISError MISProvisioningProfileSetApplicationIdentifierPrefixes(MISMutableProfileRef profile, CFArrayRef prefixes);
MISError MISProvisioningProfileSetDeveloperCertificates(MISMutableProfileRef profile, CFArrayRef certs);
MISError MISProvisioningProfileSetName(MISMutableProfileRef profile, CFStringRef name);
MISError MISProvisioningProfileSetProvisionsAllDevices(MISMutableProfileRef profile);
MISError MISProvisioningProfileSetTimeToLive(MISMutableProfileRef profile, int days);
MISError MISProvisioningProfileValidateSignature(MISProfileRef profile);
MISMutableProfileRef MISProfileCreateForProvisioning(CFAllocatorRef allocator);
MISMutableProfileRef MISProvisioningProfileCreateMutableCopy(CFAllocatorRef alloc, MISProfileRef profile);
int MISProvisioningProfileGetVersion(MISProfileRef profile);


//
// - Generic functions
//
Boolean MISAppApprovalState(CFStringRef path, CFDictionaryRef options);
Boolean MISArrayAllowsEntitlementValue(CFArrayRef entitlements, CFStringRef value);
Boolean MISBlacklistOverriddenByUser(CFDataRef cdhash, int someOptions);
Boolean MISEntitlementDictionaryAllowsEntitlementValue(CFDictionaryRef entitlements, CFStringRef entitlement, CFTypeRef value);
Boolean MISExistsIndeterminateApps(CFDataRef data, CFTypeRef arg2, Boolean *result);
Boolean MISUPPTrusted(CFStringRef upp);
CFStringRef MISCopyErrorStringForErrorCode(MISError error);
CFStringRef MISCopyErrorStringForErrorCodeUnlocalized(MISError error);
CFTypeRef CopyMockUDID(void);
MISError MISCopyInstalledProvisioningProfiles(CFArrayRef *profiles);
MISError MISCopyProvisioningProfile(CFStringRef profileName, MISProfileRef *profile);
MISError MISCopyProvisioningProfileWithConnection(CFStringRef profileName, MISProfileRef *profile, xpc_connection_t connection);
MISError MISEnumerateInstalledProvisioningProfiles(int flags, void *enumBlock);
MISError MISEnumerateMatchingProfiles(CFDataRef certificate, CFArrayRef predicates, void *enumBlock);
MISError MISEnumerateMatchingProfilesUnauthoritative(CFDataRef certificate);
MISError MISInstallProvisioningProfile(MISProfileRef profile);
MISError MISPing(char **reply);
MISError MISRemoveProvisioningProfile(MISProfileRef profile);
MISError MISValidateSignature(CFStringRef path, CFDictionaryRef options);
MISError MISValidateSignatureAndCopyInfo(CFStringRef path, CFDictionaryRef options, CFDictionaryRef *info);
MISError MISValidateSignatureAndCopyInfoWithProgress(CFStringRef path, CFDictionaryRef options, CFDictionaryRef *info, void *progressCallback);
MISError MISValidationCopySignatureVersion(CFStringRef path, CFTypeRef signatureVersion);
void MISEnumerateTrustedUPPs(void *enumBlock);
void MISSetUPPTrust(CFStringRef upp, Boolean trust);

// idk what the haty is. It often refers to 0x1a fallback which can't be CommonCrypto "hash type". Or it is?
// In XPC it is really called haty
MISError MISQueryBlacklistForBundle(CFStringRef path, UInt64 someOptions, Boolean overridenFlag, void **result, CFDataRef *cdhash, UInt64 *haty);
MISError MISQueryBlacklistForCdHash(CFDataRef cdhash, UInt64 haty, Boolean overridenFlag, void **result);
MISError MISBlacklistSetOverride(CFDataRef cdhash, UInt64 haty, Boolean override);
