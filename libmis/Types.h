#ifndef LIBMIS_H_
#define LIBMIS_H_

typedef const struct _MISProfile *MISProfileRef;
typedef struct _MISProfile *MISMutableProfileRef;
typedef const struct _MISBlacklistData *MISBlacklistDataRef;

#define sys_mobiledevice     (0x3A << 26)
#define sub_mobiledevice_mis (0x02 << 14)
#define MISMakeError(err) (sys_mobiledevice | sub_mobiledevice_mis | err)

enum {
    kMISNoError = 0,
    kMISUnknownError = MISMakeError(0x01),
    kMISNotMutableError = MISMakeError(0x02),
    kMISMalformedProfileError = MISMakeError(0x03),
    kMISProfileNotSignedError = MISMakeError(0x04),
    kMISPublicKeyError = MISMakeError(0x05),
    kMISPrivateKeyError = MISMakeError(0x06),
    kMISCertificateError = MISMakeError(0x07),
    kMISSigningError = MISMakeError(0x08),
    kMISSignatureNotValidError = MISMakeError(0x09),
    kMISAllocationError = MISMakeError(0x0a),
    kMISFileError = MISMakeError(0x0b),
    kMISConnectionClosedError = MISMakeError(0x0c),
    kMISProtocolError = MISMakeError(0x0d),
    kMISUnsignedError = MISMakeError(0x0e),
    kMISUnexpectedHashError = MISMakeError(0x0f),
    kMISUnsupportedVersionError = MISMakeError(0x10),
    kMISExpiredError = MISMakeError(0x11),
    kMISUnsupportedDeviceError = MISMakeError(0x12),
    kMISUntrustedCertChainError = MISMakeError(0x13),
    kMISAdHocSignatureError = MISMakeError(0x14),
    kMISInvalidSignerError = MISMakeError(0x15),
    kMISInvalidEntitlementError = MISMakeError(0x16),
    kMISModifiedResourcesError = MISMakeError(0x17),
    kMISInvalidSignerCertError = MISMakeError(0x18),
    kMISApplicationSignatureNotValidError = MISMakeError(0x19),
    kMISProfileSignatureNotValidError = MISMakeError(0x1A),
    kMISDeviceCommunicationError = MISMakeError(0x1B),
    kMISCodeNotSignedError = MISMakeError(0x1C),
    kMISMaximumErrorValue,
};
typedef int MISError;


#endif // LIBMIS_H_
