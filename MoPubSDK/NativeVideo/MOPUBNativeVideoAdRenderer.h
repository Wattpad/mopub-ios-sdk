//
//  MOPUBNativeVideoAdRenderer.h
//  Copyright (c) 2015 MoPub. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MPNativeAdRenderer.h"
#import "MOPUBPlayerViewController.h"

@class MPNativeAdRendererConfiguration;
@class MPStaticNativeAdRendererSettings;

@interface MOPUBNativeVideoAdRenderer : NSObject

@property (nonatomic, readonly) MPNativeViewSizeHandler viewSizeHandler;
@property (nonatomic, weak) id<MOPUBPlayerViewControllerExposerDelegate> exposerDelegate;

+ (MPNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<MPNativeAdRendererSettings>)rendererSettings;

@end
