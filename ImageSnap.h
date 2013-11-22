//
//  ImageSnap.h
//  ImageSnap
//
//  Created by Robert Harder on 9/10/09.
//  Updated by Sam Green for Mavericks (OSX 10.9) on 11/22/13
//
#import <Cocoa/Cocoa.h>
#import <AVFoundation/AVFoundation.h>

NSString *VERSION = @"0.3.0";

@interface ImageSnap : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate> {
    CVImageBufferRef mCurrentImageBuffer;
}

/**
 * Returns all attached AVCaptureDevice objects that have video.
 * This includes video-only devices (AVMediaTypeVideo) and
 * audio/video devices (AVMediaTypeMuxed).
 *
 * @return autoreleased array of video devices
 */
+ (NSArray *)videoDevices;

/**
 * Returns the default AVCaptureDevice object for video
 * or nil if none is found.
 */
+ (AVCaptureDevice *)defaultVideoDevice;

/**
 * Returns the AVCaptureDevice with the given name
 * or nil if the device cannot be found.
 */
+ (AVCaptureDevice *)deviceNamed:(NSString *)name;

/**
 * Primary one-stop-shopping message for capturing an image.
 * Activates the video source, saves a frame, stops the source,
 * and saves the file.
 */
+ (BOOL)saveSnapshotFrom:(AVCaptureDevice *)device toFile:(NSString *)path;
+ (BOOL)saveSnapshotFrom:(AVCaptureDevice *)device toFile:(NSString *)path withWarmup:(NSNumber *)warmup;
+ (BOOL)saveSnapshotFrom:(AVCaptureDevice *)device toFile:(NSString *)path withWarmup:(NSNumber *)warmup withTimelapse:(NSNumber *)timelapse;

/**
 * Returns current snapshot or nil if there is a problem
 * or session is not started.
 */
- (NSImage *)snapshot;

@end
