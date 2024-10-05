#import "../BaseTypes.h"
#import "Types.h"
#import "../CoreFoundation/Types.h"
#import "../Foundation/Foundation.h"

// CFURLResponseConnectionDidFallback
// CFURLResponseCopyPeerAddress
// _CFURLRequestSetShouldPipelineNonIdempotentHTTP
// _CFURLRequestSetShouldSkipPipelineProbe
// _CFURLResponseCreateArchiveList
// _CFURLCachePersistMemoryToDiskNow
// _CFNetworkErrorGetLocalizedFailureReason
// _CFURLCredentialCreateArchive
// _CFURLCredentialCreateFromArchive
// _CFURLCredentialCreateOAuth2
// _CFURLCredentialCreateOAuth1

//
// - Stream
//
CFStreamError CFReadStreamGetError(CFReadStreamRef stream);
CFStreamError CFWriteStreamGetError(CFWriteStreamRef stream);

//
// - CFNet
//
void _CFNetworkSetHSTSStoragePath(CFStringRef path);
Boolean _CFNetworkIsKnownHSTSHostWithSession(CFURLRef url, CFURLStorageSessionRef session);

//
// - URL
//
Boolean CFURLDestroyResource(CFURLRef url, SInt32 *errorCode);


//
// - CFURLProtocol
//
CFCachedURLResponseRef CFURLProtocolGetCachedResponse(CFURLProtocolRef prot);
CFURLProtocolClient *CFURLProtocolGetClient(CFURLProtocolRef prot);
CFURLRequestRef CFURLProtocolGetRequest(CFURLProtocolRef prot);
void CFURLProtocolRegisterImplementation(CFURLProtocolImplementation *impl);
void CFURLProtocolUnregisterImplementation(CFURLProtocolImplementation *impl);
void _CFURLProtocolSendCacheResponseIsValidCallback(CFURLProtocolRef prot, CFCachedURLResponseRef cachedResponse);
void _CFURLProtocolSendDidFailCallback(CFURLProtocolRef prot, CFErrorRef err);
void _CFURLProtocolSendDidFinishLoadingCallback(CFURLProtocolRef prot);
void _CFURLProtocolSendDidLoadDataCallback(CFURLProtocolRef prot, CFDataRef data, SInt64 originalEncodedLength);
void _CFURLProtocolSendDidReceiveResponseCallback(CFURLProtocolRef prot, CFURLResponseRef response);
void _CFURLProtocolSendWasRedirectedCallback(CFURLProtocolRef prot, CFURLRequestRef newRequest, CFURLResponseRef redirectResponse);


//
// - HTTPMessage
//
Boolean CFHTTPMessageIsHeaderComplete(CFHTTPMessageRef message);
Boolean CFHTTPMessageIsRequest(CFHTTPMessageRef message);
CFDataRef CFHTTPMessageCopyBody(CFHTTPMessageRef message);
CFDataRef CFHTTPMessageCopySerializedMessage(CFHTTPMessageRef message);
CFDictionaryRef CFHTTPMessageCopyAllHeaderFields(CFHTTPMessageRef message);
CFHTTPMessageRef CFHTTPMessageCreateCopy(CFAllocatorRef alloc, CFHTTPMessageRef message);
CFHTTPMessageRef CFHTTPMessageCreateEmpty(CFAllocatorRef alloc, Boolean isRequest);
CFHTTPMessageRef CFHTTPMessageCreateRequest(CFAllocatorRef alloc, CFStringRef requestMethod, CFURLRef url, CFStringRef httpVersion);
CFHTTPMessageRef CFHTTPMessageCreateResponse(CFAllocatorRef alloc, CFIndex statusCode, CFStringRef statusDescription, CFStringRef httpVersion);
CFStringRef CFHTTPMessageCopyHeaderFieldValue(CFHTTPMessageRef message, CFStringRef header);
CFStringRef CFHTTPMessageCopyResponseStatusLine(CFHTTPMessageRef response);
CFStringRef CFHTTPMessageCopyVersion(CFHTTPMessageRef message);
CFTypeID CFHTTPMessageGetTypeID(void);
CFURLRef CFHTTPMessageCopyRequestURL(CFHTTPMessageRef req);
UInt32 CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef response);
void CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData);
void CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField, CFStringRef value);
void _CFHTTPMessageSetResponseURL(CFHTTPMessageRef response, CFURLRef url);


