//
//  GitHubMoreAppController.h
//  GitHubMore
//
//  Created by Sword on 12-8-6.
//  Copyright LazyPandaGames 2012年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

