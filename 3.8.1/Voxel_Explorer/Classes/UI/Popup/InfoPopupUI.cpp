//
//  SettingUILayer.cpp
//  Voxel_Explorer
//
//  Created by 创李 on 15/10/26.
//
//

#include "InfoPopupUI.h"
#include "UtilityHelper.h"
#include "VoxelExplorer.h"
USING_NS_CC;
InfoPopupUI::InfoPopupUI()
{
    m_cActionType = eNone;
    m_pInfoIcon = nullptr;
    m_pInfoDesc = nullptr;
}
InfoPopupUI::~InfoPopupUI()
{
    
}



bool InfoPopupUI::initUi()
{
    m_pRootNode = cocos2d::Node::create();
    m_pRootNode->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    m_pRootNode->setContentSize(cocos2d::Size(180.00,80.00));
    m_pRootNode->setPosition(WINDOW_CENTER);
    addChild(m_pRootNode,1);
    
    cocos2d::ui::ImageView* bgImg =  cocos2d::ui::ImageView::create("ui_frame_3.png",TextureResType::PLIST);
    bgImg->setScale9Enabled(true);
    bgImg->setContentSize(m_pRootNode->getContentSize());
    bgImg->setPosition(m_pRootNode->getContentSize()*0.5);
    m_pRootNode->addChild(bgImg);
    
    m_pInfoIcon =   ui::ImageView::create();
    m_pInfoIcon->setScale(0.35);
    m_pInfoIcon->setPosition(cocos2d::Vec2(m_pRootNode->getContentSize().width*0.2,m_pRootNode->getContentSize().height*0.5));
    m_pRootNode->addChild(m_pInfoIcon);
    
    m_pInfoDesc = Label::createWithTTF("", UtilityHelper::getLocalString("FONT_NAME"), 36);
    m_pInfoDesc->setScale(0.3);
    m_pRootNode->addChild(m_pInfoDesc);
    
    m_pRootNode->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);
    return true;
}

void InfoPopupUI::setInfoData(const std::string& infoRes, std::string& infoDesc)
{
    int charCount = 0;
    if(cocos2d::Application::getInstance()->getCurrentLanguage() ==cocos2d::LanguageType::CHINESE)
    {
        charCount =20;
    }else{
        charCount = 40;
    }
    int count = UtilityHelper::getLineStr(infoDesc, charCount);

    if (nullptr != m_pInfoIcon) {
        if (infoRes.empty()) {
            m_pInfoIcon->setVisible(false);
            m_pInfoDesc->setPosition(m_pRootNode->getContentSize()*0.5);
        }else{
            m_pInfoIcon->loadTexture(infoRes,cocos2d::ui::TextureResType::PLIST);
            m_pInfoIcon->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);
            m_pInfoDesc->setPosition(cocos2d::Vec2(m_pInfoIcon->getPositionX()+m_pInfoIcon->getContentSize().width*0.5,m_pRootNode->getContentSize().height*0.5));
        }
   }
    if (nullptr!= m_pInfoDesc) {
        m_pInfoDesc->setString(infoDesc);
        m_pInfoDesc->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);
    }
}