//
// - URLConnection
//
// void CFURLConnectionSendAsynchronousRequest(CFURLRequestRef req, void (^)(CFURLResponseRef, CFDataRef, CFErrorRef));
Boolean CFURLConnectionGetResponse(CFURLConnectionRef conn, CFURLResponseRef *response, CFErrorRef *error);
Boolean CFURLConnectionSendSynchronousRequest(CFURLRequestRef req, CFURLResponseRef *response, CFErrorRef *err, CFTimeInterval timeout);
CFDictionaryRef _CFURLConnectionCopyTimingData(CFURLConnectionRef conn);
CFIndex CFURLConnectionGetMaximumBufferSize(CFURLConnectionRef conn);
CFTypeID CFHTTPMessageGetTypeID(void);
CFURLConnectionRef CFURLConnectionCreate(CFAllocatorRef alloc, CFURLRequestRef req, const CFURLConnectionContext *ctx);
CFURLConnectionRef CFURLConnectionCreateWithProperties(CFAllocatorRef alloc, CFURLRequestRef req, CFURLConnectionClient *client, CFDictionaryRef properties);
void CFURLConnectionCancel(CFURLConnectionRef conn);
void CFURLConnectionHalt(CFURLConnectionRef conn);
void CFURLConnectionPerformDefaultHandlingForChallenge(CFURLConnectionRef conn, CFURLAuthChallengeRef challenge);
void CFURLConnectionRejectChallenge(CFURLConnectionRef conn, CFURLAuthChallengeRef challenge);
void CFURLConnectionScheduleDownloadWithRunLoop(CFURLConnectionRef conn, CFRunLoopRef rl, CFStringRef mode);
void CFURLConnectionScheduleWithCurrentMessageQueue(CFURLConnectionRef conn);
void CFURLConnectionScheduleWithRunLoop(CFURLConnectionRef conn, CFRunLoopRef rl, CFStringRef mode);
void CFURLConnectionSetDelegateDispatchQueue(CFURLConnectionRef conn, dispatch_queue_t q);
void CFURLConnectionSetHandler(CFURLConnectionRef conn, const CFURLConnectionHandlerContext *handlerContext);
void CFURLConnectionSetMaximumBufferSize(CFURLConnectionRef conn, CFIndex maxSizeToBuffer);
void CFURLConnectionStart(CFURLConnectionRef conn);
void CFURLConnectionUnscheduleDownloadFromRunLoop(CFURLConnectionRef conn, CFRunLoopRef rl, CFStringRef mode);
void CFURLConnectionUnscheduleFromRunLoop(CFURLConnectionRef conn, CFRunLoopRef runLoop, CFStringRef runLoopMode);
void CFURLConnectionUseCredential(CFURLConnectionRef conn, CFURLCredentialRef creds, CFURLAuthChallengeRef challenge);


