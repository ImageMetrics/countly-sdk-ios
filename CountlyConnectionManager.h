// CountlyConnectionManager.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS
#import <UIKit/UIKit.h>
#endif

@interface CountlyConnectionManager : NSObject

@property (nonatomic, strong) NSString* appKey;
@property (nonatomic, strong) NSString* appHost;
@property (nonatomic, strong) NSURLSessionTask* connection;
@property (nonatomic, assign) BOOL startedWithTest;
#if TARGET_OS_IOS
@property (nonatomic, assign) UIBackgroundTaskIdentifier bgTask;
#endif

+ (instancetype)sharedInstance;

- (void)beginSession:(BOOL)isAppLaunch;
- (void)updateSessionWithDuration:(int)duration;
- (void)endSessionWithDuration:(int)duration;

- (void)sendEvents;
- (void)sendUserDetails:(NSString*)userDetails;
- (void)sendPushToken:(NSString*)token;
- (void)sendCrashReportLater:(NSString *)report;
- (void)sendOldDeviceID:(NSString *)oldDeviceID;
- (void)sendParentDeviceID:(NSString *)parentDeviceID;
- (void)sendLocation:(CLLocationCoordinate2D)coordinate;

- (NSString *)queryEssentials;


/**
 * IM ADDED
 */
@property (atomic, retain) NSUUID *sessionId;
@property (atomic, retain) NSString *countryCode; // TODO: Generalize this into a dictionary which gets sent with each request
@end
