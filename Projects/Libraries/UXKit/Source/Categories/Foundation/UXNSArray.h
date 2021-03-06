
/*!
@project	UXKit
@header     UXNSArray.h
@copyright  (c) 2009 Joe Hewitt/Three20
@changes	(c) 2009 Semantap
*/

#import <Foundation/Foundation.h>

/*!
@category NSArray (UXNSArray)
@abstract
@discussion
*/
@interface NSArray (UXNSArray)

	/*!
	@abstract Calls performSelector on all objects in the array.
	*/
	-(void) perform:(SEL)aSelector;
	-(void) perform:(SEL)aSelector withObject:(id)arg1;
	-(void) perform:(SEL)aSelector withObject:(id)arg1 withObject:(id)arg2;
	-(void) perform:(SEL)aSelector withObject:(id)arg1 withObject:(id)arg2 withObject:(id)arg3;

	#pragma mark -

	-(id) objectWithValue:(id)aValue forKey:(id)aKey;
	-(id) objectWithClass:(Class)aClass;

	#pragma mark -

	-(BOOL) containsObject:(id)object withSelector:(SEL)selector;

@end

#pragma mark -

/*!
@category NSMutableArray (UXNSMutableArray)
@abstract
*/
@interface NSMutableArray (UXNSMutableArray)

	/*!
	@abstract Adds a string on the condition that it's non-nil and non-empty.
	*/
	-(void) addNonEmptyString:(NSString *)string;

@end

#pragma mark -

/*!
@category NSMutableArray (UXQueue)
@abstract
*/
@interface NSMutableArray (UXQueue)

	-(void) enqueue:(id)anObject;
	-(id) dequeue;

@end
