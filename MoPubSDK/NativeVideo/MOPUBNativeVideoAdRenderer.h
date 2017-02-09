//
//  MOPUBNativeVideoAdRenderer.h
//  Copyright (c) 2015 MoPub. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MPNativeAdRenderer.h"

@class MPNativeAdRendererConfiguration;
@class MPStaticNativeAdRendererSettings;

@protocol MOPUBPlayerViewControllerObserver;

@interface MOPUBNativeVideoAdRenderer : NSObject

@property (nonatomic, readonly) MPNativeViewSizeHandler viewSizeHandler;
@property (nonatomic, weak) id<MOPUBPlayerViewControllerObserver> observer;

+ (MPNativeAdRendererConfiguration *)rendererConfigurationWithRendererSettings:(id<MPNativeAdRendererSettings>)rendererSettings;

@end