//
// - URLRequest
//
Boolean CFURLRequestGetShouldPipelineHTTP(CFURLRequestRef req);
Boolean CFURLRequestSetAllowsCellularAccess(CFMutableURLRequestRef req, Boolean allowed);
Boolean CFURLRequestSetHTTPMethod(CFMutableURLRequestRef req, CFStringRef method);
Boolean CFURLRequestSetNetworkServiceType(CFMutableURLRequestRef req, CFURLRequestNetworkServiceType type);
Boolean CFURLRequestSetTimeout(CFMutableURLRequestRef req, CFTimeInterval timeout);
Boolean CFURLRequestShouldHandleHTTPCookies(CFURLRequestRef req);
Boolean CFURLRequestShouldStartSynchronously(CFURLRequestRef req);
CFArrayRef CFURLRequestCopyAdditionalHTTPCookies(CFURLRequestRef req);
CFArrayRef CFURLRequestCopyHTTPRequestBodyParts(CFURLRequestRef req);
CFArrayRef _CFURLRequestCopyContentDispositionEncodingFallbackArray(CFURLRequestRef req);
CFDataRef CFURLRequestCopyHTTPRequestBody(CFURLRequestRef req);
CFDictionaryRef CFURLRequestCopyAllHTTPHeaderFields(CFURLRequestRef req);
CFDictionaryRef CFURLRequestGetProxySettings(CFURLRequestRef req);
CFDictionaryRef CFURLRequestGetSSLProperties(CFURLRequestRef req);
CFHTTPCookieStorageAcceptPolicy CFURLRequestGetHTTPCookieStorageAcceptPolicy(CFURLRequestRef req);
CFHTTPCookieStorageRef CFURLRequestCopyHTTPCookieStorage(CFURLRequestRef req);
CFHTTPMessageRef CFURLRequestCopyHTTPRequest(CFURLRequestRef req);
CFMutableURLRequestRef CFURLRequestCreateMutable(CFAllocatorRef alloc, CFURLRef URL, CFURLRequestCachePolicy cachePolicy, CFTimeInterval timeout, CFURLRef mainDocumentURL);
CFMutableURLRequestRef CFURLRequestCreateMutableCopy(CFAllocatorRef alloc, CFURLRequestRef origRequest);
CFMutableURLRequestRef CFURLRequestCreateMutableHTTPRequest(CFAllocatorRef alloc, CFHTTPMessageRef httpRequest, CFArrayRef bodyParts, CFURLRequestCachePolicy cachePolicy, CFTimeInterval timeout, CFURLRef mainDocumentURL);
CFMutableURLRequestRef _CFURLRequestCreateFromArchiveList(CFAllocatorRef alloc, CFIndex version, CFTypeRef* objects, CFIndex objectCount, CFDictionaryRef protocolProperties);
CFReadStreamRef CFURLRequestCopyHTTPRequestBodyStream(CFURLRequestRef req);
CFStringRef CFURLRequestCopyHTTPHeaderFieldValue(CFURLRequestRef req, CFStringRef headerField);
CFStringRef CFURLRequestCopyHTTPRequestMethod(CFURLRequestRef req);
CFTimeInterval CFURLRequestGetTimeoutInterval(CFURLRequestRef req);
CFURLRef CFURLRequestGetMainDocumentURL(CFURLRequestRef req);
CFURLRef CFURLRequestGetURL(CFURLRequestRef req);
CFURLRequestCachePolicy CFURLRequestGetCachePolicy(CFURLRequestRef req);
CFURLRequestNetworkServiceType CFURLRequestGetNetworkServiceType(CFURLRequestRef req);
CFURLRequestPriority CFURLRequestGetRequestPriority(CFURLRequestRef req);
CFURLRequestRef CFURLRequestCreate(CFAllocatorRef alloc, CFURLRef URL, CFURLRequestCachePolicy cachePolicy, CFTimeInterval timeout, CFURLRef mainDocumentURL);
CFURLRequestRef CFURLRequestCreateCopy(CFAllocatorRef alloc, CFURLRequestRef originalRequest);
CFURLRequestRef CFURLRequestCreateHTTPRequest(CFAllocatorRef alloc, CFTypeRef httpRequest, CFArrayRef bodyParts, int cachePolicy, CFTimeInterval timeout, CFURLRef mainDocumentURL);
void CFURLRequestAppendHTTPHeaderFieldValue(CFMutableURLRequestRef mutableHTTPRequest, CFStringRef httpHeaderField, CFStringRef additionalHttpHeaderFieldValue);
void CFURLRequestSetAdditionalHTTPCookies(CFMutableURLRequestRef mutableHTTPRequest, CFArrayRef additionalCookies);
void CFURLRequestSetCachePolicy(CFMutableURLRequestRef mutableRequest, CFURLRequestCachePolicy cachePolicy);
void CFURLRequestSetHTTPCookieStorage(CFMutableURLRequestRef req, CFHTTPCookieStorageRef cookieStorage);
void CFURLRequestSetHTTPCookieStorageAcceptPolicy(CFMutableURLRequestRef req, CFHTTPCookieStorageAcceptPolicy cookieStorageAcceptPolicy);
void CFURLRequestSetHTTPHeaderFieldValue(CFMutableURLRequestRef mutableHTTPRequest, CFStringRef httpHeaderField, CFStringRef httpHeaderFieldValue);
void CFURLRequestSetHTTPRequestBody(CFMutableURLRequestRef mutableHTTPRequest, CFDataRef httpBody);
void CFURLRequestSetHTTPRequestBodyParts(CFMutableURLRequestRef mutableHTTPRequest, CFArrayRef bodyParts);
void CFURLRequestSetHTTPRequestBodyStream(CFMutableURLRequestRef req, CFReadStreamRef bodyStream);
void CFURLRequestSetHTTPRequestMethod(CFMutableURLRequestRef mutableHTTPRequest, CFStringRef httpMethod);
void CFURLRequestSetMainDocumentURL(CFMutableURLRequestRef mutableRequest, CFURLRef mainDocumentURL);
void CFURLRequestSetMaximumPermissibleContentLength(CFMutableURLRequestRef mutableRequest, SInt64 maximumLength);
void CFURLRequestSetMultipleHTTPHeaderFields(CFMutableURLRequestRef mutableHTTPRequest, CFDictionaryRef headerFields);
void CFURLRequestSetProxySettings(CFMutableURLRequestRef mutableRequest, CFDictionaryRef proxySettings);
void CFURLRequestSetRequestPriority(CFMutableURLRequestRef req, CFURLRequestPriority priority);
void CFURLRequestSetSSLProperties(CFMutableURLRequestRef mutableRequest, CFDictionaryRef sslProperties);
void CFURLRequestSetShouldCacheResponse(CFMutableURLRequestRef mutableRequest, Boolean shouldCacheResponse);
void CFURLRequestSetShouldHandleHTTPCookies(CFMutableURLRequestRef mutableHTTPRequest, Boolean shouldHandleCookies);
void CFURLRequestSetShouldPipelineHTTP(CFMutableURLRequestRef req, Boolean shouldPipeline, Boolean shouldUsePipeliningHeuristics);
void CFURLRequestSetShouldStartSynchronously(CFMutableURLRequestRef req, Boolean should);
void CFURLRequestSetTimeoutInterval(CFMutableURLRequestRef mutableRequest, CFTimeInterval timeoutInterval);
void CFURLRequestSetURL(CFMutableURLRequestRef req, CFURLRef url);
void _CFURLRequestCreateArchiveList(CFAllocatorRef alloc, CFURLRequestRef req, CFIndex* version, CFTypeRef** objects, CFIndex* objectCount, CFDictionaryRef* protocolProperties);
void _CFURLRequestSetProtocolProperty(CFMutableURLRequestRef req, CFStringRef name, CFTypeRef value);
void _CFURLRequestSetStorageSession(CFMutableURLRequestRef req, CFURLStorageSessionRef storageSession);
void _CFURLRequestSetAllowedProtocolTypes(CFMutableURLRequestRef req, Boolean allow);


