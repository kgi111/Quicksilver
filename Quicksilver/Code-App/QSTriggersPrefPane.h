#import <Cocoa/Cocoa.h>
#import <PreferencePanes/PreferencePanes.h>
#import "QSPreferencePane.h"

@class QSCommandBuilder, QSTrigger;

@interface NSObject (QSTriggerManager)
- (NSString *)descriptionForTrigger:(QSTrigger *)thisTrigger;
- (NSView *)settingsView;
- (void)setSettingsSelection:(QSTrigger *)aSettingsSelection;
- (void)initializeTrigger:(QSTrigger *)trigger;
- (void)enableTrigger:(QSTrigger *)trigger;
- (void)disableTrigger:(QSTrigger *)trigger;

- (void)trigger:(QSTrigger *)trigger setTriggerDescription:(NSString *)string;
@end

@interface QSTriggersArrayController : NSArrayController
@end

@interface QSTriggersPrefPane : QSPreferencePane {
	IBOutlet id addButton;
	IBOutlet NSDrawer * optionsDrawer;
	IBOutlet NSView *sidebar;

	IBOutlet id hotKeyOptions;
	IBOutlet id removeButton;
	IBOutlet NSOutlineView * triggerTable;

	IBOutlet NSTableView * triggerSetsTable;

	IBOutlet NSController *triggerSetsController;

	IBOutlet NSArrayController *triggerArrayController;
	IBOutlet NSTreeController *triggerTreeController;

	NSMutableArray *triggerArray;
    NSMenu *typeMenu;

	NSMutableArray *triggerSets;
	QSCommandBuilder *commandEditor;

	NSSortDescriptor *sort;
	NSString *search;
	NSString *currentSet;

	NSArray *draggedEntries;
	NSArray *draggedIndexPaths;

	IBOutlet NSTabView *drawerTabView;
	IBOutlet NSTabViewItem *settingsItem;

	QSTrigger *selectedTrigger;
	NSSplitView *splitView;
	int lastRow;
}
- (NSString *)currentSet;
- (void)setCurrentSet:(NSString *)value;
//- (NSArray *)selectionIndexPaths;
//- (void)setSelectionIndexPaths:(NSArray *)newSelectionIndexPaths;

- (QSTrigger *)selectedTrigger;
- (void)setSelectedTrigger:(QSTrigger *)newSelectedTrigger;

- (NSMutableArray *)triggerSets;
- (void)setTriggerSets:(NSMutableArray *)newTriggerSets;

+ (QSTriggersPrefPane *)sharedInstance;
- (void)updateTriggerArray;
- (NSArray *)triggerArray;
- (void)setTriggerArray:(NSMutableArray *)newTriggerArray;
- (NSSortDescriptor *)sort;
- (void)setSort:(NSSortDescriptor *)newSort;

	//- (void)populateInfoFields;

- (IBAction)addTrigger:(id)sender;
- (IBAction)removeTrigger:(id)sender;
- (IBAction)editTrigger:(id)sender;
- (IBAction)selectTrigger:(id)sender;

- (IBAction)showTriggerInfo:(id)sender;
- (IBAction)hideTriggerInfo:(id)sender;
- (int)tabViewIndex;
- (void)setTabViewIndex:(int)index;

- (IBAction)editCommand:(id)sender;

- (void)populateTypeMenu;
- (void)reloadFilters;

- (void)showTrigger:(QSTrigger *)trigger;
- (BOOL)editTriggerCommand:(QSTrigger *)trigger callback:(SEL)aSelector;
- (void)showTriggerGroupWithIdentifier:(NSString *)groupID;

- (id)preferencesSplitView;
@end
