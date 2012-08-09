//
//  GameMain.cpp
//  GitHubMore
//
//  Created by sword on 12-8-7.
//  Copyright (c) 2012年 LazyPandaGames. All rights reserved.
//

#include "GameMain.h"

CCScene* GameMain::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
    //new file;
    
	// 'layer' is an autorelease object
	GameMain *layer = GameMain::node();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameMain::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
    
	CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");
    
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
    
    
    for (int x=0; x<9; x++) 
    {
        for (int y=0; y<9; y++)
        {
            Grids[x][y].number = -1;
            Grids[x][y].testnumber = 0;
            Grids[x][y].x = x+1;
            Grids[x][y].y = y+1;
        }
    }
    
    const char* pathKey = CCFileUtils::fullPathFromRelativePath("test.txt");
    FILE* pf = fopen(pathKey, "rt");
    if (pf!=NULL)
    {
        char ch;
        
        ch = fgetc(pf);
        int currentx = 0;
        int currenty = 0;
        
        int num = 1;
        CCLog("Test ------- %d -------", num);
        while (ch != EOF)
        {
            if (ch == '\t' || (ch >= '0'&&ch <='9'))
            {
                
                if (ch != '\t' )
                {
                    Grids[currentx][currenty].number = atoi(&ch);  
                    CCLog("%d, %d, %d",currentx,currenty, Grids[currentx][currenty].number);
                    currentx--;
                }
                else
                {
                    if(Grids[currentx][currenty].number == -1)
                    {
                        Grids[currentx][currenty].number = 0;  
                    }
                }
                
                ch = fgetc(pf);
                currentx++;
            }
            else
            {
                currentx = 0;
                currenty++;
                if (currenty == 10)
                {
                    currenty = 0;
                    
                    for (int x=0; x<9; x++) 
                    {
                        for (int y=0; y<9; y++)
                        {
                            Grids[x][y].number = -1;
                            Grids[x][y].testnumber = 0;
                            Grids[x][y].x = x+1;
                            Grids[x][y].y = y+1;
                        }
                    }
                    num ++;
                    CCLog("Test ------- end ------", num);
                    CCLog("Test ------- %d -------", num);
                }
                ch = fgetc(pf);
            }
        }
        CCLog("Test ------- end ------", num);
       
        
    }
    fclose(pf);
    
    
    return true;
}

