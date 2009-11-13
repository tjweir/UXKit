
/*!
@project    UXKit
@header     UXCoding.h
@copyright  (c) 2009 Keith Lazuka
@changes	(c) 2009 Semantap
*/

/*!
@abstract This macro system is pretty ugly, but at least it works.
@discussion When encoding or decoding, |p| must be a property name (NSString)
@todo ENCODE_OBJ and DECODE_OBJ macros should dispatch to a helper macro if 
there is a more specific macro available for that property type. This may 
entail switching from using pre-processor macros to proper functions. Or at 
least for stuff like UIImage, I could just implement encodeWithCoder:/initWithCoder: 
as a category extension.
@notes NSKeyedArchiver cannot handle a struct (like UIEdgeInsets) even when it
is wrapped by NSValue. I'm sure there's a way to do it by just serializing
the bytes, but Apple warns against that kind of technique since the struct
layout generated by the compiler could change with a new compiler version.
*/

#define DEBUG_UXCODING

#ifdef DEBUG_UXCODING
	#define UXCODING_LOG UXLOG
#else
	#define UXCODING_LOG
#endif

#define BEGIN_ENCODER()			UXCODING_LOG(@"BEGIN_ENCODER() - %@", [self class]); [super encodeWithCoder:encoder];

#define ENCODE_OBJ(p)			UXCODING_LOG(@"ENCODE_OBJ(%@)", p); [encoder encodeObject:[self valueForKey:p] forKey:p];
#define ENCODE_IMAGE(p)			UXCODING_LOG(@"ENCODE_IMAGE(%@)", p); [encoder encodeObject:UIImagePNGRepresentation([self valueForKey:p]) forKey:p];
#define ENCODE_EDGEINSETS(p)	UXCODING_LOG(@"ENCODE_EDGEINSETS(%@)", p); [encoder encodeUIEdgeInsets:[[self valueForKey:p] UIEdgeInsetsValue] forKey:p];
#define ENCODE_SIZE(p)			UXCODING_LOG(@"ENCODE_SIZE(%@)", p); [encoder encodeCGSize:[[self valueForKey:p] CGSizeValue] forKey:p];

#define END_ENCODER()

#define BEGIN_DECODER()			UXCODING_LOG(@"BEGIN_DECODER() - %@", [self class]); if (self = [super initWithCoder:decoder]) {

#define DECODE_OBJ(p)			UXCODING_LOG(@"DECODE_OBJ(%@)", p); [self setValue:[decoder decodeObjectForKey:p] forKey:p];
#define DECODE_IMAGE(p)			UXCODING_LOG(@"DECODE_IMG(%@)", p); [self setValue:[UIImage imageWithData:[decoder decodeObjectForKey:p]] forKey:p];
#define DECODE_EDGEINSETS(p)	UXCODING_LOG(@"DECODE_EDGEINSETS(%@)", p); [self setValue:[NSValue valueWithUIEdgeInsets:[decoder decodeUIEdgeInsetsForKey:p]] forKey:p];
#define DECODE_SIZE(p)			UXCODING_LOG(@"DECODE_SIZE(%@)", p); [self setValue:[NSValue valueWithCGSize:[decoder decodeCGSizeForKey:p]] forKey:p];

#define END_DECODER()			}
