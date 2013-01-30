//
//  RKInjective.h
//  RESTClient
//
//  Created by Sergii Kliuiev on 1/23/13.
//  Copyright (c) 2013 Sergii Kliuiev. All rights reserved.
//

#import <RestKit/RestKit.h>

typedef enum {
    RKIRequestGetObjects = 0,
    RKIRequestGetObject
} RKIRequestType;

typedef void ( ^RKIObjectsSuccessBlock ) ( NSArray *objects );
typedef void ( ^RKIObjectSuccessBlock ) ( id object );
typedef void ( ^RKIFailureBlock ) (  NSError *error );

@interface RKInjective : NSObject 
+(void)registerClass:(Class)cls;
@end

@protocol RKInjectiveProtocol <NSObject>
@optional
+ (NSString *)modelName;
+ (NSString *)modelNamePlural;
+ (RKObjectMapping *)objectMapping;
+ (NSDictionary *)objectMappingDictionary;
+ (NSString *)uniqueIdentifierName;
+ (NSString *)pathForRequestType:(RKIRequestType)requestType;
+ (NSString *)defaultPathForRequestType:(RKIRequestType)requestType;
- (id)uniqueIdentifier;
+ (void)getObjectsOnSuccess:(RKIObjectsSuccessBlock)success failure:(RKIFailureBlock)failure;
- (void)getObjectOnSuccess:(RKIObjectSuccessBlock)success failure:(RKIFailureBlock)failure;
- (void)postObjectOnSuccess:(RKIObjectSuccessBlock)success failure:(RKIFailureBlock)failure;
@end

#define rkinjective_register(cls) \
    + (void)initialize	\
    { \
        if(self == [cls class]) { \
            [RKInjective registerClass:[cls class]];\
        } \
    }