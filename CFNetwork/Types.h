#ifndef CFNETWORK_H_
#define CFNETWORK_H_

typedef const struct _CFCachedURLResponse *CFCachedURLResponseRef;
typedef const struct _CFHTTPCookie *CFHTTPCookieRef;
typedef const struct _CFHTTPCookieStorage *CFHTTPCookieStorageRef;
typedef const struct _CFURLAuthChallenge *CFURLAuthChallengeRef;
typedef const struct _CFURLCache *CFURLCacheRef;
typedef const struct _CFURLConnection *CFURLConnectionRef;
typedef const struct _CFURLCredential *CFURLCredentialRef;
typedef const struct _CFURLCredentialStorage *CFURLCredentialStorageRef;
typedef const struct _CFURLDownload *CFURLDownloadRef;
typedef const struct _CFURLProtectionSpace *CFURLProtectionSpaceRef;
typedef const struct _CFURLProtocol *CFURLProtocolRef;
typedef const struct _CFURLRequest *CFURLRequestRef;
typedef const struct _CFURLResponse *CFURLResponseRef;
typedef const struct _CFURLStorageSession *CFURLStorageSessionRef;
typedef const struct _CFNetServiceBrowser *CFNetServiceBrowserRef;

typedef struct _CFMutableURLRequest *CFMutableURLRequestRef;

typedef struct {
    CFIndex version;
    const void *clientInfo;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLConnectionClient;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLConnectionContext;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLConnectionHandlerContext;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLDownloadClient;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLProtocolClient;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFNetServiceClientContext;
typedef struct {
    CFIndex version;
    const void *info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
} CFURLProtocolImplementation;

typedef CFIndex CFURLRequestPriority;

typedef struct {
    CFIndex domain;
    SInt32 error;
} CFStreamError;

PS_ENUM(SInt32, CFURLResponseSource) {
    kCFURLResponseSourceNetwork = 0,
    kCFURLResponseSourceCache = 1,
};

PS_ENUM(SInt32, CFURLCacheStoragePolicy) {
    kCFURLCacheStorageAllowed = 0,
    kCFURLCacheStorageAllowedInMemoryOnly = 1,
    kCFURLCacheStorageNotAllowed = 2,
};

PS_ENUM(SInt32, CFURLRequestCachePolicy) {
    kCFURLRequestCachePolicyProtocolDefault = 0,
    kCFURLRequestCachePolicyReloadIgnoringCache = 1,
    kCFURLRequestCachePolicyReturnCacheDataElseLoad = 2,
    kCFURLRequestCachePolicyReturnCacheDataDontLoad = 3,
};

PS_ENUM(SInt32, CFHTTPCookieStorageAcceptPolicy) {
  kCFHTTPCookieStorageAcceptPolicyAlways = 0,
  kCFHTTPCookieStorageAcceptPolicyNever = 1,
  kCFHTTPCookieStorageAcceptPolicyOnlyFromMainDocumentDomain = 2
};

PS_ENUM(SInt32, CFURLRequestNetworkServiceType) {
	kCFURLRequestNetworkServiceTypeDefault = 0,
	kCFURLRequestNetworkServiceTypeVoIP = 1,
	kCFURLRequestNetworkServiceTypeVideo = 2,
	kCFURLRequestNetworkServiceTypeBackground = 3,
	kCFURLRequestNetworkServiceTypeVoice = 4
};

PS_ENUM(SInt32, CFURLProtectionSpaceServerType) {
    kCFURLProtectionSpaceServerHTTP,
    kCFURLProtectionSpaceServerHTTPS,
    kCFURLProtectionSpaceServerFTP,
    kCFURLProtectionSpaceProxyHTTP,
    kCFURLProtectionSpaceProxyHTTPS,
    kCFURLProtectionSpaceProxyFTP,
    kCFURLProtectionSpaceProxySOCKS,
};

PS_ENUM(SInt32, CFURLProtectionSpaceAuthenticationSchemeType) {
    kCFURLProtectionSpaceAuthenticationSchemeDefault,
    kCFURLProtectionSpaceAuthenticationSchemeHTTPBasic,
    kCFURLProtectionSpaceAuthenticationSchemeHTTPDigest,
    kCFURLProtectionSpaceAuthenticationSchemeHTMLForm,
    kCFURLProtectionSpaceAuthenticationSchemeNTLM,
    kCFURLProtectionSpaceAuthenticationSchemeNegotiate,
    kCFURLProtectionSpaceAuthenticationSchemeServerTrustEvaluationRequested,
    kCFURLProtectionSpaceAuthenticationSchemeClientCertificateRequested,
};

PS_ENUM(SInt32, CFURLCredentialPersistence) {
  kCFURLCredentialPersistenceNone = 1,
  kCFURLCredentialPersistenceForSession = 2,
  kCFURLCredentialPersistencePermanent = 3
};

typedef void (*CFHTTPCookieStorageChangedProcPtr)(CFHTTPCookieStorageRef storage, void*);
typedef void (*CFNetServiceBrowserClientCallBack)(CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError *error, void *info);

#endif // CFNETWORK_H_