//
// - URLResponse
//
Boolean CFURLResponseConnectionIsCellular(CFURLResponseRef response);
Boolean CFURLResponseDataIsEncoded(CFURLResponseRef response);
Boolean CFURLResponseIsHTTPResponse(CFURLResponseRef response);
Boolean _CFURLResponseIsCacheableWithRequest(CFURLResponseRef response, CFURLRequestRef req);
CFAbsoluteTime CFURLResponseGetCreationTime(CFURLResponseRef response);
CFDictionaryRef CFURLResponseGetHeaderFields(CFURLResponseRef response);
CFDictionaryRef _CFURLResponseGetSSLCertificateContext(CFURLResponseRef response);
CFHTTPMessageRef CFURLResponseGetHTTPResponse(CFURLResponseRef response);
CFIndex CFURLResponseGetStatusCode(CFURLResponseRef response);
CFPropertyListRef _CFURLResponseCreateParcel(CFURLResponseRef response);
CFStringRef CFURLResponseCopySuggestedFilename(CFURLResponseRef response);
CFStringRef CFURLResponseGetMIMEType(CFURLResponseRef response);
CFStringRef CFURLResponseGetTextEncodingName(CFURLResponseRef response);
CFTypeID CFURLResponseGetTypeID(void);
CFURLCacheStoragePolicy CFURLResponseGetRecommendedCachePolicy(CFURLResponseRef response);
CFURLRef CFURLResponseGetURL(CFURLResponseRef response);
CFURLResponseRef CFURLResponseCreate(CFAllocatorRef alloc, CFURLRef url, CFStringRef mimeType, SInt64 length, CFStringRef textEncoding);
CFURLResponseRef CFURLResponseCreateCopy(CFAllocatorRef alloc, CFURLResponseRef response);
CFURLResponseRef CFURLResponseCreateWithCFHTTPMessage(CFAllocatorRef alloc, CFURLRef URL, CFHTTPMessageRef responseMessage);
CFURLResponseRef CFURLResponseCreateWithHTTPResponse(CFAllocatorRef alloc, CFURLRef URL, CFHTTPMessageRef responseMessage, CFURLCacheStoragePolicy cacheStoragePolicy);
CFURLResponseRef _CFURLResponseCreateFromParcel(CFAllocatorRef alloc, CFPropertyListRef parcel);
CFURLResponseSource _CFURLResponseChooseSourceWithRequest(CFURLResponseRef response, CFURLRequestRef req, CFAbsoluteTime now);
SInt64 CFURLResponseGetExpectedContentLength(CFURLResponseRef response);
void CFURLResponseSetExpectedContentLength(CFURLResponseRef response, SInt64 length);
void CFURLResponseSetExpiration(CFURLResponseRef response, CFAbsoluteTime expiration);
void CFURLResponseSetMIMEType(CFURLResponseRef response, CFStringRef mimeType);
void CFURLResponseSetRecommendedCachePolicy(CFURLResponseRef response, CFURLCacheStoragePolicy policy);
void _CFURLResponseSetCreationTime(CFURLResponseRef response, CFAbsoluteTime creationTime);
CFTimeInterval _CFURLResponseGetFreshnessLifetime(CFURLResponseRef response);


