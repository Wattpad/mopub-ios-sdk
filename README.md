# Wattpad forked Mopub SDK
For original read me on latest version, visit: https://github.com/mopub/mopub-ios-sdk/blob/master/README.md
last edited by 18th Sept 2019, Elton

# Motivation
The reason we have a forked version of Mopub SDK is to resolve any crash or bugs we saw from crash analytics tool

The general approach to forking is we create a internal branch off master branch, then apply relevant fixes we have historically on top of it

# How to update to latest version 
1. Update our own master to top of mopub's master

To achieve this, we need to be in our repo, then do `git checkout master` then `git pull mopub master`. Check that our master branch is in sync with theirs and push it to remote master: `git push origin master`

2. Create branch off last known internal branch

To achieve this, first find the `x.x.x_internal` branch that has the latest version number we know, then do a fork from it for the latest version Mopub has: `git checkout -b <target_version_internal>`

3. Do a interactive rebase for this branch against master branch

In this branch, do `git rebase -i origin/master` so that it will apply historical changes we made (should not be a lot, otherwise pick the ones made by us). Since it is interactive, do this step by step to resolve any conflicts and/or remove the patch we made if it is irrelevant. 

It's best to pair with a senior developer at this step to ensure you did it right.

4. Make sure podspec is correct, push the branch and test using core app

Before push it to remote, make sure the podspec has the right version inside, then switch to core app repo and try to use it via Podfile

The current version of the SDK is 5.12.1

### Installation with CocoaPods

[CocoaPods](https://cocoapods.org/) is a dependency manager for Swift and Objective-C Cocoa projects, which automates and simplifies the process of using 3rd-party libraries like the MoPub SDK in your projects. You can install it with the following command:

```
$ gem install cocoapods
```

**Podfile**
To integrate MoPub SDK into your Xcode project using CocoaPods, specify it in your Podfile:

```
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '9.0'
use_frameworks!

target 'MyApp' do
  pod 'mopub-ios-sdk', '~> 5.9'
end
```

Then, run the following command:

```
$ pod install
```

### Manual Integration with Dynamic Framework

MoPub provides a prepackaged archive of the dynamic framework:

- **[MoPub SDK Framework.zip](https://github.com/mopub/mopub-ios-sdk/releases/download/5.12.1/mopub-framework-5.12.1.zip)**

  Includes everything you need to serve HTML, MRAID, and Native MoPub advertisements.  Third party ad networks are not included.

Add the dynamic framework to the target's Embedded Binaries section of the General tab.

### Manual Integration with Source Code

MoPub provides two prepackaged archives of source code:

- **[MoPub Base SDK.zip](https://github.com/mopub/mopub-ios-sdk/releases/download/5.12.1/mopub-base-5.12.1.zip)**

  Includes everything you need to serve HTML, MRAID, and Native MoPub advertisements.  Third party ad networks are not included.

- **[MoPub Base SDK Excluding Native.zip](https://github.com/mopub/mopub-ios-sdk/releases/download/5.12.1/mopub-nonnative-5.12.1.zip)**

  Includes everything you need to serve HTML and MRAID advertisements.  Third party ad networks and Native MoPub advertisements are not included.

## Integrate

Integration instructions are available on the [wiki](https://github.com/mopub/mopub-ios-sdk/wiki/Getting-Started).

## New in this Version

Please view the [changelog](https://github.com/mopub/mopub-ios-sdk/blob/master/CHANGELOG.md) for details.

- **Bug Fixes**
  - Fixed banner click trackers not firing for mediated networks that do not use MoPub's auto click tracking.

See the [Getting Started Guide](https://github.com/mopub/mopub-ios-sdk/wiki/Getting-Started#app-transport-security-settings) for instructions on setting up ATS in your app.

## Upgrading to SDK 5.0

Please see the [Getting Started Guide](https://developers.mopub.com/docs/ios/getting-started/) for instructions on upgrading from SDK 4.X to SDK 5.0.

For GDPR-specific upgrading instructions, also see the [GDPR Integration Guide](https://developers.mopub.com/docs/publisher/gdpr).

### <a name="disableViewability"></a>Disabling Viewability Measurement
There are a few options for opting out of viewability measurement:
##### Opting Out in a Manual Integration
Before dragging the MoPubSDK folder into your Xcode project, simply delete the “Moat” folder to opt out of Moat or the “Avid” folder to opt out of IAS in MoPubSDK/Viewability/. If you would like to opt out of both, delete both folders.
##### Opting Out in a CocoaPods Integration
Including `pod 'mopub-ios-sdk'` in your Podfile will include both IAS and Moat SDKs, as well as the MoPub SDK. In order to opt out:
- `pod 'mopub-ios-sdk/Avid'` will include the IAS SDK, but not the Moat SDK, as well as the MoPub SDK.
- `pod 'mopub-ios-sdk/Moat'` will include the Moat SDK, but not the IAS SDK, as well as the MoPub SDK.
- `pod 'mopub-ios-sdk/Core'` will only include the MoPub SDK, with viewability measurement totally disabled.

Make sure to run `pod update` once your Podfile is set up to your preferences.
##### Software Disable
If you would like to opt out of viewability measurement but do not want to modify the MoPub SDK, a function is provided for your convenience. As soon as possible after calling `- (void)initializeSdkWithConfiguration:completion:`, call `[[MoPub sharedInstance] disableViewability:(vendors)]`. In place of “(vendors)”, `MPViewabilityOptionIAS` will disable IAS but leave Moat enabled, `MPViewabilityOptionMoat` will disable Moat but leave IAS enabled, and `MPViewabilityOptionAll` will disable all viewability measurement.

## Requirements

- iOS 9.0 and up
- Xcode 11.0 and up

## License

We have launched a new license as of version 3.2.0. To view the full license, visit [http://www.mopub.com/legal/sdk-license-agreement/](http://www.mopub.com/legal/sdk-license-agreement/)
