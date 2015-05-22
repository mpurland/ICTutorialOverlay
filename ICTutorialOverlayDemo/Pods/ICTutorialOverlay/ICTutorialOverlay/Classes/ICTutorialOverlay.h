//
//  ICTutorialOverlay.h
//  ICTutorialOverlay
//
//  Created by Ichito Nagata on 2013/08/19.
//
//

#import <UIKit/UIKit.h>

typedef enum {
    ICTutorialOverlayHoleFormRectangle = 0,
    ICTutorialOverlayHoleFormCircle    = 1,
    ICTutorialOverlayHoleFormRoundedRectangle = 2,
} ICTutorialOverlayHoleForm;

@interface ICTutorialOverlayHole : NSObject

@property (nonatomic) CGRect rect;
@property (nonatomic) ICTutorialOverlayHoleForm form;
@property (nonatomic) BOOL transparentEvent;
@property (nonatomic) UIView *boundView;

- (UIBezierPath*)bezierPath;
- (BOOL)containsPoint:(CGPoint)point;

@end

@interface ICTutorialOverlay : UIView

@property (nonatomic, strong) NSMutableArray *holes;

@property (nonatomic) BOOL animated;
@property (nonatomic) BOOL hideWhenTapped;
@property (nonatomic, copy) void(^willShowCallback)();
@property (nonatomic, copy) void(^didShowCallback)();
@property (nonatomic, copy) void(^willHideCallback)();
@property (nonatomic, copy) void(^didHideCallback)();
@property (nonatomic, readonly) BOOL isShown;

- (ICTutorialOverlayHole*)addHoleWithRect:(CGRect)rect form:(ICTutorialOverlayHoleForm)form transparentEvent:(BOOL)transparentEvent;
- (ICTutorialOverlayHole*)addHoleWithView:(UIView*)view padding:(CGFloat)padding offset:(CGSize)offset form:(ICTutorialOverlayHoleForm)form transparentEvent:(BOOL)transparentEvent;

- (CGSize)calculatePaddingSizeWithRect:(CGRect)rect defaultPadding:(CGFloat)defaultPadding form:(ICTutorialOverlayHoleForm)form;

- (void)show;
- (void)hide;

+ (ICTutorialOverlay*)showingOverlay;

@end
