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

# How to test the updated version

After installing the updated POD, you need to make sure all the mediation adapters are working properly and if any of the adapter also needs to be updated. you can find the latest mediation adapters [here](https://developers.mopub.com/publishers/mediation/integrate/)

1. In the main app goto `settings` -> `developer options` -> `Ads playground` and manually check all the ad units and line items renders ads correctly. Each row represents a line item for [Wattpad Beta](https://app.mopub.com/apps) App in mopub dashboard. However, some of the line items are not configured correctly in the mopub dashboard and may fail to render ad. Verify this is happening due to poorly configured line item and not caused by mopub SDK update.

2. Do a regression testing in the production app and verify each ad unit renders a ad correctly.
