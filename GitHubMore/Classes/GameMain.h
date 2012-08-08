//
//  GameMain.h
//  GitHubMore
//
//  Created by sword on 12-8-7.
//  Copyright (c) 2012年 LazyPandaGames. All rights reserved.
//

#ifndef GitHubMore_GameMain_h
#define GitHubMore_GameMain_h

#include "cocos2d.h"

using namespace cocos2d;


struct NumberNode
{
    int x;
    int y;
    int number;
    int testnumber;
};


class GameMain:public CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
	    
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(GameMain);
    
    
    NumberNode Grids[9][9];
    
    
};


#endif