//
//  SDLH264Packetizer.h
//  SmartDeviceLink-iOS
//
//  Created by Sho Amano on 4/11/17.
//  Copyright © 2017 smartdevicelink. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SDLH264Packetizer

/**
 * Creates packets from given H.264 NAL units and presentation timestamp.
 *
 * @param nalUnits List of NAL units to create packets.
 * @param pts Presentation timestamp associated to the NAL units, in seconds.
 *
 * @return List of NSData. Each NSData holds a packet.
 *
 * @note This method cannot be called more than once with same pts value. All NAL units that belongs to a frame
 *       should be included in nalUnits array.
 */
- (NSArray *)createPackets:(NSArray *)nalUnits pts:(double)pts;

@end
