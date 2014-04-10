/*
 *
 * Copyright 2014 Flavio Negrão Torres
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <CoreData/CoreData.h>


#pragma mark - Notifications

/*******************
/ Sync Notifications
*******************/

/// Post this message to request the local cache to start the sync process with remote database
extern NSString *const APNotificationRequestCacheSync;

/// Post this message to request the local cache to start the FULL sync process with remote database (ignores whether or not a object was previously synced)
extern NSString *const APNotificationRequestCacheFullSync;

/// APIncrementalStore will post this message once it started the local cache sync process
extern NSString *const APNotificationCacheDidStartSync;

/// APIncrementalStore will post this message once it finished the local cache sync process
extern NSString *const APNotificationCacheDidFinishSync;

/// APNotificationCacheDidFinishSync will be sent with a userInfo which will contain the objects synced from the server keyed by constant
extern NSString* const APNotificationObjectsIDsKey;


/**************************
/ Cache Reset Notifications
***************************/

/// Post this message to request the local cache to recreate the local sqlite db as well as its psc and mocs
extern NSString* const APNotificationCacheRequestReset;

/// APIncrementalStore will post this message once it finished the local cache reset process
extern NSString* const APNotificationCacheDidFinishReset;



#pragma mark - Incremental Store Options
/*
 Use below options to configure few parameters related to this NSIncremental store subclass
 Example:
     [self.psc addPersistentStoreWithType:[APIncrementalStore type]
                            configuration:nil
                                       URL:nil
                                   options:@{APOptionAuthenticatedUserObjectKey:self.remoteDBAuthenticatedUser,
                                             APOptionCacheFileNameKey:APLocalCacheFileName,
                                             APOptionCacheFileResetKey:@NO,
                                             APOptionMergePolicyKey:APOptionMergePolicyServerWins}
                                     error:nil];
 */

/// The user object authenticated that will be used to sync with the BaaS provider.
extern NSString* const APOptionAuthenticatedUserObjectKey;

/// The name of the local cache store file.
extern NSString* const APOptionCacheFileNameKey;

/// Whether or not
extern NSString* const APOptionCacheFileResetKey;

/**
 When adding the this class to a persistant store coordinator use this option
 to control which object will get persistant when a conflict is detected between
 local and server objects:
 APIncrementalStoreMergePolicyServerWins - server object overwrite local object (DEFAULT)
 APIncrementalStoreMergePolicyClientWins - local object overwrite server object
 */
extern NSString* const APOptionMergePolicyKey;

/**
 Server object overwrite local object (DEFAULT)
 @see APOptionMergePolicy
 */
extern NSString* const APOptionMergePolicyServerWins;

/**
 Local object overwrite server object
 @see APOptionMergePolicy
 */
extern NSString* const APOptionMergePolicyClientWins;


#pragma mark -
@interface APIncrementalStore : NSIncrementalStore

+ (NSString*) type;

@end
