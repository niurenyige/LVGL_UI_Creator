#pragma once
#include <string>
#include <vector>
#include "lvgl/lvgl.h"
#include "SimWindow.h"
#include "../Widgets/CollapsableWindowManager.h"
#include "../Widgets/CollapsableWindow.h"
#include "../Widgets/MinimizableWindow.h"
#include "../Widgets/TreeView.h"
#include "UIObjectData.h"

class PropertyWindow
{
public:
	PropertyWindow(SimWindow *simWindow, int screenWidth, int screenHeight);
	TreeView *GetObjectTree();
	
private:
	MinimizableWindow *minWin;
	SimWindow *simWindow;
	lv_obj_t* propertyWin;
	int screenX, screenY;
	bool globalExpanded;
	CollapsableWindow *globalProps, *baseObjProps, *treeWin, *objProps;
	CollapsableWindowManager *cwm;
	TreeView *treeView;
	static lv_theme_t *activeTheme;
	static std::vector<lv_theme_t *> themes;
	
	static void initializeThemes(uint16_t hue);
	void createPropertyWin();
	void createGlobalProps();
	void createBaseObjProps();
	void createObjProps();
	void createTreeView();
	static void objSelectCB(TreeNode *node);
	static void deleteCB(TreeNode *node);
	
	static void theme_select_event_handler(lv_obj_t * roller, lv_event_t event);
	static void hue_select_event_cb(lv_obj_t * roller, lv_event_t event);
};