//
// - HTTPCookieStorage
//
CFArrayRef CFHTTPCookieStorageCopyCookies(CFHTTPCookieStorageRef storage);
CFArrayRef CFHTTPCookieStorageCopyCookiesForURL(CFHTTPCookieStorageRef storage, CFURLRef url);
CFArrayRef _CFHTTPCookieStorageCopyCookiesForURLWithMainDocumentURL(CFHTTPCookieStorageRef storage, CFURLRef URL, CFURLRef mainDocumentURL, Boolean sendSecureCookies);
CFDictionaryRef _CFHTTPCookieStorageCopyRequestHeaderFieldsForURL(CFAllocatorRef alloc, CFHTTPCookieStorageRef storage, CFURLRef URL);
CFHTTPCookieStorageAcceptPolicy CFHTTPCookieStorageGetCookieAcceptPolicy(CFHTTPCookieStorageRef storage);
CFHTTPCookieStorageRef _CFHTTPCookieStorageGetDefault(void);
CFURLCredentialStorageRef _CFURLStorageSessionCopyCredentialStorage(CFAllocatorRef alloc, CFURLStorageSessionRef storageSession);
void CFHTTPCookieStorageAddObserver(CFHTTPCookieStorageRef storage, CFRunLoopRef runLoop, CFStringRef, CFHTTPCookieStorageChangedProcPtr, void*);
void CFHTTPCookieStorageDeleteAllCookies(CFHTTPCookieStorageRef storage);
void CFHTTPCookieStorageDeleteCookie(CFHTTPCookieStorageRef storage, CFHTTPCookieRef cookie);
void CFHTTPCookieStorageRemoveObserver(CFHTTPCookieStorageRef storage, CFRunLoopRef runLoop, CFStringRef, CFHTTPCookieStorageChangedProcPtr, void*);
void CFHTTPCookieStorageScheduleWithRunLoop(CFHTTPCookieStorageRef storage, CFRunLoopRef runLoop, CFStringRef runLoopMode);
void CFHTTPCookieStorageSetCookies(CFHTTPCookieStorageRef storage, CFArrayRef cookies);
void CFHTTPCookieStorageUnscheduleFromRunLoop(CFHTTPCookieStorageRef storage, CFRunLoopRef runLoop, CFStringRef runLoopMode);
void _CFHTTPCookieStorageFlushCookieStores(void);


//
// - HTTPCookie
//
Boolean CFHTTPCookieIsHTTPOnly(CFHTTPCookieRef cookie);
Boolean CFHTTPCookieIsSecure(CFHTTPCookieRef cookie);
CFAbsoluteTime CFHTTPCookieGetExpirationTime(CFHTTPCookieRef inCookie);
CFArrayRef CFHTTPCookieCreateWithResponseHeaderFields(CFAllocatorRef alloc, CFDictionaryRef headerFields, CFURLRef inURL);
CFDictionaryRef CFHTTPCookieCopyProperties(CFHTTPCookieRef inCookie);
CFDictionaryRef CFHTTPCookieCopyRequestHeaderFields(CFAllocatorRef alloc, CFArrayRef inCookies);
CFHTTPCookieRef CFHTTPCookieCreateWithProperties(CFAllocatorRef alloc, CFDictionaryRef inProperties);
CFHTTPCookieStorageRef CFHTTPCookieStorageCreateFromFile(CFAllocatorRef alloc, CFURLRef storageLocation, CFHTTPCookieStorageRef baseStorage);
CFStringRef CFHTTPCookieCopyDomain(CFHTTPCookieRef inCookie);
CFStringRef CFHTTPCookieCopyName(CFHTTPCookieRef inCookie);
CFStringRef CFHTTPCookieCopyPath(CFHTTPCookieRef inCookie);
CFStringRef CFHTTPCookieCopyValue(CFHTTPCookieRef inCookie);
CFTypeID CFHTTPCookieGetTypeID(void);
UInt32 CFHTTPCookieGetFlags(CFHTTPCookieRef inCookie);


