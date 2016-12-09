//
//  SDLVideoEncoder.h
//  SmartDeviceLink-iOS
//
//  Created by Muller, Alexander (A.) on 12/5/16.
//  Copyright © 2016 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, SDLVideoEncoderError) {
    SDLVideoEncoderErrorInvalidOperatingSystemVersion = 0,
    SDLVideoEncoderErrorConfigurationCompressionSessionCreationFailure = 1,
    SDLVideoEncoderErrorConfigurationAllocationFailure = 2,
    SDLVideoEncoderErrorConfigurationCompressionSessionSetPropertyFailure = 3
};

extern NSString *const SDLErrorDomainVideoEncoder;

@class SDLVideoEncoder;

@protocol SDLVideoEncoderDelegate <NSObject>

- (void)videoEncoder:(SDLVideoEncoder *)encoder hasEncodedVideo:(NSData*)encodedVideo;

@end

@interface SDLVideoEncoder : NSObject

- (instancetype)initWithDimensions:(CGSize)dimensions delegate:(id<SDLVideoEncoderDelegate> __nullable)delegate error:(NSError **)error;

- (instancetype)initWithDimensions:(CGSize)dimensions properties:(NSDictionary<NSString *, id> *__nullable)properties delegate:(id<SDLVideoEncoderDelegate> __nullable)delegate error:(NSError **)error;

- (void)stop;

- (BOOL)encodeFrame:(CVImageBufferRef)imageBuffer;

@property (nonatomic, weak, nullable) id<SDLVideoEncoderDelegate> delegate;

/**
 *  The settings used in a VTCompressionSessionRef encoder. These will be verified when the video stream is started. Acceptable properties for this are located in VTCompressionProperties. If set to nil, the defaultVideoEncoderSettings will be used.
 *
 *  @warning Video streaming must not be connected to update the encoder properties. If it is running, issue a stopVideoSession before updating.
 */
@property (strong, nonatomic, null_resettable) NSDictionary<NSString *, id> *videoEncoderSettings;

/**
 *  Provides default video encoder settings used.
 */
@property (strong, nonatomic, readonly) NSDictionary<NSString *, id> *defaultVideoEncoderSettings;

/**
 *  The pixel buffer pool reference returned back from an active VTCompressionSessionRef encoder.
 *
 *  @warning This will only return a valid pixel buffer pool after the encoder has been initialized (when the video     session has started).
 *  @discussion Clients may call this once and retain the resulting pool, this call is cheap enough that it's OK to call it once per frame.
 */
@property (assign, nonatomic, readonly, nullable) CVPixelBufferPoolRef pixelBufferPool;


@end

NS_ASSUME_NONNULL_END