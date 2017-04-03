//
//  AMSGameKitHelper.h
//  ECrush
//
//  Created by Engel Alipio on 8/18/14.
//  Copyright (c) 2017 Agile Mobile Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>

//   Protocol to notify external
//   objects when Game Center events occur or
//   when Game Center async tasks are completed
@protocol GameKitHelperProtocol<NSObject>
-(void) onScoresSubmitted:(bool)success;
@end

@interface AMSGameKitHelper : NSObject

@property (nonatomic, assign) id<GameKitHelperProtocol> delegate;

// This property holds the last known error
// that occured while using the Game Center API's
@property (nonatomic, readonly) NSError* lastError;

+ (id) sharedGameKitHelper;

// Player authentication, info
-(void) authenticateLocalPlayer;
-(void) submitScore:(int64_t)score category:(NSString*)category;
-(void) reportAchievement:(NSDictionary *) achievementData;
-(void) showLeaderBoard:(NSString *) leaderboardID;
@end