//
// - URLProtectionSpace
//
Boolean CFURLProtectionSpaceIsProxy(CFURLProtectionSpaceRef space);
Boolean CFURLProtectionSpaceReceivesCredentialSecurely(CFURLProtectionSpaceRef space);
CFIndex CFURLProtectionSpaceGetPort(CFURLProtectionSpaceRef space);
CFStringRef CFURLProtectionSpaceGetHost(CFURLProtectionSpaceRef space);
CFStringRef CFURLProtectionSpaceGetRealm(CFURLProtectionSpaceRef space);
CFURLProtectionSpaceAuthenticationSchemeType CFURLProtectionSpaceGetAuthenticationScheme(CFURLProtectionSpaceRef space);
CFURLProtectionSpaceRef CFURLProtectionSpaceCreate(CFAllocatorRef alloc, CFStringRef host, CFIndex port, CFURLProtectionSpaceServerType serverType, CFStringRef realm, CFURLProtectionSpaceAuthenticationSchemeType scheme);
CFURLProtectionSpaceServerType CFURLProtectionSpaceGetServerType(CFURLProtectionSpaceRef space);
SecTrustRef CFURLProtectionSpaceGetServerTrust(CFURLProtectionSpaceRef space);


//
// - URLCache
//
CFCachedURLResponseRef CFCachedURLResponseCreateWithData(CFAllocatorRef alloc, CFURLResponseRef response, CFDataRef data);
CFCachedURLResponseRef CFURLCacheCopyResponseForRequest(CFURLCacheRef cache, CFURLRequestRef request);
CFURLCacheRef CFURLCacheCreate(CFAllocatorRef alloc, CFIndex memoryCapacity, CFIndex diskCapacity, CFStringRef path);
CFURLCacheRef CFURLCacheCreate(CFAllocatorRef alloc, size_t memoryCapacity, size_t diskCapacity, CFStringRef path);
CFURLResponseRef CFCachedURLResponseGetWrappedResponse(CFCachedURLResponseRef cachedResponse);
size_t CFURLCacheCurrentDiskUsage(CFURLCacheRef cache);
size_t CFURLCacheDiskCapacity(CFURLCacheRef cache);
size_t CFURLCacheMemoryCapacity(CFURLCacheRef cache);
void CFURLCacheAddCachedResponseForRequest(CFURLCacheRef cacheRef, CFCachedURLResponseRef cachedResponse, CFURLRequestRef request, CFTypeRef nsCachedURLResponse);
void CFURLCacheRemoveAllCachedResponses(CFURLCacheRef cache);
void CFURLCacheRemoveCachedResponseForRequest(CFURLCacheRef cache, CFURLRequestRef request);
void CFURLCacheSetDiskCapacity(CFURLCacheRef cache, size_t capacity);
void CFURLCacheSetMemoryCapacity(CFURLCacheRef cache, size_t capacity);
void CFURLCacheSetSharedURLCache(CFURLCacheRef cache);


//
// - URLStorageSession
//
CFHTTPCookieStorageRef _CFURLStorageSessionCopyCookieStorage(CFAllocatorRef alloc, CFURLStorageSessionRef storageSession);
CFStringRef _CFURLStorageSessionCopyIdentifier(CFAllocatorRef alloc, CFURLStorageSessionRef storageSession);
CFURLCacheRef _CFURLStorageSessionCopyCache(CFAllocatorRef alloc, CFURLStorageSessionRef storageSession);
CFURLCredentialStorageRef _CFURLStorageSessionCopyCredentialStorage(CFAllocatorRef alloc, CFURLStorageSessionRef storageSession);
CFURLStorageSessionRef _CFURLStorageSessionCopyProcessDefault(CFAllocatorRef alloc);
CFURLStorageSessionRef _CFURLStorageSessionCreate(CFAllocatorRef alloc, CFStringRef sessionIdentifier, CFDictionaryRef sessionProperties);
CFURLStorageSessionRef _CFURLStorageSessionCreateWithData(CFAllocatorRef alloc, CFDataRef data);


