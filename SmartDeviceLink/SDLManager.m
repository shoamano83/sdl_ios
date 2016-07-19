

#import <Foundation/Foundation.h>

#import "SmartDeviceLink.h"

#import "SDLManager.h"

#import "NSMapTable+Subscripting.h"
#import "SDLConnectionManagerType.h"
#import "SDLLifecycleManager.h"
#import "SDLLockScreenManager.h"
#import "SDLLockScreenPresenter.h"
#import "SDLManagerDelegate.h"
#import "SDLNotificationDispatcher.h"
#import "SDLResponseDispatcher.h"
#import "SDLStateMachine.h"


NS_ASSUME_NONNULL_BEGIN

#pragma mark - SDLManager Private Interface

@interface SDLManager ()

@property (strong, nonatomic) SDLLifecycleManager *lifecycleManager;

@end


#pragma mark - SDLManager Implementation

@implementation SDLManager

#pragma mark Lifecycle

- (instancetype)init {
    return [self initWithConfiguration:[SDLConfiguration configurationWithLifecycle:[SDLLifecycleConfiguration defaultConfigurationWithAppName:@"SDL APP" appId:@"001"] lockScreen:nil] delegate:nil];
}

- (instancetype)initWithConfiguration:(SDLConfiguration *)configuration delegate:(nullable id<SDLManagerDelegate>)delegate {
    self = [super init];
    if (!self) {
        return nil;
    }
    
    _lifecycleManager = [[SDLLifecycleManager alloc] initWithConfiguration:configuration delegate:delegate];
    
    return self;
}

- (void)start {
    [self.lifecycleManager start];
}

- (void)stop {
    [self.lifecycleManager stop];
}


#pragma mark - Passthrough getters

- (NSString *)lifecycleState {
    return self.lifecycleManager.lifecycleState;
}

- (SDLConfiguration *)configuration {
    return self.lifecycleManager.configuration;
}

- (SDLHMILevel *)currentHMILevel {
    return self.lifecycleManager.currentHMILevel;
}

- (SDLFileManager *)fileManager {
    return self.lifecycleManager.fileManager;
}

- (SDLPermissionManager *)permissionManager {
    return self.lifecycleManager.permissionManager;
}

- (nullable SDLStreamingMediaManager *)streamManager {
    return self.lifecycleManager.streamManager;
}


#pragma mark SDLConnectionManager Protocol

- (void)sendRequest:(SDLRPCRequest *)request {
    [self sendRequest:request withCompletionHandler:nil];
}

- (void)sendRequest:(__kindof SDLRPCRequest *)request withCompletionHandler:(nullable SDLRequestCompletionHandler)handler {
    [self.lifecycleManager sendRequest:request withCompletionHandler:handler];
}

@end

NS_ASSUME_NONNULL_END
