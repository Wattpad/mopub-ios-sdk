//
//  MOPUBAVPlayer.h
//  Copyright (c) 2015 MoPub. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

@class MOPUBAVPlayer;

@protocol MOPUBAVPlayerDelegate <NSObject>

- (void)avPlayer:(MOPUBAVPlayer *)player didError:(NSError *)error withMessage:(NSString *)message;

- (void)avPlayer:(MOPUBAVPlayer *)player playbackTimeDidProgress:(NSTimeInterval)currentPlaybackTime;

- (void)avPlayerDidFinishPlayback:(MOPUBAVPlayer *)player;

- (void)avPlayerDidRecoverFromStall:(MOPUBAVPlayer *)player;

- (void)avPlayerDidStall:(MOPUBAVPlayer *)player;

@end

@protocol MOPUBAVPlayerObserver <NSObject>
@optional
- (void)avPlayer:(MOPUBAVPlayer *)player didError:(NSError *)error withMessage:(NSString *)message;
- (void)avPlayer:(MOPUBAVPlayer *)player playbackTimeDidProgress:(NSTimeInterval)currentPlaybackTime;
- (void)avPlayerDidFinishPlayback:(MOPUBAVPlayer *)player;
- (void)avPlayerDidRecoverFromStall:(MOPUBAVPlayer *)player;
- (void)avPlayerDidStall:(MOPUBAVPlayer *)player;
@end


@interface MOPUBAVPlayer : AVPlayer

@property (nonatomic, weak) id<MOPUBAVPlayerObserver> observer;

// Indicates the duration of the player item.
@property (nonatomic, readonly) NSTimeInterval currentItemDuration;

// Returns the current time of the current player item.
@property (nonatomic, readonly) NSTimeInterval currentPlaybackTime;

- (id)initWithDelegate:(id<MOPUBAVPlayerDelegate>)delegate playerItem:(AVPlayerItem *)playerItem;

- (void)dispose;

@end