//
// - URLDownload
//
Boolean CFURLDownloadDeletesUponFailure(CFURLDownloadRef download);
CFDataRef CFURLDownloadCopyResumeData(CFURLDownloadRef download);
CFURLDownloadRef CFURLDownloadCreate(CFAllocatorRef alloc, CFURLRequestRef request, CFURLDownloadClient *client);
CFURLDownloadRef CFURLDownloadCreateWithResumeData(CFAllocatorRef alloc, CFDataRef resumeData, CFURLRef path, CFURLDownloadClient *client);
void CFURLDownloadCancel(CFURLDownloadRef download);
void CFURLDownloadScheduleWithRunLoop(CFURLDownloadRef download, CFRunLoopRef rl, CFStringRef mode);
void CFURLDownloadSetDeletesUponFailure(CFURLDownloadRef download, Boolean deletesUponFailure);
void CFURLDownloadSetDestination(CFURLDownloadRef download, CFURLRef path, Boolean allowOverwrite);
void CFURLDownloadStart(CFURLDownloadRef download);


//
// - URLAuthChallenge
//
CFErrorRef CFURLAuthChallengeGetError(CFURLAuthChallengeRef authChallenge);
CFIndex CFURLAuthChallengeGetPreviousFailureCount(CFURLAuthChallengeRef authChallenge);
CFTypeRef CFURLAuthChallengeGetFailureResponse(CFURLAuthChallengeRef authChallenge);
CFURLAuthChallengeRef CFURLAuthChallengeCreate(CFAllocatorRef alloc, CFURLProtectionSpaceRef protectionSpace, CFURLCredentialRef proposedCredential, CFIndex previousFailureCount, CFURLResponseRef failureResponse, CFErrorRef error);
CFURLCredentialRef CFURLAuthChallengeGetProposedCredential(CFURLAuthChallengeRef authChallenge);
CFURLProtectionSpaceRef CFURLAuthChallengeGetProtectionSpace(CFURLAuthChallengeRef authChallenge);


//
// - URLCredential
//
Boolean CFURLCredentialContainsPassword(CFURLCredentialRef credential);
CFStringRef CFURLCredentialCopyPassword(CFURLCredentialRef credential);
CFStringRef CFURLCredentialGetUsername(CFURLCredentialRef credential);
CFURLCredentialPersistence CFURLCredentialGetPersistence(CFURLCredentialRef credential);
CFURLCredentialRef CFURLCredentialCreate(CFAllocatorRef alloc, CFStringRef username, CFStringRef password, CFStringRef accountDomain, CFURLCredentialPersistence persistence);
CFURLCredentialRef CFURLCredentialCreateWithTrust(CFAllocatorRef alloc, SecTrustRef trust);
CFURLCredentialRef _CFURLCredentialCreateForKerberosTicket(CFAllocatorRef allocator, CFStringRef userPrincipalName, CFStringRef servicePrincipalName, CFDictionaryRef kerberosFlags);
CFURLCredentialRef _CFURLCredentialCreateXMobileMeAuthToken(CFAllocatorRef alloc, CFStringRef appleID, CFStringRef password, CFStringRef realm);


//
// - NetServiceBrowser
//
Boolean CFNetServiceBrowserSearchForDomains(CFNetServiceBrowserRef browser, Boolean registrationDomains, CFStreamError *error);
Boolean CFNetServiceBrowserSearchForServices(CFNetServiceBrowserRef browser, CFStringRef domain, CFStringRef type, CFStreamError *error);
CFNetServiceBrowserRef CFNetServiceBrowserCreate(CFAllocatorRef alloc, CFNetServiceBrowserClientCallBack clientCB, CFNetServiceClientContext* context);
CFTypeID CFNetServiceBrowserGetTypeID(void);
void CFNetServiceBrowserInvalidate(CFNetServiceBrowserRef browser);
void CFNetServiceBrowserScheduleWithRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode);
void CFNetServiceBrowserStopSearch(CFNetServiceBrowserRef browser, CFStreamError *error);
void CFNetServiceBrowserUnscheduleFromRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode);
