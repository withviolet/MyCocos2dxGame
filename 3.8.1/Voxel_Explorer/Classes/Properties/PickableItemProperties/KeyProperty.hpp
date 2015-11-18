//
//  KeyProperty.hpp
//  Voxel_Explorer
//
//  Created by wang haibo on 15/10/24.
//
//

#ifndef KeyProperty_hpp
#define KeyProperty_hpp

#include "PickableItemProperty.hpp"
class KeyProperty : public PickableItemProperty, public IStackable
{
public:
    KeyProperty(unsigned int instanceID, PickableItem::PickableItemType type);

    virtual void adjustByLevel();
    virtual void handleIdentify();
    
    virtual void increaseCount() { ++m_nCount; }
    virtual void decreaseCount() { --m_nCount; }
};

#endif /* KeyProperty_hpp */