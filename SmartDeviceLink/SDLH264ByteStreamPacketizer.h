//
//  SDLH264ByteStreamPacketizer.h
//  SmartDeviceLink-iOS
//
//  Created by Sho Amano on 4/11/17.
//  Copyright © 2017 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDLH264Packetizer.h"

@interface SDLH264ByteStreamPacketizer : NSObject <SDLH264Packetizer>

/**
 * Initializer.
 */
- (instancetype)init;

// see SDLH264Packetizer.h
- (NSArray *)createPackets:(NSArray *)nalUnits pts:(double)pts;

@end
