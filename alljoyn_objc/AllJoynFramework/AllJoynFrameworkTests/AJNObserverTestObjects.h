/******************************************************************************
 * Copyright AllSeen Alliance. All rights reserved.
 *
 *    Permission to use, copy, modify, and/or distribute this software for any
 *    purpose with or without fee is hereby granted, provided that the above
 *    copyright notice and this permission notice appear in all copies.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
//
//  ALLJOYN MODELING TOOL - GENERATED CODE
//
////////////////////////////////////////////////////////////////////////////////
//
//  DO NOT EDIT
//
//  Add a category or subclass in separate .h/.m files to extend these classes
//
////////////////////////////////////////////////////////////////////////////////
//
//  AJNObserverTestObjects.h
//
////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import "AJNBusAttachment.h"
#import "AJNBusInterface.h"
#import "AJNProxyBusObject.h"


////////////////////////////////////////////////////////////////////////////////
//
// TestJustADelegate Bus Interface
//
////////////////////////////////////////////////////////////////////////////////

@protocol TestJustADelegate <AJNBusInterface>


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


@end

////////////////////////////////////////////////////////////////////////////////

    

////////////////////////////////////////////////////////////////////////////////
//
// TestJustBDelegate Bus Interface
//
////////////////////////////////////////////////////////////////////////////////

@protocol TestJustBDelegate <AJNBusInterface>


// methods
//
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


@end

////////////////////////////////////////////////////////////////////////////////

    

////////////////////////////////////////////////////////////////////////////////
//
// TestBothDelegate Bus Interface
//
////////////////////////////////////////////////////////////////////////////////

@protocol TestBothDelegate <AJNBusInterface>


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


@end

////////////////////////////////////////////////////////////////////////////////

    

////////////////////////////////////////////////////////////////////////////////
//
// TestObjectABDelegateB Bus Interface
//
////////////////////////////////////////////////////////////////////////////////

@protocol TestObjectABDelegateB <AJNBusInterface>


// methods
//
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


@end

////////////////////////////////////////////////////////////////////////////////

    

////////////////////////////////////////////////////////////////////////////////
//
//  AJNTestJustA Bus Object superclass
//
////////////////////////////////////////////////////////////////////////////////

@interface AJNTestJustA : AJNBusObject<TestJustADelegate>

// properties
//


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


// signals
//


@end

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  TestJustA Proxy
//
////////////////////////////////////////////////////////////////////////////////

@interface TestJustAProxy : AJNProxyBusObject

// properties
//


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path;


@end

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  AJNTestJustB Bus Object superclass
//
////////////////////////////////////////////////////////////////////////////////

@interface AJNTestJustB : AJNBusObject<TestJustBDelegate>

// properties
//


// methods
//
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


// signals
//


@end

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  TestJustB Proxy
//
////////////////////////////////////////////////////////////////////////////////

@interface TestJustBProxy : AJNProxyBusObject

// properties
//


// methods
//
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path;


@end

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  AJNTestBoth Bus Object superclass
//
////////////////////////////////////////////////////////////////////////////////

@interface AJNTestBoth : AJNBusObject<TestBothDelegate, TestObjectABDelegateB>

// properties
//


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path message:(AJNMessage *)methodCallMessage;


// signals
//


@end

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  TestBoth Proxy
//
////////////////////////////////////////////////////////////////////////////////

@interface TestBothProxy : AJNProxyBusObject

// properties
//


// methods
//
- (void)identifyAWithBusname:(NSString**)busname andPath:(NSString**)path;
- (void)identifyBWithBusname:(NSString**)busname andPath:(NSString**)path;


@end

////////////////////////////////////////////////////////////////////////////////
