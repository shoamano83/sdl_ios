//
//  SDLRTPH264Packetizer.h
//  SmartDeviceLink-iOS
//
//  Created by Sho Amano on 4/11/17.
//  Copyright © 2017 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDLH264Packetizer.h"

@interface SDLRTPH264Packetizer : NSObject <SDLH264Packetizer>

/**
 * Payload Type (PT) of RTP header field.
 *
 * @note This must be between 0 and 127. Default value is 96.
 */
@property (assign, nonatomic) UInt8 payloadType;

/**
 * SSRC of RTP header field.
 *
 * @note A random value is generated and used as default.
 */
@property (assign, nonatomic) UInt32 ssrc;

/**
 * Initializer.
 */
- (instancetype)init;

// see SDLH264Packetizer.h
- (NSArray *)createPackets:(NSArray *)nalUnits pts:(double)pts;

@end
